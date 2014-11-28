#ifndef LEITOR_H_
#define LEITOR_H_

// Importa struct "Carro"
#include "lista.h" 

// Define o separador de milhares
#define SEPARADOR_MILHAR '.'

// getValorFromStr
// Transforma a string em "str" em um valor numérico, ignorando os separadores de milhar.
int getValorFromStr(char *str);

// printNum
// Imprime o valor "num" na tela, incluindo os separadores de milhar.
void printNum(int num);

// createCarro
// Processa "input" de forma a separar o nome, a marca e o valor do carro.
// Retorna um ponteiro para uma struct Carro alocada.
Carro *createCarro(char *input);

// leEntrada
// Lê stdin até EOF, preenchendo structs Carros com os dados da entrada utilizando createCarro().
// Retorna um vetor com todos os objetos Carros criados.
// int *size - Parâmetro usado para "retornar" a quantidade de itens lidos.
Carro *leEntrada(int *size);

#endif
