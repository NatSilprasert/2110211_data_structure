#include <list>
#include <iostream>
#include <vector>

// you can do anything........

using namespace std;

int checkzuma(list<int> &l, list<int>::iterator &it, int v)
{
    auto itback = it;
    int j = 0;
    while (itback != l.end() && *itback == v)
    {
        j++;
        itback--;
    }
    auto itfor = it;
    itfor++;
    while (itfor != l.end() && *itfor == v)
    {
        j++;
        itfor++;
    }
    if (j >= 3)
    {
        itback++;
        it = l.erase(itback, itfor);
        return 1;
    }
    return 0;
}

int main()
{
    int n, k, v;
    list<int> l;

    // read input
    cin >> n >> k >> v;
    while (n--)
    {
        int a;
        cin >> a;
        l.push_back(a);
    }

    auto it = l.begin();
    for (int i = 0; i < k; i++)
        it++;
    // cout << *(l.insert(it,v)) <<"XXX";
    it = l.insert(it, v);

    int c = checkzuma(l, it, v);
    while (c)
    {
        it--;
        if (it != l.end())
            c = checkzuma(l, it, *it);
        else
            c = 0;
    }

    // output
    for (auto &x : l)
    {
        cout << x << " ";
    }
    cout << endl;
}
