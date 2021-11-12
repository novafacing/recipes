int fd;
int r; // int r = fstat(fd, &st);
struct stat st;
asm("mov %1, %%edi\n\t"
    "mov %2, %%rsi\n\t"
    "mov $5, %%rax\n\t"
    "syscall\n\t"
    "mov %%eax, %0\n\t"
    : "=r" (r)
    : "r" (fd), "r" (&st)
    : "%rdi", "%rsi", "%rax");

