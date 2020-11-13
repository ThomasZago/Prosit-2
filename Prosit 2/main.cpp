#include <iostream>
#include <fstream>
#include <string>
#include "chiffrement.h"
#include "fichier.h"


using namespace std;
#define emplacementEntree string ("C:/Users/Silvio/Desktop/Entree.txt")
#define emplacementSortie string ("C:/Users/Silvio/Desktop/Sortie.txt")

/*--------------------------------------------------------------------------------------------*/
//fonction d'encryptage

void crypt(int securite)
{
	//Initialisation des variables
	chiffrement oC;
	fichier oF;
	char* texte; //le tableau de caractère contenant le message a traiter
	int* sizePtr;
	int size;
	sizePtr = &size; //pointeur pour obtenir le nombre de caractere du message
	texte = oF.lecture(sizePtr, emplacementEntree); //Obtention du message

	switch (securite)
	{
	case 1: //Méthode César
		cout << "Encryptage d'un fichier en securite 1" << endl;
		texte = oC.cryptC1(sizePtr, texte);
		oF.ecriture(sizePtr, texte, emplacementSortie);
		break;
	case 2: // Méthode xOR
		cout << "Encryptage d'un fichier en securite 2" << endl;
		texte = oC.cryptC2(sizePtr, texte);
		oF.ecriture(sizePtr, texte, emplacementSortie);
		break;
	case 3: //Méthode César + xOR
		cout << "Encryptage d'un fichier en securite 3" << endl;
		texte = oC.cryptC1(sizePtr, texte);
		texte = oC.cryptC2(sizePtr, texte);
		oF.ecriture(sizePtr, texte, emplacementSortie);
		break;
	}
}

/*--------------------------------------------------------------------------------------------*/
//fonction de decryptage
void decrypt(int securite)
{
	//Initialisation des variables
	chiffrement oC;
	fichier oF;
	char* texte; //le tableau de caractère contenant le message a traiter
	int* sizePtr;
	int size;
	sizePtr = &size; //pointeur pour obtenir le nombre de caractere du message
	texte = oF.lecture(sizePtr, emplacementEntree); //Obtention du message

	switch (securite)
	{
	case 1:
		cout << "Decryptage d'un fichier en securite 1" << endl;
		texte = oC.decryptC1(sizePtr, texte);
		oF.ecriture(sizePtr, texte, emplacementSortie);
		break;
	case 2:
		cout << "Decryptage d'un fichier en securite 2" << endl;
		texte = oC.decryptC2(sizePtr, texte);
		oF.ecriture(sizePtr, texte, emplacementSortie);
		break;
	case 3:
		cout << "Decryptage d'un fichier en securite 3" << endl;
		texte = oC.decryptC2(sizePtr, texte);
		texte = oC.decryptC1(sizePtr, texte);
		oF.ecriture(sizePtr, texte, emplacementSortie);
		break;
	}
}

/*--------------------------------------------------------------------------------------------*/

int main()
{
	int securite;
	string traitement;
/*--------------------------------------------------------------------------------------------*/

	cout << "Bienvenue dans le systeme de Cryptage/Decryptage" << endl
		<< "Le fichier d'entree se nomme Entree.txt et est present sur votre bureau" << endl
		<< "Veuillez entrer le mode de securite choisi (1/2/3)" << endl;
	cin >> securite;
	cout << "Veuillez le traitement souhaiter (crypt/decrypt)" << endl;
	cin >> traitement;

/*--------------------------------------------------------------------------------------------*/

	if (traitement == "crypt")
	{
		crypt(securite);
	}
	else if (traitement == "decrypt")
	{
		decrypt(securite);
	}
	else
	{
		cout << "ERREUR : Vous avez saisi une mauvaise valeur de traitement." << endl;
	}

	return 0;
}

/*--------------------------------------------------------------------------------------------*/