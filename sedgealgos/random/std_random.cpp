#include "sedgealgos/random/std_random.hpp"

#include <random>
#include <sstream>
#include <stdexcept>

namespace {
   template <typename T>
   void validate_range(T const m, T const n) {
       if (n >= m) {
           return;
       }
       std::stringstream ss;
       ss << "m is greater than n, where ";
       ss << "m=" << m << " and n=" << n;
       throw std::invalid_argument(ss.str());
   }
}

namespace sedgealgos::random {
   int StdRandom::uniform(int const n) {
       return uniform(0, n);
   } 

   int StdRandom::uniform(int const m, int const n) {
       ::validate_range(m, n);
       std::uniform_int_distribution<> distribution{m, n};
       return distribution(generator);
   }
   
   double StdRandom::uniform() {
       return uniform(0.0, 1.0);
   }

   double StdRandom::uniform(double const n) {
       return uniform(0.0, n);
   }

   double StdRandom::uniform(double const m, double const n) {
       ::validate_range(m, n);
       std::uniform_real_distribution<> distribution{m, n};
       return distribution(generator);
   }
}
