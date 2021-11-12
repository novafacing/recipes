int atoi_dumb(char * input){
    int retv = 0;
    for(int i = 0; input[i] != '\0'; i++){
        if (input[i] < '0' || input[i] > '9') break;
        retv = retv * 10;
        retv = retv + (input[i] - '0');
    }
    return retv;
}
