#include "gtest/gtest.h"
#include <iostream>

// from
// http://twtedlin31.blogspot.com/2016/03/sfinae.html

template <typename Type> class has_member
{
    using yes = char[1];
    using no = char[2];
    template <typename U> static yes &deduce(decltype(&U::foo));
    template <typename U> static yes &deduce(decltype(&U::foo2));
    template <typename U> static no &deduce(...);

  public:
    enum
    {
        value = sizeof(yes) == sizeof(deduce<Type>(0))
    };
};

struct A
{
};
struct B
{
    void foo() {}
};
struct C
{
    void foo(int) {}
};
struct D
{
    int foo;
};
struct E
{
    int foo2;
};
struct F
{
    int foo3;
};

TEST(a, b)
{
    EXPECT_FALSE(has_member<A>::value);
    EXPECT_TRUE(has_member<B>::value);
    EXPECT_TRUE(has_member<C>::value);
    EXPECT_TRUE(has_member<D>::value);
    EXPECT_TRUE(has_member<E>::value);
    EXPECT_FALSE(has_member<F>::value);
}
