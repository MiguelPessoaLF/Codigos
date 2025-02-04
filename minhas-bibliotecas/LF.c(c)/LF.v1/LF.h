#include <stdio.h>
#include <math.h>
//biblioteca padrão para atividades da unidade 1
//questoes via internet
//u1: conceitos basicos:
//questao 1: soma de numeros ate um valor n
int LF_Soma_To (int n)
{
    int soma = 0;
    for (int i = 0; i <= n; i++)
    {
        soma = soma + i;
    }
    return soma;
}
//questao 2: calculadora de fatorial
int LF_Fat (int n)
{
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        f = i * f;
    }
    return f;
}
//questao 3: media aritimetica 
float LF_Med ()
{
    int x = 0;
    float s= 0.0;
    float soma = 0.0;
    scanf ("%d", &x);
    for (int i = 0; i < x; i++)
    {
        scanf ("%f", &s);
        soma = soma + s;
    }
    float media = soma/x;
    return media;
}
//questao 4: calculadora de potencias
float LF_Pow_Of (double x, double y)
{
    float result = pow(x,y);
    return result;
}
//questao 5: calculadora de log
float LF_Log_Of(float x, float y)
{
    return log(x) / log(y);
}