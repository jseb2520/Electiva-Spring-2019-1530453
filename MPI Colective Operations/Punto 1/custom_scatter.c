#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define ROOT 0
#define N 3

//http://mpitutorial.com/tutorials/mpi-scatter-gather-and-allgather/
void custom_scatter(void *send_data, int send_count, MPI_Datatype send_datatype,
                  void *recv_data, int recv_count, MPI_Datatype recv_datatype,
                  int root, MPI_Comm communicator)
{

    int np, rank;
    int i;
    int size;

    MPI_Datatype type;
    type = send_datatype;
    MPI_Type_size(type, &size);

    MPI_Status status;
    MPI_Comm_size(communicator, &np);
    MPI_Comm_rank(communicator, &rank);

    if (rank == ROOT)
    {
        for (i = 0; i < np; i++)
        {
            MPI_Send(send_data + ((i * send_count) * size), send_count, send_datatype, i, 0, communicator);
        }
    }
    MPI_Recv(recv_data, recv_count, recv_datatype, root, 0, communicator, &status);
}

int main(int argc, char **argv)
{

    int rank, np;
    int *data;

    //MPI_Scatter
    int send_count, recv_count;
    int *recv_data;

    MPI_Status status, info;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == ROOT)
    {
        printf("root process gather");
    }

    send_count = np;
    recv_count = np;
    recv_data = malloc(recv_count * sizeof(int));

    custom_scatter(data, send_count, MPI_INT, recv_data, recv_count, MPI_INT, ROOT, MPI_COMM_WORLD);
    MPI_Finalize();
    return 0;
}