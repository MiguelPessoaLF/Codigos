import java.util.Scanner;
public class u11 {
static class Celula {
    public int elemento;
    public Celula sup, inf, esq, dir;
    public Celula(int elemento) {
        this.elemento = elemento;
        this.sup = this.inf = this.esq = this.dir = null;
    }
    public Celula() {
        this(0);
    }
}
static class Matriz {
    private Celula inicio;
    private int linhas, colunas;
    public Matriz(int linhas, int colunas) {
        this.linhas = linhas;
        this.colunas = colunas;
        Celula anteriorLinha = null;
        for (int i = 0; i < linhas; i++) {
            Celula atual = new Celula();
            if (i == 0) inicio = atual;

            Celula anteriorColuna = atual;

            for (int j = 1; j < colunas; j++) {
                Celula nova = new Celula();
                anteriorColuna.dir = nova;
                nova.esq = anteriorColuna;
                anteriorColuna = nova;
            }

            if (i > 0) {
                Celula deCima = anteriorLinha;
                Celula deBaixo = atual;
                while (deCima != null && deBaixo != null) {
                    deCima.inf = deBaixo;
                    deBaixo.sup = deCima;
                    deCima = deCima.dir;
                    deBaixo = deBaixo.dir;
                }
            }

            anteriorLinha = atual;
        }
    }
    public void set(int i, int j, int x) {
        Celula c = getCelula(i, j);
        c.elemento = x;
    }

    public int get(int i, int j) {
        return getCelula(i, j).elemento;
    }

    private Celula getCelula(int i, int j) {
        Celula c = inicio;
        for (int a = 0; a < i; a++) c = c.inf;
        for (int b = 0; b < j; b++) c = c.dir;
        return c;
    }
    public Matriz soma(Matriz m) {
        Matriz resp = new Matriz(linhas, colunas);
        for (int i = 0; i < linhas; i++)
            for (int j = 0; j < colunas; j++)
                resp.set(i, j, this.get(i, j) + m.get(i, j));
        return resp;
    }
    public Matriz multiplicacao(Matriz m) {
        Matriz resp = new Matriz(this.linhas, m.colunas);
        for (int i = 0; i < this.linhas; i++) {
            for (int j = 0; j < m.colunas; j++) {
                int soma = 0;
                for (int k = 0; k < this.colunas; k++)
                    soma += this.get(i, k) * m.get(k, j);
                resp.set(i, j, soma);
            }
        }
        return resp;
    }
    public void mostrarDiagonalPrincipal() {
        Celula c = inicio;
        while (c != null) {
            System.out.print(c.elemento + " ");
            c = (c.dir != null && c.inf != null) ? c.dir.inf : null;
        }
        System.out.println();
    }
    public void mostrarDiagonalSecundaria() {
        Celula c = inicio;
        for (int i = 0; i < colunas - 1; i++)
            c = c.dir;

        while (c != null) {
            System.out.print(c.elemento + " ");
            c = (c.esq != null && c.inf != null) ? c.esq.inf : null;
        }
        System.out.println();
    }
    public void mostrar() {
        for (int i = 0; i < linhas; i++) {
            Celula c = getCelula(i, 0);
            for (int j = 0; j < colunas; j++) {
                System.out.print(c.elemento + " ");
                c = c.dir;
            }
            System.out.println();
        }
    }
}
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int casos = sc.nextInt();

        for (int t = 0; t < casos; t++) {
            int l1 = sc.nextInt();
            int c1 = sc.nextInt();
            Matriz m1 = new Matriz(l1, c1);

            for (int i = 0; i < l1; i++)
                for (int j = 0; j < c1; j++)
                    m1.set(i, j, sc.nextInt());
            int l2 = sc.nextInt();
            int c2 = sc.nextInt();
            Matriz m2 = new Matriz(l2, c2);

            for (int i = 0; i < l2; i++)
                for (int j = 0; j < c2; j++)
                    m2.set(i, j, sc.nextInt());
            m1.mostrarDiagonalPrincipal();
            m1.mostrarDiagonalSecundaria();
            Matriz soma = m1.soma(m2);
            if (soma != null) soma.mostrar();
            Matriz mult = m1.multiplicacao(m2);
            if (mult != null) mult.mostrar();
        }
        sc.close();
    }
}

