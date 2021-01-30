load Exp16.hdl,
output-file Exp16.out,
compare-to Exp16.cmp,
output-list x%B1.16.1 y%B1.16.1 out%B1.16.1;

//2^5
set x %B0000000000000010,
set y %B0000000000000101,
eval,
output;

//8^2
set x %B0000000000001000,
set y %B0000000000000010,
eval,
output;

//9^1
set x %B0000000000001001,
set y %B0000000000000001,
eval,
output;

//9^5(overflow)
set x %B0000000000001001,
set y %B0000000000000101,
eval,
output;
