# TRABALHO FINAL LINGUAGENS DE PROGRAMAÇÃO
# LUCAS DE QUEIROZ DOS REIS
# DRE 114074787

# API C++ PARA OUTRAS LINGUAGENS

PARTE 1: TEMPLATE ENGINE C++ ACOPLADO AO JAVASCRIPT UTILIZANDO SERVER SIDE RENDERING
Nesta parte do trabalho, optei por algum nível de interface gráfica porque eu queria criar uma template engine que fosse reutilizável para outros projetos que venham a ser feitos futuramente, as classes privadas TopHTML e BottomHTML se complementam e não funcionam uma sem a outra, porém nesta refatoração de código é possível criar/modificar páginas web com C++ e Javascript apenas pela modificação dos parametros de passagem da página e "componentizar" a página: ou seja. Há uma DOM HTML real gerada pelas funções Top e Bottom que permite a permutação de N páginas. Possíveis modificações para este código seria a template engine ser uma classe template de forma que os valores de campos e argumentos sejam modificados através de extensão e sobrecarga da classe.