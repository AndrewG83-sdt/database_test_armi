#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ARMI 100
#define MAX_STRINGA 50

typedef struct {
    char brand[MAX_STRINGA];
    char categoria[MAX_STRINGA];
    char calibro[MAX_STRINGA];
    char catalogazione[MAX_STRINGA];
    int pollici;
    char colore[MAX_STRINGA];
    char derivazione[MAX_STRINGA];
} Arma;

Arma armi[MAX_ARMI];
int numero_armi = 0;

// Converte una stringa in maiuscolo
void stringa_maiuscola(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char) str[i]);
    }
}

void aggiungi_arma(const char* brand, const char* categoria, const char* calibro, const char* catalogazione, int pollici, const char* colore, const char* derivazione) {
    if (numero_armi >= MAX_ARMI) {
        printf("\nDatabase pieno.\n");
        return;
    }
    strcpy(armi[numero_armi].brand, brand);
    strcpy(armi[numero_armi].categoria, categoria);
    strcpy(armi[numero_armi].calibro, calibro);
    strcpy(armi[numero_armi].catalogazione, catalogazione);
    armi[numero_armi].pollici = pollici;
    strcpy(armi[numero_armi].colore, colore);
    strcpy(armi[numero_armi].derivazione, derivazione);
    numero_armi++;
}

void cerca_arma(const char* parametro) {
    printf("\nRisultati della ricerca per '%s':\n", parametro);
    int trovati = 0;

    char parametro_upper[MAX_STRINGA];
    strcpy(parametro_upper, parametro);
    stringa_maiuscola(parametro_upper);

    for (int i = 0; i < numero_armi; i++) {
        char brand_upper[MAX_STRINGA], categoria_upper[MAX_STRINGA], calibro_upper[MAX_STRINGA];
        strcpy(brand_upper, armi[i].brand);
        strcpy(categoria_upper, armi[i].categoria);
        strcpy(calibro_upper, armi[i].calibro);

        stringa_maiuscola(brand_upper);
        stringa_maiuscola(categoria_upper);
        stringa_maiuscola(calibro_upper);

        if (strstr(brand_upper, parametro_upper) || strstr(categoria_upper, parametro_upper) || strstr(calibro_upper, parametro_upper)) {
            printf("\n[%d] %s | %s | %s | %s | %d\" | %s | %s\n", i+1, armi[i].brand, armi[i].categoria, armi[i].calibro, armi[i].catalogazione, armi[i].pollici, armi[i].colore, armi[i].derivazione);
            trovati++;
        }
    }

    if (!trovati) {
        printf("\nNessun risultato trovato.\n");
    }
}

int main() {
    aggiungi_arma("SIG SAUER", "PISTOLA SEMIAUTOMATICA", "9X19", "SPORTIVA", 5, "TAN", "MILITARE");
    aggiungi_arma("GLOCK", "PISTOLA SEMIAUTOMATICA", "22", "SPORTIVA", 4, "NERO", "SPORTIVA");
    aggiungi_arma("INFINITY SVI", "PISTOLA SEMIAUTOMATICA", "40", "SPORTIVA", 5, "ARGENTO", "SPORTIVA");
    aggiungi_arma("SPRIGFIELD ARMORY", "PISTOLA SEMIAUTOMATICA", "9X19", "SPORTIVA", 5, "NERO", "MILITARE");
    aggiungi_arma("SMITH & WESSON", "REVOLVER", "257 MAG", "SPORTIVA", 5, "NERO", "MILITARE");

    char input[MAX_STRINGA];
    printf("Benvenuto nel database armi.\n");
    printf("Cosa stai cercando? Inserisci modello, brand o calibro: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    cerca_arma(input);

    return 0;
}
