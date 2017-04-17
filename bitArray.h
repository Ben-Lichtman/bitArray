#define WORD                char//Pick your data type of choice

#define WORD_SIZE           8 * sizeof(WORD)//Bits in a WORD

typedef struct _bitArray bitArray;

bitArray * createBitArray   (int bits);

int deleteBitArray          (bitArray *);

int setBit                  (bitArray *, int bit, int value);

int flipBit                 (bitArray *, int bit);

int getBit                  (bitArray *, int bit);

int nBits                   (bitArray *);
