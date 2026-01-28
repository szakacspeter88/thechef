#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. A HOZZÁVALÓK DEFINIÁLÁSA (Struktúrák)
typedef struct {
    float vaj;           // gramm
    float liszt;         // gramm
    char* mirepoix[3];   // sárgarépa, hagyma, zeller
    int alaple_ml;       // barna alaplé
    float paradicsom_pure;
    char* fuszerek[3];   // kakukkfű, babérlevél, bors
} EspagnoleIngredients;

// 2. A ROUX (RÁNTÁS) ELKÉSZÍTÉSE
// A függvény módosítja a keverék színét (állapotát)
void make_dark_roux(float vaj, float liszt) {
    printf("1. Vaj felolvasztása, liszt hozzáadása...\n");
    for(int perc = 0; perc < 10; perc++) {
        printf("   [Sütés] A roux sötétedik... perc: %d\n", perc);
    }
    printf("   EREDMÉNY: Sötétbarna roux kész.\n\n");
}

// 3. A SZÓSZ ÖSSZEÁLLÍTÁSA ÉS REDUKCIÓJA
void simmer_and_reduce(int *volumen) {
    printf("2. Alaplé és paradicsom hozzáadása. Lassú tűzön főzzük.\n");
    while(*volumen > 600) { // Addig főzzük, amíg harmadával nem csökken
        *volumen -= 50; 
        printf("   [Simmer] Párolgás... Aktuális mennyiség: %d ml\n", *volumen);
    }
}

// 4. A TÁLALÁS (Főfüggvény)
int main() {
    // Memória lefoglalása a receptnek
    EspagnoleIngredients *sauce = malloc(sizeof(EspagnoleIngredients));
    
    // Alapanyagok inicializálása
    sauce->vaj = 50.0;
    sauce->liszt = 50.0;
    sauce->alaple_ml = 1000; // 1 literből indulunk
    
    printf("--- SAUCE ESPAGNOLE FORDÍTÁSA ---\n\n");

    // Lépések végrehajtása
    make_dark_roux(sauce->vaj, sauce->liszt);
    
    simmer_and_reduce(&(sauce->alaple_ml));

    // 5. SZŰRÉS (Memória felszabadítása a szilárd részektől)
    printf("\n3. Finomszűrőn (Chinois) való átszűrés...\n");
    printf("   A zöldségek és fűszerek eltávolítása a rendszerből.\n");
    
    // A C-ben a 'free' olyan, mint a szűrés: kidobjuk, ami már nem kell
    free(sauce); 
    
    printf("\nSIKER: A Sauce Espagnole készen áll a Demi-Glace-szá váláshoz!\n");
    
    return 0; // Konyha lezárva, tiszta asztal.
}
