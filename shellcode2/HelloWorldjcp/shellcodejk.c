#include<stdio.h>
#include<string.h>

unsigned char code[] = \
"\xeb\x2e\x5e\x48\xb8\x01\x00\x00\x00\x00\x00\x00\x48\xbf\x01\x00\x00\x00\x00\x00\x00\x48\xba\x23\x00\x00\x00\x00\x00\x00\x0f\x05\x48\x31\xc0\xb0\x3c\x48\x31\xff\x40\xb7\x0b\x0f\x05\xe8\xcd\xff\xff\xff\x48\x65\x6c\x6c\x6f\x20\x57\x6f\x72\x6c\x64\x20\x74\x6f\x20\x74\x68\x65\x20\x53\x4c\x41\x45\x2d\x36\x34\x20\x43\x6f\x75\x72\x73\x65\x0a";

main()
{

	printf("Shellcode Length:  %d\n", (int)strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}

	
