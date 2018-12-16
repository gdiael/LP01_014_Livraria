#include "biblioteca.h"

Biblioteca::Biblioteca()
{
}

Biblioteca::~Biblioteca()
{
}

list<FichaCatalogal*> Biblioteca::getCatalago()
{
    return this->m_catalogo;
}

bool Biblioteca::addLivro(Livro* livro_)
{
    if( livro_ == nullptr ){
        return false;
    };
    FichaCatalogal* ficha = this->getLivroByTitulo(livro_->getTitulo());
    if( ficha == nullptr )
    {
        ficha = new FichaCatalogal(livro_);
        this->m_catalogo.push_back(ficha);
        cout << endl << "Novo livro cadastrado na biblioteca!" << endl << endl;
        cout << *livro_ << endl;
    }
    else
    {
        ficha->setQuantidadeCopias(ficha->getQuantidadeCopias() + 1);
        cout << endl << "Nova copia cadastrada na biblioteca!" << endl;
        cout << "O livro " << livro_->getTitulo() << " agora tem "
             << ficha->getQuantidadeCopias() << " copias disponiveis!" << endl << endl;
    };
    return true;
}

bool Biblioteca::delLivro(string titulo_)
{
    string upCaseTitulo = stringToUpper(titulo_);
    for(auto it = this->m_catalogo.begin(); it != this->m_catalogo.end(); it++)
    {
        FichaCatalogal* ficha_ = *it;
        string otherTitulo = stringToUpper(ficha_->getLivro()->getTitulo());
        if( otherTitulo == upCaseTitulo )
        {
            this->m_catalogo.erase(it);
            return true;
        };
    };
    return false;
}
    
FichaCatalogal* Biblioteca::getLivroByTitulo(string titulo_)
{
    string upCaseTitulo = stringToUpper(titulo_);
    for(auto it = this->m_catalogo.begin(); it != this->m_catalogo.end(); it++){
        FichaCatalogal* ficha_ = *it;
        string otherTitulo = stringToUpper(ficha_->getLivro()->getTitulo());
        if( otherTitulo == upCaseTitulo ){
            return ficha_;
        }
    }
    return nullptr;
}

FichaCatalogal* Biblioteca::getLivroByIsbn(string isbn_)
{
    string upCaseIsbn = stringToUpper(isbn_);
    for(auto it = this->m_catalogo.begin(); it != this->m_catalogo.end(); it++){
        FichaCatalogal* ficha_ = *it;
        string otherIsbn = stringToUpper(ficha_->getLivro()->getIsbn());
        if( otherIsbn == upCaseIsbn ){
            return ficha_;
        }
    }
    return nullptr;
}

bool Biblioteca::temLivro(string tituloOuIsbn_)
{
    FichaCatalogal* ficha_ = this->getLivroByTitulo(tituloOuIsbn_);
    if( ficha_ != nullptr){
        return true;
    }
    ficha_ = this->getLivroByIsbn(tituloOuIsbn_);
    if( ficha_ != nullptr){
        return true;
    }
    return false;
}

void Biblioteca::operar()
{
    // Livro* liv = new Livro("Sapiens: Uma breve historia da humanidade", "Yuval Harari", 2, "Atica", 2018, "1234566787BGN234");
    // FichaCatalogal ficha(liv, 2);
    // cout << *(ficha.getLivro()) << endl;

    bool executando = true;
	string opt;

	cout << endl <<
	" SISTEMA DE BIBLIOTECARIOS " << endl <<
	"---------------------------" << endl;

	while(executando) {

		cout <<
        "MENU INICIAL:" << endl << 
		"[1] Cadastrar Novo Livro" << endl <<
		"[2] Remover Livro do Cadastro" << endl <<
        "[3] Emprestar Livro" << endl <<
        "[4] Realizar Devolução" << endl <<
		"[5] Listar Livro por Título" << endl <<
		"[6] Listar Livro por ISBN" << endl <<
		"[7] Verificar se Existe Título ou ISBN na Biblioteca" << endl <<
        "[8] Verificar a quantidade de um Título disponível para empréstimo" << endl <<
		"[9] Sair" << endl;

		cout << "Selecione uma opção: ";
		std::getline(cin, opt);

		switch(opt[0]) {

			case '1':
                {
                    Livro* novolivro = new Livro();
                    cin >> *novolivro;
                    this->addLivro(novolivro);
                    break;
                }
			case '2':
				{

					cout << "Realisar a remoção de umnovo livro" << endl;
					break;
				}

			case '3':
				{
					cout << "Realizar o emprestimo do livro" << endl;
					break;
				}

			case '4':
				{
					cout << "Realisar devolução de um livro" << endl;
					break;
				}

			case '5':
				{
					cout << "Listar livro por Título" << endl;
					break;
				}
				
			case '6':
				{
					cout << "Listar livro por ISBN" << endl;
					break;
				}
			case '7':
				{
					cout << "Listar livro por ISBN" << endl;
					break;
				}

			case '8':
				{
					cout << "Listar livro por ISBN" << endl;
					break;
				}

			case '9':
				{
					/* Sair */
                    executando = false;
					break;
				}


			default:
				cout<< "Opção invalida." << endl << endl;
		}
	}
}