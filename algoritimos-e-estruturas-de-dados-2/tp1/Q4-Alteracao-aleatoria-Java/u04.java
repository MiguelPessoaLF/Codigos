import java.util.Random;
public class u04
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
    public static void main (String zzz[])//funcao que sorteia dois valores aleatorios controlados pela funcao
    //Random dentro de um intervalo especifico, no caso, os valores na tabela ascii de 'a' ate 'z'
    //depois, ela verifica se o caracter na posicao i tem valor ascii igual ao primeiro valor sorteado
    //se for verdadeiro, ele substitui esse valor pelo caracter de valor ascii referente a segundo valor sorteado
    {
        Random rand = new Random();
        rand.setSeed ( 4 ) ;
        String linhas = MyIO.readLine();
        char[] linha = linhas.toCharArray();
        while (!LF_isFim(linha))
        {
        int a = ('a'+ (Math.abs(rand.nextInt()) %26));
        int b = ('a'+ (Math.abs(rand.nextInt()) %26));
        for (int i = 0; i < linha.length; i++)
        {
            if (linha[i] == (char)(a))
            {
            linha[i] = (char)(b);
            }
            MyIO.print(linha[i]);
        }
        System.out.println();
        linhas = MyIO.readLine();
        linha = linhas.toCharArray();
        }
    }    
}