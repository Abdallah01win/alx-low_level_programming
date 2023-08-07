#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "holberton.h"
#include <elf.h>

/**
 * main - entry point display the information in the ELF header
 *
 * @ac: arguments count
 * @argv: arguments vector
 *
 * Return: Always 0 if succeed or errors if fail.
 */
int main(int ac, char *argv[])
{
	int fd1;
	char buffer[1024];
	ssize_t num;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: cp %s %s\n", argv[1]);
		exit(97);
	}
	fd1 = open(argv[1], O_RDONLY);

	if (fd1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from a file %s\n", argv[1]);
		exit(98);
	}

	while ((num = read(fd1, buffer, 1024)) > 0)
	{
		if (write(fd1, buffer, num) != num)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s", argv[1]);
			exit(99);
		}
	}
	if (close(fd1) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d", fd1);
		exit(100);
	}

	return (0);
}
