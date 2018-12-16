#ifndef _BIBLIOTECA_H_
#define _BIBLIOTECA_H_

#include "fichacatalogal.h"
#include <list>
using std::list;

class Biblioteca
{
private:
    list<FichaCatalogal*> m_catalogo;
public:
    Biblioteca();
    ~Biblioteca();

    list<FichaCatalogal*> getCatalago();

    bool addLivro(Livro* livro_);
    bool delLivro(string titulo_);
    
    FichaCatalogal* getLivroByTitulo(string titulo_);
    FichaCatalogal* getLivroByIsbn(string isbn_);
    bool temLivro(string tituloOuIsbn_);

    void operar();
};

#endif