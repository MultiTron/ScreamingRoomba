const http = require('http');
const fs = require('fs');
const path = require('path');
const os = require('os');
const dns = require('dns');

const server = http.createServer((req, res) => {
    let filePath = randomScream(1, 16);

    fs.readFile(filePath, (err, data) => {
        if (err) {
            res.writeHead(404);
            res.end("File not found");
            return;
        }
        
        res.writeHead(200, {
            'Content-Type': 'audio/mpeg',
            'Content-Length': data.length
        });
        res.end(data);
    });
});

const PORT = 3000;

server.listen(PORT, () => {
    console.log(`Server is running on http://192.168.1.105:${PORT}`);
});

function randomScream(min, max){//min-inclusive, max-exclusive
    const basePath = './screams/';
    let randomNumber = Math.floor(Math.random() * (max - min)) + min;
    console.log(randomNumber);
    return path.join(basePath, `scream_${randomNumber}.mp3`);
}
