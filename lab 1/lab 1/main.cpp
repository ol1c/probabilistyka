
#include <iostream>
#include <math.h>

struct poz {
    unsigned int populacja;
    double x;
    double y;
};

const double MAX_DOUBLE = 1.0e308 - 1;

void tmp_print(int m, int tmp[], int nr)
{
    printf("%d. ", nr);
    for (int i = 0; i < m; i++)
        printf("%d ", tmp[i]);
    printf("\n");
}

void silnia_gen(int n, int tmp[], int s, bool visited[], int *nr)
{
    if (s == n)
    {
        (*nr)++;
        tmp_print(n, tmp, *nr);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            tmp[s] = i+1;
            visited[i] = true;
            silnia_gen(n, tmp, s+1, visited, nr);
            visited[i] = false;
        }
    }
}

void permutacje(int n) {
    int* tmp = new int[n];
    bool* visited = new bool[n];
    
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int s = 0;
    int nr = 0;
    silnia_gen(n, tmp, s, visited, &nr);
    
    delete[] tmp;
    delete[] visited;
}

void zad2_szukaj(int n, int m, int s, int tmp[], int start, int* nr)
{
    if (s == m)
    {
        (*nr)++;
        tmp_print(m, tmp, *nr);
        return;
    }
    for (int i = start; i < n; i++)
    {
        tmp[s] = i + 1;
        zad2_szukaj(n, m, s+1, tmp, i, nr);
    }
}

void zad2(int n, int m)
{
    int* tmp = new int[m];

    int nr = 0;
    int start = 0;
    zad2_szukaj(n, m, 0, tmp, start, &nr);

    delete[] tmp;
}

void droga_szukaj(int n, poz miasta[], int tmp[], int odp[], int s, bool visited[], double *droga, double *min, bool *pierwszy)
{
    if (s == n)
    {
        double a, b, c;
        a = miasta[tmp[0] - 1].x - miasta[tmp[s - 1] - 1].x;
        b = miasta[tmp[0] - 1].y - miasta[tmp[s - 1] - 1].y;
        c = sqrt((a * a) + (b * b));
        *droga += c;
        if (*pierwszy)
        {
            *min = *droga;
            for (int j = 0; j < n; j++)
                odp[j] = tmp[j];
            *pierwszy = false;
        }
        else if (*droga < *min)
        {
            *min = *droga;
            for (int j = 0; j < n; j++)
                odp[j] = tmp[j];
        }
        *droga -= c;
        return;
    }
    double a, b, c;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            tmp[s] = i + 1;
            visited[i] = true;
            if (s)
            {
                a = miasta[tmp[s-1] - 1].x - miasta[tmp[s] - 1].x;
                b = miasta[tmp[s - 1] - 1].y - miasta[tmp[s] - 1].y;
                c = sqrt((a * a) + (b * b));
                *droga += c;
            }
            droga_szukaj(n, miasta, tmp, odp, s+1, visited, droga, min, pierwszy);
            if (s) *droga -= c;
            visited[i] = false;
        }
    }
}

void droga(poz miasta[], int n)
{
    int* odp = new int[n];
    int* tmp = new int[n];

    double min = MAX_DOUBLE;
    double droga = 0;

    bool* visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int s = 0;
    bool pierwszy = true;
    
    droga_szukaj(n, miasta, tmp, odp, s, visited, &droga, &min, &pierwszy);

    for (int i = 0; i < n; i++)
        printf("%d ", odp[i]);
    printf("\n%f\n", min);


    delete[] odp;
    delete[] tmp;
    delete[] visited;
}

void populacja_szukaj(int n, poz miasta[], int s, int tmp[], int odp[], int start, int* populacja, int* najblizej, int* pol)
{
    if (s == n)
    {
        if (abs(*populacja - *pol) < abs(*najblizej - *pol))
        {
            *najblizej = *populacja;
            for (int i = 0; i < n; i++)
                odp[i] = tmp[i];
        }
        return;
    }
    for (int i = start; i < n; i++)
    {
        tmp[s] = i + 1;
        if (!s || (s && tmp[s] != tmp[s - 1])) *populacja += miasta[tmp[s] - 1].populacja;
        populacja_szukaj(n, miasta, s + 1, tmp, odp, i, populacja, najblizej, pol);
        if (!s || (s && tmp[s] != tmp[s - 1])) *populacja -= miasta[tmp[s] - 1].populacja;
    }
}

void populacja(poz miasta[], int n)
{
    int* tmp = new int[n];   
    int* odp = new int[n];

    int populacja = 0;
    int najbli¿ej = 0;
    int pol = 0;
    for (int i = 0; i < n; i++) pol += miasta[i].populacja;
    najbli¿ej = pol;
    pol /= 2;
    int start = 0;
    populacja_szukaj(n, miasta, 0, tmp, odp, start, &populacja, &najbli¿ej, &pol);

    for (int i = 0; i < n; i++)
        printf("%d ", odp[i]);
    printf("\n%d\n", najbli¿ej);

    delete[] tmp;
    delete[] odp;
}

int main()
{
    //permutacje(5);
    //zad2(4, 3);

    poz miasta[] = {
        {2837, 41.9028, 12.4964},
        {1366, 45.4642, 9.1900},
        {959, 40.8522, 14.2681},
        {878, 45.0703, 7.6869},
        {675, 38.1157, 13.3615},
        {583, 44.4056, 8.9463},
        {393, 44.4949, 11.3426},
        {383, 43.7696, 11.2558},
        {325, 41.1171, 16.8719 },
        {311, 37.5079, 15.0830},
        {260, 45.4408, 12.3155},
        {257, 45.4384, 10.9916},
        {236, 38.1938, 15.5540},
        {209, 45.4064, 11.8768},
        {200, 45.6495, 13.7768}
    };
    //droga(miasta, 5);
    populacja(miasta, 3);
}