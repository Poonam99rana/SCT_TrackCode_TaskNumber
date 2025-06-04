#include <stdio.h>
#include <ctype.h>

// Function to encrypt a message
void encrypt(char *message, int shift) {
    char ch;
    for (int i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            message[i] = (ch - base + shift) % 26 + base;
        }
    }
}

// Function to decrypt a message
void decrypt(char *message, int shift) {
    char ch;
    for (int i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            message[i] = (ch - base - shift + 26) % 26 + base;
        }
    }
}

int main() {
    char message[1000];
    int shift, choice;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter shift value: ");
    scanf("%d", &shift);

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(message, shift);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {
        decrypt(message, shift);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
