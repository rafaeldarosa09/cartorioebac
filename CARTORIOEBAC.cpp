#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Cores ANSI
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define WHITE_BACKGROUND "\033[47m"

// Função para registro de dados
int registro() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf(YELLOW "Digite o CPF a ser cadastrado:\n\n" RESET);
    scanf("%s", cpf);
    strcpy(arquivo, cpf);

    FILE *file = fopen(arquivo, "w");
    fprintf(file, "CPF: %s\n", cpf);
    fclose(file);

    system("cls");
    printf(YELLOW "Digite o nome:\n\n" RESET);
    scanf("%s", nome);
    file = fopen(arquivo, "a");
    fprintf(file, "Nome: %s\n", nome);
    fclose(file);

    system("cls");
    printf(YELLOW "Digite o sobrenome:\n\n" RESET);
    scanf("%s", sobrenome);
    file = fopen(arquivo, "a");
    fprintf(file, "Sobrenome: %s\n", sobrenome);
    fclose(file);

    system("cls");
    printf(YELLOW "Digite o cargo:\n\n" RESET);
    scanf("%s", cargo);
    file = fopen(arquivo, "a");
    fprintf(file, "Cargo: %s\n", cargo);
    fclose(file);

    printf(GREEN "\nRegistro salvo com sucesso!\n" RESET);
    system("pause");
    return 0;
}

// Função para consulta de dados
int consultar() {
    char cpf[40];
    char conteudo[200];

    printf(YELLOW "Digite o CPF para consulta:\n" RESET);
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf(RED "\nArquivo não localizado!\n\n" RESET);
    } else {
        printf(BLUE "\nEssas são as informações:\n\n" RESET);
        while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
            printf("%s", conteudo);
        }
        fclose(file);
    }

    printf("\n\n");
    system("pause");
    return 0;
}

// Função para deletar arquivos (cadastros)
int deletar() {
    char cpf[40];
    char confirmacao;

    printf(YELLOW "Digite o CPF para deletar o cadastro:\n" RESET);
    scanf("%s", cpf);

    printf(RED "\nTem certeza que deseja deletar o cadastro de CPF %s? (s/n): " RESET, cpf);
    scanf(" %c", &confirmacao);  // Espaço antes do %c consome o '\n' pendente

    if (confirmacao == 's' || confirmacao == 'S') {
        if (remove(cpf) == 0) {
            printf(GREEN "\nCadastro deletado com sucesso!\n" RESET);
        } else {
            printf(RED "\nErro ao deletar o cadastro. Arquivo não encontrado.\n" RESET);
        }
    } else {
        printf(YELLOW "\nOperação de exclusão cancelada.\n" RESET);
    }

    system("pause");
    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    while (1) {
        system("cls");

        printf(CYAN "###################################\n" RESET);
        printf(CYAN "         *** CARTÓRIO ***         \n" RESET);
        printf(CYAN "###################################\n\n" RESET);

        printf(GREEN "\t[1]" RESET " Registrar nomes\n\n");
        printf(GREEN "\t[2]" RESET " Consultar nomes\n\n");
        printf(GREEN "\t[3]" RESET " Deletar nomes\n\n");
        printf(GREEN "\t[4]" RESET " Sair\n\n\n");

        printf(YELLOW "Opção desejada: " RESET);
        scanf("%d", &opcao);

        system("cls");

        switch(opcao) {
            case 1:
                registro();
                break;
            case 2:
                consultar();
                break;
            case 3:
                deletar();
                break;
            case 4:
                printf(RED "Encerrando o programa...\n" RESET);
                exit(0);
            default:
                printf(RED "Opção inválida!\n" RESET);
                system("pause");
        }
    }
    return 0;
}

