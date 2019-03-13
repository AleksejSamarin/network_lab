#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc == 3) { // www.google.com 8080
        printf("Host: %s, port: %d\n", argv[1], atoi(argv[2]));
        char ip[INET_ADDRSTRLEN];
        struct sockaddr_in addr{};
        struct hostent *host_info;
        int sock;

        host_info = gethostbyname(argv[1]);
        addr.sin_family = AF_INET;
        addr.sin_port = htons((uint16_t)atoi(argv[2]));
        addr.sin_addr = *(struct in_addr *)host_info->h_addr_list[0];

        inet_ntop(AF_INET, &(addr.sin_addr), ip, INET_ADDRSTRLEN);
        printf("IP: %s\n", ip);

        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            printf("Socket creation error\n");
            return -1;
        }
        connect(sock, (struct sockaddr *)&addr, sizeof(addr));
        close(sock);
        return 0;
    }
    return -1;
}