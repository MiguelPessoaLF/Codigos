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
    int get_Tamanho(char array[])//codigo que retorna o tamanho do array
    {
        int o = 0;
        while (array[o] != '\0')
        {
            o++;
        }
        return o;
    }
    int* LF_toInt (char array[],int new_array[], int tamanho)//codigo que transforma o array de char
    //em array de inteiros
    {
        for (int i = 0; i < tamanho;i++)
        {
            new_array[i] = array[i] - '0';
        }
        new_array[tamanho] = '\0';
        return new_array;
    }
    int somar (int array[], int tamanho, int stop, int soma)//funcao que soma os digitos de forma recursiva
    {
        if (stop == tamanho){return soma;}
        soma = soma + array[stop];
        return somar(array,tamanho,stop + 1, soma);
    }
    void main (void)//le as linhas ate a condiçao de parada, usando a funcao recursiva para ler cada
    //linha e inverte-la
    {
        char linha[400];
        int tamanho = 0;
        scanf ("%399[^\n]", linha);
        tamanho = get_Tamanho(linha);
        int* linhai = (int*)malloc((tamanho + 1) * sizeof(int));
        while (!LF_isFim(linha))
        {
            linhai = LF_toInt(linha,linhai,tamanho);
            printf("%d\n", somar(linhai,tamanho,0,0));
            free(linhai);
            scanf (" %399[^\n]", linha);
            tamanho = get_Tamanho(linha);
            linhai = (int*)malloc((tamanho + 1) * sizeof(int));
        }
    }    