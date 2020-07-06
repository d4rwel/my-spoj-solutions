**LASTDIG** 17.07.2015

<http://www.spoj.com/problems/LASTDIG/>

Algorithm

LAST-DIG(a, b)

d = 1

**for** i = 30 **to** 0

d = (d \* d) % 10

**if **b / 2\^i == 1

d = ( a \* d ) mod 10

**return** d
