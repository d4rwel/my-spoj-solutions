TOANDFRO 14.07.2015

http://www.spoj.com/problems/TOANDFRO/

Input

Multple input sets constisting of two lines:

nNumber of columns used ( 2 \<= n \<= 20 )

strCiphertext to be decoded ( max length 200 )

Output

resultPlaintext

Algorithm

DECODE(cipher, columns)

j = 0

plaintext.length = cipher.length

for i = 0 to columns -- 1

offset = i

flag = 0

while offset \<= plaintext.length

plaintext\[j\] = cipher\[offset}

if flag % 2 == 0

offset += 2 \* (columns - i) - 1

else

offset += 2 \* i + 1

j++

flag++
