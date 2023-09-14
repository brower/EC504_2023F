CXX=g++

CXXFLAGS=-std=c++11 -Wall

SRC=$(wildcard *.cpp)
BIN_DIR=../bin
BIN=$(basename $(SRC))
INC_DIR=../include
INC=$(wildcard $(INC_DIR)/*.h)

.PHONY: clean

all: $(BIN)

%: %.cpp $(INC)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -I $(INC_DIR)  $< -o $(BIN_DIR)/$@

clean:
	$(RM) -r $(addprefix $(BIN_DIR)/, $(BIN)) *~*~
