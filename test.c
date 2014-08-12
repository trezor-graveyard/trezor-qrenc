#include <stdio.h>
#include "qr_encode.h"

int main(void)
{
	int side, i, j, a;
	uint8_t bitdata[QR_MAX_BITDATA];
	char str[2048];

	printf("Enter string: ");
	fgets(str, sizeof(str), stdin);

	side = qr_encode(QR_LEVEL_M, 0, str, 0, bitdata);

	printf("side: %d\n", side);

	for (i = 0; i < side+2; i++) printf("██");
	printf("\n");
	for (i = 0; i < side; i++) {
		printf("██");
		for (j = 0; j< side; j++) {
			a = i * side + j;
			printf((bitdata[a / 8] & (1 << (7 - a % 8))) ? "  " : "██");
		}
		printf("██");
		printf("\n");
	}
	for (i = 0; i < side+2; i++) printf("██");
	printf("\n");

	return 0;
}
