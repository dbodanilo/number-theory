//
//  primes.cpp
//  number-theory
//
//  Created by Danilo Bizarria on 18/03/24.
//

#include <algorithm>
#include <iostream>

#include "primes.h"
#include "typedefs.h"

ll mod(ll x, ll n) {
    /// Limit x to [0..n]
    return ((x % n) + n) % n;
}

ll modpow(ll base, ll exp, ll n) {
    /// Naive implementation.
    //    return mod((ll)pow(base, exp), n);

    /// `fle == floor(log2(exp))`
    int fle = 0;
    ll e = exp;
    while (e >>= 1) fle++;

    /// `exp` so far.
    ll k = 0;
    /// `a**k` so far.
    ll ak = 1;

    ll a1 = mod(base, n);
    ll a2 = mod(a1 * a1, n);

    for (int i = 0; i < fle; i += 1) {
        ak = mod(ak * a2, n);
        a2 = ak;

        k = k > 0 ? k * 2 : 2;
    }

    for (; k < exp; k += 1) {
        ak = mod(ak * base, n);
    }

    return ak;
}

bool isProbablePrimeTo(ll n, ll t, int h, ll a) {
    ll beta = modpow(a, t, n);
    if (beta == 1) return true;

    for (int j = 0; j < h; j += 1) {
        if (beta == n - 1) return true;
        if (beta == 1) return false;

        beta = mod(beta * beta, n);
    }

    return false;
}

bool isProbablePrime(ll n, int certainty) {
    /// If `certainty <= 0`, `true` is returned.
    if (certainty <= 0) return true;

    /// Compact list of primes.
    vll ps = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    /// Known prime.
    if (std::find(ps.begin(), ps.end(), n) != ps.end()) return true;

    /// Even.
    if (n % 2 == 0) return false;

    /// `n - 1` is surely even.
    ll t = (n - 1) / 2;
    int h = 1;

    while (t % 2 == 0) {
        t /= 2;
        h += 1;
    }

    for (int i = 0; i < certainty && i < ps.size(); i += 1) {
        ll alpha = ps[i];
        if (!isProbablePrimeTo(n, t, h, alpha)) return false;
    }

    return true;
}
