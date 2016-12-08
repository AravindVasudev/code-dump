var sentiment = require('sentiment');
var stripTags = require('striptags');
var request   = require('request');

var data = '';
var link = process.argv[2] || 'https://en.wikipedia.org/wiki/Donald_Trump';

request(link, (error, response, body) => {
  if (!error && response.statusCode == 200) {
    data = sentiment(stripTags(body));
    data = data.score > 0 ? 'Positive' : 'Negative';
    console.log(data);
  }
  else throw error;
});
