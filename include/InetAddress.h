#pragma once

#include <netinet/in.h>
#include <string>

using namespace std;

class InetAddress
{
public:
    explicit InetAddress(uint16_t port = 0);
    InetAddress(string ip, uint16_t port);
    explicit InetAddress(const struct sockaddr_in &addr)
        : addr_(addr)
    {
    }

    sa_family_t family() const {return addr_ .sin_family;}
    string toIp() const;
    string toIpPort() const;
    uint16_t port() const;

    const sockaddr* getSockAddr() const {return (const sockaddr*)(&addr_);}     //      ?
    

private:
    sockaddr_in addr_;
};