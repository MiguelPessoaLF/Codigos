#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(void)//le as entradas linha por linha, coloca valores reais em um arquivo, fecha ele,
//e depois abre denovo para ler os dados e mostra-los a partir da ultima linha
{
    FILE* arquivow = fopen("pub.txt","w");//abre o arquivo para escrita
    int n = 0;
    scanf(" %d", &n);//le a primeira linha e guarda para contagem de repeticoes
    getchar();
    double x = 0.0;
    for (int i = 0; i < n; i++)//repete a quantidade de vezes n
    {
    x = 0.0;
    scanf(" %lf", &x);
    fwrite(&x,    sizeof(double),     1,          arquivow);//escreve um numero double no arquivo
         //tipo   tamanho em bytes    contagem    arquivo
    }
    //fecha o arquivo para escrita e abre novamente para leitura
    fclose(arquivow);
    FILE* arquivor = fopen("pub.txt","r");
    double num = 0.0;
    for (int i = n - 1; i >= 0; i--)
    {
        fseek(arquivor, i*8, SEEK_SET);//posiciona a leitura no final do arquivo
        num = 0.0;
        fread(&num, sizeof(double),1,arquivor);//equivalente ao fqrite para lida
        printf ("%g\n", num);//mostra na tela
        //obs: %g mostra o numero real com a quantidade minima de casas decimais
        //escolhe o menor dentre %e(notacao cientifica) e %f(numero real)
    }
    getchar();
    fclose(arquivor);
    return 0;
}