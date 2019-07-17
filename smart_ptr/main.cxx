#include <iostream>
#include <memory>

using namespace std;

class A
{
  public:
    virtual ~A() { cout << "is a" << endl; }
};

class B : public A
{
  public:
    ~B() { cout << "is b" << endl; }
};

int main()
{
    {
        cout << "test 1" << endl;
        unique_ptr<A> a;
        a = unique_ptr<A>(new A);
    }
    {
        cout << "test 2" << endl;
        unique_ptr<A> a;
        a = unique_ptr<A>(new B);
    }
    {
        cout << "test 3" << endl;
        unique_ptr<A> a;
        a = unique_ptr<B>(new B);
    }

    return 0;
}
