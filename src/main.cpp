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
        printf("A partir de 31km: R$25,00\n");
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

float receberPesoModalidade(float valorAtual, int &economicas, int &expressas, int &prioritarias) {
    float peso, taxaPeso, taxaModalidade = 0;
    int entradaPesoValida = 0, entradaModalidadeValida = 0;
    int modalidade;

    while(entradaPesoValida == 0) {
        printf("============= PESO =============\n");
        printf("\nAté 2kg: Valor normal\n");
        printf("\nAcima de 2kg até 5kg: 5%% taxa adicional\n");
        printf("\nAcima de 5kg até 10kg: 10%% taxa adicional\n");
        printf("\nAcima de 10kg: 20%% taxa adicional\n");
        printf("\nInsira o peso a ser carregado em kg: ");
        scanf("%f", &peso);

        if(peso > 0) {
            if(peso <= 2) {
                taxaPeso = 0 * valorAtual;
            } else if (peso <= 5) {
                taxaPeso = 0.05 * valorAtual;
            } else if (peso <= 10) {
                taxaPeso = 0.1 * valorAtual;
            } else {
                taxaPeso = 0.2 * valorAtual;
            }
            entradaPesoValida = 1;
            printf(">>> Valor adicional peso: %.2f\n", taxaPeso);
        } else {
            printf("\nPor favor, o peso deve ser maior que 0.\n");
        }
    }

    while(entradaModalidadeValida == 0) {
        printf("\n========== MODALIDADE ==========\n");
        printf("1 - Econômica: Valor normal\n");
        printf("2 - Expressa: 15%% taxa adicional\n");
        printf("3 - Prioritária: 30%% taxa adicional\n");
        printf("\nEscolha uma modalidade: ");
        scanf("%d", &modalidade);   

        switch(modalidade) {
            case 1:
                entradaModalidadeValida = 1;
                taxaModalidade = valorAtual * 0;
                economicas += 1;
                break;
            case 2:
                entradaModalidadeValida = 1;
                taxaModalidade = valorAtual * 0.15;
                expressas += 1;
                break;
            case 3:
                entradaModalidadeValida = 1;
                taxaModalidade = valorAtual * 0.30;
                prioritarias += 1;
                break;
            default:
                printf("\nA modalidade deve ser um numero inteiro entre 1 e 3.\n");
        }
    }

    printf(">>> Valor adicional modalidade: %.2f\n", taxaModalidade);
    return valorAtual + taxaPeso + taxaModalidade;
}

float ativarProtecao(float valorAtual) {
    float valorFinal;
    int entradaValida = 0;
    int protecao;

    while(entradaValida == 0) {
        printf("Deseja contratar o servico adicional de proteção?\n");
        printf("0 - Não\n");
        printf("1 - Sim (R$7.50 adicional)\n");
        scanf("%d", &protecao);

        switch(protecao) {
            case 0:
                entradaValida = 1;
                return valorAtual;
                break;
            case 1:
                entradaValida = 1;
                valorFinal = valorAtual + 7.50;
                return valorFinal;
                break;
            default:
                printf("Por favor, insira 0 ou 1.\n");
        }
    }
}

int main(void) {
    system("chcp 65001 > nul");
	setlocale(LC_ALL, "Brazilian Portuguese");

    int programaRodando = 1;
    int inputConclusaoValido;
    float subtotal = 0;
    int qtdEconomicas = 0, qtdExpressas = 0, qtdPrioritarias = 0;
    
    while (programaRodando == 1) {

        subtotal = receberDistancia();
        subtotal = receberPesoModalidade(subtotal, qtdEconomicas, qtdExpressas, qtdPrioritarias);
        subtotal = ativarProtecao(subtotal);

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
