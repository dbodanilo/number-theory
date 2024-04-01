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
    if (x < 0) x -= n * (x / n - 1);

    return (x % n);
}

ll modpow(ll base, ll exp, ll n) {
    /// Naive implementation.
//    return mod((ll)pow(base, exp), n);
    ll e = exp;
    int fle = 0;
    while (e >>= 1) fle++;

    ll k = 1;
    ll ak = mod(base, n);

    for (int i = 0; i < fle; i += 1) {
        ak = mod(ak * ak, n);
        k *= 2;
    }
    
//    std::cout << "k = " << k << std::endl;
    
    ak = k < exp ? ak * base : ak;

    return mod(ak, n);
}

bool isProbablePrime(ll n, int certainty) {
    /// If `certainty <= 0`, `true` is returned.
    if (certainty <= 0) return true;

    /// Compact list of primes.
    vll ps = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    /// Known prime.
//    if (std::find(p.begin(), p.end(), n) != p.end()) return true;

    /// Even.
    if (n % 2 == 0) return false;

    

    return false;
}

