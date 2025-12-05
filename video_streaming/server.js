const express = require('express');
const multer = require('multer');
const { exec } = require('child_process');
const { v4: uuidv4 } = require('uuid');
const path = require('path');
const fs = require('fs');

const app = express();
const upload = multer({ dest: 'uploads/' });

// Serve static HLS output
app.use('/videos', express.static(path.join(__dirname, 'videos')));

// ===========================
// GET /  — Upload UI
// ===========================
app.get('/', (req, res) => {
    const html = `
    <!DOCTYPE html>
    <html>
    <head>
        <title>Upload Video</title>
        <style>
            body { font-family: sans-serif; padding: 40px; }
            .box {
                max-width: 400px;
                margin: auto;
                border: 1px solid #ddd;
                padding: 20px;
                border-radius: 10px;
            }
            input[type=file], button {
                width: 100%;
                padding: 10px;
                margin-top: 10px;
            }
        </style>
    </head>
    <body>
        <div class="box">
            <h2>Upload Video</h2>

            <form id="uploadForm" enctype="multipart/form-data">
                <input type="file" name="video" accept="video/mp4" required />
                <button type="submit">Upload</button>
            </form>

            <p id="result"></p>

            <script>
                const form = document.getElementById('uploadForm');
                const result = document.getElementById('result');

                form.addEventListener('submit', async (e) => {
                    e.preventDefault();

                    const formData = new FormData(form);
                    result.innerHTML = "Uploading & processing...";

                    const res = await fetch('/upload', {
                        method: 'POST',
                        body: formData
                    });

                    const data = await res.json();

                    if (data.url) {
                        result.innerHTML =
                            "Done! <a href='" + data.url + "'>View video</a>";
                    } else {
                        result.textContent = "Error uploading video.";
                    }
                });
            </script>
        </div>
    </body>
    </html>
    `;
    res.send(html);
});

// ===========================
// POST /upload  — Convert video to HLS
// ===========================
app.post('/upload', upload.single('video'), (req, res) => {
    if (!req.file) return res.status(400).send('No file uploaded.');

    const id = uuidv4();
    const inputPath = req.file.path;
    const outputDir = path.join('videos', id);

    fs.mkdirSync(outputDir, { recursive: true });

    // Clean and safe ffmpeg command (single line)
    const cmd = `ffmpeg -i "${inputPath}" -codec copy -start_number 0 -hls_time 4 -hls_list_size 0 -f hls "${outputDir}/index.m3u8"`;

    exec(cmd, (err) => {
        fs.unlinkSync(inputPath); // remove raw uploaded file

        if (err) {
            console.error(err);
            return res.status(500).send('Video processing failed.');
        }

        res.json({ id, url: `/view/${id}` });
    });
});

// ===========================
// GET /view/:id — Play the video
// ===========================
app.get('/view/:id', (req, res) => {
    const id = req.params.id;
    const manifest = path.join(__dirname, 'videos', id, 'index.m3u8');

    if (!fs.existsSync(manifest)) {
        return res.status(404).send('Video not found');
    }

    const html = `
    <!DOCTYPE html>
    <html>
    <head><title>Video Player</title></head>
    <body>
        <h2>Video Player</h2>

        <video id="video" width="640" controls autoplay></video>

        <script src="https://cdn.jsdelivr.net/npm/hls.js@latest"></script>
        <script>
            const video = document.getElementById('video');
            const src = '/videos/${id}/index.m3u8';

            if (Hls.isSupported()) {
                const hls = new Hls();
                hls.loadSource(src);
                hls.attachMedia(video);
            } else {
                // Safari/iOS
                video.src = src;
            }
        </script>
    </body>
    </html>
    `;
    res.send(html);
});

// ===========================
// Start Server
// ===========================
app.listen(3000, () =>
    console.log('Server running at http://localhost:3000')
);
