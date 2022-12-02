#include <iostream> // for printing elements
using std::cout; // cout for printing elements

class B {
private:
  // Members
  int j,k;

public:
  // Constructors
  B();
  B(int _j, int _k){
    setJ(_j);
    setK(_k);
  }
  // Getters
  int getJ(){
    return j;
  }
  int getK(){
    return k;
  }
  // Setters
  void setJ(int _j){
    (this)->j = _j;
  }
  void setK(int _k){
    (this)->k = _k;
  }

  // Helpers
  //virtual inline void myPrint(){};
};

class A : public B{
private:
  // Members
  int i;

public:
  // Constructors
  A(int _i, int _j, int _k): i(_i) , B(_j, _k) {}
  // Getters
  int getI() {
    return i;
  }
  // Setters
  void setI(int _i){
    (this)->i = _i;
  }
  // Helpers
  void myPrint()
  {
    cout << "(i,j,k) = ("
    << getI() << ", "
    << getJ() << ", "
    << getK() << ")"  <<  '\n';
  }
};

int main ()
{
  B* b = new A(5, 2, 3);
  ((A*)b)->myPrint();
  return 0;
}
