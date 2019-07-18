#include "gtest/gtest.h"
#include <iostream>
#include <type_traits>

// from
// http://twtedlin31.blogspot.com/2016/03/sfinae.html

template <typename Type> class has_member
{
    using yes = char[1];
    using no = char[2];
    template <typename U> static yes &deduce(decltype(&U::foo));
    template <typename U> static no &deduce(...);

  public:
    enum
    {
        value = sizeof(yes) == sizeof(deduce<Type>(0))
    };
};

// from
// https://stackoverflow.com/questions/1005476/how-to-detect-whether-there-is-a-specific-member-variable-in-class

template <typename T, typename = int> struct has_member2 : std::false_type
{
};

template <typename T>
struct has_member2<T, decltype((void)&T::foo, 0)> : std::true_type
{
};

// test case
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

TEST(a, 1)
{
    EXPECT_FALSE(has_member<A>::value);
    EXPECT_TRUE(has_member<B>::value);
    EXPECT_TRUE(has_member<C>::value);
    EXPECT_TRUE(has_member<D>::value);
    EXPECT_FALSE(has_member<E>::value);
}

TEST(a, 2)
{
    EXPECT_FALSE(has_member2<A>::value);
    EXPECT_TRUE(has_member2<B>::value);
    EXPECT_TRUE(has_member2<C>::value);
    EXPECT_TRUE(has_member2<D>::value);
    EXPECT_FALSE(has_member2<E>::value);
}
