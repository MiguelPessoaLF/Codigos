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
char* LF_Concat (char x[], char y[], char* result){
    int lenX = LF_Size_Of_Char(x);
    int lenY = LF_Size_Of_Char(y);
    for (int i = 0; i < lenX; i++){
        result[i] = x[i];
    }
    for (int i = 0; i < lenY; i++){
        result[lenX + i] = y[i];
    }
    result[lenX + lenY] = '\0';
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
    ord(new_show->DIRECTOR, LF_Size_Of_show(new_show->DIRECTOR));
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
int month_to_number(const char* month) {
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

time_t parse_date(const char* date_str) {
    char month[20];
    int day, year;
    struct tm tm_date = {0};
    if (sscanf(date_str, "%s %d, %d", month, &day, &year) != 3) {
        // default date
        day = 1;
        strcpy((char*)month, "March");
        year = 1900;
    }
    tm_date.tm_mday = day;
    tm_date.tm_mon = month_to_number(month) - 1;  // tm_mon is 0-based
    tm_date.tm_year = year - 1900;
    return mktime(&tm_date);
}

int compare_shows_date(const show* a, const show* b) {
    time_t timeA = parse_date(a->DATE.date_added);
    time_t timeB = parse_date(b->DATE.date_added);
    if (timeA < timeB) return -1;
    if (timeA > timeB) return 1;
    return strcmp(a->TITLE, b->TITLE);
}
typedef struct Node {
    show elem;
    struct Node* prev;
    struct Node* next;
} Node;
Node* criarNo(show e) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->elem = e;
    novo->prev = NULL;
    novo->next = NULL;
    return novo;
}
void inserirFim(Node** head, show e) {
    Node* novo = criarNo(e);
    if (*head == NULL) {
        *head = novo;
        return;
    }
    Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = novo;
    novo->prev = temp;
}
Node* ultimoNo(Node* head) {
    while (head && head->next)
        head = head->next;
    return head;
}
void imprimirLista(Node* head) {
    while (head) {
        printf("%s\n", head->elem.DATE.date_added);
        head = head->next;
    }
}
Node* particao(Node* baixo, Node* alto) {
    show pivo = alto->elem;
    Node* i = baixo->prev;

    for (Node* j = baixo; j != alto; j = j->next) {
        if (compare_shows_date(&j->elem, &pivo) <= 0) {
            i = (i == NULL) ? baixo : i->next;
            show temp = i->elem;
            i->elem = j->elem;
            j->elem = temp;
        }
    }

    i = (i == NULL) ? baixo : i->next;
    show temp = i->elem;
    i->elem = alto->elem;
    alto->elem = temp;

    return i;
}
void quickSortRec(Node* baixo, Node* alto) {
    if (alto && baixo != alto && baixo != alto->next) {
        Node* p = particao(baixo, alto);
        quickSortRec(baixo, p->prev);
        quickSortRec(p->next, alto);
    }
}
void quickSort(Node* head) {
    Node* fim = ultimoNo(head);
    quickSortRec(head, fim);
}
int main(void) {
    show* shows = malloc(1400 * sizeof(show));
    memset(shows, 0, 1400 * sizeof(show));
    char line[5000];
    int showIndex = 0;
    FILE *arquivo = fopen("/tmp/disneyplus.csv", "r");
    if (arquivo == NULL) {
        arquivo = fopen("disneyplus.csv", "r");
    }
    
    if (arquivo == NULL) {
        fprintf(stderr, "Arquivo não encontrado.\n");
        return 1;
    }
    
    clock_t start = clock(); 
    fgets(line, sizeof(line), arquivo);
    
    while (fgets(line, sizeof(line), arquivo) && showIndex < 1368) {
        read(&shows[showIndex], line);
        showIndex++;
    }
    fclose(arquivo);
    char array[100];
    scanf("%99[^\n]", array);
    while (!LF_isFim(array)) {
        bool found = false;
        for (int i = 0; i < showIndex; i++) {
            if (LF_Equals(array, shows[i].SHOW_ID)) {
                mark(&shows[i]);
                found = true;
                break;
            }
        }
        if (!found) {
            printf("Show com ID %s não encontrado!\n", array);
        }
        scanf(" %99[^\n]", array);
    }
    Node* head = NULL;
    for (int i = 0; i < showIndex; i++) {
        if (shows[i].QUESTION == 1) {
            inserirFim(&head, shows[i]);
        }
    }
    if (head != NULL) {
        quickSort(head);
    }
    Node* temp = head;
    while (temp != NULL) {
        print(&temp->elem);
        temp = temp->next;
    }
    while (head != NULL) {
        Node* next = head->next;
        free(head);
        head = next;
    }
    free(shows);
    
    clock_t end = clock();
    double total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    FILE *log = fopen("867129_quicksort.txt", "w");
    if (log != NULL) {
        fprintf(log, "867129\t%.6f\t%d\n", total_time, 0);
        fclose(log);
    } else {
        fprintf(stderr, "Erro ao criar o arquivo de log.\n");
    }
    
    return 0;
}
