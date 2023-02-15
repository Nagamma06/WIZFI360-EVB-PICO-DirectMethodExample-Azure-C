// Copyright (c) WIZnet. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

// CAVEAT: This sample is to demonstrate Azure IoT client concepts only and is not a guide design principles or style
// Checking of return codes and error values shall be omitted for brevity.  Please practice sound engineering practices
// when writing production code.

#ifndef _NETIF_H_
#define _NETIF_H_

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * ----------------------------------------------------------------------------------------------------
 * Includes
 * ----------------------------------------------------------------------------------------------------
 */

/**
 * ----------------------------------------------------------------------------------------------------
 * Macros
 * ----------------------------------------------------------------------------------------------------
 */

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
/* DNS */
/**
 * \fn            int32_t wizchip_get_host_by_name (const char *name, int32_t af, uint8_t *ip, uint32_t *ip_len)
 * \brief         Retrieve host IP address from host name.
 * \param[in]     name     Host name
 * \param[in]     af       Address family
 * \param[out]    ip       Pointer to buffer where resolved IP address shall be returned
 * \param[in,out] ip_len   Pointer to length of 'ip'
 *                  - length of supplied 'ip' on input
 *                  - length of stored 'ip' on output
 * \return        status information
 *                  - 0                                 : Operation successful
 *                  - -1                                : Operation failed
 */
int32_t wizchip_get_host_by_name(const char *name, int32_t af, uint8_t *ip, uint32_t *ip_len);

/* SNTP */
/**
 * \fn            void wizchip_sntp_init(void)
 * \brief         Initialize SNTP/NTP.
 *
 * \return        none
 */
void wizchip_sntp_init(void);

/**
 * \fn            time_t wizchip_sntp_get_current_timestamp(void)
 * \brief         Get current time from SNTP/NTP server.
 *
 * \return        status information
 *                  - \ref seconds                      : Current time get from the SNTP/NTP server is returned.
 */
time_t wizchip_sntp_get_current_timestamp(void);

/**
 * \fn            time_t iot_socket_get_current_timestamp(void)
 * \brief         Get current time from SNTP/NTP server.
 *
 * \return        status information
 *                  - \ref seconds                      : Current time get from the SNTP/NTP server is returned,
 *                                                        returns a negative number if an invalid time is obtained.
 */
time_t iot_socket_get_current_timestamp(void);

/* Timer */
/**
 * \fn            void timer_callback(void *argument)
 * \brief         1 second timer callback function.
 *
 * \return        none
 */
void timer_callback(void *argument);

#ifdef __cplusplus
}
#endif

#endif /* _NETIF_H_ */
