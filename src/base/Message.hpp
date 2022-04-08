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
        char *buf = new char[1024* 1024];
        sprintf(buf, "msgID = %d\nparam = %d\nparam1 = %d\nparam2 = %d\nparam3 = %d\nparam4 = %d\nrecog = %d\ndata = %s\n", msgID, param, param1, param2, param3, param4, recog, data.c_str());
        std::string str = std::string(buf);
        delete buf;
        return str;
    }

    hv::Buffer *Encode()
    {
        // hv::BufferPtr buf = std::make_shared(new hv::Buffer);
    }

    int getInt(char *lp, bool isBig = true, int len = 4)
    {
        int body_len = 0;
        if (isBig)
        {
            for (int i = 0; i < len; ++i)
            {
                body_len = (body_len << 8) | (unsigned int)*lp++;
            }
        }
        else
        {
            for (int i = 0; i < len; ++i)
            {
                body_len |= ((unsigned int)*lp++) << (i * 8);
            }
        }
        return body_len;
    }

    void Decode(HVLBuf *hvlBuffer)
    {
        char *intT = new char[4];
        printf(intT);
        hvlBuffer->pop_front(intT, 4);
        msgID = getInt(intT);
        hvlBuffer->pop_front(intT, 4);
        param = getInt(intT);
        hvlBuffer->pop_front(intT, 4);
        param1 = getInt(intT);
        hvlBuffer->pop_front(intT, 4);
        param2 = getInt(intT);
        hvlBuffer->pop_front(intT, 4);
        param3 = getInt(intT);
        hvlBuffer->pop_front(intT, 4);
        param4 = getInt(intT);
        hvlBuffer->pop_front(intT, 4);
        recog = getInt(intT);

        if (hvlBuffer->size() > 0)
        {
            data = std::move(hvlBuffer->data());
        }
        delete intT;
    }
};