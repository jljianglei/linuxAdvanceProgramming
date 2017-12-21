#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
pthread_mutex_t mutex;
pthread_cond_t cond;
int count = 0;
void * decrement(void * arg) {
	while(1) {
    pthread_mutex_lock(&mutex);
	while(count == 0) {
	   pthread_cond_wait(&cond,&mutex);
	}
	count--;
	printf("in decrement count =  %d\n",count);
	pthread_mutex_unlock(&mutex);
	usleep(100000);
	}
}
void * increment(void * arg) {
   while(1) {
   pthread_mutex_lock(&mutex);
   count++;
   printf("in increment count = %d\n",count);
   if(count > 0) {
      pthread_cond_signal(&cond);
   }
   pthread_mutex_unlock(&mutex);
   usleep(100000);
   }
}
int main() {
    pthread_t t1,t2;
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
	pthread_create(&t1,NULL,&increment,NULL);
	pthread_create(&t2,NULL,&decrement,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
