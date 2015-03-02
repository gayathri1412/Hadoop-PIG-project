/****************************************************************************************
This file is for WPI CS561 project 2, Spring 2014 and completed by Xiao Du and Junyu Zhu
****************************************************************************************/

//reducer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]){

	int size = 2048;
	char *aLine;
	aLine = (char *) malloc (size + 1);			// one line read from STDIN

	int curt_cid = -1;							// current customer id
	int curt_cnt = 0;							// current count of transTotal by each customer id
	double curt_sum = 0;						// current sum of transTotal by each customr id

	char *cid = (char *) malloc (size + 1);		// customer id read from newly retrieved aLine
	char *total = (char *) malloc (size + 1);	// transTotal read from newly retrieved aLine

	while ( getline(&aLine, &size, stdin) != -1) {

		// retrieve customer id and transaction total
		cid = strtok (aLine, "\t");
		total = strtok (NULL, "\t");

		//printf("cid: %s | curt_cid: %d\n", cid, curt_cid); delete

		if( curt_cid == atoi(cid) ) {
			curt_cnt ++;
			curt_sum += atof(total);
		}
		else {

			//printf("curt_cid: %d\n", curt_cid); delete

			if( curt_cid != -1 ) {
				// print customer id, count of transTotal, sum of transTotal for each customer id, except last retrieved customer id
				printf("%d,%d,%f\n", curt_cid, curt_cnt, curt_sum);
				curt_cid = -1;
				curt_cnt = 0;
				curt_sum = 0;
			}
			curt_cid = atoi(cid);
			curt_cnt ++;
			curt_sum += atof(total);

			//printf("curt_cid: %d after\n", curt_cid); delete

		}	
	}

	// print customer id, count of transTotal, sum of transTotal for last customer id
	if( curt_cid != -1 ) {
		printf("%d,%d,%f\n", curt_cid, curt_cnt, curt_sum);
		curt_cid = -1;
		curt_cnt = 0;
		curt_sum = 0;
	}

	return 0;
}
