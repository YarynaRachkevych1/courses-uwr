var fs = require('fs');
var http = require('http');

(async function () {
  var page = await fs.promises.readFile('test.html', 'utf-8');
  var server = http.createServer(
  (req, res) => {
    res.setHeader('Content-type', 'text/html; charset=utf-8');

    if (req.method == 'GET'){
      res.end(page.replace('{{login}}', ''));
    } else {

        var postdate = ' ';
        req.on('data')

    }
    
  });
  server.listen(3000);
  console.log('started');
})();