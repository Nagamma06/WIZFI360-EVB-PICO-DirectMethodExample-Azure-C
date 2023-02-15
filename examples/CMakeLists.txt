set(TARGET_NAME azure_mqtt_demo)
set(TARGET_FILES
        ${TARGET_NAME}.c
        app_main.c
        iot_demo.c
        sample_certs.c
        socket_startup.c
        ${CMAKE_CURRENT_SOURCE_DIR}/custom_hsm_example/custom_hsm_x509.c
        ${CMAKE_CURRENT_SOURCE_DIR}/iothub_ll_c2d_sample/iothub_ll_c2d_sample.c
        ${CMAKE_CURRENT_SOURCE_DIR}/iothub_ll_client_x509_sample/iothub_ll_client_x509_sample.c
        ${CMAKE_CURRENT_SOURCE_DIR}/iothub_ll_telemetry_sample/iothub_ll_telemetry_sample.c
        ${CMAKE_CURRENT_SOURCE_DIR}/prov_dev_client_ll_sample/prov_dev_client_ll_sample.c
        ${CMAKE_CURRENT_SOURCE_DIR}/iothub_ll_c2d_method_invoke_sample/iothub_ll_c2d_method_invoke_sample.c
)

add_executable(${TARGET_NAME} ${TARGET_FILES})

target_include_directories(${TARGET_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PORT_DIR}
)

target_link_libraries(${TARGET_NAME} PRIVATE
        pico_stdlib
        cmsis_core
        CMSIS_FREERTOS_FILES
        FREERTOS_FILES
        IOT_SOCKET_FILES
        WIZFI360_FILES
        AZURE_SDK_PORT_FILES
        mbedtls
        mbedx509
        mbedcrypto
        TIMER_FILES
)

pico_enable_stdio_usb(${TARGET_NAME} 1)
pico_enable_stdio_uart(${TARGET_NAME} 0)

pico_add_extra_outputs(${TARGET_NAME})
