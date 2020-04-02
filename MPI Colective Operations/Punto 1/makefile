EXECS=custom_bcast custom_scatter custom_gather
MPICC?=mpicc

all: ${EXECS}

custom_bcast: custom_bcast.c
	${MPICC} -o custom_bcast custom_bcast.c

custom_scatter: custom_scatter.c
	${MPICC} -o custom_scatter custom_scatter.c

custom_gather: custom_gather.c
	${MPICC} -o custom_gather custom_gather.c

clean:
	rm -f ${EXECS}
