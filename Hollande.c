#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_fill_rwb(char tab[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        int random_number = rand() % 3;
        if (random_number == 0)
        {
            tab[i] = 'R';
        }
        else if (random_number == 1)
        {
            tab[i] = 'W';
        }
        else
        {
            tab[i] = 'B';
        }

        printf("Étape %d: [", i + 1);
        for (int j = 0; j <= i; j++)
        {
            printf("%c", tab[j]);
            if (j < i)
            {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

void dutch_flag_sort(char tab[], int size)
{
    int redCount = 0, whiteCount = 0, blueCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (tab[i] == 'R')
            redCount++;
        else if (tab[i] == 'W')
            whiteCount++;
        else
            blueCount++;
    }

    for (int i = 0; i < redCount; i++)
        tab[i] = 'R';
    for (int i = redCount; i < redCount + whiteCount; i++)
        tab[i] = 'W';
    for (int i = redCount + whiteCount; i < size; i++)
        tab[i] = 'B';
}

void print_tab(char tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c ", tab[i]);
    }
    printf("\n");
}

int main()
{
    int size = 30;
    char tab[size];

    random_fill_rwb(tab, size);

    printf("Tableau initial :\n");
    print_tab(tab, size);

    dutch_flag_sort(tab, size);

    printf("Tableau trié :\n");
    print_tab(tab, size);
}
