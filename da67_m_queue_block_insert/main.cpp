#include "queue.h"
#include "student.h"
#include <iostream>

using std::cin;
using std::cout;

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	CP::queue<int > q;

	while(true){
		char cmd;
		cin >> cmd;

		if(cmd == 's') {
			cout << q.size() << "\n";
		} else if (cmd == 'u') {
			int X;
			cin >> X;
			q.push(X);
		} else if (cmd == 'o') {
			q.pop();
		} else if (cmd == 'f') {
			cout << q.front() << "\n";
		} else if (cmd == 'b') {
			cout << q.back() << "\n";
		} else if (cmd == 'i') {
			int p,m,e;
			cin >> p >> m >> e;
			q.block_insert(p, m, e);
		} else {
			break;
		}
	}
}