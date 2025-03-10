public class u07
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
    public static char[] Reverse (char array[])//codigo que reverte o array a partir da criação de
    //um novo array
    {
        int o = 0;
        char[] reverse = new char[array.length];
        for (int i = array.length - 1; i >= 0; i--)
        {
            reverse[o] = array[i];
            o++;
        }
        return reverse;
    }
    public static void main (String zzz[])
    {
        String linhas = MyIO.readLine();
        char[] linha = linhas.toCharArray();
        char[] reverse = new char[linha.length];
        while (!LF_isFim(linha))
        {
        reverse = Reverse(linha);//chama a funçao que reverte os dados
        for (int i = 0; i < linha.length;i++)
        {
            MyIO.print(reverse[i]);
        }
        System.out.println();//reinicia os dados
        linhas = MyIO.readLine();
        linha = linhas.toCharArray();
        }
    }    
}