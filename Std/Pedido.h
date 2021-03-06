#ifndef PEDIDO_H
#define PEDIDO_H
#include "Pessoa.h"
#include <queue>
#include <QDate>
#include "Item.h"
#include <iostream>

class Pedido
{
private:
    Item objitem;
    int numero;
    std::string cliente; //cliente = codigo da pessoa juri ou fis
    std::string status;
    QDate data;
    float valortotal;

public:
    Pedido();
    friend ostream& operator << (ostream& saida,Pedido& pedid)
    {
        saida<<pedid.numero<<";"
             <<pedid.cliente<<";"
             <<pedid.status<<";"
             <<pedid.getdata()<<";"
             <<pedid.valortotal<<";"
             <<pedid.objitem.getquanti()<<";"
             <<pedid.objitem.getpcounitario()<<";"
             <<pedid.objitem.getvalortotal()<<std::endl;


        return saida;
    }
    void setnumero(int x){numero=x;}
    int getnumero(){return numero;}
    std::string getcliente(){return cliente;}
    void setvalortotal(float x){valortotal=x;}
    float getvalortotal(){return valortotal;}
    void setstatus(std::string status){ this->status=status;}
    std::string getstatus(){return status;}
    void setdata(){data=QDate::currentDate();}
    void setdata(int y,int m,int d);
    std::string getdata();
    void setitem(Item *aux){ objitem=*aux;}
    void setcliente(std::string x)
    {
        cliente =x;
    }

    Pedido* criapedi(std::string linha)
    {
        Pedido* p=new Pedido();
        std::string delimitador=";", atributo,auxano,auxmes;
        unsigned long pos=0;

        atributo = linha.substr(0, linha.find(delimitador));
        p->setnumero(std::stoi(atributo));
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0,linha.find(delimitador));
        p->setcliente(atributo);
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0, linha.find(delimitador));
        p->setstatus(atributo);
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0, linha.find("/"));
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        auxmes = linha.substr(0,linha.find("/"));
        pos =auxmes.length()+1;
        linha = linha.substr(pos);
        auxano = linha.substr(0,linha.find(delimitador));
        p->setdata(std::stoi(atributo),std::stoi(auxmes),std::stoi(auxano));
        pos =auxano.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0, linha.find(delimitador));
        p->setvalortotal(std::stof(atributo));
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0, linha.find(delimitador));
        p->objitem.setquanti(std::stoi(atributo));
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0, linha.find(delimitador));
        p->objitem.setpcounitario(std::stof(atributo));
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        atributo = linha.substr(0, linha.find(delimitador));
        p->objitem.setvalortotal();
        pos=atributo.length()+1;
        linha = linha.substr(pos);
        atributo.erase();

        return p;

    }

    void removepedido(int x)
    {
        std::string aux,desc;
        fstream arqpedi,arqaux;
        bool encontrado =false;
        arqpedi.open("filapedidos.txt",ios::in|ios::app);
        arqaux.open("Pedido aux.txt",ios::out|ios::in|ios::app);
        if(arqpedi.is_open()&&arqaux.is_open())
        {
            while(!arqpedi.eof())
            {
                getline(arqpedi,aux);
                desc= aux.substr(0,aux.find(";"));
                if(x==stoi(desc))
                {
                    encontrado =true;
                }
                else
                {
                   arqaux<<aux<<endl;
                }
            }
            if(encontrado==true)
            {
                remove("filapedidos.txt");
                rename("Pedido aux.txt","filapedidos.txt");
                puts("Produto removido");
            }
            else
            {
                puts("Nenhum dado encontrado!");
                remove("Pedido aux.txt");
            }
        }
    }

    void mostrapedidos()
    {
        string aux;
        fstream arqpedis;
        arqpedis.open("filapedidos.txt",ios::out|ios::in|ios::app);
        if(arqpedis.is_open())
        {
            while(!arqpedis.eof())
            {
                getline(arqpedis,aux);
                cout<<aux<<"\n";
            }
        }
    }

};

#endif // PEDIDO_H
