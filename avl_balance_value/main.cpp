#include <iostream>
#include <vector>
#include "map_avl.h"
#include "student.h"

using std::cin;
using std::cout;
int main() {
    std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, Q;
    int x;
    CP::map_avl<int,int> m;
    cin >> N >> Q;
    for(int i = 0;i < N;i++) {
        cin >> x;
        m[x] = x;
    }
    int a;
    for(int i = 0;i < Q;i++) {
        cin >> a;
        CP::map_avl<int,int>::iterator it = m.find(a);
        std::vector<size_t> balances = m.balance_values(it);
        for(size_t balance:balances) {
            cout << balance << " ";
        }
        cout << '\n';
    }
}