#include "livro.h"

Livro::Livro():
    m_titulo(""), m_autor(""), m_edicao(-1), m_editora(""), m_ano(-1), m_isbn("")
{
    /* nada a executar */
}

Livro::Livro(string titulo_, string autor_, int edicao_, string editora_, int ano_, string isbn_):
    m_titulo(titulo_), m_autor(autor_), m_edicao(edicao_), m_editora(editora_), m_ano(ano_), m_isbn(isbn_)
{
    /* nada a executar */
}

Livro::~Livro()
{
    /* nada a executar */
}

string Livro::getTitulo(){
    return this->m_titulo;
}

string Livro::getAutor(){
    return this->m_autor;
}

int Livro::getEdicao(){
    return this->m_edicao;
}

string Livro::getEditora(){
    return this->m_editora;
}

int Livro::getAno(){
    return this->m_ano;
}

string Livro::getIsbn(){
    return this->m_isbn;
}
    
void Livro::setTitulo(string val){
    this->m_titulo = val;
}

void Livro::setAutor(string val){
    this->m_autor = val;
}

void Livro::setEdicao(int val){
    this->m_edicao = val;
}

void Livro::setEditora(string val){
    this->m_editora = val;
}

void Livro::setAno(int val){
    this->m_ano = val;
}

void Livro::setIsbn(string val){
    this->m_isbn = val;
}

ostream& operator << (ostream& os, Livro& liv){
    os << "Titulo: " << liv.m_titulo << ";" << endl;
    os << "Autor: " << liv.m_autor << ";" << endl;
    os << "Editora " << liv.m_editora << ", " << liv.m_edicao << "a edicao, ano de " << liv.m_ano << ";" << endl;
    os << "ISBN: " << liv.m_isbn << "." << endl;
    return os;
}

istream& operator >> (istream& is, Livro& liv){
    liv.m_titulo = askForString(is, "Titulo do livro");
    liv.m_autor = askForString(is, "Autor de [" + liv.m_titulo + "]");
    liv.m_edicao = askForInteger(is, "Numero da edicao");
    liv.m_editora = askForString(is, "Nome da Editora");
    liv.m_ano = askForInteger(is, "Ano de lancamento");
    liv.m_isbn = stringToUpper(askForString(is, "Codigo Isbn"));
    return is;
}