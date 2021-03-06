#ifndef HTTPHANDLER_H_
#define HTTPHANDLER_H_

#include "httpparse.h"

class HttpHandler
{
public:
    HttpHandler(int sock);
    bool Handle (const char *buffer);

private:
    int8_t ParseHttpRequest (const char *buffer);
    bool GetFile();
    bool SendResponse (int socket, bool status);

    struct {
        std::string status_code;
        std::string http_version;
        std::string data;
    } response;

    int socket;
    // std::string read_data;
    HttpParse parser;
    HttpRequest request;
};

#endif
