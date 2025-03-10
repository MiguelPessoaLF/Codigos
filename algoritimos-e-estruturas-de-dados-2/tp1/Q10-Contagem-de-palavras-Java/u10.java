import java.util.Scanner;
public class u10
{
    public static boolean LF_isFim(char array[])//codigo boleano que le o array e diz se ele é igual a "FIM"
    //usado como condicao de parada
    {
        if (array[0] == 'F' && array[1] == 'I' && array[2] == 'M')
        {
            return true;
        }
        return false;
    }
    public static int Words_Count (char array[])//inicia o contador em 1, e adiciona mais uma palavra toda vez que encontrar um espaço,
    //retornando o resultado
    {
        int result = 1;
        for (int i = 0; i < array.length; i++)
        {
            if (array[i] == ' ')
            {
                result++;
            }
        }
        return result;
    }
    public static void main (String zzz[])
    {
        Scanner s = new Scanner(System.in);
        String linhas = s.nextLine();
        char[] linha = linhas.toCharArray();
        int words = 0;
        while (!LF_isFim(linha))//condicao de parada
        {
                words = Words_Count(linha);//funcao de leitura
                System.out.println(words);//releitura das linhas
                linhas = s.nextLine();
                linha = linhas.toCharArray();
        }
        s.close();
    }    
}