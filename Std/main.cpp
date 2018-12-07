#include <iostream>
#include "Pesfisica.h"
#include "Juridica.h"
#include "Pessoa.h"
#include "Pedido.h"
#include <list>
#include <queue>
#include <fstream>
//arq : CLIENTE , ITEM DE PEDIDO , PRODUTO , PEDIDO
// Release Final!;
int main()
{
    int escolha,choose;
    Pessoa pess;
    Pesfisica pfis;
    Juridica pjuri;
    std::string auxstr;
    int auxint;
    float auxfloat;
    fstream arqfis,arqjuri,arqprod,arqpedi,arquivolist;
    list<Produto> plist;
    Produto prod;
    list<Item*> listaItems;
    Item* itmbijeto=nullptr;
    Item itm;
    queue<Pedido*> filapedidos;
    Pedido *pedibijeto=nullptr;
    Pedido pedi;
    long telefone;


    string nomeArquivolist = "listaitems.txt", delimitador=";", linha;

    ifstream arquivoi(nomeArquivolist.c_str());
    if(arqfis.fail())
    {
        cout<<"--Arquivo Lista nao aberto--"<<endl;
    }
    else
    {
        getline(arquivoi, linha);
        while(!arquivoi.fail())
        {
            itmbijeto= itmbijeto->criaitem(linha);
            listaItems.push_back(itmbijeto);
            itmbijeto=nullptr;
            getline(arquivoi, linha);
        }
        arquivoi.close();
        cout<<"==Arquivo Lista lido com sucesso=="<<endl;
    }

    string nomeArquivofila = "filapedidos.txt", delimitadorpedidos=";", linhapedi;

    ifstream arquivopedids(nomeArquivofila.c_str());
    if(arqfis.fail())
    {
        cout<<"--Arquivo fila nao aberto--"<<endl;
    }
    else
    {
        getline(arquivopedids, linha);
        while(!arquivopedids.fail())
        {
            try
            {
                pedibijeto= pedibijeto->criapedi(linhapedi);
            }
            catch(invalid_argument)
            {
                filapedidos.push(pedibijeto);
                pedibijeto=nullptr;
                getline(arquivopedids,linhapedi);
            }

        }
        arquivoi.close();
        cout<<"==Arquivo Fila lido com sucesso=="<<endl;
    }



    do
    {
        choose=escolha=0;
        puts("1-Inserir ou remover cliente");
        puts("2-Inserir Produto");
        puts("3-Remover Produto");
        puts("4-Mostrar Produtos");
        puts("0-Sair");
        std::cin>>choose;

        switch (choose)
        {
            case 1:

                puts("1 - Criar uma Pessoa Fisica ");
                puts("2 - Criar uma Pessoa Juridica ");
                puts("3 - Excluir pessoa Fisica ");
                puts("4 - Excluir pessoa Juridica");
                puts("5 - Realizar Pedido ");
                puts("6 - Mostrar Pessoas Fisica");
                puts("7 - Mostrar Pessoas Juridica");
                puts("8 - Excluir Pedido");
                puts("9 - Mostrar Pedidos");
                puts("0 - Para sair");
                std::cin>>escolha;
                switch (escolha)
                {
                    case 1:

                        arqfis.open("Pesssoas Fis.txt",ios::out|ios::in|ios::app);
                        if(arqfis.is_open())
                        {


                            cin.ignore();
                            puts("Insira o codigo ");
                            std::getline(std::cin,auxstr);
                            pfis.setcodigo(auxstr);
                            pedi.setcliente(auxstr);

                            puts("Insira o logradouro");
                            std::getline(std::cin,auxstr);
                            pfis.setlogradouro(auxstr);

                            puts("Insira o setor ");
                            std::getline(std::cin,auxstr);
                            pfis.setsetor(auxstr);

                            puts("Insira o cidade");
                            std::getline(std::cin,auxstr);
                            pfis.setcidade(auxstr);

                            puts("Insira o estado");
                            std::getline(std::cin,auxstr);
                            pfis.setestado(auxstr);

                            puts("Insira o email");
                            std::getline(std::cin,auxstr);
                            pfis.setemail(auxstr);

                            puts("Insira o telefone ");
                            std::cin>>telefone;
                            pfis.settelefone(telefone);

                            puts("Insira o cpf");
                            std::cin.ignore();
                            std::getline(std::cin,auxstr);
                            pfis.validacpf(auxstr);

                            puts("Insira o nome");
                            std::getline(std::cin,auxstr);
                            pfis.setnome(auxstr);

                            puts("Insira o celular");
                            std::cin>>telefone;
                            pfis.setcelular(telefone);

                            arqfis<<pfis;
                            arqfis.close();
                        }
                        else
                        {
                            puts("Arquivo não aberto");
                        }
                        break;

                    case 2:


                        arqjuri.open("Pessoas Juri.txt",ios::out|ios::in|ios::app);
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
                            std::cin>>telefone;
                            pjuri.settelefone(telefone);

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


                    case 3:

                        puts("Digite o codigo da Pessoa Fisica que desejas excluir: ");
                        std::cin.ignore();
                        std::getline(std::cin,auxstr);
                        pfis.removepesfis(auxstr);

                        break;

                    case 4:

                        puts("Digite o codigo da Pessoa Juridica que desejas excluir: ");
                        std::cin.ignore();
                        std::getline(std::cin,auxstr);
                        pjuri.removepesjuri(auxstr);


                        break;

                    case 5:

                        arqpedi.open("filapedidos.txt",ios::out|ios::in|ios::app);
                        arquivolist.open("listaitems.txt",ios::out|ios::in|ios::app);
                        if(arqpedi.is_open())
                        {
                            if(arquivolist.is_open())
                            {
                                puts("Insira o codigo da PessoaFisica ou a Razão social, para a qual desejas realizar o pedido");
                                std::cin.ignore();
                                std::getline(std::cin,auxstr);
                                if(pfis.existefis(auxstr)||pjuri.existejuri(auxstr))
                                {
                                    pedi.setcliente(auxstr);
                                }

                                puts("Insira o numero do pedido");
                                std::cin>>auxint;
                                pedi.setnumero(auxint);

                                puts("Insira o status do pedido");
                                std::cin.ignore();
                                std::getline(std::cin,auxstr);
                                pedi.setstatus(auxstr);

                                pedi.setdata();

                                if(arquivolist.is_open())
                                {

                                    auxstr="";
                                    puts("Insira o nome do Produto desejado ");
                                    std::getline(std::cin,auxstr);
                                    itm.buscaprod(auxstr);

                                    puts("Insira a quantidade de Itens");
                                    std::cin>>auxint;
                                    itm.setquanti(auxint);


                                    itm.setpcounitario(itm.rtpreco(auxstr));
                                    itm.setvalortotal();
                                    pedi.setvalortotal(itm.getvalortotal());

                                    pedi.setitem(&itm);
                                    filapedidos.push(&pedi);
                                    listaItems.push_back(&itm);

                                    arquivolist<<itm;
                                    arqpedi<<pedi;

                                }
                            }
                        }

                        break;

                    case 6:

                        pfis.mostrarfis();

                        break;

                    case 7:

                        pjuri.mostrarjuri();

                        break;

                    case 8:

                        puts("Insira o numero do pedido que desejas excluir");
                        cin.ignore();
                        cin>>auxint;
                        try
                        {
                            pedi.removepedido(auxint);
                        }
                        catch(invalid_argument)
                        {}

                        break;

                    case 9:

                        pedi.mostrapedidos();

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

                    plist.push_back(prod);
                    arqprod<<prod;
                    arqprod.close();

                }
                else
                {
                    puts("Arquivo não aberto");
                }
                break;

            case 3:

                puts("Insira a descrição do produto");
                std::cin.ignore();
                std::getline(std::cin,auxstr);
                prod.removeproduto(auxstr);

                break;

            case 4:

                prod.mostrarprods();
            default:

                break;
        }

    }while(escolha!=0||choose!=0);

}
