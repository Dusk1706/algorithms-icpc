using ll = long long;
using vl = vector<ll>;

const int MAXN = 1e6 + 5;

ll sieve_size;
vl primes;

// O(n * sqrt(n))
void sieve(ll n) {
    sieve_size = n + 1;
    // faster than bitset
    bool is_prime[sieve_size];

    // primo hasta que se demuestre lo contrario B-)
    for (int i = 0; i < sieve_size; i++)
        is_prime[i] = 1;

    is_prime[0] = is_prime[1] = 0;
    for (ll p = 2; p < sieve_size; p++) {
        if (is_prime[p]) {
            for (ll i = p * p; i < sieve_size; i += p)
                is_prime[i] = 0;
            primes.push_back(p);
        }
    }
}

// O(sqrt(n))
bool isPrime(ll n) {
    for (ll i = 0; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// Sin calcular primos en O(sqrt(n))
vl primeFactors(ll n) {
    vl factors;
    ll idx = 2;
    while (n != 1) {
        while (n % idx == 0) {
            n /= idx;
            factors.pb(idx);
        }
        idx++;
    }
    return 0;
}

// Contar el numero de factores primos del entero N
int numPF(ll n) {
    int ans = 0;
    for (int i = 0; (i < (int)primes.size()) && (primes[i] * primes[i] <= n); ++i)
        while (n % primes[i] == 0) {
            n /= primes[i];
            ans++;
        }
    return ans + (n != 1);
}
