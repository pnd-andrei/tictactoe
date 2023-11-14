#include <iostream>
#include <stdlib.h>

/// X si O

using namespace std;

char v[4][4];
int pozitii_libere = 9;
bool sfarsit;   /// presupunem initial ca jocul nu va avea niciun castigator (va fi egalitate)

void castigator()
{
    for(int i=1; i<=3; ++i)
    {
        if(v[i][1] == v[i][2] && v[i][2] == v[i][3])
        {
            if(v[i][2] == 'X')
                cout<< "Jucatorul 1 a castigat!" <<endl;

            else if(v[i][2] == 'O')
                cout<< "Jucatorul 2 a castigat!" <<endl;

            pozitii_libere = 0;
            sfarsit = true;
        }

        if(v[1][i] == v[2][i] && v[2][i] == v[3][i])
        {
            if(v[2][i] == 'X')
                cout<< "Jucatorul 1 a castigat!" <<endl;

            else if(v[2][i] == 'O')
                cout<< "Jucatorul 2 a castigat!" <<endl;

            pozitii_libere = 0;
            sfarsit = true;
        }
    }

    if(v[1][1] == v[2][2] && v[2][2] == v[3][3])
    {
        if(v[2][2] == 'X')
            cout<< "Jucatorul 1 a castigat!" <<endl;

        else if(v[2][2] == 'O')
            cout<< "Jucatorul 1 a castigat!" <<endl;

        pozitii_libere = 0;
        sfarsit = true;
    }

    if(v[1][3] == v[2][2] && v[2][2] == v[3][1])
    {
        if(v[2][2] == 'X')
            cout<< "Jucatorul 1 a castigat!" <<endl;

        else if(v[2][2] == 'O')
            cout<< "Jucatorul 2 a castigat!" <<endl;

        pozitii_libere = 0;
        sfarsit = true;
    }
}

void afisare_matrice_curenta()
{
    cout<<endl;
    for(int i=1; i<=3; ++i)
    {
        for(int j=1; j<=3; ++j)
            cout<< ' ' << v[i][j] << "   ";
        cout<<endl<<endl;
    }
    cout<<endl;
}

int main()
{
    char k = '1';

    for(int i=1; i<=3; ++i)
        for(int j=1; j<=3; ++j)
            v[i][j] = k++;

    cout<<endl;
    for(int i=1; i<=3; ++i)
    {
        for(int j=1; j<=3; ++j)
            cout<< ' ' << v[i][j] << "   ";
        cout<<endl<<endl;
    }

    char inceput;

    cout<< "Jucatorul 1 joaca cu X." <<endl;
    cout<< "Jucatorul 2 joaca cu O." <<endl;
    cout<< "Se introduc pe rand pozitiile pe care se vor pune X si O incepand cu primul jucator, in matricea alaturata." <<endl<<endl;
    cout<< "Incepeti?   D - da  /  N - nu" <<endl; cin>> inceput;

    if(inceput == 'd' || inceput == 'D')
    {
        int pozitie, reincercare;
        int x = 0, y = 0;
        int mutari_1[5] = {0}, mutari_2[4] = {0};

        while(pozitii_libere)
        {
            /// jucatorul 1

            reincercare = 0;

            again_1:
            system("cls");
            afisare_matrice_curenta();

            if(reincercare == 1)
                cout<< "Introdu o pozitie neocupata!" <<endl;
            cout<< "Jucator 1: "; cin>> pozitie;

            if(pozitie % 3 == 0)
            {
                if((v[pozitie/3][3] != 'O') && (v[pozitie/3][3] != 'X'))
                {
                    v[pozitie/3][3] = 'X';
                    mutari_1[++x] = pozitie;
                    pozitii_libere --;
                }

                else
                {
                    reincercare = 1;
                    goto again_1;
                }
            }

            else
            {
                if((v[pozitie/3 + 1][pozitie%3] != 'O') && (v[pozitie/3 + 1][pozitie%3] != 'X'))
                {
                    v[pozitie/3 + 1][pozitie%3] = 'X';
                    mutari_1[++x] = pozitie;
                    pozitii_libere --;
                }

                else
                {
                    reincercare = 1;
                    goto again_1;
                }
            }

            castigator();

            if(pozitii_libere == 0)
                break;




            /// jucatorul 2

            reincercare = 0;

            again_2:
            system("cls");
            afisare_matrice_curenta();

            if(reincercare == 1)
                cout<< "Introdu o pozitie neocupata!" <<endl;
            cout<< "Jucator 2: "; cin>> pozitie;

            if(pozitie % 3 == 0)
            {
                if((v[pozitie/3][3] != 'X') && (v[pozitie/3][3] != 'O'))
                {
                    v[pozitie/3][3] = 'O';
                    mutari_2[++y] = pozitie;
                    pozitii_libere --;
                }

                else
                {
                    reincercare = 1;
                    goto again_2;
                }
            }

            else
            {
                if((v[pozitie/3 + 1][pozitie%3] != 'X') && (v[pozitie/3 + 1][pozitie%3] != 'O'))
                {
                    v[pozitie/3 + 1][pozitie%3] = 'O';
                    mutari_2[++y] = pozitie;
                    pozitii_libere --;
                }

                else
                {
                    reincercare = 1;
                    goto again_2;
                }
            }

            castigator();
        }

        system("cls");
        afisare_matrice_curenta();
        castigator();

        if(sfarsit == false)
            cout<< "Nimeni nu a castigat!" <<endl;

        cout<<endl;
        cout<< "Mutarile facute pe rand sunt: " <<endl;
        for(int i=1; i<=y; ++i)
        {
            cout<< "Jucator 1: " << mutari_1[i] <<endl;
            cout<< "Jucator 2: " << mutari_2[i] <<endl;
        }
        cout<< "Jucator 1: " << mutari_1[x] <<endl<<endl;
    }

    else if(inceput == 'n' || inceput == 'N')
        cout<< "Ok" <<endl;

    else cout<< "Optiune incorecta!" <<endl;

    return 0;
}
