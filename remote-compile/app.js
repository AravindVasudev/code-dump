const express      = require('express');
const cookieParser = require('cookie-parser');
const bodyParser   = require('body-parser');
const fs           = require('fs');
const { exec }     = require('child_process');

const app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cookieParser());

app.get('/', (req, res) => {
    res.sendFile(__dirname + '/index.html');
});

app.post('/compile', (req, res) => {
    const code = req.body.code;
    const stdin = req.body.stdin;

    fs.writeFile('temp.cc', code, (err) => {
        if (err) throw err;
        exec(`g++ temp.cc && echo "${stdin}" | ./a.out`, (err, stdout, stderr) => {
            if (err) throw err;
            res.send(`stdout: ${stdout} <br>
           stderr: ${stderr}`);
        });
    });

});

app.listen(3000, () => console.log('Listening @ 3000'));
