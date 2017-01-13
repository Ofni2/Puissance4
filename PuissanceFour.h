#ifndef PUISSANCEFOUR_H
#define PUISSANCEFOUR_H

#include "Player.h"
#include "HumanPlayer.h"
#include "ComputeurPlayer.h"

class PuissanceFour
{


    public:

        // constructor
        PuissanceFour();

        PuissanceFour(int rows,int cols,std::string player1Name,char coinType1,std::string player2Name,char coinType2,std::string partyType);


        // External methods
        void launch();


        // Destructor
        virtual ~PuissanceFour();


    private:

        // Internal method
        void displaySettings();

        void initName();

        void initCoinsType();

        void initBoardSize();

        void initGameType();

        std::string Play();


        // Attributes
        Board* m_P4Board;

        Player* m_P4Players[2];

        std::string m_gameType;



};

#endif // PUISSANCEFOUR_H
