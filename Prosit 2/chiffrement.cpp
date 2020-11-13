#include "chiffrement.h"
#include <iostream>
#include <math.h>
using namespace std;

/*--------------------------------------------------------------------------------------------*/

char* chiffrement::cryptC1(int* size, char* texte)
{
	const char alpha[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	const char alphaMAJ[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	const char number[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int decalage = 2;
	int antibug;

	for (int i = 0; i < *size; i++)
	{

		for (int n = 0; n < 26; n++)
		{
			if (n + decalage > 26)
			{
				antibug = n + decalage - 26;
			}
			else
			{
				antibug = n + decalage;
			}
			if (texte[i] == alpha[n])
			{
				texte[i] = alpha[antibug];
				break;
			}
		}

		for (int n = 0; n < 26; n++)
		{
			if (n + decalage > 26)
			{
				antibug = n + decalage - 26;
			}
			else
			{
				antibug = n + decalage;
			}
			if (texte[i] == alphaMAJ[n])
			{
				texte[i] = alphaMAJ[antibug];
				break;
			}
		}

		for (int n = 0; n < 10; n++)
		{
			if (n + decalage > 10)
			{
				antibug = n + decalage - 10;
			}
			else
			{
				antibug = n + decalage;
			}
			if (texte[i] == number[n])
			{
				texte[i] = number[antibug];
				break;
			}
		}

	}

	return texte;
}

/*--------------------------------------------------------------------------------------------*/

char* chiffrement::cryptC2(int* size, char* texte)
{
	char texteInt[8];
	for (int i = 0; i < *size; i++)
	{
		int val = int(texte[i]);
		int reverse = 0;
		for (int b = 0; b < 8; b++)
		{
			(val % 2) ? texteInt[reverse] =('1') : 
				texteInt[reverse] = ('0');
			reverse++;
			val /= 2;
		}
		for (int b = 0; b < 8; b++)
		{
			if (b < 2) // on inverse les 2 premiers bits
			{
				if (texteInt[b] == '0')
				{
					val += pow(2, b);
				}
			}
			else if (texteInt[b] == '1') 
			{
				val += pow(2, b);
			}
		}
		texte[i] = char(val);
		
	}
	return texte;
}

/*--------------------------------------------------------------------------------------------*/

char* chiffrement::decryptC1(int* size, char* texte)
{
	const char alpha[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	const char alphaMAJ[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	const char number[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int decalage = 2;
	int antibug;

	for (int i = 0; i < *size; i++)
	{
		for (int n = 0; n < 26; n++)
		{
			if (n - decalage < 0)
			{
				antibug = n - decalage + 26;
			}
			else 
			{
				antibug = n - decalage;
			}
			if (texte[i] == alpha[n])
			{
				texte[i] = alpha[antibug];
				break;
			}
		}

		for (int n = 0; n < 26; n++)
		{
			if (n - decalage < 0)
			{
				antibug = n - decalage + 26;
			}
			else
			{
				antibug = n - decalage;
			}
			if (texte[i] == alphaMAJ[n])
			{
				texte[i] = alphaMAJ[antibug];
				break;
			}
		}

		for (int n = 0; n < 10; n++)
		{
			if (n - decalage < 0)
			{
				antibug = n - decalage + 10;
			}
			else
			{
				antibug = n - decalage;
			}

			if (texte[i] == number[n])
			{
				texte[i] = number[antibug];
				break;
			}
		}
	}

	return texte;
}

/*--------------------------------------------------------------------------------------------*/

char* chiffrement::decryptC2(int* size, char* texte)
{
	char texteInt[8];

	for (int i = 0; i < *size; i++)
	{
		int val = int(texte[i]);
		int reverse = 0;

		for (int b = 0; b < 8; b++)
		{
			(val % 2) ? texteInt[reverse] = ('1') :
				texteInt[reverse] = ('0');
			reverse++;
			val /= 2;
		}
		for (int b = 0; b < 8; b++)
		{
			if (b < 2) // on inverse les 2 premiers bits
			{
				if (texteInt[b] == '0')
				{
					val += pow(2, b);
				}
			}
			else if (texteInt[b] == '1')
			{
				val += pow(2, b);
			}
		}
		texte[i] = char(val);

	}
	return texte;
}

/*--------------------------------------------------------------------------------------------*/