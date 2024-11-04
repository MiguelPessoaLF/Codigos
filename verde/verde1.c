#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <wchar.h>
#include <iso646.h>
int cad (int repeticoes)
{
	int valores[80];
	int soma = 0;
	int media = 0;
	int medi = 0;
	int med = 0;
	for (int i = 0; i < repeticoes; i = i + 1)
		{
			scanf ("%d", &valores[i]);
			soma = soma + valores[i];
		}
	med = soma / repeticoes;
	for (int j = 0; j < repeticoes; j = j + 1)
		{
			if (valores[j] == med)
			{
				medi = medi + 1;
				if (media == 0)
				{
				if (medi == 2)
				{
					medi = 1;
					media = 1;
				}
				}
			}
		}
	printf ("%d %d %d", repeticoes, soma, media);
}
int main (void)
{
	char cadeia[80];
	int repeticoes = 0;
	scanf ("%d", &repeticoes);
	cad(repeticoes);
}