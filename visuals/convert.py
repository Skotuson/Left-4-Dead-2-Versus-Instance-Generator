import csv
import re
from datetime import datetime

input_file = "../persistence/save_new.txt"
output_file = "scores.csv"

# Open the input file and parse its content
with open(input_file, "r") as file:
    lines = file.readlines()

# Prepare the CSV data§§
csv_data = [["team1", "team2", "winner", "map", "mode", "point_diff", "timestamp"]]

def parse_game_line(line):
    pattern = r"^(?P<winner>\w)\s+'(?P<map>[^']+)'\s+(?P<mode>\w)\s+(?P<point_diff>-?\d+)\s+(?P<timestamp>\d+)$"
    match = re.match(pattern, line)
    if not match:
        raise ValueError("Line format is invalid")

    data = match.groupdict()
    data["point_diff"] = int(data["point_diff"])
    data["timestamp"] = int(data["timestamp"])
    if data["map"] == "N/A":
        data["map"] = "NaN"
    return data

for line in lines:
    # Skip empty lines or lines that don't match the expected format
    if " x " not in line or " : " not in line:
        continue

    # Parse the line
    
    teams, rest = line.split(" : ")
    team1, team2 = teams.split(" x ")
    data = parse_game_line(rest.strip()); 
    
    if data["winner"] == "F":
        winner = "team1"
    else:
        winner = "team2"
    map_name = data["map"]
    if data["mode"] == "R":
        mode = "realism"
    else:
        mode = "normal"


    # Append the parsed data to the CSV data
    csv_data.append([team1.strip(), team2.strip(), winner, map_name.strip(), mode, data["point_diff"], data["timestamp"]])
    print([team1.strip(), team2.strip(), winner, map_name.strip(), mode, data["point_diff"], data["timestamp"]])

# Write the CSV data to the output file
with open(output_file, "w", newline="") as csvfile:
    writer = csv.writer(csvfile)
    writer.writerows(csv_data)

print(f"CSV file '{output_file}' has been created successfully.")