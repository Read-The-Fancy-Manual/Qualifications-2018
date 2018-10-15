// Quick reverse x64 challenge
// @x0rz
//
// gcc -fomit-frame-pointer chall.c -o chall.bin && strip chall.bin
#include <stdio.h>
#include <sys/ptrace.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define ANTIDISASSM_1(label,opcode)  \
	asm("push %rax");                \
	asm("xor %eax,%eax");            \
	asm("test %eax,%eax");           \
	asm("pop %rax");                 \
	asm("jnz "label);                \
	asm("jz "label" + 1");           \
	asm(label":");                   \
	asm(".byte 0x"opcode);

#define ANTIDISASSM_2(label,opcode)  \
	asm("push %rax");                \
	asm("xor %eax,%eax");            \
	asm("test %eax,%eax");           \
	asm("pop %rax");                 \
	asm("jnz "label);                \
	asm("jz "label" + 2");           \
	asm(label":");                   \
	asm(".short 0x"opcode);


char *tips = "Strings won't help you that much.\n\n" \
	"[+] Activating obfuscation layer 1...\n" \
	"[+] Activating extra layer 2...\n" \
	"(c) 2018 Antistrings technology [by @x0rz]";
char *nope = "KIS\x08JED@\rL]_\x11\x08\x1b>"; // "not cool bro :(\n"

// This is a custom string obfuscation function using 1 byte xor, key incremented each round
// Use the provided Python script to generate strings
// Mostly irrelevant to solve the challenge - just an extra layer of obfuscation
char *xor(char *str) {
	int l = strlen(str);
	char *buf = malloc(l);
	int i = 0;

	for (; i < l; ++i) {
		buf[i] = str[i] ^ (0x25 + i);
	}

	return(buf);
}

int validate(char* buf) {
	int waste = 500000;
	char temp[10];

	// antibruteforce ~ slow ops
	while (waste > 0) {
		waste--;
		int rd = open("\x0a\x42\x42\x5e\x06\x5f\x59\x4d\x43\x4a\x40\x5d\x3b", O_RDONLY); // /dev/urandom
		if (rd < 0) {
			read(rd, temp, 10);
		}
		close(rd);
	}

	// Flag = "sigsegv{W3llPl4y3d}"
	ANTIDISASSM_1("valid1","eb")
	if (buf[0] == 's' && buf[1] == 'i' && buf[2] == 'g' && buf[3] == 's'
		&& buf[4] == 'e' && buf[5] == 'g' && buf[6] == 'v' && buf[7] == '{') {
		ANTIDISASSM_1("valid2","eb")
		if (buf[8] == 'W' && buf[9] == '3' && buf[10] == 'l' && buf[11] == 'l') {
			ANTIDISASSM_2("valid3","1337")
			if (buf[12] == 'P' && buf[13] == 'l' && buf[14] == '4' && buf[15] == 'y' && buf[16] == '3' && buf[17] == 'd' && buf[18] == '}') {
				printf(xor("\x66\x49\x49\x4f\x5b\x4b\x5f\x59\x41\x4f\x5b\x59\x5e\x5c\x40\x15\x15\x6f\x58\x4d\x19\x52\x5a\x4a\x58\x1e\x4b\x28\x24\x62\x25\x28\x24\x21\x67\x72\x64\x63\x41"));
				return(0);
			}
		}
	}

	// Display fail
	printf(xor("\x6c\x48\x44\x47\x5b\x58\x4e\x4f\x59\x0e\x46\x5e\x41\x47\x47\x1a\x15\x62\x45\x41\x19\x5b\x5c\x5d\x54\x50\x11\x4a"));

	return 1;
}

int challenge() {
	char stdin[20];

	ANTIDISASSM_1("entrypoint","eb")

	// Simple antidebug
	if (ptrace(PTRACE_TRACEME, 0, 1, 0) < 0) {
		printf(xor(nope));
		return;
	}

	printf(xor("\x7e\x0d\x7a\x08\x7e\x4f\x47\x4f\x42\x43\x4a\x10\x45\x5d\x13\x40\x5d\x53\x17\x6a\x6d\x7c\x76\x1c\x5e\x56\x5e\x2c\x2d\x27\x2d\x23\x20\x4c"));
	printf(xor("\x7e\x0d\x7a\x08\x79\x46\x4e\x4d\x5e\x4b\x0f\x55\x5f\x46\x56\x46\x15\x42\x5f\x5d\x19\x5c\x57\x5d\x5a\x04\x1f"));
	fflush(stdout);
	read(STDIN_FILENO, stdin, 20);
	
	ANTIDISASSM_1("hide_function","eb")
	validate(stdin);
	return(0);
}

int main() {
	return(challenge());
}
