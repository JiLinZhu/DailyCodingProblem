/* 17. Google
Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. 
For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext".

Given a string representing the file system in the above format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0.
*/

int lengthLongestPath(string input) {
    vector<int> sumSoFar;
    sumSoFar.push_back(-1);
    int count = 0;
    int layer = 1;
    bool isFile = false;
    int maxLen = 0;
    for( char i: input ) {
        if ( i == '\n' ) {
            if( sumSoFar.size() == layer ) {
                sumSoFar.push_back( count + 1 + sumSoFar[layer-1] );
            } else {
                sumSoFar[layer] = count + 1 + sumSoFar[layer-1];
            }
            if( isFile ) maxLen = max( maxLen, sumSoFar[layer] ); // checks if cur layer is > max
            
            isFile = false;
            count = 0;
            layer = 1;
        } else if ( i == '\t' ) {
            layer++;
        } else {
            if( i == '.' ) isFile = true;
            count++;
        }
    }
    if( isFile ) maxLen = max( maxLen, count + 1 + sumSoFar[layer-1] );
    return maxLen;
}