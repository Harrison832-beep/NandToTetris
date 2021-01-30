load CWALU.hdl,
output-file CWALU.out,
compare-to CWALU.cmp,
output-list x%B1.16.1 y%B1.16.1 S%B1.1.1 M%B1.1.1 D%B1.1.1 
            F%B1.1.1  GL%B1.1.1 load%B1.1.2 address%B1.14.1 out%B1.16.1 of%B1.1.1;

set x %B0000000000000101,  // x = 5
set y %B0000000000000010;  // y = 2

//Compute Subtraction
set S  1,
set M  0,
set D  0,
set F  0,
set GL 0,
set load 0,
set address %B00000000000000,
tick,
output;

tock,
output;	//3

//Compute Multiplication
set S  0,
set M  1,
set D  0,
set F  0,
set GL 0,
set load 0,
set address %B00000000000001,
tick,
output;

tock,
output;	//10

//Compute Division
set S  0,
set M  0,
set D  1,
set F  0,
set GL 0,
set load 0,
set address %B00000000000010,
tick,
output;

tock,
output;	//2

//Compute Exponential
set S  0,
set M  0,
set D  0,
set F  1,
set GL 0,
set load 0,
set address %B00000000000011,
tick,
output;

tock,
output;	//25

//Compute Greater Than
set S  0,
set M  0,
set D  0,
set F  0,
set GL 1,
set load 0,
set address %B00000000000100,
tick,
output;

tock,
output;	//1

set x %B0000000000000010,  // x = 2
set y %B0000000000000011;  // y = 3

//Compute Greater Than
set S  0,
set M  0,
set D  0,
set F  0,
set GL 1,
set load 0,
set address %B00000000000101,
tick,
output;

tock,
output;	//-1

//Compute Subtraction
set S  1,
set M  0,
set D  0,
set F  0,
set GL 0,
set load 0,
set address %B00000000000110,
tick,
output;

tock,
output;	//-1

set y %B0000000000001111;  // y = 15

//Compute Subtraction
set S  1,
set M  0,
set D  0,
set F  0,
set GL 0,
set load 0,
set address %B00000000000111,
tick,
output;

tock,
output;	//-12



//Load the data stored in the previous operations and do computations again

set x %B0000000000000000,  // x = 0
set y %B0000000000000010;  // y = 2

//Compute Subtraction
//x=3
set S  1,
set M  0,
set D  0,
set F  0,
set GL 0,
set load 1,
set address %B00000000000000,
tick,
output;

tock,
output;	//1	

//Compute Multiplication
//x=10
set S  0,
set M  1,
set D  0,
set F  0,
set GL 0,
set load 1,
set address %B00000000000001,
tick,
output;

tock,
output;	//20

//Compute Division
//x=2
set S  0,
set M  0,
set D  1,
set F  0,
set GL 0,
set load 1,
set address %B00000000000010,
tick,
output;

tock,
output;	//1

//Compute Exponential
//x=25
set S  0,
set M  0,
set D  0,
set F  1,
set GL 0,
set load 1,
set address %B00000000000011,
tick,
output;

tock,
output;	//625

//Compute Greater Than
//x=1
set S  0,
set M  0,
set D  0,
set F  0,
set GL 1,
set load 1,
set address %B00000000000100,
tick,
output;

tock,
output;	//-1

