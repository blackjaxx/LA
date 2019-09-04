#include <stdio.h>
#include <stdlib.h>
int maxint = 2147483647;

void getit(int *t, int *coin, int ncoin, int money, int **m)
{
    m[ncoin][0] = 0;
    for (int i = 1; i <= money; i++)
    {
        m[ncoin][i] = maxint;
        for (int j = 1; j <= coin[ncoin]; j++)
            if (i == t[ncoin] * j)
            {
                m[ncoin][i] = j;
                break;
            }
    }

    for (int i = ncoin - 1; i >= 0; i--)
    {
        for (int j = 0; j <= money; j++)
            m[i][j] = m[i + 1][j];
        for (int j = money; j >= t[i]; j--)
            for (int k = 1; k <= coin[i]; k++)
                if ((j - t[i] * k >= 0) && (m[i][j - t[i] * k] != maxint) && (m[i][j - t[i] * k] + k < m[i][j]))
                    m[i][j] = m[i][j - t[i] * k] + k;
    }
    if (m[0][money] == maxint)
        printf("-1");
    else
        printf("%d\n", m[0][money]);
}

int main()
{
    int ncoin;
    scanf("%d", &ncoin);
    int *t = (int *)malloc(sizeof(int) * ncoin);
    int *coin = (int *)malloc(sizeof(int) * ncoin);
    for (int i = 0; i < ncoin; i++)
        scanf("%d %d", &t[i], &coin[i]);
    int money;
    scanf("%d", &money);

    int **m = (int **)malloc(sizeof(int *) * ncoin);
    for (int i = 0; i < ncoin; i++)
        m[i] = (int *)malloc(sizeof(int) * (money + 1));
    int **num = (int **)malloc(sizeof(int *) * ncoin);

    for (int i = 0; i < ncoin; i++)
        num[i] = (int *)malloc(sizeof(int) * (money + 1));
    getit(t, coin, ncoin - 1, money, m);

    for (int i = 0; i < ncoin; i++)
    {
        for (int j = 0; j <= money; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
    return 0;
}