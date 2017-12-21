#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#define MSG_MAX_LENGTH 1024
#define MSG_KEY 1024
typedef struct {
	long int msg_type;
	char msg_buf[MSG_MAX_LENGTH];
}Message;

enum msg_type {
	INVALID_MSG,
    MSG_1,
	MSG_2,
	MSG_3,
	MSG_a,
	MSG_b,
	MSG_c
};
int main() {
    int running = 1;
	Message msg;
	memset(&msg,0,sizeof(Message));
	char tmp[MSG_MAX_LENGTH];
	int msgId = -1;
	/*创建消息队列*/
	msgId = msgget((key_t)MSG_KEY,0666 | IPC_CREAT);
	if(msgId == -1) {
	   perror("msgget faild\n");
	   return -1;
	}
	printf("msgId = %d\n",msgId);
	while(running) {
	    printf("enter sone text: ");
		fgets(tmp,MSG_MAX_LENGTH,stdin);
		strcpy(msg.msg_buf,tmp);
		printf("msg buf %s\n",msg.msg_buf);
		msg.msg_type = MSG_1;/*msg_type不能为0，否则snd会失败，失败原因就是不合理的参数*/ 
		if(msgsnd(msgId,(void*)&msg,MSG_MAX_LENGTH,0) == -1) {
		   perror("msgsnd faild\n");
		   return -1;
		}
		if(strncmp(msg.msg_buf,"end",3) == 0) {
		   running = 0;
		}
	}
	if(msgctl(msgId,IPC_RMID,0) == -1) {
	   perror("msgctl(IPC_RMID) faild");
	   return -1;
	}
	return 0;
}
