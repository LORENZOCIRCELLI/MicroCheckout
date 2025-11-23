#ifndef PRODUTOS_H
#define PRODUTOS_H
#include <Arduino.h>

struct Produto {
  String uid;
  String nome;
  float preco;
};

extern Produto produtos[];
extern const int qtdProdutos;

#endif
