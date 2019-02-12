/* 45. Two Sigma
Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability, 
implement a function rand7() that returns an integer from 1 to 7 (inclusive).
*/

int rand7() {
	while( true ) {
		int num = rand5() * 5 + rand5();
		if( num < 20 ) return num;
	}
}