public class u06
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
    public static boolean isVogal(char array[])//le o array, verifica se todos os termos sao vogais
    {
        for (int i = 0; i < array.length; i++)
        {
            if (array[i] != 'a' && array[i] != 'e' && array[i] != 'i' && array[i] != 'o' && array[i] != 'u' &&
            array[i] != 'A' && array[i] != 'E' && array[i] != 'I' && array[i] != 'O' && array[i] != 'U')
            {
                return false;
            }
        }
        return true;
    }
    public static boolean isConsoante(char array[])//le o array verifica se todos os termos sao consoantes
    {
        for (int i = 0; i < array.length; i++)
        {
            if ((array[i] <= 'a' || array[i] >= 'z') || (array[i] <= 'A' || array[i] >= 'Z'))
            {
                return false;
            }
            else if (array[i] == 'a' || array[i] == 'e' || array[i] == 'i' || array[i] == 'o' || array[i] == 'u' ||
            array[i] == 'A' || array[i] == 'E' || array[i] == 'I' || array[i] == 'O' || array[i] == 'U')
            {
                return false;
            }
        }
        return true;
    }
    public static boolean isInt(char array[])//le o array, verifica se todos os termos sao numeros
    {
        for (int i = 0; i < array.length; i++)
        {
            if (array[i] >= '0' && array[i] <= '9')
            {
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    public static boolean isReal(char array[])//le o array, verifica se todos os termos sao numeros ou
    //se o termo possui virgula ou ponto final, limitando a somente um ponto ou virgula
    {
        int stop = 0;
        for (int i = 0; i < array.length; i++)
        {
            if (array[i] == ',' || array[i] == '.')
            {
                stop++;
            }
            if (array[i] >= '0' && array[i] <= '9'  || (array[i] == ',' || array[i] == '.' ) && stop <= 1)
            {
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    public static void main (String zzz[])
    {
        String linhas = MyIO.readLine();
        char[] linha = linhas.toCharArray();
        while (!LF_isFim(linha))//condicao de parada
        {
                if (isVogal(linha))//testa os casos e mostra SIM ou NAO de acordo com a resposta booleana
                //tambem printa um espaço em todos os casos menos no ultimo
                {
                    MyIO.print("SIM ");
                }
                else
                {
                    MyIO.print("NAO ");
                }
                if (isConsoante(linha))
                {
                    MyIO.print("SIM ");
                }
                else
                {
                    MyIO.print("NAO ");
                }
                if (isInt(linha))
                {
                    MyIO.print("SIM ");
                }
                else
                {
                    MyIO.print("NAO ");
                }
                if (isReal(linha))
                {
                    MyIO.print("SIM");
                }
                else
                {
                    MyIO.print("NAO");
                }
                System.out.println();//releitura das linhas
                linhas = MyIO.readLine();
                linha = linhas.toCharArray();
        }
    }    
}