#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

void print(int tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \n", tab[i]);
    }
}
void printfloat(float tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%0.2f\n", tab[i]);
    }
}
void read(int tab[], int size)
{
    int nb;
    for (int i = 0; i < size; i++)
    {
        printf("pouvez-vous me donnez un nombre ? ");
        scanf("%d", &nb);
        tab[i] = nb;
    }
    print(tab, size);
}

void random_fill_int(int tab[], int size, int vmin, int vmax)
{
    for (int i = 0; i < size; i++)
    {
        int random_number = rand() % (vmax - vmin + 1) + vmin;
        tab[i] = random_number;
    }
    // print(tab, size);
}

void random_fill_float(float tab[], int size, float vmin, float vmax)
{
    for (int i = 0; i < size; i++)
    {
        float random_number = (float)rand() / (RAND_MAX);
        tab[i] = vmin + random_number * (vmax - vmin);
    }
    printfloat(tab, size);
}

int valeur_max(int tab[], int size)
{
    int nb = tab[0];
    for (int i = 0; i < size; i++)
    {
        if (tab[i] >= nb)
        {
            nb = tab[i];
        }
    }
    return nb;
}

void swap_elt(int tab[], int size, int i, int j)
{
    int nb = tab[i];
    tab[i] = tab[j];
    tab[j] = nb;
}
int occurrences(int tab[], int size, int el)
{
    int occ;
    for (int i = 0; i < size; i++)
    {
        if (el == tab[i])
        {
            occ++;
        }
    }
    return occ;
}

int find_last(int tab[], int size, int el)
{
    int place;
    for (int i = 0; i < size; i++)
    {
        if (el == tab[i])
        {
            place = i;
        }
    }
    return place;
}

int find_first(int tab[], int size, int el)
{
    int place;
    for (int i = 0; i < size; i++)
    {
        if (el == tab[i])
        {
            place = i;
            return place;
        }
    }
    return 0;
}

void reverse(int tab[], int size)
{
    int temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = tab[i];
        tab[i] = tab[size - i - 1];
        tab[size - i - 1] = temp;
    }
    printf("tab inverse : ");
    print(tab, size);
}

void rotate_right(int tab[], int size)
{
    int temp;
    temp = tab[size - 1];

    for (int i = size - 1; i > 0; i--)
    {
        tab[i] = tab[(i - 1)];
    }
    tab[0] = temp;
}

void rotate_left(int tab[], int size)
{
    int temp;
    temp = tab[0];

    for (int i = 0; i < size - 1; i++)
    {
        tab[i] = tab[(i + 1)];
    }
    tab[size - 1] = temp;
}

bool is_palindrome(int tab[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        if (tab[i] != tab[size - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int size = 5;
    int tab[size];
    float tab2[size];
    int valeurMax;
    int occ;
    int place;

    print(tab, size);
    read(tab, size);
    random_fill_int(tab, size, 4, 15);
    random_fill_float(tab2, size, 4.2, 18.9);

    valeurMax = valeur_max(tab, size);
    printf("Voici la valeur la plus grande du tableau : %d \n ", valeurMax);
    swap_elt(tab, size, 2, 4);

    occ = occurrences(tab, size, 3);
    place = find_first(tab, size, 2);

    reverse(tab, size);
    rotate_right(tab, size);
    rotate_left(tab, size);
    if (is_palindrome(tab, size))
    {
        printf("Le tableau est un palindrome.\n");
    }
    else
    {
        printf("Le tableau n'est pas un palindrome.\n");
    }

    return 0;
}