#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:

        Board();
        Board(int rows,int cols);

        void DisplayBoard();

        void reset();

        int putCoin(int col,char coinType);

        bool checkVictory(int row,int col);

        int getTotalRow();

        int getTotalCol();

        char getCoinType(int row,int col);

        int getCoinsPerCol(int col);

        int* getCoinsPerDirection(int row,int col);

        int getRowOfLastCoin(int col);

        int setCoinType(char CoinPlayer1,char CoinPlayer2);

        int removeCoin(int col);

        virtual ~Board();


    private:

        int m_totalRow;

        int m_totalCol;

        char** m_board;

        int* m_coinsPerCol;

        int* m_coinsPerDirection;

        char m_coinType[2];
};

#endif // BOARD_H
