// Copyright (c) WIZnet. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

// CAVEAT: This sample is to demonstrate Azure IoT client concepts only and is not a guide design principles or style
// Checking of return codes and error values shall be omitted for brevity.  Please practice sound engineering practices
// when writing production code.

#ifndef _NETUTIL_H_
#define _NETUTIL_H_

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * ----------------------------------------------------------------------------------------------------
 * Includes
 * ----------------------------------------------------------------------------------------------------
 */
#include <stdint.h>

/**
 * ----------------------------------------------------------------------------------------------------
 * Macros
 * ----------------------------------------------------------------------------------------------------
 */
#define SYSTEM_LITTLE_ENDIAN

/**
 * ----------------------------------------------------------------------------------------------------
 * Variables
 * ----------------------------------------------------------------------------------------------------
 */

/**
 * ----------------------------------------------------------------------------------------------------
 * Functions
 * ----------------------------------------------------------------------------------------------------
 */
int8_t *inet_ntoa(uint32_t addr);
int8_t *inet_ntoa_pad(uint32_t addr);
uint32_t inet_addr(uint8_t *addr);
uint16_t swaps(uint16_t i);
uint32_t swapl(uint32_t l);
uint16_t htons(uint16_t hostshort);
uint32_t htonl(uint32_t hostlong);
uint32_t ntohs(uint16_t netshort);
uint32_t ntohl(uint32_t netlong);

#ifdef __cplusplus
}
#endif

#endif /* _NETUTIL_H_ */
