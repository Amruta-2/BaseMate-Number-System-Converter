#ifndef LOGIC_H
#define LOGIC_H

void showHistory();
void clearHistory();
void clearInputBuffer();


// Validation
int getValidatedDecimal();  // returns validated int
void getValidatedBinary(char binary[]);
void getValidatedOctal(char octal[]);
void getValidatedHexadecimal(char hex[]);

// Conversion functions
void decToBin(int decimal, int showsteps);
void binToDec(char binary[], int showsteps);
void decToOct(int decimal, int showsteps);
void octToDec(char octal[], int showsteps);
void decToHex(int decimal, int showsteps);
void hexToDec(char hex[], int showsteps);
void binToHex(char binary[], int showsteps);
void hexToBin(char hex[], int showsteps);

// Step-by-step prompt handler
void promptStepByStepAndCall(void (*conversionFunc)(int));

#endif
