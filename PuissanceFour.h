#ifndef PUISSANCEFOUR_H
#define PUISSANCEFOUR_H

#include "Player.h"
#include "HumanPlayer.h"
#include "ComputeurPlayer.h"

class PuissanceFour
{


    public:

        PuissanceFour();

        PuissanceFour(int rows,
                      int cols,
                      std::string player1Name="Player_1",
                      char coinType1='o',
                      std::string player2Name="Player_2",
                      char coinType2='x',
                      std::string partyType="vsIA" );


        void launch();

        virtual ~PuissanceFour();

    private:

        void DisplaySettings();

        void initName();

        void initCoinsType();

        void initBoardSize();

        std::string Play();

        Board* m_P4Board;

        Player* m_P4Players[2];
};

#endif // PUISSANCEFOUR_H
