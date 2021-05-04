//
//  test_array.cpp
//  Array
//
//  Created by Лабутин Антон Александрович on 14.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#include <iostream>

#include "dynamic_array.hpp"
#include "test_runner.hpp"
#include "test_array.hpp"

void
TestArrayConstructor()
{
    Array<int> a;
    Array<int> b(10);
    Array<int> c(5, 2);

    AssertEqual(a.Size(), 0, "Not allocated array has size 0");
    AssertEqual(a.ElemCount(), 0, "Not allocated array has 0 elements ");
    AssertEqual(b.Size(), 10, "Empty array has size 10");
    AssertEqual(b.ElemCount(), 0, "Empty array has 0 elements");
    AssertEqual(c.Size(), 5, "Array c(5, 2) has size 5");
    AssertEqual(c.ElemCount(), 5, "Array c(5, 2) has 5 elemets");

    for (size_t i = 0; i < 5; ++i) {
        AssertEqual(c.Get(i), 2, "Array c(5, 2) has elements equal to 2");
    }

    try {
        a[0];
    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        a.Get(10);
    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Array<int> d(0, 10);
    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        b[1];
    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        b.Get(0);
    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        c.Get(6);
    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void
TestArrayAdd()
{
    Array<double> a(3);
    a.Add(0.0);
    a.Add(1.1);
    a.Add(2.2);
    a.Add(3.3);

    AssertEqual(a.Size(), 6, "Array [0.0, 1.1, 2.2, 3.3] has size 6");
    AssertEqual(a.ElemCount(), 4, "Array [0.0, 1.1, 2.2, 3.3] has 4 elements");
    AssertEqual(a[3], 3.3, "3d element of array [0.0, 1.1, 2.2, 3.3] is 3.3");

    Array<int> b(1);
    b.Add(3);

    AssertEqual(b.Size(), 1, "Array b [3] has size 1");
    AssertEqual(b.ElemCount(), 1, "Array b [3] has 1 element");
    AssertEqual(b[0], 3, "0's element of Array b [3] is 3");

    b.Add(4);

    AssertEqual(b.Size(), 2, "");
    AssertEqual(b.ElemCount(), 2, "");
    AssertEqual(b[1], 4, "");

    b.Add(5);

    AssertEqual(b.Size(), 4, "");
    AssertEqual(b.ElemCount(), 3, "");
    AssertEqual(b[2], 5, "");

    Array<int> c;
    c.Add(10);

    AssertEqual(c.Size(), 2, "");
    AssertEqual(c.ElemCount(), 1, "");
    AssertEqual(c[0], 10, "");

    Array<int> d(2, 5);
    d.Add(4);

    AssertEqual(d.Size(), 4, "");
    AssertEqual(d.ElemCount(), 3, "");
    AssertEqual(d[2], 4, "");
}

void
TestArrayRemove()
{
    Array<int> a;

    try {
        a.Remove(1);
    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    a.Add(1);
    AssertEqual(a.Remove(0), 1, "");
    AssertEqual(a.Size(), 2, "");
    AssertEqual(a.ElemCount(), 0, "");

    a.Add(2);
    AssertEqual(a.Remove(0), 2, "");
    AssertEqual(a.Size(), 2, "");
    AssertEqual(a.ElemCount(), 0, "");

    a.Add(1);
    a.Add(2);
    a.Add(3);

    try {
        a.Remove(3);
    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    AssertEqual(a.Remove(0), 1, "");
    AssertEqual(a[0], 2, "");
    AssertEqual(a[1], 3, "");
    AssertEqual(a.ElemCount(), 2, "");

    a.Add(4);
    AssertEqual(a.Remove(1), 3, "");
    AssertEqual(a[0], 2, "");
    AssertEqual(a[1], 4, "");
}
