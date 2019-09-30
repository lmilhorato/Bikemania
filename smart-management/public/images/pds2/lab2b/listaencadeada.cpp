#include "listaencadeada.h"
  ListaEncadeada::ListaEncadeada(){
     this-> num_elementos = 0;
     this-> inicio = nullptr;
     this-> final = nullptr;
 };
 void ListaEncadeada::insere_elemento(int dado){
     node_t *novo  =  new node_t();
     novo->elemento = dado;
     if(this->num_elementos == 0){
         this->inicio =  novo;
         this->final =  novo;
     }
     else{
         this->final->proximo = novo;
         novo->anterior = final;
         this->final = novo;
     }
     this->num_elementos++;

 };
 
 void ListaEncadeada::insere_primeiro(int dado){
     node_t *novo = new node_t();
     novo->elemento = dado;
     if(this->num_elementos == 0){
         this->inicio = novo;
         this->final = novo;
     }
     else{
         this->inicio->anterior = novo;
         novo->proximo = inicio;
         inicio = novo;
     }
     this->num_elementos++;
 };
 int ListaEncadeada::get_iesimo(int i){
     if(i >= this->num_elementos){
         return 0;
     }
     node_t *atual = this->inicio;
     for(int j = 0; j<i; j++){
         atual= atual->proximo;
     }
     return atual->elemento;
         
 };
 int ListaEncadeada::tamanho(){
     return this->num_elementos;
 };
 void ListaEncadeada::remove_elemento(){
     this->final = final->anterior;
     this->final->proximo = nullptr;
     num_elementos--;
 };
 void ListaEncadeada::remove_primeiro(){
     this->inicio = inicio->proximo;
     this->inicio->anterior = nullptr;
     num_elementos--;
 };
 void ListaEncadeada::insere_iesimo(int dado, int i){
     node_t *novo = new node_t();
     novo->elemento = dado;
     if(i > num_elementos){
         return;
     }
     if(i == 0){
         this->inicio = novo;
         this->final = novo;
         num_elementos++;
         return;
     }
     else if(i == num_elementos){
         this->final->proximo = novo;
         novo->anterior = this->final;
         num_elementos++;
         return;
     }
     else{
         node_t *atual = this->inicio;
         for(int j = 0; j < i; j++){
             atual=atual->proximo;
         }
         novo->anterior = atual->anterior;
         novo->proximo = atual;
         atual->anterior = novo;
         novo->anterior->proximo = novo;
         num_elementos++;
     }
 };
 void ListaEncadeada::remove_iesimo(int i){
     if (i >= this->num_elementos)
 return;
 node_t *atual = this->inicio;
 node_t *anterior = nullptr;
 for (int j = 0; j < i; j++) {
 anterior = atual;
 atual = atual->proximo;
 }
 if (anterior != nullptr)
 anterior->proximo = atual->proximo;
 if (i == 0)
 this->inicio = atual->proximo;
 if (i == this->num_elementos - 1)
 this->final = anterior;
 this->num_elementos--;
 delete atual;
 };
  void ListaEncadeada::remove_consecutivos(){
      int tam=tamanho();
      int i;
   
    for(i=0; i<tam;i++){
        if(get_iesimo(i)==get_iesimo(i+1)){
            remove_iesimo(i);
            i--;
        } 
    }
  };