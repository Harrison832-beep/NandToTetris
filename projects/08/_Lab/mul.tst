load mul.vm,
output-file mul.out,
//compare-to BasicLoop.cmp,
output-list RAM[0]%D1.6.1 RAM[256]%D1.6.1;

set sp 256,
set local 300,
set argument 400,

repeat 8 {
  vmstep;
}

output;