**FCTRL** 11.07.2015

<http://www.spoj.com/problems/FCTRL/>

http://www.mathe-seiten.de/fakultaet.pdf

Berechnet die Anzahl der Nullen einer Fakultät n!

COMPUTE-TRAILING-ZEROS(N)

k=1

summe = 0

// k ist Anzahl der Vielfachen von 5 im Produkt

// der Fakultät von N!

**while** (N mod 5\^k) != N

k++

**for **i=1 **to **i \<** **k

summe = summe + abrunden(N/5\^i)

**result **summe** **
