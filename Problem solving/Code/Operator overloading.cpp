#include <iostream>  
using namespace std;  
class Test {
  public:
  int M;
  Test(){
    M = 0;
  }
  Test(int _M) {
    M = _M;
  }
  Test operator+(Test &d) {
    Test ob;
    ob.M = this->M + d.M + 10;
    return ob;
  }
};
  
int main()  
{ 
   Test a(1);
   Test b(4);
   Test c;
   c = a+b;
   cout << c.M << '\n';
    return 0;  
}  
