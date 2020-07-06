**FASHION** 16.07.2015

<http://www.spoj.com/problems/FASHION/>

Algorithm

SUM-HOTNESS(ArrMen, ArrWomen, ArrLength)

QSORT(ArrMen)

QSORT(ArrWomen)

sum = 0

**for** i = 1 **to** ArrLength

sum += ArrMen\[i\] \* ArrWomen\[i\]

**return** sum
