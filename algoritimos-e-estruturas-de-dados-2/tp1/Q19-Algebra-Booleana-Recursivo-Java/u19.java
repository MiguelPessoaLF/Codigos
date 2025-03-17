public class u19
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
    public static boolean isB_case1 (int array[], int z)//funcao que verifica o caso 1(and)
    {
        while (array[z] != 9)
        {
        if (array[z] == 0)
        {
            return false;
        }
        z++;
        }
    return true;
    }
    public static boolean isB_case2 (int array[], int z)//funcao que verifica o caso 2(not)
    {
        int t = 0;
        while (array[z] != 9)
        {
        if (array[z] == 1)
        {
            t++;
        }
        z++;
        }
        if (t == 0)
        {
        return true;
        }
        else{return false;}
    }
    public static boolean isB_case3 (int array[], int n, int z)//funcao que verifica o caso 3(or)
    {
        while (array[z] != 9)
        {
        if (array[z] == 1)
        {
            return true;
        }
        z++;
    }
    return false;
    }
    public static int find9 (int array[],int n)//funcao usada para controlar ate onde vai aquela funcao
    //"(" se tornou 8 em intl, e ")" 9. Dessa forma, o algoritimo sabe quando cada função começa e termina
    {
        int nine = 0;
        for (int i = n; i < array.length; i++)
        {
            if (array[i] == 9)
            {
                return nine;
            }
            nine++;
        }
        return nine;
    }
    public static int[] Cut (int array[],int n)//apos resolver certa parte do codigo, retira a parte ja usada
    //na main, substitui todo o interior da funcao pelo resultado da mesma
    //o codigo le cada o array, e retira tudo que estiver contido no 8 e 9
    {
        int[] new_array = new int[array.length];
        int z = find9(array,n) + n;
        int o = 0;
        for (int i = 0; i < array.length; i++)
        {
            if (i < n || i > z)
            {
                new_array[o] = array[i];
                o++;
            }
        }
        return new_array;
    }
    class p //classe do objeto com os dados inicias de cada linha, valor de A,B,C e numero de valores
    {
        char linha[]; int n; int A; int B; int C;
        public p (char linha[],int n, int A, int B, int C)//construtor
        {
            this.linha = linha;
            this.n = n;
            this.A = A;
            this.B = B;
            this.C = C;
        }
        public void remake (char linha[],int n, int A, int B, int C)//remodelagem do objeto
        {
            this.linha = linha;
            this.n = n;
            this.A = A;
            this.B = B;
            this.C = C;
        }
        public void LF_First_Boolean()//a partir da leitura do atributo "linha", separa os valores.
        {
            for (int i = 2; i <= n*2; i++)
            {
                if (i == 2)
                {
                A = (int)(linha[i]) - '0';
                }
                else if (i == 4)
                {
                B = (int)(linha[i]) - '0';
                }
                else if (i == 6)
                {
                C = (int)(linha[i]) - '0';
                }
            }
        }
    };
    public static int Boolean_Result (int intl[],int j,int stop)//funcao que faz a leitura,
    //manipulaçao e teste de dados de forma recursiva
    {
        if (stop < 0){return intl[0];}
        if (intl[stop] == 2 && (isB_case1(intl,stop)))
        {
            intl[stop] = 1;
            intl = Cut (intl,stop + 1);
        }
        else if (intl[stop] == 2 && !(isB_case1(intl,stop)))
        {
            intl[stop] = 0;
            intl = Cut (intl,stop + 1);
        }
        if (intl[stop] == 3)
        {
            if (isB_case2(intl,stop + 1))
            {
                intl[stop] = 1;
                intl = Cut (intl,stop + 1);
            }
            else if (!isB_case2(intl,stop + 1))
            {
                intl[stop] = 0;
                intl = Cut (intl,stop + 1);
            }
        }
        if (intl[stop] == 4 && (isB_case3(intl,j,stop)))
        {
            intl[stop] = 1;
            intl = Cut (intl,stop + 1);
        }
        else if (intl[stop] == 4 && !(isB_case3(intl,j,stop)))
        {
            intl[stop] = 0;
            intl = Cut (intl,stop + 1);
        }
        return Boolean_Result(intl,j,stop - 1);
    };
    public static void main (String zzz[])
    {
        String linhas = MyIO.readLine();//le a linha como string
        char[] linha = LF_toCharArray(linhas);//transforma em um array para mais facil manipulação
        int[] intl = new int[150];
        int A = 0;
        int B = 0;
        int C = 0;
        int j = 0;
        int n = (int)(linha[0]) - '0';//le o dado ascii como inteiro
        u19 objm = new u19();//cria o objeto main
        p obj = objm.new p(linha, n, A, B, C);//cria o objeto p por cima do objeto main
        while (linha[0] != '0')
        {
        obj.LF_First_Boolean();//objeto adiquire os dados inicias
        for (int i = 0; i < linha.length;i++)//transforma o array char em um array de inteiros correspondentes
        {
            if (linha[i] == 'A')
            {
                intl[j] = obj.A;
                j++;
            }
            if (linha[i] == 'B')
            {
                intl[j] = obj.B;
                j++;
            }
            if (linha[i] == 'C')
            {
                intl[j] = obj.C;
                j++;
            }
            if (linha[i] == 'a')
            {
                intl[j] = 2;
                i+=3;
                j++;
            }
            if (linha[i] == 'n')
            {
                intl[j] = 3;
                i+=3;
                j++;
            }
            if (linha[i] == 'o')
            {
                intl[j] = 4;
                i+=2;
                j++;
            }
            if (linha[i] == ',')
            {
                intl[j] = 5;
                j++;
            }
            if (linha[i] == '(')
            {
                intl[j] = 8;
                j++;
            }
            if (linha[i] == ')')
            {
                intl[j] = 9;
                j++;
            }
        }
        int result = Boolean_Result(intl,j,j - 1);
        MyIO.print(result);//no final da manipulaçao, o resultado da função vai estar na primeira casa,
        //portanto, mostra na tela esse resultado
        System.out.println();//passa a linha
        linhas = MyIO.readLine();//repete o processo de montagem do objeto
        linha = LF_toCharArray(linhas);
        A = 0;
        B = 0;
        C = 0;
        j = 0;
        n = (int)(linha[0]) - '0';
        obj.remake(linha, n, A, B, C);
        }
    }    
}