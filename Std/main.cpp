#include <iostream>
#include "Pesfisica.h"
#include "Juridica.h"
#include "Pessoa.h"
#include "Pedido.h"
#include <list>
#include <queue>
#include <fstream>
//arq : CLIENTE , ITEM DE PEDIDO , PRODUTO , PEDIDO

int main()
{
    int escolha=0,choose=0;
    Pesfisica pfis;
    Pessoa pess;
    Juridica pjuri;
    Item itm;
    Produto prod;
    Pedido pedi;
    std::string auxstr;
    int auxint;
    float auxfloat;
    fstream arqfis,arqjuri,arqprod,arqpedi;
    do
    {
        puts("1-Inserir cliente");
        puts("2-Inserir produto");
        puts("0-Sair");
        std::cin>>choose;

        switch (choose)
        {
            case 1:

                puts("1 - Fazer pedido para uma Pessoa Fisica ");
                puts("2 - Fazer pedido para uma Pessoa Juridica \n0 - Para sair");
                std::cin>>escolha;
                switch (escolha)
                {
                    case 1:

                        arqfis.open("Pedidos Fis.txt",ios::out|ios::in|ios::app);
                        if(arqfis.is_open())
                        {
                            cin.ignore();
                            puts("Insira o codigo ");
                            std::getline(std::cin,auxstr);
                            pess.setcodigo(auxstr);

                            puts("Insira o logradouro");
                            std::getline(std::cin,auxstr);
                            pess.setlogradouro(auxstr);

                            puts("Insira o setor ");
                            std::getline(std::cin,auxstr);
                            pess.setsetor(auxstr);

                            puts("Insira o cidade");
                            std::getline(std::cin,auxstr);
                            pess.setcidade(auxstr);

                            puts("Insira o estado");
                            std::getline(std::cin,auxstr);
                            pess.setestado(auxstr);

                            puts("Insira o email");
                            std::getline(std::cin,auxstr);
                            pess.setemail(auxstr);

                            puts("Insira o telefone ");
                            std::cin>>auxint;
                            pess.settelefone(auxint);

                            puts("Insira o cpf");
                            std::cin.ignore();
                            std::getline(std::cin,auxstr);
                            pfis.validacpf(auxstr);

                            puts("Insira o nome");
                            std::getline(std::cin,auxstr);
                            pfis.setnome(auxstr);

                            puts("Insira o celular");
                            std::cin>>auxint;
                            pfis.setcelular(auxint);

                            puts("Insira o numero do pedido");
                            std::cin>>auxint;
                            pedi.setnumero(auxint);

                            puts("Insira o status do produto");
                            std::cin.ignore();
                            std::getline(std::cin,auxstr);
                            pedi.setstatus(auxstr);

                            //pedi.setdata();
                            pedi.setvalortotal();
                            //pedi.setcliente()

                            puts("Insira a quantidade de Itens");
                            std::cin.ignore();
                            std::cin>>auxint;
                            itm.setquanti(auxint);

                            puts("Insira o preço unitario do item");
                            std::cin.ignore();
                            std::cin>>auxfloat;
                            itm.setpcounitario(auxfloat);

                            pedi.setitem(&itm);

                            arqfis<<pfis;
                            arqfis<<pedi;
                            arqfis.close();
                        }
                        else
                        {
                            puts("Arquivo não aberto");
                        }
                        break;

                    case 2:


                        arqjuri.open("Pedidos Juri.txt",ios::out|ios::in|ios::app);
                        if(arqjuri.is_open())
                        {
                            cin.ignore();
                            puts("Insira o codigo ");
                            std::getline(std::cin,auxstr);
                            pjuri.setcodigo(auxstr);

                            puts("Insira o logradouro");
                            std::getline(std::cin,auxstr);
                            pjuri.setlogradouro(auxstr);

                            puts("Insira o setor ");
                            std::getline(std::cin,auxstr);
                            pjuri.setsetor(auxstr);

                            puts("Insira o cidade");
                            std::getline(std::cin,auxstr);
                            pjuri.setcidade(auxstr);

                            puts("Insira o estado");
                            std::getline(std::cin,auxstr);
                            pjuri.setestado(auxstr);

                            puts("Insira o email");
                            std::getline(std::cin,auxstr);
                            pjuri.setemail(auxstr);

                            puts("Insira o telefone ");

                            std::cin>>auxint;
                            pjuri.settelefone(auxint);

                            puts("Insira o cnpj");
                            std::cin.ignore();
                            std::getline(std::cin,auxstr);
                            pjuri.setCnpj(auxstr);

                            puts("Insira o nome do contato");
                            std::getline(std::cin,auxstr);
                            pjuri.setNomeContato(auxstr);

                            puts("Insira a razão social");
                            std::getline(std::cin,auxstr);
                            pjuri.setRazaoSocial(auxstr);

                            arqjuri<<pjuri;
                            arqjuri.close();
                        }
                        else
                        {
                            puts("Arquivo não aberto");
                        }

                        break;

                    default:

                        break;
                }
                break;

            case 2:

                arqprod.open("Produtos.txt",ios::out|ios::in|ios::app);
                if(arqprod.is_open())
                {
                    puts("Digite o codigo do produto");
                    std::cin>>auxint;
                    prod.setCodigo(auxint);

                    puts("Digite a descrição do produto");
                    std::cin.ignore();
                    std::getline(std::cin,auxstr);
                    prod.setDescricao(auxstr);

                    puts("Digite o preço do produto");
                    std::cin>>auxfloat;
                    prod.setPreco(auxfloat);

                    puts("Digite a quantidade de produtos");
                    std::cin>>auxint;
                    prod.setQuantidade(auxint);

                    arqprod<<prod;
                    arqprod.close();

                }
                else
                {
                    puts("Arquivo não aberto");
                }
                break;


        }

    }while(escolha!=0||choose!=0);

}
