#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <vector>
#include <stack>

using namespace std;

int eval_postfix(vector<pair<int, int>> v)
{
    stack<int> s;

    for (auto [op, num] : v)
    {
        if (op == 1)
        {
            s.push(num);
        }
        else if (op == 0)
        {
            if (s.size() < 2)
                return 0;

            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int res = 0;
            if (num == 0)
                res = a + b;
            if (num == 1)
                res = a - b;
            if (num == 2)
                res = a * b;
            if (num == 3)
                res = a / b;

            s.push(res);
        }
    }

    return s.empty() ? 0 : s.top();
}

#endif