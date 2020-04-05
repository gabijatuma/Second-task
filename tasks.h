#ifndef TASKS_H_INCLUDED
#define TASKS_H_INCLUDED


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

using namespace std;
using namespace std::chrono;

struct student{
        string name, surname;
        double vid;

    };

//void readrandom(char ty, int studk);



void readfileL(char ty, int k);
void writefileL(list<student>S, char type, int k);
void writetwoL(list<student>S, int k);
void writedeleteL(list<student>S, int k);

void readfileV(char ty, int k);
void writefile(vector<student>S, char type, int k);
void writetwoV(vector<student>S, int k);
void writedeleteV(vector<student>S, int k);



void readfileD(char ty, int k);
void writefileD(deque<student>S, char type, int k);
void writetwoD(deque<student>S, int k);
void writedeleteD(deque<student>S, int k);

void create (int k, char type);
bool sorting (const student& a, const student& b);








#endif // TASKS_H_INCLUDED
