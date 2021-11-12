int fd;
// close(fd);
asm("mov %0, %%edi\n\t"
    "mov $3, %%rax\n\t"
    "syscall\n\t"
    :
    : "r" (fd)
    : "%rdi", "%rax");

