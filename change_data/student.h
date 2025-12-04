#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>

using namespace std;

void change_1(stack<vector<queue<int>>> &a, int from, int to)
{
    stack<vector<queue<int>>> tmp;

    while (!a.empty())
    {
        auto x = a.top();

        for (auto &y : x)
        {
            queue<int> tmp_queue;
            while (!y.empty())
            {
                tmp_queue.push(y.front() == from ? to : y.front());
                y.pop();
            }
            y = tmp_queue;
        }

        tmp.push(x);
        a.pop();
    }

    while (!tmp.empty())
    {
        a.push(tmp.top());
        tmp.pop();
    }
}

void change_2(map<string, pair<priority_queue<int>, int>> &a, int from,
              int to)
{
    for (auto &y : a)
    {
        auto &x = y.second;
        auto pq = x.first;
        x.second = x.second == from ? to : x.second;
        priority_queue<int> tmp;

        while (!pq.empty())
        {
            tmp.push(pq.top() == from ? to : pq.top());
            pq.pop();
        }
        x.first = tmp;
    }
}

void change_3(set<pair<list<int>, map<int, pair<int, string>>>> &a, int from,
              int to)
{
    set<pair<list<int>, map<int, pair<int, string>>>> tmp;
    for (auto &x : a)
    {
        auto &ls = x.first;
        auto &mp = x.second;

        list<int> tmpls;
        map<int, pair<int, string>> tmpmp;

        for (auto &a : ls)
        {
            tmpls.push_back(a == from ? to : a);
        }

        for (auto &a : mp)
        {
            tmpmp[a.first == from ? to : a.first] = {
                a.second.first == from ? to : a.second.first, a.second.second};
        }

        tmp.insert({tmpls, tmpmp});
    }
    a = tmp;
}

#endif
