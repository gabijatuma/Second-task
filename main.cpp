#include <iostream>
#include <iomanip>
#include<cstdlib>

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
    int nd[100];//reiketu pakeist kazkaip i dinamine atminti kad nebutu is anksto nusakytas masyvo dydis
    int k=1;
    student S[studk];

    int index=1,
            *array=new int[index];

    for(int ij = 0; ij < studk; ij++)
    {

        sum = 0;
        index = 1;

        cout<<"Iveskite savo varda ir pavarde"<<endl;
        cin>>S[ij].name>>S[ij].surname;
        cout<<"Cia vyks namu darbu pazymiu ivedimas. Jei noresite uzbaigti pazymiu ivedima irasykite 0"<<endl;
        cout<<"jei ivesite netinkama skaiciu, balas bus sugeneruotas atsitiktinai."<<endl;




        do{
            cout<<"Iveskite paazymi "<<endl;
            cin>>array[index-1];
            if(array[index-1]<0 || array[index - 1]>10)
                array[index-1] = 1+(double)rand()/RAND_MAX*9;
            index++;
          }while (array[index-2]!=0);

        for (int i=0;i<index-1;i++){
	        sum+=array[i];
            }

        cout<<"Iveskite savo egzamino rezultata"<<endl;
        cin>>egz;
        if(egz<1 || egz>10)
                egz = 1+(double)rand()/RAND_MAX*9;

        cout<<"Jei norite kad butu skaiciuojamas vidurkis iveskite 'v', o jei norite medianos iveskite 'm'"<<endl;

        cin>>S[ij].type;
        if(S[ij].type=='v')
        {
            S[ij].vid = 0.6*(double)egz + 0.4*((double)sum/(double)(index-2));
        }
        else if(S[ij].type=='m')
        {
            for(int i = 0; i < index-3; i++)
                for(int j = i; j < index - 2; j++)
                {
                    if(array[j]<array[i])
                        swap(array[j], array[i]);
                }




            if((index-1)%2==0)
                S[ij].vid = (double)array[(index-3)/2]*0.4 + (double)egz*0.6;
            else S[ij].vid = (double)(array[(index-4)/2]+array[(index-2)/2])/2*0.4 + (double)egz*0.6;

        }
        delete array;
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
   // else goto 47;

    /*
    int n, egz, sum=0;
    double vid;

    cout<<"Iveskite savo varda ir pavarde"<<endl;
    cin>>name>>surname;
    cout<<name<<" "<<surname;
    cout<<"Kiek atlikote namu darbu?"<<endl;
    cin>>n;
    int nd[n];
    for(int i = 0; i < n; i++)
    {
        cout<<"Koks yra jusu "<<i+1<<" namu darbo ivertinimas?"<<endl;
        cin>>nd[i];
        sum+=nd[i];
    }
    cout<<"Kiek gavote is egzamino?"<<endl;
    cin >> egz;

    vid = 0.6*(double)egz + 0.4*((double)sum/(double)n);

    cout<<"jusu vidurkis yra "<<vid<<endl;*/

    return 0;
}
