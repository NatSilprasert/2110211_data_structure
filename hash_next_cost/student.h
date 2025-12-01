#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "unordered_map.h"

namespace CP
{

    template <typename KeyT,
              typename MappedT,
              typename HasherT,
              typename EqualT>
    size_t CP::unordered_map<KeyT, MappedT, HasherT, EqualT>::next_cost(iterator iter)
    {
        size_t cost = 0;

        if (iter == this->end()) return 0;
        
        size_t bucketIdx = hash_to_bucket(iter->first);
        ValueIterator it = find_in_bucket(mBuckets[bucketIdx], iter->first);
        it++;

        if (it != mBuckets[bucketIdx].end()) return 1; // มีตัวถัดไปที่ติดกัน
        
        cost++;

        for (size_t i = bucketIdx + 1; i < this->mBuckets.size(); ++i) {
            cost++;
            if (!this->mBuckets[i].empty()) return cost;
        }

        cost++;

        return cost;
    }

}

#endif
