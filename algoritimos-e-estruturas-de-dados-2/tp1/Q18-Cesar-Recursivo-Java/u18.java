public class u18
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
    public static char[] Cesar (char array[], char new_array[], int stop)//funcao recursiva que soma o valor
    //de cada caracter na tabela ascii por 3 para funcionamento da cifra de cesar
    {
        if (stop >= array.length)//condicao de parada
        {
            return new_array;
        }
        new_array[stop] = ((char)(array[stop] + 3));//manipulaçao
        return Cesar(array,new_array,stop + 1);//chamada recursiva
    }
    public static void main (String zzz[])
    {
        //criaçao e transformaçao de arrays paramais facil manipulaçao
        String linhas = MyIO.readLine();
        char[] linha = LF_toCharArray(linhas);
        char[] result = new char[500];
        char[] new_array = new char[500];
        while (!LF_isFim(linha))//condicao de parada
        {
            result = Cesar(linha,new_array,0);
            for (int i = 0; i < linha.length; i++)
            {
            MyIO.print(result[i]);
            }
            System.out.println();//releitura das linhas
            linhas = MyIO.readLine();
            linha = LF_toCharArray(linhas);
        }
    }    
}    