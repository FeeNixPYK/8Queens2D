#include <iostream>
using namespace std;

int main() {
    int Q[8][8]={0};
    int r, c = 0;
    int solnum = 0;

    /*Place the Queen in upper left square*/
    Q[0][0]=1;
    /* And then go to next column*/
    NC:
    c++;
    if(c==8) goto Print; //End of board.
    r = -1; /*Why?*/
    NR:
    r++; /*Starting at row 0*/
    if(r==8) goto Backtrack; // cannot place a Queen in any row, backtrack one column.

    /* Row test after placing the Q in next column*/
    for (int i=0; i<c; i++){
       if(Q[r][i]==1) goto NR;
    }

    /*Check the diagonals*/
    for (int i=0;(c-i)>-1&&(r-i)>-1;i++){
        if(Q[r-i][c-i]==1) goto NR;
    }
    for(int i=0; (c-i)>-1&&(r+i)<8; i++){
        if(Q[r+i][c-i]==1) goto NR;
    }
    /*When it pass the tests, place a Queen*/
    Q[r][c]=1;
    /*After placing the Queen, move to Next column to place another Queen*/
    goto NC;

    /*Print the result*/
    Print:
    solnum++;
    cout << "Solution number: #" << solnum <<"#" << endl;
    for(int r=0; r<8;r++){
        for(int c=0; c<8; c++){
            cout << Q[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl; // separate prints.

    /*Backtrack one column to try another solution*/
    Backtrack:
    /* go back one column */
    c--;
    if(c==-1) {
        cout << "There are total of " << solnum << " solutions";
        return 0; // run out of column, all solutions found.
    }
    r=0; // set r to zero to search for the queen in the column.
    while(Q[r][c]!=1) r++; //searching every row in the same column for the Queen.
    Q[r][c] = 0; // removes the previous Queen placed.
    goto NR; // put the Queen in next row in the same column.
}
