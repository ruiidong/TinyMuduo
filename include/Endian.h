#pragma once

#include <stdint.h>
#include <endian.h>

namespace sockets
{
    inline uint32_t hostToNetwork32(uint32_t host32)
    {
        return htobe32(host32);
    }

    inline uint16_t hostToNetwork16(uint16_t host16)
    {
        return htobe16(host16);
    }

    inline uint16_t networkToHost16(uint16_t net16)
    {
        return be16toh(net16);
    }
}