vector<bool> marked, marked2;
vector<int> primes, primes2;
void Seg_Sieve(lint L, lint R) {

    lint len = sqrt(R);
    marked = vector<bool>(len + 1, false);
    for (lint i = 2; i <= len; ++i) {
        if (!marked[i]) {
            primes.emplace_back(i);
            for (lint j = i * i; j <= len; j += i)
                marked[j] = true;
        }
    }

    marked2 = vector<bool>(R - L + 1, true);
    for (lint i : primes)
        for (lint j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            marked2[j - L] = false;
    
    for(lint i = L; i <= R; i++) {
      if(marked2[i - L]) {
        primes2.push_back(i);
      }
    }
}
