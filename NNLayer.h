#ifndef NNLAYER_H
#define NNLAYER_H

class Mat;
class Vect;

class NNLayer
{
	int num_input;
	int num_output;
	Mat *w;
	Vect *b;
	Vect *_z;
	Vect *_x;

public:

	NNLayer(int num_input, int num_output);

	Vect* forwardPropagate(const Vect* input);
	Vect* backwardPropagate(const Vect *e, float lr);

	int getNumInput() const;
	int getNumOutput() const;

	void print() const;

	~NNLayer();
};


#endif  // NNLAYER_H
