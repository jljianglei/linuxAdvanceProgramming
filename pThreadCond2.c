#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>
static int numIndex = 1;
static pthread_mutex_t mutex;
static pthread_cond_t cond;
void* thread1(void * arg) {
   while(numIndex < 50) {
       pthread_mutex_lock(&mutex);
	   numIndex++;
	   printf("in thread1 numIndex = %d\n",numIndex);
	   pthread_cond_signal(&cond);
	   pthread_mutex_unlock(&mutex);
	   usleep(10);
   }
}
void* thread2(void * arg) {
   while(numIndex < 50) {
       pthread_mutex_lock(&mutex);
	   numIndex++;
	   printf("in thread2 numIndex = %d\n",numIndex);
	   pthread_cond_signal(&cond);
	   pthread_mutex_unlock(&mutex);
	   usleep(10);
   }
}
void * thread3(void * msg) {
   while(1) {
	  pthread_mutex_lock(&mutex);
      while(numIndex % 3 != 0) {
	     pthread_cond_wait(&cond,&mutex);
	  }
	  printf("in thread3 numIndex / 3 = %d\n",numIndex / 3);
	  pthread_mutex_unlock(&mutex);
	  usleep(10);
   }
}
int main() {
   pthread_mutex_init(&mutex,NULL);
   pthread_cond_init(&cond,NULL);
   pthread_t t1,t2,t3;
   pthread_create(&t1,NULL,&thread1,NULL);
   pthread_create(&t2,NULL,&thread2,NULL);
   pthread_create(&t3,NULL,&thread3,NULL);
   pthread_join(t1,NULL);
   pthread_join(t2,NULL);
   pthread_join(t3,NULL);
   return 0;
}

