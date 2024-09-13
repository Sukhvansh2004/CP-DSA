#include <stdio.h>
#include <unistd.h>

int main() {
    int syscall_number = 39; // Syscall number for getpid in x86_64
    pid_t pid;
    // Inline assembly to invoke the syscall
    asm("syscall"
        : "=a" (pid)             // Output: store the return value in pid
        : "a" (syscall_number)   // Input: syscall number in the rax register
        : "rcx", "r11", "memory" // Clobbered registers
    );

    printf("Process ID: %d\n", pid);
    return 42;
}
