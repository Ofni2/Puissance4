#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:

        Board();
        Board(int rows,int cols);

        virtual ~Board();

        void DisplayBoard();
        void reset();
        int putCoin(int col,char coinType);
        bool checkVictory(int row,int col);

        int getTotalRow();
        int getTotalCol();
        int getCoinsPerCol(int col);
        int getLastCoinPos(int col);

        void test(int row, int col);


    private:

        int m_totalRow;
        int m_totalCol;

        char** m_board;
        int* m_coinsPerCol;
        int* m_lastCoinPerCol;

};

#endif // BOARD_H
