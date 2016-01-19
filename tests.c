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

#include <check.h>
#include <stdlib.h>
#include <stdio.h>

#include "tests_results.h"

#include "qr_encode.h"

int bitsize(int side) {
	return (side * side + 7) / 8;
}

START_TEST(test_numeral)
{
	int side;
	uint8_t bitdata[QR_MAX_BITDATA];

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_L, 0, "1234567890", 0, bitdata);
	ck_assert_int_eq(side, 21);
	ck_assert_int_eq(memcmp(bitdata, RESULT_NUMERAL_1, bitsize(side)), 0);

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_M, 0, "1234567890", 0, bitdata);
	ck_assert_int_eq(side, 21);
	ck_assert_int_eq(memcmp(bitdata, RESULT_NUMERAL_2, bitsize(side)), 0);

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_Q, 0, "1234567890", 0, bitdata);
	ck_assert_int_eq(side, 21);
	ck_assert_int_eq(memcmp(bitdata, RESULT_NUMERAL_3, bitsize(side)), 0);

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_H, 0, "1234567890", 0, bitdata);
	ck_assert_int_eq(side, 21);
	ck_assert_int_eq(memcmp(bitdata, RESULT_NUMERAL_4, bitsize(side)), 0);

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_L, 0, "12345678901234567890123456789012345678901234567890", 0, bitdata);
	ck_assert_int_eq(side, 25);
	ck_assert_int_eq(memcmp(bitdata, RESULT_NUMERAL_5, bitsize(side)), 0);

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_M, 0, "12345678901234567890123456789012345678901234567890", 0, bitdata);
	ck_assert_int_eq(side, 25);
	ck_assert_int_eq(memcmp(bitdata, RESULT_NUMERAL_6, bitsize(side)), 0);

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_Q, 0, "12345678901234567890123456789012345678901234567890", 0, bitdata);
	ck_assert_int_eq(side, 29);
	ck_assert_int_eq(memcmp(bitdata, RESULT_NUMERAL_7, bitsize(side)), 0);

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_H, 0, "12345678901234567890123456789012345678901234567890", 0, bitdata);
	ck_assert_int_eq(side, 29);
	ck_assert_int_eq(memcmp(bitdata, RESULT_NUMERAL_8, bitsize(side)), 0);
}
END_TEST

START_TEST(test_alphabet)
{
	int side;
	unsigned char bitdata[QR_MAX_BITDATA];

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_L, 0, "test", 0, bitdata);
	ck_assert_int_eq(side, 21);
	ck_assert_int_eq(memcmp(bitdata, RESULT_ALPHA_1, bitsize(side)), 0);

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_M, 0, "test", 0, bitdata);
	ck_assert_int_eq(side, 21);
	ck_assert_int_eq(memcmp(bitdata, RESULT_ALPHA_2, bitsize(side)), 0);

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_Q, 0, "test", 0, bitdata);
	ck_assert_int_eq(side, 21);
	ck_assert_int_eq(memcmp(bitdata, RESULT_ALPHA_3, bitsize(side)), 0);

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_H, 0, "test", 0, bitdata);
	ck_assert_int_eq(side, 21);
	ck_assert_int_eq(memcmp(bitdata, RESULT_ALPHA_4, bitsize(side)), 0);

#if QR_MAX_VERSION >= QR_VERSION_M
	const char *lipsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras at risus sodales, rhoncus arcu eu, accumsan augue. Mauris a mauris et ante porta eleifend. Sed condimentum metus vitae tortor bibendum, et scelerisque quam placerat. Nam at sapien lacus. Proin magna ipsum, dapibus non dignissim a, posuere vitae nulla. Donec pretium odio sit amet lorem interdum, nec ullamcorper diam iaculis. Mauris at est sit amet purus venenatis pretium vitae sed magna.";

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_L, 0, lipsum, 0, bitdata);
	ck_assert_int_eq(side, 73);
	ck_assert_int_eq(memcmp(bitdata, RESULT_ALPHA_5, bitsize(side)), 0);

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_M, 0, lipsum, 0, bitdata);
	ck_assert_int_eq(side, 85);
	ck_assert_int_eq(memcmp(bitdata, RESULT_ALPHA_6, bitsize(side)), 0);

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_Q, 0, lipsum, 0, bitdata);
	ck_assert_int_eq(side, 97);
	ck_assert_int_eq(memcmp(bitdata, RESULT_ALPHA_7, bitsize(side)), 0);

	memset(bitdata, sizeof(bitdata), 0);
	side = qr_encode(QR_LEVEL_H, 0, lipsum, 0, bitdata);
	ck_assert_int_eq(side, 109);
	ck_assert_int_eq(memcmp(bitdata, RESULT_ALPHA_8, bitsize(side)), 0);
#endif
}
END_TEST


// define test suite and cases
Suite *test_suite(void)
{
	Suite *s = suite_create("microqrcode");
	TCase *tc;

	tc = tcase_create("qr");
	tcase_add_test(tc, test_numeral);
	tcase_add_test(tc, test_alphabet);
	suite_add_tcase(s, tc);

	return s;
}

// run suite
int main(void)
{
	int number_failed;
	Suite *s = test_suite();
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return number_failed;
}
