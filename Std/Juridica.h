#ifndef JURIDICA_H
#define JURIDICA_H
#include "Pessoa.h"
#include <iostream>
#include <fstream>
#include <QString>

using namespace std;

class Juridica: public Pessoa
{
protected:
    string cnpj;
    string razaoSocial;
    string nomeContato;
public:
    Juridica();
    friend ostream& operator << (ostream& os, Juridica& Pessoa){
        os  << Pessoa.codigo    <<";"
            << Pessoa.cnpj         <<";"
            << Pessoa.razaoSocial    <<";"
            << Pessoa.nomeContato    <<";"
            << Pessoa.logradouro     <<";"
            << Pessoa.setor          <<";"
            << Pessoa.cidade         <<";"
            << Pessoa.estado         <<";"
            << Pessoa.telefone       <<";"
            << Pessoa.email          <<::endl;
        return os;
    }

    bool setCnpj(string x);
    void setRazaoSocial(string razaoSocial){this->razaoSocial=razaoSocial;}
    void setNomeContato(string nomeContato){this->nomeContato=nomeContato;}

    string getCnpj(){return cnpj;}
    string getRazaoSocial(){return razaoSocial;}
    string getNomeContato(){return nomeContato;}
    void removepesjuri(std::string x)
    {
        std::string aux,codigo;
        fstream arqjuri,arqaux;
        arqjuri.open("Pessoas Juri.txt",ios::out|ios::in|ios::app);
        arqaux.open("Pesssoas auxj.txt",ios::out|ios::in|ios::app);
        if(arqjuri.is_open())
        {
            while(!arqjuri.eof())
            {
                getline(arqjuri,aux);
                codigo= aux.substr(0,aux.find(";"));
                if(x==codigo)
                {
                    puts("Pessoa removida");
                }
                else
                {
                    arqaux<<aux;
                }
            }
            remove("Pessoas Juri.txt");
            rename("Pesssoas auxj.txt","Pessoas Juri.txt");
        }
    }

    bool existejuri(std::string x)
    {
        std::string aux;
        fstream arqjuri;
        arqjuri.open("Pessoas Juri.txt",ios::out|ios::in|ios::app);
        if(arqjuri.is_open())
        {
            while(!arqjuri.eof())
            {
                getline(arqjuri,aux);
                aux= aux.substr(0,aux.find(";"));
                if(x==codigo)
                {
                    puts("Pessoa encontrada");
                    return true;
                }
                aux="";
            }
        }
        puts("Pessoa não encontrada");
        return false;
    }
    void mostrarjuri()
    {
        std::string aux;
        fstream arqjurid;
        arqjurid.open("Pessoas Juri.txt",ios::out|ios::in|ios::app);
        if(arqjurid.is_open())
        {
            while(!arqjurid.eof())
            {
                getline(arqjurid,aux);
                std::cout<<aux<<"\n";
            }
        }
    }
};

#endif // JURIDICA_H
