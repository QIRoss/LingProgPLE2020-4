# TrabalhoGrafos
# Lucas de Queiroz dos Reis

# Introdução:

Este trabalho foi concluído utilizando uma lista de adjacências ao invés de ponteiros.
"Node" é uma classe (que poderia ser uma struct) que contém apenas os valores da string a ser adicionada.
"Graph" é uma classe que contém o método para ler o arquivo txt e gerar o resultado das incidências.
Considerando que o enunciado diz que é para utilizar apenas parágrafos, abri mão do O(n.log(n)) do grafo feito com ponteiros e parti para uma abordagem O(n²) utilizando lista de adjacências.

# Uso:

$ make
$./main "arquivo texto a ser processado" "numero de palavras a serem capturadas"

Arquivo "exemplo.txt" do enunciado acompanha o trabalho.

# Algoritmo:

Para n=1, todas as palavras capturadas tem o seu primeiro caractere minimizado. Se as palavras tiverem pontuação como último caractere, este caractere é removido.
Ao encontrar uma palavra, verifica-se se esta palavra já está na lista que é composta por um VETOR DE NÓS. Caso ela esteja na lista, o valor "count" do nó é incrementado. Caso ela não se encontre, um nó com esta palavra e valor "count" 1 é adicionado ao final da lista.

Para n>1, todas as palavras capturadas são armazenadas em um buffer. Quando esse buffer chega a n, estas n palavras são concatenadas na mesma string. Para a próxima iteração do laço, a primeira string do vector queue é removida e a próxima palavra adicionada ao final do vetor, mantendo assim as n palavras enquando conserva as n-1 palavras anteriores. Caso seja encontrada alguma pontuação, este buffer "queue" é esvaziado e recomença a busca. A verificação da lista de incidências é feita da mesma forma que para n=1.

# Auto-avaliação:

Me faltou intimidade com a sintaxe de C++ em alguns pontos. O código foi desnecessariamente repetitivo e com certeza há soluções mais eficientes e/ou elegantes que a minha.
O código está divido em n=1 e n>1 porém o bloco de n>1 também funciona para n=1. Deixei propositalemente estas duas soluções separadas para mostrar que procurei primeiro a solução do caso particular (que ignora pontuação) e logo depois o algoritmo do caso global. Outras adições que poderiam ser feitas no código seria melhorar esteticamente o output na CLI.