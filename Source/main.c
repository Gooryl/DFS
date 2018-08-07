#include "stdio.h"
#include "stdlib.h"
#include "../Header/main.h"

int main()
{
    unsigned char matrixSize = 0;
    unsigned char inputBuffer[MAX_DIGITS] = {0};
    unsigned char* pAdjacencyMatrix;
    unsigned char* pMarksMatrix;

    printf("This programm is intended to perform a depth-first search \nEnter the amount of nodes in graph: ");
    if ( ( !input_check(inputBuffer, &matrixSize ) ) || (matrixSize <= 1))
    {
        do
        {
            printf("Wrong input. The number must consist of only digits and be greater than 1.\n Enter the amount of nodes in graph: ");
        } while ((!input_check(inputBuffer, &matrixSize)) || (matrixSize <= 1));
    }

    printf("Enter the adjacency matrix:\n");

    pAdjacencyMatrix = (unsigned char*)malloc(matrixSize * matrixSize * sizeof(unsigned char));
    pMarksMatrix = (unsigned char*)malloc(matrixSize * sizeof(unsigned char));

    adjacency_matrix_builder(matrixSize,pAdjacencyMatrix);
    DFS(0, pAdjacencyMatrix, pMarksMatrix, matrixSize);

    printf("\b\b\b   \n");

    getchar();
    return 0;
}

//Take the input buffer, check input and convert it to number
unsigned char input_check(unsigned char* buffer, unsigned char* output)
{
    unsigned char* p = buffer;
    while ((*(p++) = (unsigned char)getchar()) != '\n');
    *(--p) = '\0';

    int array_length = 0;
    char* local_array = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        if ((buffer[i] < 48) || (buffer[i] > 57)) return FALSE;
        array_length++;
    }

    local_array = (char*)malloc(array_length*sizeof(char));
    for (int i = 0; i <= array_length; i++)
    {
        local_array[i] = buffer[i];
    }
    *output = (unsigned char)atoi(local_array);
    return TRUE;
}

//Create of the adjacency matrix with check of binary input
void adjacency_matrix_builder(unsigned char matrixSize, unsigned char* pAdjacencyMatrix)
{
    for (int i = 0; i<matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            if (i < j)
            {
                unsigned char array[MAX_DIGITS] = { 0 };
                printf("[%d][%d] = ", i+1, j+1);
                if (!input_check(array, pAdjacencyMatrix + i*matrixSize + j) ||
                    !((*(pAdjacencyMatrix + i*matrixSize + j) == 1) || (*(pAdjacencyMatrix + i*matrixSize + j) == 0)))
                {
                    do {
                        printf("Wrong input. The number must consist of only digits and be 1 or 0.\n[%d][%d] = ",
                               i + 1, j + 1);
                    } while (!input_check(array, pAdjacencyMatrix + i * matrixSize + j) ||
                             !((*(pAdjacencyMatrix + i * matrixSize + j) == 1) ||
                               (*(pAdjacencyMatrix + i * matrixSize + j) == 0)));
                }
            }
            else if (i == j)
            {
                *(pAdjacencyMatrix + i*matrixSize + j) = 0;
            }
            else
                *(pAdjacencyMatrix + i*matrixSize + j) = *(pAdjacencyMatrix + j*matrixSize + i);
        }
    }

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            printf("%5d ", *(pAdjacencyMatrix + i*matrixSize + j));
        }
        printf("\n");
    }
}

//DFS algorithm
void DFS(unsigned char node, unsigned char* pAdjacencyMatrix, unsigned char* pMarksMatrix, unsigned char matrixSize)
{
    if (*(pMarksMatrix + node) == TRUE) return;
    *(pMarksMatrix + node) = TRUE;
    printf ("%d -> ", node+1);
    for (unsigned char i = node ; i < matrixSize; i++)
    {
        if ( *(pAdjacencyMatrix + node*matrixSize + i) == 1 ) {
            DFS(i, pAdjacencyMatrix, pMarksMatrix, matrixSize);
        }
    }
}

