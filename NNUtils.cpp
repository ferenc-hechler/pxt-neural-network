#ifndef NNUTILS_H
#define NNUTILS_H

#include "Vect.h"
#include "Mat.h"

#include <stdlib.h>
#include <time.h>


void initRand() {
	 time_t t;
	 srand((unsigned) time(&t));
	 rand(); rand(); rand();
}

void fillRandom(Mat* mat, float from, float to) {
	float diff = to-from;
	int maxR = mat->getRows();
	int maxC = mat->getCols();
	for (int r=0; r<maxR; r++) {
		for (int c=0; c<maxC; c++) {
			float v = ((float) (rand() % 1001))/1001.0f;
			float vRange = from+diff*v;
			mat->set(r, c, vRange);
		}
	}
}

void fillRandom(Vect* vect, float from, float to) {
	float diff = to-from;
	for (int i=0; i<vect->getLength(); i++) {
		float v = ((float) (rand() % 1001))/1001.0f;
		float vRange = from+diff*v;
		vect->set(i, vRange);
	}
}

void fillRandomNorm(Mat* mat, float from, float to) {
	float diff = to-from;
	int maxR = mat->getRows();
	int maxC = mat->getCols();
	for (int r=0; r<maxR; r++) {
		for (int c=0; c<maxC; c++) {
			float v = ((float) ((rand() % 1001)+(rand() % 1001)+(rand() % 1001)))/3003.0;
			float vRange = from+diff*v;
			mat->set(r, c, vRange);
		}
	}
}

void fillRandomNorm(Vect* vect, float from, float to) {
	float diff = to-from;
	for (int i=0; i<vect->getLength(); i++) {
		float v = ((float) ((rand() % 1001)+(rand() % 1001)+(rand() % 1001)))/3003.0;
		float vRange = from+diff*v;
		vect->set(i, vRange);
	}
}


void fill(Vect* vect, float v) {
	for (int i=0; i<vect->getLength(); i++) {
		vect->set(i, v);
	}
}

void fill(Mat* mat, float v) {
	for (int r=0; r<mat->getRows(); r++) {
		for (int c=0; c<mat->getRows(); r++) {
			mat->set(r,c, v);
		}
	}
}


float relu(float f) {
	if (f<0.0f) {
		return 0.0f;
	}
	return f;
}

void relu(Vect *vect) {
	for (int i=0; i<vect->getLength(); i++) {
		vect->set(i, relu(vect->get(i)));
	}
}

float relu_prime(float f) {
	if (f<0.0f) {
		return 0.0f;
	}
	return 1.0f;
}

void relu_prime(Vect *vect) {
	for (int i=0; i<vect->getLength(); i++) {
		vect->set(i, relu_prime(vect->get(i)));
	}
}



#endif // NNUTILS_H
