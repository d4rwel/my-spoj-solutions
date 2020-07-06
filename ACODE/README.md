**ACODE** 06.08.2015

Algorithm

1\. Compute Fibonacci sequence till Fib(94).

2\. Slice *cipher *in permutable sequences. e.g. 136517201221129 =\>
(13)(17)(1221129)

3\. Take care of zeros, because they form just two decodings (10=J,
20=T).

There are no trailing or consecutive zeros!

4\. Multiply Fibonacci numbers resulting from every length of given
permutable sequences. e.g. Fib(length(13)) \* Fib(length(17)) \*
Fib(length(1221129)

5\. Product is the result.

*DECODE-CIPHER(cipher)*

i = 0

sequence\_length = 1

result = 1

**for** i = 0 **to** cipher.length

**if** cipher\[i\] \< 3 and cipher\[i\] \> 0

sequence\_length = sequence\_length + 1

**else **

**if** cipher\[i\] == 0

sequence\_length = sequence\_length -- 2

**if **sequence\_length == 0

sequence\_length = 1

result = result \* FIBONACCI(sequence\_length)

sequence\_length = 1

**return** result
