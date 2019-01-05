#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
        int columns = 0;

        while(scanf("%i", &columns) && columns) {
                int i = 0;
                int j = 0;
                char *cipher;
                char *plaintext;

                cipher = calloc(4001, sizeof(char));
                plaintext = calloc(4001, sizeof(char));

                scanf("%s", cipher);
                if(strlen(cipher) % columns != 0) return 1;

                for(i=0; i < columns; i++) {
                        int offset = i;
                        int flag = 0;
                        while(offset < strlen(cipher)) {
                                plaintext[j++] = cipher[offset];
                                if(flag % 2 == 0)
                                        offset += 2 * (columns - i) - 1;
                                else
                                        offset += 2 * i + 1;
                                flag++;
                        }
                }
                plaintext[j] = '\0';
                printf("%s\n", plaintext);

                free(cipher);
                free(plaintext);
        }

        return 0;
}
