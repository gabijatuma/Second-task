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
    for(int kiekis = 1000; kiekis <= 10000000; kiekis*=10)
    {
    create(kiekis, type);
    readfileV(type, kiekis);
    readfileD(type, kiekis);
    readfileL(type, kiekis);
    cout<<endl;
    }

    return 0;
}
