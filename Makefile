test:
	gcc -g -m64 main.c libmem/libmem.c -o main -ldl -Wall -Wextra
	gcc -g -m64 -shared -fPIC lib.c -o libtest.so -Wall -Wextra -Wpedantic