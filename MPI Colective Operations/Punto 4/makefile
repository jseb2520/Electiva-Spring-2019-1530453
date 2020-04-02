EXECS=promedioReduce
MPICC?=mpicc

all: ${EXECS}

promedioReduce: promedioReduce.c
	${MPICC} -o promedioReduce promedioReduce.c

clean:
	rm -f ${EXECS}
