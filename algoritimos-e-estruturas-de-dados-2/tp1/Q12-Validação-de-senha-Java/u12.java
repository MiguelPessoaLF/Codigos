import java.util.Scanner;
public class u12
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
    public static boolean isValid (char array[])//funcao booleana que verifica cada exigencia da criaçao de uma senha
    {
        int isM = 0;
        int ism = 0;
        int isE = 0;
        int isN = 0;
        if (array.length < 8){return false;}
        for (int i = 0; i < array.length; i++)
        {
            if (array[i] >= 'a' && array[i] <= 'z')//se tem minuscula
            {
                ism = 1;
            }
            if (array[i] >= 'A' && array[i] <= 'Z')//se tem maiuscula
            {
                isM = 1;
            }
            if (array[i] >= '0' && array[i] <= '9')//se tem digito
            {
                isN = 1;
            }
            if ((array[i] >= 32 && array[i] <= 47) || (array[i] >= 58 && array[i] <= 64) || (array[i] >= 91 &&
            array[i] <= 96) || (array[i] >= 123 && array[i] <= 254))//usa a tabela ascii para indentificar caracter especial
            {
                isE = 1;
            }
        }
        if (isM == 1 && isE == 1 && ism == 1 && isN == 1){return true;}//junta tudo e retorna a resposta
        return false;
    }
    public static void main (String zzz[])
    {
        Scanner s = new Scanner(System.in);
        String linhas = s.nextLine();
        char[] linha = LF_toCharArray(linhas);
        while (!LF_isFim(linha))//condicao de parada
        {
            if (isValid(linha)){MyIO.print("SIM");}
            else if (!isValid(linha)){MyIO.print("NAO");}
                System.out.println();//releitura das linhas
                linhas = s.nextLine();
                linha = LF_toCharArray(linhas);
            }
        s.close();
    }    
}