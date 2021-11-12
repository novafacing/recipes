char * infile = "filename";
int fd; // int fd = open(infile, O_RDWR, 0666);
asm("mov %1, %%rdi\n\t"     // infile -> rdi
    "mov $2, %%rsi\n\t"     // 2 -> rsi
    "mov $438, %%rdx\n\t"   // 0666 -> rdx
    "mov $2, %%rax\n\t"
    "syscall\n\t"
    "mov %%eax, %0\n\t"
    : "=r" (fd)
    : "r" (infile)
    : "%rdi", "%rsi", "%rdx", "%rax");

