#include <iostream>
#include "PuissanceFour.h"


using namespace std;

int main()
{
    // "vsH" to play versus an human
    // "vsIA" to play versus the computer
    // "IAvsIA" to play IA vs IA (for test only)

    // computer is always the second player

    // all parameters are editable in game

    // For test only
    //PuissanceFour P4(6,7,"Gregory",'x',"Guillaume",'o',"IAvsIA");

    PuissanceFour P4(6,7,"Gregory",'x',"Guillaume",'o',"vsIA");
    P4.launch();

    return 0;

    // Reste à faire :
    //
    // - Securiser les données rentrées (ça plante parfois si pas une valeur attendu)
    //
    // - IA_3 pas encore 100% fonctionnelle
    //
    // - prévoir une methode pour que l'IA joue un coup "interdit"
    //   (par exemple si le seul coup possible donne la victoire à l'adversaire)
    //
    // - gestion de IA_level  perfectible
}
