#include "Item.h"

Item::Item()
{
    quantidade=0;
    pcounitario=valortotal=0;
}
bool Item::buscaprod(std::string aux)
{
    std::string linha,delimitador=";",atributo;
    ifstream busca("Produtos.txt");
    if(!busca.is_open())
    {
        puts("Nada encontrado no arquivo\n");
        return false;
    }
    else
    {
        while(!busca.fail())
        {
            getline(busca,linha);
            atributo = linha.substr(0, linha.find(delimitador));
            if(atributo==aux)
            {
                puts("Produto encontrado com sucesso!\n");
                objproduto = atributo;
                atributo.erase();
                return true;
            }
            else
            {
                atributo.erase();
            }
        }
        puts("Produto nao encontrado\n");
        return false;

    }
}
