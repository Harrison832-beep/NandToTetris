#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define L 1000	// Line
#define C 100	// Column


char engine[L][C];
int enSize = 0;


/*symbolTable routines:
constructor()
startSubroutine()
define()
VarCount()
KindOf()
TypeOf()
IndexOf()
*/

struct symbolTable {
	int scope;
	char name[50];
	char type[50];
	char kind[50];
	unsigned int index;
	struct symbolTable* next;
};

typedef struct symbolTable SymbolTable;


void readXML(FILE*);

int createSymbolTableList(int loc, int scope, SymbolTable** sPtr);
void appendList(SymbolTable** sPtr, int scope, char kind[], char type[], char name[], unsigned int index);
int VarCount(char kind[], int scope, SymbolTable* sPtr);
void printList(SymbolTable* start);
void freeSubroutine(SymbolTable** start);
void removeHashTag(char str[]);

/*VMWriter routines:
constructor
writePush
writePop
writeArithmetic
writeLabel
writeGoto
writeIf
writeCall
writeFunction
writeReturn
close
*/


char VMcode[L][C];
int VMsize = 0;

void VMConstructor(char vmName[]) {
	FILE* vmPtr = fopen(vmName, "w");
	if (vmPtr == NULL) {
		puts("Unable to open vm file.");
	}
	else {
		for (int i = 0; i < VMsize; i++) {
			fprintf(vmPtr, "%s\n", VMcode[i]);
		}

		fclose(vmPtr);
	}


}
void VMWriter();
int writeFunction(int loc, SymbolTable** sPtr);
int writeCall(int loc, SymbolTable* sPtr);
int codeWrite(int loc, SymbolTable* sPtr);
int writePush(int loc, SymbolTable* sPtr);
void writePop(char varName[], SymbolTable** sPtr);
void writeArithmetic(char op, int opLoc);
void writeReturn(int voidFunction);

int main(void) {
	char* fileName = "Main";
	char xmlFileName[30];
	char vmFileName[30];

	strcpy(vmFileName, fileName);
	strcpy(xmlFileName, fileName);

	// Concatenate ".vm" to vmFileName[]
	strcat(vmFileName, ".vm");

	// Concatenate "_My.xml" to xmlFile[]
	strcat(xmlFileName, "_My.xml");

	// Open xml file
	FILE* xmlPtr = fopen(xmlFileName, "r");

	if (xmlPtr == NULL) {
		puts("Fail to open xml file.");
	}
	else {
		// BEGIN

/***************************************************************************************************************************
****************************************************************************************************************************/

		// readXML()
		puts("Enter readXML()");
		readXML(xmlPtr);
		puts("Exit readXML()");
		
		// TEST
		/*for (int i = 0; i < enSize; i++) {
			printf("%s", engine[i]);
		}*/

/***************************************************************************************************************************
****************************************************************************************************************************/

		// VMWriter()
		puts("Enter VMWriter()");
		VMWriter();
		puts("Exit VMWriter()");

		// VMConstructor()
		puts("Enter VMConstructor() (main())");
		VMConstructor(vmFileName);
		puts("Exit VMConstructor() (main())");

		fclose(xmlPtr);
	}


	// Return to OS
}

/*
**********************************************************************************************************************************************
**********************************************************************************************************************************************
*/

void readXML(FILE* xml) {
	// Put all content to engine[][]
	char read[100];

	fgets(read, 100, xml);
	while (!feof(xml)) {
		
		strcpy(engine[enSize], read);
		enSize++;

		fgets(read, 100, xml);
	}


}


void VMWriter() {
	SymbolTable* startPtr = NULL;

	// Scope, 1 for Class-Level
	// Other for Subroutine-Level
	int scope = 0;
	int i;
	int voidFunction = 0;
	int itsMethod = 0;

	// Loop through engine[][]
	for (i = 0; i < enSize; i++) {
		

		// For class-level, use iteration
		// If "<classVarDec>", scope = Class-Level
		// End when "</classVarDec>"
		if (strstr(engine[i], "<classVarDec>")) {
			scope = 1;
			
			// Call createSymbolTableList()
			// For parameterList
			puts("Enter createSymbolTableList() <classVarDec>");
			i = createSymbolTableList(i, scope, &startPtr);
			puts("Exit createSymbolTableList() <classVarDec>");

			printList(startPtr);
		}
		

		// Subroutine level
		// Might use recursive function for nested-scopes
		// If "<varDec> OR "<parameterList>" OR "method", scope = 2
		if (strstr(engine[i], "<subroutineDec>")) {
			// Start subroutine
			// Free the previous subroutine list
			freeSubroutine(&startPtr);
			puts("Free subroutine:");
			printList(startPtr);
			
			// Reset voidFunction
			voidFunction = 0;
			// Reset itsMethod
			itsMethod = 0;

		}
		
		// If "<parameterList>" OR "<varDec>" scope = 2 
		// And call createSymbolTableList()
		if (strstr(engine[i], "<varDec>")) {
			scope = 2;

			puts("Enter createSymbolTableList() <varDec>");
			i = createSymbolTableList(i, scope, &startPtr); //Call createSymbolTableList()
			puts("Exit createSymbolTableList() <varDec>");

			printList(startPtr);
		}

			
		

	// End of basic symbolTable
/*************************************************************************************************************************************/
	// Write VM code
		// If "function" OR "constructor" OR "method"
		// writeFunction()
		if (strstr(engine[i], "function") || strstr(engine[i], "constructor") || strstr(engine[i], "method")) {
			// If next token is "void", record as void
			if (strstr(engine[i], "void")) {
				voidFunction = 1;
			}
			// If "method", write THIS
			if (strstr(engine[i], "method")) {
				itsMethod = 1;
				// Create string to copy class name
				char className[C];
				strcpy(className, engine[2]);
				removeHashTag(className);
				appendList(&startPtr, 2, "argument", className, "this", 0);
			}
				
			// Write function
			puts("Enter writeFunction()(VMWriter()");
			i = writeFunction(i, &startPtr);
			puts("Exit writeFunciton()(VMWriter())");

			if (itsMethod) {
				// Push argument = and Pop pointer 0
				sprintf(VMcode[VMsize], "%s", "push argument 0");
				VMsize++;
				sprintf(VMcode[VMsize], "%s", "pop pointer 0");
				VMsize++;
			}

		}


		// let statement
		// If "let", loop until ';'
		if (strstr(engine[i], "<keyword> let </keyword>")) {
			char varName[C];
			// Token after "let" is the variable name that needs to be poped
			strcpy(varName, engine[i+1]);
			removeHashTag(varName);
#if 0
			printf(varName);
			exit(0);
#endif // 0

			while (strchr(engine[i], ';') == NULL) {
				i++;
				// If "<expression>"
				// codeWrite()
				if (strstr(engine[i], "<expression>")) {
					puts("Enter codeWrite().(let)");
					i = codeWrite(i, startPtr);
					puts("Exit codeWrite().(let)");
				}
				
				// End of while loop
			}
			// When exit while loop write pop
			// writePop()
				puts("Enter writePop().(let)");
				writePop(varName, &startPtr);
				puts("Exit writePop().(let)");
#if 1
				static int count = 0;
				count++;
				if (count == 2) {
					for (int i = 0; i < VMsize; i++) {
						printf("%s\n", VMcode[i]);
					}
					printf("current token: %s\n", engine[i]);
					exit(0);
				}
#endif // 0
		}



		// do statement
		// If "do", write function name and write function call
		if (strstr(engine[i], "<keyword> do")) {
			while (strchr(engine[i], ';') == NULL) {
				i++;
				// If '.'
				// Call writeCall()
				if (strchr(engine[i], '.')) {
					puts("Enter writeCall().(do)");
					i = writeCall(i, startPtr);
					puts("Exit writeCall().(do)");
				}

				// End of while loop
			}
		}



		// writeReturn()
		// If "return", write return
		if (strstr(engine[i], "<keyword> return")) {
			puts("Enter writeReturn() (VMWriter())");
			writeReturn(voidFunction);
			puts("Exit writeReturn() (VMWriter())");
			i++;
		}



		//Branching


		// End of for Loop
	}

	// Return to main()
}

/*
This function will return every time it meets ';'
This function will return the current location of the OCompilationEngine[][]
*/
int createSymbolTableList(int loc, int scope, SymbolTable** sPtr) {
	// Kindof, typeOf and index
	char kindOf[50];
	char typeOf[50];
	char nameOf[50];
	unsigned int index;

	int openBraceDetected = 0;
	

	// Loop
	while (loc < enSize) {

		// If the scope is Class-Level
		// Create Class-Level list
		if (scope == 1) {
			// Write Class Level
			while (loc < enSize) {

				// In class, the kind follows <classVarDec>
				// Write name, type, kind and index
				// If "static" OR "field", put in kind

				if (strstr(engine[loc], "static") || strstr(engine[loc], "field")) {
					sprintf(kindOf, "%s", engine[loc]);
					// The next token is type
					loc++;
					sprintf(typeOf, "%s", engine[loc]);
					loc++;
				}

				// Next is name (Could be multiple names)
				// If "<identifier>", define
				// Check if there is any name of the same kind
				// Then determine the index
				if (strstr(engine[loc], "<identifier>")) {
					// Write nameOf[]
					sprintf(nameOf, "%s", engine[loc]);
					loc++;

					// Call VarCount(), return count to index
					index = VarCount(kindOf, scope, *sPtr);


					// Finish one element
					removeHashTag(nameOf);
					removeHashTag(typeOf);
					removeHashTag(kindOf);

					appendList(sPtr, scope, kindOf, typeOf, nameOf, index);
				}

				// If ','


				// If ';', exit createSymbolTableList()
				if (strchr(engine[loc], ';')) {
					return loc;
				}

				// Advance
				loc++;
				// End of Class-Level
			}
		}

		// If the scope is Subroutine-Level
		// Create Subroutine-Level List

		// Arguments follow "<parameterList>"
		// In subroutine type follows keyword "var"
		// The kind is local
		else {
			// Write Subroutine Level

				// ARG
				if (strstr(engine[loc], "<parameterList>")) {
					while (loc < enSize) {
						
						if(strstr(engine[loc], "<keyword>")) {
							sprintf(kindOf, "argument");
							index = VarCount(kindOf, scope, *sPtr);

							// Because this loop is entered with "<parameterList>"
							// Therefore, the next token should be type
							// Write type

							if (strstr(engine[loc], "<keyword>")) {
								sprintf(typeOf, "%s", engine[loc]);
								loc++;
							}
							else {
								puts("Error when wrting type! (ParameterList)");
								exit(-1);
							}

							// Next is name
							if (strstr(engine[loc], "<identifier>")) {
								// Write name
								// ',' or ';' after the name
								sprintf(nameOf, "%s", engine[loc]);
								loc++;

								removeHashTag(typeOf);
								removeHashTag(nameOf);

								// Add to list
								appendList(sPtr, scope, kindOf, typeOf, nameOf, index);
							}
							else {
								puts("Error when wrting name! (ParameterList)");
								exit(-1);
							}
						} 
						

						// If ',', finish one and start a new one
						if (strchr(engine[loc], ',')) {
							loc++; // Get the type
							while (strstr(engine[loc], "</parameterList>") == NULL) {
								// Write type
								if (strstr(engine[loc], "<keyword>")) {
									sprintf(typeOf, "%s", engine[loc]);
									removeHashTag(typeOf);
									loc++;

									// Next is name
									if (strstr(engine[loc], "<identifier>")) {
										sprintf(nameOf, "%s", engine[loc]);
										removeHashTag(nameOf);
										index++;
										appendList(sPtr, scope, kindOf, typeOf, nameOf, index);
									}
								}

								loc++; // Advance
								// End of while Loop
							}
						}

						// If "</parameterList>", finish one and Exit
						if (strstr(engine[loc], "</parameterList>")) {
							return loc;
						}

						loc++;
						// End of while loop
					}
				}
				else
				// LCL
				if (strstr(engine[loc], "<varDec>")) {

					// If another scope within subroutine
					// Call recursive function
					if (openBraceDetected) {
						scope++;
						createSymbolTableList(loc, scope, sPtr);
					}
					else {
						while (loc < enSize) {

							if (strstr(engine[loc], "<varDec>")) {
								loc += 2; // Skip <varDec> and "var" to get the type
							}

							// Write kind, and index
							strcpy(kindOf, "local");

							puts("Enter VarCount");
							index = VarCount(kindOf, scope, *sPtr);
							puts("Exit VarCount");

							// Write type
							sprintf(typeOf, "%s", engine[loc]);
							loc++;

							// Next is name
							if (strstr(engine[loc], "<identifier>")) {
								// Write name
								sprintf(nameOf, "%s", engine[loc]);
								loc++;

								removeHashTag(typeOf);
								removeHashTag(nameOf);

								// Add to list
								appendList(sPtr, scope, kindOf, typeOf, nameOf, index);
							}
							else {
								puts("Error when wrting name! (localVar)");
								exit(-1);
							}

							// If '{', open curly brace detected, look out for another "<varDec>"
							// If there is one, call recursive function
							if (strchr(engine[loc], '{')) {
								openBraceDetected = 1;
							}

							// If ',', advance one to get name and increment index
							if (strchr(engine[loc], ',')) {
								loc++; // Get the name
								while (strchr(engine[loc], ';') == NULL) {
									if (strstr(engine[loc], "<identifier>")) {
										sprintf(nameOf, "%s", engine[loc]);
										removeHashTag(nameOf);
										index++;
										appendList(sPtr, scope, kindOf, typeOf, nameOf, index);
									}

									loc++; // Advance
									// End of while Loop
								}
							}

							// If ';', return
							if (strchr(engine[loc], ';')) {
								return loc;
							}

							// Advance
							loc++;

						}
					}
				}
				else {
					puts("Error when writing symbolTable, should be one of <classVar>, <parameterList> or <varDec> when called!");
				}

			// End of Subroutine level
		}
		// End of while Loop
	}

	puts("Error when writing symbolTable, should never reach the end!");
	exit(EXIT_FAILURE);
	return loc;
	// Return to VMWriter()
}

void appendList(SymbolTable** sPtr, int scope, char kind[], char type[], char name[], unsigned int index) {
	// Initialise all the structure pointers
	SymbolTable* newPtr = (SymbolTable*)malloc(sizeof(SymbolTable));
	SymbolTable* curPtr = *sPtr;
	SymbolTable* prePtr = NULL;

	newPtr->scope = scope;
	strcpy(newPtr->kind, kind);
	strcpy(newPtr->type, type);
	strcpy(newPtr->name, name);
	newPtr->index = index;
	newPtr->next = NULL;

	//If sPtr is NULL, create start point
	if (curPtr == NULL) {
		puts("Start point created.");
		*sPtr = newPtr;
	}
	else {
		while (curPtr != NULL) {
			// Next
			prePtr = curPtr;
			curPtr = curPtr->next;
		}

		prePtr->next = newPtr;
	}

	// Return to createSymbolTableList()
}

/*
This function will return the index
*/
int VarCount(char kind[], int scope, SymbolTable* sPtr) {
	unsigned int count = 0;

	// If the list is NULL, exit directly
	while (sPtr != NULL) {
		// If the same kind and same scope
		// count ++
		if (strstr(kind, sPtr->kind) && sPtr->scope == scope) {
			count++;
		}

		// Next
		sPtr = sPtr->next;
		// End of while Loop
	}

	return count;
	// Return to createSymbolTableList()
}

void printList(SymbolTable* start) {

	printf("\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "Scope", "Name", "Type", "Kind", "Index");
	while (start != NULL) {

		printf("%u\t\t%s\t\t%s\t\t%s\t\t%u\n", start->scope, start->name, start->type, start->kind, start->index);

		start = start->next;
	}
}

void freeSubroutine(SymbolTable** start) {
	SymbolTable* tempPtr = NULL;
	SymbolTable* cur = *start;
	SymbolTable* pre = NULL;

	while (cur != NULL) {
		if (cur->scope != 1) {
			tempPtr = cur->next;
			free(cur);
			cur = tempPtr;
		}
		else {
			pre = cur;
			cur = cur->next;
		}

		// End of loop
	}

	if (pre != NULL) {
		pre->next = NULL;
	}
	else {
		*start = NULL;
	}
}


void removeHashTag(char str[]) {
	char strProcessed[100];

	int j = 0;
	for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
		// If '>' advance one and start copying string
		if (str[i] == '>') {
			i += 2;
			// Stop at '<', and set white space to '\0'
			for (j = 0; str[i+1] != '<'; j++) {
				// Copy string
				strProcessed[j] = str[i];
				i++;
			}
			
			// Set white space to '\0'
			strProcessed[j] = '\0';
			strcpy(str, strProcessed);

			break;
		}

		// End of for Loop
	}

	// Return to createSymbolTableList()
}


// End of SymbolTable routines
/******************************************************************************************************************************
*******************************************************************************************************************************/
// Write VM commands


int writeFunction(int loc, SymbolTable** sPtr) {
	char functionName[C];
	char className[C];
	int paraCount = 0;
	char paraCountStr[10];

	// After writing function name, return
	// If "<identifier>"
	// Write function name

	// First write "function " to VMcode[][]
	sprintf(VMcode[VMsize], "%s", "function ");

	while (strstr(engine[loc], "<subroutineBody>") == NULL) {
		if (strstr(engine[loc], "<identifier>")) {
			// Concatenate class name
			// Copy class name
			strcpy(className, engine[2]);
			removeHashTag(className);
			strcat(VMcode[VMsize], className);

			// Concatenate '.'
			strcat(VMcode[VMsize], ".");

			// Concatenate function name
			// Copy in order not to change the engine[][]
			strcpy(functionName, engine[loc]);
			removeHashTag(functionName);
			strcat(VMcode[VMsize], functionName);

			

		}

		// If "<parameterList>", scope = 2 
		// And call createSymbolTableList()
		// Count parameters
		if (strstr(engine[loc], "<parameterList>")) {
			

			puts("Enter createSymbolTableList() <parameterList> or <varDec>");
			loc = createSymbolTableList(loc, 2, sPtr); //Call createSymbolTableList()
			puts("Exit createSymbolTableList() <parameterList> or <varDec>");

			// When it's done writing symbolTable
			// Count parameters
			SymbolTable* curPtr = *sPtr;
			while (curPtr != NULL) {
				if (strstr(curPtr->kind, "argument")) {
					paraCount++;
				}

				curPtr = curPtr->next;
				//End of while loop
			}

			// Concatenate parameter number
			sprintf(paraCountStr, " %d", paraCount);
			strcat(VMcode[VMsize], paraCountStr);

			// Increase VMsize
			VMsize++;
		}




		// Advance
		loc++;
	}
	
	return loc;
}


int writeCall(int loc, SymbolTable* sPtr) {
	char functionName[C] = { "call " };
	char part1[C];
	char part2[C];
	char part3[C];
	int argCount = 0;

	puts("start writing functionName");
	// In do statement
	// The next is part1 of the function
	// Remember function name first, then write call
	// Exit when ';'
	// Copy first part of function name
	strcpy(part1, engine[loc-1]);
	// Copy '.'
	strcpy(part2, engine[loc]);
	// Copy last part of function name
	strcpy(part3, engine[loc+1]);

	removeHashTag(part1);
	removeHashTag(part2);
	removeHashTag(part3);
	strcat(functionName, part1);
	strcat(functionName, part2);
	// Complete functionName[]
	strcat(functionName, part3);
	

	// Write all expressions
	while (strstr(engine[loc], "</expressionList>") == NULL) {
		// If "<expression>" begin codeWrite()
		if (strstr(engine[loc], "<expression>")) {
			argCount++;
			loc = codeWrite(loc, sPtr);
		}
		
		loc++;
		// End of while loop
	}

	// Write call functionName argCount
	// Concatenate argCount
	sprintf(VMcode[VMsize], "%s %d", functionName, argCount);
	VMsize++;


	return loc;
}

int codeWrite(int loc, SymbolTable* sPtr) {
	// OperandList
	char operandList[6] = {'+', '-', '*', '/', '~', '\0' };
	char op = '\0';
	int opLoc = 0;
	// A copy to remove hash tag so that there won't be </...>
	char copy[C];

	// Because we enter with <expression>, need to advance over
	loc++;

	while (strstr(engine[loc], "</expression>") == NULL) {
		// If "<expression>", recursive
		if (strstr(engine[loc], "<expression>")) {
			loc = codeWrite(loc, sPtr);
			loc++; // Advance over </expression>
		}

		// If "<symbol>", search operandList[]
		if (strstr(engine[loc], "<symbol>")) {
			strcpy(copy, engine[loc]);
			removeHashTag(copy);

			for (int i = 0; operandList[i] != '\0'; i++) {
				// If operand +-*/~, write it in op[], use it when exit loop
				// Remember the location when it is found
				if (operandList[i] == copy[0]) {
					op = copy[0];
					opLoc = loc;
				}
			}
			

		}

		// If "<integerConstant>" OR "<identifier>" OR "true" OR "false" OR "null"
		if (strstr(engine[loc], "<integerConstant>") || strstr(engine[loc], "<identifier>") ||
			strstr(engine[loc], "true") || strstr(engine[loc], "false") || strstr(engine[loc], "null")) {
			// If '.'
			// writeCall()
			if (strstr(engine[loc], "<identifier>") && strchr(engine[loc + 1], '.')) {
				puts("Enter writeCall().(codeWrite())");
				loc = writeCall(loc + 1, sPtr); // loc+1 so that passed loc is '.'
				puts("Exit writeCall().(codeWrite())");
			}
			// writePush()
			else {
				puts("Enter writePush().(codeWrite())");
				loc = writePush(loc, sPtr);
				puts("Exit writePush().(codeWrite())");
			}

		}

		loc++;
		// End of while loop
	}

	// After exiting while loop
	// writeArithmetic()
	if (op != 0) {
		puts("Enter writeArithmetic() (codeWrite())");
		writeArithmetic(op, opLoc);
		puts("Exit writeArithmetic() (codeWrite())");
	}

	return loc;
}


int writePush(int loc, SymbolTable* sPtr) {
	char intConst[C];
	//char variable[C];

	// If it's a constant, push directly
	if (strstr(engine[loc], "<integerConstant>")) {
		strcpy(intConst, engine[loc]);
		removeHashTag(intConst);
		// Write Push
		sprintf(VMcode[VMsize], "push constant %s", intConst);
		VMsize++;
	}
	// Else, if "true", push constant 1 and neg
	else if (strstr(engine[loc], "true")) {
		sprintf(VMcode[VMsize], "%s", "push constant 1");
		VMsize++;
		sprintf(VMcode[VMsize], "%s", "neg");
		VMsize++;
	}
	// Else, if "false" OR "null", push constant 0
	else if (strstr(engine[loc], "false") || strstr(engine[loc], "null")) {
		sprintf(VMcode[VMsize], "%s", "push constant 0");
		VMsize++;
	}
	// Else, it's a variable, look up the symbolTable
	else {
		while (sPtr != NULL) {
			//If name found, write push
			//Then return
			if (strstr(engine[loc], sPtr->name)) {
				sprintf(VMcode[VMsize], "push %s %d", sPtr->kind, sPtr->index);
				VMsize++;

				return loc;
			}

			sPtr = sPtr->next;
			//End of while loop
		}
		
		// CANNOT REACH HERE!
		puts("Error when writing push command, variable not found in symbolTable!");
		printf("Current token: %s", engine[loc]);
		exit(-1);
	}

	return loc;
}


void writePop(char varName[], SymbolTable** sPtr) {
	SymbolTable* curPtr = *sPtr;

	// Search symbolTable
	while (curPtr != NULL) {
		//If varName found, write pop command
		if (strstr(curPtr->name, varName)) {
			sprintf(VMcode[VMsize], "pop %s %d", curPtr->kind, curPtr->index);
			VMsize++;
			return;
		} 

		curPtr = curPtr->next;
		// End of while loop
	} 

	// CANNOT REACH HERE!
	puts("Error when writing pop command, variable not found in list");
	printf("current varName: %s", varName);
	exit(-1);
}


void writeArithmetic(char op, int opLoc) {
	// '+', add
	if (op == '+') {
		sprintf(VMcode[VMsize], "%s", "add");
		VMsize++;
		return;
	}
	// '-', sub or neg
	if (op == '-') {
		// If "<identifier>" OR "<integerConstant>" two tokens before
		// sub
		if (strstr(engine[opLoc - 2], "<identifier>") || strstr(engine[opLoc - 2], "<integerConstant>")) {
			sprintf(VMcode[VMsize], "%s", "sub");
			VMsize++;
			return;
		}
		else {
			sprintf(VMcode[VMsize], "%s", "neg");
			VMsize++;
			return;
		}
	}
	// '~', not
	if (op == '~') {
		sprintf(VMcode[VMsize], "%s", "not");
		VMsize++;
		return;
	}
	// '*', Math.multiply()
	if (op == '*') {
		sprintf(VMcode[VMsize], "%s", "call Math.multiply 2");
		VMsize++;
		return;
	}
	// '/', writecall() for Math.divide()
	if (op == '/') {
		sprintf(VMcode[VMsize], "%s", "call Math.divide 2");
		VMsize++;
		return;
	}
	// CANNOT REACH HERE
	puts("op is empty!");
	exit(-1);
	return;
}


void writeReturn(int voidFunction) {
	// If voidFunction, write "push constant 0"
	if (voidFunction) {
		sprintf(VMcode[VMsize], "%s", "push constant 0");
		VMsize++;
	}
	sprintf(VMcode[VMsize], "%s", "return");
	VMsize++;


}