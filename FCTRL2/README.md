**FCTRL2 **14.07.2015

Input:

TNumber of following lines ( 1 \<= T \<= 100 )

N\[T\]Array of numbers with size T ( 1 \<= N\[i\] \<= 100 )

Output:

R\[T\]Array of Factorials of N\[i\]

Algorithm:

*FACTORIAL(n):*

*array\[100\]*

*array\[1\] = 1*

*size = 1*

**for** i=1 **to** n

carry = 0

**for** j=1 **to** size

prod = array\[j\] \* i + carry

array\[j\] = prod % 10

carry = abrunden(prod / 10)

**while** carry != 0

array\[size+1\] = carry % 10

carry = abrunden(carry / 10)

size++

**return** array
