/**
 * Author:   KeeneChen
 * DateTime: 2021.10.16-09:27:51
 * Description: Windows Socket Server
 */

#include "./Socket.h"

/**
 * 1.初始化DLL
 * 2.创建套接字
 * 3.绑定套接字
 * 4.进行监听
 * 5.接收客户端请求
 * 6.先客户端发送数据
 * 7.关闭套接字
 * 8.终止DLL使用
 */

int main(void)
{
    // 1.初始化DLL
    WSADATA wsadata;
    WORD wVersionRequested = MAKEWORD(2, 2);
    WSAStartup(wVersionRequested, &wsadata);

    // 2.创建套接字
    SOCKET serverSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // 返回值为SOCKET类型句柄，类似Linux文件标识符

    // 3.绑定套接字
    SOCKADDR_IN sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(PORT);
    sockAddr.sin_addr.s_addr = inet_addr(IP);
    bind(serverSock, (SOCKADDR *)&sockAddr, sizeof(sockAddr));

    // 4.进行监听
    listen(serverSock, 20);

    // 5.接收客户端请求
    SOCKADDR_IN clientAddr;
    int size = sizeof(SOCKADDR);
    SOCKET clientSock = accept(serverSock, (SOCKADDR *)&clientAddr, &size);

    // 6.先客户端发送数据
    char str[BUF_SIZE] = "KeeneChen";
    send(clientSock, str, strlen(str) + sizeof(char), 0);

    // 7.关闭套接字
    closesocket(clientSock);
    closesocket(serverSock);

    // 8.终止DLL使用
    WSACleanup();
    return 0;
}