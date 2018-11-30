#ifndef CPF_H
#define CPF_H
#include <string>
#include <iostream>
#include <ostream>
#include <QString>
#include "Pessoa.h"

using namespace std;

class Pesfisica : public Pessoa
{
private:
    string cdpessoafis;
    string nome;
    int celular;

public:
    Pesfisica();
    friend ostream& operator << (ostream& saida,Pesfisica& Pessoa)
    {
       saida << "Dados: Codigo :"
            << Pessoa.codigo <<", Nome :"
            << Pessoa.nome       <<", Cpf :"
            << Pessoa.cdpessoafis<<", Celular :"
            << Pessoa.celular    <<", Logradouro :"
            << Pessoa.logradouro <<", Setor :"
            << Pessoa.setor      <<", Cidade :"
            << Pessoa.cidade     <<", Estado :"
            << Pessoa.estado     <<", Telefone :"
            << Pessoa.telefone   <<", email :"
            << Pessoa.email      <<endl;

        return saida;
    }
    bool validacpf(string);
    void setnome(string x){nome=x;}
    string getnome(){return nome;}
    void setcelular(int num){celular=num;}
    int getcelular(){return celular;}

};
#endif // CPF_H
