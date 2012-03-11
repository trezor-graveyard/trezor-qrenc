#include <stdio.h>
#include "qr_encode.h"

int main()
{
	int side, i, j, a;
	unsigned char bitdata[MAX_BITDATA];
	char str[1024];

	printf("Enter string: ");
	fgets(str, 1024, stdin);

	side = QREncode(QR_LEVEL_H, 0, str, 0, bitdata);

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
