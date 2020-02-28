#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>
#include "tasks.h"

using namespace std;


int main()
{

    srand (time(NULL));


    char type;
    cout<<"Jei norite kad butu skaiciuojamas vidurkis iveskite 'v', o jei norite medianos iveskite 'm'"<<endl;
    cin>>type;

    string whichread;
    cout<<"Jei duomenis vesite patys, parasykite 'pats'"<<endl<<"O jei norite duomenis nuskaityti is failo rasykite 'failas'"<<endl;
    cout<<"Jei ivesite neteisingus duomenis, gausite atsitiktini studentu ir vidurkiu sarasa"<<endl;
    cin >> whichread;

    if(whichread == "pats") readscreen(type);
    else if (whichread == "failas") readfile(type);
    else readrandom(type);

    return 0;
}




