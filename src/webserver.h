#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uv.h"
#include "http.c"

/**
 * HTTP Client.
 *
 * The HTTP Client uses a TCP socket stream, a instance of HTTP Parser and a
 * usable write request to write our response to the socket stream.
typedef struct {
    uv_write_t req;
    uv_stream_t stream;
    http_parser parser;
    http_request_t request;
} http_client_t;
 */

/**
 * TCP on new connection callback.
 */
void connection_cb(uv_stream_t* server, int status);

/**
 * Reads data from tcp client.
 */
void read_cb(uv_stream_t* stream, ssize_t nread, uv_buf_t);

/**
 * Writes data from read to the tcp client.
 */
void write_cb(uv_write_t* req, int status);

/**
 * Readers header field from http request.
 */
int headers_complete_cb(http_parser* parser);

/**
 * Allocates a new buffer for reading.
 */
uv_buf_t alloc_buffer(uv_handle_t* handle, size_t size);

#endif