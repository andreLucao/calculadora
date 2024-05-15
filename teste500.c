


#include <stdio.h>
#include <string.h> // Para usar a função strcmp




int main() {
    char op[2];
    double n1, n2, n3;

    printf("Digite o primeiro numero: ");
    scanf("%lf", &n1);

    while (strcmp(op, "a") != 0) { // enquanto o usuário não digitar 'a'

        printf("Escolha a operacao (+ - * /) ou 'a' para sair: ");
        scanf("%s", op); // lê como uma string

        if (strcmp(op, "a") == 0) // se o usuário digitar 'a', sai do loop
            break;

        printf("Digite o segundo numero: ");
        scanf("%lf", &n2);

        switch (op[0]) { // op é um vetor de caracteres, usamos op[0] para acessar o primeiro caractere
            case '+':
                n3 = n1 + n2;
                printf("O resultado e: %lf\n", n3);
                break;
            case '-':
                n3 = n1 - n2;
                printf("O resultado e: %lf\n", n3);
                break;
            case '*':
                n3 = n1 * n2;
                printf("O resultado e: %lf\n", n3);
                break;
            case '/':
                if (n2 != 0) {
                    n3 = n1 / n2;
                    printf("O resultado e: %lf\n", n3);
                } else {
                    printf("Erro: divisao por zero!\n");
                }
                break;
            default:
                printf("Operador inválido!\n");
                break;
        }
        n1 = n3; // atualiza n1 com o resultado da operação
    }

    printf("Programa encerrado.\n");

    return 0;
}
