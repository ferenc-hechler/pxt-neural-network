#include "pxt.h"
#include "MicroBit.h"
#include "Utils.h"
#include "Mat.h"
#include "Vect.h"

//#include<stdio.h>
#include<stdarg.h>
//#include<string.h>
//#include <math.h>
//#include <float.h>
//#include <iostream>


// from: https://github.com/espressif/arduino-esp32/blob/master/cores/esp32/Print.cpp
size_t float2char(char* buf, float number, uint8_t digits) {
  size_t n = 0;

  if (isnan(number)) return sprintf(buf, "nan");
  if (isinf(number)) return sprintf(buf, "inf");
  if(number > 4294967040.0) {
      return sprintf(buf, "ovf");    // constant determined empirically
  }
  if(number < -4294967040.0) {
      return sprintf(buf, "ovf");    // constant determined empirically
}

  // Handle negative numbers
  if (number < 0.0)
  {
     n += sprintf((char*)(buf+n), "-");
     number = -number;
  }

  // Round correctly so that print(1.999, 2) prints as "2.00"
  float rounding = 0.5;
  for (uint8_t i=0; i<digits; ++i)
    rounding /= 10.0;

  number += rounding;

  // Extract the integer part of the number and print it
  unsigned long int_part = (unsigned long)number;
  double remainder = number - (double)int_part;
  n += sprintf((char*)(buf+n), "%lu", int_part);

  // Print the decimal point, but only if there are digits beyond
  if (digits > 0) {
    n += sprintf((char*)(buf+n), ".");
  }

  // Extract digits from the remainder one at a time
  while (digits-- > 0)
  {
    remainder *= 10.0;
    int toPrint = int(remainder);
    n += sprintf((char*)(buf+n), "%d",toPrint);
    remainder -= toPrint;
  }

  return n;
}

Vect createVect(int length, ...) {
	va_list argp;
	va_start(argp, length);
	Vect result = Vect(length);
	for (int i=0; i<length; i++) {
		float f = va_arg(argp, double);
		result.set(i, f);
	}
	va_end(argp);
	return result;
}

Mat createMat(int rows, int cols, ...) {
	va_list argp;
	va_start(argp, cols);
	Mat result = Mat(rows, cols);
	for (int r=0; r<rows; r++) {
		for (int c=0; c<cols; c++) {
			float f = va_arg(argp, double);
			result.set(r,c, f);
		}
	}
	va_end(argp);
	return result;
}


void throwError(const char *errMsg) {
	while (true) {
		uBit.display.scroll(errMsg);
        uBit.sleep(1000);
        if ( uBit.buttonA.isPressed() == true ) {
        	uBit.sleep(24*60*60*1000);
        }
	}
}

void log(const char *msg) {
	uBit.serial.send(msg);
}

void logFloat(float f) {
	char buf[30];
	float2char(buf, f, 3);
	log(buf);
}

void logInt(int i) {
	char buf[30];
	sprintf(buf, "%d", i);
	log(buf);
}
