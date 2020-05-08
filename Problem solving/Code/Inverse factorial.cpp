vector<int> fac, facInv, inv;
void facInit(int nmax)
{
    fac = facInv = inv = vector<int>(nmax + 1, 1);
    for (int i = 2; i <= nmax; i++)
    {
        fac[i] = fac[i-1] * i % Mod;
        inv[i] = Mod - inv[Mod%i] * (Mod/i) % Mod;
        facInv[i] = facInv[i-1] * inv[i] % Mod;
    }
}
