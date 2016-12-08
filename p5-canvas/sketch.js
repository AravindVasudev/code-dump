var x = 0, y = 0, z =50;

function setup() {
  var myCanvas = createCanvas(500, 500);
  myCanvas.parent("p5");
  background(0, 0, 0);
  stroke(255,100);
//  fill("#F0DF2B");
  noFill();
  rectMode(CENTER);
}

function draw() {
    var angle=0.02*mouseX+0.02*mouseY;
  translate(mouseX,mouseY);
   rotate(angle);
//  rect(mouseX, mouseY, 50, 50);

 if (mouseIsPressed)
    ellipse(0, 0, 50, 50);
  else
    rect(0, 0, 50, 50);
}
