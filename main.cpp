#include <iostream>
#include "PuissanceFour.h"

using namespace std;

int main()
{
    // "vsH" to play versus an human
    // "vsIA" to play versus the computer

    // computer is always the second player

    // all parameters are editable in game

    PuissanceFour P4(6,7,"Gregory",'x',"Guillaume",'o',"IAvsIA");
    P4.launch();

    return 0;
}
