// var https = require('https');

// https.get('https://www.google.pl/', function(resp) {
//     var buf = '';
//     resp.on('data', function(data) {
//         buf += data.toString();
//     });

//     resp.on('end', function() { 
//         console.log( buf );
//     });
// });

const https = require("https");

function fetchResource(url) {
  return new Promise((resolve, reject) => {
    const request = https.get(url, (response) => {
      // sprawdzanie statusu zwrotu
      if (response.statusCode !== 200) {
        reject(
          new Error(
            `Failed to fetch resource. Status code: ${response.statusCode}`
          )
        );
        return;
      }

      // pobieranie danych
      let data = "";
      response.on("data", (chunk) => {
        data += chunk;
      });

      // pobrano cale dane
      response.on("end", () => {
        resolve(data);
      });
    });

    // blad podczas wysylania requesta
    request.on("error", (error) => {
      reject(error);
    });

    request.end();
  });
}

fetchResource("https://www.google.pl/")
  .then((data) => {
    console.log(data);
  })
  .catch((error) => {
    console.error(error.message);
  });
