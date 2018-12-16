#ifndef _LIVRO_H_
#define _LIVRO_H_

#include "auxiliar.h"

class Livro
{
private:
    string m_titulo;
    string m_autor;
    int m_edicao;
    string m_editora;
    int m_ano;
    string m_isbn;
public:
    Livro();
    Livro(string titulo_, string autor_, int edicao_, string editora_, int ano_, string isbn_);
    ~Livro();
    /* Metodos Getrs */
    string getTitulo();
    string getAutor();
    int getEdicao();
    string getEditora();
    int getAno();
    string getIsbn();
    /* Metodos Setrs */
    void setTitulo(string val);
    void setAutor(string val);
    void setEdicao(int val);
    void setEditora(string val);
    void setAno(int val);
    void setIsbn(string val);
    friend ostream& operator << (ostream& os, Livro& liv);
    friend istream& operator >> (istream& is, Livro& liv);
};

#endif