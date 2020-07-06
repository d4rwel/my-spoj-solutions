**STAMPS** 15.08.2015

Algorithm

COUNT-BORROWS(ArrayStamps, MinSum, CountFriends)

SORT(ArrayStamps)

// ArrayStamps is sorted max to min

Sum = 0

i = 0

while Sum \< MinSum and i \< CountFriends

Sum = Sum + ArrayStamps\[i\]

i = i + 1

if Sum \< MinSum

return i

else

return 0
