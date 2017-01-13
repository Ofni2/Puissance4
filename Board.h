#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:

        // Constructor
        Board();

        Board(int rows,int cols);


        // Set
        int setCoinType(char CoinPlayer1,char CoinPlayer2);


        // Get
        int getTotalRow();

        int getTotalCol();

        char getCoinType(int row,int col);

        int getCoinsPerCol(int col);

        int getRowOfLastCoin(int col);


        // Other methods
        void DisplayBoard();

        void reset();

        int putCoin(int col,char coinType);

        int removeCoin(int col);

        int countCoins(int row,int col,int DirRow,int DirCol);

        bool checkVictory(int row,int col);


        // Destructor
        virtual ~Board();


    private:

        //attributes
        int m_totalRow;

        int m_totalCol;

        char** m_board;

        int* m_coinsPerCol;
};

#endif // BOARD_H
