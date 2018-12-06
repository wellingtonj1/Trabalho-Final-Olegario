#ifndef CPF_H
#define CPF_H
#include <string>
#include <iostream>
#include <fstream>
#include <QString>
#include "Pessoa.h"

using namespace std;

class Pesfisica : public Pessoa
{
private:
    string cdpessoafis;
    string nome;
    long celular;

public:
    Pesfisica();
    friend ostream& operator << (ostream& saida,Pesfisica& Pessoa)
    {
       saida <<Pessoa.codigo <<";"
            << Pessoa.nome       <<";"
            << Pessoa.cdpessoafis<<";"
            << Pessoa.celular    <<";"
            << Pessoa.logradouro <<";"
            << Pessoa.setor      <<";"
            << Pessoa.cidade     <<";"
            << Pessoa.estado     <<";"
            << Pessoa.telefone   <<";:"
            << Pessoa.email      <<endl;

        return saida;
    }
    bool validacpf(string);
    void setnome(string x){nome=x;}
    string getnome(){return nome;}
    void setcelular(long num){celular=num;}
    long getcelular(){return celular;}
    void removepesfis(std::string x)
    {
        std::string aux,codigo;
        fstream arqfisica,arqaux;
        arqfisica.open("Pesssoas Fis.txt",ios::out|ios::in|ios::app);
        arqaux.open("Pesssoas aux.txt",ios::out|ios::in|ios::app);
        if(arqfisica.is_open())
        {
            while(!arqfisica.eof())
            {
                getline(arqfisica,aux);
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
            remove("Pessoas Fis.txt");
            rename("Pessoas aux","Pesssoas Fis.txt");
        }
    }
    bool existefis(std::string x)
    {
        std::string aux;
        fstream arqfisica;
        arqfisica.open("Pesssoas Fis.txt",ios::out|ios::in|ios::app);
        if(arqfisica.is_open())
        {
            while(!arqfisica.eof())
            {
                getline(arqfisica,aux);
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
    void mostrarfis()
    {
        std::string aux;
        fstream arqfisica;
        arqfisica.open("Pesssoas Fis.txt",ios::out|ios::in|ios::app);
        if(arqfisica.is_open())
        {
            while(!arqfisica.eof())
            {
                getline(arqfisica,aux);
                std::cout<<aux<<"\n";
            }
        }
    }

};
#endif // CPF_H
