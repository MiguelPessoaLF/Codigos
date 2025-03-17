import java.util.Scanner;
public class u11
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
    public static int Subs_abc (char array[])//funcao do formato janela deslizante
    //se baseia em uma cadeia booleana que enquanto nao encontrar um termo repetido, continua andando e aumentando o contador, 
    //ao encontrar um valor repetido, ele guarda o contador, caso seja o maior, e move a janela para
    //o ponto final da ultima analise
    {
        boolean[] caracteres = new boolean[128];//array booleano
        int start = 0;
        int max = 0;
        for (int end = 0; end < array.length; end++)
        {
            char atual = array[end];
            while (caracteres[atual])
            {
                caracteres[array[start]] = false;//trasnforma aquela posicao em false, dessa forma, caracteres repetidos serao
                //considerados erro, e portanto, moverao a janela para a posicao da frente
                start++;//aumenta o contador
            }
            caracteres[atual] = true;//define o caracter que tinha sido transformado em falso pelo codigo
            //anterior em true, e cria a nova janela a partir dele
            if (end - start + 1 > max)//teste se o contador é maior que o ultimo maior contador e troca
            //se necessario, o contador é calculado com a posicao atual, menos o contador que aumentava a cada
            //nova interaçao, somado a 1 para ajustamento
            {
                max = end - start + 1;
            }
        }
        return max;
    }
    public static void main (String zzz[])
    {
        Scanner s = new Scanner(System.in);
        String linhas = s.nextLine();
        char[] linha = LF_toCharArray(linhas);
        int subs = 0;
        while (!LF_isFim(linha))//condicao de parada
        {
                subs = Subs_abc(linha);//funcao de leitura
                System.out.println(subs);//releitura das linhas
                linhas = s.nextLine();
                linha = LF_toCharArray(linhas);
            }
        s.close();
    }    
}