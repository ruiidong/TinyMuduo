#include "InetAddress.h"
#include "Endian.h"
#include "SocketOps.h"
#include <strings.h>
#include <arpa/inet.h>

InetAddress::InetAddress(uint16_t port)
{
    ::bzero(&addr_, sizeof addr_);
    string ip = "127.0.0.1";
    sockets::fromIpPort(ip.c_str(), port, &addr_);
}

InetAddress::InetAddress(string ip, uint16_t port)
{
    ::bzero(&addr_, sizeof addr_);
    sockets::fromIpPort(ip.c_str(), port, &addr_);
}

string InetAddress::toIp() const
{
    char buf[64] = "";
    sockets::toIp(buf, sizeof buf, getSockAddr());
    return buf;
}

string InetAddress::toIpPort() const
{
    char buf[64] = "";
    sockets::toIpPort(buf, sizeof buf, getSockAddr());
    return buf;
}

uint16_t InetAddress::port() const
{
    return sockets::networkToHost16(addr_.sin_port);
}