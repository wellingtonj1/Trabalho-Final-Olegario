#ifndef PEDIDO_H
#define PEDIDO_H
#include "Pessoa.h"
#include <queue>
#include <QDate>
#include "Item.h"


class Pedido: public Pessoa
{
private:
    Item objitem;
    int numero;
    Pessoa cliente;
    std::string status;
    QDate data;
    float valortotal;

public:
    Pedido();
    friend ostream& operator << (ostream& saida,Pedido& pedid)
    {
        saida<<"Dados do Pedido--> Numero :"
             <<pedid.numero<<", Status :"
             <<pedid.status<<", Data :"
             <<pedid.getdata()<<", Valor total :"
             <<pedid.valortotal<<", Quantidade :"
             <<pedid.objitem.getquanti()<<", Preço unitario :"
             <<pedid.objitem.getpcounitario()<<", Valor Total :"
             <<pedid.objitem.getvalortotal()<<std::endl;


        return saida;
    }
    void setnumero(int x){numero=x;}
    int getnumero(){return numero;}
    Pessoa getcliente(){return cliente;}
    void setvalortotal(){;}
    float getvalortotal(){return valortotal;}
    void setstatus(std::string status){ this->status=status;}
    std::string getstatus(){return status;}
    void setdata(){data=QDate::currentDate();}
    std::string getdata();
    void setitem(Item *aux){ objitem=*aux;}
    bool setcliente(Pessoa *aux)
    {
        if(aux!=nullptr)
        {
            cliente=*aux;
            return true;
        }
        else
        {
            return false;
        }
    }

};

#endif // PEDIDO_H
