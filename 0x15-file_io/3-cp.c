#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

/**
 * main - entry point copy contents of file.
 *
 * @ac: arguments count
 * @argv: arguments vector
 *
 * Return: Always 0 if succeed or erros if fail.
 */
int main(int ac, char *argv[])
{
	int fd1, fd2;
	char buffer[1024];
	ssize_t num;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp %s %s\n", argv[1], argv[2]);
		exit(97);
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (fd1 == -1 || fd2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from a file %s\n", argv[1]);
		exit(98);
	}

	while ((num = read(fd1, buffer, 1024)) > 0)
	{
		if (write(fd2, buffer, num) != num)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s", argv[2]);
			exit(99);
		}
	}
	if (close(fd1) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d", fd1);
		exit(100);
	}
	if (close(fd2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d", fd2);
		exit(100);
	}

	return (0);
}
