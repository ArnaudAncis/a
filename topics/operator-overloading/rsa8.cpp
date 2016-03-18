p = generate_prime(SIZE, 15);
q = generate_prime(SIZE, 15);
n = p * q;
PhiN = (p - 1) * (q - 1);
do
{
  e = generate_prime(2 * SIZE);
} while( (e.compareTo(PhiN) != 1) ||
         (e.gcd(PhiN).compareTo(
            BigInteger.valueOf(1)) != 0));
d = e.modInverse(PhiN);
