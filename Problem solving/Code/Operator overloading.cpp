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
  Test operator%(Test &d) {
    Test ob;
    ob.M = this->M % d.M;
    return ob;
  }
    Test operator+(Test &d) {
    Test ob;
    ob.M = this->M + d.M;
    return ob;
  }
   void operator=(int tr) {
    Test ob;
    M = tr;
  }
  friend ostream &operator<<( ostream &output, const Test &D ) { 
  output << "->" << D.M << '\n';
  return output;            
}

 friend istream &operator>>( istream  &input, Test &D ) { 
  input >> D.M;
  return input;            
}
  
};
  
int main()  
{ 
   Test a(11);
   Test b(4);
   Test c(4);
   Test ans;
   ans = (a + b) % c;
   cout << "ans = " << ans.M << '\n';
  Test h;
  h.M = 100;
  cout << h.M << '\n';
   Test g;
   g.M = 50;
   cout << g.M << '\n';
   //----------------------------------
   Test S;
   cin >> S;
   cout << S << '\n';
    return 0;  
}  
