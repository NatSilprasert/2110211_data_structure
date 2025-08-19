#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    map<long long, long long> father;
    while (n--) {
        long long f, c;
        cin >> f >> c;
        father[c] = f;
    }

    while (m--) {
        long long p1, p2;
        cin >> p1 >> p2;

        if (father.count(p1) && father.count(father.at(p1)) &&
            father.count(p2) && father.count(father.at(p2))) 
        {
            int gp1 = father.at(father.at(p1));
            int gp2 = father.at(father.at(p2));
            if (gp1 == gp2 && p1 != p2)
            {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}