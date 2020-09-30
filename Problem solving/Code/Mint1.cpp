#include <iostream>  
using namespace std;  
class Mint {
public:
int mod; int M;
Mint(){ M = 0; mod = 1e9 + 7; }
Mint(int _M) { M = _M; mod = 1e9 + 7; }
Mint operator%(Mint &d) { Mint ob; ob.M = this->M % d.M;  return ob; }
Mint operator+(Mint &d) { Mint ob; ob.M = ( ( (this->M % mod + mod) % mod ) + ( (d.M % mod + mod) % mod) ) % mod;  return ob; }
Mint operator*(Mint &d) {
Mint ob; ob.M = ( ( (this->M % mod + mod) % mod ) * ( (d.M % mod + mod) % mod) ) % mod;  return ob; }
void operator=(int tr) {  Mint ob; M = tr; }
};
  
int main()  
{ 
   Mint a(11);
   Mint b(4);
   Mint c(4);
   Mint ans;
   ans = (a + b);
   cout << "ans = " << ans.M << '\n';
  Mint h;
  h.M = 100;
  cout << h.M << '\n';
   Mint g;
   g = 10000;
   Mint X, Y , Z;
   X = 5;
   Y = 5;
   Z = X * Y;
   cout << X.M <<" " << Y.M << '\n';
   cout << Z.M << '\n';
    return 0;  
}  
