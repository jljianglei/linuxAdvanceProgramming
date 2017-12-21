#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
pthread_mutexattr_t attr;
pthread_mutex_t mutex;
void * print_msg(void * arg) {
    int i;
	pthread_mutex_lock(&mutex);
	for(i = 0; i < 15; ++i) {
	    printf("output :%d\n",i);
		usleep(100);
	}
	pthread_mutex_unlock(&mutex);
}
int main() {
    pthread_mutex_init(&mutex,NULL);
	pthread_mutexattr_init(&attr);
	int share;
	pthread_mutexattr_getpshared(&attr,&share);
	printf("default mutex shared type is %d\n",share);
	pthread_mutexattr_setpshared(&attr,PTHREAD_PROCESS_SHARED);
	pthread_mutexattr_getpshared(&attr,&share);
	printf("default mutex shared type is %d\n",share);
	int type;
	pthread_mutexattr_gettype(&attr,&type);
	printf("default mutex type is %d\n",type);
	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE_NP);
	pthread_mutexattr_gettype(&attr,&type);
	printf("default mutex type is %d\n",type);
	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_ERRORCHECK_NP);
	pthread_mutexattr_gettype(&attr,&type);
	printf("default mutex type is %d\n",type);
	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_ADAPTIVE_NP);
	pthread_mutexattr_gettype(&attr,&type);
	printf("default mutex type is %d\n",type);
	pthread_t t1,t2;
	pthread_create(&t1,NULL,&print_msg,NULL);
	pthread_create(&t2,NULL,&print_msg,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}
