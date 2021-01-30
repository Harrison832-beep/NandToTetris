
load FullSub.hdl,
output-file FullSub.out,
compare-to FullSub.cmp,
output-list x%B1.1.1 y%B1.1.1 b%B1.1.1 borrow%B4.1.4 out%B2.1.2;

set x 0,
set y 0,
set b 0,
eval,
output;

set b 1,
eval,
output;

set y 1,
set b 0,
eval,
output;

set b 1,
eval,
output;

set x 1,
set y 0,
set b 0,
eval,
output;

set b 1,
eval,
output;

set y 1,
set b 0,
eval,
output;

set b 1,
eval,
output;