size_t len;
char * ptr; // char * ptr = (char *)mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
asm("mov $0, %%rdi\n\t"
    "mov %1, %%rsi\n\t"
    "mov $3, %%rdx\n\t"
    "mov $1, %%r10\n\t"
    "mov %2, %%r8d\n\t"
    "xor %%r9, %%r9\n\t"
    "mov $9, %%rax\n\t"
    "syscall\n\t"
    "mov %%rax, %0\n\t"
    : "=r" (ptr)
    : "r" (len), "r" (fd)
    : "%rdi", "%rsi", "%rdx", "%r10", "%r8", "%r9", "%rax");

