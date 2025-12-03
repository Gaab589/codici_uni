#include <stdio.h>
#include <string.h>

#define MAX_LENGHT 50

int conta_carattere(const char *, char );           //inizio ad usare il camel_case come vuole lei prof
void copia_senza_spazi(const char *, char *);

int main() {
    char str[MAX_LENGHT];
    char str_senza_spazi[MAX_LENGHT];
    char ch;

    printf("Inserisci una stringa:\n");
    fgets(str, MAX_LENGHT, stdin);
    str[strcspn(str, "\n")] = '\0';     //usando questa funzione rimuoviamo il carattere \n

    printf("Inserisci il carattere da contare:\n");
    scanf(" %c", &ch);

    int conta = conta_carattere(str, ch);   //chiama la funzione che conta il carattere

    printf("Il carattere '%c' compare %d volte.\n", ch, conta);     

    copia_senza_spazi(str, str_senza_spazi);

    printf("Stringa senza spazi: %s\n", str_senza_spazi);

    return 0;
}

int conta_carattere(const char *str, char c) {
    int contatore = 0;
    while (*str != '\0') {      //finchè non trova il carattere di chiusura esso continuerà a contare 
        if (*str == c) {        //quando trova il carattere giusto, incvrementa il contatore
            contatore++;
        }
        str++;
    }
    return contatore;
}

void copia_senza_spazi(const char *str, char *destinazione) {
    while (*str != '\0') {      //finché non si trova il carattere di chiusure stringa esso continuerà a acopiare
        if (*str != ' ') {      //quando trova uno spazio lo salta
            *destinazione = *str;
            destinazione++;
        }
        str++;
    }
    *destinazione = '\0';           //chiudo la stringa per non avere errori
}