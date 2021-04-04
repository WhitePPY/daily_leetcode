- task

gives 2 string, return common substring(discontinuous is allowed).

- official rating

medium

- solution

dynamic program, 2-dim vector to record the length of the substring from the beginning to the current position. when char1 = char2 , dp\[i\]\[j\] =dp\[i-1\]\[j-1\]+1

