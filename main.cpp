#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>
#include <chrono>
#include <list>
#include <deque>
#include "tasks.h"

using namespace std;


int main()
{

    srand (time(NULL));


    char type = 'v';
    int kiekis = 1000;
    cout<<"iveskite studentu kieki. 1000, 10000, 100000, 1000000 arba 10000000"<<endl;
    cin>>kiekis;
    if(kiekis<1000 && kiekis > 10000000 && kiekis%10 !=0)
        kiekis = 1000;

    create(kiekis, type);
    readfileV(type, kiekis);
    readfileD(type, kiekis);
    readfileL(type, kiekis);

    return 0;
}




