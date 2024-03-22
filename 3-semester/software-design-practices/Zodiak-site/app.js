const http = require("http");
const express = require("express");
const { sign } = require("crypto");
const app = express();

app.set("view engine", "ejs");
app.set("views", "./views");
  
app.use(express.urlencoded({ extended: true }));
app.use(express.static(__dirname + '/static'));

app.post("/", (req, res) => {
  let { date } = req.body; 
  day_num = dayOfYear(date)
  let query;
  if (day_num >= 19 && day_num <= 49){
    query = "?sign=_aq"
  }
  else if (day_num >= 50 && day_num <= 79){
    query = "?sign=_pi"
  }
  else if (day_num >= 80 && day_num <= 110){
    query = "?sign=_ar"
  }
  else if (day_num >= 111 && day_num <= 140){
    query = "?sign=_ta"
  }
  else if (day_num >= 141 && day_num <= 171){
    query = "?sign=_ge"
  }
  else if (day_num >= 172 && day_num <= 203){
    query = "?sign=_ca"
  }
  else if (day_num >= 204 && day_num <= 234){
    query = "?sign=_le"
  }
  else if (day_num >= 235 && day_num <= 265){
    query = "?sign=_vi"
  }
  else if (day_num >= 266 && day_num <= 295){
    query = "?sign=_li"
  }
  else if (day_num >= 296 && day_num <= 326){
    query = "?sign=_sc"
  }
  else if (day_num >= 327 && day_num <= 355){
    query = "?sign=_sa"
  }
  else {
    query = "?sign=_cap"
  }
  res.redirect("/sign" + query);
});

app.get("/", (req, res) => {
  res.render("main");
});

app.get("/sign", (req, res) => {
  const { sign } = req.query;
  res.render("sign" + sign);
});

function dayOfYear(data) {
  const parts = data.split('.');
  const day = parseInt(parts[0]);
  const month = parseInt(parts[1]);
  const year = parseInt(parts[2]);

  const dateObj = new Date(year, month - 1, day); 

  const startOfYear = new Date(year, 0, 1);

  const diffTime = Math.abs(dateObj - startOfYear); 
  const diffDays = Math.ceil(diffTime / (1000 * 60 * 60 * 24)); 

  return diffDays;
}

http.createServer(app).listen(3000);
console.log("started");