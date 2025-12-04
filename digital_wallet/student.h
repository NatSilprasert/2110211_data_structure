#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <string>
#include <map>
#include <queue>

// you can include anything

using namespace std;

class DigitalWallet
{
  // declare variables here

  // when my money expire (with amount)
  map<string, queue<pair<size_t, int>>> m_w_exp;
  map<string, int> c_money;

  // at each time, whose money expire
  map<size_t, vector<string>> p_w_exp;

  long long t_give = 0, t_spent = 0, t_expired = 0;

private:
  void process_expired(size_t time, string person_id)
  {
    while (!m_w_exp[person_id].empty() &&
           m_w_exp[person_id].front().first < time)
    {
      c_money[person_id] -= m_w_exp[person_id].front().second;
      t_expired += m_w_exp[person_id].front().second;
      m_w_exp[person_id].pop();
    }
  }

public:
  void add_money(size_t time, string person_id, int amount, size_t duration)
  {
    t_give += amount;

    c_money[person_id] += amount;
    m_w_exp[person_id].emplace(time + duration, amount);

    p_w_exp[time + duration].push_back(person_id);
  }

  bool use_money(size_t time, string person_id, int amount)
  {
    process_expired(time, person_id);

    if (amount > c_money[person_id])
      return false;

    t_spent += amount;
    c_money[person_id] -= amount;

    while (amount > 0)
    {
      if (m_w_exp[person_id].front().second >= amount)
      {
        m_w_exp[person_id].front().second -= amount;
        return true;
      }
      amount -= m_w_exp[person_id].front().second;
      m_w_exp[person_id].pop();
    }
  }

  int current_money(size_t time, string person_id)
  {
    process_expired(time, person_id);
    return c_money[person_id];
  }

  void status(size_t time, long long &total_give, long long &total_spent,
              long long &total_expired)
  {
    auto it = p_w_exp.begin();
    while (it != p_w_exp.end())
    {
      if (it->first < time)
      {
        for (auto &x : it->second)
        {
          process_expired(time, x);
        }
      }
      else
      {
        break;
      }

      auto tmp = it++;
      p_w_exp.erase(tmp);
    }

    total_give = t_give;
    total_spent = t_spent;
    total_expired = t_expired;
  }
};

#endif
