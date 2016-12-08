/****************************************************************************
* wiki-scrapper
*
* A simple Wikipedia Scrapper that returns a JSON scrapped from Wikipedia.
*
* INPUT
*  - The URL should be passed as a query string inside wiki parameter
*
* OUTPUT
*  - The output contains three parameter: title, body and error
*  - 'title' contains the title of the document
*  - 'body' conatins the first paragraph of text
*  - 'error' parameter is added whenever something goes wrong
 ***************************************************************************/

var express = require('express');
var request = require('request');
var cheerio = require('cheerio');
var app     = express();

var port    = process.env.PORT || 8080;
var address = process.env.ADDRESS || '127.0.0.1';

app.get('/', (req, res) => {
  var url = req.query.wiki;
  //Accepts only a valid URL that is a wikipedia page
  if(typeof url === 'undefined' || !url.match(/https:\/\/en.wikipedia.org\/wiki\/[\w\.?=%&=\-@/$,+]+/ig))
    res.json({error : "invalid url"});
  else {
    request(url, (error, response, body) => {
      if (!error && response.statusCode == 200) {
        var json = {title : "", body : ""};
        //loads the returned data into cheerio
        var $    = cheerio.load(body);

        //Extracts the title and the first paragraph using cheerio's DOM methods
        json.title = $('h1#firstHeading').text().trim();
        json.body  = $('#mw-content-text > p').first().text().trim();

        res.json(json);
      }
      else
        res.status(404).json({error : "Server Doesn't Respond"});
    });
  }
});

app.listen(port, address, () => {
  console.log(`Listening at ${address}:${port}`);
});
