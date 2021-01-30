load Div16.hdl,
output-file Div16.out,
compare-to Div16.cmp,
output-list in%B1.16.1 out%B1.16.1;

set in %B0000000000000001, 
eval,
output;

set in %B1111111111111111,  
eval,
output;

set in %B0000000000000100, 
eval,
output;

set in %B1111111111111011,  
eval,
output;
