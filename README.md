# Left 4 Dead 2 Versus Instance Generator
 > Simple CLI application which generates `L4D2` Versus gamemode configuration, like team composition and a map to play.

❗Not really finished, current version lacks configurable filenames and other quality of life features❗

## Usage
There are several modes the app can run in, like:
- `default` - Prints out randomly shuffled teams and map
- `stat`    - Prints out all recorded players and their winrates
- `update`  - Serves to automatically update database

All of the above mentioned modes can be ran by using the `make` command with the mode name, e.g.  
```
make update
```
