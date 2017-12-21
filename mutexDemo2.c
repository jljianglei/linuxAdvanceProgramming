#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
static int value = 1;
pthread_mutex_t mutex;
void * thread1(void * arg) {
	int count = 0;
     while(count < 2) {
		count++;
	    value *= 2;
		printf("in thread1 value = %d\n",value);
	 }
}
void * thread2(void * arg) {
	int count = 0;
     while(count < 2) {
		count++;
	    value *= 2;
		printf("int thread2 value = %d\n",value);
	 }
}
void * thread3(void * arg) {
	int count = 0;
     while(count < 2) {
		count++;
	    value *= 2;
		printf("int thread3 value = %d\n",value);
	 }
}
int main() {
    pthread_t t1,t2,t3;
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&t1,NULL,&thread1,NULL);
	pthread_create(&t2,NULL,&thread2,NULL);
	pthread_create(&t3,NULL,&thread3,NULL);
    pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	printf("----------------value = %d\n",value);
	pthread_mutex_destroy(&mutex);
	return 0;
}
