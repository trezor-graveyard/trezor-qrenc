#include "qr_encode.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	int side, i, j, a;
	unsigned char bitdata[MAX_BITDATA];

	if (argc < 2) {
		printf("Pass string as first command line parameter.\n");
		return 1;
	}

	side = QREncode(QR_LEVEL_H, 0, argv[1], 0, bitdata);

	for (i = 0; i < side+2; i++) printf("██");
	printf("\n");
	for (i = 0; i < side; i++) {
		printf("██");
		for (j = 0; j< side; j++) {
			a = i*side + j;
			printf((bitdata[a/8] & (1<<(7-a%8))) ? "  " : "██");
		}
		printf("██");
		printf("\n");
	}
	for (i = 0; i < side+2; i++) printf("██");
	printf("\n");

	return 0;
}
