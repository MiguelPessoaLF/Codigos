#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int LF_Size_Of_Char (char array[]) //faz a funcao do strlen, conta os elementos do array ate encontrar o \0
{
    int contador = 0;
    for (int i = 0; array[i] != '\0'; i++)
    {
        contador++;
    }
    return contador;
} 
bool LF_isFim (char array[])//verifica se o array lido é igual a "FIM", usado como condicao de parada 
{
    if (array[0] == 'F' && array[1] == 'I' && array[2] == 'M')
    {
        return true;
    }
    return false;
}
bool LF_isEqual_Reverse(char array[], int n)//verifica se o array eh um palindromo, 
//fazendo comparacoes ate metade do array, comparando os primeiros aos ultimos termos.
{
    char array_new[1000];
    int new = 0;
    for (int j = 0; j < n; j++)
    {
        if (array[j] >= 0 || j % 2 == 0)
        {
        array_new[new] = array[j];
        new++;
        }
    }
    if (new % 2 == 0)
    {
    n = new/2;
    }
    else
    {
    n = new/2 + 1;
    }
    int o = new - 1;
    for (int i = 0; i < n; i++)
    {
        if (array_new[i] != array_new[o])
        {
            return false;
        }
        o--;
    }
    return true;
}
int main(void)//le as entradas linha por linha, e faz as devidas comparacoes
{
    char array[500];
    scanf("%400[^\n]", array);
    while (!LF_isFim(array))
    {
        int tamanho = LF_Size_Of_Char(array);
        if (LF_isEqual_Reverse(array, tamanho))
        {
            printf("%s\n", "SIM");
        }
        else
        {
            printf("%s\n", "NAO");
        }
        scanf(" %400[^\n]", array);
    }
    return 0;
}