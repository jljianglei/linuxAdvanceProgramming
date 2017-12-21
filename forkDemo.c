#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() {
    pid_t p1,p2;
	p1 = fork();
	p2 = fork();
	printf("p1: %d,p2 %d\n",p1,p2);
	return 0;
}
