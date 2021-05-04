//
//  tests.cpp
//  Binary Heap
//
//  Created by Лабутин Антон Александрович on 27.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#include "tests.hpp"
#include "binary_heap.hpp"
#include "test_runner.hpp"

template <typename T>
class Greater {
public:
    bool
    operator () (const T& x, const T& y) const
    {
        return x > y;
    }

    T
    Limit() const
    {
        return std::numeric_limits<T>::max();
    }
};

template <typename T>
class Less {
public:
    bool
    operator () (const T& x, const T& y) const
    {
        return x < y;
    }

    T
    Limit() const
    {
        return std::numeric_limits<T>::min();
    }
};

void
TestBinaryHeapConstructor()
{
    BinaryHeap<int, Greater<int>> bh1;
    AssertEqual(bh1.Size(), 0, "bh1 is empty");

    BinaryHeap<double, Less<double>> bh2;
    AssertEqual(bh2.Size(), 0, "bh2 is empty");

    BinaryHeap<int, Greater<int>> bh3(1);
    AssertEqual(bh3.Size(), 1, "bh1 has size 1");

    BinaryHeap<double, Less<double>> bh4(2.0);
    AssertEqual(bh4.Size(), 1, "bh1 has size 1");
}

void
TestBinaryHeapInsert()
{
    {
        BinaryHeap<int, Greater<int>> bh1;

        bh1.Insert(1);
        // 1
        AssertEqual(bh1.Size(), 1, "bh1 has size 1");
        AssertEqual(bh1.Get(), 1, "bh1's top is 1");
        AssertEqual(bh1.Get(0), 1, "bh1's top is 1");

        bh1.Insert(5);
        // 5 1
        AssertEqual(bh1.Size(), 2, "bh1 has size 2");
        AssertEqual(bh1.Get(), 5, "bh1's top is 5");
        AssertEqual(bh1.Get(1), 1, "bh1[1] is 1");

        bh1.Insert(3);
        // 5 1 3
        AssertEqual(bh1.Size(), 3, "bh1 has size 3");
        AssertEqual(bh1.Get(), 5, "bh1's top is 5");
        AssertEqual(bh1.Get(1), 1, "bh1[1] is 1");
        AssertEqual(bh1.Get(2), 3, "bh1[2] is 3");

        bh1.Insert(4);
        // 5 4 3 1
        AssertEqual(bh1.Size(), 4, "bh1 has size 4");
        AssertEqual(bh1.Get(), 5, "bh1's top is 5");
        AssertEqual(bh1.Get(1), 4, "bh1[1] is 4");
        AssertEqual(bh1.Get(2), 3, "bh1[2] is 3");
        AssertEqual(bh1.Get(3), 1, "bh1[2] is 1");
    }
    {
        BinaryHeap<int, Less<int>> bh2;

        bh2.Insert(1);
        // 1
        AssertEqual(bh2.Size(), 1, "bh2 has size 1");
        AssertEqual(bh2.Get(), 1, "bh2's top is 1");
        AssertEqual(bh2.Get(0), 1, "bh2's top is 1");

        bh2.Insert(5);
        // 1 5
        AssertEqual(bh2.Size(), 2, "bh2 has size 2");
        AssertEqual(bh2.Get(), 1, "bh2's top is 1");
        AssertEqual(bh2.Get(1), 5, "bh2[1] is 5");

        bh2.Insert(3);
        // 1 5 3
        AssertEqual(bh2.Size(), 3, "bh2 has size 3");
        AssertEqual(bh2.Get(), 1, "bh2's top is 1");
        AssertEqual(bh2.Get(1), 5, "bh2[1] is 5");
        AssertEqual(bh2.Get(2), 3, "bh2[2] is 3");

        bh2.Insert(4);
        // 1 4 3 5
        AssertEqual(bh2.Size(), 4, "bh2 has size 4");
        AssertEqual(bh2.Get(), 1, "bh2's top is 1");
        AssertEqual(bh2.Get(1), 4, "bh2[1] is 4");
        AssertEqual(bh2.Get(2), 3, "bh2[2] is 3");
        AssertEqual(bh2.Get(3), 5, "bh2[2] is 5");
    }
}

void
TestBinaryHeapExtract()
{
    {
        BinaryHeap<int, Greater<int>> bh1;

        bh1.Insert(1);
        bh1.Extract();
        AssertEqual(bh1.Size(), 0, "bh1 is empty");

        bh1.Insert(2);
        // 2
        bh1.Insert(5);
        // 5 2
        bh1.Insert(3);
        // 5 2 3

        bh1.Extract();
        // 3 2
        AssertEqual(bh1.Size(), 2, "bh1 has size 2");
        AssertEqual(bh1.Get(), 3, "bh1'top is 3");
        AssertEqual(bh1.Get(1), 2, "bh1[1] is 2");

        bh1.Extract();
        AssertEqual(bh1.Size(), 1, "bh1 has size 1");
        AssertEqual(bh1.Get(), 2, "bh1'top is 2");
    }
    {
        BinaryHeap<int, Less<int>> bh2;

        bh2.Insert(1);
        bh2.Extract();
        AssertEqual(bh2.Size(), 0, "bh2 is empty");

        bh2.Insert(3);
        bh2.Insert(5);
        bh2.Insert(2);

        bh2.Extract();
        AssertEqual(bh2.Size(), 2, "bh2 has size 2");
        AssertEqual(bh2.Get(), 3, "bh2'top is 3");
        AssertEqual(bh2.Get(1), 5, "bh2[1] is 5");

        bh2.Extract();
        AssertEqual(bh2.Size(), 1, "bh2 has size 1");
        AssertEqual(bh2.Get(), 5, "bh2'top is 5");
    }
}

void
TestBinaryHeapDelete()
{
    {
        BinaryHeap<int, Greater<int>> bh1;

        bh1.Insert(1);
        bh1.Delete(0);
        AssertEqual(bh1.Size(), 0, "bh1 is empty");

        bh1.Insert(2);
        // 2
        bh1.Insert(5);
        // 5 2
        bh1.Insert(3);
        // 5 2 3
        bh1.Insert(10);
        // 10 5 3 2
        bh1.Insert(7);
        // 10 7 3 2 5

        bh1.Delete(3);
        // 10 7 3 5
        AssertEqual(bh1.Size(), 4, "bh1 has size 4");
        AssertEqual(bh1.Get(), 10, "bh1'top is 10");
        AssertEqual(bh1.Get(1), 7, "bh1[1] is 7");
        AssertEqual(bh1.Get(2), 3, "bh1[2] is 3");
        AssertEqual(bh1.Get(3), 5, "bh1[3] is 5");

        bh1.Delete(1);
        // 10 5 3
        AssertEqual(bh1.Size(), 3, "bh1 has size 3");
        AssertEqual(bh1.Get(), 10, "bh1'top is 10");
        AssertEqual(bh1.Get(1), 5, "bh1'[1] is 5");
        AssertEqual(bh1.Get(2), 3, "bh1'[2] is 3");

        bh1.Delete(0);
        // 5 3
        AssertEqual(bh1.Size(), 2, "bh1 has size 2");
        AssertEqual(bh1.Get(), 5, "bh1'top is 5");
        AssertEqual(bh1.Get(1), 3, "bh1'[1] is 3");

        bh1.Delete(0);
        // 3
        AssertEqual(bh1.Size(), 1, "bh1 has size 1");
        AssertEqual(bh1.Get(), 3, "bh1'top is 3");
    }
    {
        BinaryHeap<int, Less<int>> bh2;

        bh2.Insert(1);
        bh2.Delete(0);
        AssertEqual(bh2.Size(), 0, "bh2 is empty");

        bh2.Insert(2);
        // 2
        bh2.Insert(5);
        // 2 5
        bh2.Insert(3);
        // 2 5 3
        bh2.Insert(10);
        // 2 5 3 10
        bh2.Insert(7);
        // 2 5 3 10 7

        bh2.Delete(3);
        // 2 5 3 7
        AssertEqual(bh2.Size(), 4, "bh2 has size 4");
        AssertEqual(bh2.Get(), 2, "bh2'top is 2 after delete idx 3");
        AssertEqual(bh2.Get(1), 5, "bh2[1] is 5");
        AssertEqual(bh2.Get(2), 3, "bh2[2] is 3");
        AssertEqual(bh2.Get(3), 7, "bh2[3] is 7");

        bh2.Delete(1);
        // 2 7 3
        AssertEqual(bh2.Size(), 3, "bh2 has size 3");
        AssertEqual(bh2.Get(), 2, "bh2'top is 2 after deleting idx 1");
        AssertEqual(bh2.Get(1), 7, "bh2'[1] is 7");
        AssertEqual(bh2.Get(2), 3, "bh2'[2] is 3");

        
        bh2.Delete(0);
        // 3 7
        AssertEqual(bh2.Size(), 2, "bh2 has size 2");
        AssertEqual(bh2.Get(), 3, "bh2'top is 3");
        AssertEqual(bh2.Get(1), 7, "bh2'[1] is 7");

        bh2.Delete(0);
        // 7
        AssertEqual(bh2.Size(), 1, "bh2 has size 1");
        AssertEqual(bh2.Get(), 7, "bh2'top is 7");
    }
}

void
TestBinaryHeap()
{
    TestRunner tr;

    tr.RunTest(TestBinaryHeapConstructor, "TestBinaryHeapConstructor");
    tr.RunTest(TestBinaryHeapInsert, "TestBinaryHeapInsert");
    tr.RunTest(TestBinaryHeapExtract, "TestBinaryHeapExtract");
    tr.RunTest(TestBinaryHeapDelete, "TestBinaryHeapDelete");
}
