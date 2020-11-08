gdb ./main

'''
run
^

x86:
set $eax = dlopen_in
set $ebx = lib
set $ecx = mode
set $eip = injection_buffer

x64:
set $rax = dlopen_in
set $rdi = lib
set $rsi = mode
set $rip = injection_buffer

continue
'''