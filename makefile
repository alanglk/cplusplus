opt=0

CXX=g++
CFLAGS=-Wall -std=c++17

BUILD=build/
SRC=${wildcard *.cpp ./src/*.cpp}
OBJ=${patsubst %.cpp,$(BUILD)%.o,${SRC}}

ifeq (${opt},0)
  CFLAGS+=-g
else
  CFLAGS+=-O3
endif

all: ${OBJ}
	${CXX}  ${CFLAGS} ${OBJ} -o main ${LDFLAGS}

build/%.o : %.cpp
	mkdir -p ${dir $@}
	${CXX} -o $@ $< -c ${CFLAGS}

clean :
	rm -rf main build