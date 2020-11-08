#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <dlfcn.h>
#include "libmem/libmem.h"

void test(int num1, int num2)
{
    printf("%i + %i = %i\n", num1, num2, num1 + num2);
}

extern void* __libc_dlopen_mode(void* handle, const char* symbol);


const unsigned char injection_buffer[] =
{
#   if defined(MEM_86)
    0x51,
    0x53,
    0xFF, 0xD0,
    0xCC,
#   elif defined(MEM_64)
    0xFF, 0xD0,
    0xCC,
#   endif
};

void* dlopen_in = (void*)__libc_dlopen_mode;
int   mode = RTLD_LAZY;
const char lib[] = "/home/rdbo/Documents/Codes/C/test-loadlib-in/libtest.so";

int main()
{
    mem_in_protect((mem_voidptr_t)injection_buffer, sizeof(injection_buffer), PROT_EXEC | PROT_READ | PROT_WRITE);
    printf("Waiting...\n");
    getchar();

    return 0;
}