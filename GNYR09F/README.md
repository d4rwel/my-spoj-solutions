GNYR09F 11.07.2015

http://www.spoj.com/problems/GNYR09F/

Count-Satisfying-Bitstrings berechnet die Anzahl der Bitstrings x mit
der Länge n, welche AdjBC(X) = k erfüllen.

AdjBC(X) = X1\*X2 + X2\*X3 +\...+ X(n-1)\*Xn

Bruteforce Approach:

1.  erstelle Bit-Array der Länge x
2.  fülle das Bit-Array mit jedem möglichen Bitmuster
3.  wenn AdjBC des aktuellen Bit-Array-Musters gleich k dann erhöhe x
4.  wenn jedes mögliche Bit-Array-Muster durchlaufen, dann gib x aus
5.  fertig

COUNT-SATISFIYING-BITSRINGS(n, k)

x = 0

// Bit-Array: jedes Element kann nur 1 oder 0 sein

erstelle BitArray mit der Länge n

initialisiere BitArray mit Nullen

**for** i = 1 **to** n

Dynamische Programmierung??
