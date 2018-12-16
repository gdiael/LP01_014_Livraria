#include "auxiliar.h"

string stringToUpper(string str){
    string s = str;
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });
    return s;
}

vector<string> splitString(string& linha, char delimitador){
	vector<string> colunas;
	string buffer = "";
	for(unsigned i = 0; i < linha.size(); i++){
		char c = linha[i];
		if(c == delimitador){
			colunas.push_back(buffer);
			buffer = "";
		}else{
			string letra(1, c);
			buffer += letra;
		};
	};
	if(buffer != "") colunas.push_back(buffer);
	return colunas;
}

bool isNumeric(string str)
{
	set<char> base = {'-', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ',', '.'};
	for( auto it = str.begin(); it != str.end(); it++ )
	{
		if( base.count(*it) != 1){
			return false;
		}
	}
	return true;
}

string askForString(istream& is, string msg, bool acceptNull)
{
	bool executando = true;
	string msgError = "\nEntrada invalida!\n";
	string result;

	while(executando){

		cout << msg << ": ";
		std::getline(is, result);

		if( result == "" ){
			if( acceptNull ){
				executando = false;
			}else{
				cout << msgError;
			}
		}else{
			executando = false;
		}
	}

    return result;
}

int askForInteger(istream& is, string msg, bool acceptNegative, bool acceptZero)
{
	bool executando = true;
	string msgError = "\nEntrada invalida!\n";
	int result = -1;

	while(executando){

		cout << msg << ": ";
		string buffer;
		std::getline(is, buffer);
		if( buffer == "" ){
			cout << msgError;
		}else{
			if(isNumeric(buffer)){
				result = stoi(buffer);
				if( result == 0 && !acceptZero ){
					cerr << msgError;
				}else if( result < 0 && !acceptNegative ){
					cerr << msgError;
				}else{
					executando = false;
				};
			}else{
				cerr << msgError;
			};
		}
	}

    return result;
}

double askForDouble(istream& is, string msg, bool acceptNegative, bool acceptZero)
{
	bool executando = true;
	string msgError = "\nEntrada invalida!\n";
	double result = -1.0;

	while(executando){

		cout << msg << ": ";
		string buffer;
		std::getline(is, buffer);
		if( buffer == "" ){
			cout << msgError;
		}else{
			if(isNumeric(buffer)){
				result = stod(buffer);
				if( result == 0 && !acceptZero ){
					cerr << msgError;
				}else if( result < 0 && !acceptNegative ){
					cerr << msgError;
				}else{
					executando = false;
				};
			}else{
				cerr << msgError;
			};
		}
	}

    return result;
}