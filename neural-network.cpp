#include "pxt.h"
#include "MicroBit.h"

using namespace pxt;

namespace feri {

	//% blockId=nn_Test
	//% block="Test"
	//% shim=nn::test
	void test() {
		uBit.display.scroll("cpp-NN-test");
	}

}
