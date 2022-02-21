#pragma once

#include <string>
#include <iostream>
#include <memory>

#include "hv/Buffer.h"

class Message
{
public:
    int msgID = 0;
    int param = 1;
    int param1 = 2;
    int param2 = 3;
    int param3 = 40;
    int param4 = 50;
    int recog = -1;
    std::string data = "";

    std::string ToString()
    {
        char buf[sizeof(int)];
        sprintf(buf, "msgID = %d\nparam = %d\nparam1 = %d\nparam2 = %d\nparam3 = %d\nparam4 = %d\nrecog = %d\ndata = %s\n", msgID, param, param1, param2, param3, param4, recog, data.c_str());
        return buf;
    }

    hv::Buffer *Encode()
    {
        // hv::BufferPtr buf = std::make_shared(new hv::Buffer);
    }

    void Decode(hv::Buffer *buf)
    {
        int offset = 4;
        msgID = ReadInt(buf, offset);
        param = ReadInt(buf, offset);
        param1 = ReadInt(buf, offset);
        param2 = ReadInt(buf, offset);
        param3 = ReadInt(buf, offset);
        param4 = ReadInt(buf, offset);
        recog = ReadInt(buf, offset);
        int size = buf->size() - 32;

        if (size > 0)
        {
            char *c = new char[size];
            memcpy(c, buf->base + 32, size);
            std::string str = std::move(c);
        }
    }

    int ReadInt(hv::Buffer *buf, int &offset)
    {
        char i[4];
        memcpy(i, buf->base + offset, 4);
        offset += 4;
        return atoi(i);
    }
};