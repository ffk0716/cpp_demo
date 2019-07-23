#include "common.h"
#include <iostream>

using namespace std;
class X
{
  public:
};

class A
{
  public:
    virtual uint32_t check() { return sizeof(*this); }
};

class B : public A
{
  public:
    uint32_t check() { return sizeof(*this); }
    int b;
};
class C : public B
{
    int c[10];
};
int main()
{
    C *c = new C();
    TEST_VALUE(sizeof(X));
    TEST_VALUE(sizeof(void *));
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(*c) << endl;
    cout << c->check() << endl;
    return 0;
}
