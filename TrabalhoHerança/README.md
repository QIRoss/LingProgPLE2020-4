# LUCAS DE QUEIROZ DOS REIS
# UNIVERSIDADE FEDERAL DO RIO DE JANEIRO
# PROFESSOR MIGUEL ELIAS CAMPISTA
# DRE 114074787

# TRABALHO REFERENTE A OPERADORES CLASSES TEMPLATE E POLIMORFISMO (INCOMPLETO)

# USO (quando pronto):
    $make
    $./main
    Obs: nenhum argumento é necessário.

# RESUMO:
    1- Classe Template Árvore Constrói uma árvore vazia como Classe Cadastro ao inicializar o programa.
    2- Programa abre o menu que permite adicionar um nome, buscar um nome ou imprimir a lista inteira.

# ALGORITMO:
    Para printar a árvore completa, escolhi o algoritmo Breadth First Search como método de sobrecarregar ostream e objeto proveniente da árvore. Este algoritmo carrega um array em ordem de níveis da árvore e logo após este array é impresso utilizando um loop que imprime conforme a sobrecarga para um único elemento.

# FALTAS:
    Estou entregando os arquivos referentes ao paciente e ao paciente emergencial a fim de em breve implementar a classe template. O paciente emergencial utiliza um método virtual da classe base a fim de comprovar que ambos funcionarão para uma implementação feita a partir da classe base.