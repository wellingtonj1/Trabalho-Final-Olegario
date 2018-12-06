#ifndef ITEM_H
#define ITEM_H
#include <list>
#include "Produto.h"
#include <fstream>
#include <iostream>

class Item
{
private:

    std::string objproduto;
    int quantidade;
    float pcounitario,valortotal; //quantidade de produtos pço de cada produto valor total é o pço x quantidade;


public:
    Item();
    bool buscaprod(std::string aux);
    std::string getdescriprod(){return objproduto;}
    int getquanti(){ return quantidade;}
    float getpcounitario() { return pcounitario;}
    float getvalortotal() { return valortotal;}
    void setquanti(int x) { quantidade=x;}
    void setpcounitario(float x) { pcounitario=x;}
    void setvalortotal() { valortotal=pcounitario*quantidade;}    
    void setdesc(std::string x) {objproduto=x;}
    float rtpreco(std::string aux);
    Item* criaitem(std::string linha)
    {
        Item* p=new Item();
        std::string delimitador=";", atributo;
        unsigned long pos=0;

        atributo = linha.substr(0, linha.find(delimitador));
        p->setquanti(std::stoi(atributo));
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0, linha.find(delimitador));
        p->setpcounitario(std::stof(atributo));
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        p->setvalortotal();

        return p;

    }
    friend ostream& operator << (ostream& saida,Item& it)
    {
        saida<<it.getquanti()<<";"
             <<it.getpcounitario()<<";"
             <<it.getvalortotal()<<std::endl;

        return saida;
    }

};

#endif // ITEM_H
