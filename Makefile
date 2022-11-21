CXX = g++
# CXX = clang++

CXXFLAGS= -Wall -Wno-uninitialized -DWITHOUT_NUMPY -I/usr/local/include/python3.10 -lpython3.10

BINARIES=main

# COMMON_OBJECTS=tddFuncs.o utility.o shapeFuncs.o

all: ${BINARIES}

# tests: ${BINARIES}
# 	./distanceBetweenTest
# 	./initPointTest
# 	./pointsApproxEqualTest
# 	./boxesApproxEqualTest
# 	./initBoxTest
# 	./areaOfBoxTest
# 	./pointToStringTest
# 	./boxToStringTest

main: main.o 
	$(CXX) $(CXXFLAGS) $^ -o $@

# initPointTest: initPointTest.o $(COMMON_OBJECTS)
# 	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o