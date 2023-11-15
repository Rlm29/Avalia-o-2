#include <stdio.h>

// validar a quantidade de peças fabricadas
int validaQuantidade(int quantidade) {
    if (quantidade <= 0) {
        printf("Quantidade inválida. Digite novamente.\n");
        return -1;
    } else {
        return quantidade;
    }
}

// calcular o salário total
float calculaSalario(int quantidade) {
    const float salarioBase = 600.00;
    const float adicional50 = 0.50;
    const float adicional80 = 0.75;

    if (quantidade <= 50) {
        return salarioBase;
    } else if (quantidade <= 80) {
        return salarioBase + (quantidade - 50) * adicional50;
    } else {
        return salarioBase + 30 * adicional50 + (quantidade - 80) * adicional80;
    }
}

// mostrar o resultado final
void mostraFinal(char nome[], float salario) {
    printf("O funcionario %s recebera um salario de R$%.2f\n", nome, salario);
}

// algoritmo principal
int main() {
    char nome[50];
    int quantidadePecas;

    while (1) {
        printf("Digite o nome do funcionario (ou 'sair' para encerrar): ");
        scanf("%s", nome);

        if (strcmp(nome, "sair") == 0) {
            break;
        }

        printf("Digite a quantidade de pecas fabricadas por %s: ", nome);
        scanf("%d", &quantidadePecas);

        quantidadePecas = validaQuantidade(quantidadePecas);

        if (quantidadePecas != -1) {
            float salarioTotal = calculaSalario(quantidadePecas);
            mostraFinal(nome, salarioTotal);
        }
    }

    return 0;
}