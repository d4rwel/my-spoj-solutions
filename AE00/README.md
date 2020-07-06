**AE00** 24.07.2015

Algorithm

*COUNT-COMP-RECT(numRect)*

count = numRect

i = 2

tempRect = 0

**for** i = 2 **to** i\*i \<= numRect

tempRect = i\*i

**while** tempRect \<= numRect

count = count +1

tempRect = tempRect + i

**return** count
