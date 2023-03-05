# solving information
- reading: ~1 minute
- thinking: ~3 minutes
- coding: ~6 minutes

# explanation:
[link to problem](https://atcoder.jp/contests/abc202/tasks/abc202_c)  
this problem asks for the # of unique pairs for $i$ and $j$ which fulfill the equation $A_i=B_{C_j}$.  
 for some possible value of $B_{C_j}$, if there are $n$ values of $i$ such that $A_i=B_{C_j}$ and $m$ values of
 $j$ in $C$, then there are $nm$ different combinations of $i$ and $j$ which satisfy that expression for $B_{C_j}$
   
 so, we store the # of times a number appears in $A$ in a map, with the key being the # and the value being the # of times it appears.  
 we then do the same for $C$.  
 after storing this information, I iterate over each index of $B$ and see if:
 1. there are any values $i$ such that $A_i$ = the current index and count how many by looking it up in the map
 2. how many times that index can be found in $C$
   
 then, I add the product of the two to a variable which stores the total # of pairs
