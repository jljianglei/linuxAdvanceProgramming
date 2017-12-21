#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
static int value = 0;
pthread_mutex_t mutex;
void * thread1(void * arg) {
   int count = 0;
   while(value < 20) {
	   pthread_mutex_lock(&mutex);
       value++;
	   pthread_mutex_unlock(&mutex);
	   printf("in thread1 value = %d\n",value);
	   usleep(100000);
   }
}
void * thread2(void * arg) {
   int count = 0;
   while(value < 20) {
	   pthread_mutex_lock(&mutex);
       value++;
       pthread_mutex_unlock(&mutex);
	   printf("in thread2 value = %d\n",value);
	   usleep(100000);
   }
}
int main() {
    pthread_t t1,t2;
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&t1,NULL,&thread1,NULL);
	pthread_create(&t2,NULL,&thread2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("-----------------------value = %d\n",value);
	return 0;
}

