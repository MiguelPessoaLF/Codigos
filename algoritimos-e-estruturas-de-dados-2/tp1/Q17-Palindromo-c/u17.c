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
int LF_isEqual_Reverse(char array[], int n, int stop, int o, int result)//verifica se o array eh um palindromo, 
//fazendo comparacoes ate metade do array, comparando os primeiros aos ultimos termos de forma recursiva
{
    if (stop >= n/2)
    {
        return result;
    }
    if (array[stop] != array[o])
    {
        result = 0;
    }
    return LF_isEqual_Reverse(array,n,stop + 1,o - 1,result);//chamada recursiva
}
int main(void)//le as entradas linha por linha, e faz as devidas comparacoes
{
    char array[500];
    scanf("%400[^\n]", array);
    while (!LF_isFim(array))
    {
        int tamanho = LF_Size_Of_Char(array);
        if (LF_isEqual_Reverse(array, tamanho,0,tamanho - 1,1))
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