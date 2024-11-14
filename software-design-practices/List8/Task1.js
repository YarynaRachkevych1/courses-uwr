var http = require('http');
var express = require('express');
var multer = require('multer');
var path = require('path');

var app = express();

app.set('view engine', 'ejs');
app.set('views', './views');

const storage = multer.diskStorage({
  filename: function (req, file, cb) {
    cb(null, Date.now() + path.extname(file.originalname)); 
  }
});

const upload = multer({ storage: storage });

app.get('/', (req, res) => {
  res.render('Zadanie1');
});

app.post('/upload', upload.single('fileInput'), (req, res) => {
  if (!req.file) {
    return res.status(400).send('Nie wybrano pliku.');
  }
  res.send('Plik został przesłany!');
});

http.createServer(app).listen(3000);
console.log("started");