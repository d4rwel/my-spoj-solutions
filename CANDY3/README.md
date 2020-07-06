**CANDY3** 25.07.2015

3 WAs because of bad specification. Constraints not given. OR bad use of
modulo. Better modulo every input, to keep output below INT\_MAX!!!

Algorithm

IS-CANDY-DIVIDABLE(numChild, ArrayCandy)

i = 0

sum = 0

**for **i = 1** to** ArrayCandy.length

sum = (sum mod numChild) + (ArrayCandy\[i\] mod numChild)

**if** sum mod numChild != 0

**return** false

**else**

**return** true
