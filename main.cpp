#include <iostream>
#include "PuissanceFour.h"

using namespace std;

int main()
{

PuissanceFour p4;
const char* winner=NULL;
string win(" ");


PuissanceFour p4_2(3,3);

win=p4.Play();

cout<<"winner is : "<<win<<endl;

        return 0;
}
