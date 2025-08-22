#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
struct MyDate{
    char date_added[50];
    char date_realese[50]; 
};
typedef struct MyDate Date;
struct Show{
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
    int  QUESTION;
};
typedef struct Show show;
char* get_TITLE (show* l){
    return l->TITLE;
}
char* get_YEAR (show* l){
    return l->DATE.date_realese;
}
bool LF_isFim (char array[])//verifica se o array lido é igual a "FIM", usado como condicao de parada 
{
    if (array[0] == 'F' && array[1] == 'I' && array[2] == 'M')
    {
        return true;
    }
    return false;
}
int LF_Size_Of_Char (char array[])
{
    int contador = 0;
    for (int i = 0; array[i] != '\0'; i++)
    {
        contador++;
    }
    return contador;
} 
bool LF_Equals(char x[], char y[]){
    if (LF_Size_Of_Char(x) != LF_Size_Of_Char(y)) return false;
    for (int i = 0; i < LF_Size_Of_Char(x); i++){
        if (x[i] != y[i]){
            return false;
        }
    }
    return true;
}
void LF_Clean (char *x){
    while (*x) {
        *x = '\0';
        x++;
    }
}
bool LF_Bigger (char x[], char y[]) {//serve para encontrar o tamanho dentre duas strings
    int len = (LF_Size_Of_Char(x) < LF_Size_Of_Char(y)) ? LF_Size_Of_Char(x) : LF_Size_Of_Char(y);
    for (int i = 0; i < len; i++) {
        if (x[i] > y[i]) return true;
        if (x[i] < y[i]) return false;
    }
    return LF_Size_Of_Char(x) > LF_Size_Of_Char(y);
}
char* LF_Concat (char x[], char y[], char* result) {
    int len_x = LF_Size_Of_Char(x);
    int len_y = LF_Size_Of_Char(y);

    for (int i = 0; i < len_x; i++) {
        result[i] = x[i];
    }
    for (int i = 0; i < len_y; i++) {
        result[len_x + i] = y[i];
    }

    result[len_x + len_y] = '\0';

    return result;
}
char* LF_Add (char x[], char y, char* result) {
    int tam = LF_Size_Of_Char(x);
    int i = 0;
    for (i = 0; i < tam;i++){
        result[i] = x[i];
    }
    result[i] = y;
    result[i+1] = '\0';
    return result;
}
char* NaN_it (char* x){
    x[0] = 'N';
    x[1] = 'a';
    x[2] = 'N';
    for (int i = 3; i < 50; i++) {
        x[i] = '\0';
    }
    return x;
}
char* Space_remove(char* str){
    int start = 0;
    int end = LF_Size_Of_Char(str) - 1;

    while (start <= end && str[start] == ' ') start++;
    while (end >= start && str[end] == ' ') end--;
    int j = 0;
    for (int i = start; i <= end; i++) {
        str[j++] = str[i];
    }
    str[j] = '\0';
    return str;
}
int LF_Size_Of_show(char arr[][50]) {
    int count = 0;
    for (int i = 0; i < 450; i++) {
        if (arr[i][0] == '\0') break;
        count++;
    }
    return count;
}
void ord(char arr[50][50], int n) {
    char temp[50];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}
show* read(show* new_show, char x[]) {//tive que refazer minha read inteira...
    int i = 0, index = 0, field = 0;
    char temp[500];
    int len = LF_Size_Of_Char(x);
    bool inQuotes = false;
    int castIndex = 0, directorIndex = 0, listedIndex = 0;
    LF_Clean(temp);
    for (int f = 0; f < 450; f++) {
        LF_Clean(new_show->CAST[f]);
        LF_Clean(new_show->DIRECTOR[f]);
        LF_Clean(new_show->LISTED_IN[f]);
    }
    while (i <= len) {
        if ((x[i] == '"' && x[i + 1] == '"') && inQuotes) {
            temp[index++] = '"'; i += 2; continue;
        }
        if (x[i] == '"') {
            inQuotes = !inQuotes;
            i++; continue;
        }
        if ((x[i] == ',' && !inQuotes) || x[i] == '\0' || x[i] == '\n') {
            temp[index] = '\0';
            Space_remove(temp);
            if (LF_Equals(temp, "")) NaN_it(temp);

            switch (field) {
                case 0: strcpy(new_show->SHOW_ID, temp); break;
                case 1: strcpy(new_show->TYPE, temp); break;
                case 2: strcpy(new_show->TITLE, temp); break;
                case 3: {
                    char* tok = strtok(temp, ",");
                    while (tok) {
                        Space_remove(tok);
                        strcpy(new_show->DIRECTOR[directorIndex++], tok);
                        tok = strtok(NULL, ",");
                    }
                    if (directorIndex == 0) strcpy(new_show->DIRECTOR[0], "NaN");
                    break;
                }
                case 4: {
                    char* tok = strtok(temp, ",");
                    while (tok) {
                        Space_remove(tok);
                        strcpy(new_show->CAST[castIndex++], tok);
                        tok = strtok(NULL, ",");
                    }
                    if (castIndex == 0) strcpy(new_show->CAST[0], "NaN");
                    break;
                }
                case 5: strcpy(new_show->COUNTRY, temp); break;
                case 6: strcpy(new_show->DATE.date_added, temp); break;
                case 7: strcpy(new_show->DATE.date_realese, temp); break;
                case 8: strcpy(new_show->RATING, temp); break;
                case 9: strcpy(new_show->DURATION, temp); break;
                case 10: {
                    char* tok = strtok(temp, ",");
                    while (tok) {
                        Space_remove(tok);
                        strcpy(new_show->LISTED_IN[listedIndex++], tok);
                        tok = strtok(NULL, ",");
                    }
                    if (listedIndex == 0) strcpy(new_show->LISTED_IN[0], "NaN");
                    break;
                }
            }
            field++;
            index = 0;
            LF_Clean(temp);
            i++; continue;
        }
        temp[index++] = x[i++];
    }
    ord(new_show->CAST, LF_Size_Of_show(new_show->CAST));
    ord(new_show->LISTED_IN, LF_Size_Of_show(new_show->LISTED_IN));
    return new_show;
}
void mark (show* marked_show){
marked_show->QUESTION = 1;
}
void print (show* x){
    printf("%s%s%s%s%s%s%s", "=> ", x->SHOW_ID, " ## ", x->TITLE, " ## ", x->TYPE, " ## ");
    if (LF_Equals(x->DIRECTOR[0],"NaN")) printf("NaN");
    else{
    for (int j = 0; j < LF_Size_Of_show(x->DIRECTOR); j++) {
        if (j > 0) printf(", ");
        printf("%s", x->DIRECTOR[j]);
    }
    }
    printf(" ## [");
    if (LF_Equals(x->CAST[0],"NaN")) printf("NaN");
    else{
    for (int j = 0; j < LF_Size_Of_show(x->CAST); j++) {
        if (j > 0) printf(", ");
        printf("%s", x->CAST[j]);
    }
    }
    printf("%s%s%s%s%s%s%s%s%s%s%s", "] ## ", x->COUNTRY, " ## ", x->DATE.date_added, " ## ", x->DATE.date_realese, " ## ", x->RATING, " ## ", x->DURATION, " ## [");
    if (LF_Equals(x->LISTED_IN[0],"NaN")) printf("NaN");
    else{
    for (int j = 0; j < LF_Size_Of_show(x->LISTED_IN); j++) {
        if (j > 0) printf(", ");
        printf("%s", x->LISTED_IN[j]);
    }
    }
    printf("] ##\n");
}
int LF_Size_Of_shows(show arr[]) {
    int count = 0;
    while (arr[count].SHOW_ID[0] != '\0' && count < 1400) count++;
    return count;
}
int month_to_number(const char* month) {//tradutor de string pra mes
    if (strcmp(month, "January") == 0) return 1;
    if (strcmp(month, "February") == 0) return 2;
    if (strcmp(month, "March") == 0) return 3;
    if (strcmp(month, "April") == 0) return 4;
    if (strcmp(month, "May") == 0) return 5;
    if (strcmp(month, "June") == 0) return 6;
    if (strcmp(month, "July") == 0) return 7;
    if (strcmp(month, "August") == 0) return 8;
    if (strcmp(month, "September") == 0) return 9;
    if (strcmp(month, "October") == 0) return 10;
    if (strcmp(month, "November") == 0) return 11;
    if (strcmp(month, "December") == 0) return 12;
    return 0;
}
time_t parse_date(const char* date_str) {//leitor de datas
    char month[20];
    int day, year;
    struct tm tm_date = {0};
    if (sscanf(date_str, "%s %d, %d", month, &day, &year) != 3) {
        strcpy((char*)date_str, "March 1, 1900");
        sscanf(date_str, "%s %d, %d", month, &day, &year);
    }
    tm_date.tm_mday = day;
    tm_date.tm_mon = month_to_number(month);
    tm_date.tm_year = year - 1900;
    tm_date.tm_hour = 0;
    tm_date.tm_min = 0;
    tm_date.tm_sec = 0;
    if (tm_date.tm_mon < 0) {
        tm_date.tm_mday = 1;
        tm_date.tm_mon = 2;
        tm_date.tm_year = 0;
    }
    return mktime(&tm_date);
}
char* Char_remove(char* x, int i) {
    int tam = LF_Size_Of_Char(x);
    char* copy = malloc(tam);
    int index = 0;
    for (int a = 0; a < tam; a++) {
        if (a != i) {
            copy[index++] = x[a];
        }
    }
    copy[index] = '\0';
    return copy;
}

typedef struct No {
    show* elemento;
    struct No* esq;
    struct No* dir;
    int altura;
} No;

typedef struct ArvoreAVL {
    No* raiz;
} ArvoreAVL;

No* novoNo(show* elemento) {
    No* no = (No*)malloc(sizeof(No));
    no->elemento = elemento;
    no->esq = NULL;
    no->dir = NULL;
    no->altura = 1;
    return no;
}

int altura(No* no) {
    return (no == NULL) ? 0 : no->altura;
}

int maximo(int a, int b) {
    return (a > b) ? a : b;
}

No* rotacaoDir(No* y) {
    No* x = y->esq;
    No* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = maximo(altura(y->esq), altura(y->dir)) + 1;
    x->altura = maximo(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

No* rotacaoEsq(No* x) {
    No* y = x->dir;
    No* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = maximo(altura(x->esq), altura(x->dir)) + 1;
    y->altura = maximo(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

int getBalance(No* n) {
    return (n == NULL) ? 0 : altura(n->esq) - altura(n->dir);
}

No* inserir(No* no, show* x) {
    if (no == NULL)
        return novoNo(x);

    int cmp = strcmp(x->TITLE, no->elemento->TITLE);
    if (cmp < 0)
        no->esq = inserir(no->esq, x);
    else if (cmp > 0)
        no->dir = inserir(no->dir, x);
    else
        return no;

    no->altura = 1 + maximo(altura(no->esq), altura(no->dir));

    int balance = getBalance(no);

    if (balance > 1 && strcmp(x->TITLE, no->esq->elemento->TITLE) < 0)
        return rotacaoDir(no);

    if (balance < -1 && strcmp(x->TITLE, no->dir->elemento->TITLE) > 0)
        return rotacaoEsq(no);

    if (balance > 1 && strcmp(x->TITLE, no->esq->elemento->TITLE) > 0) {
        no->esq = rotacaoEsq(no->esq);
        return rotacaoDir(no);
    }

    if (balance < -1 && strcmp(x->TITLE, no->dir->elemento->TITLE) < 0) {
        no->dir = rotacaoDir(no->dir);
        return rotacaoEsq(no);
    }

    return no;
}

void inserirNaAVL(ArvoreAVL* a, show* x) {
    a->raiz = inserir(a->raiz, x);
}

void caminharCentral(No* i) {
    if (i != NULL) {
        caminharCentral(i->esq);
        printf("%s\n", i->elemento->TITLE);
        caminharCentral(i->dir);
    }
}

void caminharCentralAVL(ArvoreAVL* a) {
    caminharCentral(a->raiz);
}

bool pesquisar(No* i, const char* x) {
    if (i == NULL) return false;

    int cmp = strcmp(x, i->elemento->TITLE);
    if (cmp == 0) return true;
    else if (cmp < 0) {
        printf("esq ");
        return pesquisar(i->esq, x);
    } else {
        printf("dir ");
        return pesquisar(i->dir, x);
    }
}

bool pesquisarNaAVL(ArvoreAVL* a, const char* x) {
    printf("raiz ");
    return pesquisar(a->raiz, x);
}

ArvoreAVL* novaAVL() {
    ArvoreAVL* a = (ArvoreAVL*)malloc(sizeof(ArvoreAVL));
    a->raiz = NULL;
    return a;
}

int main(void) {
    show* shows = malloc(1400 * sizeof(show));
    memset(shows, 0, 1400 * sizeof(show));

    FILE *arquivo = fopen("/tmp/disneyplus.csv", "r");
    if (arquivo == NULL) {
        arquivo = fopen("disneyplus.csv", "r");
    }

    char line[5000];
    fgets(line, sizeof(line), arquivo); 
    int showIndex = 0;
    while (fgets(line, sizeof(line), arquivo) && showIndex < 1368) {
        read(&shows[showIndex], line);
        showIndex++;
    }
    fclose(arquivo);

    clock_t start = clock(); 
    int comp = 0;

    ArvoreAVL* arvore = novaAVL();

    char input[100];
    scanf(" %99[^\n]", input);

    while (!LF_isFim(input)) {
        for (int i = 0; i < showIndex; i++) {
            if (LF_Equals(input, shows[i].SHOW_ID)) {
                mark(&shows[i]);
                inserirNaAVL(arvore, &shows[i]);
            }
        }
        scanf(" %99[^\n]", input);
    }

    scanf(" %99[^\n]", input);
    while (!LF_isFim(input)) {
        if (pesquisarNaAVL(arvore, input)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        scanf(" %99[^\n]", input);
    }

    clock_t end = clock();
    double total_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    FILE* log = fopen("867129_avl.txt", "w");
    if (log != NULL) {
        fprintf(log, "867129\t%.6f\t%d\n", total_time, comp);
        fclose(log);
    } else {
        fprintf(stderr, "Erro ao criar o arquivo de log.\n");
    }

    return 0;
}
