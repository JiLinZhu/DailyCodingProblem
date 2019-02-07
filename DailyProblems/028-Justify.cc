/* 28. Palantir
Write an algorithm to justify text. Given a sequence of words and an integer line length k, return a list of strings which represents each line, fully justified.

More specifically, you should have as many words as possible in each line. There should be at least one space between each word. Pad extra spaces when necessary so that each line has exactly length k. Spaces should be distributed as equally as possible, with the extra spaces, if any, distributed starting from the left.

If you can only fit one word on a line, then you should pad the right-hand side with spaces.

Each word is guaranteed not to be longer than k.

For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k = 16, you should return the following:

["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly
*/

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