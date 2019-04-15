/* 86. Google
Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed to make the string valid (i.e. each open parenthesis is eventually closed).

For example, given the string "()())()", you should return 1. Given the string ")(", you should return 2, since we must remove all of them.
*/

int removeParen(string s) {
  int count = 0;
  int result;
  for( char c : s ) {
    if( c == '(' ) count++;
    else if( count == 0 ) result++;
    else count--;
  }

  return result + count;
}
