CC = gcc
RM = rm -f
TARGETS = qsort selection MCS

.PHONY: all clean

all: ${TARGETS}

clean:
	${RM} *.o ${TARGETS}

qsort: qsort.o partition.o
	${CC} -o $@ $^

selection: selection.o partition.o
	${CC} -o $@ $^

MCS: MCS.c
	${CC} -o $@ $<

%.o: %.c
	${CC} -c $< 