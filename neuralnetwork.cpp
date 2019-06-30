#include "pxt.h"
#include "MicroBit.h"

#include "NN.h"
#include "Vect.h"

using namespace pxt;

namespace nn {

	static NN *brain = 0;


	Vect *toVect(RefCollection &param) {
	    int len = param.length();
	    Vect *result = new Vect(len);
	    for (int i=0; i<len; i++) {
		    TNumber tn = param.getAt(i);
			float f = toFloat(tn);
			result->set(i, f);
	    }
	    return result;
	}

	RefCollection *toRefCollection(Vect *vect) {
	    int len = vect->getLength();
	    RefCollection *result = Array_::mk();
	    for (int i=0; i<len; i++) {
	    	float v = vect->get(i);
		    Array_::insertAt(result, i, fromFloat(v));
	    }
	    return result;
	}


	//% blockId=nn_initFCNN
	//% block="Init Brain|number %inputs|number[] %hidden|number %outputs"
	//% shim=nn::initFCNN
	void initFCNN(int inputs, RefCollection &hidden, int outputs) {

		if (brain != 0) {
			delete brain;
		}
		brain = new NN(inputs);

	    int numHidden = hidden.length();
	    uBit.serial.printf("creating FCNN: in:%d, hidden-layers:%d, out:%d\r\n", inputs, numHidden, outputs);
	    for (int i=0; i<numHidden; i++) {
		    TNumber tn = hidden.getAt(i);
			int nodes = toInt(tn);
			brain->addLayer(nodes);
		    uBit.serial.printf("    hidden layer #%d: %d\r\n", i, nodes);
	    }

		brain->addLayer(outputs);

	    uBit.serial.printf("FCNN successfully created\r\n");
	}


	//% blockId=nn_train
	//% block="Train|number[] %input|number %expected_output"
	//% shim=nn::train
	float train(RefCollection &input, RefCollection &expected_output) {
		float learning_rate = 0.001;
		Vect *x = toVect(input);
		Vect *y = toVect(expected_output);
		Vect *y_hat = brain->forwardPropagate(x);
		Vect *e = brain->backwardPropagate(y, y_hat, learning_rate);
		y_hat->sub(y);
		y_hat->sqr();
		float sum_sq_err = y_hat->sum();
		delete x;
		delete y;
		delete y_hat;
		delete e;
		return sum_sq_err;
	}


	//% blockId=nn_predict
	//% block="Predict|"
	//% shim=nn::predict
	RefCollection *predict(RefCollection &input) {
		Vect *x = toVect(input);
		Vect *y_hat = brain->forwardPropagate(x);
		RefCollection *result = toRefCollection(y_hat);
		delete x;
		delete y_hat;
		return result;
	}



}
