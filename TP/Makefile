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
	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas10jg.txt -r 1000 -j 10 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas10jg.txt -r 2000 -j 10 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas10jg.txt -r 3000 -j 10 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas10jg.txt -r 4000 -j 10 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas10jg.txt -r 5000 -j 10 -v 0

	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas20jg.txt -r 1000 -j 20 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas20jg.txt -r 2000 -j 20 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas20jg.txt -r 3000 -j 20 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas20jg.txt -r 4000 -j 20 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas20jg.txt -r 5000 -j 20 -v 0

	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas30jg.txt -r 1000 -j 30 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas30jg.txt -r 2000 -j 30 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas30jg.txt -r 3000 -j 30 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas30jg.txt -r 4000 -j 30 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas30jg.txt -r 5000 -j 30 -v 0

	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas40jg.txt -r 1000 -j 40 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas40jg.txt -r 2000 -j 40 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas40jg.txt -r 3000 -j 40 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas40jg.txt -r 4000 -j 40 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas40jg.txt -r 5000 -j 40 -v 0

	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas50jg.txt -r 1000 -j 50 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas50jg.txt -r 2000 -j 50 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas50jg.txt -r 3000 -j 50 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas50jg.txt -r 4000 -j 50 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas50jg.txt -r 5000 -j 50 -v 0

perf: $(EXE)
	$(EXE) -p $(REGPERF)/1000rodadas10jg.out -i $(EXECFILES)/entrada1000rodadas10jg.txt -o $(EXECFILES)/saida1000rodadas10jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas10jg.out -i $(EXECFILES)/entrada2000rodadas10jg.txt -o $(EXECFILES)/saida2000rodadas10jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas10jg.out -i $(EXECFILES)/entrada3000rodadas10jg.txt -o $(EXECFILES)/saida3000rodadas10jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas10jg.out -i $(EXECFILES)/entrada4000rodadas10jg.txt -o $(EXECFILES)/saida4000rodadas10jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas10jg.out -i $(EXECFILES)/entrada5000rodadas10jg.txt -o $(EXECFILES)/saida5000rodadas10jg.txt

	$(EXE) -p $(REGPERF)/1000rodadas20jg.out -i $(EXECFILES)/entrada1000rodadas20jg.txt -o $(EXECFILES)/saida1000rodadas20jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas20jg.out -i $(EXECFILES)/entrada2000rodadas20jg.txt -o $(EXECFILES)/saida2000rodadas20jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas20jg.out -i $(EXECFILES)/entrada3000rodadas20jg.txt -o $(EXECFILES)/saida3000rodadas20jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas20jg.out -i $(EXECFILES)/entrada4000rodadas20jg.txt -o $(EXECFILES)/saida4000rodadas20jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas20jg.out -i $(EXECFILES)/entrada5000rodadas20jg.txt -o $(EXECFILES)/saida5000rodadas20jg.txt
	
	$(EXE) -p $(REGPERF)/1000rodadas30jg.out -i $(EXECFILES)/entrada1000rodadas30jg.txt -o $(EXECFILES)/saida1000rodadas30jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas30jg.out -i $(EXECFILES)/entrada2000rodadas30jg.txt -o $(EXECFILES)/saida2000rodadas30jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas30jg.out -i $(EXECFILES)/entrada3000rodadas30jg.txt -o $(EXECFILES)/saida3000rodadas30jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas30jg.out -i $(EXECFILES)/entrada4000rodadas30jg.txt -o $(EXECFILES)/saida4000rodadas30jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas30jg.out -i $(EXECFILES)/entrada5000rodadas30jg.txt -o $(EXECFILES)/saida5000rodadas30jg.txt

	$(EXE) -p $(REGPERF)/1000rodadas40jg.out -i $(EXECFILES)/entrada1000rodadas40jg.txt -o $(EXECFILES)/saida1000rodadas40jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas40jg.out -i $(EXECFILES)/entrada2000rodadas40jg.txt -o $(EXECFILES)/saida2000rodadas40jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas40jg.out -i $(EXECFILES)/entrada3000rodadas40jg.txt -o $(EXECFILES)/saida3000rodadas40jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas40jg.out -i $(EXECFILES)/entrada4000rodadas40jg.txt -o $(EXECFILES)/saida4000rodadas40jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas40jg.out -i $(EXECFILES)/entrada5000rodadas40jg.txt -o $(EXECFILES)/saida5000rodadas40jg.txt

	$(EXE) -p $(REGPERF)/1000rodadas50jg.out -i $(EXECFILES)/entrada1000rodadas50jg.txt -o $(EXECFILES)/saida1000rodadas50jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas50jg.out -i $(EXECFILES)/entrada2000rodadas50jg.txt -o $(EXECFILES)/saida2000rodadas50jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas50jg.out -i $(EXECFILES)/entrada3000rodadas50jg.txt -o $(EXECFILES)/saida3000rodadas50jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas50jg.out -i $(EXECFILES)/entrada4000rodadas50jg.txt -o $(EXECFILES)/saida4000rodadas50jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas50jg.out -i $(EXECFILES)/entrada5000rodadas50jg.txt -o $(EXECFILES)/saida5000rodadas50jg.txt

cleantemp: cleanperf cleanmem clean

cleanperf:
	rm -f $(REGPERF)/*.png $(REGPERF)/*.out

cleanmem:
	rm -f $(REGMEM)/*.gpdat $(REGMEM)/*.png $(REGMEM)/*.out

clean: 
	rm -f $(EXE) $(OBJS) gmon.out