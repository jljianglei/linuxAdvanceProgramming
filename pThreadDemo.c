#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
typedef struct{
   int val;
   float fval;
   char* buf;
}Info;
void * thread_run(void *arg) {
    Info* info = (Info*)arg;
	if(info == NULL)
		return 0;
	printf("%d,%f,%s\n",info->val,info->fval,info->buf);
	return 0;
}
int main() {
    pthread_t tid;
	Info* info1 = malloc(sizeof(Info));
	if(info1 == NULL) {
	   printf("info malloc faild\n");
	   return -1;
	}
	memset(info1,0,sizeof(Info));
	info1->buf = "123456";
	info1->val = 10;
	info1->fval = 1.2;
	if(pthread_create(&tid,NULL,&thread_run,info1) != 0) {
	   printf("pthread_create faild\n");
	   if(info1) {
	      free(info1);
		  info1 = NULL;
	   }
	   return -1;
	}
	pthread_join(tid,NULL);
	return 0;
}
