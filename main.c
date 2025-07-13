#include "logic.h"
#include <stdio.h>
#include <stdlib.h>

// Clear input buffer after scanf to avoid leftover characters
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to validate step-by-step explanation input
int askShowSteps() {
    char response;
    while (1) {
        printf("🧾 Do you want step-by-step explanation? (y/n): ");
        scanf(" %c", &response);
        clearInputBuffer();

        if (response == 'y' || response == 'Y')
            return 1;
        else if (response == 'n' || response == 'N')
            return 0;
        else
            printf("⚠️ Invalid input! Please enter 'y' or 'n'.\n");
    }
}

// Function to get menu choice safely
int getMenuChoice() {
    int choice;
    printf("\n👉 Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        clearInputBuffer();  // discard invalid input
        return -1;           // indicate invalid input
    }
    clearInputBuffer();
    return choice;
}

// Function to ask for continuation safely
int askContinue() {
    char response;
    while (1) {
        printf("\n🔁 Do you want to continue? (y/n): ");
        scanf(" %c", &response);
        clearInputBuffer();

        if (response == 'y' || response == 'Y')
            return 1;
        else if (response == 'n' || response == 'N')
            return 0;
        else
            printf("⚠️ Invalid input! Please enter 'y' or 'n'.\n");
    }
}

int main() {
    printf("\n\n🔢 ================================================= 🔢\n");
    printf("     🚀 Welcome to Advanced Number System Converter\n");
    printf("           💻 Developed by Amruta Pradip Patil \n");
    printf("🔢 ================================================= 🔢\n");

    int choice, show;

    do {
        printf("\n📋 === Number System Conversion Menu === 📋\n\n");
        printf("1️⃣  Decimal to Binary\n");
        printf("2️⃣  Binary to Decimal\n");
        printf("3️⃣  Decimal to Octal\n");
        printf("4️⃣  Octal to Decimal\n");
        printf("5️⃣  Decimal to Hexadecimal\n");
        printf("6️⃣  Hexadecimal to Decimal\n");
        printf("7️⃣  Binary to Hexadecimal\n");
        printf("8️⃣  Hexadecimal to Binary\n");
        printf("9️⃣  View Conversion History 🔍\n");
        printf("🔟  Clear History 🧹\n");
        printf("1️⃣1️⃣  Exit ❌\n");

        choice = getMenuChoice();
        printf("\n");

        switch (choice) {
            case 1: {
                int decimal = getValidatedDecimal();
                show = askShowSteps();
                decToBin(decimal, show);
                break;
            }
            case 2: {
                char binary[33];
                getValidatedBinary(binary);
                show = askShowSteps();
                binToDec(binary, show);
                break;
            }
            case 3: {
                int decimal = getValidatedDecimal();
                show = askShowSteps();
                decToOct(decimal, show);
                break;
            }
            case 4: {
                char octal[33];
                getValidatedOctal(octal);
                show = askShowSteps();
                octToDec(octal, show);
                break;
            }
            case 5: {
                int decimal = getValidatedDecimal();
                show = askShowSteps();
                decToHex(decimal, show);
                break;
            }
            case 6: {
                char hex[33];
                getValidatedHexadecimal(hex);
                show = askShowSteps();
                hexToDec(hex, show);
                break;
            }
            case 7: {
                char binary[33];
                getValidatedBinary(binary);
                show = askShowSteps();
                binToHex(binary, show);
                break;
            }
            case 8: {
                char hex[33];
                getValidatedHexadecimal(hex);
                show = askShowSteps();
                hexToBin(hex, show);
                break;
            }
            case 9:
                showHistory();
                break;
            case 10:
                clearHistory();
                break;
            case 11:
                printf("👋 Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("⚠️ Invalid choice. Please try again.\n");
        }

    } while (askContinue());

    printf("\n👋 Exiting the program. Goodbye!\n");
    return 0;
}
