public class u20
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
    public static int isVogal(char array[],int stop, int vogais)//le o array, verifica se todos os termos sao vogais
    {
        if (stop == array.length){return vogais;}
            if (array[stop] == 'a' || array[stop] == 'e' || array[stop] == 'i' || array[stop] == 'o' || array[stop] == 'u' ||
            array[stop] == 'A' || array[stop] == 'E' || array[stop] == 'I' || array[stop] == 'O' || array[stop] == 'U')
            {
                vogais++;
            }
        return isVogal(array,stop + 1,vogais);
    }
    public static int isConsoante(char array[],int stop, int falso)//le o array verifica se todos os termos sao consoantes
    {
        if (stop == array.length){return falso;}
            if ((array[stop] <= 'a' || array[stop] > 'z') || (array[stop] <= 'A' || array[stop] > 'Z'))
            {
                falso++;
            }
            else if (array[stop] == 'a' || array[stop] == 'e' || array[stop] == 'i' || array[stop] == 'o' || array[stop] == 'u' ||
            array[stop] == 'A' || array[stop] == 'E' || array[stop] == 'I' || array[stop] == 'O' || array[stop] == 'U')
            {
                falso++;
            }
        return isConsoante(array, stop + 1, falso);
    }
    public static int isInt(char array[],int stop,int falso)//le o array, verifica se todos os termos sao numeros
    {
        if (stop == array.length){return falso;}
            if (array[stop] >= '0' && array[stop] <= '9')
            {
            }
            else
            {
                falso++;
            }
        return isInt(array,stop + 1,falso);
    }
    public static int isReal(char array[],int stop,int falso, int parada)//le o array, verifica se todos os termos sao numeros ou
    //se o termo possui virgula ou ponto final, limitando a somente um ponto ou virgula
    {
        if (stop == array.length){return falso;}
        if (array[stop] == ',' || array[stop] == '.'){parada++;}
        if ((array[stop] >= '0' && array[stop] <= '9')){falso = 1;}
        if (parada > 1){falso = 0;}
        return isReal(array,stop + 1,falso,parada);
    }
    public static String is (char linha[])
    {
            String isV = isVogal(linha, 0, 0) == linha.length ? "SIM " : "NAO ";
            String isC = isConsoante(linha, 0, 0) == 0 ? "SIM " : "NAO ";
            String isI = isInt(linha, 0, 0) == 0 ? "SIM " : "NAO ";
            String isR = isReal(linha, 0, 0, 0) == 1 ? "SIM" : "NAO";
            return isV + isC + isI + isR;
    }
    public static void main (String zzz[])
    {
        String linhas = MyIO.readLine();
        char[] linha = LF_toCharArray(linhas);
        while (!LF_isFim(linha))//condicao de parada
        {
            System.out.println(is(linha));//releitura das linhas
            linhas = MyIO.readLine();
            linha = LF_toCharArray(linhas);
        }
    }    
}