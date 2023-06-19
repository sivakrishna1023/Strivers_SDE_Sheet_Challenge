#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &matrix, int n, int m)
{
    int rowStart=0,colStart=0,rowEnd=n-1,colEnd=m-1;
   while (rowStart <rowEnd && colStart <colEnd) {
        // Print the top row
        int prev=matrix[rowStart+1][colStart];
        for (int j = colStart; j <= colEnd; j++) {
                int val=matrix[rowStart][j];
                matrix[rowStart][j]=prev;
                prev=val;
        }
        rowStart++;

        // Print the rightmost column
        for (int i = rowStart; i <= rowEnd; i++) {
            int val=matrix[i][colEnd];
            matrix[i][colEnd]=prev;
            prev=val;
           // std::cout << matrix[i][colEnd] << " ";
        }
        colEnd--;

        // Print the bottom row (if exists)
        if (rowStart <= rowEnd) {
            for (int j = colEnd; j >= colStart; j--) {
                int val=matrix[rowEnd][j];
                matrix[rowEnd][j]=prev;
                prev=val;
               // std::cout << matrix[rowEnd][j] << " ";
            }
            rowEnd--;
        }

        // Print the leftmost column (if exists)
        if (colStart <= colEnd) {
            for (int i = rowEnd; i >= rowStart; i--) {
                int val=matrix[i][colStart];
                matrix[i][colStart]=prev;
                prev=val;
               // std::cout << matrix[i][colStart] << " ";
            }
            colStart++;
        }
    }
    // Write your code here

}
