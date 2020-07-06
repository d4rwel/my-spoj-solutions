**NSTEPS** 12.07.2015

Input:

Nnumber of coordinates that will follow

x\[\], y\[\]x and y coordinates of the points

Output:

contentfor each point, write the number in the coordinate; write „No
Number" if there is none

Algorithm:

*IS-CONTENT-IN-COORDINATE(x,y)*

**if** x==y

**if** x mod 2==0

**result** 2\*x

**else**

**result** 2\*x-1

**elseif** x -- y == 2

**if **x mod 2 == 0

**result** x+y** **

**else**

**result** x+y-1

**else**

**result **No Number
