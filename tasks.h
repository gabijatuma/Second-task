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
void readfileV(char ty, int k);
void readfileD(char ty, int k);
void readfileL(char ty, int k);
void writefile(vector<student>S, char type, int k);
void writefileD(deque<student>S, char type, int k);
void writefileL(list<student>S, char type, int k);
void create (int k, char type);
bool sorting (const student& a, const student& b);





void readfileV(char ty, int k) try
{
    auto start = high_resolution_clock::now();
    ifstream fd;
    string filename;
    filename = "studentai" + to_string(k);
    fd.open( filename.c_str() );
    if(fd.good())
    {
    vector<student> st;

    int egz, sum, index, counter = 0;
    string random;
    int cnt = -1;
    fd >> random >> random;
    while(random!="Egz.")
    {
        fd >> random;
        cnt++;
    }



    int v[cnt];

    for(int kk = 0; kk < k; kk++)
    {
        st.push_back(student());
        fd >> st[counter].name >> st[counter].surname;
        sum = 0;
        index = 0;

        for(int i = 0; i < cnt; i++)
        {
            fd >> v[i];
            if(v[i]<0 || v[i]>10)
                v[i] = 1+(double)rand()/RAND_MAX*9;
            index++;
        }
        fd >> egz;
        fd.ignore();
        if(egz<0 || egz>10)
                egz = 1+(double)rand()/RAND_MAX*9;

        for (int i=0;i<cnt;i++)
        {
	        sum+=v[i];
        }

        if(ty=='v')
        {
            st[counter].vid = 0.6*(double)egz + 0.4*((double)sum/(double)(index-1));
        }
        else if(ty=='m')
        {
            for(int i = 0; i < index-2; i++)
                for(int j = i; j < index - 1; j++)
                {
                    if(v[j]<v[i])
                        swap(v[j], v[i]);
                }

            if((index)%2==0) st[counter].vid = (double)v[(index-2)/2]*0.4 + (double)egz*0.6;
            else st[counter].vid = (double)(v[(index-3)/2]+v[(index-1)/2])/2*0.4 + (double)egz*0.6;

        }

        counter++;
    }

    fd.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << k << " studentu irasu nuskaitymas i 'vector' uztruko: " <<(double)duration.count()/1000000 << " sekundziu "<<endl;

        for (int i=0; i!=st.size()-2; i++)
    {
        for (int j = i; j!=st.size()-1; j++)
        {
            if(st[i].surname>st[j].surname) swap(st[i], st[j]);
                else if (st[i].surname==st[j].surname && st[i].name> st[j].name) swap(st[i], st[j]);
        }
    }

    writefile(st, ty, k);
    }

    else
    {
        throw 1;
    }

}

catch(...)
    {
        cout<<"Reikalingas failas nebuvo rastas."<<endl;
    }










    void readfileD(char ty, int k) try
{
    auto start = high_resolution_clock::now();
    ifstream fd;
    string filename;
    filename = "studentai" + to_string(k);
    fd.open( filename.c_str() );
    if(fd.good())
    {
    deque<student> st;

    int egz, sum, index, counter = 0;
    string random;
    int cnt = -1;
    fd >> random >> random;
    while(random!="Egz.")
    {
        fd >> random;
        cnt++;
    }
    {
    int v[cnt];
    for(int kk = 0; kk < k; kk++)
    {
        st.push_back(student());
        fd >> st[counter].name >> st[counter].surname;
        sum = 0;
        index = 0;

        for(int i = 0; i < cnt; i++)
        {
            fd >> v[i];
            if(v[i]<0 || v[i]>10)
                v[i] = 1+(double)rand()/RAND_MAX*9;
            index++;
        }
        fd >> egz;
        fd.ignore();
        if(egz<0 || egz>10)
                egz = 1+(double)rand()/RAND_MAX*9;

        for (int i=0;i<cnt;i++)
        {
	        sum+=v[i];
        }

        if(ty=='v')
        {
            st[counter].vid = 0.6*(double)egz + 0.4*((double)sum/(double)(index-1));
        }
        else if(ty=='m')
        {
            for(int i = 0; i < index-2; i++)
                for(int j = i; j < index - 1; j++)
                {
                    if(v[j]<v[i])
                        swap(v[j], v[i]);
                }

            if((index)%2==0) st[counter].vid = (double)v[(index-2)/2]*0.4 + (double)egz*0.6;
            else st[counter].vid = (double)(v[(index-3)/2]+v[(index-1)/2])/2*0.4 + (double)egz*0.6;

        }

        counter++;
    }

    fd.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << k << " studentu irasu nuskaitymas i 'deque' uztruko: " <<(double)duration.count()/1000000 << " sekundziu "<<endl;

        for (int i=0; i!=st.size()-2; i++)
    {
        for (int j = i; j!=st.size()-1; j++)
        {
            if(st[i].surname>st[j].surname) swap(st[i], st[j]);
                else if (st[i].surname==st[j].surname && st[i].name> st[j].name) swap(st[i], st[j]);
        }
    }


    writefileD(st, ty, k);
    }
    }
    else
    {
        throw 1;
    }

}

catch(...)
    {
        cout<<"Reikalingas failas nebuvo rastas."<<endl;
    }









void readfileL(char ty, int k) try
{
    auto start = high_resolution_clock::now();
    ifstream fd;
    string filename;
    filename = "studentai" + to_string(k);
    fd.open( filename.c_str() );
    if(fd.good())
    {
    list<student> st;

    int egz, sum, index;
    string random;
    int cnt = -1;
    fd >> random >> random;
    while(random!="Egz.")
    {
        fd >> random;
        cnt++;
    }
    {
//string nm, srnm;
    student one;
            //st.push_back(student());
    int v[cnt];
    for(int kk = 0; kk < k; kk++)
    {
        fd >> one.name >> one.surname;

        sum = 0;
        index = 0;

        for(int i = 0; i < cnt; i++)
        {
            fd >> v[i];
            if(v[i]<0 || v[i]>10)
                v[i] = 1+(double)rand()/RAND_MAX*9;
            index++;
        }
        fd >> egz;
        fd.ignore();
        if(egz<0 || egz>10)
                egz = 1+(double)rand()/RAND_MAX*9;

        for (int i=0;i<cnt;i++)
        {
	        sum+=v[i];
        }

        if(ty=='v')
        {
            one.vid = 0.6*(double)egz + 0.4*((double)sum/(double)(index-1));
        }
        else if(ty=='m')
        {
            for(int i = 0; i < index-2; i++)
                for(int j = i; j < index - 1; j++)
                {
                    if(v[j]<v[i])
                        swap(v[j], v[i]);
                }

            if((index)%2==0) one.vid = (double)v[(index-2)/2]*0.4 + (double)egz*0.6;
            else one.vid = (double)(v[(index-3)/2]+v[(index-1)/2])/2*0.4 + (double)egz*0.6;

        }
        st.push_back(one);
    }

    fd.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << k << " studentu irasu nuskaitymas i 'list' uztruko: " <<(double)duration.count()/1000000 << " sekundziu "<<endl;


    st.sort(sorting);

    writefileL(st, ty, k);
    }
    }
    else
    {
        throw 1;
    }

}

catch(...)
    {
        cout<<"Reikalingas failas nebuvo rastas."<<endl;
    }







bool sorting (const student& a, const student& b)
{
    return a.name > b.name;
}




void writefile(vector<student>S, char type, int k)
{

    ofstream frg;
    ofstream frb;
    string filename;
    filename = "VECTORgerieji" + to_string(k);
    frg.open( filename.c_str() );
    filename = "VECTORblogieji" + to_string(k);
    frb.open( filename.c_str() );




    frg<<"Pavarde             Vardas             Galutinis(vid.) Galutinis(med.)"<<endl;
    frg<<"--------------------------------------------------------------------"<<endl;

    frb<<"Pavarde             Vardas             Galutinis(vid.) Galutinis(med.)"<<endl;
    frb<<"--------------------------------------------------------------------"<<endl;

    auto start = high_resolution_clock::now();
    for(auto ij: S)
    {
       if(ij.vid < 5.0)
       {
        frb<<setw(20)<<left<<ij.surname;
        frb<<setw(20)<<left<<ij.name;
        frb<<setw(20)<<fixed<<setprecision(2)<<left<<ij.vid;
        frb<<endl;
       }
       else
       {
        frg<<setw(20)<<left<<ij.surname;
        frg<<setw(20)<<left<<ij.name;
        frg<<setw(20)<<fixed<<setprecision(2)<<left<<ij.vid;
        frg<<endl;
       }



    }
    frg.close();
    frb.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << S.size() << " studentu irasymas i atitinkamus failus uztruko: " <<(double)duration.count()/1000000 << " sekundziu "<<endl;
}



void writefileD(deque<student>S, char type, int k)
{

    ofstream frg;
    ofstream frb;
    string filename;
    filename = "DEQUEgerieji" + to_string(k);
    frg.open( filename.c_str() );
    filename = "DEQUEblogieji" + to_string(k);
    frb.open( filename.c_str() );




    frg<<"Pavarde             Vardas             Galutinis(vid.) Galutinis(med.)"<<endl;
    frg<<"--------------------------------------------------------------------"<<endl;

    frb<<"Pavarde             Vardas             Galutinis(vid.) Galutinis(med.)"<<endl;
    frb<<"--------------------------------------------------------------------"<<endl;

    auto start = high_resolution_clock::now();
    for(auto ij: S)
    {
       if(ij.vid < 5.0)
       {
        frb<<setw(20)<<left<<ij.surname;
        frb<<setw(20)<<left<<ij.name;
        frb<<setw(20)<<fixed<<setprecision(2)<<left<<ij.vid;
        frb<<endl;
       }
       else
       {
        frg<<setw(20)<<left<<ij.surname;
        frg<<setw(20)<<left<<ij.name;
        frg<<setw(20)<<fixed<<setprecision(2)<<left<<ij.vid;
        frg<<endl;
       }



    }
    frg.close();
    frb.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << S.size() << " studentu irasymas i atitinkamus failus uztruko: " <<(double)duration.count()/1000000 << " sekundziu "<<endl;
}




void create (int k, char type)
{
    ofstream f;
    string filename;
    filename = "studentai" + to_string(k);
    f.open( filename.c_str() );

     int a;
    f <<setw(20)<<left<<"vardas"<<setw(20)<<left<<"pavarde"<<setw(20)<<left<<"ND1"<<setw(20)<<left<<"ND2"<<setw(20)<<left<<"ND3"<<setw(20)<<left<<"ND4"<<setw(20)<<left<<"ND5"<<setw(20)<<left<<"ND6"<<setw(20)<<left<<"ND7"<<setw(20)<<left<<"ND8"<<setw(20)<<left<<"ND9"<<setw(20)<<left<<"ND10"<<setw(20)<<left<<"ND11"<<setw(20)<<left<<"ND12"<<setw(20)<<left<<"ND13"<<setw(20)<<left<<"ND14"<<setw(20)<<left<<"ND15"<<setw(20)<<left<<"Egz."<<endl;
    for(int i = 0; i < k; i++)
    {
        a = rand();
        f <<setw(20)<<left<< "vardas" + to_string(a);
        f <<setw(20)<<left<< "pavarde" + to_string(a);

        for(int i = 0; i <= 15; i++)
            f <<setw(20)<<left<<(int)( 1+(double)rand()/RAND_MAX*9);
        f << endl;

    }
    f.close();


}



void writefileL(list<student>S, char type, int k)
{

    ofstream frg;
    ofstream frb;
    string filename;
    filename = "LISTgerieji" + to_string(k);
    frg.open( filename.c_str() );
    filename = "LISTblogieji" + to_string(k);
    frb.open( filename.c_str() );




    frg<<"Pavarde             Vardas             Galutinis(vid.) Galutinis(med.)"<<endl;
    frg<<"--------------------------------------------------------------------"<<endl;

    frb<<"Pavarde             Vardas             Galutinis(vid.) Galutinis(med.)"<<endl;
    frb<<"--------------------------------------------------------------------"<<endl;

    auto start = high_resolution_clock::now();
    for(auto ij: S)
    {
       if(ij.vid < 5.0)
       {
        frb<<setw(20)<<left<<ij.surname;
        frb<<setw(20)<<left<<ij.name;
        frb<<setw(20)<<fixed<<setprecision(2)<<left<<ij.vid;
        frb<<endl;
       }
       else
       {
        frg<<setw(20)<<left<<ij.surname;
        frg<<setw(20)<<left<<ij.name;
        frg<<setw(20)<<fixed<<setprecision(2)<<left<<ij.vid;
        frg<<endl;
       }



    }
    frg.close();
    frb.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << S.size() << " studentu irasymas i atitinkamus failus uztruko: " <<(double)duration.count()/1000000 << " sekundziu "<<endl;
}








#endif // TASKS_H_INCLUDED
