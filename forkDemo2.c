#include<unistd.h>
#include<stdio.h>
int main() {
    int a[] = {2,3,5,6,9,1};
	pid_t pid = 0;
	pid = fork();
	if(pid > 0) {
	   printf("this is parent process,pid is %d,ppid %d\n",getpid(),getppid());
	   printf("arr elem is :\n");
	   int i;
	   for(i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
	       printf("%d ",a[i]);
	   }
	   printf("\n");
	}
	else {
	   printf("this is child process,pid is %d,ppid %d\n",getpid(),getppid());
	   printf("arr length is %d\n",sizeof(a)/sizeof(a[0]));
	}
	return 0;
}
