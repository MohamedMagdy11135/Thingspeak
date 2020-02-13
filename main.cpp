#include <stdio.h>
#include <winsock2.h>
#include <delayimp.h>
#pragma comment(lib,"ws2_32.lib")//winsock liberary bdal ely 3amaltelha include fe

int main(int argc, char *argv[])
{
    /*-----------------------Special init for Windows----------------------------------------*/
    WSADATA wsa;
    SOCKET s;//soket desc low fe EM int
    struct sockaddr_in server;

    printf("\ninitialising Winsock....");
    if(WSAStartup(MAKEWORD(2,2),&wsa) !=0)
    {
        printf("Failed Error Code :&d",WSAGetLastError());
        return 1;//mean that code return error
    }
    printf("Initialised.\n");
    /*---------------------------------------------------------------------------------------*/
    //create socket
    int y=50;
    while(1)
    {
    if((s = socket(AF_INET , SOCK_STREAM ,0)) == INVALID_SOCKET)
    {
        printf("Cloud not create socket : %d", WSAGetLastError());
    }
    printf("socket created\n");
    /*-------------------------------------creat socket--------------------------*/
    server.sin_family = AF_INET;//Address family ipv4
    server.sin_port = htons(80);//443 port of HTTP
    server.sin_addr.s_addr = inet_addr("184.106.153.149");
    int x = connect(s,(struct sockaddr *)&server,sizeof(server));
    printf("Connection error : %d",x);
    char massage[200] ="GET /update?api_key=B0B0U9DBP3BJ5GFB&field1=";
    char recv_buf[2000]="";
    printf("send done");
    sprintf(massage+strlen(massage),"%d",y);
    strcat(massage, "\r\n\r\n");
    int count =send(s,massage,strlen(massage),0);
    printf("\nbytes transmitted  :%d \n\n\n",count);
    printf("%s",massage);
   // recv(s,recv_buf,2000,0);
   // puts(recv_buf);
    y=y+5;
    Sleep(5000);
    }
closesocket(s);
}
