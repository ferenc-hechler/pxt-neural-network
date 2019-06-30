#ifndef NNUTILS_H
#define NNUTILS_H

class Vect;
class Mat;

void initRand();

void fillRandomNorm(Mat* mat, float from, float to);
void fillRandomNorm(Vect* vect, float from, float to);

void fillRandom(Mat* mat, float from, float to);
void fillRandom(Vect* vect, float from, float to);

void fill(Vect* vect, float v);
void fill(Mat* mat, float v);

float relu(float f);
void relu(Vect *vect);

float relu_prime(float f);
void relu_prime(Vect *vect);

#endif // NNUTILS_H
