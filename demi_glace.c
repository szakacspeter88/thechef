#include <stdio.h>
#include <stdbool.h>

// 1. ÖRÖKLŐDÉS: A Demi-Glace az Espagnole-ra épül
typedef struct {
    int espagnole_sauce_ml;
    int brown_stock_ml;
    float sherry_wine_ml; // Opcionális "finishing" érintés
} DemiGlaceBase;

// 2. A REDUKCIÓS FOLYAMAT (A mártás sűrítése)
void reduction(int *current_volume, int target_volume) {
    printf("Redukció megkezdése...\n");
    while (*current_volume > target_volume) {
        *current_volume -= 10; // Párolog a víz
        if (*current_volume % 100 == 0) {
            printf("  Aktuális mennyiség: %d ml - Az ízek koncentrálódnak...\n", *current_volume);
        }
    }
    printf("Elértük a kívánt állagot: %d ml.\n", target_volume);
}

// 3. A FŐZÉS LOGIKÁJA
int main() {
    DemiGlaceBase pot;
    
    // 1:1 arányban keverjük az alapanyagokat
    pot.espagnole_sauce_ml = 500;
    pot.brown_stock_ml = 500;
    
    int total_volume = pot.espagnole_sauce_ml + pot.brown_stock_ml;
    int final_target = total_volume / 2; // A Demi-Glace lényege a feleződés

    printf("--- DEMI-GLACE RECEPT C NYELVEN ---\n");
    printf("Kiindulási mennyiség: %d ml (Espagnole + Alaplé)\n\n", total_volume);

    // Főzés fázis
    reduction(&total_volume, final_target);

    // Befejezés: Sherry hozzáadása (opcionális extra paraméter)
    pot.sherry_wine_ml = 30.0;
    printf("\nFiniselés: %.1f ml Sherry hozzáadása a fényes felületért.\n", pot.sherry_wine_ml);

    // Ellenőrzés: A kanál hátulján megmarad-e? (Nappé teszt)
    bool is_viscous_enough = true; 
    if (is_viscous_enough) {
        printf("Állag: TÖKÉLETES. A szósz bevonja a kanalat.\n");
    }

    printf("\nSiker: A Demi-Glace tálalásra kész!\n");

    return 0;
}
