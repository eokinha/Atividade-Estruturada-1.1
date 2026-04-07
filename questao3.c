#include <stdio.h>

#define MAX 5

typedef struct {
    char nome[50];
    int  tempo;   // em minutos
    int  status;  // 0 = não concluído | 1 = concluído
} Projeto;

// --- Função que percorre por ponteiro e atualiza status ---
void verificarConclusao(Projeto *lista, int tamanho, int limite) {
    Projeto *p;
    for (p = lista; p < lista + tamanho; p++) {
        if (p->tempo <= limite) {
            p->status = 1; // altera o original via ponteiro
        }
    }
}

void exibirTodos(Projeto *lista, int tamanho) {
    printf("%-20s %-12s %s\n", "Projeto", "Tempo(min)", "Status");
    printf("---------------------------------------------\n");
    Projeto *p;
    for (p = lista; p < lista + tamanho; p++) {
        printf("%-20s %-12d %s\n",
               p->nome,
               p->tempo,
               p->status == 1 ? "Concluido" : "Pendente");
    }
}

void exibirConcluidos(Projeto *lista, int tamanho) {
    printf("\n== Projetos concluidos ==\n");
    int encontrou = 0;
    Projeto *p;
    for (p = lista; p < lista + tamanho; p++) {
        if (p->status == 1) {
            printf("  - %s (%d min)\n", p->nome, p->tempo);
            encontrou = 1;
        }
    }
    if (!encontrou) printf("  Nenhum projeto concluido.\n");
}

int main() {
    Projeto fila[MAX] = {
        {"Suporte de celular",  45,  0},
        {"Engrenagem pequena",  120, 0},
        {"Tampa de caixa",      90,  0},
        {"Miniatura decorativa",200, 0},
        {"Clipe ajustavel",     30,  0}
    };

    int limite = 100; // minutos

    printf("=== ANTES DA VERIFICACAO (limite: %d min) ===\n", limite);
    exibirTodos(fila, MAX);

    verificarConclusao(fila, MAX, limite);

    printf("\n=== DEPOIS DA VERIFICACAO ===\n");
    exibirTodos(fila, MAX);

    exibirConcluidos(fila, MAX);

    return 0;
}