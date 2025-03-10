import java.util.Scanner;
public class u09
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
    public static boolean isAnagram (char linha[])// funcao que le duas palavras separadas por "-" e
    //retorna true se for um anagrama.
    {
        int i = 0;
        int p = 0;
        char[] string1 = new char[linha.length];//cria dois arrays para guardar cada palavra
        char[] string2 = new char[linha.length];
        while (linha[i] != '-')//os dois proximos loopings formam cada um dos 2 arrays
        {
            string1[i] = linha[i];
            p++;
            i++;
        }
        i = p + 2;
        p = 0;
        while (i < linha.length)
        {
            string2[p] = linha[i];
            p++;
            i++;
        }
        int anagram = 0;
        for (int o = 0; o < string1.length; o++)//loop duplo que compara cada termo do primeiro array
        //com cada termo do segundo, ignorando se os termos sao maiusculos ou minusculos
        {
            for (int b = 0; b < string2.length; b++)
            {
                if (string1[o] == string2[b] || string1[o] == string2[b] + 32 ||  string1[o] == string2[b] - 32)
                {
                    anagram++;
                    b = string2.length;
                }
            }
        }
        if (anagram == string1.length)//se o somatorio das letras que aparecem em ambos as palavras
        //forem iguais ao tamanho do array, significa que todas as letras do primeiro estao no segundo
        {
            return true;
        }
        return false;
    }
    public static void main (String zzz[])
    {
        Scanner s = new Scanner(System.in);
        String linhas = s.nextLine();
        char[] linha = linhas.toCharArray();
        while (!LF_isFim(linha))//condicao de parada
        {
            if (isAnagram(linha)){MyIO.print("SIM");}
            else if (!isAnagram(linha)){MyIO.print("NÃO");}
                System.out.println();//releitura das linhas
                linhas = s.nextLine();
                linha = linhas.toCharArray();
        }
        s.close();
    }    
}