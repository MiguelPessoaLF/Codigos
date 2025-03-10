import java.util.Scanner;
public class u01
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
    public static boolean LF_isReverse(char array[])//le o array e faz comparacoes ate metade do array, 
    //comparando os primeiros termos aos ultimos de forma a indentificar um palindromo
    {
        int o = array.length - 1;
        for (int i = 0; i < array.length/2; i++)
        {
            if (array[i] != array[o])
            {
                return false;
            }
            o--;
        }
        return true;
    }
    public static void main (String[] array)//chama todas as funcoes, faz a leitura inicial, transforma a
    //string lida em um array, depois chama a funcao para comparar o array com "FIM", parando o programa
    //caso seja positivo, depois chama a funcao que indentifica o palindromo, e refaz a leitura da proxima linha
    {
        Scanner s = new Scanner(System.in);
        String linhas = s.nextLine();
        char[] linha = linhas.toCharArray();
        while (!LF_isFim(linha))
        {
            if (LF_isReverse(linha))
            {
                System.out.println("SIM");
            }
            else
            {
                System.out.println("NAO");
            }
        linhas = s.nextLine();
        linha = linhas.toCharArray();
        }
        s.close();
    }
}
