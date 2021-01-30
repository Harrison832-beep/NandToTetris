#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	// Open two files and compare texts
	FILE* myFilePtr = fopen("Main_My.xml", "r");
	FILE* targetFilePtr = fopen("Main.xml", "r");

	if (myFilePtr == NULL || targetFilePtr == NULL) {
		puts("Fail to open file.");
	}
	else {
		// Compare
		char readMy[100];
		char readTar[100];
		int location = 1;	// Count lines to check error location if there is any

		fgets(readMy, 100, myFilePtr);
		fgets(readTar, 100, targetFilePtr);

		while (!feof(myFilePtr) && !feof(targetFilePtr)) {

			if (strcmp(readMy, readTar) == 0) {
				location++;
			}
			else {
				printf("Comparison fail at line %d.\n", location);
				printf("%s", readMy);
				printf("%s", readTar);
				exit(EXIT_FAILURE);
			}

			fgets(readMy, 100, myFilePtr);
			fgets(readTar, 100, targetFilePtr);
		}
        puts("Comparison success!");

		fclose(myFilePtr);
		fclose(targetFilePtr);
	}




	return 0;
}
