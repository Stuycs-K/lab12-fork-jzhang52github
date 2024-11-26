#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/wait.h>

int main(){
  printf("%d about to create 2 child processes.\n", getpid());
  pid_t p;
  p = fork();
  if(p<0){
    perror("Fork failed.\n");
    exit(1);
  }
  else if (p == 0){
    srand(getpid());
    int random;
    random = rand() % 5 + 1;
    printf("%d %dsec\n", getpid(), random);
    sleep(random);
    printf("%d finished after %d seconds.\n", getpid(), random);
  }
  else{
    pid_t p1;
    p1 = fork();
    if(p1<0){
      perror("Fork failed.\n");
      exit(1);
    }
    else if (p1 == 0){
      srand(getpid());
      int random;
      random = rand() % 5 + 1;
      printf("%d %dsec\n", getpid(), random);
      sleep(random);
      printf("%d finished after %d seconds.\n", getpid(), random);
    }
    else{
      int status;
      pid_t cpid;
      cpid = wait(&status);
      srand(cpid);
      int random;
      random = rand() % 5 + 1;
      printf("Main Process %d is done. Child %d slept for %d sec\n", getpid(), cpid, random);
    }
  }
  return 0;
}
