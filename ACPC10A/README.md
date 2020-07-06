**ACPC10A** 14.07.2015

Input

(x1, x2, x3)Three integers as a sequence (-10,000 \< x1, x2, x3 \<
10,000), where x1 != x2 != x3

Output

XX yXX is either AP (arithmetic progression) or GP (geometric
progression); y is next number in the sequence

Problem

Find out whether sequence (x1, x2, x3) is AP or GP, and determine x4.

AP = difference of any two successive members is a constant

e.g. 3, 5, 7 =\> 2 is the common difference

GP = each term after the first is found by multiplying the previous

e.g. 2, 6, 18 =\> 3 is the common ratio

Find common difference or ratio for a sequence (x1, x2, x3)!

Algorithm

1.  If x3 -- x2 = x2 -- x1, then AP
2.  Else GP

*DETERMINE-SEQUENCE(x1, x2, x3)*

*if x2 -- x1 == x3 -- x2*

*// sequence is AP*

*x4 = x3 -- x2*

*else*

*// sequence is GP*

*x4 = x3 % x2*
