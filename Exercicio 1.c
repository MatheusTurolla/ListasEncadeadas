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

//Função que acrescenta valores à lista
void inserir_elemento(No **lista, int num)
{
    //Alocando memória equivalente ao tamanho da estrutura "nó" criada
    No *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
        //Controle de erros
        printf("Não foi possível alocar memória!\n");
}

//Função que realiza a busca um elemento pela chave e retorna o o endereço do valor(ponteiro)
No *buscar_elemento(No **lista, int num)
{
    //Ponteiros "aux" e "no" inicialmente recebem null
    No *aux, *no = NULL;

    //aux recebe o ponteiro(lista)
    aux = *lista;
    //Enquanto o ponteiro aux for diferente do valor inserido para busca, ele passa para o próximo valor da lista
    while (aux && aux->valor != num)
        aux = aux->proximo;
    if (aux)
        no = aux;
    return;
}

//Função principal que executa o teste das demais funções
int main()
{
    //Declarando as variáveis que serão utilizadas na função Main()
    int opcao, valor;
    No *busca, *lista = NULL;

    //Menu de opções e entrada de dados do usuário
    do
    {
        printf("\n ************************ ESTRUTURAS DE DADOS - EX1 - BUSCAR UM ELEMENTO E RETORNAR SEU PONTEIRO ************************\n");
        printf("\nOpcoes: \n\n");
        printf(" 0 - Sair \n");
        printf(" 1 - Inserir Elemento na Lista \n");
        printf(" 2 - Efetuar a Busca de um Elemento \n\n");
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
            printf("Digite um valor para busca: ");
            scanf("%d", &valor);
            printf("\n");
            busca = buscar_elemento(&lista, valor);
            if (busca)
            {
                printf("Endereco do valor encontrado: %x\n", &valor);
            }
            else
            {
                printf("Elemento nao encontrado!\n\n");
            }
            break;
        default:
            //Se a opção escolhida nao estiver listada nos casos, imprimir opção inexistente
            if (opcao != 0)
                printf("Opcao inexistente!\n");
        }

    } while (opcao != 0);

    return 0;
}