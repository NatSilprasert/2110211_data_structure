#include <stdio.h>
#include "unordered_map.h"
#include "student.h"
 
using namespace std;

struct SimpleHash {
    size_t operator()(int key) const {
        return key % 5;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    CP::unordered_map<int, std::string, SimpleHash> myMap;
    int n, k, a;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> k;
        myMap[k] = "myData";
    }
    cin >> a;
    auto it = myMap.begin();
    while(a--) it++;
    cout << myMap.next_cost(it);
}

