CC = gcc
RM = rm -f
TARGETS = qsort rselection MCS

.PHONY: all clean

all: ${TARGETS}

clean:
	${RM} *.o ${TARGETS}

qsort: qsort.o func.o
	${CC} -o $@ $^

rselection: rselection.o func.o
	${CC} -o $@ $^

MCS: MCS.c
	${CC} -o $@ $<

%.o: %.c
	${CC} -c $< 