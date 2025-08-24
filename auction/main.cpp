#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

vector<map<int, int>> b;
vector<int> itemCount;
vector<vector<int>> r;
int n, m, a, tmp;
char in;
int user, item, value;

int main() {
	cin >> n >> m >> a;
	b.resize(n);
	r.resize(m);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		itemCount.push_back(tmp);
	}

	while (a--) {
		cin >> in;
		if (in == 'B') {
			cin >> user >> item >> value;
			b[--item][--user] = value;
		} else if (in == 'W') {
			cin >> user >> item;
			b[--item].erase(--user);
		}
	}
	
	for (int i = 0; i < n; i++) {
		priority_queue<pair<int, int>> q;
		for (auto j = b[i].begin(); j != b[i].end(); j++) {
            int user = j->first;
            int bidValue = j->second; 
            q.push(make_pair(bidValue, user));
        }
		while (itemCount[i] > 0 && !q.empty()) {
            int user = q.top().second;
			r[user].push_back(i);
			q.pop();
			itemCount[i]--;
		}
	}
    
	for (int i = 0; i < m; i++) {
		if (r[i].empty()) {
            cout << "NONE" << endl;
            continue;
        } 
        for (int item : r[i]) {
            cout << item + 1 << " ";
        }
        cout << endl;
	}

    return 0;
}