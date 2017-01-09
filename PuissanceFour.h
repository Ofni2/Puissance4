#ifndef PUISSANCEFOUR_H
#define PUISSANCEFOUR_H

#include "Board.h"
#include "Player.h"

class PuissanceFour
{


    public:

        PuissanceFour();
        PuissanceFour(int rows, int cols);

        std::string Play();

        virtual ~PuissanceFour();

    private:



        Board* m_Board;

        int m_numberOfRow;
        int m_numberOfCol;

        Player m_player1;
        Player m_player2;

};

#endif // PUISSANCEFOUR_H
