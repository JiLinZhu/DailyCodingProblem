/* 57. Justify
Given a string s and an integer k, break up the string into multiple texts such 
that each text has a length of k or less. You must break it up so that words don't 
break across lines. If there's no way to break the text up, then return null.

You can assume that there are no spaces at the ends of the string and that there 
is exactly one space between each word.

For example, given the string "the quick brown fox jumps over the lazy dog" and 
k = 10, you should return: ["the quick", "brown fox", "jumps over", "the lazy", "dog"]. 
No string in the list has a length of more than 10.
*/

// solution is for Justify, a more complicated version of this

vector<string> fullJustify(vector<string>& words, int maxWidth) { 
    vector<int> len;
    vector<string> result;
    for( string s : words ) {
        len.push_back(s.length());
    }
    
    int count = -1;
    int startIndex = 0;
    int numSections, numSpaces, addSpaces, placeholder;
    string cur = "";
    for( int i = 0; i < words.size(); i++ ) {
        if( count + 1 + len[i] > maxWidth ) {
            numSections = i - startIndex - 1;
            placeholder = numSections;
            numSpaces = maxWidth - count + numSections;
            while( numSections > 0 ) {
                cur += words[startIndex + placeholder - numSections];
                addSpaces = numSpaces/numSections +  ( numSpaces % numSections == 0 ? 0 : 1 );
                for( int k = 0; k < addSpaces; k++ ) cur += " ";  
                numSpaces -= addSpaces;
                numSections--;
            }
            cur += words[i-1];
            for( int l = cur.length(); l < maxWidth; l++ ) cur += " ";  

            startIndex = i;
            count = len[i];
            result.push_back( cur );
            cur = "";
        } else {
            count = count + len[i] + 1;
        }
    }
    if( startIndex < words.size() ) {
        cur = words[startIndex++];
    }
    for( int i = startIndex; i < words.size(); i++ ) {
        cur = cur + " " + words[i];
    }
    for( int i = cur.length(); i < maxWidth; i++ ) {
        cur += " ";
    }
    result.push_back(cur);
    return result;
}