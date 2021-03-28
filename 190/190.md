task: one uint32_t is given, reverse it
solution: bit after bit, ans<<=1 and ans+=n&1 means get last bit to the front
n>>=1 means get rid of last bit and replace it with one single bit just a bit f-resher to it
