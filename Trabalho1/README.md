Lucas de Queiroz dos Reis
DRE: 114074787

Comentários do aluno:

Durante o desenvolvimento do trabalho utilizei uma file chamada caos.cpp que também estou enviando mas conforme pode verificar não está no makefile. Devido a problemas iniciais com a sintaxe de strings, vectors, classes e boilerplate do C++ provoquei um "spaghetti code" desnecessário.

A expectativa do trabalho era originalmente utilizar um design pattern Adapter (comprei o livro "Design Patterns" porque o mesmo me pareceu interessante).

Resumo da UML:
O método estadualDeaths da classe Estadual é responsável por processar o csv do qual os dados foram extraídos. Cada ciclo do loop lê as três colunas do csv e utilizar algumas regras de negócio para definir estado, mortes e se está sendo buscado na data correta.

A classe Estadual possui uma friend class Nacional para esta acessar seus atributos privados. A ideia permite que um loop indexando o vetor de UFs instancie um objeto da classe Estado com construtor "uf". A fim de gerar dados nacionais a partir da soma dos dados destes 27 objetos.

Nota de observação: optei na main por utilizar argumentos com 1 mês de espaçamento porque a diferença percentual da curva modificando apenas um dia era muito curta, todos mostrariam estabilidade.

Os dados são reais e foram atualizados até 9 de setembro de 2020.
Os mesmos podem ser encontrados em diversos formatos em 
<a href="https://brasil.io/dataset/covid19/files/" target="_blank">Brasil.io</a>
Colunas não relevantes foram deletadas a fim de facilitar o desenvolvimento do código. Por motivos de trabalho, burnout e 30 créditos semanais apenas implementei as features mínimas para entrega do projeto.

O trabalho se encontra no meu repositório público
<a href="https://github.com/QIRoss/LingProgPLE2020-4/tree/master/Trabalho1" target="_blank">Repo</a>
Caso prefira que o código se mantenha em privado, por favor me avise.

Autocrítica do aluno:

A GUI produzida na CLI poderia ter contado com mais instruções de escolhas de data e uf. Porém considerando que o foco da matéria é OOP acredito que este seja pouco relevante.

A Classe Nacional não conta com métodos get e set para manipular suas funções. Em uma aplicação real acredito que eu utilizaria mais uma classe por cima a fim de encapsular todas as regras de negócio da Classe Nacional (Acredito que esse seja o Chain of Responsability Design Pattern)

Código não utilizou DRY principles. Reutilizei trechos de código e causei propagação de resultados desnecessárias em algumas funções.

Tenho minhas dúvidas se utilizei SOLID principles.

Att, Lucas de Queiroz dos Reis