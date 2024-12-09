#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Função para registrar usuário
int registro() {
    char arquivo[40], cpf[40], nome[40], sobrenome[40], cargo[40];

    printf("Digite seu CPF a ser cadastrado: ");
    scanf("%39s", cpf);
    strcpy(arquivo, cpf);

    FILE *file = fopen(arquivo, "w"); // Abre para escrita
    if (!file) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    // Coleta e grava informações
    printf("Digite o nome a ser cadastrado: ");
    scanf("%39s", nome);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%39s", sobrenome);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%39s", cargo);

    fprintf(file, "%s,%s,%s,%s", cpf, nome, sobrenome, cargo);
    fclose(file);

    printf("Registro salvo com sucesso!\n");
    system("pause");
    return 0;
}

// Função para consultar usuário
int consulta() {
    char cpf[40], conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%39s", cpf);

    FILE *file = fopen(cpf, "r");
    if (!file) {
        printf("Não foi possível localizar o arquivo!\n");
        system("pause");
        return 1;
    }

    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("\nEssas são as informações do usuário: %s\n", conteudo);
    }
    fclose(file);

    system("pause");
    return 0;
}

// Função para deletar usuário
int deletar() {
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%39s", cpf);

    if (remove(cpf) == 0) {
        printf("Usuário deletado com sucesso!\n");
    } else {
        printf("Erro: usuário não encontrado!\n");
    }
    system("pause");
    return 0;
}

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    while (1) {
        system("cls");

        printf("Primeiro Projeto\n\n");
        printf("\t-### Cartório da EBAC ###-\n\n");
        printf("Escolha a opção desejada do menu: \n\n");
        printf("\t1 - Registrar Nomes\n");
        printf("\t2 - Consultar Nomes\n");
        printf("\t3 - Deletar Nomes\n");
        printf("\t4 - Sair do Sistema\n\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
                printf("Obrigado por utilizar o sistema!\n");
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
                system("pause");
                break;
        }
    }
}
