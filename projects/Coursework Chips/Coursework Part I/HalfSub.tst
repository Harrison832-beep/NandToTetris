load HalfSub.hdl,
output-file HalfSub.out,
compare-to HalfSub.cmp,
output-list x%B2.1.2 y%B2.1.2 borrow%B5.1.5 out%B3.1.3;

set x 0,
set y 0,
eval,
output;

set x 0,
set y 1,
eval,
output;

set x 1,
set y 0,
eval,
output;

set x 1,
set y 1,
eval,
output;
