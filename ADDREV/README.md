ADDREV 12.07.2015

Input:

NNumber of cases, written in first line ( N \<= 10000 )

x\[\], y\[\]Numbers of each case, written in the next lines ( unsigned
int )

Output

sumReversed sum of two reversed numbers x\[i\], y\[i\]

Problem:

Reversed Value of two numbers x and y have to be add together and
reversed. All leading zeros are omitted. ( e.g. 1200 gives 21). Also the
reversed number never has any trailing zeros ( e.g. ~~00021~~ ).

Algorithm:

*REVERSE-NUMBER(number)*

*reversed = 0*

*while number \> 0*

*reversed \*= 10*

*reversed += number mod 10*

*number = abrunden(number / 10)*

*result reversed*
