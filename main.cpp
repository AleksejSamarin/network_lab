#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char **argv) {
    char host[] = "www.google.com";
    uint16_t port = 8080;
    char ip[INET_ADDRSTRLEN];
    struct sockaddr_in addr{};
    struct hostent *host_info;
    int sock;

    host_info = gethostbyname(host);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)host_info->h_addr_list[0];

    inet_ntop(AF_INET, &(addr.sin_addr), ip, INET_ADDRSTRLEN);
    printf("%s\n", ip);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }
    connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    return 0;
}