CC = gcc
RM = rm -f
TARGETS = qsort selection

.PHONY: all clean

all: ${TARGETS}

clean:
	${RM} *.o ${TARGETS}

qsort: qsort.o partition.o
	${CC} -o $@ $^

selection: selection.o partition.o
	${CC} -o $@ $^

%.o: %.c
	${CC} -c $< 