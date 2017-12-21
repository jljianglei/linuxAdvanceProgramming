#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>
void * thread_run(void * arg) {
     int count = 0;
	 printf("&count = %p\n",&count);
	 while(count < 10) {
	      count++;
		  printf("count = %d\n",count);
	 }
}
int main() {
    pthread_t tid[2];
	int i;
	for(i = 0; i < 2; ++i) {
	    pthread_create(&tid[i],NULL,&thread_run,NULL);
	}
	for(i = 0; i < 2; ++i) {
	    pthread_join(tid[i],NULL);
	}
	return 0;
}
