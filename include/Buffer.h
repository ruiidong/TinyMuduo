#pragma once

#include <vector>
#include <unistd.h>

class Buffer
{
public:
    
private:
    std::vector<char> buffer_;
    size_t readerIndex_;
    size_t writerIndex_;

    static const char kCRLF[];
};