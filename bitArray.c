#include <stdlib.h>

#include "bitArray.h"

struct _bitArray
{
	int nBits;
	WORD * bits;
};

bitArray * createBitArray(int bits)
{
	bitArray * a = malloc(sizeof(bitArray));
	if(!a)
		return NULL;
	int words = bits/WORD_SIZE + (bits%WORD_SIZE != 0);
	a->nBits = bits;
	a->bits = calloc(sizeof(WORD), words);
	return a;
}

int deleteBitArray(bitArray * a)
{
	if(!a)
		return 0;
	free(a->bits);
	free(a);
	return 1;
}

int setBit(bitArray * a, int bit, int value)
{
	if(!a || bit >= a->nBits || bit < 0)
		return 0;
	int word = bit/WORD_SIZE;
	WORD cursor = 1 << bit%WORD_SIZE;
	if(value)
		a->bits[word] |= cursor;
	else
		a->bits[word] &= ~cursor;
	return 1;
}

int flipBit(bitArray * a, int bit)
{
	if(!a || bit >= a->nBits || bit < 0)
		return -1;
	int word = bit/WORD_SIZE;
	WORD cursor = 1 << bit%WORD_SIZE;
	a->bits[word] ^= cursor;
	return 1;
}

int getBit(bitArray * a, int bit)
{
	if(!a || bit >= a->nBits || bit < 0)
		return -1;
	int word = bit/WORD_SIZE;
	return 1 & (a->bits[word] >> bit%WORD_SIZE);
}

int nBits(bitArray * a)
{
	if(!a)
		return -1;
	return a->nBits;
}
