#ifndef LISTAENCADEADA_H_
#define LISTAENCADEADA_H_

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
  void remove_consecutivos();
};
#endif /* LISTAENCADEADA_H_ */

