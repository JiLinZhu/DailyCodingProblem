/* 40. Google
Given an array of integers where every integer occurs three times except for one integer, which only occurs once, find and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.
*/


int singleNumber(vector<int>& nums) {
    int a=0;
    int b=0;
    for(int c:nums){
        int ta=(~a&b&c)|(a&~b&~c);
        b=(~a&~b&c)|(~a&b&~c);
        a=ta;
    }

    return a|b;
}