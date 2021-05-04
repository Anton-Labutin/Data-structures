//
//  main.cpp
//  Array
//
//  Created by Лабутин Антон Александрович on 14.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#include <iostream>

#include "dynamic_array.hpp"
#include "test_runner.hpp"
#include "test_array.hpp"

int
main()
{
    TestRunner tr;
    tr.RunTest(TestArrayConstructor, "TestArrayConstructor");
    tr.RunTest(TestArrayAdd, "TestArrayAdd");
    tr.RunTest(TestArrayRemove, "TestArrayRemove");

    return 0;
}
