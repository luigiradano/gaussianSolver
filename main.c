#include <stdlib.h>

#include "gSolve.h"

#define MAT_X 300
#define MAT_Y 300
#define RUNS 10000

void printVect(int size, double m[]) {
   	int j;
	for (j = 0; j < size; j++) {
   		printf("%.2f ", m[j]);
   	}	
   	printf("\n"); 
}

void initMat(int cols, int rows, double mat[rows][cols]){
	for(int i = 0; i < cols; i++){
		for(int j = 0; j < rows; j++){
			mat[i][j] = 0;
		}
	}
}

double randD() {
    uint64_t r53 = ((uint64_t)(rand()) << 21) ^ (rand() >> 2);
    return (double)r53 / 740991.0; // 2^53 - 1
}

void randMat(uint32_t cols, uint32_t rows, double mat[rows][cols]){
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			mat[i][j] = randD(); 
		}
	}
}

int main(){
	
	double knownMat[MAT_X][MAT_Y];
	double knownVec[MAT_Y];
	double xVec[MAT_Y];
		randMat(MAT_Y, MAT_X, knownMat);
		randMat(1,MAT_Y, knownVec);	

	for(int i=0; i<RUNS; i++){
		

		solveSystem(MAT_Y, MAT_X, knownMat, knownVec, xVec);
		//printf("RUN: %d\tRES: %2.3f\n", i, getResidual(MAT_X, MAT_Y, knownMat, knownVec, xVec));
		//printVect(MAT_Y, xVec);
	}		
}
