load Exp1.hdl,
output-file Exp1.out,
compare-to Exp1.cmp,
output-list x%B1.16.1 y%B1.1.1 out%B1.16.1;

set x %B0000000000000000,
set y 0,
eval,
output;

set x %B0000000111111110,
set y 0,
eval,
output;

set x %B0111111111111111,
set y 0,
eval,
output;

set y 1,
eval,
output;