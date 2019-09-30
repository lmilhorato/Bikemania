#ifndef LISTAENCADEADA_H_
#define LISTAENCADEADA_H_

/*
  usem a struct 'node_t' para criar o atributo nó da lista. Notem que ela possui um campo inteiro
  e um ponteiro para o próximo nó. A lista deve conter referências para o primeiro
  e último nós. A lista deve conter métodos para:
   (a) insere_elemento(int). Insere um elemento no fim da lista.
   (b) insere_primeiro(int). Insere um elemento no inicio da lista.
   (c) get_iesimo(int). Retorna um elemento na posição i.
   (d) remove_elemento(). Remove um elemento no fim da lista.
   (e) remove_primeiro(). Remove o primeiro elemento da lista.
   (f) insere_iesimo(int, int). Insere um elemento na posicão i.
   (g) remove_iesimo(int). Remove um elemento na posição i
   (h) tamanho(). Retorna o numero de elementos da lista atual
*/

struct node_t {
	int elemento;
	node_t *proximo;
	node_t *anterior;
};

class ListaEncadeada{
    private:
    int num_elementos;
    node_t *inicio;
    node_t *final;
    public:
    int tamanho();
  int get_iesimo(int i);
  ListaEncadeada();
  void insere_elemento(int dado);
  void insere_primeiro(int dado);
  void remove_elemento();
  void remove_primeiro();
  void insere_iesimo(int dado, int i);
  void remove_iesimo(int i);
};
#endif /* LISTAENCADEADA_H_ */

