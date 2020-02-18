#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{

    struct student{
        string name, surname;
        double vid;
        char type;
    };

    int studk;
    cout<<"Kiek strudentu planuojate ivesti?"<<endl;
    cin>>studk;

    int egz, sum;
    int index;
    student S[studk];
    vector<int> v(1);

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
        if(egz<1 || egz>10)
                egz = 1+(double)rand()/RAND_MAX*9;

        cout<<"Jei norite kad butu skaiciuojamas vidurkis iveskite 'v', o jei norite medianos iveskite 'm'"<<endl;

        cin>>S[ij].type;
        if(S[ij].type=='v')
        {
            S[ij].vid = 0.6*(double)egz + 0.4*((double)sum/(double)(index-1));
        }
        else if(S[ij].type=='m')
        {
            for(int i = 0; i < index-2; i++)
                for(int j = i; j < index - 1; j++)
                {
                    if(v[j]<v[i])
                        swap(v[j], v[i]);
                }





            if((index)%2==0)
                S[ij].vid = (double)v[(index-2)/2]*0.4 + (double)egz*0.6;
            else S[ij].vid = (double)(v[(index-3)/2]+v[(index-1)/2])/2*0.4 + (double)egz*0.6;

        }
        //delete v;
    }
    cout<<"Pavarde             Vardas             Galutinis(vid)/Galutinis(med)"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    for(int ij = 0; ij < studk; ij++)
    {
        cout<<setw(20)<<left<<S[ij].surname;
        cout<<setw(20)<<left<<S[ij].name;
        if(S[ij].type == 'v') cout<<setw(10)<<left<<S[ij].vid;
        else cout<<setw(20)<<right<<S[ij].vid;
        cout<<endl;
    }

    return 0;
}
