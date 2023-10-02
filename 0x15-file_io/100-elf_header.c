#include "main.h"

/**
 * p_type - prints type
 * @ptr: magic.
 */

void p_type(char *ptr)
{
	char type = ptr[16];

	if (ptr[5] == 1)
		type = ptr[16];
	else
		type = ptr[17];

	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (Relocatable file)\n");
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

/**
 * p_OS_ABI - prints OS/ABI
 * @ptr: magic.
 */

void p_OS_ABI(char *ptr)
{
	char os_abi = ptr[7];

	printf("  OS/ABI:                            ");
	if (os_abi == 0)
		printf("UNIX - System V\n");
	else if (os_abi == 2)
		printf("UNIX - NetBSD\n");
	else if (os_abi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", os_abi);

	printf("  ABI Version:                       %d\n", ptr[8]);
}

/**
 * p_addr - prints address
 * @ptr: magic.
 */

void p_addr(char *ptr)
{
	int x;
	int begin;
	char sys;

	printf("  Entry point address:               0x");

	sys = ptr[4] + '0';
	if (sys == '1')
	{
		begin = 26;
		printf("80");
		for (x = begin; x >= 22; x--)
		{
			if (ptr[x] > 0)
				printf("%x", ptr[x]);
			else if (ptr[x] < 0)
				printf("%x", 256 + ptr[x]);
		}
		if (ptr[7] == 6)
			printf("00");
	}

	if (sys == '2')
	{
		begin = 26;
		for (x = begin; x > 23; x--)
		{
			if (ptr[x] >= 0)
				printf("%02x", ptr[x]);

			else if (ptr[x] < 0)
				printf("%02x", 256 + ptr[x]);

		}
	}
	printf("\n");
}

/**
 * p_data - prints data
 * @ptr: magic.
 */

void p_data(char *ptr)
{
	char data = ptr[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");

	if (data == 2)
		printf(", big endian\n");
}

/**
 * p_version - prints version
 * @ptr: magic.
 */

void p_version(char *ptr)
{
	int version = ptr[6];

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}

/**
 * p_magic - prints magic info.
 * @ptr: magic.
 */

void p_magic(char *ptr)
{
	int bytes;

	printf("  Magic:  ");

	for (bytes = 0; bytes < 16; bytes++)
		printf(" %02x", ptr[bytes]);

	printf("\n");

}

/**
 * check_elf - check if it is an elf file.
 * @ptr: magic.
 * Return: 1 if it is an elf file. 0 if not.
 */

int check_elf(char *ptr)
{
	int addr = (int)ptr[0];
	char E = ptr[1];
	char L = ptr[2];
	char F = ptr[3];

	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * check_system - check the version system.
 * @ptr: magic.
 */

void check_system(char *ptr)
{
	char sys = ptr[4] + '0';

	if (sys == '0')
		exit(98);

	printf("ELF Header:\n");
	p_magic(ptr);

	if (sys == '1')
		printf("  Class:                             ELF32\n");

	if (sys == '2')
		printf("  Class:                             ELF64\n");

	p_data(ptr);
	p_version(ptr);
	p_OS_ABI(ptr);
	p_type(ptr);
	p_addr(ptr);
}

/**
 * main - program that displays the information contained in the
 * ELF header at the start of an ELF file
 * @ac: number of arguments.
 * @av: arguments vector.
 * Return: 0 (success).
 */
int main(int ac, char *av[])
{
	int fileDes, read_size;
	char ptr[64];

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	fileDes = open(av[1], O_RDONLY);
	if (fileDes < 0)
	{
		dprintf(STDERR_FILENO, "Error: file cannot be opened\n");
		exit(98);
	}
	lseek(fileDes, 0, SEEK_SET);
	read_size = read(fileDes, ptr, 27);
	if (read_size == -1)
	{
		dprintf(STDERR_FILENO, "Error: This file cannot be read\n");
		exit(98);
	}

	if (!check_elf(ptr))
	{
		dprintf(STDERR_FILENO, "Error: It is not an ELF\n");
		exit(98);
	}

	check_system(ptr);
	close(fileDes);

	return (0);
}
