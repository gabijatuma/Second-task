#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>
#include <chrono>
#include "tasks.h"

using namespace std;


int main()
{

    srand (time(NULL));


    char type = 'v';

    create(1000, type);
    create(10000, type);
    create(100000, type);
    create(1000000, type);
    create(10000000, type);


    return 0;
}
