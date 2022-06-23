#include "SocketOps.h"
#include "Endian.h"
#include "Logging.h"
#include <sys/socket.h>
#include <string.h>

void sockets::fromIpPort(const char *ip, uint16_t port,
                         struct sockaddr_in *addr)
{
    addr->sin_family = AF_INET;
    addr->sin_port = hostToNetwork16(port);
    if (::inet_pton(AF_INET, ip, &addr->sin_addr) <= 0)
    {
        LOG_ERROR("sockets::fromIpPort");
    }
}

void sockets::toIp(char *buf, size_t size,
                   const struct sockaddr *addr)
{
    const struct sockaddr_in *addr4 = (const struct sockaddr_in *)addr;
    ::inet_ntop(AF_INET, &addr4->sin_addr, buf, static_cast<socklen_t>(size));
}

void sockets::toIpPort(char *buf, size_t size,
                       const struct sockaddr *addr)
{
    toIp(buf, size, addr);
    size_t end = ::strlen(buf);
    const struct sockaddr_in *addr4 = (const struct sockaddr_in *)addr;
    uint16_t port = sockets::networkToHost16(addr4->sin_port);
    snprintf(buf + end, size - end, ":%u", port);
}