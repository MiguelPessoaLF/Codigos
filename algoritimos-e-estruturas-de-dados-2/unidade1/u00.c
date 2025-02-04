#include <stdio.h>
#include "LF.h"
void main (void)
{
    printf ("Atividades - Miguel Pessoa Lima Ferreira\n");
    int x = 0;
    do
    {
        scanf("%d", &x);
        switch (x)
        {
            case 0:              break;
            case 1: int soma = LF_Soma_To(5); printf("%d\n", soma); break;
            case 2: int fat = LF_Fat(7); printf("%d\n", fat); break;
            case 3: float x = LF_Med(); printf("%7.4f\n", x);break;
            case 4: float y = LF_Pow_Of(3,9); printf ("%7.4lf\n", y); break;
            case 5: float z = LF_Log_Of(8,2); printf ("%7.4lf", z); break;
            default: break;
        }
    }while(x != 0);
}