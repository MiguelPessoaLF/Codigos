public class u03
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
    public static char[] Cesar (char array[])//funcao recursiva que soma o valor
    //de cada caracter na tabela ascii por 3 para funcionamento da cifra de cesar
    {
        char[] new_array = new char[array.length];
        for (int i = 0; i < array.length; i++)
        {
            new_array[i] = ((char)(array[i] + 3));//manipulaçao
        }
        return new_array;
    }
    public static void main (String zzz[])
    {
        //criaçao e transformaçao de arrays paramais facil manipulaçao
        String linhas = MyIO.readLine();
        char[] linha = linhas.toCharArray();
        char[] result = new char[500];
        while (!LF_isFim(linha))//condicao de parada
        {
            result = Cesar(linha);
            for (int i = 0; i < linha.length; i++)
            {
            MyIO.print(result[i]);
            }
            System.out.println();//releitura das linhas
            linhas = MyIO.readLine();
            linha = linhas.toCharArray();
        }
    }    
}    