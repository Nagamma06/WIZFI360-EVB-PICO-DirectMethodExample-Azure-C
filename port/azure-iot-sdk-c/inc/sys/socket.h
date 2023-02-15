#ifndef _SOCKETS_H_
#define _SOCKETS_H_

/**
 * @transportstruct
 * @typedef NetworkContext_t
 * @brief The NetworkContext is an incomplete type. An implementation of this
 * interface must define struct NetworkContext for the system requirements.
 * This context is passed into the network interface functions.
 */
/* @[define_networkcontext] */
struct NetworkContext
{
    int socket_descriptor;
};
typedef struct NetworkContext NetworkContext_t;
/* @[define_networkcontext] */

#endif /* _SOCKETS_H_ */
