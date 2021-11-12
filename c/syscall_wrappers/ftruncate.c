size_t len;
int fd;
asm("mov %0, %%edi\n\t"
    "mov %1, %%esi\n\t"
    "mov $77, %%rax\n\t"
    "syscall\n\t"
    :
    : "r" (fd), "r" (len)
    : "%rdi", "%rsi", "%rax");
