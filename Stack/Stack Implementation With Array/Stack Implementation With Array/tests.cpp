//
//  tests.cpp
//  Stack Implementation With List
//
//  Created by Лабутин Антон Александрович on 17.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#include "tests.hpp"
#include "test_runner.hpp"
#include "stack.hpp"

void
TestStackConstructor()
{
    Stack<int> s1;

    AssertEqual(s1.GetSize(), 0, "Stack s1 is empty");

    Stack<int> s2(3);
    AssertEqual(s2.GetSize(), 1, "Stack s2 has size 1");
    AssertEqual(s2.Top(), 3, "Stack s2 is {2}");

    Stack<double> s3(5.0, 3);
    AssertEqual(s3.GetSize(), 3, "Stack s3 has size 3");
    AssertEqual(s3.Top(), 5.0, "Stack s3's top is 5.0");
}

void
TestStackPush()
{
    Stack<int> s1;
    s1.Push(2);
    AssertEqual(s1.GetSize(), 1, "Stack s1 has len 1");
    AssertEqual(s1.Top(), 2, "Stack s1's top is 2");

    s1.Push(3);
    AssertEqual(s1.GetSize(), 2, "Stack s1 has len 2");
    AssertEqual(s1.Top(), 3, "Stack s1's top is 3");

    s1.Push(4);
    AssertEqual(s1.GetSize(), 3, "Stack s1 has len 3");
    AssertEqual(s1.Top(), 4, "Stack s1's top is 4");
}

void
TestStackPop()
{
    Stack<double> s1;

    try {
        s1.Pop();
    } catch(std::runtime_error& rte) {
        std::cerr << rte.what() << std::endl;
    }

    s1.Push(1.0);
    s1.Pop();
    AssertEqual(s1.GetSize(), 0, "Stack s1 is empty");

    s1.Push(2.0);
    s1.Push(3.0);
    s1.Pop();
    AssertEqual(s1.GetSize(), 1, "Stack s1 has size 1");
    AssertEqual(s1.Top(), 2.0, "Stack s1's top is 2.0");

    s1.Pop();
    AssertEqual(s1.GetSize(), 0, "Stack s1 is empty");
}

void
TestStackTop()
{
    Stack<double> s1;

    try {
        s1.Top();
    } catch(std::runtime_error& rte) {
        std::cerr << rte.what() << std::endl;
    }

    s1.Push(1.0);
    AssertEqual(s1.Top(), 1.0, "Stack s1's top is 1.0");

    s1.Push(2.0);
    AssertEqual(s1.Top(), 2.0, "Stack s1's top is 2.0");

    s1.Push(3.0);
    AssertEqual(s1.Top(), 3.0, "Stack s1's top is 3.0");
}

void
TestStackEmpty()
{
    Stack<int> s1;
    Assert(s1.Empty(), "Stack s1 is empty");

    s1.Push(1);
    Assert(! s1.Empty(), "Stack s1 is not empty");

    s1.Push(2);
    Assert(! s1.Empty(), "Stack s1 is not empty");

    s1.Pop();
    Assert(! s1.Empty(), "Stack s1 is not empty");

    s1.Pop();
    Assert(s1.Empty(), "Stack s1 is empty");
}

void
TestStackGetSize()
{
    Stack<int> s1;
    AssertEqual(s1.GetSize(), 0, "Stack s1 is empty");

    s1.Push(1);
    AssertEqual(s1.GetSize(), 1, "Stack s1 has size 1");

    s1.Push(2);
    AssertEqual(s1.GetSize(), 2, "Stack s1 has size 2");

    s1.Pop();
    AssertEqual(s1.GetSize(), 1, "Stack s1 has size 1");

    s1.Pop();
    AssertEqual(s1.GetSize(), 0, "Stack s1 is empty");
}

void
TestStack()
{
    TestRunner tr;

    tr.RunTest(TestStackConstructor, "TestStackConstructor");
    tr.RunTest(TestStackPush, "TestStackPush");
    tr.RunTest(TestStackPop, "TestStackPop");
    tr.RunTest(TestStackTop, "TestStackTop");
    tr.RunTest(TestStackEmpty, "TestStackEmpty");
    tr.RunTest(TestStackGetSize, "TestStackGetSize");
}
