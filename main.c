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
    char key[key_length];
    for (int i = 0; i < key_length; ++i) {
        char result_char =(crypted_message[i] + partial_decrypted_message[i]) % ('Z' - 'A' + 1) + 'A';
        key [i] = result_char;
    }
    return beaufort_cipher(crypted_message, key);
}


int main() {
    char *crypted_message2 =beaufort_cipher("HELLO WORLD", "DIANA");
    printf("%s\n", crypted_message2);


    printf("Entrer the ciphertext (max 1024 characters):\n");
    char message[1024];
    fgets(message, 1024, stdin);
    printf("Entrer the key (max 1024 characters):\n");
    char key[1024];
    fgets(key, 1024, stdin);
    printf("%d", strlen(key));
    printf("%d" , strlen(message));
    char *crypted_message = beaufort_cipher(message, key);
    printf("The crypted message is: %s\n", crypted_message);


}
