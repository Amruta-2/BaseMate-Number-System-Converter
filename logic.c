#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "logic.h"



void logConversion(const char *input, const char *output, int fromBase, int toBase)
{
    // Get current timestamp
    time_t now = time(NULL);
    char timestamp[30];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Open history file in append mode
    FILE *log = fopen("history.txt", "a");
    if (log)
    {
        fprintf(log, "%s ➜ %s | Base %d ➜ %d | %s\n", input, output, fromBase, toBase, timestamp);
        fclose(log);
    }
}



int getValidatedDecimal() {
    int decimal;
    printf("Enter Decimal number: ");
    while (scanf("%d", &decimal) != 1 || decimal < 0) {
        printf("❌ Invalid input. Enter a positive decimal number: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    return decimal;
}

void getValidatedBinary(char binary[]) {
    int i;

    printf("Enter a Binary Number: ");
    scanf("%s", binary);

    for (i = 0; binary[i] != '\0'; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("❌ Invalid input. Only 0 and 1 allowed.\n");
            getValidatedBinary(binary);
            return;
        }
    }
}

void getValidatedOctal(char octal[]) {
    int i;

    printf("Enter an Octal Number: ");
    scanf("%s", octal);

    for (i = 0; octal[i] != '\0'; i++) {
        if (octal[i] < '0' || octal[i] > '7') {
            printf("❌ Invalid input. Only digits 0–7 allowed.\n");
            getValidatedOctal(octal);
            return;
        }
    }
}

void getValidatedHexadecimal(char hex[]) {
    int i;

    printf("Enter a Hexadecimal Number: ");
    scanf("%s", hex);

    for (i = 0; hex[i] != '\0'; i++) {
        if (!((hex[i] >= '0' && hex[i] <= '9') ||
              (hex[i] >= 'A' && hex[i] <= 'F') ||
              (hex[i] >= 'a' && hex[i] <= 'f'))) {
            printf("❌ Invalid input. Only 0–9 and A–F allowed.\n");
            getValidatedHexadecimal(hex);
            return;
        }
    }
}


void decToBin(int decimal,int showsteps)
{
    int  i = 0, step = 1;
    int binary[32];  // Array to store binary digits (max 32 bits for an int)

    // Handle the special case when input is 0
    if (decimal == 0)
    {
        printf("Binary of 0 is: 0\n");
        logConversion("0", "0", 10, 2);
        return;
    }

    int original = decimal;

    // Step-by-step explanation
    if (showsteps)
    {
        printf("\n--- Step-by-step Conversion ---\n");
    }

    // Loop to convert decimal to binary
    while (decimal > 0)
    {
        int quotient = decimal / 2;
        int remainder = decimal % 2;
        binary[i++] = remainder;

        if (showsteps)
        {
            printf("Step %d: %d / 2 = %d, Remainder = %d\n", step++, decimal, quotient, remainder);
        }

        decimal = quotient;
    }

    // Display result
    printf("Binary of %d is: ", original);
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
    printf("\n");

    // Prepare log data
    char output[33] = "";
    for (int j = i - 1; j >= 0; j--)
        output[i - 1 - j] = binary[j] + '0';
    output[i] = '\0';

    char inputStr[20];
    sprintf(inputStr, "%d", original);

    logConversion(inputStr, output, 10, 2);
}


void binToDec(char binary[], int showsteps)
{
    int decimal = 0;       // Final decimal result

    int length = strlen(binary);  // Find the length of the input string

    // Validate and process binary input
    for (int i = 0; i < length; i++)
    {
        char ch = binary[i];

        // Validate binary digits
        if (ch != '0' && ch != '1')
        {
            printf("Invalid binary digit '%c' at the position %d. Only 0 and 1 are allowed.\n", ch, i + 1);
            return;
        }
    }

    // Optional step-by-step display
    if (showsteps)
    {
        printf("\n--- Step-by-step Conversion ---\n");
    }

    // Convert binary to decimal
    for (int i = 0; i < length; i++)
    {
        int bit = binary[i] - '0';
        int power = length - 1 - i;
        int value = bit * (1 << power);
        decimal += value;

        if (showsteps)
        {
            printf("Step %d: (%d * 2^%d) = %d, Accumulated Decimal = %d\n", i + 1, bit, power, value, decimal);
        }
    }

    // Display the final result
    printf("Decimal of %s is: %d\n", binary, decimal);

    // Logging
    char output[20];
    sprintf(output, "%d", decimal);
    logConversion(binary, output, 2, 10);
}



void decToOct(int decimal, int showsteps)
{
    int octal[32], i = 0, step = 1;

    // Special case: when input is 0
    if (decimal == 0)
    {
        printf("Octal: 0\n");
        logConversion("0", "0", 10, 8);
        return;
    }

    int original = decimal;  // Store original value for displaying in output

    if (showsteps)
    {
        printf("\n--- Step-by-step Conversion ---\n");
    }

    // Convert decimal to octal using repeated division by 8
    while (decimal > 0)
    {
        int remainder = decimal % 8;
        int quotient = decimal / 8;
        octal[i++] = remainder;

        if (showsteps)
        {
            printf("Step %d: %d / 8 = %d, Remainder = %d\n", step++, decimal, quotient, remainder);
        }

        decimal = quotient;
    }

    // Print the octal result in reverse (most significant digit first)
    printf("\nOctal of %d is : ", original);
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", octal[j]);
    }
    printf("\n");

    // Prepare output string for logging
    char output[33];
    for (int j = 0; j < i; j++)
        output[j] = octal[i - 1 - j] + '0';
    output[i] = '\0';

    char inputStr[20];
    sprintf(inputStr, "%d", original);
    logConversion(inputStr, output, 10, 8);
}


void octToDec(char octal[], int showsteps)
{
    int decimal = 0;        // Resulting decimal value


    int length = strlen(octal);  // Get length of input

    if (showsteps)
    {
        printf("\n--- Step-by-step Conversion ---\n");
    }

    // Loop through each digit of the octal input
    for (int i = 0; i < length; i++)
    {
        char ch = octal[i];  // Current digit

        // Validate if character is a valid octal digit (0-7)
        if (ch < '0' || ch > '7')
        {
            printf("Invalid octal digit '%c' at position %d. Only digits 0-7 are allowed.\n", ch, i + 1);
            return;
        }

        // Convert character to decimal and accumulate
        int digit = ch - '0';
        decimal = decimal * 8 + digit;

        if (showsteps)
        {
            printf("Step %d: Decimal = Decimal * 8 + %d => %d\n", i + 1, digit, decimal);
        }
    }

    // Display the result
    printf("\nDecimal of %s is : %d\n", octal, decimal);

    char output[20];
    sprintf(output, "%d", decimal);
    logConversion(octal, output, 8, 10);
}


void decToHex(int decimal, int showsteps)

{
    int  i = 0;
    char hex[32];  // Array to store hexadecimal digits

    // Special case: if the input is 0
    if (decimal == 0)
    {
        printf("Hexadecimal: 0\n");
        logConversion("0", "0", 10, 16);
        return;
    }

    int original = decimal;  // Store the original input for final output

    if (showsteps)
    {
        printf("\n--- Step-by-step Conversion ---\n");
    }

    // Loop to convert decimal to hexadecimal
    while (decimal > 0)
    {
        int remainder = decimal % 16;  // Get the remainder
        int quotient = decimal / 16;

        // Convert remainder to appropriate hex digit
        char digit;
        if (remainder < 10)
            digit = '0' + remainder;        // 0–9
        else
            digit = 'A' + (remainder - 10); // A–F

        hex[i++] = digit;

        if (showsteps)
        {
            printf("Step %d: %d / 16 = %d, Remainder = %d => Hex Digit = %c\n", i, decimal, quotient, remainder, digit);
        }

        decimal = quotient;  // Divide decimal by 16
    }

    // Print the hexadecimal number in reverse order
    printf("\nHexadecimal of %d is: ", original);
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hex[j]);
    }
    printf("\n");

    // Prepare string for logging
    char output[33];
    for (int j = 0; j < i; j++)
        output[j] = hex[i - 1 - j];
    output[i] = '\0';

    char inputStr[20];
    sprintf(inputStr, "%d", original);
    logConversion(inputStr, output, 10, 16);
}


void hexToDec(char hex[], int showsteps)
{
    int decimal = 0;     // Final result

   
    int length = strlen(hex);  // Get length of the input

    if (showsteps)
    {
        printf("\n--- Step-by-step Conversion ---\n");
    }

    // Loop through each character of the hexadecimal input
    for (int i = 0; i < length; i++)
    {
        char ch = toupper(hex[i]);  // Convert to uppercase for uniformity
        int value;

        // Convert valid hex character to its numeric value
        if (ch >= '0' && ch <= '9')
            value = ch - '0';
        else if (ch >= 'A' && ch <= 'F')
            value = ch - 'A' + 10;
        else
        {
            // Invalid character found
            printf("Invalid hexadecimal digit '%c' at position %d. Only 0-9 and A-F are allowed.\n", ch, i + 1);
            return;
        }

        // Accumulate decimal value
        int prevDecimal = decimal;
        decimal = decimal * 16 + value;

        if (showsteps)
        {
            printf("Step %d: Decimal = %d * 16 + %d => %d\n", i + 1, prevDecimal, value, decimal);
        }
    }

    // Print the final decimal result
    printf("\nDecimal of %s is: %d\n", hex, decimal);

    char output[20];
    sprintf(output, "%d", decimal);
    logConversion(hex, output, 16, 10);
}

void binToHex(char binary[], int showsteps)
{
    int decimal = 0;        // Decimal equivalent
    char hex[32];           // Hexadecimal output
    int i = 0;

    int length = strlen(binary);  // Get length of the input

    if (showsteps)
    {
        printf("\n--- Step-by-step Conversion ---\n");
    }

    // Validate and convert binary to decimal
    for (int j = 0; j < length; j++)
    {
        char ch = binary[j];

        // Check for valid binary digit
        if (ch != '0' && ch != '1')
        {
            printf("Invalid binary digit '%c' at position %d. Only 0 and 1 are allowed.\n", ch, j + 1);
            return;
        }

        int bit = ch - '0';

        if (showsteps)
        {
            printf("Step %d: Decimal = Decimal * 2 + %d => %d\n", j + 1, bit, decimal * 2 + bit);
        }

        decimal = decimal * 2 + bit;  // Convert to decimal
    }

    // Special case if input was "0"
    if (decimal == 0)
    {
        printf("Hexadecimal: 0\n");
        logConversion("0", "0", 2, 16);
        return;
    }

    // Convert decimal to hexadecimal
    while (decimal > 0)
    {
        int remainder = decimal % 16;

        // Convert numeric value to hexadecimal character
        if (remainder < 10)
            hex[i++] = '0' + remainder;
        else
            hex[i++] = 'A' + (remainder - 10);

        if (showsteps)
        {
            printf("Step %d: %d / 16 = %d, Remainder = %d\n", i, decimal, decimal / 16, remainder);
        }

        decimal /= 16;
    }

    // Print the hexadecimal result in reverse order
    printf("\nHexadecimal of %s is: ", binary);
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hex[j]);
    }
    printf("\n");

    char output[33];
    for (int j = 0; j < i; j++)
        output[j] = hex[i - 1 - j];
    output[i] = '\0';

    logConversion(binary, output, 2, 16);
}


void hexToBin(char hex[], int showsteps)
{
          
    char binary[129] = "";  // Output string (4 bits per hex digit max)
    
    int length = strlen(hex);  // Get length of input

    if (showsteps)
    {
        printf("\n--- Step-by-step Conversion ---\n");
    }

    // Loop through each hex character
    for (int i = 0; i < length; i++)
    {
        char ch = toupper(hex[i]);  // Make uppercase for uniform handling
        const char *binPart;

        // Convert hex digit to binary string and append
        switch (ch)
        {
            case '0': binPart = "0000"; break;
            case '1': binPart = "0001"; break;
            case '2': binPart = "0010"; break;
            case '3': binPart = "0011"; break;
            case '4': binPart = "0100"; break;
            case '5': binPart = "0101"; break;
            case '6': binPart = "0110"; break;
            case '7': binPart = "0111"; break;
            case '8': binPart = "1000"; break;
            case '9': binPart = "1001"; break;
            case 'A': binPart = "1010"; break;
            case 'B': binPart = "1011"; break;
            case 'C': binPart = "1100"; break;
            case 'D': binPart = "1101"; break;
            case 'E': binPart = "1110"; break;
            case 'F': binPart = "1111"; break;
            default:
                // Invalid character handling
                printf("Invalid hexadecimal digit '%c' at position %d. Only 0-9 and A-F are allowed.\n", ch, i + 1);
                return;
        }

        if (showsteps)
        {
            printf("Step %d: %c => %s\n", i + 1, ch, binPart);
        }

        strcat(binary, binPart);
    }

    // Remove leading zeros from binary output
    int start = 0;
    while (binary[start] == '0' && binary[start + 1] != '\0')
        start++;

    // Final output
    printf("\nBinary of %s is: %s\n", hex, &binary[start]);

    logConversion(hex, &binary[start], 16, 2);
}

void showHistory()
{
    FILE *file = fopen("history.txt", "r");

    if (file == NULL)
    {
        printf("📂 No conversion history found.\n");
        return;
    }

    printf("\n📜 Conversion History:\n");
    printf("----------------------------------------------------------\n");

    char line[256];
    int count = 1;
    while (fgets(line, sizeof(line), file))
    {
        printf("%2d️ %s", count++, line);  // Adds emoji-style index
    }

    printf("----------------------------------------------------------\n");
    fclose(file);
}

void clearHistory() {
    FILE *file = fopen("history.txt", "w");  // Overwrite
    if (file) {
    
        fclose(file);
        printf("🧹 Conversion history cleared successfully!\n");
    }
}
