#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
struct MyDate
{
    char date_added[50];
    char date_realese[50];
};
typedef struct MyDate Date;
struct Show
{
    char SHOW_ID[450];
    char TYPE[450];
    char TITLE[450];
    char DIRECTOR[450][50];
    char CAST[450][50];
    char COUNTRY[450];
    Date DATE;
    char RATING[450];
    char DURATION[450];
    char LISTED_IN[450][50];
    char DESCRIPTION[450];
    int QUESTION;
};
typedef struct Show show;
char *get_TITLE(show *l)
{
    return l->TITLE;
}
char* get_YEAR (show* l){
    return l->DATE.date_realese;
}
bool LF_isFim(char array[]) // verifica se o array lido é igual a "FIM", usado como condicao de parada
{
    if (array[0] == 'F' && array[1] == 'I' && array[2] == 'M')
    {
        return true;
    }
    return false;
}
int LF_Size_Of_Char(char array[])
{
    int contador = 0;
    for (int i = 0; array[i] != '\0'; i++)
    {
        contador++;
    }
    return contador;
}
bool LF_Equals(char x[], char y[])
{
    if (LF_Size_Of_Char(x) != LF_Size_Of_Char(y))
        return false;
    for (int i = 0; i < LF_Size_Of_Char(x); i++)
    {
        if (x[i] != y[i])
        {
            return false;
        }
    }
    return true;
}
void LF_Clean(char *x)
{
    while (*x)
    {
        *x = '\0';
        x++;
    }
}
bool LF_Bigger(char x[], char y[])
{ // serve para encontrar o tamanho dentre duas strings
    int len = (LF_Size_Of_Char(x) < LF_Size_Of_Char(y)) ? LF_Size_Of_Char(x) : LF_Size_Of_Char(y);
    for (int i = 0; i < len; i++)
    {
        if (x[i] > y[i])
            return true;
        if (x[i] < y[i])
            return false;
    }
    return LF_Size_Of_Char(x) > LF_Size_Of_Char(y);
}
char *LF_Concat(char x[], char y[], char *result)
{
    int len_x = LF_Size_Of_Char(x);
    int len_y = LF_Size_Of_Char(y);

    for (int i = 0; i < len_x; i++)
    {
        result[i] = x[i];
    }
    for (int i = 0; i < len_y; i++)
    {
        result[len_x + i] = y[i];
    }

    result[len_x + len_y] = '\0';

    return result;
}
char *LF_Add(char x[], char y, char *result)
{
    int tam = LF_Size_Of_Char(x);
    int i = 0;
    for (i = 0; i < tam; i++)
    {
        result[i] = x[i];
    }
    result[i] = y;
    result[i + 1] = '\0';
    return result;
}
char *NaN_it(char *x)
{
    x[0] = 'N';
    x[1] = 'a';
    x[2] = 'N';
    for (int i = 3; i < 50; i++)
    {
        x[i] = '\0';
    }
    return x;
}
char *Space_remove(char *str)
{
    int start = 0;
    int end = LF_Size_Of_Char(str) - 1;

    while (start <= end && str[start] == ' ')
        start++;
    while (end >= start && str[end] == ' ')
        end--;
    int j = 0;
    for (int i = start; i <= end; i++)
    {
        str[j++] = str[i];
    }
    str[j] = '\0';
    return str;
}
int LF_Size_Of_show(char arr[][50])
{
    int count = 0;
    for (int i = 0; i < 450; i++)
    {
        if (arr[i][0] == '\0')
            break;
        count++;
    }
    return count;
}
void ord(char arr[50][50], int n)
{
    char temp[50];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}
show *read(show *new_show, char x[])
{ // tive que refazer minha read inteira...
    int i = 0, index = 0, field = 0;
    char temp[500];
    int len = LF_Size_Of_Char(x);
    bool inQuotes = false;
    int castIndex = 0, directorIndex = 0, listedIndex = 0;
    LF_Clean(temp);
    for (int f = 0; f < 450; f++)
    {
        LF_Clean(new_show->CAST[f]);
        LF_Clean(new_show->DIRECTOR[f]);
        LF_Clean(new_show->LISTED_IN[f]);
    }
    while (i <= len)
    {
        if ((x[i] == '"' && x[i + 1] == '"') && inQuotes)
        {
            temp[index++] = '"';
            i += 2;
            continue;
        }
        if (x[i] == '"')
        {
            inQuotes = !inQuotes;
            i++;
            continue;
        }
        if ((x[i] == ',' && !inQuotes) || x[i] == '\0' || x[i] == '\n')
        {
            temp[index] = '\0';
            Space_remove(temp);
            if (LF_Equals(temp, ""))
                NaN_it(temp);

            switch (field)
            {
            case 0:
                strcpy(new_show->SHOW_ID, temp);
                break;
            case 1:
                strcpy(new_show->TYPE, temp);
                break;
            case 2:
                strcpy(new_show->TITLE, temp);
                break;
            case 3:
            {
                char *tok = strtok(temp, ",");
                while (tok)
                {
                    Space_remove(tok);
                    strcpy(new_show->DIRECTOR[directorIndex++], tok);
                    tok = strtok(NULL, ",");
                }
                if (directorIndex == 0)
                    strcpy(new_show->DIRECTOR[0], "NaN");
                break;
            }
            case 4:
            {
                char *tok = strtok(temp, ",");
                while (tok)
                {
                    Space_remove(tok);
                    strcpy(new_show->CAST[castIndex++], tok);
                    tok = strtok(NULL, ",");
                }
                if (castIndex == 0)
                    strcpy(new_show->CAST[0], "NaN");
                break;
            }
            case 5:
                strcpy(new_show->COUNTRY, temp);
                break;
            case 6:
                strcpy(new_show->DATE.date_added, temp);
                break;
            case 7:
                strcpy(new_show->DATE.date_realese, temp);
                break;
            case 8:
                strcpy(new_show->RATING, temp);
                break;
            case 9:
                strcpy(new_show->DURATION, temp);
                break;
            case 10:
            {
                char *tok = strtok(temp, ",");
                while (tok)
                {
                    Space_remove(tok);
                    strcpy(new_show->LISTED_IN[listedIndex++], tok);
                    tok = strtok(NULL, ",");
                }
                if (listedIndex == 0)
                    strcpy(new_show->LISTED_IN[0], "NaN");
                break;
            }
            }
            field++;
            index = 0;
            LF_Clean(temp);
            i++;
            continue;
        }
        temp[index++] = x[i++];
    }
    ord(new_show->CAST, LF_Size_Of_show(new_show->CAST));
    ord(new_show->LISTED_IN, LF_Size_Of_show(new_show->LISTED_IN));
    return new_show;
}
void mark(show *marked_show)
{
    marked_show->QUESTION = 1;
}
void print(show *x)
{
    printf("%s%s%s%s%s%s%s", "=> ", x->SHOW_ID, " ## ", x->TITLE, " ## ", x->TYPE, " ## ");
    if (LF_Equals(x->DIRECTOR[0], "NaN"))
        printf("NaN");
    else
    {
        for (int j = 0; j < LF_Size_Of_show(x->DIRECTOR); j++)
        {
            if (j > 0)
                printf(", ");
            printf("%s", x->DIRECTOR[j]);
        }
    }
    printf(" ## [");
    if (LF_Equals(x->CAST[0], "NaN"))
        printf("NaN");
    else
    {
        for (int j = 0; j < LF_Size_Of_show(x->CAST); j++)
        {
            if (j > 0)
                printf(", ");
            printf("%s", x->CAST[j]);
        }
    }
    printf("%s%s%s%s%s%s%s%s%s%s%s", "] ## ", x->COUNTRY, " ## ", x->DATE.date_added, " ## ", x->DATE.date_realese, " ## ", x->RATING, " ## ", x->DURATION, " ## [");
    if (LF_Equals(x->LISTED_IN[0], "NaN"))
        printf("NaN");
    else
    {
        for (int j = 0; j < LF_Size_Of_show(x->LISTED_IN); j++)
        {
            if (j > 0)
                printf(", ");
            printf("%s", x->LISTED_IN[j]);
        }
    }
    printf("] ##\n");
}
int LF_Size_Of_shows(show arr[])
{
    int count = 0;
    while (arr[count].SHOW_ID[0] != '\0' && count < 1400)
        count++;
    return count;
}
int month_to_number(const char *month)
{ // tradutor de string pra mes
    if (strcmp(month, "January") == 0)
        return 1;
    if (strcmp(month, "February") == 0)
        return 2;
    if (strcmp(month, "March") == 0)
        return 3;
    if (strcmp(month, "April") == 0)
        return 4;
    if (strcmp(month, "May") == 0)
        return 5;
    if (strcmp(month, "June") == 0)
        return 6;
    if (strcmp(month, "July") == 0)
        return 7;
    if (strcmp(month, "August") == 0)
        return 8;
    if (strcmp(month, "September") == 0)
        return 9;
    if (strcmp(month, "October") == 0)
        return 10;
    if (strcmp(month, "November") == 0)
        return 11;
    if (strcmp(month, "December") == 0)
        return 12;
    return 0;
}
time_t parse_date(const char *date_str)
{ // leitor de datas
    char month[20];
    int day, year;
    struct tm tm_date = {0};
    if (sscanf(date_str, "%s %d, %d", month, &day, &year) != 3)
    {
        strcpy((char *)date_str, "March 1, 1900");
        sscanf(date_str, "%s %d, %d", month, &day, &year);
    }
    tm_date.tm_mday = day;
    tm_date.tm_mon = month_to_number(month);
    tm_date.tm_year = year - 1900;
    tm_date.tm_hour = 0;
    tm_date.tm_min = 0;
    tm_date.tm_sec = 0;
    if (tm_date.tm_mon < 0)
    {
        tm_date.tm_mday = 1;
        tm_date.tm_mon = 2;
        tm_date.tm_year = 0;
    }
    return mktime(&tm_date);
}
char *Char_remove(char *x, int i)
{
    int tam = LF_Size_Of_Char(x);
    char *copy = malloc(tam);
    int index = 0;
    for (int a = 0; a < tam; a++)
    {
        if (a != i)
        {
            copy[index++] = x[a];
        }
    }
    copy[index] = '\0';
    return copy;
}
int stringToInt(char *str)
{
    int result = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i] - '0');
        }
    }
    return result;
}
bool startsWith(char texto[], char prefixo[])
{
    if (LF_Size_Of_Char(prefixo) > LF_Size_Of_Char(texto))
    {
        return false;
    }

    for (int i = 0; i < LF_Size_Of_Char(prefixo); i++)
    {
        if (texto[i] != prefixo[i])
        {
            return false;
        }
    }

    return true;
}
int split(const char *str, const char *delimitador, char partes[20][100])
{
    int count = 0;
    char copia[strlen(str) + 1];
    strcpy(copia, str);

    char *token = strtok(copia, delimitador);
    while (token != NULL && count < 20)
    {
        strncpy(partes[count], token, 100 - 1);
        partes[count][100 - 1] = '\0';
        count++;
        token = strtok(NULL, delimitador);
    }

    return count;
}
char *strdup_(const char *s)
{
    if (s == NULL)
        return NULL;

    char *dup = malloc(strlen(s) + 1);
    if (dup != NULL)
    {
        strcpy(dup, s);
    }
    return dup;
}
/*
typedef struct Celula {
    show elemento;
    struct Celula* prox;
} Celula;
typedef struct {
    Celula* primeiro;
    Celula* ultimo;
} Lista;
int tamanhoLista(Lista* l) {
    int tam = 0;
    for (Celula* i = l->primeiro->prox; i != NULL; i = i->prox) {
        tam++;
    }
    return tam;
}
void inicializar(Lista* l) {
    l->primeiro = (Celula*) malloc(sizeof(Celula));
    l->primeiro->prox = NULL;
    l->ultimo = l->primeiro;
}
void inserirInicio(Lista* l, show x) {
    Celula* tmp = (Celula*) malloc(sizeof(Celula));
    tmp->elemento = x;
    tmp->prox = l->primeiro->prox;
    l->primeiro->prox = tmp;

    if (l->primeiro == l->ultimo) {
        l->ultimo = tmp;
    }
}
void inserirFim(Lista* l, show x) {
    l->ultimo->prox = (Celula*) malloc(sizeof(Celula));
    l->ultimo = l->ultimo->prox;
    l->ultimo->elemento = x;
    l->ultimo->prox = NULL;
}
char* removerInicio(Lista* l) {
    if (l->primeiro == l->ultimo) {
        printf("Erro: lista vazia\n");
        exit(1);
    }

    Celula* tmp = l->primeiro->prox;
    show elemento = tmp->elemento;
    l->primeiro->prox = tmp->prox;

    if (tmp == l->ultimo) {
        l->ultimo = l->primeiro;
    }

    free(tmp);
    return strdup_(get_TITLE(&elemento));
}
char* removerFim(Lista* l) {
    if (l->primeiro == l->ultimo) {
        printf("Erro: lista vazia\n");
        exit(1);
    }

    Celula* i;
    for (i = l->primeiro; i->prox != l->ultimo; i = i->prox);

    show elemento = l->ultimo->elemento;
    free(l->ultimo);
    l->ultimo = i;
    l->ultimo->prox = NULL;

    return strdup_(get_TITLE(&elemento));
}

void inserir(Lista* l, show x, int pos) {
    int tamanho = tamanhoLista(l);
    if (pos < 0 || pos > tamanho) {
        printf("Erro: posição inválida\n");
        exit(1);
    } else if (pos == 0) {
        inserirInicio(l, x);
    } else if (pos == tamanho) {
        inserirFim(l, x);
    } else {
        Celula* i = l->primeiro;
        for (int j = 0; j < pos; j++, i = i->prox);

        Celula* tmp = (Celula*) malloc(sizeof(Celula));
        tmp->elemento = x;
        tmp->prox = i->prox;
        i->prox = tmp;
    }
}

char* remover(Lista* l, int pos) {
    int tamanho = tamanhoLista(l);
    if (pos < 0 || pos >= tamanho) {
        printf("Erro: posição inválida\n");
        exit(1);
    } else if (pos == 0) {
        return removerInicio(l);
    } else if (pos == tamanho - 1) {
        return removerFim(l);
    } else {
        Celula* i = l->primeiro;
        for (int j = 0; j < pos; j++, i = i->prox);

        Celula* tmp = i->prox;
        i->prox = tmp->prox;

        show elemento = tmp->elemento;
        free(tmp);
        return strdup_(get_TITLE(&elemento));
    }
}

void mostrar(Lista* l) {
    for (Celula* i = l->primeiro->prox; i != NULL; i = i->prox) {
        print(&i->elemento);
    }
}
*/
#define MAX 1400
typedef struct
{
    show *array;
    int n;
    int capacidade;
} Pilha;
void inicializar_Pilha(Pilha *p)
{
    p->capacidade = 10;
    p->n = 0;
    p->array = malloc(p->capacidade * sizeof(show));
    if (p->array == NULL)
    {
        printf("Erro de alocação\n");
        exit(1);
    }
}
void inserirFim_Pilha(Pilha *p, show x)
{
    if (p->n >= p->capacidade)
    {
        p->capacidade *= 2;
        p->array = realloc(p->array, p->capacidade * sizeof(show));
        if (p->array == NULL)
        {
            printf("Erro ao realocar memória\n");
            exit(1);
        }
    }
    p->array[p->n++] = x;
}
char *removerFim_Pilha(Pilha *p)
{
    if (p->n == 0)
    {
        printf("Pilha vazia!\n");
        exit(1);
    }
    show temp = p->array[--p->n];
    return get_TITLE(&temp);
}
void mostrar_Pilha(Pilha *p)
{
    for (int i = p->n - 1; i >= 0; i--)
    {
        printf("[%d] ", i);
        print(&p->array[i]);
    }
}
void liberar_Pilha(Pilha *p)
{
    free(p->array);
}
#define max 5

typedef struct Celula
{
    show elemento;
    struct Celula *prox;
} Celula;

typedef struct
{
    Celula *inicio;
    Celula *fim;
    int tamanho;
} FilaFlex;

FilaFlex *novaFila()
{
    FilaFlex *f = malloc(sizeof(FilaFlex));
    f->inicio = f->fim = NULL;
    f->tamanho = 0;
    return f;
}

char* remover_Fila(FilaFlex* f) {
    if (f->inicio == NULL) return "";
    Celula* temp = f->inicio;
    show removido = temp->elemento;

    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    f->tamanho--;
    free(temp);
    return get_TITLE(&removido);
}

int get_YearInt(show *x)
{
    return stringToInt(get_YEAR(x));
}

int get_media(FilaFlex *f)
{
    Celula *atual = f->inicio;
    int soma = 0;
    int count = 0;
    while (atual != NULL)
    {
        soma += get_YearInt(&atual->elemento);
        atual = atual->prox;
        count++;
    }
    return (count > 0) ? soma / count : 0;
}

void inserir_Fila(FilaFlex *f, show x)
{
    if (f->tamanho >= max)
    {
        remover_Fila(f);
    }
    Celula *nova = malloc(sizeof(Celula));
    nova->elemento = x;
    nova->prox = NULL;
    if (f->fim == NULL)
    {
        f->inicio = f->fim = nova;
    }
    else
    {
        f->fim->prox = nova;
        f->fim = nova;
    }
    f->tamanho++;
    printf("[Media] %d\n", get_media(f));
}
void mostrar_Fila(FilaFlex* f) {
    Celula* atual = f->inicio;
    int index = 0;

    while (atual != NULL) {
        printf("[%d] ",index);
        print(&atual->elemento);
        atual = atual->prox;
        index++;
    }
}
int main(void)
{
    show *shows = malloc(1400 * sizeof(show));
    memset(shows, 0, 1400 * sizeof(show));
    char line[5000];
    int showIndex = 0;
    FILE *arquivo = fopen("/tmp/disneyplus.csv", "r");
    if (arquivo == NULL)
    {
        arquivo = fopen("disneyplus.csv", "r");
    }
    clock_t start = clock(); // inicia o timer
    int comp = 0;
    int count = 0;
    fgets(line, sizeof(line), arquivo); // pula a primeira linha
    while (fgets(line, sizeof(line), arquivo) && showIndex < 1368)
    { // le e monta o arranjo de shows
        read(&shows[showIndex], line);
        showIndex++;
    }
    fclose(arquivo);
    char array[100];
    scanf("%9[^\n]", array);
    // Lista* l = malloc(sizeof(Lista));
    // Pilha* p = malloc(sizeof(Pilha));
    // inicializar_Pilha(p);
    FilaFlex *f = novaFila();
    // inicializar(l);
    while (!LF_isFim(array))
    {
        int found = 0;
        int pos = 0;
        for (int i = 0; i < showIndex; i++)
        {
            if (LF_Equals(array, shows[i].SHOW_ID))
            {
                found = 1;
                pos = i;
                i = showIndex;
            }
        }
        if (found)
        {
            // print(&shows[pos]);
            // inserir(l, shows[pos], count);
            // inserirFim_Pilha(p, shows[pos]);
            inserir_Fila(f, shows[pos]);
            count++;
            mark(&shows[pos]); // chama mark com o objeto escolhido
        }
        else
        {
            printf("Show com ID %s não encontrado!\n", array);
        }
        scanf(" %9[^\n]", array);
    }
    int n = 0;
    char temp[100];
    scanf("%d", &n);
    scanf("%99[^\n]", temp);
    char partes[20][100];
    int id = 0;
    int trash = 0;
    for (int i = 0; i < n; i++)
    {
        scanf(" %99[^\n]", temp);
        if (startsWith(temp, "I"))
        {
            trash = split(temp, " ", partes);
            id = stringToInt(Char_remove(partes[1], 0));
            inserir_Fila(f, shows[id - 1]);
        }
        else if (startsWith(temp, "R"))
        {
            char* removido = remover_Fila(f);
            printf("(R) %s\n", removido);
        }
        /*
        if (startsWith(temp,"RI")) {
            char* removido = removerInicio(l);
            printf("(R) %s\n", removido);

        } else if (startsWith(temp, "RF")) {
            char* removido = removerFim(l);
            printf("(R) %s\n", removido);

        } else if (startsWith(temp, "II")) {
            trash = split(temp, " ", partes);
            id = stringToInt(Char_remove(partes[1], 0));
            inserirInicio(l, shows[id - 1]);

        } else if (startsWith(temp, "IF")) {
            trash = split(temp, " ", partes);
            id = stringToInt(Char_remove(partes[1], 0));
            inserirFim(l, shows[id - 1]);

        } else if (startsWith(temp, "I*")) {
            trash = split(temp, " ", partes);
            int pos = atoi(partes[1]);
            id = stringToInt(Char_remove(partes[2], 0));
            inserir(l, shows[id - 1], pos);

        } else if (startsWith(temp, "R*")) {
            trash = split(temp, " ", partes);
            int pos = atoi(partes[1]);
            char* removido = remover(l, pos);
            printf("(R) %s\n", removido);
        }
            */
    }
    mostrar_Fila(f);
    clock_t end = clock(); // fim da contagem do tempo
    double total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    FILE *log = fopen("867129_tp3.txt", "w");
    if (log != NULL)
    {
        fprintf(log, "867129\t%.6f\t%d\n", total_time, comp);
        fclose(log);
    }
    else
    {
        fprintf(stderr, "Erro ao criar o arquivo de log.\n");
    }
    return 0;
}