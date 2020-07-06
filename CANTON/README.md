**CANTON** 06.08.2015

Algorithm

GET-CANTOR-COUNT(number)

dividend = 1

divisor = 1

// -1 is up, 1 is down

direction = -1

**while** number != 1

**if** dividend == 1 **and** direction == -1

divisor = divisor + 1

direction = 1

***else** **if **divisor == 1 **and** direction == 1*

dividend = dividend + 1

*direction = -1*

**else**

dividend = dividend + direction

divisor = divisor -- direction

**// ONLY FOR REAL CANTORS COUNT**

**// if **IS-CANTOR-COUNT(dividend, divisor)

// number = number -- 1

number = number -- 1

**return **dividend, divisor

// only for real Cantors Count

IS-CANTOR-COUNT(dividend, divisor)

**if **dividend == 1 or divisor == 1

**return** true

**if** dividend % divisor == 0 **or** divisor % dividend == 0

**return** false

**else**

**return **true
