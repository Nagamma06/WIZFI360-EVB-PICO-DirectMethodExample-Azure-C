/* -----------------------------------------------------------------------------
 * Copyright (c) 2020 Arm Limited (or its affiliates). All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "Driver_WiFi.h"

/* Wi-Fi configuration */
#define SSID "ssid"
#define PASSWORD "password"
#define SECURITY_TYPE ARM_WIFI_SECURITY_WPA2

extern ARM_DRIVER_WIFI Driver_WiFi1;

int32_t socket_startup(void)
{
    ARM_WIFI_CONFIG_t config;
    int32_t retval = ARM_DRIVER_ERROR;

    printf(" Connecting to WiFi ...\n");

    retval = Driver_WiFi1.Initialize(NULL);
    printf(" Driver_WiFix.Initialize(NULL) : %d\n", retval);

    retval = Driver_WiFi1.PowerControl(ARM_POWER_FULL);
    printf(" Driver_WiFix.PowerControl(ARM_POWER_FULL) : %d\n", retval);

    memset((void *)&config, 0, sizeof(config));

    config.ssid = SSID;
    config.pass = PASSWORD;
    config.security = SECURITY_TYPE;
    config.ch = 0U;

    retval = Driver_WiFi1.Activate(0U, &config);
    printf(" Driver_WiFix.Activate(0U, &config) : %d\n", retval);

    retval = Driver_WiFi1.IsConnected();
    printf(" Driver_WiFix.IsConnected() : %d\n", retval);

    if (retval == 0U)
    {
        printf(" Wi-Fi network connection failed!\n");

        return -1;
    }
    else // returns '1' if the Wi-Fi connection is successful.
    {
        printf(" Wi-Fi network connection succeeded!\n");
    }

    return 0;
}
