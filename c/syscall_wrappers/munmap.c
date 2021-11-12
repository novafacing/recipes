int len;
char * ptr;
// munmap(p1, reallen);
asm("mov %0, %%rdi\n\t"
    "mov %1, %%esi\n\t"
    "mov $11, %%rax\n\t"
    "syscall\n\t"
    :
    : "r" (ptr), "r" (len)
    : "%rdi", "%rsi", "%rax");
