// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed.
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

// Set up pointer to screen
@SCREEN
D = A
@addr
M = D // addr = 16384
      // (screen's base address)
@i
M = 0 // i = 0

// RAM[0] = 8192
@8192
D = A
@R0
M = D

(LOOP)
	// set i back to 0
    	@i
    	M = 0

    	// if D != 0 (Key pressed) , blacken the screen
    	@KBD
    	D = M
    	@BLACKEN
    	D; JGT

    	// Otherwise, whiten the screen
    	@WHITEN
    	D; JEQ

(BLACKEN)
    	@i
    	D = M
    	@addr
    	A = M + D // goto memory pointer of SCREEN
	M = -1 // Blacken the whole row

	@i
	M = M + 1 // i ++
	D = M
	@R0
	D = D - M

	@BLACKEN
	D; JLT // if i<8192, goto BLACKEN

	@LOOP
	D; JEQ // goto LOOP

(WHITEN)
	@i
	D = M
	@addr
	A = M + D // Go to memory address of a row on SCREEN
	M = 0

	@i
	M = M + 1 // i ++
	D = M
	@R0
	D = D - M

    	// if i<8192, goto WHITEN
	@WHITEN
	D; JLT
	
	// goto LOOP
	@LOOP
	D; JEQ 

