size_t len;
char * ptr; // char * ptr = (char *)mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, 0, 0);
asm("mov $0, %%rdi\n\t"
    "mov %1, %%rsi\n\t"
    "mov $3, %%rdx\n\t"
    "mov $34, %%r10\n\t"
    "mov $0, %%r8\n\t"
    "xor %%r9, %%r9\n\t"
    "mov $9, %%rax\n\t"
    "syscall\n\t"
    "mov %%rax, %0\n\t"
    : "=r" (ptr)
    : "r" (len)
    : "%rdi", "%rsi", "%rdx", "%r10", "%r8", "%r9", "%rax");

