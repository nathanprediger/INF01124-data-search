# Descrição da estrutura do projeto

## Considerações iniciais
Para rodar o programa, basta compilar os arquivos (manualmente ou executando `make`) e, após, executar o binário gerado na pasta `/bin`.

## Pastas
1. `/bin` pasta onde é salvo o executável da aplicação após a execução do comando make (ou da compilação manual dos arquivos)
2. `/data` pasta dos arquivos de entrada e saída da aplicação (anicialmente, outputs será vazio, os arquivos serão criados na execução do executável)
3. `/src` arquivos de código fonte do projeto

## Arquivos

### Diretório base
1. gitignore - define quais arquivos serão enxergados pelo Git
2. makefile - define regras para a construção e compilação do projeto. Além de definir o comando `make clean` que apaga os executáveis e os outputs de execuções anteriores do programa.

### Arquivos fonte `/src`
1. utils.cpp - define funções auxiliares ao programa como `get_random_number()`, `swap()`, etc.
2. quicksort.cpp - implementa o quicksort e os arquivos utilizados por ele, como `lomuto()` e `hoare()`
3. main.cpp - Fluxo principal de execução dos programas: abertura dos arquivos, execução dos testes, escrita dos resultados.
4. constants.h - Define constantes do projeto e Struct usada para facilitar execução de testes.


Feito por Marcelo B.
22/04/2024