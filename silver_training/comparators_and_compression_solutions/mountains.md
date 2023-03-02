# solving information:
- reading:   ~ 2 minutes
- thinking:  ~ 40 minutes
- coding:    ~ 10 minutes
- debugging: ~ 10 minutes

# explanation:
## mathematical reasoning:
for a given mountain, m, with a peak of (m_x, m_y), we can think think of it as:  
y = -x + s  
  
where s = m_x + m_y.  
  
any point, p, whose coordinates', p_x and p_y, sum is less than or equal to s will fall within the mountain if:  
- p_y - p_x <= m_y - m_x  
  
if you're skeptical, try it out for any mountain. 
try to find a point whose sum is less than or equal to the sum of the peak whose "y - x" value is less than the peaks **and** is outside of that mountain.
I'm not going into deeper mathematical reasoning mostly because of the time it'd take.

## application  
we'd first start out by storing all the mountains in an array.
since we can use the equation between any pair of mountains where m_y + m_x > p_y + p_x, an intuitive continuation could be:
1. store each peak in an array, in ascending order of sums of coordinates
2. for every peak, iterate over all subsequent peaks in the array and check if any have a "y - x" value greater than the current peak
3. if there are no such peaks, add one to the current # of visible peaks  
  
the main flaw of this method is that it has a runtime of O(n^2), which would exceed the time limit

## revision
investigating the two components of this runtime, we have:
1. checking each mountain
2. checking whether or not each mountain's peak is visible
we can't not interate over some mountains. so, I tried to figure out how to reduce the runtime of checking if a mountain's peak is visible.
the first thought which came to mind was using .lower_bound() in a set or map, which has O(log n) runtime. 
this could work since, for any given mountain, we only care about the mountains whose peaks have a coordinate sum greater than it.
however, quickly locating where to start in the array would still require to check on the subsequent mountains.  
after thinking about this problem, if we're looking at a peak at one index, we only care about whatever subsequent mountain has the largest "y - x" value.

## final program
the program works as follows:
1. create a map to store each mountain. the key is the sum of the peak coordinates and the value is the "y - x" value of the peak
2. read in every peak. if a peak with the same sum is already present, keep the larger "y - x" value (the smaller lies on the right edge of the mountain with the peak of the larger)
3. determine whether each peak is visible, it is visible if it has the largest "y - x" of all elements to its right. we do this by maintaining a maximum value and comparing it to the current value in the key:value pair.
