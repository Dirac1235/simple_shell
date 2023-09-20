#include "main.h"

void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			free(buff);
		}
		exit(0);
	}
}

int main( __attribute__((unused))int argc, char *argv[])
{
    while (1)
    {
        size_t x = 0;
        char *input = NULL;
		int len;
        char **inputarr;
		void (*fun)(char **);
		char *token;
        int i = 0;

		if (isatty(STDIN_FILENO))
        {
            _putchar('$');
            _putchar(' ');
			
            fflush(stdout);
        }
		len = getline(&input, &x, stdin);
		_EOF(len, input);
        input[_strlen(input) - 1] = '\0';

        inputarr = malloc(sizeof(char *) * x);
        token = strtok(input, " ");
        if (token == NULL)
        {
            free(input);
            continue;
        }

       
		inputarr[i++] = token;
        while (token)
        {
            token = strtok(NULL, " ");
            inputarr[i++] = token;
        }
		fun = checkbuild(inputarr);
			if (fun)
			{
				free(input);
				fun(inputarr);
			}

        if (access(inputarr[0], X_OK) != -1) {
            int pid = fork();
            if (pid == 0)
            {
                execve(inputarr[0], inputarr, environ);
                perror("execve");
                exit(1);
            }
            else
            {
                wait(NULL);
            }
        } else {
					inputarr[0] = path_checker(inputarr[0],split_path(_get_path("PATH")));
					if(inputarr[0])
					{

						if (access(inputarr[0], X_OK) != -1) 
						{
							int pid = fork();
							if (pid == 0)
							{
								execve(inputarr[0], inputarr, environ);
								perror("execve");
								exit(1);
							}
							else
							{
								wait(NULL);
							}
						}
						else
						{
							perror(argv[0]);
						}
            
        			}
					else{
						perror(argv[0]);
					}
				}


        free(input);
    }

    return 0;
}
