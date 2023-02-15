// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#include "azure_c_shared_utility/tcpsocketconnection_c.h"

#include "iot_socket.h"
#include "Driver_WiFi.h"

#include "sys/socket.h"
#include "netif.h"

/* IP address family */
#define AF_INET IOT_SOCKET_AF_INET

extern NetworkContext_t g_network_context;

TCPSOCKETCONNECTION_HANDLE tcpsocketconnection_create(void)
{
    NetworkContext_t *network_context = &g_network_context;

    network_context->socket_descriptor = iotSocketCreate(AF_INET, IOT_SOCKET_SOCK_STREAM, IOT_SOCKET_IPPROTO_TCP);

    if (network_context->socket_descriptor < 0)
    {
        printf(" TCP socket create failed : %d\n", network_context->socket_descriptor);
    }
    else
    {
        printf(" TCP socket create : %d\n", network_context->socket_descriptor);
    }

    return (TCPSOCKETCONNECTION_HANDLE)network_context;
}

void tcpsocketconnection_set_blocking(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle, bool blocking, unsigned int timeout)
{
    ;
}

void tcpsocketconnection_destroy(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle)
{
    NetworkContext_t *network_context = (NetworkContext_t *)tcpSocketConnectionHandle;

    iotSocketClose(network_context->socket_descriptor);

    printf(" TCP socket destroy : %d\n", network_context->socket_descriptor);
}

int tcpsocketconnection_connect(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle, const char *host, const int port)
{
    int32_t retval = -1;
    uint8_t ip[4] = {0, };
    uint32_t ip_len = 0;

    NetworkContext_t *network_context = (NetworkContext_t *)tcpSocketConnectionHandle;

    retval = wizchip_get_host_by_name(host, AF_INET, ip, &ip_len);

    if (retval != 0)
    {
        return (-1);
    }

    retval = iotSocketConnect(network_context->socket_descriptor, ip, ip_len, port);

    if (retval < 0)
    {
        printf(" TCP socket connect failed : %d\n", retval);

        iotSocketClose(network_context->socket_descriptor);

        return (-1);
    }

    printf(" TCP socket connect : %d\n", retval);

    return 0;
}

bool tcpsocketconnection_is_connected(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle)
{
    int32_t retval = -1;
    uint8_t ip[4] = {0, };
    uint16_t port = 0;
    uint32_t ip_len = 0;

    NetworkContext_t *network_context = (NetworkContext_t *)tcpSocketConnectionHandle;

    retval = iotSocketGetPeerName(network_context->socket_descriptor, ip, &ip_len, &port);

    if (retval < 0)
    {
        return false;
    }

    return true;
}

void tcpsocketconnection_close(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle)
{
    NetworkContext_t *network_context = (NetworkContext_t *)tcpSocketConnectionHandle;

    iotSocketClose(network_context->socket_descriptor);

    printf(" TCP socket close : %d\n", network_context->socket_descriptor);
}

int tcpsocketconnection_send(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle, const char *data, int length)
{
    int32_t retval = -1;

    NetworkContext_t *network_context = (NetworkContext_t *)tcpSocketConnectionHandle;

    retval = iotSocketSend(network_context->socket_descriptor, data, length);

    if (retval < 0)
    {
        return (-1);
    }

    return retval;
}

int tcpsocketconnection_send_all(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle, const char *data, int length)
{
    int32_t retval = -1;

    NetworkContext_t *network_context = (NetworkContext_t *)tcpSocketConnectionHandle;

    retval = iotSocketSend(network_context->socket_descriptor, data, length);

    if (retval < 0)
    {
        return (-1);
    }

    return retval;
}

int tcpsocketconnection_receive(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle, char *data, int length)
{
    int32_t retval = -1;
    uint32_t timeout = 0;

    NetworkContext_t *network_context = (NetworkContext_t *)tcpSocketConnectionHandle;

    /* Set socket receive timeout: 5 seconds */
    timeout = 5000U;

    retval = iotSocketSetOpt(network_context->socket_descriptor, IOT_SOCKET_SO_RCVTIMEO, &timeout, sizeof(timeout));

    if (retval < 0)
    {
        return (-1);
    }

    retval = iotSocketRecv(network_context->socket_descriptor, data, length);

    if (retval < 0)
    {
        return (0);
    }

    return retval;
}

int tcpsocketconnection_receive_all(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle, char *data, int length)
{
    int32_t retval = -1;
    uint32_t timeout = 0;

    NetworkContext_t *network_context = (NetworkContext_t *)tcpSocketConnectionHandle;

    /* Set socket receive timeout: 5 seconds */
    timeout = 5000U;

    retval = iotSocketSetOpt(network_context->socket_descriptor, IOT_SOCKET_SO_RCVTIMEO, &timeout, sizeof(timeout));

    if (retval < 0)
    {
        return (-1);
    }

    retval = iotSocketRecv(network_context->socket_descriptor, data, length);

    if (retval < 0)
    {
        return (0);
    }

    return retval;
}
