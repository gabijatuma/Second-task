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
#include <algorithm>
#include "tasks.h"

using namespace std;


int main()
{

    srand (time(NULL));

    int what;
    char type = 'v';
    cout<<"pasirinkite konteineri."<<endl<<"1 - list, 2 - vector, 3 - deque."<<endl;

    cin>>what;
    if(what!=1 && what!=2 && what!=3)
    {
        cout<<"ivedete neteisinga pasirinkima. bus pasirinktas list konteineris"<<endl;
        what = 1;
    }

    for(int kiekis = 1000; kiekis <= 10000000; kiekis*=10)
    {
    create(kiekis, type);
    if(what == 1) readfileL(type, kiekis);
    if(what == 2) readfileV(type, kiekis);
    if(what == 3) readfileD(type, kiekis);

    }

    return 0;
}
