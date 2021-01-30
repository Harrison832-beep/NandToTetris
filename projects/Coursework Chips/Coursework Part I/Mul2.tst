load Mul2.hdl,
output-file Mul2.out,
compare-to Mul2.cmp,
output-list in%B1.16.1 out%B1.16.1;

set in %B0000000000000000,
eval,
output;

set in %B0000000000000001,
eval,
output;

set in %B1111111111111111,
eval,
output;

set in %B1010101010101010,
eval,
output;

set in %B1110011001100111,
eval,
output;
