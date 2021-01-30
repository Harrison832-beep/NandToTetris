
load Signal16.hdl,
output-file Signal16.out,
compare-to Signal16.cmp,
output-list in%B1.16.1 out%B2.1.2;

set in %B0000000000000000,  
eval,
output;

set in %B1111111111111111,  
eval,
output;

set in %B0000000000000101,  
eval,
output;

set in %B1111111111111011,  
eval,
output;
