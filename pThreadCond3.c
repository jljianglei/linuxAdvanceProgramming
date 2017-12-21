#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
/*互斥锁*/
static pthread_mutex_t mutex;
/*条件变量*/
static pthread_cond_t cond;
/*全局资源*/
static int money;
void err_exit(const char* err_msg) {
    printf("error : %s\n",err_msg);
	exit(1);
}
void * thread_run(void * arg) {
    while(1) {
	    pthread_mutex_lock(&mutex);
		while(money > 0) {
			printf("子线程坐等money等于0\n");
		    pthread_cond_wait(&cond,&mutex);
			printf("-----------------------------\n");
		}
		if(money == 0) {
		   money += 200;
		   printf("子线程: money = %d\n",money);
		}
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}
int main() {
    pthread_t tid;
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
	pthread_create(&tid,NULL,&thread_run,NULL);
	money = 1000;
	while(1) {
	    pthread_mutex_lock(&mutex);
		if(money > 0) {
			money -= 100;
			printf("主线程: money = %d\n",money);
		}
		pthread_mutex_unlock(&mutex);
		if(money == 0) {
		   pthread_cond_signal(&cond);
		}
		sleep(1);
	}
	return 0;
}

