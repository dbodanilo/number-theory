//
//  main.cpp
//  number-theory
//
//  Created by Danilo Bizarria on 31/03/24.
//

#include <iostream>
#include <set>

#include "primes.h"

int main(int argc, const char * argv[]) {
    std::cout << ( -1) <<     " % " << 10 << " = " << (-1 % 10) << std::endl;
    std::cout << ( -1) << " `mod` " << 10 << " = " << mod(-1, 10) << std::endl;
    std::cout << (-11) <<     " % " << 10 << " = " << (-11 % 10) << std::endl;
    std::cout << (-11) << " `mod` " << 10 << " = " << mod(-11, 10) << std::endl;

    for (int e = 0; e < 13; e += 1) {
        std::cout << 3 << " `modpow` " << e << ", " << 7 << " = " << modpow(3, e, 7) << std::endl;
    }

    /// Last 4 primes of A000040, followed by the first 4
    /// Charmichael numbers, followed by the first 4
    /// (originally 11) numbers of A014233.
    vll pps = {
        257, 263, 269, 271, 561, 1105, 1729, 2465, 2047,
        1373653, 25326001, 3215031751,
//        2152302898747, 3474749660383, 341550071728321,
//        341550071728321, 3825123056546413051,
    };

        auto ps = std::set<ll>(pps.begin(), pps.end());

        for (int c = 1; c < 13; c += 1) {
            std::cout << "certainty: " << c << std::endl;
            for (auto pp : pps) {
                if (ps.count(pp)) {
                    bool isPP = isProbablePrime(pp, c);

                    std::cout << pp << (isPP ? " is" : " is not") << " a probable prime" << std::endl;

                    if (!isPP) ps.erase(pp);
                }
            }
            std::cout << std::endl;
        }

    return 0;
}
