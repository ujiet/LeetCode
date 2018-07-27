struct node {
    int val;
    struct node *next;
};

int hash(int val, int size) {
    return abs(val % size);
}

bool insert(struct node **table, int val) {
    /* Return value: true means val is already exist, when false means not. */
    if (*table == NULL) {
        /* Create first node of this key. */
        struct node *head = *table = (struct node *) malloc(sizeof(struct node));
        head->val = val;
        head->next = NULL;
        return false;
    } else {
        struct node *head = *table;
        struct node *temp = head->next;
        
        /* Traverse until find the number we want or head is the last node.*/
        while (head->val != val && temp != NULL) {
            head = head->next;
            temp = temp->next;
        }
        
        /* If head->val == val, the number is already exist. Or we create a new node. */
        if (head->val == val) { 
            return true;
        } else {
            head->next = (struct node *) malloc(sizeof(struct node));
            head->next->val = val;
            head->next->next = NULL;
            return false;
        }
    }
}

void freeTable(struct node **table, int size){
    for (int i = 0; i < size; i++) {
        if (table[i] == NULL) continue;
        
        struct node *head = table[i];
        struct node *temp = head->next;
        
        while(temp != NULL) {
            free(head);
            head = temp;
            temp = temp->next;
        }
        
        free(head);
    }
    
    free(table);
    return;
}

bool containsDuplicate(int* nums, int numsSize) {
    struct node **table = (struct node **) calloc(numsSize, sizeof(struct node *));
    
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        int key = hash(val, numsSize);
     
        if (insert(&table[key], val)) {
            freeTable(table, numsSize);
            return true;
        }
    }
    
    freeTable(table, numsSize);
    return false;
}
