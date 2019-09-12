/* 108. Google
Given two strings A and B, return whether or not A can be shifted some number of times to get B.

For example, if A is abcde and B is cdeab, return true. If A is abc and B is acb, return false.
*/

bool rotatedString(string a, string b) {
  return b.length == a.length && b.isSubstring(a+a);
}
