//Biblioteca que controlam entrada e saída de dados
#include <stdio.h>
//Biblioteca que fornece definições da linguagem de programação C para as macros (NULL,etc)
#include <stddef.h>
//Biblioteca para funções de uso geral
#include <stdlib.h>

//Definindo o tipo e atribuindo o novo nome para a estrutura
typedef struct no
{
    int valor;
    struct no *proximo;
} No;

//Função que insere elementos na lista em ordem crescente
void inserir_ordem_crescente(No **lista, int num)
{
    //Alocando memória equivalente ao tamanho da estrutura "nó" criada
    No *aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        // Faz a checagem se a lista esta vazia e se é o primeiro elemento a ser inserido
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        } // Se já tiver valores na lista, comparar com o valor a ser inserido
        else if (novo->valor < (*lista)->valor)
        {
            novo->proximo = *lista;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        //Controle de erros
        printf("Não foi possível alocar memória!\n");
}

//Função que imprime os atuais elementos da lista
void imprimir_lista(No *no)
{
    printf("\n\tLista: ");

    while (no)
    {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

//Função principal que executa o teste das demais funções
int main()
{
    //Declarando as variáveis que serão utilizadas na função Main()
    int opcao, valor;
    No *lista = NULL;

    //Menu de opções e entrada de dados do usuário
    do
    {
        printf("\n ******************* ESTRUTURAS DE DADOS - EX3 - INSERCAO DE ELEMENTOS NA LISTA EM ORDEM CRESCENTE *******************\n");
        printf("\nOpcoes: \n\n");
        printf(" 0 - Sair \n");
        printf(" 1 - Inserir Elemento na Lista em Ordem Crescente \n");
        printf(" 2 - Exibir Lista \n\n");
        //Lê a opção que o usuário selecionou
        scanf("%d", &opcao);

        //De acordo com a opção que o usuario escolher, o "case" acessa a respectiva função
        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            printf("\n");
            inserir_ordem_crescente(&lista, valor);
            printf("Elemento inserido! \n");
            printf("\n");
            break;

        case 2:
            imprimir_lista(lista);
            break;

        default:
            //Se a opção escolhida nao estiver listada nos casos, imprimir opção inexistente
            if (opcao != 0)
                printf("Opcao inexistente!\n");
        }

    } while (opcao != 0);

    return 0;
}