CXX = g++
LIBS = 
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/jogador.o $(OBJ)/mesaDePoker.o
HDRS = $(INC)/msgassert.hpp $(INC)/cartaDeBaralho.hpp $(INC)/jogador.hpp $(INC)/mesaDePoker.hpp
SANITIZE = -fsanitize=undefined,address
CXXFLAGS = -Wall -c -I$(INC) -g $(SANITIZE)
LDFLAGS = $(SANITIZE)
MAIN = $(BIN)/main.exe

EXE = $(BIN)/main.exe

$(MAIN): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(MAIN) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/jogador.o: $(HDRS) $(SRC)/jogador.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/jogador.o $(SRC)/jogador.cpp

$(OBJ)/mesaDePoker.o: $(HDRS) $(SRC)/mesaDePoker.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/mesaDePoker.o $(SRC)/mesaDePoker.cpp

clean: 
	rm -f $(EXE) $(OBJS) gmon.out