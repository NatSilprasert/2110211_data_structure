#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

std::vector<size_t> count_value(const std::map<long long, int> &data, const std::vector<std::pair<int, int>> &queries)
{
  std::vector<int> values;
  values.reserve(data.size()); 
  for (const auto &pair : data) {
    values.push_back(pair.second);
  }

  std::sort(values.begin(), values.end());

  std::vector<size_t> results;
  results.reserve(queries.size());

  for (const auto &q : queries) {
    int a = q.first;
    int b = q.second;

    auto lower = std::lower_bound(values.begin(), values.end(), a);

    auto upper = std::upper_bound(values.begin(), values.end(), b);

    size_t count = std::distance(lower, upper);
    results.push_back(count);
  }

  return results;
}

#endif
