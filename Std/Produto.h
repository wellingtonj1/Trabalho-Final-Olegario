#ifndef PRODUTO_H
#define PRODUTO_H
#include<QString>
#include<iostream>
#include<fstream>
using namespace std;

class Produto
{
private:
    int codigo;
    string descricao;
    float preco;
    int quantidade;
public:
    Produto();
    friend ostream& operator << (ostream& saida,Produto &Product)
    {
        saida<<Product.descricao<<";"
             <<Product.codigo<<";"
             <<Product.preco<<";"
             <<Product.quantidade<<std::endl;

        return saida;

    }
    void setCodigo(int codigo){this->codigo=codigo;}
    void setDescricao(string descricao){this->descricao=descricao;}
    void setPreco(float preco){this->preco=preco;}
    void setQuantidade(int quantidade){this->quantidade=quantidade;}

    int getCodigo(){return codigo;}
    string getDescricao(){return descricao;}
    float getPreco(){return preco;}
    int getQuantidade(){return quantidade;}
    void removeproduto(std::string x)
    {
        if(x!="")
        {
            std::string aux,desc;
            fstream arqprod,arqaux;
            bool encontrado =false;
            arqprod.open("Produtos.txt",ios::in|ios::app);
            arqaux.open("Produtos aux.txt",ios::out|ios::in|ios::app);
            if(arqprod.is_open()&&arqaux.is_open())
            {
                while(!arqprod.eof())
                {
                    getline(arqprod,aux);
                    desc= aux.substr(0,aux.find(";"));
                    if(x==desc)
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
                    remove("Produtos.txt");
                    rename("Produtos aux.txt","Produtos.txt");
                    puts("Produto removido");
                }
                else
                {
                    puts("Nenhum dado encontrado!");
                    remove("Produtos aux.txt");
                }
            }
        }
        else
        {
            puts("Nenhum dado Inserido!");
        }
    }

    void mostrarprods()
    {
        std::string aux;
        fstream arqprod;
        arqprod.open("Produtos.txt",ios::out|ios::in|ios::app);
        if(arqprod.is_open())
        {
            while(!arqprod.eof())
            {
                getline(arqprod,aux);
                cout<<aux<<endl;
            }
        }
    }
};

#endif // PRODUTO_H
