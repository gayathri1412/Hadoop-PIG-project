/****************************************************************************************
This file is for WPI CS561 project 2, Spring 2014 and completed by Xiao Du and Junyu Zhu
****************************************************************************************/

//mapper
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]){

	int size = 2048;
	char *aLine;
	aLine = (char *) malloc (size + 1);

	while ( getline(&aLine, &size, stdin) != -1) {
	
		// filter customer id and transaction total
		char *pch, *cid, *transTotal;
		pch = strtok (aLine, ",");
		pch = strtok (NULL, ",");
		cid = pch;
		pch = strtok (NULL, ",");
		transTotal = pch;

		// print cid and transTotal into STDOUT
		printf("%s\t%s\n", cid, transTotal);	
	}

	return 0;
}
