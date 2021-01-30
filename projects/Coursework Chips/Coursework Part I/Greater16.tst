
load Greater16.hdl,
output-file Greater16.out,
compare-to Greater16.cmp,
output-list x%B1.16.1 y%B1.16.1 out%B1.16.1;

set x %B0000000000000000,
set y %B0000000000000000,
eval,
output;

set x %B0000000000000000,
set y %B0000000000000001,
eval,
output;

set x %B0111111111111111,
set y %B0000000000000000,
eval,
output;

set x %B1111111111111111,
set y %B1111111111111111,
eval,
output;