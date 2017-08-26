const express = require('express');
const five    = require("johnny-five");
const board   = new five.Board();
const app = express();

board.on("ready", () => {
    const buzzer = new five.Led(4);

    app.get('/', (req, res) => {
        res.sendFile(__dirname + '/index.html');
    });

    app.get('/on', (req, res) => {
        buzzer.on();
        res.send('1');
    });

    app.get('/off', (req, res) => {
        buzzer.off();
        res.send('1');
    });

    app.listen(3000, () => console.log('Listening @ 0.0.0.0:3000'));
});

