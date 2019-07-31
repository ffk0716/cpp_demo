#include "gtest/gtest.h"

using namespace std;

class A
{
  public:
    bool is_const()
    {
        return false;
    }
    bool is_const() const
    {
        return true;
    }
};

TEST(foo, simple)
{
    A a;
    A *p1 = &a;
    A const *p2 = &a;
    A *const p3 = &a;
    A const *const p4 = &a;
    EXPECT_FALSE(p1->is_const());
    EXPECT_TRUE(p2->is_const());
    EXPECT_FALSE(p3->is_const());
    EXPECT_TRUE(p4->is_const());
}
