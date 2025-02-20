#include <stdio.h>
#include <math.h>

// Function to convert decimal to binary using division method
void decimalToBinary(int decimal) {
    // Handle special case when input is 0
    if (decimal == 0) {
        printf("Result: 0\n");
        return;
    }
    
    int binary = 0;
    int position = 1; // Used to track place value in binary representation
    
    // Convert decimal to binary using repeated division by 2
    while (decimal > 0) {
        binary += (decimal % 2) * position; // Extract remainder and place in correct position
        decimal /= 2; // Reduce decimal number
        position *= 10; // Move to next binary place value
    }
    
    printf("Result: %d\n", binary);
}

// Function to convert decimal to octal
void decimalToOctal(int decimal) {
    // Handle special case when input is 0
    if (decimal == 0) {
        printf("Result: 0\n");
        return;
    }
    
    int octal = 0;
    int position = 1; // Used to track place value in octal representation
    
    // Convert decimal to octal using repeated division by 8
    while (decimal > 0) {
        octal += (decimal % 8) * position; // Extract remainder and place in correct position
        decimal /= 8; // Reduce decimal number
        position *= 10; // Move to next octal place value
    }
    
    printf("Result: %d\n", octal);
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    // Handle special case when input is 0
    if (decimal == 0) {
        printf("Result: 0\n");
        return;
    }
    
    printf("Result: ");
    // Convert decimal to hexadecimal using repeated division by 16
    while (decimal > 0) {
        int remainder = decimal % 16; // Extract remainder
        // Print corresponding hexadecimal character
        if (remainder < 10) {
            printf("%d", remainder);
        } else {
            printf("%c", 'A' + remainder - 10);
        }
        decimal /= 16; // Reduce decimal number
    }
    printf("\n");
}

// Function to convert binary to decimal
int binaryToDecimal(int binary) {
    int decimal = 0;
    int power = 0;
    
    // Convert binary to decimal using positional value method
    while (binary > 0) {
        decimal += (binary % 10) * pow(2, power); // Extract digit and multiply by corresponding power of 2
        binary /= 10; // Reduce binary number
        power++; // Move to next power
    }
    
    return decimal;
}

// Function to convert octal to decimal
int octalToDecimal(int octal) {
    int decimal = 0;
    int power = 0;
    
    // Convert octal to decimal using positional value method
    while (octal > 0) {
        decimal += (octal % 10) * pow(8, power); // Extract digit and multiply by corresponding power of 8
        octal /= 10; // Reduce octal number
        power++; // Move to next power
    }
    
    return decimal;
}

// Function to validate binary input
int validateBinary(int binary) {
    while (binary > 0) {
        if (binary % 10 > 1) {
            return 0;  // Invalid binary number (contains digits other than 0 or 1)
        }
        binary /= 10;
    }
    return 1;  // Valid binary number
}

// Function to validate octal input
int validateOctal(int octal) {
    while (octal > 0) {
        if (octal % 10 > 7) {
            return 0;  // Invalid octal number (contains digits greater than 7)
        }
        octal /= 10;
    }
    return 1;  // Valid octal number
}

int main() {
    int sourceBase, targetBase, number;
    
    // Display menu for number system converter
    printf("Number System Converter\n");
    printf("----------------------\n");
    printf("Available bases:\n");
    printf("2 - Binary\n");
    printf("8 - Octal\n");
    printf("10 - Decimal\n");
    printf("16 - Hexadecimal\n\n");
    
    // Get source base from user
    do {
        printf("Enter source base (2, 8, 10, or 16): ");
        scanf("%d", &sourceBase);
    } while (sourceBase != 2 && sourceBase != 8 && sourceBase != 10);
    
    // Get target base from user
    do {
        printf("Enter target base (2, 8, 10, or 16): ");
        scanf("%d", &targetBase);
    } while (targetBase != 2 && targetBase != 8 && targetBase != 10 && targetBase != 16);
    
    // Get the number to convert
    printf("Enter the number to convert: ");
    scanf("%d", &number);
    
    // Validate input based on source base
    if (sourceBase == 2 && !validateBinary(number)) {
        printf("Error: Invalid binary number\n");
        return 1;
    }
    if (sourceBase == 8 && !validateOctal(number)) {
        printf("Error: Invalid octal number\n");
        return 1;
    }
    
    // Convert input to decimal first if source base is not decimal
    int decimal;
    if (sourceBase == 2) {
        decimal = binaryToDecimal(number);
    } else if (sourceBase == 8) {
        decimal = octalToDecimal(number);
    } else {
        decimal = number; // Already in decimal form
    }
    
    // Convert from decimal to target base and display result
    if (targetBase == 2) {
        decimalToBinary(decimal);
    } else if (targetBase == 8) {
        decimalToOctal(decimal);
    } else if (targetBase == 16) {
        decimalToHexadecimal(decimal);
    } else {
        printf("Result: %d\n", decimal);
    }
    
    return 0;
}
