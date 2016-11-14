#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include<time.h>

void doprocessing (int sock,int Ans) {
   int n;
   char buffer[256],c,i,j,CAns,AAns[4],ACAns[4],A=0,B=0,AC,AA;
   char *message,re[100];
   bzero(buffer,256);
   n = read(sock,buffer,255);
   
   if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }
printf("Here is the message: %s\n",buffer);
A=0;
B=0;
AA = Ans;
CAns = (buffer[0]-'0')*1000+(buffer[1]-'0')*100+(buffer[2]-'0')*10+(buffer[3]-'0');
ACAns[0] = CAns/1000;
CAns-=ACAns[0]*1000;
ACAns[1] = CAns/100;
CAns-=ACAns[1]*100;
ACAns[2] = CAns/10;
CAns-=ACAns[2]*10;
ACAns[3] = CAns/1;
AAns[0] = AA/1000;
AA-=AAns[0]*1000;
AAns[1] = AA/100;
AA-=AAns[1]*100;
AAns[2] = AA/10;
AA-=AAns[2]*10;
AAns[3] = AA/1;
for(i = 0;i<=3;i++)
{
if(ACAns[i]==AAns[i])
{
A++;
}
}
for(j=0;j<=3;j++)
{
for(i=0;i<=3;i++)
{
if(ACAns[i]==AAns[j]&&i!=j)
{
B++;
}
}
}
if(A==4)
{
message = "You Are RIGHT!!!";
write(sock , message, strlen(message)+1);
}
else
{
	sprintf(re,"%dA%dB",A,B);
	n = write(sock , re, strlen(re)+1);;
}  
   n = write(sock,"I got your message",18);
   
   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }
	
}
