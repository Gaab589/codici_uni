#include <stdio.h>
#include <string.h>

#define MAX_LENGHT 50

void iniziali_maiuscolo(char *);
void tutto_maiuscolo(char *);
char *tutto_maiuscolo_parziale(char *, int n, char *);

int main() {
    char str[MAX_LENGHT];
    char destinazione[MAX_LENGHT];
    char scelta;
    int num;

    do {
        printf("\n--- MENU ---\n");
        printf("a. Iniziali maiuscole\n");
        printf("b. Tutto maiuscolo\n");
        printf("c. Maiuscolo parziale\n");
        printf("d. Esci\n");
        printf("Scelta: ");
        scanf(" %c", &scelta);
        
        while(getchar() != '\n'); 

        switch(scelta) {
            case 'a':
                printf("Inserisci la stringa: ");
                fgets(str, MAX_LENGHT, stdin);
                str[strcspn(str, "\n")] = '\0';
                
                iniziali_maiuscolo(str);
                printf("Risultato: %s\n", str);
                break;

            case 'b':
                printf("Inserisci la stringa: ");
                fgets(str, MAX_LENGHT, stdin);
                str[strcspn(str, "\n")] = '\0';
                
                tutto_maiuscolo(str);
                printf("Risultato: %s\n", str);
                break;

            case 'c':
                printf("Inserisci la stringa: ");
                fgets(str, MAX_LENGHT, stdin);
                str[strcspn(str, "\n")] = '\0';

                printf("Quanti caratteri convertire? ");
                scanf("%d", &num);
                while(getchar() != '\n'); 

                tutto_maiuscolo_parziale(str, num, destinazione);
                printf("Risultato parziale: %s\n", destinazione);
                break;

            case 'd':
                printf("Uscita...\n");
                break;

            default:
                printf("Scelta non valida.\n");
        }
    } while(scelta != 'd');

    return 0;
}

void iniziali_maiuscolo(char *str) {
    int nuova_parola = 1;

    while (*str != '\0') {
        if (*str == ' ') {
            nuova_parola = 1;
        } else if (nuova_parola) {
            if (*str >= 'a' && *str <= 'z') {   
                *str = *str - 32;
            }
            nuova_parola = 0;
        }
        str++;
    }
}

void tutto_maiuscolo(char *str) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 32;
        }
        str++;
    }
}

char *tutto_maiuscolo_parziale(char *str, int n, char *destinazione) {
    char *start = destinazione; 
    int i = 0;

    while (*str != '\0') {
        char c = *str;

        if (i < n) {                // converto SOLO se sono ancora dentro il limite dei primi n caratteri
            if (c >= 'a' && c <= 'z') {
                c = c - 32;
            }
        }
        
        *destinazione = c;          // copio il carattere (che sia stato convertito o no)
        
        str++;
        destinazione++;
        i++;
    }

    *destinazione = '\0';
    
    return start;
}