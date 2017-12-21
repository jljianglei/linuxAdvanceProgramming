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
int main() {
   Message rcvmsg;
   memset(&rcvmsg,0,sizeof(rcvmsg));
   int running = 1;
   int msgid = -1;
   long int msgType = 0;
   msgid = msgget((key_t)MSG_KEY,0666 | IPC_CREAT);
   if(msgid == -1) {
      perror("msgget faild");
	  return -1;
   }
   while(running) {
      if(msgrcv(msgid,(void *)&rcvmsg,MSG_MAX_LENGTH,msgType,0) == -1) {
	     perror("msgrcv faild");
		 return -1;
	  }
	  printf("rcv data is %s\n",rcvmsg.msg_buf);
	  if(strncmp(rcvmsg.msg_buf,"end",3) == 0) {
	     running = 0;
	  }
   }
   if(msgctl(msgid,IPC_RMID,0) == -1) {
      perror("msgctl faild");
	  return -1;
   }
   return 0;
}
