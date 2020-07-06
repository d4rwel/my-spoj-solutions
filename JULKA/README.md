**JULKA** 16.07.2015

<http://www.spoj.com/problems/JULKA/>

<https://en.wikipedia.org/wiki/Arbitrary-precision_arithmetic>

<http://www-irm.mathematik.hu-berlin.de/~hgrass/0wr/node67.html>

Algorithm

1\. Represent sum and diff as CharArrays ( i.e. 23 = \[2\]\[3\] )

2\. K (Klaudia) = (sum + diff) / 2

3\. N (Natalia) = (sum -- K)

STRING-TO-ARRNUM(StringNumber)

ArrNum\[1..MAX\] = 0

j = MAX -- StringNumber.Length

**for** i = 1 **to** StringNumber.Length

ArrNum\[i + j\] = StringNumber\[i\]

ARRNUM-TO-STRING

i = 0

**repeat**

i++

**until** ArrNum\[i\] \> 0

**return** ArrNum\[i..MAX\]

DIVISION-BY-2(ArrNum, ArrLen, carry)

**if** ArrLen \< 0

**return**

**else if** ArrNum\[MAX-ArrLen\] % 2 == 0

DIVISION-BY-2(ArrNum, ArrLen-1, 0)

**else **

DIVISION-BY-2(ArrNum, ArrLen-1, 1)

**if** carry

ArrNum\[MAX -- ArrLen\] = (ArrNum\[MAX -- ArrLen\] + 10) / 2

**else**

ArrNum\[MAX -- ArrLen\] = ArrNum\[MAX -- ArrLen\] / 2

ADD-2-ARRNUM(ArrNum1, ArrNum2)

ArrNumResult\[1..MAX\] = 0

carry = 0

**for **i = MAX **to** 1

ArrNumResult\[i\] = (ArrNum1\[i\] + ArrNum2\[i\] + carry) % 10

carry = (ArrNum1\[i\] + ArrNum2\[i\] + carry) / 10

**return** ArrNumResult

SUB-2ARRNUM(ArrNum1, ArrNum2)

ArrNumResult\[1..MAX\] = 0

carry = 0

**for** i = MAX **to** 0

**if** ArrNum1\[i\] \< (ArrNum2\[i\] - carry)

ArrNumResult\[i\] = ((10 + ArrNum1\[i\]) -- ArrNum2\[i\] -- carry)

carry = 1

**else**

ArrNumResult\[i\] = ArrNum1\[i\] -- ArrNum2\[i\] -- carry

carry = 0
