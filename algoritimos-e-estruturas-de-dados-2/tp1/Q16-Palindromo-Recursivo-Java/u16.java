import java.util.Scanner;
public class u16
{
    public static char[] LF_toCharArray(String s)//funcao pessoal equivalente a toCharArray()
    //da classe string
    {
        char[] array = new char[s.length()];
        for (int i = 0; i < array.length; i++)
        {
            array[i] = s.charAt(i);
        }
        return array;
    }
    public static boolean LF_isFim(char array[])//codigo boleano que le o array e diz se ele é igual a "FIM"
    //usado como condicao de parada
    {
        if (array[0] == 'F' && array[1] == 'I' && array[2] == 'M')
        {
            return true;
        }
        return false;
    }
    public static int LF_isReverse(char array[],int stop,int o,int result)//le o array e faz comparacoes ate metade do array, 
    //comparando os primeiros termos aos ultimos de forma a indentificar um palindromo de forma recursiva
    {
            if (stop >= array.length / 2)
            {
                return result;
            }
            if (array[stop] != array[o])
            {
                result = 0;
            }
            return LF_isReverse(array, stop + 1, o - 1, result);//chamada recursiva
    }
    public static void main (String[] array)//chama todas as funcoes, faz a leitura inicial, transforma a
    //string lida em um array, depois chama a funcao para comparar o array com "FIM", parando o programa
    //caso seja positivo, depois chama a funcao que indentifica o palindromo, e refaz a leitura da proxima linha
    {
        Scanner s = new Scanner(System.in);
        String linhas = s.nextLine();
        char[] linha = LF_toCharArray(linhas);
        while (!LF_isFim(linha))
        {
            if (LF_isReverse(linha,0,linha.length - 1,1) == 1)
            {
                System.out.println("SIM");
            }
            else
            {
                System.out.println("NAO");
            }
        linhas = s.nextLine();
        linha = LF_toCharArray(linhas);
        }
        s.close();
    }
}
