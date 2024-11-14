var http = require('http');
var express = require('express');
var app = express();

app.set('view engine', 'ejs');
app.set('views', './views');

app.get('/', (req, res) => {
  var combo1 = {
    name: 'combo1',
    options: [
      { value : 1, text : 'element 1' },
      { value : 2, text : 'element 2' },
      { value : 3, text : 'element 3' }
    ]
  };
  var combo2 = {
    name: 'combo2',
    options: [
      { value : 4, text : 'element 4' },
      { value : 5, text : 'element 5' },
      { value : 6, text : 'element 6' }
    ]
  }
  res.render('Zadanie2', { combo1, combo2 });
});

http.createServer(app).listen(3000);
console.log("strarted");