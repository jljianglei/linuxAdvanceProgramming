#include<stdio.h>
int main() {
   FILE* fp;
   fp = fopen("log.txt","wb+");
   if(fp == NULL) {
      printf("fopen faild\n");
	  return;
   }
   fprintf(fp,"this is first log\n");
   fprintf(stdout,"this is first log\n");
   fprintf(stderr,"this is first log\n");
   //fprintf(stdin,"this is first log\n");
   fprintf(fp,"this is second log\n");
   fprintf(stdout,"this is second log\n");
   fprintf(stderr,"this is first log\n");
   //fprintf(stdin,"this is first log\n");
   if(fp) {
      fclose(fp);
	  fp = NULL;
   }
   return 0;
}
