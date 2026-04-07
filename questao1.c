#include <stdio.h>
#include <string.h> // necessário para strcspn

#define MAX 50

typedef struct {
    int id;
    char marca[50];
    char modelo[50];
    int memoria;
    float preco;
} Notebook;

int main() {
    Notebook note[MAX];
    int N, i, indiceMaior;

    // --- Validação da quantidade ---
    do {
        printf("Quantos notebooks deseja cadastrar? (1 a %d): ", MAX);
        scanf("%d", &N);
    } while (N < 1 || N > MAX);

    // --- Cadastro ---
    for (i = 0; i < N; i++) {
        printf("\nCadastro do notebook %d\n", i + 1);

        printf("Digite o ID do notebook: ");
        scanf("%d", &note[i].id);

        getchar(); // limpa o '\n' residual antes dos fgets

        printf("Digite a marca do notebook: ");       // (1) marca estava ausente
        fgets(note[i].marca, 50, stdin);
        note[i].marca[strcspn(note[i].marca, "\n")] = '\0';

        printf("Digite o modelo do notebook: ");
        fgets(note[i].modelo, 50, stdin);
        note[i].modelo[strcspn(note[i].modelo, "\n")] = '\0'; // (2) remove '\n' do fgets

        printf("Digite a memoria RAM (GB): ");
        scanf("%d", &note[i].memoria);

        printf("Digite o preco (R$): ");
        scanf("%f", &note[i].preco);
    }

    // --- Busca do maior RAM ---
    indiceMaior = 0;
    for (i = 1; i < N; i++) {
        if (note[i].memoria > note[indiceMaior].memoria) {
            indiceMaior = i;
        }
    }

    // --- Catálogo ---
    printf("\n---------- Bem-vindos a Kinha Informatica! ----------\n\n");
    printf("---------- Nosso catalogo de notebooks ----------\n\n");

    for (i = 0; i < N; i++) {
        printf("ID:      %d\n",     note[i].id);
        printf("Marca:   %s\n",     note[i].marca);
        printf("Modelo:  %s\n",     note[i].modelo);   // (3) era %.2f — corrigido para %s
        printf("Memoria: %d GB\n",  note[i].memoria);
        printf("Preco:   R$ %.2f\n",note[i].preco);
        printf("-----------------------------\n");
    }

    // --- Resultado ---
    printf("\n== Notebook com maior memoria RAM ==\n");
    printf("Modelo: %s\n",     note[indiceMaior].modelo);
    printf("Marca:  %s\n",     note[indiceMaior].marca);
    printf("RAM:    %d GB\n",  note[indiceMaior].memoria);
    printf("Preco:  R$ %.2f\n",note[indiceMaior].preco);

    return 0;
}