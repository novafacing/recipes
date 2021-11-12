char * getenv_raw(char* envp[], char * name, int size){
    int found;
    for (int i = 0; envp[i] != NULL; i++){
        found = 1;
        for (int j = 0; j < size; j++){
            if(envp[i][j] != name[j]){
                found = 0;
                break;
            }
        }
        if (found == 1){
            return envp[i] + size;
        }
    }
    return NULL;
}
