p = new BigInteger(SIZE, 15, new Random());
q = new BigInteger(SIZE, 15, new Random());
n = p.multiply(q);
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
