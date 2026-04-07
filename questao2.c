#include <stdio.h>

typedef struct {
    char especie[50];
    int dias; // dias sem água
    char status; // 'N' = necessita rega | 'O' = ok
} Planta;

// --- Função que recebe ponteiro e atualiza se necessário ---
void verificarIrrigacao(Planta *p) {
    if (p->dias >= 3) {
        p->status = 'O'; // atualiza o original via ponteiro
        p->dias = 0; // zera o contador
    }
}

void exibirPlanta(Planta p) {
    printf("  Especie: %s\n", p.especie);
    printf("  Dias sem agua: %d\n", p.dias);
    printf("  Status: %c (%s)\n\n",
           p.status,
           p.status == 'O' ? "ok" : "necessita rega");
}

int main() {
    // Duas plantas para testar comportamentos diferentes
    Planta p1 = {"Samambaia", 1, 'N'}; // 1 dia — não deve regar
    Planta p2 = {"Cacto", 5, 'N'}; // 5 dias — deve regar

    // --- Antes ---
    printf("=== ANTES DA VERIFICACAO ===\n");
    printf("Planta 1:\n");
    exibirPlanta(p1);
    printf("Planta 2:\n");
    exibirPlanta(p2);

    // --- Atualização via ponteiro ---
    verificarIrrigacao(&p1); // passa o endereço de p1
    verificarIrrigacao(&p2); // passa o endereço de p2

    // --- Depois ---
    printf("=== DEPOIS DA VERIFICACAO ===\n");
    printf("Planta 1:\n");
    exibirPlanta(p1);
    printf("Planta 2:\n");
    exibirPlanta(p2);

    return 0;
}
