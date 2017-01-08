#include <iostream>
#include "board.h"

using namespace std;

int main()
{
    bool victory;
    Board grille1;

    //grille1.test(1,2);

    grille1.putCoin(1,'o');
    grille1.putCoin(2,'o');
    grille1.putCoin(2,'o');
    grille1.putCoin(3,'x');
    grille1.putCoin(3,'o');
    grille1.putCoin(3,'o');
    grille1.putCoin(4,'o');
    grille1.putCoin(4,'o');
    grille1.putCoin(4,'o');
    grille1.putCoin(4,'o');

    grille1.DisplayBoard();

    int tmp( grille1.getTotalRow()-grille1.getCoinsPerCol(4)  );

    victory=grille1.checkVictory(3,3);

    cout<<"victory? : "<<victory<<endl;

        return 0;
}