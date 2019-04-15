/* 55. 
Implement a URL shortener with the following methods:

shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.
restore(short), which expands the shortened string into the original url. If no such shortened string exists, return null.
Hint: What if we enter the same URL twice?
*/


class URLShortener {
public:

  void encode( string longUrl ) {
    string shortUrl = ""

    while( shortUrl == "" || map.find(shortUrl) != map.end() ) {
      shortUrl = "";
      for( int i = 0; i < 6; i++ ) {
        shortUrl += chars[randInt(62)]
      }
    }
    map[shortUrl] = longUrl;
  }

  string decode( string shortUrl ) {
    if( map.find(shortUrl) == map.end() ) return NULL;
    else return map[shortUrl]; 
  }

private:

  string chars = "abcefg........1234567890"

  unordered_map<string, string> map;
}



// Can also just turn longUrl -> id (base 10) -> base62