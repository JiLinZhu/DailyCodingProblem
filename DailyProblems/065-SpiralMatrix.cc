/* 65. Amazon
Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.
*/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int rowCur = 0;
    bool rowInc = true;
    int colCur = 0;
    bool colInc = true;
    int colSize = matrix.size();
    if( colSize == 0 ) return result;
    int rowSize = matrix[0].size();

    while( rowSize > 0 && colSize > 0 ) {
        for( int i = 0; i < rowSize; i++, rowCur += rowInc ? 1 : -1 ) {
            result.push_back(matrix[colCur][rowCur]);
        }
        rowInc = !rowInc;
        colSize--;
        rowCur += rowInc ? 1 : -1;
        colCur += colInc ? 1 : -1;
        for( int i = 0; i < colSize; i++, colCur += colInc ? 1 : -1 ) {
            result.push_back(matrix[colCur][rowCur]);
        }
        colInc = !colInc;
        rowSize--;
        rowCur += rowInc ? 1 : -1;
        colCur += colInc ? 1 : -1;
    }

    return result;
}
