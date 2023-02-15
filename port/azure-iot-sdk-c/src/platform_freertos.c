// Copyright (C) Firmwave Ltd., All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <time.h>

#include "azure_c_shared_utility/platform.h"
#include "azure_c_shared_utility/xio.h"
#include "azure_c_shared_utility/tlsio_mbedtls.h"
#include "azure_c_shared_utility/threadapi.h"

#include "netif.h"

int platform_init(void)
{
    char strftime_buf[64] = {0, };
    struct tm timeinfo = {0};
    time_t curr_sectime = 0;

    wizchip_sntp_init();
    curr_sectime = wizchip_sntp_get_current_timestamp();

    localtime_r(&curr_sectime, &timeinfo);
    strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
    printf("The current date/time is: %s\n", strftime_buf);

    return 0;
}

const IO_INTERFACE_DESCRIPTION* platform_get_default_tlsio(void)
{
    return tlsio_mbedtls_get_interface_description();
}

STRING_HANDLE platform_get_platform_info(PLATFORM_INFO_OPTION options)
{
    // No applicable options, so ignoring parameter
    (void)options;

    // Expected format: "(<runtime name>; <operating system name>; <platform>)"

    return STRING_construct("(native; freertos; rp2040)");
}

void platform_deinit(void)
{
    while(1) {};
}
