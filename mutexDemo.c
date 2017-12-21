#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
/*临界资源*/
static pthread_mutex_t mutex;
void printer(const char* str) {
    if(str == NULL)
		return;
	pthread_mutex_lock(&mutex);
	while(*str != '\0') {
	   putchar(*str);
	   fflush(stdout);
       str++;
	   sleep(1);
	}
	printf("\n");
	pthread_mutex_unlock(&mutex);
}
void * thread_func1(void * arg) {
    const char* str = "hello";
	printer(str);
}
void * thread_func2(void * arg) {
    const char* str = "world";
	printer(str);
}
int main() {
    pthread_t t1,t2;
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&t1,NULL,&thread_func1,NULL);
	pthread_create(&t2,NULL,&thread_func2,NULL);
    pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
