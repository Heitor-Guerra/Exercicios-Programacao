#include <stddef.h>
#include <stdint.h>

/// Calculate at most `max_primes` prime numbers in the interval [2,limit]
/// using the Sieve of Eratosthenes and store the prime numbers in `primes`
/// in increasing order.
/// The function returns the number of calculated primes.

void markNotPrimes(unsigned short int *notPrimes, uint32_t limit,
                   uint32_t number) {
  for (int i = 2; i * number <= limit; i++) {
    notPrimes[i * number] = 1;
  }
}

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
  unsigned short int notPrimes[limit];
  uint32_t primeCounter = 0;
  for (uint32_t i = 2; i <= limit; i++) {
    if (notPrimes[i] == 1) {
      continue;
    }
    *primes = i;
    primes++;
    if (primeCounter < max_primes) {
      primeCounter++;
    }
    markNotPrimes(notPrimes, limit, i);
  }
  return primeCounter;
}
