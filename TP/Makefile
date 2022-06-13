CXX = g++
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
SANITIZE = #-fsanitize=undefined,address -static-libasan
CXXFLAGS = -Wall -c -I$(INC) -g $(SANITIZE) -O3
LDFLAGS = $(SANITIZE) -g -O3
ANALISAMEM = ../analisamem/bin/analisamem
GENLOAD = ../geracargapoquer/bin/geracarga

EXE = $(BIN)/tp1.exe

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(EXE) $(OBJS)

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
	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas100jg.txt -r 1000 -j 100 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas100jg.txt -r 2000 -j 100 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas100jg.txt -r 3000 -j 100 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas100jg.txt -r 4000 -j 100 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas100jg.txt -r 5000 -j 100 -v 0

	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas200jg.txt -r 1000 -j 200 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas200jg.txt -r 2000 -j 200 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas200jg.txt -r 3000 -j 200 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas200jg.txt -r 4000 -j 200 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas200jg.txt -r 5000 -j 200 -v 0

	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas300jg.txt -r 1000 -j 300 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas300jg.txt -r 2000 -j 300 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas300jg.txt -r 3000 -j 300 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas300jg.txt -r 4000 -j 300 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas300jg.txt -r 5000 -j 300 -v 0

	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas400jg.txt -r 1000 -j 400 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas400jg.txt -r 2000 -j 400 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas400jg.txt -r 3000 -j 400 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas400jg.txt -r 4000 -j 400 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas400jg.txt -r 5000 -j 400 -v 0

	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas500jg.txt -r 1000 -j 500 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas500jg.txt -r 2000 -j 500 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas500jg.txt -r 3000 -j 500 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas500jg.txt -r 4000 -j 500 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas500jg.txt -r 5000 -j 500 -v 0

	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas600jg.txt -r 1000 -j 600 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas600jg.txt -r 2000 -j 600 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas600jg.txt -r 3000 -j 600 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas600jg.txt -r 4000 -j 600 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas600jg.txt -r 5000 -j 600 -v 0

	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas700jg.txt -r 1000 -j 700 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas700jg.txt -r 2000 -j 700 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas700jg.txt -r 3000 -j 700 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas700jg.txt -r 4000 -j 700 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas700jg.txt -r 5000 -j 700 -v 0

	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas800jg.txt -r 1000 -j 800 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas800jg.txt -r 2000 -j 800 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas800jg.txt -r 3000 -j 800 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas800jg.txt -r 4000 -j 800 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas800jg.txt -r 5000 -j 800 -v 0

	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas900jg.txt -r 1000 -j 900 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas900jg.txt -r 2000 -j 900 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas900jg.txt -r 3000 -j 900 -
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas900jg.txt -r 4000 -j 900 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas900jg.txt -r 5000 -j 900 -v 0

	$(GENLOAD) -o $(EXECFILES)/entrada1000rodadas1000jg.txt -r 1000 -j 1000 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada2000rodadas1000jg.txt -r 2000 -j 1000 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada3000rodadas1000jg.txt -r 3000 -j 1000 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada4000rodadas1000jg.txt -r 4000 -j 1000 -v 0
	$(GENLOAD) -o $(EXECFILES)/entrada5000rodadas1000jg.txt -r 5000 -j 1000 -v 0

perf: $(EXE)
	$(EXE) -p $(REGPERF)/1000rodadas100jg.out -i $(EXECFILES)/entrada1000rodadas100jg.txt -o $(EXECFILES)/saida1000rodadas100jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas100jg.out -i $(EXECFILES)/entrada2000rodadas100jg.txt -o $(EXECFILES)/saida2000rodadas100jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas100jg.out -i $(EXECFILES)/entrada3000rodadas100jg.txt -o $(EXECFILES)/saida3000rodadas100jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas100jg.out -i $(EXECFILES)/entrada4000rodadas100jg.txt -o $(EXECFILES)/saida4000rodadas100jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas100jg.out -i $(EXECFILES)/entrada5000rodadas100jg.txt -o $(EXECFILES)/saida5000rodadas100jg.txt

	$(EXE) -p $(REGPERF)/1000rodadas200jg.out -i $(EXECFILES)/entrada1000rodadas200jg.txt -o $(EXECFILES)/saida1000rodadas200jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas200jg.out -i $(EXECFILES)/entrada2000rodadas200jg.txt -o $(EXECFILES)/saida2000rodadas200jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas200jg.out -i $(EXECFILES)/entrada3000rodadas200jg.txt -o $(EXECFILES)/saida3000rodadas200jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas200jg.out -i $(EXECFILES)/entrada4000rodadas200jg.txt -o $(EXECFILES)/saida4000rodadas200jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas200jg.out -i $(EXECFILES)/entrada5000rodadas200jg.txt -o $(EXECFILES)/saida5000rodadas200jg.txt
	
	$(EXE) -p $(REGPERF)/1000rodadas300jg.out -i $(EXECFILES)/entrada1000rodadas300jg.txt -o $(EXECFILES)/saida1000rodadas300jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas300jg.out -i $(EXECFILES)/entrada2000rodadas300jg.txt -o $(EXECFILES)/saida2000rodadas300jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas300jg.out -i $(EXECFILES)/entrada3000rodadas300jg.txt -o $(EXECFILES)/saida3000rodadas300jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas300jg.out -i $(EXECFILES)/entrada4000rodadas300jg.txt -o $(EXECFILES)/saida4000rodadas300jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas300jg.out -i $(EXECFILES)/entrada5000rodadas300jg.txt -o $(EXECFILES)/saida5000rodadas300jg.txt

	$(EXE) -p $(REGPERF)/1000rodadas400jg.out -i $(EXECFILES)/entrada1000rodadas400jg.txt -o $(EXECFILES)/saida1000rodadas400jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas400jg.out -i $(EXECFILES)/entrada2000rodadas400jg.txt -o $(EXECFILES)/saida2000rodadas400jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas400jg.out -i $(EXECFILES)/entrada3000rodadas400jg.txt -o $(EXECFILES)/saida3000rodadas400jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas400jg.out -i $(EXECFILES)/entrada4000rodadas400jg.txt -o $(EXECFILES)/saida4000rodadas400jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas400jg.out -i $(EXECFILES)/entrada5000rodadas400jg.txt -o $(EXECFILES)/saida5000rodadas400jg.txt

	$(EXE) -p $(REGPERF)/1000rodadas500jg.out -i $(EXECFILES)/entrada1000rodadas500jg.txt -o $(EXECFILES)/saida1000rodadas500jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas500jg.out -i $(EXECFILES)/entrada2000rodadas500jg.txt -o $(EXECFILES)/saida2000rodadas500jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas500jg.out -i $(EXECFILES)/entrada3000rodadas500jg.txt -o $(EXECFILES)/saida3000rodadas500jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas500jg.out -i $(EXECFILES)/entrada4000rodadas500jg.txt -o $(EXECFILES)/saida4000rodadas500jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas500jg.out -i $(EXECFILES)/entrada5000rodadas500jg.txt -o $(EXECFILES)/saida5000rodadas500jg.txt

	$(EXE) -p $(REGPERF)/1000rodadas600jg.out -i $(EXECFILES)/entrada1000rodadas600jg.txt -o $(EXECFILES)/saida1000rodadas600jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas600jg.out -i $(EXECFILES)/entrada2000rodadas600jg.txt -o $(EXECFILES)/saida2000rodadas600jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas600jg.out -i $(EXECFILES)/entrada3000rodadas600jg.txt -o $(EXECFILES)/saida3000rodadas600jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas600jg.out -i $(EXECFILES)/entrada4000rodadas600jg.txt -o $(EXECFILES)/saida4000rodadas600jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas600jg.out -i $(EXECFILES)/entrada5000rodadas600jg.txt -o $(EXECFILES)/saida5000rodadas600jg.txt

	$(EXE) -p $(REGPERF)/1000rodadas700jg.out -i $(EXECFILES)/entrada1000rodadas700jg.txt -o $(EXECFILES)/saida1000rodadas700jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas700jg.out -i $(EXECFILES)/entrada2000rodadas700jg.txt -o $(EXECFILES)/saida2000rodadas700jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas700jg.out -i $(EXECFILES)/entrada3000rodadas700jg.txt -o $(EXECFILES)/saida3000rodadas700jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas700jg.out -i $(EXECFILES)/entrada4000rodadas700jg.txt -o $(EXECFILES)/saida4000rodadas700jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas700jg.out -i $(EXECFILES)/entrada5000rodadas700jg.txt -o $(EXECFILES)/saida5000rodadas700jg.txt

	$(EXE) -p $(REGPERF)/1000rodadas800jg.out -i $(EXECFILES)/entrada1000rodadas800jg.txt -o $(EXECFILES)/saida1000rodadas800jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas800jg.out -i $(EXECFILES)/entrada2000rodadas800jg.txt -o $(EXECFILES)/saida2000rodadas800jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas800jg.out -i $(EXECFILES)/entrada3000rodadas800jg.txt -o $(EXECFILES)/saida3000rodadas800jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas800jg.out -i $(EXECFILES)/entrada4000rodadas800jg.txt -o $(EXECFILES)/saida4000rodadas800jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas800jg.out -i $(EXECFILES)/entrada5000rodadas800jg.txt -o $(EXECFILES)/saida5000rodadas800jg.txt

	$(EXE) -p $(REGPERF)/1000rodadas900jg.out -i $(EXECFILES)/entrada1000rodadas900jg.txt -o $(EXECFILES)/saida1000rodadas900jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas900jg.out -i $(EXECFILES)/entrada2000rodadas900jg.txt -o $(EXECFILES)/saida2000rodadas900jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas900jg.out -i $(EXECFILES)/entrada3000rodadas900jg.txt -o $(EXECFILES)/saida3000rodadas900jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas900jg.out -i $(EXECFILES)/entrada4000rodadas900jg.txt -o $(EXECFILES)/saida4000rodadas900jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas900jg.out -i $(EXECFILES)/entrada5000rodadas900jg.txt -o $(EXECFILES)/saida5000rodadas900jg.txt

	$(EXE) -p $(REGPERF)/1000rodadas1000jg.out -i $(EXECFILES)/entrada1000rodadas1000jg.txt -o $(EXECFILES)/saida1000rodadas1000jg.txt
	$(EXE) -p $(REGPERF)/2000rodadas1000jg.out -i $(EXECFILES)/entrada2000rodadas1000jg.txt -o $(EXECFILES)/saida2000rodadas1000jg.txt
	$(EXE) -p $(REGPERF)/3000rodadas1000jg.out -i $(EXECFILES)/entrada3000rodadas1000jg.txt -o $(EXECFILES)/saida3000rodadas1000jg.txt
	$(EXE) -p $(REGPERF)/4000rodadas1000jg.out -i $(EXECFILES)/entrada4000rodadas1000jg.txt -o $(EXECFILES)/saida4000rodadas1000jg.txt
	$(EXE) -p $(REGPERF)/5000rodadas1000jg.out -i $(EXECFILES)/entrada5000rodadas1000jg.txt -o $(EXECFILES)/saida5000rodadas1000jg.txt

gprof: $(EXE)
	$(EXE) -p $(REGPERF)/1000rodadas100jg.out -i $(EXECFILES)/entrada1000rodadas100jg.txt -o $(EXECFILES)/saida1000rodadas100jg.txt
	gprof $(EXE) gmon.out > $(REGPERF)/1000rodadas100jggprof.txt

cleantemp: cleanperf cleanmem clean

cleanperf:
	rm -f $(REGPERF)/*.png $(REGPERF)/*.out

cleanmem:
	rm -f $(REGMEM)/*.gpdat $(REGMEM)/*.png $(REGMEM)/*.out

clean: 
	rm -f $(EXE) $(OBJS) gmon.out