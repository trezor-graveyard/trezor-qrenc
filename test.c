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

int main(void)
{
	int side, i, j, a, ecclevel;
	uint8_t bitdata[QR_MAX_BITDATA];
	char str[2048];

	printf("ECC Level [LMQH]: ");
	if (!fgets(str, sizeof(str), stdin)) {
		return 1;
	}
	switch (str[0]) {
	case 'l':
	case 'L':
		ecclevel = QR_LEVEL_L;
		break;
	case 'm':
	case 'M':
	default:
		ecclevel = QR_LEVEL_M;
		break;
	case 'q':
	case 'Q':
		ecclevel = QR_LEVEL_Q;
		break;
	case 'h':
	case 'H':
		ecclevel = QR_LEVEL_H;
		break;
	}

	printf("Enter string: ");
	if (!fgets(str, sizeof(str), stdin)) {
		return 1;
	}
	// remove newline
	if (str[strlen(str) - 1] == '\n') {
		str[strlen(str) - 1] = 0;
	}

	side = qr_encode(ecclevel, 0, str, 0, bitdata);

	printf("side: %d\n", side);

	for (i = 0; i < side + 2; i++) printf("██");
	printf("\n");
	for (i = 0; i < side; i++) {
		printf("██");
		for (j = 0; j < side; j++) {
			a = i * side + j;
			printf((bitdata[a / 8] & (1 << (7 - a % 8))) ? "  " : "██");
		}
		printf("██");
		printf("\n");
	}
	for (i = 0; i < side + 2; i++) printf("██");
	printf("\n");

	return 0;
}
