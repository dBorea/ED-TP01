CXX = g++
LIBS = 
SRC = src
OBJ = obj
INC = include
BIN = bin
TEMP = ../temp
REGMEM = $(TEMP)/regmem
REGPERF = $(TEMP)/regperf
EXECFILES = $(TEMP)/execfiles
OBJS = $(OBJ)/pokerSim.o $(OBJ)/jogador.o $(OBJ)/mesaDePoker.o $(OBJ)/memlog.o
HDRS = $(INC)/msgassert.hpp $(INC)/cartaDeBaralho.hpp $(INC)/jogador.hpp $(INC)/mesaDePoker.hpp $(INC)/memlog.hpp
SANITIZE = -fsanitize=undefined,address -static-libasan
CXXFLAGS = -Wall -c -I$(INC) -g $(SANITIZE)
LDFLAGS = $(SANITIZE)
ANALISAMEM = ../analisamem/bin/analisamem
GENLOAD = ../geracargapoquer/bin/geracarga

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

mem: $(EXE)
	rm -f $(REGMEM)/pokerSimLog.out 
	$(EXE) -p $(REGMEM)/pokerSimLog.out -l -i $(EXECFILES)/entrada.txt -o $(EXECFILES)/saida.txt
	$(ANALISAMEM) -i $(REGMEM)/pokerSimLog.out -p $(REGMEM)/pokerSimLogData
	gnuplot $(REGMEM)/*.gp

genload: $(GENLOAD)
	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas.txt -r 1000 -j 4 -v 1
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas.txt -r 2000 -j 4 -v 1
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas.txt -r 3000 -j 4 -v 1
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas.txt -r 4000 -j 4 -v 1
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas.txt -r 5000 -j 4 -v 1
	$(GENLOAD) -o $(EXECFILES)/entrada10jogadores.txt -r 5000 -j 5 -v 5
	$(GENLOAD) -o $(EXECFILES)/entrada20jogadores.txt -r 5000 -j 15 -v 5
	$(GENLOAD) -o $(EXECFILES)/entrada30jogadores.txt -r 5000 -j 25 -v 5
	$(GENLOAD) -o $(EXECFILES)/entrada40jogadores.txt -r 5000 -j 35 -v 5
	$(GENLOAD) -o $(EXECFILES)/entrada50jogadores.txt -r 5000 -j 45 -v 5

perf: $(EXE)
	$(EXE) -p $(REGPERF)/1000rodadas.out -i $(EXECFILES)/entrada1000rodadas.txt -o $(EXECFILES)/saida1000rodadas.txt
	$(EXE) -p $(REGPERF)/2000rodadas.out -i $(EXECFILES)/entrada2000rodadas.txt -o $(EXECFILES)/saida2000rodadas.txt
	$(EXE) -p $(REGPERF)/3000rodadas.out -i $(EXECFILES)/entrada3000rodadas.txt -o $(EXECFILES)/saida3000rodadas.txt
	$(EXE) -p $(REGPERF)/4000rodadas.out -i $(EXECFILES)/entrada4000rodadas.txt -o $(EXECFILES)/saida4000rodadas.txt
	$(EXE) -p $(REGPERF)/5000rodadas.out -i $(EXECFILES)/entrada5000rodadas.txt -o $(EXECFILES)/saida5000rodadas.txt

	$(EXE) -p $(REGPERF)/10jogadores.out -i $(EXECFILES)/entrada10jogadores.txt -o $(EXECFILES)/saida10jogadores.txt
	$(EXE) -p $(REGPERF)/20jogadores.out -i $(EXECFILES)/entrada20jogadores.txt -o $(EXECFILES)/saida20jogadores.txt
	$(EXE) -p $(REGPERF)/30jogadores.out -i $(EXECFILES)/entrada30jogadores.txt -o $(EXECFILES)/saida30jogadores.txt
	$(EXE) -p $(REGPERF)/40jogadores.out -i $(EXECFILES)/entrada40jogadores.txt -o $(EXECFILES)/saida40jogadores.txt
	$(EXE) -p $(REGPERF)/50jogadores.out -i $(EXECFILES)/entrada50jogadores.txt -o $(EXECFILES)/saida50jogadores.txt

cleantemp: cleanperf cleanmem clean

cleanperf:
	rm -f $(REGPERF)/*.gp $(REGPERF)/*.gpdat $(REGPERF)/*.png $(REGPERF)/*.out

cleanmem:
	rm -f $(REGMEM)/*.gp $(REGMEM)/*.gpdat $(REGMEM)/*.png $(REGMEM)/*.out

clean: 
	rm -f $(EXE) $(OBJS) gmon.out