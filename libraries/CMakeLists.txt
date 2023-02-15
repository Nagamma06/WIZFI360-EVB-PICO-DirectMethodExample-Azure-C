# AZURE SDK
add_library(AZURE_SDK_FILES STATIC)

target_sources(AZURE_SDK_FILES PUBLIC
        ${AZURE_SDK_DIR}/certs/certs.c
        ${AZURE_SDK_DIR}/c-utility/adapters/httpapi_compact.c
        ${AZURE_SDK_DIR}/c-utility/adapters/socketio_mbed.c
        ${AZURE_SDK_DIR}/c-utility/pal/tlsio_options.c
        ${AZURE_SDK_DIR}/c-utility/src/azure_base32.c
        ${AZURE_SDK_DIR}/c-utility/src/azure_base64.c
        ${AZURE_SDK_DIR}/c-utility/src/buffer.c
        ${AZURE_SDK_DIR}/c-utility/src/consolelogger.c
        ${AZURE_SDK_DIR}/c-utility/src/constbuffer.c
        ${AZURE_SDK_DIR}/c-utility/src/constmap.c
        ${AZURE_SDK_DIR}/c-utility/src/crt_abstractions.c
        ${AZURE_SDK_DIR}/c-utility/src/doublylinkedlist.c
        ${AZURE_SDK_DIR}/c-utility/src/gb_stdio.c
        ${AZURE_SDK_DIR}/c-utility/src/gb_time.c
        ${AZURE_SDK_DIR}/c-utility/src/gballoc.c
        ${AZURE_SDK_DIR}/c-utility/src/hmac.c
        ${AZURE_SDK_DIR}/c-utility/src/hmacsha256.c
        ${AZURE_SDK_DIR}/c-utility/src/http_proxy_io.c
        ${AZURE_SDK_DIR}/c-utility/src/httpapiex.c
        ${AZURE_SDK_DIR}/c-utility/src/httpapiexsas.c
        ${AZURE_SDK_DIR}/c-utility/src/httpheaders.c
        ${AZURE_SDK_DIR}/c-utility/src/map.c
        ${AZURE_SDK_DIR}/c-utility/src/optionhandler.c
        ${AZURE_SDK_DIR}/c-utility/src/sastoken.c
        ${AZURE_SDK_DIR}/c-utility/src/sha1.c
        ${AZURE_SDK_DIR}/c-utility/src/sha224.c
        ${AZURE_SDK_DIR}/c-utility/src/sha384-512.c
        ${AZURE_SDK_DIR}/c-utility/src/singlylinkedlist.c
        ${AZURE_SDK_DIR}/c-utility/src/string_token.c
        ${AZURE_SDK_DIR}/c-utility/src/string_tokenizer.c
        ${AZURE_SDK_DIR}/c-utility/src/strings.c
        ${AZURE_SDK_DIR}/c-utility/src/urlencode.c
        ${AZURE_SDK_DIR}/c-utility/src/usha.c
        ${AZURE_SDK_DIR}/c-utility/src/vector.c
        ${AZURE_SDK_DIR}/c-utility/src/xio.c
        ${AZURE_SDK_DIR}/c-utility/src/xlogging.c
        ${AZURE_SDK_DIR}/deps/parson/parson.c
        ${AZURE_SDK_DIR}/iothub_client/src/iothub.c
        ${AZURE_SDK_DIR}/iothub_client/src/iothub_client_authorization.c
        ${AZURE_SDK_DIR}/iothub_client/src/iothub_client_core_ll.c
        ${AZURE_SDK_DIR}/iothub_client/src/iothub_client_diagnostic.c
        ${AZURE_SDK_DIR}/iothub_client/src/iothub_client_ll.c
        ${AZURE_SDK_DIR}/iothub_client/src/iothub_client_ll_uploadtoblob.c
        ${AZURE_SDK_DIR}/iothub_client/src/iothub_client_retry_control.c
        ${AZURE_SDK_DIR}/iothub_client/src/iothub_device_client_ll.c
        ${AZURE_SDK_DIR}/iothub_client/src/iothub_message.c
        ${AZURE_SDK_DIR}/iothub_client/src/iothub_transport_ll_private.c
        ${AZURE_SDK_DIR}/iothub_client/src/iothubtransport.c
        ${AZURE_SDK_DIR}/iothub_client/src/iothubtransport_mqtt_common.c
        ${AZURE_SDK_DIR}/iothub_client/src/iothubtransporthttp.c
        ${AZURE_SDK_DIR}/iothub_client/src/iothubtransportmqtt.c
        ${AZURE_SDK_DIR}/iothub_client/src/version.c
        ${AZURE_SDK_DIR}/serializer/src/agenttypesystem.c
        ${AZURE_SDK_DIR}/serializer/src/codefirst.c
        ${AZURE_SDK_DIR}/serializer/src/commanddecoder.c
        ${AZURE_SDK_DIR}/serializer/src/datamarshaller.c
        ${AZURE_SDK_DIR}/serializer/src/datapublisher.c
        ${AZURE_SDK_DIR}/serializer/src/dataserializer.c
        ${AZURE_SDK_DIR}/serializer/src/iotdevice.c
        ${AZURE_SDK_DIR}/serializer/src/jsondecoder.c
        ${AZURE_SDK_DIR}/serializer/src/methodreturn.c
        ${AZURE_SDK_DIR}/serializer/src/multitree.c
        ${AZURE_SDK_DIR}/serializer/src/schema.c
        ${AZURE_SDK_DIR}/serializer/src/schemalib.c
        ${AZURE_SDK_DIR}/serializer/src/schemaserializer.c
        ${AZURE_SDK_DIR}/provisioning_client/adapters/hsm_client_data.c
        ${AZURE_SDK_DIR}/provisioning_client/deps/utpm/src/Marshal.c
        ${AZURE_SDK_DIR}/provisioning_client/deps/utpm/src/Memory.c
        ${AZURE_SDK_DIR}/provisioning_client/deps/utpm/src/tpm_codec.c
        ${AZURE_SDK_DIR}/provisioning_client/deps/utpm/src/tpm_comm_emulator.c
        ${AZURE_SDK_DIR}/provisioning_client/src/iothub_auth_client.c
        ${AZURE_SDK_DIR}/provisioning_client/src/iothub_security_factory.c
        ${AZURE_SDK_DIR}/provisioning_client/src/prov_auth_client.c
        ${AZURE_SDK_DIR}/provisioning_client/src/prov_device_client.c
        ${AZURE_SDK_DIR}/provisioning_client/src/prov_device_ll_client.c
        ${AZURE_SDK_DIR}/provisioning_client/src/prov_security_factory.c
        ${AZURE_SDK_DIR}/provisioning_client/src/prov_transport_mqtt_client.c
        ${AZURE_SDK_DIR}/provisioning_client/src/prov_transport_mqtt_common.c
        ${AZURE_SDK_DIR}/umqtt/src/mqtt_client.c
        ${AZURE_SDK_DIR}/umqtt/src/mqtt_codec.c
        ${AZURE_SDK_DIR}/umqtt/src/mqtt_message.c
        )

target_include_directories(AZURE_SDK_FILES PUBLIC
        ${AZURE_SDK_DIR}/certs
        ${AZURE_SDK_DIR}/c-utility/inc
        ${AZURE_SDK_DIR}/c-utility/deps/azure-macro-utils-c/inc
        ${AZURE_SDK_DIR}/c-utility/deps/umock-c/inc
        ${AZURE_SDK_DIR}/c-utility/pal/inc
        ${AZURE_SDK_DIR}/c-utility/pal/freertos
        ${AZURE_SDK_DIR}/c-utility/pal/generic
        ${AZURE_SDK_DIR}/iothub_client/inc
        ${AZURE_SDK_DIR}/umqtt/inc
        ${AZURE_SDK_DIR}/umqtt/inc/azure_umqtt_c
        ${AZURE_SDK_DIR}/serializer/inc
        ${AZURE_SDK_DIR}/deps/azure-macro-utils-c/inc
        ${AZURE_SDK_DIR}/deps/parson
        ${AZURE_SDK_DIR}/deps/umock-c/inc
        ${AZURE_SDK_DIR}/provisioning_client/inc
        ${AZURE_SDK_DIR}/provisioning_client/adapters
        ${AZURE_SDK_DIR}/provisioning_client/deps/utpm/inc
        ${PORT_DIR}/azure-iot-sdk-c/inc
        )

# WizFi360 Driver
add_library(WIZFI360_DRIVER_FILES STATIC)

target_sources(WIZFI360_DRIVER_FILES PUBLIC
        ${WIZFI360_DRIVER_DIR}/BufList/BufList.c
        ${WIZFI360_DRIVER_DIR}/BufList/LinkList.c
        ${WIZFI360_DRIVER_DIR}/WiFi_WizFi360.c
        ${WIZFI360_DRIVER_DIR}/WiFi_WizFi360_Os.c
        ${WIZFI360_DRIVER_DIR}/WizFi360.c
        ${WIZFI360_DRIVER_DIR}/WizFi360_Serial.c
        )

target_include_directories(WIZFI360_DRIVER_FILES PUBLIC
        ${CMSIS_5_DIR}/CMSIS/Core/Include
        ${CMSIS_5_DIR}/CMSIS/Driver/Include
        ${CMSIS_5_DIR}/CMSIS/RTOS2/Include
        ${WIZFI360_DRIVER_DIR}
        ${WIZFI360_DRIVER_DIR}/BufList
        ${FREERTOS_DIR}/include
        ${FREERTOS_DIR}/portable/GCC/ARM_CM0
        ${PORT_DIR}/FreeRTOS-Kernel/inc
        )

target_link_libraries(WIZFI360_DRIVER_FILES PRIVATE
        pico_stdlib
        cmsis_core
        CMSIS_FREERTOS_FILES
        FREERTOS_FILES
        WIZFI360_FILES
        )

# CMSIS FreeRTOS
add_library(CMSIS_FREERTOS_FILES STATIC)

target_sources(CMSIS_FREERTOS_FILES PUBLIC
        ${CMSIS_FREERTOS_DIR}/source/ARM/clib_arm.c
        ${CMSIS_FREERTOS_DIR}/source/cmsis_os2.c
        ${CMSIS_FREERTOS_DIR}/source/freertos_evr.c
        ${CMSIS_FREERTOS_DIR}/source/os_systick.c
        )

target_include_directories(CMSIS_FREERTOS_FILES PUBLIC
        ${PICO_SDK_PATH}/src/rp2_common/cmsis/stub/CMSIS/Core/Include
        ${PICO_SDK_PATH}/src/rp2_common/cmsis/stub/CMSIS/Device/RaspberryPi/RP2040/Include
        ${CMSIS_5_DIR}/CMSIS/Core/Include
        ${CMSIS_5_DIR}/CMSIS/RTOS2/Include
        ${CMSIS_FREERTOS_DIR}/include
        ${PORT_DIR}/FreeRTOS-Kernel/inc
        ${PORT_DIR}/RTE/inc
        )

target_link_libraries(CMSIS_FREERTOS_FILES PRIVATE
        pico_stdlib
        cmsis_core
        FREERTOS_FILES
        )

# FreeRTOS
add_library(FREERTOS_FILES STATIC)

target_sources(FREERTOS_FILES PUBLIC
        ${FREERTOS_DIR}/portable/GCC/ARM_CM0/port.c
        ${FREERTOS_DIR}/portable/MemMang/heap_4.c
        ${FREERTOS_DIR}/event_groups.c
        ${FREERTOS_DIR}/list.c
        ${FREERTOS_DIR}/queue.c
        ${FREERTOS_DIR}/stream_buffer.c
        ${FREERTOS_DIR}/tasks.c
        ${FREERTOS_DIR}/timers.c
        )

target_include_directories(FREERTOS_FILES PUBLIC
        ${PICO_SDK_PATH}/src/rp2_common/cmsis/stub/CMSIS/Device/RaspberryPi/RP2040/Include
        ${PICO_SDK_PATH}/src/rp2_common/cmsis/stub/CMSIS/Core/Include
        ${FREERTOS_DIR}/include
        ${FREERTOS_DIR}/portable/GCC/ARM_CM0
        ${PORT_DIR}/FreeRTOS-Kernel/inc
        ${PORT_DIR}/RTE/inc
        )

target_link_libraries(FREERTOS_FILES PRIVATE
        pico_stdlib
        cmsis_core
        CMSIS_FREERTOS_FILES
        )

# IoT Socket
add_library(IOT_SOCKET_FILES STATIC)

target_sources(IOT_SOCKET_FILES PUBLIC
        ${IOT_SOCKET_DIR}/source/wifi/iot_socket.c
        )

target_include_directories(IOT_SOCKET_FILES PUBLIC
        ${IOT_SOCKET_DIR}/include
        )

target_link_libraries(IOT_SOCKET_FILES PRIVATE
        pico_stdlib
        cmsis_core
        CMSIS_FREERTOS_FILES
        FREERTOS_FILES
        WIZFI360_FILES
        )
