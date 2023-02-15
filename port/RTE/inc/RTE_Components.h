#ifndef RTE_COMPONENTS_H
#define RTE_COMPONENTS_H

#include "hardware/regs/addressmap.h"

/*
 * Define the Device Header File:
 */
#define CMSIS_device_header "RP2040.h"

/* ARM.FreeRTOS::RTOS.Config.CMSIS RTOS2 */
#define RTE_RTOS_FreeRTOS_CONFIG_RTOS2 /* RTOS FreeRTOS Config for CMSIS RTOS2 API */
/* ARM.FreeRTOS::RTOS.Core.Cortex-M */
#define RTE_RTOS_FreeRTOS_CORE /* RTOS FreeRTOS Core */
/* ARM.FreeRTOS::RTOS.Event Groups */
#define RTE_RTOS_FreeRTOS_EVENTGROUPS /* RTOS FreeRTOS Event Groups */
/* ARM.FreeRTOS::RTOS.Heap.Heap_4 */
#define RTE_RTOS_FreeRTOS_HEAP_4 /* RTOS FreeRTOS Heap 4 */
/* ARM.FreeRTOS::RTOS.Timers */
#define RTE_RTOS_FreeRTOS_TIMERS /* RTOS FreeRTOS Timers */
/* ARM::CMSIS.RTOS2.FreeRTOS.Cortex-M */
#define RTE_CMSIS_RTOS2          /* CMSIS-RTOS2 */
#define RTE_CMSIS_RTOS2_FreeRTOS /* CMSIS-RTOS2 FreeRTOS */

/* ARM::Security:mbed TLS:2.28.0 */
#define RTE_Security_mbedTLS /* Security mbed TLS */
#define RTE_Compiler_IO_STDIN      /* Compiler I/O: STDIN */
#define RTE_Compiler_IO_STDIN_User /* Compiler I/O: STDIN User */
/* Keil.ARM Compiler::Compiler:I/O:STDOUT:User:1.2.0 */
/* Keil::CMSIS Driver:WiFi:WizFi360:UART:1.4.0 */
#define RTE_Drivers_WiFi_WIZFI360_UART /* Driver WiFi WizFi360 (UART) */
#define RTE_IoT_Client_Azure /* Azure IoT Client */
/* MDK-Packs::IoT Utility:Azure:Common:1.1.4 */
#define RTE_IoT_Azure_Common /* Azure Common Code */
/* MDK-Packs::IoT Utility:Azure:MQTT:1.1.4 */
#define RTE_IoT_Azure_MQTT /* Azure MQTT */
/* MDK-Packs::IoT Utility:Socket:WiFi:1.0.0 */
#define RTE_IoT_Socket      /* IoT Socket */
#define RTE_IoT_Socket_WiFi /* IoT Socket: WiFi */

#endif /* RTE_COMPONENTS_H */
