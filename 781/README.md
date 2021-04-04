- task

gives an array, each number represents that a rabbit claims the number of its peers with the same color. return the minimum number of all the rabbits.

- official rating

medium

- solution

use a map, to calculate the number of rabbits which claim the same number. and use the final statistics to calculate the final result. core function : 

```cpp
sum+=((i.second-1) / (i.first+1)+1) * (i.first+1);
```

