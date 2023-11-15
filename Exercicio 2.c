#include <stdio.h>

// validar o sexo
char validaSexo(char sexo) {
    while (sexo != 'M' && sexo != 'F') {
        printf("Sexo inválido. Digite novamente (M para masculino, F para feminino): ");
        scanf(" %c", &sexo);
    }
    return sexo;
}

// validar o salário
float validaSalario() {
    float salario;
    do {
        printf("Digite o salário do assalariado (maior que R$1,00): ");
        scanf("%f", &salario);
    } while (salario <= 1.00);
    return salario;
}

// classificar o salário em relação ao salário mínimo
char classificaSalario(float salario) {
    const float salarioMinimo = 1400.00;

    if (salario > salarioMinimo) {
        return 'A'; // Acima do salário mínimo
    } else if (salario == salarioMinimo) {
        return 'I'; // Igual ao salário mínimo
    } else {
        return 'B'; // Abaixo do salário mínimo
    }
}

//  mostrar os resultados
void mostraClassifica(char nome[], float salario, char sexo) {
    printf("Assalariado: %s\n", nome);
    printf("Salario: R$%.2f\n", salario);
    printf("Classificacao: %c\n", classificaSalario(salario));
    printf("Sexo: %s\n", (sexo == 'M') ? "Masculino" : "Feminino");
}

// algoritmo principal
int main() {
    int assalariadosAbaixo = 0;
    int assalariadosAcima = 0;
    char nome[50];
    char sexo;
    float salario;

    while (1) {
        printf("Digite o nome do assalariado (ou 'sair' para encerrar): ");
        scanf("%s", nome);

        if (strcmp(nome, "sair") == 0) {
            break;
        }

        printf("Digite o sexo do assalariado (M para masculino, F para feminino): ");
        scanf(" %c", &sexo);
        sexo = validaSexo(sexo);

        salario = validaSalario();

        mostraClassifica(nome, salario, sexo);

        if (classificaSalario(salario) == 'A') {
            assalariadosAcima += 1;
        } else if (classificaSalario(salario) == 'B') {
            assalariadosAbaixo += 1;
        }
    }

    printf("Quantidade de assalariados abaixo do salario minimo: %d\n", assalariadosAbaixo);
    printf("Quantidade de assalariados acima do salario minimo: %d\n", assalariadosAcima);

    return 0;
}
