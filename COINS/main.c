#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_TBL_SIZE 100003 

typedef struct HashNode HashNode;

typedef struct HashNode {
        unsigned int key;
        unsigned int data;
        HashNode *next;
} HashNode;

HashNode *HashTable[HASH_TBL_SIZE];

void HashCreate();
void HashDestroy();
void HashInsert(unsigned int, unsigned int);
bool HashContains(unsigned int);
unsigned int HashGet(unsigned int);

void HashCreate() 
{
        unsigned int i = 0;
        for(i = 0; i < HASH_TBL_SIZE; i++)
                HashTable[i] = NULL;       
}

void HashDestroy()
{
        unsigned int i = 0;
        for(i = 0; i < HASH_TBL_SIZE; i++) {
                HashNode *node = HashTable[i];
                while(node != NULL) {
                        HashNode *next = node->next;
                        free(node);
                        node = next;
                }
        }
}

void HashInsert(unsigned int key, unsigned int data)
{
        HashNode *node = malloc(sizeof(HashNode));

        int idx = key % HASH_TBL_SIZE;

        node->data = data;
        node->key = key;
        node->next = HashTable[idx];

        HashTable[idx] = node;
}

bool HashContains(unsigned int key)
{
        int idx = key % HASH_TBL_SIZE;

        HashNode *node = HashTable[idx];
        while(node != NULL) {
                if(node->key == key) {
                        return true;
                }
                node = node->next;
        }

        return false;
}

unsigned int HashGet(unsigned int key)
{
        int idx = key % HASH_TBL_SIZE;

        HashNode *node = HashTable[idx];
        while(node != NULL) {
                if(node->key == key) {
                        return node->data;
                }
                node = node->next;
        }
        return 0;
}

typedef struct {
        unsigned int half;
        unsigned int third;
        unsigned int quarter;
        unsigned int sum;
} Coin;

unsigned int exchange;

void memoize(unsigned int count, Coin *coin)
{
        if(HashContains((*coin).half)) 
                (*coin).half = HashGet((*coin).half); 
        if(HashContains((*coin).third)) 
                (*coin).third = HashGet((*coin).third); 
        if(HashContains((*coin).quarter)) 
                (*coin).quarter = HashGet((*coin).quarter); 

        HashInsert(count, (*coin).half + (*coin).third + (*coin).quarter);
}

void get_exchange_coins(unsigned int count, Coin *coin)
{
        (*coin).half = count / 2;
        (*coin).third = count / 3;
        (*coin).quarter = count / 4;
        (*coin).sum = (*coin).half + (*coin).third + (*coin).quarter;
}

void compute_exchange(unsigned int count)
{
        Coin *coin = malloc(sizeof(Coin));
        
        if(HashContains(count)) {
                exchange += HashGet(count);
        } else {
                get_exchange_coins(count, coin);
                if((*coin).sum <= count) {
                        exchange += count;
                } else {
                        compute_exchange((*coin).half);
                        compute_exchange((*coin).third);
                        compute_exchange((*coin).quarter);
                        memoize(count, coin);
                }
        }

        free(coin);
}

int main(int argc, char *argv[])
{
        HashCreate();
        unsigned int n = 0;
        while(scanf("%u", &n) && !feof(stdin)) {
                exchange = 0;
                compute_exchange(n);
                printf("%u\n", exchange);
        }
        HashDestroy();

        return 0;
}
