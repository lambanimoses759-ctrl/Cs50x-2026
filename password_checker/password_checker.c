#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>


int isCommonPassword(char *password) {
    char *common[] = {"password", "123456", "123456789", "qwerty", "abc123", 
                      "password123", "admin", "letmein", "welcome", "monkey"};
    for (int i = 0; i < 10; i++) {
        if (strcmp(password, common[i]) == 0) return 1;
    }
    return 0;
}

int main() {
    char password[100];
    int length, hasUpper = 0, hasLower = 0, hasDigit = 0, hasSymbol = 0;
    int score = 0, charsetSize = 0;
    double entropy, crackSeconds;

    printf("=== Password Strength Checker V2 ===\n");
    printf("Enter password to check: ");
    scanf("%s", password);

    length = strlen(password);

    
    if (isCommonPassword(password)) {
        printf("\n[ALERT] This password is in top 10 most hacked passwords!\n");
        printf("Result: WEAK - Never use common passwords\n");
        printf("Crack Time: Instant (0 seconds)\n");
        return 0;
    }

    if (length >= 8) score++;
    if (length >= 12) score++;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        if (islower(password[i])) hasLower = 1;
        if (isdigit(password[i])) hasDigit = 1;
        if (!isalnum(password[i])) hasSymbol = 1;
    }

    if (hasUpper) { score++; charsetSize += 26; }
    if (hasLower) { score++; charsetSize += 26; }
    if (hasDigit) { score++; charsetSize += 10; }
    if (hasSymbol) { score++; charsetSize += 32; }
    if (charsetSize == 0) charsetSize = 26;

    entropy = length * log2(charsetSize);
    crackSeconds = pow(2, entropy) / 1e9; 

    printf("\n--- Analysis ---\n");
    printf("Length: %d | Entropy: %.1f bits\n", length, entropy);
    printf("Uppercase: %s | Lowercase: %s\n", hasUpper ? "YES" : "NO", hasLower ? "YES" : "NO");
    printf("Number: %s | Symbol: %s\n", hasDigit ? "YES" : "NO", hasSymbol ? "YES" : "NO");
    printf("Score: %d/6\n", score);

    printf("\n--- Security ---\n");
    if (crackSeconds < 60) printf("Crack Time: %.0f seconds [INSTANT RISK]\n", crackSeconds);
    else if (crackSeconds < 3600) printf("Crack Time: %.0f minutes\n", crackSeconds/60);
    else if (crackSeconds < 86400) printf("Crack Time: %.1f hours\n", crackSeconds/3600);
    else if (crackSeconds < 31536000) printf("Crack Time: %.1f days\n", crackSeconds/86400);
    else printf("Crack Time: >1 million years [SECURE]\n");

    
    if (score <= 2) printf("\nResult: WEAK\n");
    else if (score <= 4) printf("\nResult: MEDIUM\n");
    else printf("\nResult: STRONG\n");

    printf("\n--- How to Improve ---\n");
    if (!hasUpper) printf("+ Add uppercase letter (A-Z)\n");
    if (!hasLower) printf("+ Add lowercase letter (a-z)\n");
    if (!hasDigit) printf("+ Add a number (0-9)\n");
    if (!hasSymbol) printf("+ Add symbol (!@#$%%)\n");
    if (length < 12) printf("+ Make it at least 12 characters\n");
    if (score == 6) printf("Perfect! No changes needed.\n");

    return 0;
}