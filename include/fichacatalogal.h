#ifndef _FICHA_CATALOGAL_H_
#define _FICHA_CATALOGAL_H_

#include "livro.h"

class FichaCatalogal
{
private:
    /* livro a qual esse catalogo se refere */
    Livro* m_livro;
    /* número de cópias total no estoque */
    unsigned int m_quantidadeCopias;
    /* vector com o nome dos usuarios aos quais as copias estao esprestadas atualmente */
    vector<string> m_emprestimos;
public:
    FichaCatalogal(Livro* livro_, int quantidade_ = 1);
    ~FichaCatalogal();
    Livro* getLivro();
    int getQuantidadeCopias();
    vector<string> getEmprestimos();
    void setLivro(Livro* livro_);
    bool setQuantidadeCopias(int quantidade_);
    bool emprestar(string usuario);
    bool devolver(string usuario);
    bool tudoEmprestado();
    bool nadaEmprestado();
};

#endif