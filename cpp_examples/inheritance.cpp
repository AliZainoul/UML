#include <iostream>
#include <vector>

using namespace std;

class A
{
  private:
    int z;
  protected:
    int y;
  public:
    int x;
    A()
    {
      cout << "Calling A() default constuctor of A" << endl;
      x = 44; y = 45; z = 46;
    }

    A(int _x, int _y, int _z)
    {
      cout << "Calling A(int _x, int _y, int _z) constuctor of A" << endl;
      x = _x; y = _y; z = _z;
    }

    // Getters
    vector<int> getCoords()
    {
      vector<int> v = {0, 0, 0};
      v[0] = x;
      v[1] = y;
      v[2] = z;
      return v;
    }
  //
};
// x is public, y is protected and z is private in A class.
class B : public A 
{
  public:
    B() : A() {;}
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
  public:
    C() : A() {;}
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
  public:
    D() : A() {;}

    // x is private
    // y is private
    // z is not accessible from D
};

int main()
{

  A* a = new A(22,23,24);
  vector<int> vA = a->getCoords();
  for (unsigned int i = 0; i < vA.size(); i++)
  {
    cout <<  vA[i] << endl;
  }
  //cout << a->x << endl;
  //x is public so visible
  //cout << a->y << endl;
  //y is protected so inaccessible
  //cout << a->z << endl;
  //z is private so inaccessible



  B* b = new B();
  vector<int> vB = b->getCoords();
  for (unsigned int i = 0; i < vB.size(); i++)
  {
    cout << vB[i] << endl;
  }
  cout << b->x << endl;
  //A::x is public so visible
  //cout << b->y << endl;
  //A::y is protected so inaccessible
  //cout << b->z << endl;
  //A::z is private so inaccessible


  C* c = new C();
  vector<int> vC = c->getCoords();
  for (unsigned int i = 0; i < vC.size(); i++)
  {
    cout << vC[i] << endl;
  }
  //cout << c->x << endl;
  //A::x is public so visible
  //cout << c->y << endl;
  //A::y is protected so inaccessible
  //cout << c->z << endl;
  //A::z is private so inaccessible


  delete a; //freed memory
  a = NULL;

  delete b; //freed memory
  b = NULL;

  delete c; //freed memory
  c = NULL;

  return 0;
}
