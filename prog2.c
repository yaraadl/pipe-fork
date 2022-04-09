//yara adel hassan mohamed 19100683
// programming assignmnent q2
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#define R 0
#define W 1

int main(){
int i;
int pids[1024]; //array of pids
int pipefd[2];
int j;
int array[1024];
int buffer;
int value;
int sum;
 printf("parent process <pid: %d> and <ppid:%d>\n", getpid(),getppid());

for(i=0;i<10;i++){ // looping for 10 times 

    if(pipe(pipefd) < 0){
        perror("pipe error!\n");
        exit(1);
    }
pids[i]=fork(); // forking within the loop 
if(pids[i]<0){
 perror("fork error!\n");
        exit(1);
}
else if (pids[i]==0){//this is a child
close(pipefd[R]);
printf("child process <pid: %d> and <ppid:%d>\n", getpid(),getppid());

 value=getpid();
write(pipefd[W], &value, sizeof(int));
close(pipefd[W]);
}

else{//this is a parent

close(pipefd[W]);

read(pipefd[R], &value, sizeof(int));
printf("%d\n",value);

sum+=value;
printf("sum:%d\n",sum);


}
return 0;
}
}
