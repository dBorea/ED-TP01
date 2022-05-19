

CXX = g++
LIBS = 
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/listaEncadeada.o 
HDRS = $(INC)/listaEncadeada.hpp $(INC)/msgassert.hpp $(INC)/cartaDeBaralho.hpp
CFLAGS = -Wall -c -I$(INC) -g
MAIN = $(BIN)/main.exe

#EXE = $(BIN)/

$(MAIN): $(OBJS)
	$(CXX) -o $(MAIN) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CXX) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/listaEncadeada.o: $(HDRS) $(SRC)/listaEncadeada.cpp
	$(CXX) $(CFLAGS) -o $(OBJ)/listaEncadeada.o $(SRC)/listaEncadeada.cpp