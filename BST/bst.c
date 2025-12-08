#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *pai;
    struct no *esquerda;
    struct no *direita;
    int valor;
} no;

void inserirValor(no **raiz);

// função do tipo no *
no* buscarValor(no **raiz, int valorBuscado);

int buscarValorMaximo(no **raiz);

int buscarValorMinimo(no **raiz);

void transplant(no **raiz, no *antigoNo, no *novoNo);

void removerNo(no **raiz, no *noRemovido);

void exibirArvore(no *raiz, int nivel);

int main() {
    int escolhaUser, continuar = 1;
    no *raiz = NULL;
    
    printf("Seja bem vindo(a) a árvore binária de busca");

    while (continuar == 1) {
        printf("escolha uma das seguintes opções\n");
        printf("[0] Sair\n");
        printf("[1] Inserir valor\n");
        printf("[2] Buscar o valor máximo\n");
        printf("[3] Buscar o valor mínimo\n");
        printf("[4] Buscar valor\n");

        scanf("%d", &escolhaUser);
        switch (escolhaUser) {
            case 0:
                continuar == 0;
                break;
            case 1:
                inserirValor(&raiz);
                exibirArvore(raiz, 0);
                break;
            case 2:
                printf("O valor máximo é: %d\n", buscarValorMaximo(&raiz));
                break;
            case 3:
                printf("O valor mínimo é: %d\n", buscarValorMinimo(&raiz));
                break;
            case 4:
                int valorBuscado;

                printf("Qual valor você gostaria de buscar?\n");
                scanf("%d", &valorBuscado);

                if (buscarValor(&raiz, valorBuscado) == NULL) {
                    printf("Não encontrado\n");
                } else {
                    printf("O valor %d, está em %p\n", valorBuscado, buscarValor(&raiz, valorBuscado));
                }
            case 5:
                int valorRemover;
                printf("Qual valor quer remover?\n");
                scanf("%d", &valorRemover);

                no *enderecoNoRemover = buscarValor(&raiz, valorRemover);
                if (enderecoNoRemover == NULL) {
                    printf("Número não encontrado\n");
                    break;

                } else {
                    removerNo(&raiz, enderecoNoRemover);
                }
                exibirArvore(raiz, 0);
                break;
            case 6:
                exibirArvore(&raiz, 0);
                break;
        }
    }
}

void inserirValor(no **raiz) {
    int valorAdicionado;
    no *antecessor = NULL;
    no *noAtual = *raiz;

    printf("Qual valor você gostaria de adicionar?\n");
    scanf("%d", &valorAdicionado);    

    while (noAtual != NULL) {
        antecessor = noAtual;

        if (valorAdicionado == noAtual->valor) {
            printf("número já inserido\n");
            return;
        }

        if (valorAdicionado < noAtual->valor) {
            noAtual = noAtual->esquerda;
        } else {
            noAtual = noAtual->direita;
        }
    }

    if (antecessor == NULL) {
        *raiz = malloc(sizeof **raiz);

        (*raiz)->pai = NULL;
        (*raiz)->esquerda = NULL, (*raiz)->direita = NULL;
        (*raiz)->valor = valorAdicionado;

        printf("novo nó está na raiz, o endereço é: %p\n", &raiz);

    } else {
        no *novoNo = malloc(sizeof *novoNo);

        novoNo->pai = antecessor;
        novoNo->valor = valorAdicionado;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;

        if (valorAdicionado < antecessor->valor) {
            antecessor->esquerda = malloc(sizeof *novoNo);
            antecessor->esquerda = novoNo;

            printf("novo nó está para a esquerda de %d, o endereço é: %p\n", antecessor->valor, antecessor->esquerda);

        } else {
            antecessor->direita = malloc(sizeof *novoNo);
            antecessor->direita = novoNo;

            printf("novo nó está para a direita de %d, o endereço é: %p\n", antecessor->valor, antecessor->direita);
        }

        printf("Novo nó está em %p, tem o valor de %d\n", novoNo, novoNo->valor);
    }  
}

// função do tipo no *
no* buscarValor(no **raiz, int valorBuscado) {
    no *atual = *raiz;

    while (atual != NULL) {
        if (valorBuscado == atual->valor) {
            return atual; 
        }

        if (valorBuscado < atual->valor) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }

    return NULL; 
}

int buscarValorMaximo(no **raiz) {
    no *atual = *raiz;

    while (atual->direita != NULL) {
        atual = atual->direita;
    }

    return atual->valor;
}

int buscarValorMinimo(no **raiz) {
    no *atual = *raiz;

    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }

    return atual->valor;
}

void transplant(no **raiz, no *antigoNo, no *novoNo) {
    if (antigoNo->pai == NULL) {
        *raiz = novoNo;

    } else if (antigoNo == antigoNo->pai->esquerda) {  // vê se o antigoNo é o filho da esquerda e substitui
        antigoNo->pai->esquerda = novoNo;

    } else {
        antigoNo->pai->direita = novoNo;

    }

    if (novoNo != NULL) { // troca os pais
        novoNo->pai = antigoNo->pai;
    }
}

void removerNo(no **raiz, no *noRemovido) {
    if (noRemovido->esquerda == NULL) { // se não tem esquerda, vai substituir pela direita
        transplant(raiz, noRemovido, noRemovido->direita);

    } else if (noRemovido->direita == NULL) { // se não tem direita, vai substituir pela esquerda
        transplant(raiz, noRemovido, noRemovido->esquerda);

    } else { // tem direita e esquerda, então procura o sucessor
        int valorSucessor = buscarValorMinimo(&noRemovido->direita);
        no *sucessor = buscarValor(raiz, valorSucessor);

        if (sucessor->pai != noRemovido) {
            transplant(raiz, sucessor, sucessor->direita);

            sucessor->direita = noRemovido->direita;
            sucessor->pai = sucessor;
        } 

        transplant(raiz, noRemovido, sucessor);
        sucessor->esquerda = noRemovido->esquerda;
        sucessor->esquerda->pai = sucessor;
    }
}

void exibirArvore(no *raiz, int nivel) {
    if (raiz == NULL)
        return;

    // imprime lado esquerdo
    exibirArvore(raiz->esquerda, nivel + 1);

    // imprime indentação de acordo com o nível
    for (int i = 0; i < nivel; i++)
        printf("    ");

    // imprime valor do nó
    printf("%d\n", raiz->valor);

    // imprime lado direito
    exibirArvore(raiz->direita, nivel + 1);

}
