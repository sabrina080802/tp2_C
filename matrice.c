#include <stdio.h>

typedef float Mat33[3][3];

void printMatrix(Mat33 M)
{
    for (int i = 0; i < 3; i++)
    {
        printf("\n");

        for (int j = 0; j < 3; j++)
        {
            printf("%6.2f ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void readMat33(Mat33 M)
{
    int nb;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Pouvez-vous me donner un nombre pour la ligne %d, colonne %d ? ", i + 1, j + 1);
            scanf("%d", &nb);
            M[i][j] = nb;
        }
    }
    printMatrix(M);
}
void setId(Mat33 M)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            M[i][j] = (i == j ? 1 : 0);
        }
    }

    // printMatrix(M);
}
void somme(Mat33 A, Mat33 B, Mat33 ApB)
{
    printMatrix(A);
    printMatrix(B);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ApB[i][j] = A[i][j] + B[i][j];
        }
    }
    printMatrix(ApB);
}

void produit(Mat33 A, Mat33 B, Mat33 AfB)
{
    printMatrix(A);
    printMatrix(B);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            AfB[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                AfB[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printMatrix(AfB);
}

int main()
{
    Mat33 M;
    Mat33 B;
    Mat33 C;

    // readMat33(M);
    setId(M);
    setId(B);
    somme(M, B, C);
    produit(M, B, C);
}