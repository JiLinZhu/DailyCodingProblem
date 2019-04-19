
string binaryToString(double num) {
  int length = 0;
  string result = ""

  while( num != 0 && length < 32 ) {
    num *= 2;

    if( num > 1 ) {
      result += '1';
      num -= 1;
    } else {
      result += '0';
    }
    length++;
  }
  return num == 0 ? result : "";
}
