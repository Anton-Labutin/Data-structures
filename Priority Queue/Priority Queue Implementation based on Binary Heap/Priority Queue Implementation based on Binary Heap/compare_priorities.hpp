//
//  compare_priorities.hpp
//  Priority Queue Implementation based on Binary Heap
//
//  Created by Лабутин Антон Александрович on 28.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#ifndef compare_priorities_hpp
#define compare_priorities_hpp

#include <utility>

template <typename KeyType, typename ValueType, typename CompareType>
class ComparePriorities {
public:
    bool
    operator () (const std::pair<KeyType, ValueType>& p1,
                 const std::pair<KeyType, ValueType>& p2
                 ) const
    {
        return CompareType().operator()(p1.first, p2.first);
    }

    ValueType
    Limit() const
    {
        return CompareType().Limit();
    }
};

#endif /* compare_priorities_hpp */
