#include <stdio.h>
#include <stdlib.h>

int equate_packets(int *packets, int count)
{
        int result = 0;
        int average = 0;
        int sum = 0;

        int i = 0;
        for(i = 0; i < count; i++) {
                sum += packets[i];
        }
        
        average = sum / count;
        if((double)sum / average == count)
        {
                for(i=0; i < count; i++) {
                        while(packets[i] < average) {
                                packets[i]++;
                                result++;
                        }
                }
                return result;
        } else {
                return -1; 
        }
}

int main(int argc, char * argv[])
{
        int count = -1;

        while(scanf("%i", &count) && count != -1){
                int *packets = malloc(count * sizeof(int));
                int i = 0;
                for(i = 0; i < count; i++) {
                        scanf("%i", &(packets[i]));
                }
                printf("%i\n", equate_packets(packets, count));
                free(packets);
        }

        return 0;
}
