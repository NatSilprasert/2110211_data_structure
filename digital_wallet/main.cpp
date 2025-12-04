#include <iostream>
#include "student.h"

using namespace std;

int main() {
  DigitalWallet wallet;
  while (true) {
    char func;
    cin >> func;

    size_t time, duration;
    string person_id;
    int amount;

    switch (func) {
      case 'a':
        cin >> time >> person_id >> amount >> duration;
        wallet.add_money(time, person_id, amount, duration);
        break;

      case 'u':
        cin >> time >> person_id >> amount;
        if (wallet.use_money(time, person_id, amount))
          cout << "true\n";
        else
          cout << "false\n";
        break;

      case 'c':
        cin >> time >> person_id;
        cout << wallet.current_money(time, person_id) << '\n';
        break;

      case 's':
        cin >> time;
        long long total_give, total_spent, total_expired;
        wallet.status(time, total_give, total_spent, total_expired);
        cout << "total_give = " << total_give
             << ", total_spent = " << total_spent
             << ", total_expired = " << total_expired << '\n';
        break;

      case 'q':
        exit(0);
    }
  }
}