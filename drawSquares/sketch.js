var x = 0, y = 0, z = 50;
var myCanvas;

function setup() {
  myCanvas = createCanvas(800, 800);
  myCanvas.parent("p5");
  background(0, 0, 0);
  stroke(255,100);
  noFill();
  rectMode(CENTER);
}

function draw() {
  var angle=0.02 * mouseX + 0.02 * mouseY;
  translate(mouseX,mouseY);
  rotate(angle);

  if (mouseIsPressed && mouseButton == LEFT) {
    rect(0, 0, 50, 50);
  }
}

function keyPressed() {
  if (keyCode === ESCAPE) {
    saveCanvas(myCanvas, 'art', 'png');
  }
}
