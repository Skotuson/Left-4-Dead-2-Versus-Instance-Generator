const Maps = new Map([
  [1, "No Mercy"],
  [2, "Crash Course"],
  [3, "Death Toll"],
  [4, "Dead Air"],
  [5, "Blood Harvest"],
  [6, "The Sacrifice"],
  [7, "The Last Stand"],
  [8, "Dead Center"],
  [9, "The Passing"],
  [10, "Dark Carnival"],
  [11, "Swamp Fever"],
  [12, "Hard Rain"],
  [13, "The Parish"],
  [14, "Cold Stream"]
]);
const CringeMaps = ["Crash Course", "The Sacrifice", "The Last Stand", "The Passing", "Cringe Map"];
let maps_by_colour = new Map();
let rotation_speed = 0;
let colour_slice = 0;
let duration = 10;
let final_colour = 0;
function setup() {
  createCanvas(800, 800);

  angleMode(DEGREES);

  fill(255);
  textSize(20);
  textAlign(CENTER, CENTER);

  // Set the color mode to hue-saturation-brightness (HSB)
  colorMode(HSB);
  background(0);
  // Create screen reader accessible description
  describe('Left 4 Dead 2 Map Roulette');
}
function draw_roulette() {
  let i = 1;
  let current_map = ""
  for (let angle = 0; angle <= 336; angle += 24) {
    // Save current coordinate system
    push();

    // Translate to center of canvas and rotate by angle
    translate(0, 0);
    rotate(angle);

    // Set color based on angle and draw arc representing each circle slice
    colour_slice = angle;
    stroke(angle, 100, 100);
    fill(angle, 100, 50);
    strokeWeight(5);
    //line(0, 0, 250, 0);
    arc(0, 0, 600, 600, 0, PI * 7.6);
    if (i <= 14) {
      current_map = Maps.get(i);
      stroke(0);
      fill(angle, 100, 100);
      strokeWeight(2);
      text(current_map, 220, 15);
      maps_by_colour.set(colour_slice, current_map)
      i += 1;
      // Restore coordinate system
      pop()
    } else {
      stroke(0);
      fill(angle, 100, 100);
      strokeWeight(2);
      text("Cringe Map", 220, 15);
      // Restore coordinate system
      pop()
    }
  }
}

function draw() {
  background(0);
  static_lines();
  translate(width / 2, height / 2);
  rotate(frameCount / 20 * rotation_speed);
  draw_roulette();
  if (rotation_speed >= 0) {
    rotation_speed -= 1
  } else {
    return get_map_name();
  }
}

function static_lines() {
  translate(0, 0)
  stroke(0, 255, 255);
  strokeWeight(5);
  line(width, height, width - 180, height - 180);
  line(width - 180, height - 180, width - 75, height - 150);
  line(width - 180, height - 180, width - 150, height - 75);
}

function mousePressed() { // Spin the wheel. Random rotation does not work so far.
  rotation_speed = floor(random(0, 360));
}
function get_map_name() { // Find hue from the RGB value returned by get
  translate(0, 0);
  final_colour = get(width - 200, height - 200)
  let max_rg_b = Math.max(final_colour[0], final_colour[1], final_colour[2]);
  let min_rg_b = Math.min(final_colour[0], final_colour[1], final_colour[2]);
  let hue_final = 0;

  // all greyscale colors have hue of 0deg
  if (max_rg_b - min_rg_b == 0) {
    hue_final = 0;
  }

  else if (max_rg_b == final_colour[0]) {
    // if red is the predominant color
    hue_final = (final_colour[1] - final_colour[2]) / (max_rg_b - min_rg_b);
  }
  else if (max_rg_b == final_colour[1]) {
    // if green is the predominant color
    hue_final = 2 + (final_colour[2] - final_colour[0]) / (max_rg_b - min_rg_b);
  }
  else if (max_rg_b == final_colour[2]) {
    // if blue is the predominant color
    hue_final = 4 + (final_colour[0] - final_colour[1]) / (max_rg_b - min_rg_b);
  }

  hue_final = hue_final * 60;

  // make sure h is a positive angle on the color wheel between 0 and 360
  hue_final %= 360;
  if (hue_final < 0) {
    hue_final += 360;
  }
  stroke(0);
  fill(hue_final, 100, 100);
  strokeWeight(15);
  hue_final = Math.round(hue_final);
  final_map = maps_by_colour.get(hue_final)
  resetMatrix()
  if (CringeMaps.includes(final_map) || final_map === undefined) {
    text("CRINGE MAP: Time to reroll", width - 250, height - 30);
  } else {
    final_map = "The chosen map is: " + final_map
    text(final_map, width - 250, height - 30);
  }
}