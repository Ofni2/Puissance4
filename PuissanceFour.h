#ifndef PUISSANCEFOUR_H
#define PUISSANCEFOUR_H

#include "Player.h"
#include "HumanPlayer.h"
#include "ComputeurPlayer.h"

class PuissanceFour
{


    public:

        PuissanceFour();
        PuissanceFour(int rows,int cols,std::string player1Name="Player_1",std::string player2Name="Player_2",std::string partyType="vsIA" );

        std::string Play();

        virtual ~PuissanceFour();

    private:

        Board* m_P4Board;
        Player* m_P4Players[2];

};

#endif // PUISSANCEFOUR_H
