#ifndef JURIDICA_H
#define JURIDICA_H
#include "Pessoa.h"
#include <iostream>
#include <sstream>
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
        os  << "Dados: Codigo :"
            << Pessoa.codigo    <<", Cnpj :"
            << Pessoa.cnpj         <<", Razão social :"
            << Pessoa.razaoSocial    <<", Nomecontato :"
            << Pessoa.nomeContato    <<", Logradouro :"
            << Pessoa.logradouro     <<", Setor :"
            << Pessoa.setor          <<", Cidade :"
            << Pessoa.cidade         <<", Estado :"
            << Pessoa.estado         <<", Telefone :"
            << Pessoa.telefone       <<", Email :"
            << Pessoa.email          <<::endl;
        return os;
    }

    bool setCnpj(string x);
    void setRazaoSocial(string razaoSocial){this->razaoSocial=razaoSocial;}
    void setNomeContato(string nomeContato){this->nomeContato=nomeContato;}

    string getCnpj(){return cnpj;}
    string getRazaoSocial(){return razaoSocial;}
    string getNomeContato(){return nomeContato;}

};

#endif // JURIDICA_H
