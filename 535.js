/**
 * Encodes a URL to a shortened URL.
 *
 * @param {string} longUrl
 * @return {string}
 */

let enCode = new Map();
let deCode = new Map();
let num = 0;
var encode = function(longUrl) {
    if (!enCode.has(longUrl)) {
        enCode.set(longUrl, 'http://tinyurl.com/' + num.toString());
        deCode.set('http://tinyurl.com/' + num, longUrl);
        num++;
    }
    return enCode.get(longUrl);
};

/**
 * Decodes a shortened URL to its original URL.
 *
 * @param {string} shortUrl
 * @return {string}
 */
var decode = function(shortUrl) {
    return deCode.get(shortUrl);
};

/**
 * Your functions will be called as such:
 * decode(encode(url));
 */