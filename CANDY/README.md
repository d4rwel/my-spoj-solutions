**CANDY **16.07.2015

<http://www.spoj.com/problems/CANDY/>

Algorithm

EQUATE-PACKETS(Array, Arraylength)

sum = 0

average = 0

result = 0

**for** i = 1 **to** Arraylength

sum += Array\[i\]

average = sum / Arraylength

**if** sum / average = Arraylength

**for **i = 1 **to** Arraylength

**while** Array\[i\] \< average

Array\[i\]++

result++

**else**

**return** -1
