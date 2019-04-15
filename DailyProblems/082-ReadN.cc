/* 82. Microsoft
Using a read7() method that returns 7 characters from a file, implement readN(n) which reads n characters.

For example, given a file with the content “Hello world”, three read7() returns “Hello w”, “orld” and then “”.
*/


int read(int n) {
    int i = 0;
    string result = ""
    while( i < n ) {
        string s = read7(buf);
        result += s;
        i += s.length();
        if(s == "") return result;
    }
    return result.substring(n);
}
