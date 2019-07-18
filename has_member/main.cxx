#include "gtest/gtest.h"
#include <iostream>

// from
// https://stackoverflow.com/questions/9117603/how-does-this-has-member-class-template-work

template <typename Type> class has_member
{
    class yes
    {
        char m;
    };
    class no
    {
        yes m[2];
    };
    struct BaseMixin
    {
        void operator()() {}
    };
    struct Base : public Type, public BaseMixin
    {
    };
    template <typename T> class Helper
    {
    };
    template <typename U, typename T = decltype(&U::operator())>
    static no deduce(U *);
    static yes deduce(...);

  public:
    static const bool result = sizeof(yes) == sizeof(deduce((Base *)(0)));
};

struct A
{
}; // SFINAE is triggered for A
struct B
{
    void operator()() {}
}; // SFINAE is not triggered for B
struct C
{
    void operator()(int, int) {}
}; // SFINAE is not triggered for C

TEST(a, b)
{
    auto a = has_member<A>::result;
    EXPECT_FALSE(a);
    auto b = has_member<B>::result;
    EXPECT_TRUE(b);
    auto c = has_member<C>::result;
    EXPECT_TRUE(c);
}
