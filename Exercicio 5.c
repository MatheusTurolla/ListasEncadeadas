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
    //Atribuições de ponteiros que navegam nos dois sentidos(tanto para o próximo nó dda lista, quanto para o anterior). Caracterizando uma lista duplamente encadeada
    struct no *proximo;
    struct no *anterior;
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
            novo->anterior = NULL;
            *lista = novo;
        }
        // Checa se há valores na lista, e compara com o valor a ser inserido
        else if (novo->valor < (*lista)->valor)
        {
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            if (aux->proximo)
                aux->proximo->anterior = novo;
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }
    else
        //Controle de erros
        printf("Não foi possível alocar memoria!\n");
}

//Função para remover um específico elemento da lista
No *remover_elemento(No **lista, int num)
{
    //Nessa função, inicialmente os ponteiros "aux" e "remover" começam vazios
    No *aux, *remover = NULL;

    //Se o valor inserido for igual ao elemento que estiver apontado pra lista, então ele é removido e o espaço vazio é substituido
    if (*lista)
    {
        if ((*lista)->valor == num)
        {
            remover = *lista;
            *lista = remover->proximo;
            if (*lista)
                (*lista)->anterior = NULL;
        }
        else
        {
            aux = *lista;
            while (aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if (aux->proximo)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if (aux->proximo)
                    aux->proximo->anterior = aux;
            }
        }
    }
    return remover;
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

//Declarando as variáveis que serão utilizadas na função Main()
int main()
{

    int opcao, valor;
    No *removido, *lista = NULL;

    //Menu de opções e entrada de dados do usuário
    do
    {
        printf("\n ************************ ESTRUTURAS DE DADOS - EX5 - LISTA DUPLAMENTE ENCADEADA ************************\n");
        printf("\nOpcoes: \n\n");
        printf(" 0 - Sair \n");
        printf(" 1 - Inserir Elemento na Lista em Ordem Crescente \n");
        printf(" 2 - Remover Elemento da Lista \n");
        printf(" 3 - Exibir Lista \n\n");
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
            printf("Digite um elemento a ser removido: ");
            scanf("%d", &valor);
            printf("\n");
            removido = remover_elemento(&lista, valor);
            if (removido)
            {
                printf("Elemento removido: %d\n", removido->valor);
                //Limpa o espaço de memória que o malloc alocou
                free(removido);
            }
            else
                printf("Elemento inexistente!\n");
            break;
        case 3:
            imprimir_lista(lista);
            break;

        default:
            //Se a opção escolhida nao estiver listada nos casos, imprimir opção inexistente
            if (opcao != 0)
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}