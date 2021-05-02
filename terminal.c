#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

char *get_current_dir(char *home, char *pwd) {
	return pwd + strlen(home);

}

void print_header(char *logname, char *username, char *home, char *pwd) {
	printf("%s@%s:~%s$ ", logname, username, get_current_dir(home, pwd));
}

int main(int argc, char *argv[], char *envp[]) {
	char *PATH = getenv("PATH");
	char *SHELL = getenv("SHELL");
	char *HOME = getenv("HOME");
	char *USERNAME = getenv("USERNAME");
	char *PWD = getenv("PWD");
	char *LOGNAME = getenv("LOGNAME");

	char input_buffer[MAX_INPUT_SIZE];

	while (1) {
		print_header(LOGNAME, USERNAME, HOME, PWD);
		fgets(input_buffer, MAX_INPUT_SIZE, stdin);

		if (strcmp(input_buffer, "exit") == 0) {
			return 0;
		} else {
			printf("%ld\n", strlen(input_buffer));
			execl("/usr/bin/ls", "/usr/bin/ls", NULL);
		}

	}

}
