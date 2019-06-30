#include "pxt.h"
#include "MicroBit.h"

#include "NN.h"

using namespace pxt;

namespace nn {

	static NN *brain = 0;

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
		uBit.serial.printf("train not yet implemented\r\n");
		return -1.0f;
	}


	//% blockId=nn_predict
	//% block="Predict|"
	//% shim=nn::predict
	RefCollection *predict(RefCollection &input) {
		uBit.serial.printf("train not yet implemented\r\n");
		return 0;
	}

}
