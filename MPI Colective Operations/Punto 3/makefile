EXECS=promedio
MPICC?=mpicc

all: ${EXECS}

promedio: promedio.c
	${MPICC} -o promedio promedio.c

clean:
	rm -f ${EXECS}
