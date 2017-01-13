#include <iostream>
#include "Board.h"

using namespace std;



/**
*
* default constructor with :
*
* ->  m_totalCol=7
* ->  m_totalRow=6
* ->  m_board[][]='.'
* ->  m_coinsPerCol[]=0
*
**/
Board::Board()
{
    m_totalCol=7;
    m_totalRow=6;

    // dynamic allocation of the board
    m_board = new char*[m_totalCol];
    for(int i(0); i < m_totalRow; ++i)
    {
        m_board[i] = new char[m_totalCol];
    }

    // dynamic allocation of the tab coinsPerRow
    m_coinsPerCol=new int[m_totalCol];


    //initialization of the board
    reset();
}



/**
*
* Constructor to create the Board with a size defined by the user
*
* @param[in] : int cols : number of colums
* @param[in] : int rows : number of rows
*
**/
Board::Board(int rows,int cols)
{
    m_totalRow=rows;
    m_totalCol=cols;

    // dynamic allocation of the board
    m_board = new char*[m_totalRow];
    for(int i(0); i < m_totalRow; ++i)
    {
        m_board[i] = new char[m_totalCol];
    }

    // dynamic allocation of the tab coinsPerRow
    m_coinsPerCol=new int[m_totalCol];

    //initialization of the board
    reset();
}



/**
*
* Destructor
*
**/
Board::~Board()
{
    for(int i = 0; i < m_totalCol; ++i){ delete[] m_board[i];}

    delete[] m_board;
    delete[] m_coinsPerCol;
}



/**
*
* Method to empty/init the board
*
* Board are full with '.' and coinsPerCol[] is set to 0
*
**/
void Board::reset()
{
    for (int j(0); j<m_totalCol; j++)
    {
        for (int i(0); i<m_totalRow; i++)
        {
            m_board[i][j]='.';
        }
        m_coinsPerCol[j]=0;
    }
}



/**
*
* Method to display the Board
*
**/
void Board::DisplayBoard()
{
    cout<<endl;

    // display columns index
    for(int i(0);i<m_totalCol;i++)
        cout<<i<<" ";
    cout<<endl;

    // display grid
    for (int i(0); i<m_totalRow; i++)
    {
        for (int j(0); j<m_totalCol; j++)
        {
            cout<<m_board[i][j]<<" ";
        }
        cout<<endl;
    }
}



/**
*
* Method to put a coins in the board
*
* @param[in]  :   int cols        : Index of the colum where to put the coin
* @param[in]  :   char coinType   : Graphics of the coin ('x' or 'o')
* @param[out] :   return          : Return -1 if the coin is put outside the board
*
**/
int Board::putCoin(int col,char coinType)
{
    if (m_coinsPerCol[col]>=m_totalRow || col<0)
    {
        return -1;
    }
    else
    {
        m_board[m_totalRow-(m_coinsPerCol[col])-1][col]=coinType;
        m_coinsPerCol[col]++;
    }

    return 0;

}



/**
*
* Method to count the number of consecutive coins of the same type in a direction
*
*
* Direction 0,1  is the horizontal direction from left to right
* Direction -1,0 is the vertical direction from bottom to top (board[0][0] is the corner at top left)
* Direction 1,1  is a diagonal direction
*
* @param[in]  :   int row        : Row of the coin to consider
* @param[in]  :   int col        : Column of the coin to consider
* @param[in]  :   bool DirCol    : Horizontal direction
* @param[in]  :   bool DirRow    : Vertical direction
* @param[out] :   return         : Returns the number of coins
*
**/
int Board::countCoins(int row,int col,int DirRow,int DirCol)
{
    int counter(0);

    // if we are outside the board return 0
    if ( ( row<0 || row>=m_totalRow ||  col<0 || col>=m_totalCol) ) {return 0;}

    // if coin if on the edge of the board
    if ( ( row+DirRow < 0 || row+DirRow >= m_totalRow ||  col+DirCol < 0 || col+DirCol >= m_totalCol) ) {return 0;}

    // if next coin is empty or different from the previous
    if ( ( m_board[row][col] != m_board[row+DirRow][col+DirCol] ) ||
         ( m_board[row][col] == '.')   )
         {return 0;}

    counter=1+countCoins(row+DirRow,col+DirCol,DirRow,DirCol);

    return counter;
}



/**
*
* Method to check if a coin is in a line of 4
*
* @param[in]  :   int row        : Row of the coin to consider
* @param[in]  :   int col        : Column of the coin to consider
* @param[out] :   return         : Returns "true" if there is a puissance4
*
**/
bool Board::checkVictory(int row,int col)
{
    bool isAVictory(false);

    // check in vertical direction
    if (countCoins(row,col,0,-1)+countCoins(row,col,0,1)+1 >= 4) {isAVictory=true;}

    // check in horizontal direction
    else if (countCoins(row,col,1,0)+countCoins(row,col,-1,0)+1 >= 4) {isAVictory=true;}

    // check in first diagonal direction
    else if (countCoins(row,col,-1,-1)+countCoins(row,col,1,1)+1 >= 4) {isAVictory=true;}

    // check in second diagonal direction
    else if (countCoins(row,col,1,-1)+countCoins(row,col,-1,1)+1 >= 4) {isAVictory=true;}

 return isAVictory;
}



/**
*
* Method to get the number of row in the board
*
* @param[out] : return    : Returns the row number of the board
*
**/
int Board::getTotalRow()
{
    return m_totalRow;
}



/**
*
* Method to get the number of col in the board
*
* @param[out] : return  : Returns the column number of the board
*
**/
int Board::getTotalCol()
{
    return  m_totalCol;
}



/**
*
* Method to get the number of coins in a column
*
* @param[in]  : int col : Index of the column of interest
* @param[out] : return  : Returns the number of coin in the column "col" (and -1 if error)
*
**/
int Board::getCoinsPerCol(int col)
{
    if ( col < 0 || col >= m_totalCol ) { return -1;}

    return m_coinsPerCol[col];
}



/**
*
* Method to get the type of a coin at a position
*
* @param[in]  : int row : Index of the row of interest
* @param[in]  : int col : Index of the column of interest
* @param[out] : return  : Returns the type of the coin
*                         ( ' ' if there is not coins at this position and -1 if error)
*
**/
char Board::getCoinType(int row,int col)
{
if (row < 0 ||row >= m_totalRow || col < 0 ||col >= m_totalCol) {return -1;}

if (m_board[row][col] != '.')
    {
     return m_board[row][col];
    }
    else
    {
        return ' ';
    }
}



/**
*
* Method to get the row of the last coin in a column
*
* @param[in]  : int col : Index of the column of interest
* @param[out] : return  : Returns the row of the coin ( and -1 if error)
*
**/
int Board::getRowOfLastCoin(int col)
{
    if (col < 0 ||col >= m_totalCol) {return -1;}

    return ( getTotalRow()-(getCoinsPerCol(col)) );
}



/**
*
* Method to remove a coin from a column
*
* @param[in]   : int col        : Columns to consider
* @param[out]  : return         : returns -1 if error 0 else
*
**/
int Board::removeCoin(int col)
{
    if (col < 0 ||col >= m_totalCol) {return -1;}

    int coinRow(getRowOfLastCoin(col));

    // if the columns is not empty
    if (m_board[coinRow][col] != '.' )
    {
        m_board[coinRow][col]='.';
        m_coinsPerCol[col]--;
    }

    return 0;
}


