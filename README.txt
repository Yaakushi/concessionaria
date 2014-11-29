Trabalho - CI056 - Estrutura de Dados e Algoritmos II

Autores:
- Jonathan Rodrigues Szlachta - jrs14 - GRR20143147
- Kaio Augusto de Camargo - kac14 - GRR20143061

Como compilar:
Execute o comando "make" na pasta "src". Um executável será gerado na pasta "bin" (na raiz do projeto) caso a compilação ocorra com sucesso. Caso a pasta "bin" não exista, ela será criada durante o processo de make.

Relatório:
O trabalho foi dividido em 4 módulos, sendo eles:
- Leitor: Módulo responsável pela leitura da entrada e processamento desses dados.
- Lista: Implementação de uma lista duplamente encadeada.
- Sort: Implementação dos métodos de ordenação em lista e vetores, conforme especificado no trabalho.
- Concessionaria: Arquivo com a implementação do trabalho, utilizando os 3 módulos acima.

O módulo "leitor" é um módulo simples, e não há muito o que ser comentado sobre ele.
O módulo "lista" é basicamente a implementação de uma lista duplamente encadeada (não muito distante das listas encadeadas vistas em sala de aula). Escolhemos implementar uma lista duplamente encadeada ao invés de uma encadeada simples pois pensamos que um ponteiro "anterior" poderia ser útil (e um pouco mais de desafio é sempre bem-vindo).
O módulo "sort" contem basicamente com as implementações dos algoritmos de ordenação vistos em sala de aula. Esse foi o módulo mais "problemático", visto que tentamos fazer o insertSort em lista utilizando dois nós para delimitar o inicio e o fim da ordenação (No inicio, No fim), o que se apresentou totalmente ineficaz quando nos demos conta que a posição dos nós variaria durante a ordenação, ou seja, durante os passos da recursividade, o nó "início" poderia sair do começo da lista, o que poderia ocasionar uma ordenação falha.
O módulo "concessionária" é outro módulo simples, apenas implementando as funções dos outros módulos para ler a entrada, ordenar e imprimir na tela conforme necessário.
