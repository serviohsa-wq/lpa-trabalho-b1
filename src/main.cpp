#include <iostream>
#include <locale.h>

float receberDistancia() {
    float distancia, valorBase;
    int entradaValida = 0;
    float valorFinal;

    while (entradaValida == 0) {
        printf("============= DISTÂNCIA =============\n");
        printf("Até 5km: R$8,00\n");
        printf("De 6 a 15km: R$12,00\n");
        printf("De 16 a 30km: R$18,00\n");
        printf("A partir de 31km......: R$25,00\n");
        printf("Insira a distância a ser percorrida em km: ");
        scanf("%f", &distancia);

        if(distancia > 0) {
            entradaValida = 1;
            if(distancia <= 5) {
                valorBase = 8;
            } else if(distancia <= 15) {
                valorBase = 12;
            } else if(distancia <= 30) {
                valorBase = 18;
            } else {
                valorBase = 25;
            }

            valorFinal = valorBase + (distancia * 1.20);
            // printf("Valor distancia: %.2f", valorFinal);
            return valorFinal;
        } else {
            printf("\nPor favor, insira um numero maior que 0.\n");
        }
    }
    return 0;
}

int main(void) {
    system("chcp 65001 > nul");
	setlocale(LC_ALL, "Brazilian Portuguese");

    int programaRodando = 1;
    int inputConclusaoValido;
    float subtotal = 0;
    
    while (programaRodando == 1) {

        subtotal = receberDistancia();

        inputConclusaoValido = 0;
        while(inputConclusaoValido == 0) {
            printf("\n=== Entrega processada ===\n");
            printf("Valor da entrega: R$%.2f\n", subtotal);
            printf("0 - Concluir sessão\n");
            printf("1 - Processar nova entrega\n");
            scanf("%d", &programaRodando);

            switch(programaRodando) {
                case 1:
                    inputConclusaoValido = 1;
                    break;
                case 0:
                    inputConclusaoValido = 1;
                    break;
                default:
                    printf("\nOpção inválida, por favor insira uma opção válida.\n");
            }
        }
    }
    
    return 0;
}
