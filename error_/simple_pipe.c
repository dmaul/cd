/* simple_pipe.c

   Simple demonstration of the use of a pipe to communicate
   between a parent and a child process.

   Usage: simple_pipe "string"

   The program creates a pipe, and then calls fork() to create a child process.
   After the fork(), the parent writes the string given on the command line
   to the pipe, and the child uses a loop to read data from the pipe and
   print it on standard output.
*/
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
 
#define BUF_SIZE 10
#define	STDIN_FILENO	0	/* Standard input.  */
#define	STDOUT_FILENO	1	/* Standard output.  */
#define	STDERR_FILENO	2	/* Standard error output.  */
#define EXIT_SUCCESS 0

 
 int
 main(int argc, char *argv[])
 {
     int pfd[2];                             /* Pipe file descriptors */
     char buf[BUF_SIZE];
     size_t numRead;
 
     if (argc != 2 || strcmp(argv[1], "--help") == 0)
         printf("%s string\n", argv[0]);
 
     if (pipe(pfd) == -1)                    /* Create the pipe */
         exit(1);
 
     switch (fork()) {
     case -1:
         exit(1);
 
     case 0:             /* Child  - reads from pipe */
         if (close(pfd[1]) == -1)            /* Write end is unused */
             exit(1);
 
         for (;;) {              /* Read data from pipe, echo on stdout */
             numRead = read(pfd[0], buf, BUF_SIZE);
             if (numRead == -1)
                 exit(1);
             if (numRead == 0)
                 break;                      /* End-of-file */
             if (write(STDOUT_FILENO, buf, numRead) != numRead)
                 exit(1);
         }
 
         write(STDOUT_FILENO, "\n", 1);
         if (close(pfd[0]) == -1)
             exit(1);
         exit(EXIT_SUCCESS);
 
     default:            /* Parent - writes to pipe */
         if (close(pfd[0]) == -1)            /* Read end is unused */
             exit(1);
 
         if (write(pfd[1], argv[1], strlen(argv[1])) != strlen(argv[1]))
             exit(1);
 
         if (close(pfd[1]) == -1)            /* Child will see EOF */
             exit(1);
         wait(0);                         /* Wait for child to finish */
         exit(EXIT_SUCCESS);
     }
     printf("%s","all done");
 }
