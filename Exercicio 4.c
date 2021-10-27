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
    //Atribuição dos ponteiros que percorrerão a lista
    struct no *proximo;
    struct no *anterior;
} No;

//Função que insere elementos na lista em ordem de inserção
void inserir_elemento(No **lista, int num)
{
    //Alocando memória equivalente ao tamanho da estrutura "nó" criada
    No *aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;

        // Checa se é o primeiro elemento a ser inserido
        if (*lista == NULL)
        {
            *lista = novo;
            novo->anterior = NULL;
        }
        else
        {
            aux = *lista;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
    else
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

//Função que imprime os atuais elementos da lista de forma inversa
void imprimir_lista_inversa(No *no)
{
    printf("\n\tLista inversa: ");
    while (no)
    {
        printf("%d ", no->valor);
        no = no->anterior;
    }
    printf("\n\n");
}

// Função que atribui o ponteiro para o último nó da lista
No *ultimo(No **lista)
{
    No *aux = *lista;
    while (aux->proximo)
        aux = aux->proximo;
    return aux;
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
        printf("\n ************************ ESTRUTURAS DE DADOS - EX4 - INVERTER ORDEM DA LISTA ************************\n");
        printf("\nOpcoes: \n\n");
        printf(" 0 - Sair \n");
        printf(" 1 - Inserir Elemento na Lista \n");
        printf(" 2 - Exibir Lista \n");
        printf(" 3 - Exibir Lista Inversa \n\n");
        //Lê a opção que o usuário selecionou
        scanf("%d", &opcao);

        //De acordo com a opção que o usuario escolher, o "case" acessa a respectiva função
        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            printf("\n");
            inserir_elemento(&lista, valor);
            printf("Elemento inserido! \n");
            printf("\n");
            break;

        case 2:
            imprimir_lista(lista);
            break;
        case 3:
            imprimir_lista_inversa(ultimo(&lista));
            break;
        default:
            //Se a opção escolhida nao estiver listada nos casos, imprimir opção inexistente
            if (opcao != 0)
                printf("Opcao inexistente!\n");
        }

    } while (opcao != 0);

    return 0;
}