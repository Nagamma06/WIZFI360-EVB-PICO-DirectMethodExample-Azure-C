# azure-iot-sdk-c
add_library(AZURE_SDK_PORT_FILES STATIC)

target_sources(AZURE_SDK_PORT_FILES PUBLIC
        ${PORT_DIR}/azure-iot-sdk-c/src/agenttime.c
        ${PORT_DIR}/azure-iot-sdk-c/src/lock.c
        ${PORT_DIR}/azure-iot-sdk-c/src/netif.c
        ${PORT_DIR}/azure-iot-sdk-c/src/netutil.c
        ${PORT_DIR}/azure-iot-sdk-c/src/platform_freertos.c
        ${PORT_DIR}/azure-iot-sdk-c/src/tcpsocketconnection_c.c
        ${PORT_DIR}/azure-iot-sdk-c/src/threadapi.c
        ${PORT_DIR}/azure-iot-sdk-c/src/tickcounter.c
        ${PORT_DIR}/azure-iot-sdk-c/src/tlsio_mbedtls.c
        )

target_include_directories(AZURE_SDK_PORT_FILES PUBLIC
        ${CMSIS_5_DIR}/CMSIS/Driver/Include
        ${MBEDTLS_DIR}/include
        ${PORT_DIR}
        ${PORT_DIR}/azure-iot-sdk-c/inc
        )

target_link_libraries(AZURE_SDK_PORT_FILES PUBLIC
        pico_stdlib
        CMSIS_FREERTOS_FILES
        FREERTOS_FILES
        IOT_SOCKET_FILES
        AZURE_SDK_FILES
        )

# timer
add_library(TIMER_FILES STATIC)

target_sources(TIMER_FILES PUBLIC
        ${PORT_DIR}/timer/src/timer.c
        )

target_include_directories(TIMER_FILES PUBLIC
        ${PORT_DIR}
        ${PORT_DIR}/timer/inc
        )

target_link_libraries(TIMER_FILES PRIVATE
        pico_stdlib
        )

# WizFi360
add_library(WIZFI360_FILES STATIC)

target_sources(WIZFI360_FILES PUBLIC
        ${PORT_DIR}/WizFi360/src/UART_RP2040.c
        )

target_include_directories(WIZFI360_FILES PUBLIC
        ${CMSIS_5_DIR}/CMSIS/Driver/Include
        ${PORT_DIR}
        ${PORT_DIR}/RTE/inc
        ${PORT_DIR}/WizFi360/inc
        )

target_link_libraries(WIZFI360_FILES PRIVATE
        pico_stdlib
        hardware_uart
        cmsis_core
        CMSIS_FREERTOS_FILES
        FREERTOS_FILES
        WIZFI360_DRIVER_FILES
        )
