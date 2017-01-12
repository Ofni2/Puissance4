#include <iostream>
#include "Board.h"

using namespace std;



/**
*
* Method to create the Board with a default size ( 7 columns, 6 Rows)
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

    m_coinsPerDirection=new int[8];


    //initialisation of the board
    reset();
}



/**
*
* Method to create the Board with a size defined by the user
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

    m_coinsPerDirection=new int[8];

    //initialisation of the board
    reset();
}



/**
*
* Method to destruct the Board
*
**/
Board::~Board()
{
    for(int i = 0; i < m_totalCol; ++i)
    {
        delete[] m_board[i];
    }

    delete[] m_board;
    delete[] m_coinsPerCol;
    delete[] m_coinsPerDirection;
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

    for (int i(0);i<8;i++) {m_coinsPerDirection[i]=0;}
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
* Method to check if a coin is in a line of 4
*
* @param[in]  :   int row        : Row of the coin to consider
* @param[in]  :   int col        : Column of the coin to consider
* @param[out] :   return         : Returns "true" if there is a puissance4
*
**/
bool Board::checkVictory(int row,int col)
{
    int i;
    int coinCounter(0);
    //int m_coinsPerDirection[7]={0};
/*

    401
    5x2
    673

    coin at position x
    direction 0 is vertical direction, from the coin to the top of the board
    direction 3 is diagonal direction from top to bottom and left to right

    oXXXo  considering the first X m_coinsPerDirection[2]=3  (first coins is taken into account)
     ^                             m_coinsPerDirection[5]=1  (first coins is taken into account)
*/


// count the number of coins of the same type all around the coins of interest
// be careful if you use checkVictory where the coinType is '.'

//horizontal direction
//--------------------
    coinCounter=1;

    // Sens droite/gauche
    //--------------------
    i=1;
    while( (col-i) >=0 && m_board[row][col-i] == m_board[row][col])
    {
        coinCounter++;
        i++;
    }
    //m_coinsPerDirection[5]=coinCounter;

    // Sens gauche/droite
    //--------------------
    i=1;
    while( (col+i)<m_totalCol &&  m_board[row][col] == m_board[row][col+i])
    {
        coinCounter++;
        i++;
    }

    // Be careful coinCounter is not reset when the sens is changing.
    //m_coinsPerDirection[2]=coinCounter-m_coinsPerDirection[5]+1;

    if (coinCounter>=4)
    {
        return true;
    }


// vertical direction;
//--------------------
    coinCounter=1;

    // Sens bas/haut
    //--------------
    i=1;
    while( (row-i) >=0 && m_board[row-i][col] == m_board[row][col])
    {
        coinCounter++;
        i++;
    }
    //m_coinsPerDirection[0]=coinCounter;

    // Sens haut/bas
    //--------------
    i=1;
    while( (row+i)<m_totalRow &&  m_board[row][col] == m_board[row+i][col])
    {
        coinCounter++;
        i++;
    }
    //m_coinsPerDirection[7]=coinCounter-m_coinsPerDirection[0]+1;

    if (coinCounter>=4)
    {
        return true;
    }


//direction diagonale gauche/droite
//---------------------------------
    coinCounter=1;

    // Sens bas/haut
    //--------------

    i=1;
    while( (col-i) >=0 && (row-i) >=0 && m_board[row-i][col-i] == m_board[row][col])
    {
        coinCounter++;
        i++;
    }
    //m_coinsPerDirection[4]=coinCounter;

    // Sens haut/bas
    //--------------
    i=1;
    while( (col+i) >m_totalCol && (row+i) >m_totalRow && m_board[row+i][col+i] == m_board[row][col])
    {
        coinCounter++;
        i++;
    }
    //m_coinsPerDirection[3]=coinCounter-m_coinsPerDirection[4]+1;


    if (coinCounter>=4)
    {
        return true;
    }



//direction diagonale droite/gauche
//---------------------------------
    coinCounter=1;

    // Sens bas/haut
    //--------------

    i=1;
    while( (col+i) <m_totalCol && (row-i) >=0 && m_board[row-i][col+i] == m_board[row][col])
    {
        coinCounter++;
        i++;
    }
    //m_coinsPerDirection[1]=coinCounter;

    // Sens haut/bas
    //--------------
    i=1;
    while( (col-i) >=0 && (row+i) <m_totalRow && m_board[row+i][col-i] == m_board[row][col])
    {
        coinCounter++;
        i++;
    }
    //m_coinsPerDirection[6]=coinCounter-m_coinsPerDirection[1]+1;


    if (coinCounter>=4)
    {
        return true;
    }


    return false;


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
* Method to get the number of coins in a colum
*
* @param[in]  : int col : Index of the colum of interest
* @param[out] : return  : Returns the number of coin in the column "col"
*
**/
int Board::getCoinsPerCol(int col)
{
return m_coinsPerCol[col];
}


/**
*
* Method to get the number of coins in each direction
* (usefull for IA)
*
* @param[in]  : int col : Index of the colum of interest
* @param[in]  : int dir : Index of the colum of interest
* @param[out] : return  : Returns the number of coin in the column "col"
*
**/
int* Board::getCoinsPerDirection(int row,int col)
{
 // method not optimal, is run for each dir whereas we already know all direction..
    if ( m_board[row][col] !='.')
    {
        checkVictory(row,col);
    }
    return m_coinsPerDirection;
}


/**
*
* Method to get the type of a coin at a position
*
* @param[in]  : int row : Index of the row of interest
* @param[in]  : int col : Index of the column of interest
* @param[out] : return  : Returns the type of the coin
*                         ( ' ' if there is not coins at this position)
*
**/
char Board::getCoinType(int row,int col)
{
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
* @param[out] : return  : Returns the row of the coin
*
**/
int Board::getRowOfLastCoin(int col)
{
    return ( getTotalRow()-(getCoinsPerCol(col)) );

}



/**
*
* Method to get the row of the last coin in a column
*
* @param[in]  : char coinPlayer1   : Graphic used for player 1 coins
* @param[in]  : char coinPlayer2   : Graphic used for player 2 coins
*
**/
int Board::setCoinType(char CoinPlayer1,char CoinPlayer2)
{
    m_coinType[0]=CoinPlayer1;
    m_coinType[1]=CoinPlayer2;
}


/**
*
* Method to remove a coin from a column
*
* @param[in]  : int col
*
**/
int Board::removeCoin(int col)
{
    int coinRow(getRowOfLastCoin(col));

    if ( col>getTotalCol() )
    {
            return -1;
    }
    else if (m_board[coinRow][col] != '.' )
    {
        m_board[coinRow][col]='.';
        m_coinsPerCol[col]--;
    }

    return 0;
}
