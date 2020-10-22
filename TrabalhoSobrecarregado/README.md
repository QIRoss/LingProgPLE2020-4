# Trabalho Operadores Sobrecarregados

Lucas de Queiroz dos Reis

# Objetivo

Compreender o entendimento de como funcionam Operadores Sobrecarregados.
Não há muito o que ser dito sobre este trabalho porque o enunciado é muito preciso sobre o que requisita e "amarra" as possibilidades de modificação de código de muitas maneiras.

# Uso:

$ make
$./main "arquivo texto a ser processado" "inteiro referente ao comprimento maximo do vetor"

Arquivo "filmes.txt" do enunciado acompanha o trabalho.
alavras a serem capturadas

# Análise

Foram escritas diversas funções conforme pede o enunciado.
Todos os requisitos do enunciado foram cumpridos exceto a sobrecarga de ">" para string da struct dos filmes também ser sobrecarregada para double notaDoFilme.

# Auto-avaliação

Além dos operadores sobrecarregados, houve o desafio de controle de informação utilizando manipulação de ponteiros, que foi respondido completamente. Pode-se observar que tanto a desreferenciação do ponteiro para busca quanto a edição do valor de um filme a partir da referência daquele filme foram alcançados. Os requisitos menos alcançados foram os de código enxuto. Se possível ainda vou enxugar parte do "spaghetti code".