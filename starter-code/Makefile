CXX = g++
# CXX = clang++

CXXFLAGS= -Wall -Wno-uninitialized -DWITHOUT_NUMPY -I/usr/local/include/python3.10 -lpython3.10


OBJECTFILES = dataManipulationFuncs.o graphingTool.o
TARGET = graphingTool

all: ${TARGET}

${TARGET}: ${OBJECTFILES}
	$(CXX) ${CXXFLAGS} -o ${TARGET} ${OBJECTFILES} 

clean:
	/bin/rm -f ${TARGET} *.o