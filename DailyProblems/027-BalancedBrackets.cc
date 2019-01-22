/* 27. Facebook
Given a string of round, curly, and square open and closing brackets, 
return whether the brackets are balanced (well-formed).
*/

bool isValid(string s) {
    stack<char> brackets;
    unordered_map<char> u;
    u['('] = ')';
    u['['] = ']';
    u['{'] = '}';

    for( char c: s ) {
        if( c == '(' || c == '[' || c == '{' ) brackets.push(c);
        else {
            if( brackets.size() == 0 || u[brackets.top()] != c ) return false;
            brackets.pop();
        }
    }
    return brackets.size() == 0;
}