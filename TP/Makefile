CXX = g++
LIBS = 
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/pokerSim.o $(OBJ)/jogador.o $(OBJ)/mesaDePoker.o $(OBJ)/memlog.o
HDRS = $(INC)/msgassert.hpp $(INC)/cartaDeBaralho.hpp $(INC)/jogador.hpp $(INC)/mesaDePoker.hpp $(INC)/memlog.hpp
SANITIZE = -fsanitize=undefined,address
CXXFLAGS = -Wall -c -I$(INC) -g $(SANITIZE)
LDFLAGS = $(SANITIZE)
ANALISAMEM = ../analisamem/bin/analisamem

EXE = $(BIN)/pokerSim.exe

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/pokerSim.o: $(HDRS) $(SRC)/pokerSim.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/pokerSim.o $(SRC)/pokerSim.cpp 

$(OBJ)/jogador.o: $(HDRS) $(SRC)/jogador.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/jogador.o $(SRC)/jogador.cpp

$(OBJ)/mesaDePoker.o: $(HDRS) $(SRC)/mesaDePoker.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/mesaDePoker.o $(SRC)/mesaDePoker.cpp

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.cpp

perf: $(EXE)
	$(EXE) -l ../temp/pokerSimLog.out
	$(ANALISAMEM) -i ../temp/pokerSimLog.out -p ../temp/pokerSimLogData
	gnuplot ../temp/*.gp

clean: 
	rm -f $(EXE) $(OBJS) gmon.out