TARGET = quicksort
OBJ_FILES = main.o
SRC_FILES = main.cpp
CC = g++

${TARGET}:${OBJ_FILES}
	${CC} ${OBJ_FILES} -o ${TARGET}

${OBJ_FILES}:${SRC_FILES}
	${CC} -c ${SRC_FILES} -o ${OBJ_FILES}

clean:
	rm ${OBJ_FILES}
	rm ${TARGET}
