#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;
string dane[1000];
int licznik = 0;
bool wczytajPlik(string nazwa)
{
	ifstream file;
	string value;
	file.open(nazwa);
	if (!file.good())
		return false;
	while (getline(file, value))
	{
		dane[licznik++] = value;
	};

	file.close();
	return true;
}
int zadA()
{
	int suma = 0;
	for(int i=0; i < licznik; i++)
	{
		if(dane[i].length()%2 == 0){
                suma++;
        }
	}
	return suma;
}
int zadB()
{
	int suma = 0;
	for (int i = 0; i < licznik; i++)
	{
		int zero = 0;
		int jeden = 0;
		string s = dane[i];
		for (int k = 0; k < s.length(); k++)
		{
			char znakwnapisie = s[k];
			if (znakwnapisie == '0'){
                zero++;
            }
			if (znakwnapisie == '1'){
                jeden++;
            }
		}
		if (zero == jeden){
            suma++;
        }
	}
	return suma;
}
void zadC()
{
	int suma = 0;
	int samezera = 0;
	int samejedynki = 0;
	for (int i = 0; i < licznik; i++)
	{
		int zera = 0;
		int jedynki = 0;
		string napis = dane[i];
		for (int k = 0; k < napis.length(); k++)
		{
			char znakwnapisie = napis[k];
			if (znakwnapisie == '0'){
                zera++;
            }
			if (znakwnapisie == '1'){
                jedynki++;
            }
		}
		if (zera == 0){
            samejedynki++;
		}
		if (jedynki == 0){
            samezera++;
		}
	}
	cout << "same zera = " << samezera << endl;
	cout << "same jedynki = " << samejedynki << endl;
}
void zadD()
{
	for (int k = 2; k <= 16; k++)
	{
		int suma = 0;
		for (int i = 0; i < licznik; i++)
		{
			string napis = dane[i];
			if (napis.length() == k)
				suma++;
		}
		cout << "dla " << k << " = " << suma << endl;
	}
}
int main()
{
	string nazwa = "napisy.txt";
	cout << "wczytuje dane z pliku dane.txt" << endl;
	if (!wczytajPlik(nazwa))
		cout << "blad obslugi pliku" << endl;
	cout << "Zad4"<< endl;
	cout << "a):" << endl << zadA() << endl;
	cout << "b):" << endl <<zadB() << endl;
	cout << "c):" << endl;
	zadC();
	cout << "d):" << endl;
	zadD();
	return 0;
}
