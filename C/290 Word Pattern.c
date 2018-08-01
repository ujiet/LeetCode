bool wordPattern(char* pattern, char* str) {

    /* copy str to buffer to avoid revise of input string */
    int str_len = strlen(str);
    char buffer[str_len + 1];
    snprintf(buffer, str_len + 1, "%s", str);
    printf("buffer = %s\n", buffer);

    /* p point to pattern, s point to first word of str */
    char *p = pattern;
    char *s = strtok(buffer, " ");

    /* create table from a to z */
    char *table[26];
    memset(table, '\0', 26 * sizeof(char *));

    do {
        /* if *p is null and s is not, it means "pattern" is too short */
        if (*p == '\0') return false;
        int input = *p++ - 'a';

        if (table[input] == NULL) {                         //  this character hasn't appeared            
            /* check if there's another character map to s string */
            for (int i = 0; i < 26; i++) {
                if (table[i] == NULL) continue;
                if (strcmp(table[i], s) == 0) return false;
            }
            
            /* put s in the table */
            table[input] = (char *) malloc((strlen(s) + 1) * sizeof(char));
            strcpy(table[input], s);
        } else {                                            //  this character has already in table                                         
            /* check if the content of table fits s */
            if (strcmp(table[input], s)) return false;
        }
        
        /* get next word for s */
        s = strtok(NULL, " ");
    } while (s != NULL);
    
    /* if *p still points to some character, it means "str" is too short */
    if (*p != '\0') return false;
    
    return true;
}
