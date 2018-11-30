#ifndef ITEM_H
#define ITEM_H
#include <list>
#include "Produto.h"

class Item
{
private:
    Produto objproduto;
    int quantidade;
    float pcounitario,valortotal; //pcounitario = Preço unitario;


public:
    Item();
    void setproduto(Produto *aux){ objproduto=*aux;}
    int getquanti() { return quantidade;}
    float getpcounitario() { return pcounitario;}
    float getvalortotal() { return valortotal;}
    void setquanti(int x) { quantidade=x;}
    void setpcounitario(float x) { pcounitario=x;}
    void setvalortotal() { valortotal=pcounitario*quantidade;}

};

#endif // ITEM_H
