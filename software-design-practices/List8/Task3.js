var http = require('http');
var express = require("express");

var app = express();

app.set('view engine', 'ejs');
app.set('views', './views');

app.get("/", (req, res) => {
  res.render('Zadanie3')
  //res.redirect('/download');
});

app.get('/download', (req, res) => {
  res.setHeader('Content-disposition', 'attachment; filename=plik.txt');
  res.end('Hello world');
});

http.createServer(app).listen(3000);
console.log("strarted");  