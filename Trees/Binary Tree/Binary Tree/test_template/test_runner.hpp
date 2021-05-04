//
//  test_runner.hpp
//  Unit Testing Framework
//
//  Created by Лабутин Антон Александрович on 07.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#ifndef test_runner_hpp
#define test_runner_hpp

#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>

template <class T>
std::ostream&
operator << (std::ostream&, const std::set<T>&);

template <class K, class V>
std::ostream&
operator << (std::ostream&, const std::map<K, V>&);

void
Assert(bool, const std::string&);

template<class T, class U>
void
AssertEqual(const T&, const U&, const std::string&);

class TestRunner {
public:
    template <class TestFunc>
    void
    RunTest(TestFunc, const std::string&);

    ~TestRunner();

private:
    int fail_count = 0;
};



template <class TestFunc>
void
TestRunner::RunTest(TestFunc func, const std::string& test_name)
{
    try {
        func();
        std::cerr << test_name << " OK" << std::endl;
    } catch (std::runtime_error& e) {
        ++fail_count;
        std::cerr << test_name << " fail: " << e.what() << std::endl;
    }
}

template <class T>
std::ostream&
operator << (std::ostream& os, const std::set<T>& s)
{
    os << "{";
    bool first = true;

    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;

        os << x;
    }

    return os << "}";
}

template <class K, class V>
std::ostream&
operator << (std::ostream& os, const std::map<K, V>& m) {
    os << "{";
    bool first = true;

    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;

        os << kv.first << ": " << kv.second;
    }

    return os << "}";
}

template <class T>
std::ostream&
operator << (std::ostream& os, const std::vector<T>& v)
{
    os << "{";
    bool first = true;

    for (const auto& el : v) {
        if (! first) {
            os << ", ";
        }
        first = false;

        os << el;
    }

    return os << "}";
}

template<class T, class U>
void
AssertEqual(const T& t, const U& u, const std::string& hint)
{
    if (t != u) {
        std::ostringstream os;
        os << "Assertion failed: " << t << " != " << u << " hint: " << hint;
        throw std::runtime_error(os.str());
    }
}

#endif /* test_runner_hpp */
