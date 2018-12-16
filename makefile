# Arquivo de Script MakeFile
# Questões 5 e 6 da Lista de Exercícios 02
# https://github.com/gdiael/LP01_014_Livraria.git
# - Legenda
# $@ = nome da regra de compilação
# $^ = lista de depedências da regra
# $< = primeira dependência da regra

# Comando de compilação do gcc [c++]
CC = g++ -g

# Diretórios do Programa
SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./build

# Arquivo executável [programa principal]
PROG = $(BIN)/biblioteca

# Regras de compilação
FLAGS = -Wall -pedantic -std=c++11 -I$(INC)

PROG_OBJS = $(OBJ)/auxiliar.o $(OBJ)/livro.o $(OBJ)/fichacatalogal.o $(OBJ)/biblioteca.o $(OBJ)/main.o

all: mkdirs $(PROG)

mkdirs:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

$(PROG): $(PROG_OBJS)
	$(CC) $(FLAGS) -o $@ $^

$(OBJ)/auxiliar.o: $(SRC)/auxiliar.cpp $(INC)/auxiliar.h
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ)/livro.o: $(SRC)/livro.cpp $(INC)/livro.h $(INC)/auxiliar.h
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ)/fichacatalogal.o: $(SRC)/fichacatalogal.cpp $(INC)/fichacatalogal.h $(INC)/livro.h
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ)/biblioteca.o: $(SRC)/biblioteca.cpp $(INC)/biblioteca.h $(INC)/fichacatalogal.h
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/biblioteca.h
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(BIN)/*
	rm -f $(OBJ)/*

run:
	$(PROG)

# propriedades para serem usadas ao compilar no windows com o MinGW com gcc e gdb
# não usar o comando Make e sim o executável: mingw32-make.exe

mkdirswin:
	if not exist $(BIN) mkdir "$(BIN)
	if not exist $(OBJ) mkdir "$(OBJ)

mkwin: mkdirswin $(PROG) 

runwin: mkwin
	chcp 65001
	$(PROG)

cleanwin: 
	del /q "$(BIN)\*
	del /q "$(OBJ)\*