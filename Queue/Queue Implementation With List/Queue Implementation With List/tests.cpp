//
//  tests.cpp
//  Queue Implementation With List
//
//  Created by Лабутин Антон Александрович on 17.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#include "tests.hpp"
#include "test_runner.hpp"
#include "queue.hpp"

void
TestQueueConstructor()
{
    Queue<int> q1;
    AssertEqual(q1.GetSize(), 0, "Queue q1 is empty");

    Queue<int> q2(3);
    AssertEqual(q2.GetSize(), 1, "Queue q2 has size 1");
    AssertEqual(q2.Dequeue(), 3, "Queue q2 is {3}");

    Queue<double> q3(4.0, 2);
    AssertEqual(q3.GetSize(), 2, "Queue q3 has size 2");
    AssertEqual(q3.Dequeue(), 4.0, "Queue q3 is {4.0, 4.0}");
    AssertEqual(q3.Dequeue(), 4.0, "Queue q3 is {4.0}");
}

void
TestQueueEnqueue()
{
    Queue<int> q1;
    q1.Enqueue(2);
    AssertEqual(q1.GetSize(), 1, "Queue q1 has size 1");
    AssertEqual(q1.Dequeue(), 2, "Queue q1 is {2}");

    Queue<int> q2(1, 2);
    q2.Enqueue(3);
    AssertEqual(q2.GetSize(), 3, "Queue q2 has size 3");
    AssertEqual(q2.Dequeue(), 1, "Queue q2 is {1, 1, 3}");
    AssertEqual(q2.Dequeue(), 1, "Queue q2 is {1, 3}");
    AssertEqual(q2.Dequeue(), 3, "Queue q2 is {3}");
}

void
TestQueueDeque()
{
    Queue<int> q1;
    try {
        q1.Dequeue();
    } catch(std::runtime_error& rte) {
        std::cerr << rte.what() << std::endl;
    }

    q1.Enqueue(2);
    AssertEqual(q1.GetSize(), 1, "Queue q1 has size 1");
    AssertEqual(q1.Dequeue(), 2, "Queue q1 is {2}");

    Queue<int> q2(1, 2);
    q2.Enqueue(3);
    AssertEqual(q2.GetSize(), 3, "Queue q2 has size 3");
    AssertEqual(q2.Dequeue(), 1, "Queue q2 is {1, 1, 3}");
    AssertEqual(q2.Dequeue(), 1, "Queue q2 is {1, 3}");
    AssertEqual(q2.Dequeue(), 3, "Queue q2 is {3}");
}

void
TestQueueGetSize()
{
    Queue<int> q;
    AssertEqual(q.GetSize(), 0, "Queue q is empty");

    q.Enqueue(1);
    AssertEqual(q.GetSize(), 1, "Queue q has size 1");

    q.Enqueue(2);
    AssertEqual(q.GetSize(), 2, "Queue q has size 2");

    q.Dequeue();
    AssertEqual(q.GetSize(), 1, "Queue q has size 1");

    q.Dequeue();
    AssertEqual(q.GetSize(), 0, "Queue q is empty");
}

void
TestQueueEmpty()
{
    Queue<int> q;
    Assert(q.Empty(), "Queue q is empty");

    q.Enqueue(1);
    Assert(! q.Empty(), "Queue q has size 1");

    q.Enqueue(2);
    Assert(! q.Empty(), "Queue q has size 2");

    q.Dequeue();
    Assert(! q.Empty(), "Queue q has size 1");

    q.Dequeue();
    Assert(q.Empty(), "Queue q is empty");
}

void
TestQueue()
{
    TestRunner tr;

    tr.RunTest(TestQueueConstructor, "TestQueueConstructor");
    tr.RunTest(TestQueueEnqueue, "TestQueueEnqueue");
    tr.RunTest(TestQueueDeque, "TestQueueDeque");
    tr.RunTest(TestQueueGetSize, "TestQueueGetSize");
    tr.RunTest(TestQueueEmpty, "TestQueueEmpty");
}
