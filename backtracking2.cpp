


/* This problem asks us to fill N Queens in N * N ChessBoard such that no Queen will cancel each other
In order to be sure, no Queen cancel out each other, we need to check in 3 directions:
a) In the column where we are placing the Queen
b) In the Top Right / Upper Right Diagonal of the Cell in which we are placing the Queen
c) In the Top Left  / Upper Left Diagonal of the  Cell in which we are placing the Queen
We don't need to check for the Rows, as each row will contain only a single Queen

Instead of using isSafe() function, which takes O(N) time to check if the Current Cell (i , j) is Safe or Not, we will use 3 vectors:
i)   col[n] --> Checks if we have already placed a Queen or not in the Same Column
ii)  topLeft[2 * n] -->  Checks if our Queen can be attacked by any Queen sitting in it's Top Left Diagonal / Upper Left Diagonal
iii) topRight[2 * n] --> Checks if our Queen can be attacked by any other Queen sitting in it's Top Right Diagonal / Upper Right Diagonal

To mark every index in our topLeft[] & topRight[] vectors, we use the following :
a) For any cell in our ChessBoard (i , j) to map it with corresponsing index in topLeft[], we use the formula: (i - j + n - 1)
b) For any cell in our ChessBoard (i , j) to map it with the corresponding index in topRight[], we use the formula(i + j)

*/

class Solution {
private:

void help(int i , int n , vector<vector<char>> &chessBoard , vector<vector<string>> &ans , vector<int> &col , vector<int> &topLeft , vector<int> &topRight)
{
    // If i becomes equal to N , it means we have safely placed all the N Queens in N Rows such that no one attacks one another

    if(i == n)
    {
        // string temp will store the current configuration of the chessBoard which we can later put inside our ans[][]

        vector<string> temp ;

        for(int j = 0 ; j < n ; j++)
        {
            // currRow will contain the configuration of the CurrentRow which we are traversing

            string currRow = "" ;

            for(int k = 0 ; k < n ; k++)
            {
                currRow.push_back(chessBoard[j][k]) ;
            }

            // After traversing one row, we need to push it inside our temp vector

            temp.push_back(currRow) ;
        }

        // After vector temp[] is ready, we put it inside our ans[][] and simply return back to explore other possible configurations

        ans.push_back(temp) ;
        return ;
    }

    for(int j = 0 ; j < n ; j++)
    {
        // We need to first check if we can place a Queen in (i , j) position by calling isSafe() function

        if( ( col[j] == 0 ) AND ( topLeft[i - j + n - 1] == 0 ) AND ( topRight[i + j] == 0 ) )
        {
            // If isSafe() returns true, then we defintely can place a Queen in (i , j) cell

            chessBoard[i][j] = 'Q' ;

            col[j] = 1 ;
            topLeft[i - j + n - 1] = 1 ;
            topRight[i + j] = 1 ;

            // We ask recursion to do rest of the task

            help(i + 1 , n , chessBoard , ans , col , topLeft , topRight) ;

            // Before leaving, we need to backtrack &#038; undo the change we have done

            chessBoard[i][j] = '.' ;

            col[j] = 0 ;
            topLeft[i - j + n - 1] = 0 ;
            topRight[i + j] = 0 ;

        }
    }
}

public:
    vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> ans ;

    // We create the chessBoard which has dimmensions N * N
    // Any cell inside chessBoard will have either '.' or 'Q' as a Character
    // If chessBoard[i][j] = '.' , indicates that the cell is vacant and we can place a Queen
    // If chessBoard[i][j] = 'Q' , indicates that the cell is occupied by a Queen

    vector<vector<char>> chessBoard(n , vector<char> (n , '.') ) ;

    // col[] vector will help us determine if any Queen is already placed in that particular column or not in O(1) Time Complexity

    vector<int> col(n , 0) ;

    // topLeft[] vector will help us to check in the Top Left / Upper Left Direction in O(1) Time Complexity
    // We use the formula (i - j + n - 1) for mapping any index in topLeft with it's corresponding (i , j) in our ChessBoard

    vector<int> topLeft(2 * n , 0) ;

    // topRight[] vector will help us to check in the Top Right / Upper Right Direction in O(1) Time Complexity
    // We use the formula (i + j) for mapping any index in topRight with it's corresponding (i , j) in our ChessBoard

    vector<int> topRight(2 * n , 0) ;

    help(0 , n , chessBoard , ans , col , topLeft , topRight) ;

    return ans ;

}
};

/*
Time Complexity:  O(N!)
Space Complexity: O(N) {For Recursive Stack and For the 3 vectors col[] , topLeft[] , topRight[] we are using in place of isSafe() function } & O(N^2) {For our ans[][] vector}
*/



/*
Note: First go through LECTURE 20 otherwise you will not be able to grasp this concept.

Problem Statement
N Queens

Briefing the problem statement

You are given an integer ‘N’. For a given ‘N’ x ‘N’ chessboard, find a way to place ‘N’ queens such that no queen can attack any other queen on the chessboard.

A queen can be killed when it lies in the same row, same column, or the same diagonal as any of the other queens. You have to print all such configurations.

The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.

In chess, Queen can attack horizontally, vertically, or even diagonally

Example:

 



In a 4 X 4 chessboard, there should be 4 queens and no queen should attack another queen. Same for 8 or any other number.

So how can we place N queens on an N X N chessboard so that no two queens attack each other?

Let’s say we have a 4 X 4 chessboard with us





Example:

Input:

4

Output: 

[0 1 0 0]
[0 0 0 1]
[1 0 0 0]
[0 0 1 0]

First, we should know some points to solve this problem:

1. We need to place N Queens on the N X N chessboard. That means we can only set only one Queen in every row. We cannot skip any row else we cannot solve it. We must return all possible solutions by placing queens in different positions throughout the chessboard.

2. Queens can cancel each other – in the same row, in the same column, on the left diagonal (both up and down), and on the right diagonal (up and down). However, we are placing 1 Queen in every row so we don’t need to check for rows.

3. Also, as we are filling our chessboard in a top-to-the-down manner, we don’t need to check for down Left Diagonal and Down Right Diagonal respectively.

Steps To Solve:

Step 1: We don’t want to check every time in the Column or Upper Left or Right Diagonal respectively. So instead of checking every time. We can use 3 separate arrays/vectors of length n to check if placing a queen at ( i, j) in the board is safe or not. The mapping goes as follows:

For columns: a simple array where cols[i] = 1 if Queen is placed else cols[i] = 0 is sufficient.

For Upper Right Diagonal: we map using (row + col) with index of Upper Right vector, that is, in our Upper Right Diagonal Array UpperLeft [currentRow + currentCol] = 1 if Queen is present in the Upper Right Diagonal of (currentRow, currentCol) else it will be 0.

For Upper Left Diagonal: we map (row – col + n – 1) with the index of the Upper Left vector. If Queen is present UpperLeft[i] = 1 else it will be 0.

Step 2: Now our task is pretty easy. If our row == n, it means we have successfully placed all N-Queens in the chessboard, so we save our current configuration of the board in our vector<vector<int>> and return.

Step 3: Otherwise, we will iterate over all the columns from 0 till n-1 using a for loop and see where we can place a Queen in currentRow or ith row.

Step 4: For check we will declare a isSafe() function which takes currentRow, currentCol, cols[] , UpperLeft[] and UpperRight[] vectors. Or we can simply iterate over all the columns of currentRow, and check the diagonals as well. Whichever suits us better we can use it.

Step 5: Lastly, whenever isSafe() returns true, we will place the Queen at that location and ask recursion to place the rest of the Queens starting from the next Row that is currentRow + 1.

Step 6: At the end, we return our ans[][] from the given function, which contains all possible N-Queens solutions.

Source Code


*/