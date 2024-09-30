#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(float tab[], int size)
{
    printf("Tableau de réels aléatoires entre -1 et 1 :\n");
    for (int i = 0; i < size; i++)
    {
        printf("%0.2f ", tab[i]);
    }
    printf("\n");
}

void triabulle(float tab[], int size)
{
    float temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int size = 30;
    float tab[size];

    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        tab[i] = ((float)rand() / RAND_MAX) * 2 - 1;
    }

    print(tab, size);
    triabulle(tab, size);
    print(tab, size);
}
