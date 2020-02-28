#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

struct student{
        string name, surname;
        double vid;

    };

void readrandom(char ty);
void readcreen(char ty);

void readfile(char ty);
void writefile(vector<student>S, char type);




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

    if(whichread == "pats") readcreen(type);
    else if (whichread == "failas") readfile(type);
    else readrandom(type);

    return 0;
}

void readcreen(char ty)
{
    int egz, sum, index, studk;

    vector<int> v(1);
    cout<<"Kiek strudentu planuojate ivesti?"<<endl;
    cin>>studk;

     vector<student> S(studk);
   //  S.push_back(student());

    for(int ij = 0; ij < studk; ij++)
    {

        sum = 0;
        index = 0;

        cout<<"Iveskite savo varda ir pavarde"<<endl;
        cin>>S[ij].name>>S[ij].surname;
        cout<<"Cia vyks namu darbu pazymiu ivedimas. Jei noresite uzbaigti pazymiu ivedima irasykite 0"<<endl;
        cout<<"jei ivesite netinkama skaiciu, balas bus sugeneruotas atsitiktinai."<<endl;

        do{
            cout<<"Iveskite paazymi "<<endl;
            cin>>v[index];
            if(v[index]<0 || v[index]>10)
                v[index] = 1+(double)rand()/RAND_MAX*9;
            index++;
          }while (v[index-1]!=0);

        for (int i=0;i<index;i++){
	        sum+=v[i];
            }

        cout<<"Iveskite savo egzamino rezultata"<<endl;
        cin>>egz;
        if(egz<0 || egz>10)
                egz = 1+(double)rand()/RAND_MAX*9;


        if(ty=='v')
        {
            S[ij].vid = 0.6*(double)egz + 0.4*((double)sum/(double)(index-1));
        }
        else if(ty=='m')
        {
            for(int i = 0; i < index-2; i++)
                for(int j = i; j < index - 1; j++)
                {
                    if(v[j]<v[i])
                        swap(v[j], v[i]);
                }

            if((index)%2==0) S[ij].vid = (double)v[(index-2)/2]*0.4 + (double)egz*0.6;
            else S[ij].vid = (double)(v[(index-3)/2]+v[(index-1)/2])/2*0.4 + (double)egz*0.6;

            S.push_back(student());
        }
    }

    writefile(S, ty);

}




void readfile(char ty)
{
    ifstream fd("studentai.txt");

    vector<student> st;
     st.push_back(student());

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


    while(!fd.eof())
    {
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
        st.push_back(student());
    }

    fd.close();
    writefile(st, ty);

}

void writefile(vector<student>S, char type)
{

    ofstream fr("kursiokai.txt");

    for (int i=0; i!=S.size()-2; i++)
    {
        for (int j = i; j!=S.size()-1; j++)
        {
            if(S[i].surname>S[j].surname) swap(S[i], S[j]);
                else if (S[i].surname==S[j].surname && S[i].name> S[j].name) swap(S[i], S[j]);
        }
    }

    fr<<"Pavarde             Vardas             Galutinis(vid.) Galutinis(med.)"<<endl;
    fr<<"--------------------------------------------------------------------"<<endl;
    for(auto ij: S)
    {
        fr<<setw(20)<<left<<ij.surname;
        fr<<setw(20)<<left<<ij.name;
        if(type == 'v') fr<<setw(20)<<fixed<<setprecision(2)<<left<<ij.vid;
        else fr<<setw(20)<<left<<ij.vid;
        fr<<endl;
    }
    fr.close();
}





void readrandom(char ty)
{
    int egz, sum, index, studk;
    studk = 1 + (double)rand()/RAND_MAX*10000;



     vector<student> S(studk);
   //  S.push_back(student());

    index = 1+(double)rand()/RAND_MAX*50;
    int v[index];
    int a;

    for(int ij = 0; ij < studk; ij++)
    {

        sum = 0;
        a = rand();
        S[ij].name = "vardas" + to_string(a);
        S[ij].surname = "pavarde" + to_string(a);
        for(int i = 0; i < index; i++)
        {
            v[i] = 1+(double)rand()/RAND_MAX*9;
        }

        for (int i=0;i<index;i++)
        {
	        sum+=v[i];
        }
        egz = 1+(double)rand()/RAND_MAX*9;


        if(ty=='v')
        {
            S[ij].vid = 0.6*(double)egz + 0.4*((double)sum/(double)(index-1));
        }
        else if(ty=='m')
        {
            for(int i = 0; i < index-2; i++)
                for(int j = i; j < index - 1; j++)
                {
                    if(v[j]<v[i])
                        swap(v[j], v[i]);
                }

            if((index)%2==0) S[ij].vid = (double)v[(index-2)/2]*0.4 + (double)egz*0.6;
            else S[ij].vid = (double)(v[(index-3)/2]+v[(index-1)/2])/2*0.4 + (double)egz*0.6;

            S.push_back(student());
        }
    }

    writefile(S, ty);

}
