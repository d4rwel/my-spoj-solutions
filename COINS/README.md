COINS 26.07.2015

Algorithm ( only Recursion ) :

GET-EXCHANGE-COINS(count)

triple\[1\] = count div 2

triple\[2\] = count div 3

triple\[3\] = count div 4

triple.sum = triple\[1\] + triple\[2\] + triple\[3\]

return triple

global exchange = 0

COMPUTE-EXCHANGE(count)

triple = GET-EXCHANGE-COINS(count)

if triple.sum \<= count

exchange = exchange + count

else

COMPUTE-EXCHANGE(triple.\[1\])

COMPUTE-EXCHANGE(triple.\[2\])

COMPUTE-EXCHANGE(triple.\[3\])

Algorithm ( Recursion with Memoisation ):

Hashtable with trivial hash function and chaining with linked lists

MEMOIZE(count, triple)

**if **HashContains(triple\[1\])

triple\[1\] = HashGet(triple\[1\])

**else if **HashContains(triple\[2\])

triple\[2\] = HashGet(triple\[2\])

**else if** HashContains(triple\[3\])

triple\[3\] = HashGet(triple\[3\])

HashInsert(count, triple\[1\] + triple\[2\] + triple\[3\])

GET-EXCHANGE-COINS(count)

triple\[1\] = count div 2

triple\[2\] = count div 3

triple\[3\] = count div 4

triple.sum = triple\[1\] + triple\[2\] + triple\[3\]

return triple

global exchange = 0

COMPUTE-EXCHANGE(count)

triple = GET-EXCHANGE-COINS(count)

if HashContains(count)

exchange = exchange + HashGet(count)

else

if triple.sum \<= count

exchange = exchange + count

else

COMPUTE-EXCHANGE(triple.\[1\])

COMPUTE-EXCHANGE(triple.\[2\])

COMPUTE-EXCHANGE(triple.\[3\])

MEMOIZE(count, triple)
