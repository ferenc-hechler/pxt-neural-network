#include "pxt.h"
#include "MicroBit.h"

using namespace pxt;

namespace nn {

	//% blockId=nn_test
	//% block="Test"
	//% shim=nn::test
	void test() {
	    uBit.serial.send("CALL: test()\r\n");
		uBit.display.scroll("cpp-NN-test");
	}

//	static char *buf = 0;
//
//	void cleanup() {
//		if (buf != 0) {
//			delete buf;
//			buf = 0;
//		}
//	}

	//% blockId=nn_show
	//% block="Show"
	//% shim=nn::show
	void show(String text) {
	    uBit.serial.send("CALL: show(...)\r\n");
		const char *msg = PXT_STRING_DATA(text);
	    uBit.serial.printf("show(%s)\r\n", msg);
		uBit.display.scroll(msg);
	}


	static int cnt = 0;

	//% blockId=nn_gettime
	//% block="Current Time"
	//% shim=nn::gettime
	String gettime() {
	    uBit.serial.send("CALL: gettime()\r\n");

	    char buf[30];
	    cnt += 1;
	    sprintf(buf, "cpp-%d", cnt);
	    return mkString(buf);
	}

}
