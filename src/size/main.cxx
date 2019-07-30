#include "common.h"
#include <iostream>

using namespace std;
class empty_class
{
  public:
};

class base
{
  public:
    virtual uint32_t foo()
    {
        return 1;
    }
    virtual ~base() = default;
};

class derv1 : public base
{
  public:
    uint32_t foo() override
    {
        return 2;
    }
    int b;
};

class derv2 : public derv1
{
  public:
    int c;
    int d;
};

int main()
{
    derv1 *c = new derv2();
    TEST_VALUE(sizeof(empty_class));
    TEST_VALUE(sizeof(void *));
    TEST_VALUE(sizeof(base));
    TEST_VALUE(sizeof(derv1));
    TEST_VALUE(sizeof(derv2));
    TEST_VALUE(sizeof(*c));
    TEST_VALUE(c->foo());
    delete c;
    return 0;
}
