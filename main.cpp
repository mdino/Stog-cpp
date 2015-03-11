#include <iostream>
//#include "polje.h"
#include "pok.h"
#include <cstring>

using namespace std;


int ubr_zena=0;
int ubr_muskih=0;

char status[8][30]= {"neozenjen",
                     "ozenjen",
                     "udovac",
                     "razveden",
                     "neudata",
                     "udata",
                     "udovica",
                     "razvedena"
                    };

void ukrcaj(t_svi_putnici*glavni_stog){
        t_putnik novi;
        cout<<"OIB: ";
        cin>>novi.oib;
        cout<<"Prezime: ";
        cin>>novi.prezime;
        cout<<"Ime: ";
        cin>>novi.ime;
        cout<<"Datum rodenja: ";
        cin>>novi.god;
        cout<<"Spol <m/z> : ";
        cin>>novi.spol;
        if(novi.spol[0]=='m') {
                int random_broj=(rand()%4);
                strcpy(novi.b,status[random_broj]);
                cout<<"OIB: "<<novi.oib<<endl;
                cout<<"Prezime: "<<novi.prezime<<endl;
                cout<<"Ime: "<<novi.ime<<endl;
                cout<<"Dat rodenja: "<<novi.god<<endl;
                cout<<"Spol: "<<novi.spol[0]<<endl;
                cout<<"Bracni status: "<<novi.b<<endl;
                ubr_muskih++;
                ubaci_na_vrh(novi,glavni_stog);
                } 
        else{
                int random_broj=(rand()%4)+4;
                strcpy(novi.b,status[random_broj]);
                cout<<"OIB: "<<novi.oib<<endl;
                cout<<"Prezime: "<<novi.prezime<<endl;
                cout<<"Ime: "<<novi.ime<<endl;
                cout<<"Dat rodenja: "<<novi.god<<endl;
                cout<<"Spol: "<<novi.spol[0]<<endl;
                cout<<"Bracni status: "<<novi.b<<endl;
                ubr_zena++;
                ubaci_na_vrh(novi,glavni_stog);
        }//else
}//ukrcaj

void iskircaj(t_svi_putnici*glavni_stog){
        if(ubr_muskih<5||ubr_zena<5) {
                cout<<"Niste unijeli dovoljan broj osoba!"<<endl;
                return;
        }
        t_svi_putnici*pomocni_stog=new t_svi_putnici;
        Init(pomocni_stog);
        t_putnik p;
        while(IsEmpty(glavni_stog)==false) { 
                p=vrh_stoga(glavni_stog);
                izbaci_sa_vrha(glavni_stog);
                if(!strcmp(p.b,"neozenjen")||(!strcmp(p.b,"neudata"))) {
                        if(2012-p.god>=18&&2012-p.god<=25) {
                                if(p.spol[0]=='m')
                                        ubr_muskih--;
                                else
                                        ubr_zena--;
                        } 
                        else
                                ubaci_na_vrh(p,pomocni_stog);
                } 
                else
                        ubaci_na_vrh(p,pomocni_stog);
        }
        cout<<endl<<endl;
        cout<<"Ispisujem sa dna stoga!!"<<endl;
        while(IsEmpty(pomocni_stog)==false) {
                p=vrh_stoga(pomocni_stog);
                cout<<"OIB: "<<p.oib<<endl;
                cout<<"Prezime: "<<p.prezime<<endl;
                cout<<"Ime: "<<p.ime<<endl;
                cout<<"Dat rodenja: "<<p.god<<endl;
                cout<<"Spol: "<<p.spol[0]<<endl;
                cout<<"Bracni status: "<<p.b<<endl;
                izbaci_sa_vrha(pomocni_stog);
                ubaci_na_vrh(p,glavni_stog);
                cout<<endl<<"................................."<<endl;
        }//while
}//iskircaj

void iskircaj_drugi(t_svi_putnici*glavni_stog){
        if(IsEmpty(glavni_stog)==true)return;
        t_putnik p;
        p=vrh_stoga(glavni_stog);
        izbaci_sa_vrha(glavni_stog);
        iskircaj_drugi(glavni_stog);
        if(2012-p.god>50) {
                if(!strcmp(p.b,"udovica")) {
                        return;
                }//if
        }//if
        cout<<"OIB: "<<p.oib<<endl;
        cout<<"Prezime: "<<p.prezime<<endl;
        cout<<"Ime: "<<p.ime<<endl;
        cout<<"Dat rodenja: "<<p.god<<endl;
        cout<<"Spol: "<<p.spol[0]<<endl;
        cout<<"Bracni status: "<<p.b<<endl;
        cout<<endl<<"................................."<<endl;
        ubaci_na_vrh(p,glavni_stog);
}//iskircaj_drugi


int main(){

        t_svi_putnici*glavni_stog=new t_svi_putnici;
        Init(glavni_stog);
        int izbor;

        do{
                system("cls");
                cout<<"1. Ukrcaj"<<endl;
                cout<<"2. Iskrcaj 1"<<endl;
                cout<<"3. Iskrcaj 2"<<endl;
                cout<<"0. Izlaz"<<endl;
                cout<<"Vas izbor: ";
                cin>>izbor;

                switch(izbor){
                              case 1:
                                   ukrcaj(glavni_stog);
                                   break;
                              case 2:
                                   iskircaj(glavni_stog);
                                   break;
                              case 3:
                                   iskircaj_drugi(glavni_stog);
                                   break;
                }//switch
        system("pause");
        }while(izbor!=0);

        return 0;
}//main

