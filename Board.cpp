#include <iostream>
#include "Board.h"

using namespace std;



/**
*
* Method to create the Board with a default size
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

    // dynamic allocation of the tab lastCoinPerCol
    m_lastCoinPerCol=new int[m_totalCol];

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

    // dynamic allocation of the tab lastCoinPerCol
    m_lastCoinPerCol=new int[m_totalCol];

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
    delete[] m_lastCoinPerCol;
    delete[] m_coinsPerCol;
}



/**
*
* Method to empty the board
*
**/
void Board::reset()
{
    for (int i(0); i<m_totalRow; i++)
    {
        for (int j(0); j<m_totalCol; j++)
        {
            m_board[i][j]='.';
        }
        m_coinsPerCol[i]=0;
        m_lastCoinPerCol[i]=0;
    }
}



/**
*
* Method to display the Board
*
**/
void Board::DisplayBoard()
{
    //int rows = sizeof(m_board)/sizeof(m_board[0]);
    //int cols = sizeof(m_board[0])/sizeof(m_board[0][0]);

    for (int i(0); i<m_totalRow; i++)
    {
        for (int j(0); j<m_totalCol; j++)
        {
            cout<<m_board[i][j];
        }
        cout<<endl;
    }
}



/**
*
* Method to put a coins in the board
*
* @param[in] :   int cols        : indice of the colum where to put the coin
* @param[in] :   char coinType   : graphics of the coin ('x' or 'o')
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
        m_board[m_totalRow-m_coinsPerCol[col]-1][col]=coinType;
        m_coinsPerCol[col]++;
    }
    return 0;
}



/**
*
* Method to check if a coin is in a line of 4
*
* @param[in] :   int cols        : colum of the coin to consider
* @param[in] :   char coinType   : row of the coin to consider
*
**/
bool Board::checkVictory(int row,int col)
{
    int i;
    int coinCounter(0);

//direction horizontale
    coinCounter=1;

    // Sens droite/gauche
    i=1;
    while( (col-i) >=0 && m_board[row][col-i] == m_board[row][col])
    {
        coinCounter++;
        i++;
    }

    // Sens gauche/droite
    i=1;
    while( (col+i)<m_totalCol &&  m_board[row][col] == m_board[row][col+i])
    {
        coinCounter++;
        i++;
    }

    if (coinCounter==4)
    {
        return true;
    }

//direction verticale;
    coinCounter=1;

    // Sens bas/haut
    i=1;
    while( (row-i) >=0 && m_board[row-i][col] == m_board[row][col])
    {
        coinCounter++;
        i++;
    }

    // Sens haut/bas
    i=1;
    while( (row+i)<m_totalRow &&  m_board[row][col] == m_board[row+i][col])
    {
        coinCounter++;
        i++;
    }

    if (coinCounter==4)
    {
        return true;
    }


//direction diagonale gauche/droite
    coinCounter=1;

    // Sens bas/haut

    i=1;
    while( (col-i) >=0 && (row-i) >=0 && m_board[row-i][col-i] == m_board[row][col])
    {
        coinCounter++;
        i++;
    }
    // Sens haut/bas
    i=1;
    while( (col+i) >m_totalCol && (row+i) >m_totalRow && m_board[row+i][col+i] == m_board[row][col])
    {
        coinCounter++;
        i++;
    }


    if (coinCounter==4)
    {
        return true;
    }



//direction diagonale droite/gauche
    coinCounter=1;

    // Sens bas/haut

    i=1;
    while( (col+i) <m_totalCol && (row-i) >=0 && m_board[row-i][col+i] == m_board[row][col])
    {
        coinCounter++;
        i++;
    }
    // Sens haut/bas
    i=1;
    while( (col-i) >=0 && (row+i) <m_totalRow && m_board[row+i][col-i] == m_board[row][col])
    {
        coinCounter++;
        i++;
    }


    if (coinCounter==4)
    {
        return true;
    }




    return false;


}

/**
*
* Method to get the number of row in the board
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
**/
int Board::getTotalCol()
{
    return  m_totalCol;
}

/**
*
* Method to get the number of coins in a colum
*
* @param[in] int col : index of the colum of interest
*
**/
int Board::getCoinsPerCol(int col)
{
return m_coinsPerCol[col];
}


/**
*
* Method to get the row of the last coin in a column
*
* @param[in] int col : index of the colum of interest
*
**/
int Board::getLastCoinPos(int col)
{

return 0;
}




void Board::test(int row, int col)
{
    reset();
    m_board[row][col]='@';
    DisplayBoard();


}
