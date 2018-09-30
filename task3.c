/*
 ============================================================================
 Name        : task3.c
 Author      : prashanna-rai
 Version     : dev
 Copyright   : Your copyright notice
 Description : simple shell
 ============================================================================
 */


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main()
{
  char cmd[23];
  while (1)
    {
      printf(" myshell > ");
      scanf("%s", cmd);
      if(strcmp("quit",cmd)==0)
            {
              printf("quit! \n" );
              return 0;
            }
          if(strcmp("ls",cmd)==0)
                {
                  printf("/usr/bin/ls \n" );
                  if (fork() == 0)
                    {
                      execl("/bin/ls", "",(char *) NULL);
                      return 0;
                    }
                  else
                    {
                      wait(NULL);
                    }

                }
                if(strcmp("pstree",cmd)==0)
                      {

                        if(fork()==0)
                          {
                            execl("/usr/bin/pstree", "",(char *) NULL);
                            return 0;
                          }

                        else
                          {
                            wait(NULL);
                          }
                       }
                    if(strcmp("htop",cmd)==0)
                          {

                            printf("/usr/bin/htop \n" );
                            if(fork()==0)
                              {
                                execl("/usr/bin/htop", "",(char *) NULL);
                                return 0;
                              }
                            else
                              {
                                wait(NULL);
                              }
                          }
                        if(strcmp("ifconfig",cmd)==0)
                              {
                                printf("/sbin/ifconfig \n" );
                                if(fork()==0)
                                  {
                                    execl("/sbin/ifconfig","" ,(char *) NULL);
                                    return 0;
                                  }
                                else
                                  {
                                    wait(NULL);
                                  }
                              }
                        else{
                            printf("Command unknown \n" );
                          }

                      }
                    return 0;
                  }

