# lpa-trabalho-b1
Programa fictício de entregas locais em C++

# Trabalho B1 - Lógica de Programação e Algoritmos 
 
## Descrição 
O projeto consiste num programa em linguagem C++ de entregas locais, calculando o valor do serviço com taxas e serviços adicionais, sendo também possível processar várias entregas em uma única sessão do programa.
 
## Funcionalidades
Recebe e valida os seguintes dados:

Distância (Deve ser maior que 0)

Peso (Deve ser maior que 0)

Modalidade (Selecionar uma das opções: 1 - Econômica; 2 - Expressa; 3 - Prioritária)

Serviço de Proteção (Selecionar: 0 - Não ou 1 - Sim)

Tentativas Adicionais (Deve ser maior ou igual a 0)

Finalizar sessão ou iniciar nova entrega (0 - Finalizar sessão ou 1 - Nova entrega)

Resumo final: Total de entregas, Valor total, Valor medio das entregas, Quantidade de cada modalidade, Maior valor e Menor valor.
 
## Organização da solução 
ReceberDistancia() - Essa função irá solicitar a distância e calcular, depois retornar o valor para int main()

receberPesoModalidade() - Essa função receberá o valor atual calculado da distância e solicitar o peso e a modalidade, aplicando separadamente suas respectivas taxas, se necessário.

ativarProtecao() - Pergunta ao usuário se deseja pagar um valor extra para a proteção adicional, calcula e devolve com o novo valor.

receberTentativasEntregas() - Pergunta ao usuário quantas tentativas extras deseja após a primeira em caso de falha, calcula e devolve com o valor final.

contabilizarEstatisticas() - Após calcular o valor total, essa função é chamada para atualizar as variáveis para o resumo final, tais como: quantidade de entregas, valor total das entregas, maior valor, etc...
 
## Compilação 
Terminal do windows:
Certifique-se de ter um compilador de C++ instalado, tal como o g++
Abra o arquivo "programa.exe" na pasta do projeto, ou execute no cmd: cd "diretorio do projeto até /src" e depois o comando: g++ main.cpp -o programa.exe

Compilar no VSCode:
Com um compilador de C++, abra a pasta src no arquivo main.cpp pelo VSCode, use o atalho Ctrl + Shift + B e F6 para compilar o programa.
 
## Uso de Inteligência Artificial 
Declaro que não utilizei ferramentas de Inteligência Artificial generativa para produzir código ou texto 
deste trabalho.
 
## Fontes consultadas 
Não houve fontes consultadas durante o projeto.