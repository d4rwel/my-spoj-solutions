**PALIN **29.07.2015

Algorithm

MIRROR(BigNum)

left = BigNum.Length -- 1

right = 0

**while** left \> right

BigNum\[right\] = BigNum\[left\]

left = left -- 1

right = right + 1

INC\_BIGNUM(BigNum, offset)

**if **BigNum\[offset\] == 9

INC\_BIGNUM(BigNum, offset + 1)

BigNum\[offset\] = (BigNum\[offset\] + 1) % 10

COMPUTE\_PALINDROM(BigNum)

mid = BigNum.Length / 2

if BigNum.Length mod 2 == 0

left = mid

else

left = mid + 1

right = mid -- 1

**while** right \<\> -1 **and** BigNum\[left\] == BigNum\[right\]

left = left + 1

right = right -- 1

**if** right == -1

right = right + 1

**if** BigNum\[left\] \< BigNum\[right\]

MIRROR(BigNum)

**else** **if **BigNum\[left\] \> BigNum\[right\]

INC\_BIGNUM(BigNum, mid)

MIRROR(BigNum)
