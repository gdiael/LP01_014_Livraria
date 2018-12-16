#include "fichacatalogal.h"

FichaCatalogal::FichaCatalogal(Livro* livro_, int quantidade_):
    m_livro(livro_)
{
    if(quantidade_ > 0){
        this->m_quantidadeCopias = quantidade_;
    }
    else
    {
        this->m_quantidadeCopias = 1;
        cerr << "A quantidade minima de copias eh 1, o valor foi ajustado automaticamente!" << endl;
    }
    
}

FichaCatalogal::~FichaCatalogal()
{
    delete this->m_livro;
}

Livro* FichaCatalogal::getLivro()
{
    return this->m_livro;
}

int FichaCatalogal::getQuantidadeCopias()
{
    return this->m_quantidadeCopias;
}

vector<string> FichaCatalogal::getEmprestimos()
{
    return this->m_emprestimos;
}

void FichaCatalogal::setLivro(Livro* livro_)
{
    this->m_livro = livro_;
}

bool FichaCatalogal::setQuantidadeCopias(int quantidade_)
{
    if( quantidade_ > 0 ){
        this->m_quantidadeCopias = quantidade_;
        return true;
    };
    cerr << "O valor para a quantidade de copias precisar ser maior ou igual a 1." << endl;
    return false;
}

bool FichaCatalogal::emprestar(string usuario)
{
    if( this->tudoEmprestado() ){
        cerr << "Nao ha copias no catalogo, espere alguns dias!" << endl;
        return false;
    }
    this->m_emprestimos.push_back(stringToUpper(usuario));
    return true;
}

bool FichaCatalogal::devolver(string usuario)
{
    if( this->nadaEmprestado() ){
        cerr << "Nao eh possivel realizar devolucao, nao existe emprestimo aberto!" << endl;
        return false;
    };

    string upCaseUser = stringToUpper(usuario);

    for(auto it = this->m_emprestimos.begin(); it != this->m_emprestimos.end(); it++){
        if( *it == upCaseUser ){
            this->m_emprestimos.erase(it);
            return true;
        };
    };

    cerr << "Nao ha emprestimo no nome de " << usuario << "!" << endl;
    return false;
}

bool FichaCatalogal::tudoEmprestado()
{
    return ( this->m_quantidadeCopias == this->m_emprestimos.size() );
}

bool FichaCatalogal::nadaEmprestado(){
    return ( this->m_emprestimos.size() == 0 );
}