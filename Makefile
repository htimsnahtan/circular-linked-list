CXX = g++
CXXFLAGS = -std=c++0x -Wall -g

TARGET = program
OBJS = main.o Queue.o utilityFunctions.o
SRCS = main.cpp Queue.cpp utilityFunctions.cpp
HEADERS = Queue.hpp utilityFunctions.hpp

${TARGET}: ${OBJS} ${HEADERS}
	${CXX} ${SRCS} -o ${TARGET}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm ${OBJS}