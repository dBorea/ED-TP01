CXX = g++
LIBS = 
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/listaEncadeada.o 
HDRS = $(INC)/listaEncadeada.hpp $(INC)/msgassert.hpp $(INC)/cartaDeBaralho.hpp
SANITIZE = #-fsanitize=undefined,address
CXXFLAGS = -Wall -c -I$(INC) -g $(SANITIZE)
LDFLAGS = $(SANITIZE)
MAIN = $(BIN)/main.exe

EXE = $(BIN)/main.exe

$(MAIN): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(MAIN) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/listaEncadeada.o: $(HDRS) $(SRC)/listaEncadeada.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/listaEncadeada.o $(SRC)/listaEncadeada.cpp

clean: 
	rm -f $(EXE) $(OBJS) gmon.out