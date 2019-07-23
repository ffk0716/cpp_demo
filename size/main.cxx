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
    virtual uint32_t check() { return sizeof(*this); }
};

class derv1 : public base
{
  public:
    uint32_t check() override { return sizeof(*this); }
    int b;
};

class derv2 : public derv1
{
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
    TEST_VALUE(c->check());
    delete c;
    return 0;
}
