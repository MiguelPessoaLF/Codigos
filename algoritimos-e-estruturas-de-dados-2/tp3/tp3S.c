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
#define MAX 1400
typedef struct {
    show array[MAX];
    int n;
} ListaArranjo;
void inicializar(ListaArranjo* l) {
    l->n = 0;
}
void inserirInicio(ListaArranjo* l, show x) {
    if (l->n >= MAX) {
        printf("Lista cheia!\n");
        exit(1);
    }
    for (int i = l->n; i > 0; i--) {
        l->array[i] = l->array[i - 1];
    }
    l->array[0] = x;
    l->n++;
}

void inserirFim(ListaArranjo* l, show x) {
    if (l->n >= MAX) {
        printf("Lista cheia!\n");
        exit(1);
    }
    l->array[l->n++] = x;
}

void inserir(ListaArranjo* l, show x, int pos) {
    if (l->n >= MAX || pos < 0 || pos > l->n) {
        printf("Posição inválida!\n");
        exit(1);
    }
    for (int i = l->n; i > pos; i--) {
        l->array[i] = l->array[i - 1];
    }
    l->array[pos] = x;
    l->n++;
}

char* removerInicio(ListaArranjo* l) {
    if (l->n == 0) {
        printf("Lista vazia!\n");
        exit(1);
    }
    show temp = l->array[0];
    for (int i = 0; i < l->n - 1; i++) {
        l->array[i] = l->array[i + 1];
    }
    l->n--;
    return get_TITLE(&temp);
}

char* removerFim(ListaArranjo* l) {
    if (l->n == 0) {
        printf("Lista vazia!\n");
        exit(1);
    }
    show temp = l->array[--l->n];
    return get_TITLE(&temp);
}

char* remover(ListaArranjo* l, int pos) {
    if (l->n == 0 || pos < 0 || pos >= l->n) {
        printf("Posição inválida!\n");
        exit(1);
    }
    show temp = l->array[pos];
    for (int i = pos; i < l->n - 1; i++) {
        l->array[i] = l->array[i + 1];
    }
    l->n--;
    return get_TITLE(&temp);
}

void mostrar(ListaArranjo* l) {
    for (int i = 0; i < l->n; i++) {
        print(&l->array[i]);
    }
}

int stringToInt(char* str) {
    int result = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        }
    }
    return result;
}
bool startsWith(char texto[], char prefixo[]) {
    if (LF_Size_Of_Char(prefixo) > LF_Size_Of_Char(texto) ) {
        return false;
    }

    for (int i = 0; i < LF_Size_Of_Char(prefixo); i++) {
        if (texto[i] != prefixo[i]) {
            return false;
        }
    }

    return true;
    }
int split(const char* str, const char* delimitador, char partes[20][100]) {
    int count = 0;
    char copia[strlen(str) + 1];
    strcpy(copia, str);

    char* token = strtok(copia, delimitador);
    while (token != NULL && count < 20) {
        strncpy(partes[count], token, 100 - 1);
        partes[count][100 - 1] = '\0';
        count++;
        token = strtok(NULL, delimitador);
    }

    return count;
}
typedef struct {
    show array[MAX];
    int n;
} PilhaArranjo;
void inserirFim_Pilha(PilhaArranjo* p, show x) {
    if (p->n >= MAX) {
        printf("Lista cheia!\n");
        exit(1);
    }
    p->array[p->n++] = x;
}
char* removerFim_Pilha(PilhaArranjo* p) {
    if (p->n == 0) {
        printf("Lista vazia!\n");
        exit(1);
    }
    show temp = p->array[--p->n];
    return get_TITLE(&temp);
}
void mostrar_Pilha(PilhaArranjo* p) {
    for (int i = p->n - 1; i > 0; i--) {
        printf("[%d] ", i);
        print(&p->array[i]);
    }
}
#define max 5
typedef struct {
    show array[max];
    int inicio;
    int fim;
    int tamanho;
} FilaCircular;

int get_YearInt (show* x){
    return stringToInt(get_YEAR(x));
}
int get_media (FilaCircular* f){
    int count = 0;
    int m = 0;
    for (int i = 0; i < f->tamanho; i ++){
        m = get_YearInt(&f->array[i]) + m;
        i = (i + 1) % max;
        count++;
    }
    return m / count;
}
    
char* remover_FilaCircular(FilaCircular *f) {
    if (f->tamanho == 0) return "";
        show temp = f->array[f->inicio];
        f->inicio = (f->inicio + 1) % max;
        f->tamanho--;
     return get_TITLE(&temp);
}

int inserir_FilaCircular(FilaCircular *f, show x) {
    if (f->tamanho >= max) remover_FilaCircular(f);
    f->array[f->fim] = x;
    f->fim = (f->fim + 1) % max;
    f->tamanho++;
    int media = get_media(f);
    printf("[Media] %d\n", media);
    return 1;
}

void mostrar_FilaCircular(FilaCircular* f) {
    for (int i = f->inicio; i < f->fim; i++) {
        printf("[%d] ", i - 1);
        print(&f->array[i]);
    }
}

int main ( void ) {
    show* shows = malloc(1400 * sizeof(show));
    memset(shows, 0, 1400 * sizeof(show));
    char line[5000];
    int showIndex = 0;
    FILE *arquivo = fopen("/tmp/disneyplus.csv", "r");
    if (arquivo == NULL) {
        arquivo = fopen("disneyplus.csv", "r");
    }
    clock_t start = clock();//inicia o timer
    int comp = 0; 
    int count = 0;
    fgets(line, sizeof(line), arquivo);//pula a primeira linha
    while (fgets(line, sizeof(line), arquivo) && showIndex < 1368){//le e monta o arranjo de shows
        read(&shows[showIndex],line);
        showIndex++;
    }
    fclose(arquivo);
    char array[100];
    scanf("%9[^\n]", array);
    //ListaArranjo* l = malloc(sizeof(ListaArranjo));
    //PilhaArranjo* p = malloc(sizeof(PilhaArranjo));
    FilaCircular* f = malloc(sizeof(FilaCircular));
    while (!LF_isFim(array))
    {
        int found = 0;
        int pos = 0;
        for (int i = 0; i < showIndex; i++) {
            if (LF_Equals(array, shows[i].SHOW_ID)) {
                found = 1;
                pos = i;
                i = showIndex;
            }
        }
        if (found) {
            //print(&shows[pos]);
            //inserir(l, shows[pos], count);
            //inserirFim_Pilha(p, shows[pos]);
            inserir_FilaCircular(f, shows[pos]);
            count++;
            mark(&shows[pos]);//chama mark com o objeto escolhido
        } else {
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
    for (int i = 0; i < n; i++) {
        scanf(" %99[^\n]", temp);
        if (startsWith(temp, "I")) {
            trash = split(temp, " ", partes);
            id = stringToInt(Char_remove(partes[1], 0));
            inserir_FilaCircular(f, shows[id - 1]);
        } else if (startsWith(temp, "R")) {
            char* removido = remover_FilaCircular(f);
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
    mostrar_FilaCircular(f);
    //mostrar_Pilha(p);
    clock_t end = clock(); // fim da contagem do tempo
    double total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    FILE *log = fopen("867129_selection_p_sortr.txt", "w");
    if (log != NULL) {
        fprintf(log, "867129\t%.6f\t%d\n", total_time, comp);
        fclose(log);
    } else {
        fprintf(stderr, "Erro ao criar o arquivo de log.\n");
    }
    return 0;
}