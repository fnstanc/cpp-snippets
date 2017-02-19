/*
 * File Name: test_weak_callback.cc
 * Author: Stan.Lch
 * Mail: fn.stanc@gmail.com
 * Created Time: Sat 18 Feb 2017 12:31:35 AM CST
 */

#include "weak_callback.h"
#include <iostream>

class Foo
{
public:
    void bar()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
};

int main(int argc, char **argv)
{
    using namespace yatl;

    auto foo = std::make_shared<Foo>();
    auto cb = makeWeakCallback(std::move(foo), std::bind(&Foo::bar, foo.get()));
    std::cout << "callback before reset." << std::endl;
    cb();
    foo.reset();
    std::cout << "callback after reset." << std::endl;
    cb();

    return 0;
}
