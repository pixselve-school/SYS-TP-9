#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//char message[] = "HELLO WORLD!";
//char key[] = "DIANA"  ;

char *beaufort_cipher(char message[], char key[]) {
    unsigned long message_length = strlen(message);
    unsigned long key_length = strlen(key);
    char *result = calloc(message_length, sizeof(char));
    int key_index = 0;
    for (int i = 0; i < message_length; ++i) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            int coded_letter_index = key[key_index] - message[i];
            if (coded_letter_index < 0) {
                coded_letter_index += ('Z' - 'A' + 1);
            }
            result[i] = (char) (coded_letter_index + 'A');
            key_index++;
            key_index %= (int) key_length;
        } else {
            result[i] = message[i];
        }
    }
    return result;
}


char *decrypt(char crypted_message[], char partial_decrypted_message[], int key_length) {
    unsigned long crypted_message_length = strlen(crypted_message);
    char *result = calloc(crypted_message_length, sizeof(char));
}


int main() {
    char *result = beaufort_cipher("HELLO WORLD!", "DIANA");
    printf("%s", result);
    free(result);
    return 0;
}
