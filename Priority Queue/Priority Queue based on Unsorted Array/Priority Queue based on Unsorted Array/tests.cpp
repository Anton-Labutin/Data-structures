//
//  tests.cpp
//  Priority Queue based on Unsorted Array
//
//  Created by Лабутин Антон Александрович on 27.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#include "tests.hpp"
#include "test_runner.hpp"
#include "priority_queue.hpp"

template <typename T>
class Greater {
public:
    Greater() {}
    bool
    operator () (const T& x, const T& y) const
    {
        return x > y;
    }
};


template <typename T>
class Less {
public:
    Less() {}
    bool
    operator () (const T& x, const T& y) const
    {
        return x < y;
    }
};

void
TestPriorityQueueConstructor()
{
    PriorityQueue<int, int, Greater<int>> pqueue1;
    PriorityQueue<int, double, Less<int>> pqueue2(1, 2.0);

    Assert(pqueue1.Size() == 0, "pqueue1 is empty");
    Assert(pqueue2.Size() == 1, "pqueue2 has size 1");
}

void
TestPriorityQueueInsert()
{
    {
        PriorityQueue<int, int, Greater<int>> pqueue1;

        pqueue1.Insert(1, 2);
        Assert(pqueue1.Size() == 1, "pqueue1 has size 1");
        Assert(pqueue1.Get() == 2, "pqueue1's top is 2");

        pqueue1.Insert(2, 3);
        Assert(pqueue1.Size() == 2, "pqueue1 has size 2");
        Assert(pqueue1.Get() == 3, "pqueue1's top is 3");

        pqueue1.Insert(-1, 10);
        Assert(pqueue1.Size() == 3, "pqueue1 has size 3");
        Assert(pqueue1.Get() == 3, "pqueue1's top is 3");
    }
    {
        PriorityQueue<int, int, Less<int>> pqueue2;

        pqueue2.Insert(1, 2);
        AssertEqual(pqueue2.Size(), 1, "pqueue2 has size 1 after inserting (1, 2)");
        AssertEqual(pqueue2.Get(), 2, "pqueue2's top is 2 after inserting (1, 2)");

        pqueue2.Insert(2, 3);
        AssertEqual(pqueue2.Size(), 2, "pqueue2 has size 2 after inserting (2, 3)");
        AssertEqual(pqueue2.Get(), 2, "pqueue2's top is 2 after inserting (2, 3)");

        pqueue2.Insert(-1, 10);
        AssertEqual(pqueue2.Size(), 3, "pqueue2 has size 3 after inserting (-1, 10)");
        AssertEqual(pqueue2.Get(), 10, "pqueue2's top is 10 after inserting (-1, 10)");
    }
}

void
TestPriorityQueueExtract()
{
    {
        PriorityQueue<int, int, Greater<int>> pqueue1;

        pqueue1.Insert(1, 2);
        pqueue1.Extract();
        Assert(pqueue1.Size() == 0, "pqueue1 is empty");
        try {
            pqueue1.Get();
        } catch(std::runtime_error& rte) {
            std::cerr << rte.what() << std::endl;
        }

        pqueue1.Insert(2, 3);
        pqueue1.Insert(-1, 10);
        pqueue1.Extract();
        Assert(pqueue1.Size() == 1, "pqueue1 has size 1");
        Assert(pqueue1.Get() == 10, "pqueue1's top is 10");
    }
    {
        PriorityQueue<int, int, Less<int>> pqueue2;

        pqueue2.Insert(1, 2);
        pqueue2.Extract();
        Assert(pqueue2.Size() == 0, "pqueue2 is empty");
        try {
            pqueue2.Get();
        } catch(std::runtime_error& rte) {
            std::cerr << rte.what() << std::endl;
        }

        pqueue2.Insert(2, 3);
        pqueue2.Insert(-1, 10);
        pqueue2.Extract();
        Assert(pqueue2.Size() == 1, "pqueue2 has size 1");
        Assert(pqueue2.Get() == 3, "pqueue2's top is 3");
    }
}

void
TestPriorityQueueSize()
{
    PriorityQueue<int, int, Greater<int>> pqueue;
    Assert(pqueue.Size() == 0, "pqueue is empty");

    pqueue.Insert(1, 2);
    Assert(pqueue.Size() == 1, "pqueue has size 1");

    pqueue.Insert(2, 3);
    Assert(pqueue.Size() == 2, "pqueue has size 2");

    pqueue.Get();
    Assert(pqueue.Size() == 2, "pqueue has size 2");

    pqueue.Extract();
    Assert(pqueue.Size() == 1, "pqueue has size 1");

    pqueue.Extract();
    Assert(pqueue.Size() == 0, "pqueue is empty");
}

void
TestPriorityQueue()
{
    TestRunner tr;

    tr.RunTest(TestPriorityQueueConstructor, "TestPriorityQueueConstructor");
    tr.RunTest(TestPriorityQueueInsert, "TestPriorityQueueInsert");
    tr.RunTest(TestPriorityQueueExtract, "TestPriorityQueueExtract");
    tr.RunTest(TestPriorityQueueSize, "TestPriorityQueueSize");
}
