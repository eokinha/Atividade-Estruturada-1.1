#include <stdio.h>

#define MAX (50)

typedef struct {
    int id;
    char marca[50];
    char modelo[50];
    int memoria;
    float preco;
} notebooks;


int main() {
    notebooks note[MAX];
    int N, i;
    do {
        printf("Quantos notebooks deseja cadastrar ? (0 a 50)   ");
        scanf("%d", &N);
    } while (N < 0 || N > MAX
    )
    ;

    for (i = 0; i < N; i++) {
        printf("Cadastro do notebook %d\n", i + 1);

        printf("Digite o ID do notebook: \n");
        scanf("%d", &note[i].id);

        printf("Digite o modelo do notebook: \n");
        fgets(note[i].modelo, 50, stdin);

        printf("Digite a quantidade de memoria-ram do notebook: \n");
        fgets(note[i].memoria, 50, stdin);

        printf("Digite o preço do notebook: ");
        scanf("%f", &note[i].preco);
    }

    printf("---------- Bem vindos a Kinha Informática! ---------- \n\n");
    printf("---------- Nosso catálogo de notebooks ---------- \n\n");

    for (int i = 0; i < N; i++) {
        printf("Marca: %s \n Modelo: %.2f \n Memoria: %d \n Preço: %.2f \n",
               note[i].marca,
               note[i].modelo,
               note[i].memoria,
               note[i].preco);
    }
}
