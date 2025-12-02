#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash

//struct
typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    if (!nova) {
        printf("Erro ao alocar memória para sala.\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

void explorarSalas(Sala* atual) {
    char escolha;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);

        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Não há mais caminhos a partir daqui. Fim da exploração!\n");
            return;
        }

        printf("Para onde deseja ir?\n");
        printf("   (e) Ir para a esquerda\n");
        printf("   (d) Ir para a direita\n");
        printf("   (s) Sair\n");
        printf("Escolha: ");
        scanf(" %c", &escolha);

        if (escolha == 'e') {
            if (atual->esquerda != NULL)
                atual = atual->esquerda;
            else
                printf("Caminho inexistente!\n");
        }
        else if (escolha == 'd') {
            if (atual->direita != NULL)
                atual = atual->direita;
            else
                printf("Caminho inexistente!\n");
        }
        else if (escolha == 's') {
            printf("\nSaindo da exploração... \n");
            return;
        }
        else {
            printf("Opção inválida!\n");
        }
    }
}


int main() {

     // Criando manual da árvore da mansão
    Sala* hall = criarSala("Hall de Entrada");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* cozinha = criarSala("Cozinha");
    Sala* sotao = criarSala("Sótão");
    Sala* jardim = criarSala("Jardim");

    // árvore binária fixa
    hall->esquerda = biblioteca;
    hall->direita = cozinha;

    biblioteca->esquerda = sotao;     // Nó-folha
    biblioteca->direita = jardim;     // Nó-folha

    // cozinha não possui filhos 

    printf("=== Detective Quest - Exploração da Mansão ===\n");

    // Iniciando exploração
    explorarSalas(hall);

    return 0;
}

