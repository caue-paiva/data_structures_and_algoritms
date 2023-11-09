#include "abb.h"



int main(){
    ITEM* I1 = item_criar(5);
    ITEM* I2 = item_criar(3);
    ITEM* I3 = item_criar(4);
    ITEM* I4 = item_criar(2);
    ITEM* I5 = item_criar(7);
    AB* arvo = abb_criar();
    abb_inserir(arvo,I1);
    abb_inserir(arvo,I2);
    abb_inserir(arvo,I3);
    abb_inserir(arvo,I4);
    abb_inserir(arvo,I5);

    abb_imprime(arvo);
    abb_remove(arvo, I1);
    printf("\n\n");
    abb_imprime(arvo);
}