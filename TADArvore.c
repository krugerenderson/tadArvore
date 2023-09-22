#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore
struct NoArv {
    int valor;
    struct NoArv* esquerda;
    struct NoArv* direita;
};

typedef struct NoArv NoArv;

// Função auxiliar para criar um novo nó da árvore
NoArv* criarNo(int valor) {
    NoArv* novoNo = (NoArv*)malloc(sizeof(NoArv));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o nó da árvore.\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para calcular a altura de um nó da árvore
int altura(NoArv* no) {
    if (no == NULL) {
        return 0;
    }
    int altura_esquerda = altura(no->esquerda);
    int altura_direita = altura(no->direita);
    return (altura_esquerda > altura_direita) ? altura_esquerda + 1 : altura_direita + 1;
}

// Função para calcular o fator de balanceamento de um nó
int fator_balanceamento(NoArv* no) {
    if (no == NULL) {
        return 0;
    }
    return altura(no->esquerda) - altura(no->direita);
}

// Função para realizar uma rotação simples à esquerda
NoArv* rotacao_esquerda(NoArv* raiz) {
    NoArv* nova_raiz = raiz->direita;
    raiz->direita = nova_raiz->esquerda;
    nova_raiz->esquerda = raiz;
    return nova_raiz;
}

// Função para realizar uma rotação simples à direita
NoArv* rotacao_direita(NoArv* raiz) {
    NoArv* nova_raiz = raiz->esquerda;
    raiz->esquerda = nova_raiz->direita;
    nova_raiz->direita = raiz;
    return nova_raiz;
}

// Função para inserir um valor na árvore com balanceamento
NoArv* inserir_com_balanceamento(NoArv* raiz, int valor) {
    // Inserção normal de um novo elemento na árvore
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir_com_balanceamento(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_com_balanceamento(raiz->direita, valor);
    } else {
        // Valor duplicado, não é permitido
        return raiz;
    }

    // Atualize o fator de balanceamento deste nó
    int fb = fator_balanceamento(raiz);

    // Realize as rotações necessárias para balancear a árvore
    if (fb > 1) {
        // Rotação à direita
        if (valor < raiz->esquerda->valor) {
            return rotacao_direita(raiz);
        }
        // Rotação dupla: rotação à esquerda seguida por rotação à direita
        else {
            raiz->esquerda = rotacao_esquerda(raiz->esquerda);
            return rotacao_direita(raiz);
        }
    }
    if (fb < -1) {
        // Rotação à esquerda
        if (valor > raiz->direita->valor) {
            return rotacao_esquerda(raiz);
        }
        // Rotação dupla: rotação à direita seguida por rotação à esquerda
        else {
            raiz->direita = rotacao_direita(raiz->direita);
            return rotacao_esquerda(raiz);
        }
    }

    return raiz;
}

// Função de interface que chama inserir_com_balanceamento com os parâmetros iniciais
NoArv* inserir(NoArv* raiz, int valor) {
    raiz = inserir_com_balanceamento(raiz, valor);
    return raiz;
}

// Função para imprimir a árvore em ordem
void imprimir_arvore(NoArv* raiz) {
    if (raiz == NULL) {
        return;
    }
    imprimir_arvore(raiz->esquerda);
    printf("%d ", raiz->valor);
    imprimir_arvore(raiz->direita);
}

int main() {
    NoArv* arvore = NULL;

    int valores[] = {30, 20, 40, 10, 25, 35, 50};

    for (int i = 0; i < sizeof(valores) / sizeof(valores[0]); i++) {
        arvore = inserir(arvore, valores[i]);
    }

    printf("Árvore binária de busca balanceada em ordem:\n");
    imprimir_arvore(arvore);
    printf("\n");

    return 0;
}
