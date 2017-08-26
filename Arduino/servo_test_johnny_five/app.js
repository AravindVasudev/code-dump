const five  = require("johnny-five");
const board = new five.Board();

board.on("ready", () => {
    let motion = new five.Motion(7);
    let servo  = new five.Servo(8);
    let buzzer = new five.Led(4);

    motion.on("calibrated", function() {
        console.log("calibrated");
      });

    motion.on("motionstart", () => {
        console.log("motionstart");
        servo.to(90);
        buzzer.on();
    });

    motion.on("motionend", () => {
        console.log("motionend");
        servo.to(0);
        buzzer.off();
    });
});