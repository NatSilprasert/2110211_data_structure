#include <bits/stdc++.h>
using namespace std;

int value[2005];

int n, m;

int probe(int val, int collision)
{
    return ((val) % n + (collision * collision) % n) % n;
}

int find_space(int val)
{
    int col = 0;
    while (value[probe(val, col)] >= 0)
    {
        col++;
    }
    return probe(val, col);
}

int find_space_cnt(int val)
{
    int col = 0;
    while (value[probe(val, col)] >= 0)
    {
        col++;
    }
    return col;
}

int find_blank_cnt(int val)
{
    int col = 0;
    while (value[probe(val, col)] != -1)
    {
        col++;
    }
    return col;
}

int find_val(int val)
{
    int col = 0;
    while (value[probe(val, col)] != val)
    {
        if (value[probe(val, col)] == -1)
            return -1;
        col++;
    }
    return probe(val, col);
}

main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        value[i] = -1;

    while (m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if (a == 1)
        {
            value[find_space(b)] = b;
        }
        else
        {
            int pos = find_val(b);
            if (pos == -1)
                continue;
            value[pos] = -2;
        }
    }

    int mx1 = -1, mx2 = -1;

    for (int i = 0; i < n; i++)
    {
        mx1 = max(mx1, find_space_cnt(i));
        mx2 = max(mx2, find_blank_cnt(i));
    }

    printf("%d %d", mx1 + 1, mx2 + 1);
}