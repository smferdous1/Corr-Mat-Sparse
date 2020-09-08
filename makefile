CFLAGS =  -O3 -std=c++11

INCLUDE_DIR = ${PWD}/include
BIN_DIR = ${PWD}/bin
EXE_DIR = ${PWD}/exe
SRC_DIR = ${PWD}/src
TEST_DIR = ${PWD}/test

all: lazygreedy 
 
lazygreedy: input.o graph.o edgeCoverCore.o utility.o */lazyGreedyEdgeCover.cpp
	g++ $(CFLAGS) $(BIN_DIR)/utility.o $(BIN_DIR)/input.o $(BIN_DIR)/edgeCoverCore.o $(BIN_DIR)/graph.o $(SRC_DIR)/lazyGreedyEdgeCover.cpp $(TEST_DIR)/lazy_greedy_edge_cover_test.cpp -I$(INCLUDE_DIR) -o $(EXE_DIR)/lazygreedy.out
 
graph.o: $(INCLUDE_DIR)/graph.h $(SRC_DIR)/graph.cpp
	g++ $(CFLAGS) -c $(SRC_DIR)/graph.cpp -I$(INCLUDE_DIR)  -o $(BIN_DIR)/graph.o

edgeCoverCore.o: $(INCLUDE_DIR)/edgeCover.h $(SRC_DIR)/edgeCoverCore.cpp
	g++ $(CFLAGS) -c  $(SRC_DIR)/edgeCoverCore.cpp -I$(INCLUDE_DIR)  -o $(BIN_DIR)/edgeCoverCore.o

utility.o: $(INCLUDE_DIR)/utility.h $(SRC_DIR)/utility.cpp
	g++ $(CFLAGS) -c  $(SRC_DIR)/utility.cpp -I$(INCLUDE_DIR)  -o $(BIN_DIR)/utility.o

input.o: $(INCLUDE_DIR)/input.h $(SRC_DIR)/input.cpp
	g++ $(CFLAGS) -c  $(SRC_DIR)/input.cpp -I$(INCLUDE_DIR)  -o $(BIN_DIR)/input.o 

