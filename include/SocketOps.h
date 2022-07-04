#pragma once

#include <arpa/inet.h>

namespace sockets
{
        void fromIpPort(const char *ip, uint16_t port,
                        struct sockaddr_in *addr);

        void toIp(char *buf, size_t size,
                  const struct sockaddr *addr);

        void toIpPort(char *buf, size_t size,
                      const struct sockaddr *addr);

        ssize_t write(int sockfd, const void *buf, size_t count);

        ssize_t read(int sockfd, void *buf, int count);
}