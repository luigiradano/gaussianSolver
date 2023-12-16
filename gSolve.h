#include <stdint.h>
#include <stdio.h>
#include <math.h>
#define MAX_MATRIX_COLS 10


void solveSystem(uint32_t cols, uint32_t rows, double knownMat[rows][cols], double knownVec[], double xVec[]);
void printMat(uint32_t cols, uint32_t rows, double mat[cols][rows]);
double getResidual(uint32_t cols, uint32_t rows, double knownMat[rows][cols], double knownVec[], double xVec[]);
