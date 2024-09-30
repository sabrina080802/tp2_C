#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void print2(int tab[][3], int size)
{
    // for (int i = 0; i < size; i++)
    // {
    //     printf("Lignes %d \n", i);
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("tab :%d \n", tab[i][j]);
    //     }
    // }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

void read2(int tab[][3], int size)
{
    int nb;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Pouvez-vous me donner un nombre pour la ligne %d, colonne %d ? ", i + 1, j + 1);
            scanf("%d", &nb);
            tab[i][j] = nb;
        }
    }
    print2(tab, size);
}

int valeur_max2(int tab[][3], int size)
{
    int nb = tab[0][0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tab[i][j] > nb)
            {
                nb = tab[i][j];
            }
        }
    }
    return nb;
}

int occurrences2(int tab[][3], int size, int el)
{
    int occ = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (el == tab[i][j])
            {
                occ++;
            }
        }
    }
    return occ;
}

bool is_sudoku(int tab[3][3])
{
    srand(time(NULL));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tab[i][j] = rand() % 9 + 1;
        }
    }

    print2(tab, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (occurrences2(tab, 3, tab[i][j]) > 1)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int size = 3;
    int tab[size][3];
    int occ;
    int tab2[3][3];

    print2(tab, size);
    // read2(tab, size);
    occ = occurrences2(tab, size, 3);
    printf("L'occurrences dans ce tab est : %d\n", occ);

    int max_val = valeur_max2(tab, size);
    printf("La valeur maximale du tableau est : %d\n", max_val);

    if (is_sudoku(tab2) == true)
    {
        printf("sudoku marche");
    }
    else
    {
        printf("sudoku marche pas");
    }
}