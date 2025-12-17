#include <stdio.h>
#include <string.h>
#define MAX_LENGHT 50   

char* concatenaStringhe1(char *str1, char *str2, char *str3);
char* concatenaStringhe2(char *str1, char *str2, char *str3);

int main(){
    char str1[MAX_LENGHT], str2[MAX_LENGHT];    
    printf("Inserisci la stringa 1:\n");
    fgets(str1, MAX_LENGHT, stdin);             //uso fgets per un 'inserimento corretto delle stringhe
                                                //(se ci fosse uno spazio, scanf si fermerebbe ad esso)
    printf("Inserisci la stringa 2:\n");        
    fgets(str2, MAX_LENGHT, stdin);

    str1[strcspn(str1, "\n")] = '\0';       //fgets prende in input anche \n, facendo così lo rimuoviamo
    str2[strcspn(str2, "\n")] = '\0';       // da entrambe le stringhe

    char str3[2*MAX_LENGHT];                //inizializzo str3 a 100 così che si possa concatenare SEMPRE
    concatenaStringhe1(str1, str2, str3);       //passo il primo indirizzo di str3 così che salvi la stringa concatenata       
    
    char str4[2*MAX_LENGHT];
    concatenaStringhe2(str1, str2, str4);
    
    printf("Le due stringhe concatenate senza strcat: %s \n", str3);
    printf("Le due stringhe concatenate con strcat: %s \n", str4);
    
    if(strcmp(str3, str4)==0){          //strcmp ritorna 0 SOLO se sono uguali
        printf("LE DUE STRINGHE SONO UGUALI");
    }else printf("LE DUE STRINGHE NON SONO UGUALI");

    return 0;
}

char* concatenaStringhe1(char *str1, char *str2, char *str3){  
    char *start = str3;         // salvo l'inizio per il return

    while(*str1 != '\0'){       //raggiungo l'indice di str1 dove la si conclude (cioè quando trovo \0)
        *str3 = *str1;          // Copio valore puntato
        str1++;                 // Incremento puntatore sorgente
        str3++;                 // Incremento puntatore destinazione
    }

    while(*str2 != '\0'){       //faccio lo stesso per str2
        *str3 = *str2;
        str2++;
        str3++;
    }
    *str3 = '\0';             //riscrivo il carattere \0 per 'chiudere' la stringa
    
    return start; 
}

char* concatenaStringhe2(char *str1, char *str2, char *str3){
    strcpy(str3, str1);          // copio str1 in str3 
    strcat(str3, str2);          //concateno le due stringhe
    return str3;
}