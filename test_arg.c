/*
 * Copyright (c) 2012-2014 Pavol Rusnak <stick@gk2.sk>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <string.h>
#include "qr_encode.h"

/**
 * The same as test.c, only it reads from the first argument
 * and prints 0s and 1s instead of picture.
 *
 * It's used for compiling to JavaScript, because we can set up
 * argument and read 1/0s more easily
 */
int main(int argc, char **argv)
{
	int side, i, j, a;
	uint8_t bitdata[QR_MAX_BITDATA];

    if (argc<2){
        printf("1");
        return 1;
    }

    char *str=argv[1];

	side = qr_encode(QR_LEVEL_M, 0, str, 0, bitdata);


	//for (i = 0; i < side + 2; i++) printf("1");
	for (i = 0; i < side; i++) {
	//	printf("1");
		for (j = 0; j < side; j++) {
			a = i * side + j;
			printf((bitdata[a / 8] & (1 << (7 - a % 8))) ? "0" : "1");
		}
	//	printf("1");
	}
	//for (i = 0; i < side + 2; i++) printf("1");

	return 0;
}
