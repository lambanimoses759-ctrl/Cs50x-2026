#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 200

int main() {
    FILE *file = fopen("auth.log", "r");
    if (file == NULL) {
        printf("Error: auth.log not found!\n");
        return 1;
    }

    char line[MAX_LINE];
    int total_failed = 0;
    int total_success = 0;
    
    printf("=== INTRUSION DETECTION REPORT ===\n");
    printf("Analyzing auth.log...\n\n");

    while (fgets(line, MAX_LINE, file) != NULL) {
        // Count FAILED vs SUCCESS
        if (strstr(line, "FAILED") != NULL) {
            total_failed++;
            printf("[ALERT] %s", line);
        } else if (strstr(line, "SUCCESS") != NULL) {
            total_success++;
        }
    }

    fclose(file);

    printf("\n--- SUMMARY ---\n");
    printf("Total Failed Logins: %d\n", total_failed);
    printf("Total Success Logins: %d\n", total_success);

    if (total_failed >= 5) {
        printf("\n[CRITICAL] Possible Brute Force Attack Detected!\n");
        printf("Recommendation: Block IP 192.168.1.10\n");
    } else {
        printf("\nStatus: Normal\n");
    }

    return 0;
}
