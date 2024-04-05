//
//  main.cpp
//  number-theory
//
//  Created by Danilo Bizarria on 31/03/24.
//

#include <iostream>

#include "primes.h"

int main(int argc, const char * argv[]) {
    std::cout << ( -1) <<     " % " << 10 << " = " << (-1 % 10) << std::endl;
    std::cout << ( -1) << " `mod` " << 10 << " = " << mod(-1, 10) << std::endl;
    std::cout << (-11) <<     " % " << 10 << " = " << (-11 % 10) << std::endl;
    std::cout << (-11) << " `mod` " << 10 << " = " << mod(-11, 10) << std::endl;

    for (int e = 0; e < 13; e += 1) {
        std::cout << 3 << " `modpow` " << e << ", " << 7 << " = " << modpow(3, e, 7) << std::endl;
    }

        
    return 0;
}
