
include build/__code__.mk

ifndef CODE
$(error Require problem code)
endif

SRC		:= src/$(CODE)
ALGO	:= $(wildcard $(SRC)/*.cpp)
TARGET	:= build/$(CODE)
PBPASTE	?= pbpaste
CXXFLAGS	:= -g -Wall

all: $(TARGET)

$(TARGET): $(SRC)/_io.cc $(ALGO)
	$(CXX) -I $(SRC) $^ -o $@ $(CXXFLAGS)

run: $(TARGET) 
	./$<

runtest: $(TARGET) 
	$(PBPASTE) | ./$<
