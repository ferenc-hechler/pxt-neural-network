#include "Mat.h"
#include "Vect.h"
#include "NNLayer.h"
#include "NNUtils.h"
#include "Utils.h"
#include <stdio.h>
#include <math.h>



NNLayer::NNLayer(int num_input, int num_output) {
	this->num_input = num_input;
	this->num_output = num_output;
	w = new Mat(num_input, num_output);
	fillRandomNorm(w, -1.0f, 1.0f);
	w->multiply(sqrt(2.0f/num_input));
	b = new Vect(num_output);
	fill(b, 0.1f);
	_x = 0;
	_z = 0;
}


int NNLayer::getNumInput() const {
	return num_input;
}

int NNLayer::getNumOutput() const {
	return num_output;
}


Vect* NNLayer::forwardPropagate(const Vect *x) {
	if (_x != 0) {
		delete _x;
		delete _z;
	}
	_x = new Vect(x);
	_z = x->multiplyC(w);
	_z->add(b);
	Vect *result = new Vect(_z);
	relu(result);
	return result;
}

Vect* NNLayer::backwardPropagate(const Vect *e, float lr) {
	if (_z == 0) {
		print();
		throwError("calling backProp without haveing called forwardProp.");
	}
	Vect *e_zrp = new Vect(_z);
	relu_prime(e_zrp);
	e_zrp->multiply(e);
	Mat *dw = e_zrp->multiplyCR(_x);
	dw->multiply(lr);
	w->sub(dw);
	Vect* e_in = e->multiplyR(w);
	delete e_zrp;
	delete dw;
	return e_in;
}

void NNLayer::print() const {
	printf("NNLayer(%d, %d)", num_input, num_output);
	w->print();
	b->print();
}

NNLayer::~NNLayer() {
	if (_x != 0) {
		delete _x;
		delete _z;
		_x=0;
		_z=0;
	}
	delete w;
	delete b;
	w = 0;
	b = 0;
}
