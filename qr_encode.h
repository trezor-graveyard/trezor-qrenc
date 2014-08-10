/*
 * Copyright (c) 2010 Psytec Inc.
 * Copyright (c) 2012 Alexey Mednyy <swexru@gmail.com>
 * Copyright (c) 2012 Pavol Rusnak <stick@gk2.sk>
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

#include <stdint.h>

// Constants

// Error correction level
#define QR_LEVEL_L         0    //  7% of codewords can be restored
#define QR_LEVEL_M         1    // 15% of codewords can be restored
#define QR_LEVEL_Q         2    // 25% of codewords can be restored
#define QR_LEVEL_H         3    // 30% of codewords can be restored

// Data Mode
#define QR_MODE_NUMERAL    0    // numbers
#define QR_MODE_ALPHABET   1    // alphanumberic
#define QR_MODE_8BIT       2    // rest

// Group version (Model number)
#define QR_VERSION_S       0    //  1 -  9
#define QR_VERSION_M       1    // 10 - 26
#define QR_VERSION_L       2    // 27 - 40

// Length constants
#define MAX_ALLCODEWORD    3706 // Maximum total number of code words
#define MAX_DATACODEWORD   2956 // Maximum data word code (version 40-L)
#define MAX_CODEBLOCK      153  // Maximum number of block data code word (including RS code word)
#define MAX_MODULESIZE     177  // Maximum number of modules in a side
#define MAX_BITDATA        3917 // Maximum size of bit data

//
// * level - error correction level, use QR_LEVEL_? macros
// * version - version of the code (1-40), use 0 for autodetection
// * source - source data
// * source_len - length of the source data, use 0 when passing zero-terminated string
// * result - array to write, writes to bits
//
// * function returns the size of the square side
//
int qr_encode(int level, int version, const char *source, size_t source_len, uint8_t *result);
