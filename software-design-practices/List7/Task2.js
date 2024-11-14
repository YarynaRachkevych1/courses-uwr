var https = require('https');
var fs = require('fs');

(async function () {
  var pfx = await fs.promises.readFile('test.pfx');
  https.createServer(
    {
      pfx: pfx,
      passphrase: '1234'
    },
    (req, res) => {
    res.setHeader('Content-type', 'text/html; charset=utf-8');
    res.end(`hello world: ${req.url}, it's ${new Date()}`);

  }).listen(3000);

  console.log('started');
})(); 