import java.util.Scanner;
public class u08
{
    public static int Somador (int array[], int stop)//funcao recursiva que soma os termos
    {
        if (stop < 0)//condicao de parada
        {
            return 0;
        }
        int x = array[stop];
        return x + Somador(array, stop - 1);//chamada recursiva que retorna o valor final,
        //soma os valores do array ao resultado da ultima soma
    }
    public static void main (String zzz[])
    {
        Scanner s = new Scanner(System.in);
        String linhas = s.nextLine();
        char[] linha = linhas.toCharArray();
        int[] somar = new int[linha.length];
        while (linha[0] >= '0' && linha [0] <= '9')
        {
        for (int i = 0; i < linha.length; i++)
        {
            somar[i] = (int)(linha[i]) - '0';//usa da tabela ascii para transformar o valor char em
            //inteiro
        }
        System.out.println(Somador(somar,somar.length - 1));
        //reinicia os dados
        linhas = s.nextLine();
        linha = linhas.toCharArray();
        }
        s.close();
    }    
}