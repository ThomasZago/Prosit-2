#include "fichier.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*--------------------------------------------------------------------------------------------*/

char* fichier::lecture(int* size, string emplacement)
{
	ifstream fichier(emplacement, ios::in);
	char* test;
	if (fichier)
	{
		string ligne;
		int sizeInt = 0;
		while (getline(fichier, ligne))
		{
			test = new char[ligne.length()];
			for (int i = 0; i < ligne.length(); i++)
			{
				test[i] = ligne[i];
				sizeInt++;
				
			}
			*size = sizeInt;
			return test;
		}
		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier" << endl;
		char erreur[] = "erreur";
		test = erreur;
		return test;
}

/*--------------------------------------------------------------------------------------------*/

void fichier::ecriture(int* size, char* texte, string emplacement)
{
	ofstream fichier(emplacement, ios::out | ios::ate);

	if (fichier)
	{
		for (int i = 0; i < *size; i++)
		{
			fichier.put(texte[i]);
		}

		fichier.close();
	}
	else
		cerr << "Erreur a l'ouverture" << endl;
}

/*--------------------------------------------------------------------------------------------*/