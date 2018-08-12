/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct HashNode {
    int key;
    int val;
} HashNode;

typedef struct HashMap {
    int size;
    HashNode **storage;
} HashMap;

struct Hashmap *createHash(int size) {
    struct HashMap *hashMap = (struct HashMap *) malloc(sizeof(struct HashMap));
    hashMap->size = size;
    hashMap->storage = (struct HashNode**) calloc(size, sizeof(struct HashNode *));
    return hashMap;
}

void destroyHash(struct HashMap *hashMap) {
    struct HashNode *node;
    
    for (int i = 0; i < hashMap->size; i++) {
        if (node = hashMap->storage[i])
            free(node);
    }
    
    free(hashMap->storage);
    free(hashMap);
    return;
}

void setHash(struct HashMap *hashMap, int key, int val) {
    int hash = abs(key) % hashMap->size;
    struct HashNode *node;
    
    while (node = hashMap->storage[hash]) 
        hash = (hash + 1) % hashMap->size;
    
    node = (struct HashNode *) malloc(sizeof(struct HashNode));
    node->key = key;
    node->val = val;
    hashMap->storage[hash] = node;
    return;
}

struct HashNode *getHash(struct HashMap *hashMap, int key) {
    int hash = abs(key) % hashMap->size;
    struct HashNode *node;
    
    while(node = hashMap->storage[hash]) {
        if (node->key == key)
            return node;
        hash = (hash + 1) % hashMap->size;
    }
    
    return NULL;
}

int* twoSum(int* nums, int numsSize, int target) {
    struct HashMap *hashmap = createHash(2 * numsSize);
    struct HashNode *node;
    int *result = (int *) malloc(2*sizeof(int));
    int rest;
    
    for (int i = 0; i < numsSize; i++) {
        rest = target - nums[i];
        node = getHash(hashmap, rest);
        
        if (node) {
            result[0] = node->val;
            result[1] = i;
            return result;
        }
        
        setHash(hashmap, nums[i], i);
    }
    return result;
}
