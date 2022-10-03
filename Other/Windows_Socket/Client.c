/**
 * Author:   KeeneChen
 * DateTime: 2021.10.16-10:12:10
 * Description: Windows Socket Clinet
 */

#include "./Socket.h"

/**
 * 1.初始化DLL
 * 2.创建套接字
 * 3.向服务器发起请求
 * 4.接收服务器数据
 * 5.业务模块
 * 6.关闭套接字
 * 7.终止DLL
 */

int main(void)
{
    // 1.初始化DLL
    WSADATA wsadata;
    // word wVersionRequested = MAKEWORD(2, 2);
    WSAStartup(MAKEWORD(2, 2), &wsadata);

    // 2.创建套接字
    SOCKET clientSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // 返回值为SOCKET类型句柄，类似Linux文件标识符

    // 3.向服务器发起请求
    SOCKADDR_IN sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(PORT);
    sockAddr.sin_addr.s_addr = inet_addr(IP);
    connect(clientSock, (SOCKADDR *)&sockAddr, sizeof(sockAddr));

    // 4.接收服务器数据
    char recvBuf[BUF_SIZE] = {0};
    recv(clientSock, recvBuf, BUF_SIZE, 0);

    // 5.打印接收数据
    printf("Messages form Server: %s\n",recvBuf);

    // 6.关闭套接字
    closesocket(clientSock);

    // 7.终止DLL使用
    WSACleanup();
    system("pause");
    return 0;
}