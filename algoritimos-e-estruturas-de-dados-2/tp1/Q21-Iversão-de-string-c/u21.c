#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
    bool LF_isFim(char array[])//codigo boleano que le o array e diz se ele é igual a "FIM"
    //usado como condicao de parada
    {
        if (array[0] == 'F' && array[1] == 'I' && array[2] == 'M')
        {
            return true;
        }
        return false;
    }
    int get_Tamanho(char array[])
    {
        int o = 0;
        while (array[o] != '\0')
        {
            o++;
        }
        return o;
    }
    char* Reverse (char array[], char reverse[], int tamanho, int i, int o)//codigo que reverte o array a partir da criação de
    //um novo array
    {
        if (i >= 0)
        {
            reverse[o] = array[i];
            reverse = Reverse(array,reverse,tamanho, i - 1, o + 1);//chamada recursiva
        }
        reverse[tamanho] = '\0';//coloca um \0 no final do array
        return reverse;
    }
    void main (void)//le as linhas ate a condiçao de parada, usando a funcao recursiva para ler cada
    //linha e inverte-la
    {
        char linha[400];
        int tamanho = 0;
        scanf ("%399[^\n]", linha);
        tamanho = get_Tamanho(linha);
        char* reverse = (char*)malloc((tamanho + 1) * sizeof(char));
        while (!LF_isFim(linha))
        {
            reverse = Reverse(linha,reverse,tamanho, tamanho - 1, 0);//chama a funçao que reverte os dados
            printf("%s\n", reverse);
            free(reverse); 
            scanf (" %399[^\n]", linha);
            tamanho = get_Tamanho(linha);
            reverse = (char*)malloc((tamanho + 1) * sizeof(char));
        }
    }    