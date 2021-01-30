#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define L 100000	// Line
#define C 1000	// Column

char keywords[21][100] = { "class", "constructor", "function", "method", "field", "static", "var", "int", "char", "boolean",
								"void", "true", "false", "null", "this", "let", "do", "if", "else", "while", "return" };
char sym[100] = "{}()[].,;+-*&|<>=~/";

enum tokenType {KEYWORD = 1, SYMBOL, IDENTIFIER, INT_CONST, STRING_CONST};
enum keyWord {CLASS = 1, METHOD, FUNCTION, CONSTRUCTOR, INT, BOOLEAN, CHAR, VOID, VAR, STATIC, FIELD, LET, DO, IF, ELSE, WHILE, RETURN,
						 TRUE, FALSE, Null, THIS};

char OTokenizer[L][C];	// Array contains JackTokenizer Output
int OTsize = 0;	// Initialize size to 0

void JackTokenizer(FILE* jPtr);
int tokenType(char* token);

void tokenContructor(char fName[]);

/*	JackTokenizer
void key(char* token);
void symbol(char* token);
void identifier(char* token);
void intVal(char* token);
void stringVal(char* token);
constructorJack();	// Not used
bool hasMoreTokens() and advance() //(replace with fgets() sort of functions)
constructorXML(); // Not unsed
*/


char OCompilationEngine[L][C];
int OCsize = 0;
int com = 0;

enum termCase {EXPRESSION = 1, EXPRESSIONLIST};

void compilationEngine(FILE* xmlFile);
void compileClass(FILE* xml);
void compileClassVarDec(FILE* xml);
void compileSubroutineDec(FILE* xml);
void compileSubroutineBody(FILE* xml);
void compileVarDec(FILE* xml);
void compileParameterList(FILE* xml);
void compileStatements(FILE* xml);
void compileLet(FILE* xml);
void compileDo(FILE* xml);
void compileExpression(FILE* xml);
void compileTerm(FILE* xml);
void compileExpressionList(FILE* xml);
void compileReturn(FILE* xml);
void compileIf(FILE* xml);
void compileWhile(FILE* xml);

void compilationEngineConstructor(FILE* xml);
/*	CompilationEngine
compileClass()
compileClassVarDec()
compileSubroutine()
compileParameterList()
compileVarDec()
compileStatements()
compileDo()
compileLet()
compileWhile()
compileReturn()
compileIf()
compileExpression()
compileTerm()
compileExpressionList()
*/

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



void symbolTableConstructor();
void symbolTableConstructor();
int createSymbolTableList(int loc, int scope, SymbolTable** sPtr, int methodDetected);
void appendList(SymbolTable** sPtr, int scope, char kind[], char type[], char name[], unsigned int index);
int VarCount(char kind[], int scope, SymbolTable* sPtr);
void printList(SymbolTable* start);
void freeSubroutine(SymbolTable** start);
void removeHashTag(char str[]);


int main(void) {
	// File name
	char *fileName = "Main";
	char jackFileName[30];
	char xmlFileName[30];

	strcpy(jackFileName, fileName);
	strcpy(xmlFileName, fileName);
	// Concatenate ".jack" to jackFile[]
	strcat(jackFileName, ".jack");
	
	// Concatenate "_My.xml" to xmlFile[]
	strcat(xmlFileName, "_My.xml");

	// Read xxx.jack file
	FILE* jackPtr = fopen(jackFileName, "r");


	if (jackPtr == NULL) {
		puts("Jack file not opened.");
	}
	else {


		// Open xxx.xml file for writing
		FILE* xmlPtr = fopen(xmlFileName, "w");

		if (xmlPtr == NULL) {
			puts("XML file not opened.");
		}
		else {


			// Call JackTokenizer()
			puts("Enter JackTokenizer().");
			JackTokenizer(jackPtr);
			puts("Exit JackTokenizer().");

			// Write token file
			//tokenContructor(fileName);

			// TEST
			/*for (int i = 0; i < OTsize; i++) {
				printf("%s", OTokenizer[i]);
			}*/

			// Call CompilationEngine()
			puts("Enter compilationEngine().");
			compilationEngine(xmlPtr);
			puts("Exit compilationEngine().");
			/*for (int i = 0; i < OCsize; i++) {
				printf("%s", OCompilationEngine[i]);
			}*/

			// Use constructor() to write outputs into xml file
			compilationEngineConstructor(xmlPtr);



			// Create SymbolTable
			//symbolTableConstructor();

			// Close JACK file and XML file
			fclose(xmlPtr);
		}
		fclose(jackPtr);

	}

}

// ALL FUNCTIONS START FROM HERE
/**************************************************************************************************************************************
**************************************************************************************************************************************/


void JackTokenizer(FILE* jPtr) {
	/*// Star Hash tag for tokenizer
	sprintf(OTokenizer[OTsize], "<token>\n");
	OTsize++;*/
	char readJack[1000];	// Use for acquiring input from jack file

	fgets(readJack, 1000, jPtr);
	while (!feof(jPtr)) {
		static int longComment = 0;

		// Remove white space and comments

		// Remove comments
		
			int i = 0;
			for (i = 0; readJack[i] != '\n'; i++) {
				if (readJack[i] == '/' && (readJack[i + 1] == '/' || readJack[i + 1] == '*')) {
					if (readJack[i + 1] == '/') {
						break;	// If meet comments, exit loop
					}
					if (readJack[i + 1] == '*') {
						longComment = 1;	// If '/*', it's a long comment
						break;
					}
				}
			}
			
			// If it's a long comment, search for the end comment indicator, if there is, longComment=0
			// Else, get next line, until otherwise

			if (longComment) {
				if (strstr(readJack, "*/") != NULL) {
					longComment = 0;
				}
				fgets(readJack, 1000, jPtr);
				continue;
			}
			

			// If the line only contains comments, then discard line
			if (i - 1 < 0) {
				fgets(readJack, 1000, jPtr);
				continue;
			}

			// End of removing comments
			
			// i is now the location of the comments '/' 
			// Remove white space
			if (isblank(readJack[i - 1])) {	// If the char before '/' is blank, decrement location
				i--;	// Decrement address
					while (isblank(readJack[i]) && i>0) {
						i--;
							continue;
					}
				// When exit while(isblank(readJack[i]) && i>0), it could be when i==0, or !isblank 
				// If there is only spaces but nothing else discard
				if (isblank(readJack[i])) {
					fgets(readJack, 1000, jPtr);
						continue;
				}
				else {
					readJack[i + 1] = '\0';
				}
			}
			else { // If NOT blank, set the it as terminal char
				readJack[i] = '\0';
			}
			// If there is nothing left after removing comments, get nextline
			// Otherwise, write tokens
			
			if (readJack[0] != '\0') {
				int type = 0;

				// Start of tokenising

				// Loop while the line is not finished
				int endLine = 0;
				// Set i to 0
				i = 0;
				// Quotation mark
				int quoSym = 0;

				while (!endLine) {
					// Initialise tokenStr for writing tokens
					char tokenStr[100];
					// Initialise j for writing tokens
					int j = 0;
					while (readJack[i] != '\0') {
						// If quotation mark met, string constant, ignore all other rules
						if (quoSym) {
							// If another quotation makr met, set quoSym to 0, and break as one token
							if (readJack[i] == '"') {
								type = STRING_CONST;
								quoSym = 0;
								i++;
								break;
							}
							tokenStr[j] = readJack[i];
							j++;
							i++;
							continue;
						}
						else {
							type = 0;
						}


						// If a space is met, break as one token
						if (isblank(readJack[i]) && j == 0) {
							// If the space appears before any character is taken, increment and continue
							i++;
							continue;
						}
						else if (isblank(readJack[i]) && j != 0) {
							i++;
							break;
						}
						else if (strchr(sym, readJack[i]) != NULL && j == 0) {
							// If the first met character is a symbol, take as one token
							tokenStr[j] = readJack[i];
							j++;
							i++;
							break;
						}
						else if (strchr(sym, readJack[i]) != NULL && j != 0) {
							// If it is a symbol but not first occurrence 
							break;
						}
						else if (readJack[i] == '"') {
							// If a quoSym is met set quoSym to 1
							quoSym = 1;
							i++;
							continue;
						}
						tokenStr[j] = readJack[i];
						j++;
						i++;
					}
					// Add terminal character to tokenStr
					tokenStr[j] = '\0';
					
					/*Check for what reason did while loop exit
					If it's because of symbol or space is met, then don't do anything
					If it's because of terminal character is met, then set endLine to 1*/
					if (readJack[i] == '\0') {
						endLine = 1;
					}

					// If string type is not met, call tokenType()
					if (type != STRING_CONST) {
						// Call tokenType()
						type = tokenType(tokenStr);
					}


					// Start of switch()
					switch (type) {
					case KEYWORD:
						// Write XML codes into OTokenizer array
						sprintf(OTokenizer[OTsize], "<keyword> %s </keyword>\n", tokenStr);
						OTsize++;
						break;

					case SYMBOL:
						// Write XML codes into OTokenizer array
						// If the symbol is < > or &, write them in a different way
						if (tokenStr[0] == '<') {
							sprintf(OTokenizer[OTsize], "<symbol> &lt; </symbol>\n");
						}
						else if (tokenStr[0] == '>') {
							sprintf(OTokenizer[OTsize], "<symbol> &gt; </symbol>\n");
						}
						else if (tokenStr[0] == '&') {
							sprintf(OTokenizer[OTsize], "<symbol> &amp; </symbol>\n");
						}
						else {
							sprintf(OTokenizer[OTsize], "<symbol> %s </symbol>\n", tokenStr);

						}
						OTsize++;
						break;

					case IDENTIFIER:
						// Write XML codes into OTokenizer array
						sprintf(OTokenizer[OTsize], "<identifier> %s </identifier>\n", tokenStr);
						OTsize++;
						break;

					case INT_CONST:
						// Write XML codes into OTokenizer array
						sprintf(OTokenizer[OTsize], "<integerConstant> %s </integerConstant>\n", tokenStr);
						OTsize++;
						break;

					case STRING_CONST:
						// Write XML codes into OTokenizer array
						sprintf(OTokenizer[OTsize], "<stringConstant> %s </stringConstant>\n", tokenStr);
						OTsize++;
						break;
					}
					// End of switch()
				}

				// End of while(!endline)
			}

		// Grab the next line
		fgets(readJack, 100, jPtr);
	}



}


int tokenType(char* token) {

		// Check if KEYWORD
		for (int i = 0; i < 21; i++) {
			if (strcmp(token, keywords[i]) == 0) {
				return KEYWORD;
			}
		}
		// Check if SYMBOL
		
			if (strstr(sym, token) != NULL) {
				return SYMBOL;
			}
		

		// Check if INT_CONST
		if (isdigit(token[0])) {
			return INT_CONST;
		}

		// Check if STRING_CONST
		if (strstr(token, "\"\"")) {
			return STRING_CONST;
		}

		// If none of it fits, it is a identifier
		return IDENTIFIER;


}


void compilationEngine(FILE* xmlFile) {

	// Compilation step
	// The first token should be "class"
	// If NOT "class", EXIT
	if (strstr(OTokenizer[com], "class") == NULL) {
		puts("Error in compilationEngine(), the first token should be \"class\"!");
		exit(-1);
	}
	else {
		// Start compiling
		puts("Enter compileClass()...");
		compileClass(xmlFile);
		puts("compileClass() finished.");
	}
}


void compileClass(FILE* xml) {
	// print <class>
	sprintf(OCompilationEngine[OCsize], "<class>\n");
	OCsize++;
	// Print "class"
	sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
	com++;
	OCsize++;
	// Print title, the next token should be '{'
	// If NOT '{', EXIT
	sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
	com++;
	OCsize++;
	if (strchr(OTokenizer[com], '{') == NULL) {
		puts("Error in compileClass(), '{' should follow the title of class!");
		exit(-1);
	}
	else {
		// Print '{'
		sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
		com++;
		OCsize++;
	}

	int compileClassEnd = 0;

	while (1) {
		if (strstr(OTokenizer[com], "static") || strstr(OTokenizer[com], "field") ) {
			// "static" OR "field" will be printed in compileClassVarDec()
			puts("Enter compileClassVarDec()... ");
			compileClassVarDec(xml);	// Call compileClassVarDec()
			puts("Finished compileClassVarDec().");
			continue;
		}
		else if (strstr(OTokenizer[com], "function") || strstr(OTokenizer[com], "method") || strstr(OTokenizer[com], "constructor")) {
			// Call compileSubroutineDec()
			puts("Enter compileSubroutineDec()...");
			compileSubroutineDec(xml);
			puts("subroutineDec() finished.");
			
		}
		else {
			// When exit all compileSubroutineDec(), the current token should be '}'
			// If NOT '}', EXIT
			if (strchr(OTokenizer[com], '}') == NULL) {
				puts("Error in compileClass(), '}' should be there when exit subroutineDec()!");
				compilationEngineConstructor(xml);
				exit(-1);
			}
			else {
				// Print '}' and terminate compileClass()
				sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
				com++;
				OCsize++;
				break;
			}
		}
		
		// End of loop
	}

	// Print </class>
	sprintf(OCompilationEngine[OCsize], "</class>\n");
	OCsize++;
	// Return to compilationEngine()
}


void compileClassVarDec(FILE* xml) {
	// Print <classVarDec>
	sprintf(OCompilationEngine[OCsize], "<classVarDec>\n");
	OCsize++;
	// The next token should be "field" OR "static"
	// If NOT, EXIT
	if (strstr(OTokenizer[com], "static") == NULL && strstr(OTokenizer[com], "field") == NULL) {
		puts("Error in compileClassVarDec(), there should be either \"field\" OR \"static\"!");
			exit(-1);
	}

	int classVarDecEnd = 0;
	while (1) {
		// If ';', print and terminate classVarDec
		if (strchr(OTokenizer[com], ';') != NULL) {
			// Print ';'
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
			com++;
			OCsize++;
			break;
		}

		// Next token
		sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
		com++;
		OCsize++;

		// End of loop
	}
	// print </classVarDec>
	sprintf(OCompilationEngine[OCsize], "</classVarDec>\n");
	OCsize++;
	// Return to compileClass()
}


void compileSubroutineDec(FILE* xml) {
	// Print <subroutineDec>
	sprintf(OCompilationEngine[OCsize], "<subroutineDec>\n");
	OCsize++;
	// Print "constructor", "function" OR "method"
	sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
	com++;
	OCsize++;

	int subroutineDecEnd = 0;
	int parameterListActivate = 0;
	// Loop
	while (1) {
		// If '(', print and call compileParameterList()
		if (strchr(OTokenizer[com], '(') != NULL) {
			// Print '('
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
			com++;
			OCsize++;

			puts("Enter compileParameterList()... (compileSubroutineDec())");
			compileParameterList(xml);
			puts("Finished compileParameterList(). (compileSubroutineDec())");
			
			// When exit compileParameterList(), the current token should be ')'
			// If NOT, EXIT
			if (strchr(OTokenizer[com], ')') == NULL) {
				puts("Error in compileSubroutineDec(), ')' should be the token that terminates compileParameterList()!");
				exit(-1);
			}
			else {
				// Print ')', the next token should be '{'
				// If NOT '{', Exit
				sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
				com++;
				OCsize++;
				if (strchr(OTokenizer[com], '{') == NULL) {
					puts("Error in compileSubroutineDec(), '{' should follow ')'!");
					exit(-1);
				}
			}
		}

		// If open curly brace is met, call compileSubroutineBody()
		// When subroutine Body is finished, exit
		if (strchr(OTokenizer[com], '{')) {
			puts("Enter compileSubroutineBody()... (compileSubroutineDec())");
			compileSubroutineBody(xml);	// Call compileSubroutineBody()
			puts("Finished compileSubroutineBody(). (compileSubroutineDec())");
			// When exit compileSubroutineBody(), terminate subroutineDec
			break;
		}

		// Next token
		sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
		com++;
		OCsize++;

		

		// End of loop
	}

	// Print </subroutineDec>
	sprintf(OCompilationEngine[OCsize], "</subroutineDec>\n");
	OCsize++;
	// Return to compileClass()
}


void compileParameterList(FILE* xml) {
	// Print <parameterList>
	sprintf(OCompilationEngine[OCsize], "<parameterList>\n");
	OCsize++;
	int parameterListEnd = 0;

	// Loop
	while (1) {
		// If ')', terminate parameterList
		// Without printing ')'
		if (strchr(OTokenizer[com], ')')) {
			break;
		}
		else {
			// Next token
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
			com++;
			OCsize++;
		}

		// End of loop
	}

	// Print </parameterList>
	sprintf(OCompilationEngine[OCsize], "</parameterList>\n");
	OCsize++;
	// Return to compileSubroutineDec()
}


void compileSubroutineBody(FILE* xml) {
	char statements[5][100] = { "if", "do", "let", "while", "return" };
	// Print <subroutineBody>
	sprintf(OCompilationEngine[OCsize], "<subroutineBody>\n");
	OCsize++;
	// Print '{', the next token should be either a "var" OR a statement
	sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
	com++;
	OCsize++;
	
	int subroutineBodyEnd = 0;

	while (1) {
		// If "var", call compileVarDec()
		if (strstr(OTokenizer[com], "var")) {
			puts("Enter compileVarDec()... (compileSubroutineBody())");
			compileVarDec(xml); // Call compileVarDec()
			puts("Finished compileVarDec()... (compileSubroutineBody())");
			continue;
		}

		 
		/*If "let", "do", "if", "while", "return"
		Call compileStatements()
		Search from array statements[][]*/
		
		for (int i = 0; i < 5; i++) {
			if (strstr(OTokenizer[com], statements[i])) {
				puts("Enter compileStatements()... (compileSubroutineBody())");
				compileStatements(xml);	// Call compileStatements()
				puts("Enter compileStatements()... (compileSubroutineBody())");
				continue;
			}
		}

		// If '}', print and terminate subroutineBody
		// This should also terminate subroutineDec
		if (strchr(OTokenizer[com], '}')) {
			// Print '}'
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
			com++;
			OCsize++;
			break;
		}

		// subroutineBody should never reach the end, it should be exited only by breaking
		// If it does reach the end, EXIT
		puts("Error compileSubroutineBody(), there should be a '}' that terminates the function!");
		compilationEngineConstructor(xml);
		exit(-1);
		
		// Next token
		/*sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
		com++;
		OCsize++;*/

		// End of loop
	}

	// Print </subroutineBody>
	sprintf(OCompilationEngine[OCsize], "</subroutineBody>\n");
	OCsize++;
	// Return to compileSubroutineDec()
}


void compileVarDec(FILE* xml) {
	// Print <classVarDec>
	sprintf(OCompilationEngine[OCsize], "<varDec>\n");
	OCsize++;
	// Print "var"
	sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
	com++;
	OCsize++;

	int classVarDecEnd = 0;

	// Loop
	while (1) {


		// If ';', print and terminate varDec
		if (strchr(OTokenizer[com], ';')) {
			// Print ';'
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
			com++;
			OCsize++;
			break;
		}


		// Next token, could be anything
		sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);// Print token
		com++;
		OCsize++;

		// End of loop
	}


	// Print </classVarDec>
	sprintf(OCompilationEngine[OCsize], "</varDec>\n");
	OCsize++;
	// Return to subroutineBody()
}


void compileStatements(FILE* xml) {
	// Print <statements>
	sprintf(OCompilationEngine[OCsize], "<statements>\n");
	OCsize++;
	
	int compileStatementsEnd = 0;

	// Loop
	while (1) {

		// If "let", call compileLet()
		if (strstr(OTokenizer[com], "let") != NULL) {
			// Call compileLet()
			puts("Enter compileLet()... (compileStatements())");
			compileLet(xml);
			puts("Finished compileLet()... (compileStatements())");
			continue;
		}

		// If "do", call compileDo()
		if (strstr(OTokenizer[com], "do") != NULL) {
			// Call compileDo()
			puts("Enter compileDo()... (compileStatements())");
			compileDo(xml);
			puts("Finished compileDo()... (compileStatements())");
			continue;
		}

		// If "return", call compileReturn()
		if (strstr(OTokenizer[com], "return") != NULL) {
			// Call compileReturn
			puts("Enter compileReturn()... (compileStatements())");
			compileReturn(xml);
			puts("Finished compileReturn()... (compileStatements())");
			continue;
		}

		// If "if", call compileIf()
		if (strstr(OTokenizer[com], "if") != NULL) {
			// Call compileIf()
			puts("Enter compileIf()...");
			compileIf(xml);
			puts("compileIf() finished.");
			continue;
		}

		// If "while", call compileWhile()
		if (strstr(OTokenizer[com], "while") != NULL) {
			// Call compileWhile()
			puts("Enter compileWhile()...");
			compileWhile(xml);
			puts("compileWhile() finished.");
			continue;
		}

		// If no more statements, end
		break;
		// End of loop
	}

	// Print </statements>
	sprintf(OCompilationEngine[OCsize], "</statements>\n");
	OCsize++;

	// Return to compileSubroutineBody()
	// Return to compileIf()
}


// '; is the ONLY token that terminates letStatement!
void compileLet(FILE* xml) {
	// Print <letStatement>
	sprintf(OCompilationEngine[OCsize], "<letStatement>\n");
	OCsize++;
	// Print "let"
	sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
	com++;
	OCsize++;

	int letStatementEnd = 0;
	int expressionActivate = 0;

	// Loop
	while (1) {

		// If '=', call compileExpression()
		// '=' should be printed first before calling compileExpression()
		// If '[', call compileExpression()
		// '[' should be printed first before calling compileExpression()
		if (strchr(OTokenizer[com], '=') != NULL || strchr(OTokenizer[com], '[') != NULL) {
			// Print '=' or '['
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
			com++;
			OCsize++;

			puts("Enter compileExpression()... (compileLet())");
			compileExpression(xml);	// Call compileExpression()
			puts("Finished compileExpression(). (compileLet())");
			
			// When exit compileExpression(), the current token should be ']'(enter with '[') OR ';'(enter with '=')
			// If ']', print and keep going, the next token should be '='
			// If ';', print and terminate letStatement
			// If NEITHER ']', EXIT
			if (strchr(OTokenizer[com], ']') == NULL && strchr(OTokenizer[com], ';') == NULL) {
				puts("Error in compileLet(), ']' OR ';' should be the tokens that terminates compileExpression()!");
				compilationEngineConstructor(xml);
				exit(-1);
			}
			else if(strchr(OTokenizer[com], ']') != NULL) {
				// Print ']', next token should be '=' OR ';'
				// If NOT '=', EXIT
				sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
				com++;
				OCsize++;
				if (strchr(OTokenizer[com], '=') == NULL && strchr(OTokenizer[com], ';') == NULL) {
					puts("Error in compileLet(), '=' should be the token that follow ']'!");
					compilationEngineConstructor(xml);
					exit(-1);
				}
			}
			else if (strchr(OTokenizer[com], ';') != NULL) {
				// Print ';'
				sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
				com++;
				OCsize++;
				break;
			}
		}
		else {

			// Next token, print all "<identifier>"
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
			com++;
			OCsize++;
		}

		// End of loop
	}

	// Print </letStatement>
	sprintf(OCompilationEngine[OCsize], "</letStatement>\n");
	OCsize++;

	// Return to compileStatements()
}


void compileDo(FILE* xml) {
	// Print <doStatement>
	sprintf(OCompilationEngine[OCsize], "<doStatement>\n");
	OCsize++;
	// Print "do", next token shoudl be any "<identifier>"
	// If NOT "<identifier>, EXIT
	sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
	com++;
	OCsize++;
	if (strstr(OTokenizer[com], "<identifier>") == NULL) {
		puts("Error in compileDo, \"<identifier>\" should follow \"do\"");
		exit(-1);
	}

	int doStatementEnd = 0;
	int expressionListActivate = 0;

	// Loop
	while (1) {

		// If '(', print and call compileExpressionList()
		if (strchr(OTokenizer[com], '(') != NULL) {
			// Print '('
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
			com++;
			OCsize++;
			
			
			puts("Enter compileExpressionList()... (compileDo())");
			compileExpressionList(xml);	// Call compileExpressionList()
			puts("Enter compileExpressionList()... (compileDo())");
			
			// When exit compileExpressionList(), the current token should be ')'
			// If NOT ')', EXIT
			if (strchr(OTokenizer[com], ')') == NULL) {
				puts("Error in compileDo(), ')' should be the token that terminates compileExpressionList()!");
				exit(-1);
			}
			else {
				// Print ')'
				sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
				com++;
				OCsize++;
			}
		}

		// If ';', print and terminates doStatement
		if (strchr(OTokenizer[com], ';')) {
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
			com++;
			OCsize++;
			break;
		}

		// Next token, print all identifier and '.'
		sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
		com++;
		OCsize++;

		// End of loop
	}

	// Print </doStatement>
	sprintf(OCompilationEngine[OCsize], "</doStatement>\n");
	OCsize++;

	// Return to compileStatements()
}


void compileExpression(FILE* xml) {
	// Print <expression>
	sprintf(OCompilationEngine[OCsize], "<expression>\n");
	OCsize++;

	int expressionEnd = 0;

	// Loop
	while (1) {

		// Call compileTerm
		puts("Enter compileTerm()... (compileExpression())");
		compileTerm(xml);
		puts("compileTerm() finished. (compileExpression()");

		// If ';', expressionEnd, without printing ';', printed in the caller
		// If ']', expressionEnd, without printing ']', printed in the caller
		// If ')', expressionEnd, without printing ')', printed in the caller
		// If ',', expressionEnd, without printing ',', printed in the caller, should be printed in compileExpressionList()
		if ((strchr(OTokenizer[com], ';') && strchr(OTokenizer[com], '&') == NULL) || strchr(OTokenizer[com], ']') || 
			strchr(OTokenizer[com], ')') || strchr(OTokenizer[com], ',') ) {
			break;
		}
		else {
			// Next token, usually math operator (+-*/)
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
				com++;
				OCsize++;
		}

		// End of loop
	}

	// Print </expression>
	sprintf(OCompilationEngine[OCsize], "</expression>\n");
	OCsize++;

	// Return to compileLet()
	// Return to compileIf()
	// Return to compileTerm()
	// Return to compileReturn()
}


/*
compileTerm() is only going to be looped through once
Unless there is a '.' that indentifies that it a different case
*/
void compileTerm(FILE* xml) {
	// Print <term>
	sprintf(OCompilationEngine[OCsize], "<term>\n");
	OCsize++;

	int termEnd = 0;
	static int scenario = 0;


	while (1) {
		// If '.', print and set as the case of expressionList
		if (strchr(OTokenizer[com], '.')) {
			// Print '.'
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
			com++;
			OCsize++;
			scenario = EXPRESSIONLIST;
		}

		// If '(' , look into the scenario and determine which function to call
		if (strchr(OTokenizer[com], '(') || strchr(OTokenizer[com], '[')) {// If '(' OR '[', call compileExpression()
			// Print '(' OR '['
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
			com++;
			OCsize++;

			// If EXPRESSIONLIST, call compileExpressionList()
			if (scenario == EXPRESSIONLIST) {
				puts("Enter compileExpressionList()... (compileTerm())");
				compileExpressionList(xml); // Call compileExpressionList()
				puts("Finished compileExpressionList(). (compileTerm())");
			}
			else {
			// Else, EXPRESSION, call compileExpression()
				puts("Enter compileExpression()... (compileTerm())");
				compileExpression(xml); // Call compileExpression()
				puts("Finished compileExpression(). (compileTerm())");
			}

			// When exit compileExpression() OR compileExpressionList(), token should be ')'
			// If ')', print ')'
			// If NOT ')', EXIT
			if (strchr(OTokenizer[com], ')') || strchr(OTokenizer[com], ']')) {
				// Print ')' OR ']'
				sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
				com++;
				OCsize++;
				scenario = 0;	// Reinitialise scenario
				break;
			}
			else {
				puts("Error in compileTerm(), ')' should be the token when exit compileExpression() OR compileExpressionList()!");
				exit(-1);
			}
		}
		// If "<symbol>" rather than '(' AND NOT (EXPRESSION OR last token '('), terminate term
		else if (strstr(OTokenizer[com], "<symbol>")) {
			if (scenario == EXPRESSION || strstr(OTokenizer[com-1], "<symbol>")) {
				// If EXPRESSION, print and Recursive
				sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
				com++;
				OCsize++;

				compileTerm(xml);

				// When exit compileTerm(), the current token should be ')'
				// If NOT ')', EXIT
				// If ')', terminate term
				if (strchr(OTokenizer[com], ')')) {
					break;
				}
				else {
					puts("Error in recursive compileTerm(), ')' should be the token when exit compileTerm()!");
#if 1
					for (int i = 0; i < OTsize; i++) {
						printf("%s\n", OTokenizer[i]);
					}
					exit(-1);
#endif 


					exit(-1);
				}
			}
			else {
				break;
			}
		}


		// If ')' OR ']', terminate term
		if (strchr(OTokenizer[com], ']') || strchr(OTokenizer[com], ')')) {
			break;
		}

		// If none of above, print term
		sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
		com++;
		OCsize++;

		// End of loop
	}

	// Print </term>
	sprintf(OCompilationEngine[OCsize], "</term>\n");
	OCsize++;

	// Return to compileExpression()
}


/*expressionList could be empty*/
void compileExpressionList(FILE* xml) {
	// Print <expressionList>
	sprintf(OCompilationEngine[OCsize], "<expressionList>\n");
	OCsize++;

	int expressionListEnd = 0;

	// Loop
	while (1) {

		/* If ')', expressionListEnd, without printing out ')'
		 ')' should be printed in the caller					*/
		if (strchr(OTokenizer[com], ')') != NULL) {
			break;
		}
		else {
			// Call compileExpression()
			puts("Enter compileExpression()... (compileExpressionList())");
			compileExpression(xml);
			puts("Finished compileExpression(). (compileExpressionList())");

			// When exit compileExpression(), the current token could be ',' and ')' 
			// If ',', print and get the next token, which should be an "<identifier>" OR "<integerConstant>"
			// If ')', do nothing, loop again and expressionList will be terminated
			if (strchr(OTokenizer[com], ',') != NULL) {
				// Print ','
				sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
				com++;
				OCsize++;
			}
		}

		// End of loop
	}

	// Print </expressionList>
	sprintf(OCompilationEngine[OCsize], "</expressionList>\n");
	OCsize++;

	// Return to compileTerm()
	// Return to compileDo()
}


void compileReturn(FILE* xml) {
	// Print <returnStatement>
	sprintf(OCompilationEngine[OCsize], "<returnStatement>\n");
	OCsize++;
	// Print "return", the next token could be ';' or expressions
	sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
	com++;
	OCsize++;

	int returnStatementEnd = 0;

	// Loop
	while (1) {
		// If the next token is ';', end returnStatment
		// Else, call compileExpression()

		// If ';', print and terminate returnStatement
		// Else, call compileExpression()
		if (strchr(OTokenizer[com], ';') != NULL) {
			// Print ';'
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
			com++;
			OCsize++;
			break;
		}
		else {
			puts("Enter compileExpression()... (compileReturn())");
			compileExpression(xml); // Call compileExpression()
			puts("Finished compileExpression(). (compileReturn())");

			// When exit, it means the current token is ';'
			// If NOT, EXIT
			if (strchr(OTokenizer[com], ';') == NULL) {
				puts("Error in compileReturn(), ';' should be the token that terminates compileExpression()!");
				exit(-1);
			}
		}

		// Next token
		/*sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
		com++;
		OCsize++;*/

		

		// End of loop
	}

	// Print </returnStatement>
	sprintf(OCompilationEngine[OCsize], "</returnStatement>\n");
	OCsize++;

	// Return to compileStatements()
}


void compileIf(FILE* xml) {
	// Print <ifStatement>
	sprintf(OCompilationEngine[OCsize], "<ifStatement>\n");
	OCsize++;
	// Print "if", the next token should be '('
	sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
	com++;
	OCsize++;
	// If the next token is NOT '(', EXIT
	if (strchr(OTokenizer[com], '(') == NULL) {
		puts("Error in compileIf(), the token follows \"if\" should be '('!");
		exit(-1);
	}

	int ifStatementEnd = 0;
	int expressionActivate = 0;
	int statementsActivate = 0;

	while (1) {

		/* If '(', call compileExpression() 
		   '(' should be printed before calling compileExpression() */
		// '(' should follow "if"
		if (strchr(OTokenizer[com], '(') != NULL) {
			// Print '('
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
			com++;
			OCsize++;
			
			puts("Enter compileExpression()... (compileIf())");
			compileExpression(xml);	// Call compileExpression()
			puts("Finished compileExpression(). (compileIf())");

			// Print ')', the next token should be '}'
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
			com++;
			OCsize++;
			// If the next token is NOT '}', Exit
			if (strchr(OTokenizer[com], '{') == NULL) {
				puts("Error in compileIf(), the token follows ')' should be '{'!");
				exit(-1);
			}
		}

		/*	If ')', next token
			')' will be printed in this function but does not terminate it */
		
		/*	If '{', call compileStatements()
			'{' should be printed first before calling compileStatements()	*/
		if (strchr(OTokenizer[com], '{') != NULL) {
			// Print '{'
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
			com++;
			OCsize++;

			puts("Enter compileStatements()... (compileIf())");
			compileStatements(xml);	// Call compileStatements()
			puts("Finished compileStatements(). (compileIf())");

			// Print '}'
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
			com++;
			OCsize++;
			// If '}' AND the next token is not "else", terminate ifStatement
			if (strstr(OTokenizer[com], "else") == NULL) {
				break;
			}
			else {
				// Print "else"
				sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
				com++;
				OCsize++;
			}
		}

		// Next token, [not needed, all tokens should be printed in compileStatements() or compileExpression()...]
		/*sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
		com++;
		OCsize++;*/

		// End of loop
	}


	// Print </ifStatement>
	sprintf(OCompilationEngine[OCsize], "</ifStatement>\n");
	OCsize++;
	

	// Return to compileStatements()
}


void compileWhile(FILE* xml) {
	// Print <whileStatement>
	sprintf(OCompilationEngine[OCsize], "<whileStatement>\n");
	OCsize++;

	// Print "while"
	sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
	com++;
	OCsize++;

	int whileStatementEnd = 0;

	while (1) {
		// If '(', print and call compileExpression()
		if (strchr(OTokenizer[com], '(') != NULL) {
			// Print '('
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
			com++;
			OCsize++;

			puts("Enter compileExpression()... (compileWhile())");
			compileExpression(xml);	// Call compileExpression()
			puts("compileExpression() finished. (compileWhile())");

			// Print ')', the next token should be '{'
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
			com++;
			OCsize++;
			// If the next token is not '{', EXIT
			if (strchr(OTokenizer[com], '{') == NULL) {
				puts("Error in compileWhile(), the token follows ')' should be '{'!");
				exit(-1);
			}
		}

		// If '{', print and call compileStatements
		if (strchr(OTokenizer[com], '{') != NULL) {
			// Print '{'
			sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
			com++;
			OCsize++;

			compileStatements(xml);	// Call compileStatements()

			// Print '}' and terminates whileStatement
			if (strchr(OTokenizer[com], '}') != NULL) {
				sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
				com++;
				OCsize++;
				break;
			}
			else {
				puts("Error in compileWhile(), '}' should be the token that terminates compileStatements()!");
				exit(-1);
			}
		}

		/*// Next token
		sprintf(OCompilationEngine[OCsize], "%s", OTokenizer[com]);	// Print token
		com++;
		OCsize++;*/

		// End of loop
	}

	// Print </whileStatement>
	sprintf(OCompilationEngine[OCsize], "</whileStatement>\n");
	OCsize++;

	// Return to compileStatements()
}


void compilationEngineConstructor(FILE* xml) {
	// Spaces indentation
	int spaces = 0;
	// Write XML file
	for (int i = 0; i < OCsize; i++) {
		
		
		// Write spaces into file before writing tokens
		for (int j = 0; j < spaces; j++) {
			fprintf(xml, "%s", " ");
		}
		fprintf(xml, "%s", OCompilationEngine[i]);

		// If '/'(</name>), decrease 2 spaces
		// Else, increase 2 spaces every time
		// If there are two '<', do nothing
		if ((i + 1) < OCsize && strchr(strchr(OCompilationEngine[i+1], '<') + 1, '<') == NULL) {
			if (strchr(OCompilationEngine[i+1], '/') != NULL) {
				spaces -= 2;
			}
		}
		if (strchr(strchr(OCompilationEngine[i], '<') + 1, '<') == NULL) {
			if (strchr(OCompilationEngine[i], '/') == NULL) {
				spaces += 2;
			}
		}
		
	}


}


void tokenContructor(char fName[]) {
	// Copy
	char tokenFileName[30];
	strcpy(tokenFileName, fName);

	// Concatenate "T_My.xml"
	strcat(tokenFileName, "T_My.xml");

	// Write token file
	FILE* tokenf = fopen(tokenFileName, "w");

	if (tokenf == NULL) {
		puts("Unable to open token file.");
	}
	else {

		for (int i = 0; i < OTsize; i++) {
			if (i == 0) {
				fprintf(tokenf, "%s\n" ,"<tokens>");
			}
			
			
				fprintf(tokenf, "%s", OTokenizer[i]);
			
				if (i == (OTsize - 1)) {
					fprintf(tokenf, "%s\n", "</tokens>");
				}
		}

		puts("Finished writing token file.");
		fclose(tokenf);
	}

}


void symbolTableConstructor() {
	// Create linked-list start pointer
	SymbolTable* startPtr = NULL;

	// Scope, 1 for Class-Level
	// 2 for Subroutine-Level
	int scope = 0;
	int i;
	int methodDetected = 0;

	// Loop through all the output of compilationEngine()
	for (i = 0; i < OCsize; i++) {

		// For class-level, use iteration
		// If "<classVarDec>", scope = Class-Level
		// End when "</classVarDec>"
		if (strstr(OCompilationEngine[i], "<classVarDec>")) {
			scope = 1;
			for (; i < OCsize && scope == 1; i++) {
				// Call createSymbolTableList()
				i = createSymbolTableList(i, scope, &startPtr, methodDetected);

				// If "</classVarDec>", End
				if (strstr(OCompilationEngine[i], "</classVarDec>")) {
					scope = 0;
				}
				// End of for loop
			}
		}

		// For subroutine-level use iteration
		// Might use recursive function for nested-scopes
		// If "<subroutineBody>", scope = Subroutine-Level
		// End when "</subroutineBody>"
		if (strstr(OCompilationEngine[i], "<subroutineDec>")) {
			scope = 2;
			for (; i < OCsize && scope == 2; i++) {
				if (strstr(OCompilationEngine[i], "method")) {
					methodDetected = 1;
				}

				// If "<varDec>"
				// Call createSymbolTableList()
				if (strstr(OCompilationEngine[i], "<varDec>")) {
					i = createSymbolTableList(i, scope, &startPtr, methodDetected); //Call createSymbolTableList()
				}

				// If "</subroutineBody>", reset subroutine-level list and End
				if (strstr(OCompilationEngine[i], "</subroutineDec>")) {
					
					// Free subroutine-level list
					printList(startPtr);
					puts("One subroutine finished!");
					freeSubroutine(&startPtr);
					puts("after freeing subroutine:");
					printList(startPtr);
					
				}
			}
		}

		// End of for Loop
	}

	// Return to main()
}

/*
This function will return every time it meets ';'
This function will return the current location of the OCompilationEngine[][]
*/
int createSymbolTableList(int loc, int scope, SymbolTable **sPtr, int methodDetected) {
	// Kindof, typeOf and index
	char kindOf[50];
	char typeOf[50];
	char nameOf[50];
	unsigned int index;

	int openBraceDetected = 0;

	// Loop
	while (loc < OCsize) {

		// If the scope is Class-Level
		// Create Class-Level list
		if (scope == 1) {
			// Write Class Level
			while (loc < OCsize) {

				// In class, the kind follows <classVarDec>
				// Write name, type, kind and index
				// If "static" OR "field", put in kind

				if (strstr(OCompilationEngine[loc], "static") || strstr(OCompilationEngine[loc], "field")) {
					sprintf(kindOf, "%s", OCompilationEngine[loc]);
					// The next token is type
					loc++;
					sprintf(typeOf, "%s", OCompilationEngine[loc]);
					loc++;
				}

				// Next is name (Could be multiple names)
				// If "<identifier>", define
				// Check if there is any name of the same kind
				// Then determine the index
				if (strstr(OCompilationEngine[loc], "<identifier>")) {
					// Write nameOf[]
					sprintf(nameOf, "%s", OCompilationEngine[loc]);
					loc++;

					// Call VarCount(), return count to index
					index = VarCount(kindOf, scope, *sPtr);

					
					// Finish one element
					removeHashTag(nameOf);
					removeHashTag(typeOf);
					removeHashTag(kindOf);
					
					appendList(sPtr, scope, kindOf, typeOf, nameOf, index);
				}

				// If ',', allocate new space for new name
				

				// If ';', exit createSymbolTableList()
				if (strchr(OCompilationEngine[loc], ';')) {
					loc++;
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
		else{
			// Write Subroutine Level
			while (loc < OCsize) {
				// ARG
				if (strstr(OCompilationEngine[loc], "<parameterList>") && strstr(OCompilationEngine[loc + 1], "</parameterList>") == NULL) {
					while (loc < OCsize) {

						// If it's a method
						// The first argument is this
						if (methodDetected) {
							// Write kind = argument, index = 0, type = OCompilationEngine[2], name = this
							sprintf(typeOf, "%s", OCompilationEngine[2]);
							removeHashTag(typeOf);
							
							// Add to list
							appendList(sPtr, scope, "argument", typeOf, "this", 0);
							// Just in case
							methodDetected = 0;
						}

						sprintf(kindOf, "argument");
						loc++;
						index = VarCount(kindOf, scope, *sPtr);
						// Because this loop is entered with "<parameterList>"
						// Therefore, the next token should be type
						// Write type
						
						sprintf(typeOf, "%s", OCompilationEngine[loc]);
						loc ++;

						// Next is name
						if (strstr(OCompilationEngine[loc], "<identifier>")) {
							// Write name
							// ',' or ';' after the name
							sprintf(nameOf, "%s", OCompilationEngine[loc]);
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

						// If ',', finish one and start a new one
						if (strchr(OCompilationEngine[loc], ',')) {
							loc++; // Get the name
							while (strstr(OCompilationEngine[loc], "</parameterList>") == NULL) {
								if (strstr(OCompilationEngine[loc], "<identifier>")) {
									sprintf(nameOf, "%s", OCompilationEngine[loc]);
									removeHashTag(nameOf);
									index++;
									appendList(sPtr, scope, kindOf, typeOf, nameOf, index);
								}

								loc++; // Advance
								// End of while Loop
							}
						}

						// If "</parameterList>", finish one and Exit
						if (strstr(OCompilationEngine[loc], "</parameterList>")) {
							break;
						}

						loc++;
						// End of while loop
					}
				}

				// LCL
				if (strstr(OCompilationEngine[loc], "<varDec>")) {
					
					// If another scope within subroutine
					// Call recursive function
					if (openBraceDetected) {
						scope++;
						createSymbolTableList(loc, scope, sPtr, methodDetected);
					}
					else {
						while (loc < OCsize) {

							if (strstr(OCompilationEngine[loc], "<varDec>")) {
								loc += 2; // Skip <varDec> and "var" to get the type
							}

							// Write kind, and index
							strcpy(kindOf, "local");

							puts("Enter VarCount");
							index = VarCount(kindOf, scope, *sPtr);
							puts("Exit VarCount");

							// Write type
							sprintf(typeOf, "%s", OCompilationEngine[loc]);
							loc++;

							// Next is name
							if (strstr(OCompilationEngine[loc], "<identifier>")) {
								// Write name
								sprintf(nameOf, "%s", OCompilationEngine[loc]);
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
							if (strchr(OCompilationEngine[loc], '{')) {
								openBraceDetected = 1;
							}

							// If ',', advance one to get name and increment index
							if (strchr(OCompilationEngine[loc], ',')) {
								loc++; // Get the name
								while (strchr(OCompilationEngine[loc], ';') == NULL) {
									if (strstr(OCompilationEngine[loc], "<identifier>")) {
										sprintf(nameOf, "%s", OCompilationEngine[loc]);
										removeHashTag(nameOf);
										index++;
										appendList(sPtr, scope, kindOf, typeOf, nameOf, index);
									}

									loc++; // Advance
									// End of while Loop
								}
							}

							// If ';', return
							if (strchr(OCompilationEngine[loc], ';')) {
								loc++;
								return loc;
							}

							// Advance
							loc++;

						}
					}
				}
				
				loc++;
				// End of Subroutine-Level
			}
		}
		// End of while Loop
	}

	return loc;
	// Return to symbolTableConstructor()
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
int VarCount(char kind[], int scope, SymbolTable *sPtr) {
	unsigned int count = 0;
	
	// If the list is NULL, exit directly
	while (sPtr != NULL) {
		// If the same kind and same scope
		// count ++
		if (strstr(sPtr->kind, kind) && sPtr->scope == scope) {
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

	printf("\n\n%s\t\t%s\t\t%s\t\t\t%s\t\t%s\n", "Scope", "Name", "Type", "Kind", "Index");
	while (start != NULL) {

		printf("%u\t\t%s\t\t%s\t\t\t%s\t\t%u\n", start->scope, start->name, start->type, start->kind, start->index);
		
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
	pre->next = NULL;
}


void removeHashTag(char str[]) {
	char strProcessed[100];

	int j = 0;
	for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
		// If '>' advance one and start copying string
		if (str[i] == '>') {
			i += 2;
			// Stop at '<', and set white space to '\0'
			for (j = 0; str[i] != '<'; j++) {
				// Copy string
				strProcessed[j] = str[i];
				i++;
			}
			j--;
			// Set white space to '\0'
			strProcessed[j] = '\0';
			strcpy(str, strProcessed);

			break;
		}

		// End of for Loop
	}

	// Return to createSymbolTableList()
}