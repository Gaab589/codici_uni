#include <stdio.h>
#include <string.h>
#define MAX_LENGHT 50

typedef struct{
    char nome[MAX_LENGHT];
    char cognome[MAX_LENGHT];
    int eta;
    char email[MAX_LENGHT];
}Persona;

void flush();
void inserisci_dati(Persona[], int);
void stampa_dati(Persona*, int);
void cerca_cognome(Persona*, int);
void modifica_dati(Persona*, int);
void set_nome(Persona *p, char *nuovo_nome) {       
    strcpy(p->nome, nuovo_nome);
}

void set_cognome(Persona *p, char *nuovo_cognome) {
    strcpy(p->cognome, nuovo_cognome);
}

void set_eta(Persona *p, int nuova_eta) {
    p->eta = nuova_eta;
}

void set_email(Persona *p, char *nuova_email) {
    strcpy(p->email, nuovo_email);
}

int main (){
    int dimensione;
    do{
        printf("Quante persone vuoi inserire? Massimo 20: ");
        scanf("%d", &dimensione);
        if(dimensione>20 || dimensione<=0){
            printf("\nInserisci un numero minore di 20");
        } 
    }while (dimensione>20 || dimensione <=0);
    flush();

    Persona persone[dimensione];
    inserisci_dati(persone, dimensione);
    stampa_dati(persone, dimensione);

    cerca_cognome(persone, dimensione);
    modifica_dati(persone, dimensione);
}

void flush(){                  //la funzione flush si utilizza dopo aver usato una scanf per pulire il buffer  
    while (getchar() != '\n'); //dell'input dal carattere '\n'. se non usassimo questa funzione
}                              //è possibile che '\n' venga preso come input dal prossimo scanf
                               //la funzione flush quindi obbliga a svuotare completamente il buffer prima di riutilizzarlo
void inserisci_dati(Persona p[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("\nPersona numero %d", i+1);

        printf("\nInserisci il nom: ");
        fgets(p[i].nome, MAX_LENGHT, stdin);       //per prendere come input una stringa, usiamo fgets perché,
        p[i].nome[strcspn(p[i].nome, "\n")]='\0';  //al contrario di scanf, essa non si ferma al primo spazio 
                                                   //questo ci permette di memorizzare stringe con una o più spazi all'interno
        printf("\nInserisci il cognome: ");        //sempre se rientra nel numero massimo di caratteri inseribili
        fgets(p[i].cognome, MAX_LENGHT, stdin);
        p[i].cognome[strcspn(p[i].cognome, "\n")]='\0';

        printf("\nInserisci l'età:");
        scanf("%d", &p[i].eta);

        flush();

        printf("\nInserisci l'email:");
        fgets(p[i].email, MAX_LENGHT, stdin);
        p[i].email[strcspn(p[i].email, "\n")]='\0';
    }
}

void stampa_dati(Persona *p, int n){
    int i;
    for (i=0; i<n; i++){
        printf("\nPersona numero %d", i+1);
        printf("\nNome: %s", p->nome);
        printf("\nCognome: %s", p->cognome);
        printf("\nEtà: %d", p->eta);
        printf("\nEmail: %s", p->email);
        p++;
    }
}


/*
usando l'accesso indicizzato in un array, il compilatore calcola da solo l'indirizzo a cui si richiede l'accesso
persona[i].nome per il compilatore equivale a dire primo_indirizzo+(i*dimensione_struct)

quando usiamo l'aritmetica dei puntatori siamo noi a dire a quale indirizzo di memoria deve cercare il compilatore
persona+i->nome equivale a dirgli primo_indirizzo+i(offset) ed allora legge il contenuto seguito dalla freccia (nome)
*/
void cerca_cognome(Persona *p, int n){
    int i;
    char cognome_da_cercare[MAX_LENGHT];
    printf("\nInserisci il cognome da cercare: ");
    fgets(cognome_da_cercare, MAX_LENGHT, stdin);
    cognome_da_cercare[strcspn(cognome_da_cercare, "\n")]='\0';
    for(i=0; i<n; i++){
        if(strcmp(p->cognome, c)==0){
            printf("\nCognome trovato alla persona numero %d", i+1);
            printf("\nNome persona: %s", p->nome);
        }
        p++;
    }
}

void modifica_dati(Persona *p, int n) {
    char cognome_da_cercare[MAX_LENGHT];
    char str[MAX_LENGHT]; 
    int num, i, trovato = 0, scelta;

    printf("\nInserisci il cognome della persona da modificare: ");
    fgets(cognome_da_cercare, MAX_LENGHT, stdin);
    cognome_da_cercare[strcspn(cognome_da_cercare, "\n")] = '\0';

    for (i = 0; i < n; i++) {

        if (strcmp((p + i)->cognome, cognome_da_cercare) == 0) {
            trovato = 1;
            Persona *corrente = (p + i); 

            
            printf("\nPersona trovata:\n");
            printf("\nNome: %s", corrente->nome);
            printf("\nCognome: %s", corrente->cognome);
            printf("\nEtà: %d", corrente->eta);
            printf("\nEmail: %s", corrente->email);
            printf("\nQuale campo vuoi modificare?\n");
            printf("1 = Nome\n2 = Cognome\n3 = Eta'\n4 = Email\n");
            printf("Scelta: ");
            scanf("%d", &scelta);
            flush(); 
            switch (scelta) {
                case 1:
                    printf("Inserisci il nuovo Nome: ");
                    fgets(str, MAX_LENGHT, stdin);
                    str[strcspn(str, "\n")] = '\0';
                    set_nome(corrente, str); 
                    break;
                
                case 2:
                    printf("Inserisci il nuovo Cognome: ");
                    fgets(str, MAX_LENGHT, stdin);
                    str[strcspn(str, "\n")] = '\0';
                    set_cognome(corrente, str);
                    break;

                case 3:
                    printf("Inserisci la nuova Eta': ");
                    scanf("%d", &num);
                    flush(); 
                    set_eta(corrente, num);
                    break;

                case 4:
                    printf("Inserisci la nuova Email: ");
                    fgets(str, MAX_LENGHT, stdin);
                    str[strcspn(str, "\n")] = '\0';
                    set_email(corrente, str);
                    break;

                default:
                    printf("Scelta non valida.\n");
            }

            printf("\nDati Aggiornati");
            printf("\nNome: %s", corrente->nome);
            printf("\nCognome: %s", corrente->cognome);
            printf("\nEtà: %d", corrente->eta);
            printf("\nEmail: %s", corrente->email);
            
            return; 
        }
    }

    if (!trovato) {
        printf("Nessuna persona trovata con il cognome '%s'.\n", cognome_da_cercare);
    }
}