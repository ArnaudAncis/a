p = generate_prime(SIZE, 15);
q = generate_prime(SIZE, 15);
n = p * q;
PhiN = p.subtract(BigInteger.valueOf(1));
PhiN = PhiN.multiply(
        q.subtract( BigInteger.valueOf(1)));
do
{
  e = new BigInteger(2*SIZE, new Random());
} while( (e.compareTo(PhiN) != 1) ||
         (e.gcd(PhiN).compareTo(
            BigInteger.valueOf(1)) != 0));
d = e.modInverse(PhiN);
