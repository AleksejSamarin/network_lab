#include <iostream>
//#include <sys/types.h>
//#include <sys/socket.h>
#include <arpa/inet.h>  // inet_ntop()
#include <netdb.h>      // gethostbyname()
#include <unistd.h>     // close()
//#include <netinet/in.h>
//#include <netdb.h>
//#include <cstring>

int main(int argc, char **argv) {
    char host[] = "www.google.com";
    uint16_t port = 8080;
    char ip[INET_ADDRSTRLEN];
    struct sockaddr_in addr{};
    struct hostent *host_info;

    host_info = gethostbyname(host);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)host_info->h_addr_list[0];

    inet_ntop(AF_INET, &(addr.sin_addr), ip, INET_ADDRSTRLEN);
    printf("%s\n", ip);
    return 0;
}