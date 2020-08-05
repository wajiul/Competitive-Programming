

class Binomial {
  private:
  const int Mod = 1e9 + 7;
  vector<int> fac, finv, inv;

  public:
  Binomial(int n) : fac(n, 1), finv(n, 1), inv(n, 1) {
    for(int i = 2; i < n; i++) {
      fac[i] = fac[i-1] * i % Mod;
      inv[i] = Mod - inv[Mod%i] * (Mod/i) % Mod;
      finv[i] = finv[i-1] * inv[i] % Mod;
    }
  }
  int C(int n, int r) {
    return (fac[n] * finv[r] % Mod * finv[n - r] ) % Mod;
  }
  int P(int n, int r) {
    return (fac[n] * finv[n - r]) % Mod;
  }
};

