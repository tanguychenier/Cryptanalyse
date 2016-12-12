#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define alpha 26
#define TAILLE 100                  /* modifie ici pour un texte de plus de 100 caracteres */

char	caractere[alpha][2] ;
char 	texte[TAILLE] ;                /* texte a analyser */
int 	compte[alpha] ;                 /* pour compter les differentes lettres */
int	total = 0;
float 	pourcent[alpha] ;             /* pour calculer le pourcentage */

void init(void)
{
	int i ;
	for(i=0 ; i<alpha ; i++)
	{
		caractere[i][0]='A'+i;
		caractere[i][1]='a'+i;
		compte[i] = 0 ;
		pourcent[i] = 0 ;
	}
}

int main(int argc, char **argv)
{
	int i, j ;
	init() ;

	if(argc < 2)
	{
		printf("aide : %s <\"texte\"> ",argv[0]) ;
		exit(0) ;
	}

	strcpy(texte, argv[1]) ;

	for (i=0 ; i<strlen(texte) ; i++)
	{
		total++ ;
		for (j=0 ; j<26 ; j++)
		{
			if ((texte[i] == caractere[j][0])||(texte[i] == caractere[j][1]))
				compte[j]++ ;
		}
	}


	printf("Voici l\'analyse de frequence :\n\n");

	for (i=0 ; i<alpha ; i++)
		if (compte[i] != 0)
		{
			pourcent[i] = ( compte[i] * 100 ) / total ;
			printf("\t%.2f%% de %c.\n", pourcent[i], caractere[i][0]);
		}

	return 0 ;
}
