# Getting Started with WizFi360 Azure IoT Examples

These sections will guide you through a series of steps from configuring development environment to running WizFi360 Azure IoT examples using the **WIZnet's Wi-Fi products**.

- [**Development environment configuration**](#development_environment_configuration)
- [**Hardware requirements**](#hardware_requirements)
- [**WizFi360 Azure IoT example structure**](#wizfi360_azure_iot_example_structure)
- [**WizFi360 Azure IoT example testing**](#wizfi360_azure_iot_example_testing)



<a name="development_environment_configuration"></a>
## Development environment configuration

To test the WizFi360 Azure IoT examples, the development environment must be configured to use WizFi360-EVB-Pico.

The WizFi360 Azure IoT examples were tested by configuring the development environment for **Windows**. Please refer to the '**9.2. Building on MS Windows**' section of '**Getting started with Raspberry Pi Pico**' document below and configure accordingly.

- [**Getting started with Raspberry Pi Pico**][link-getting_started_with_raspberry_pi_pico]

**Visual Studio Code** was used during development and testing of WizFi360 Azure IoT examples, the guide document in each directory was prepared also base on development with Visual Studio Code. Please refer to corresponding document.



<a name="hardware_requirements"></a>
## Hardware requirements

The WizFi360 Azure IoT examples use **WizFi360-EVB-Pico** - Wi-Fi I/O module built on [**RP2040**][link-rp2040] and WIZnet's [**WizFi360**][link-wizfi360] Wi-Fi module.

- [**WizFi360-EVB-Pico**][link-wizfi360-evb-pico]

![][link-wizfi360-evb-pico_main]



<a name="wizfi360_azure_iot_example_structure"></a>
## WizFi360 Azure IoT example structure

Examples are available at '**WizFi360-EVB-Pico-AZURE-C/examples/**' directory. As of now, following examples are provided.

- [**iothub_ll_telemetry_sample**][link-iothub_ll_telemetry_sample]
- [**iothub_ll_c2d_sample**][link-iothub_ll_c2d_sample]
- [**iothub_ll_client_x509_sample**][link-iothub_ll_client_x509_sample]
- [**prov_dev_client_ll_sample**][link-prov_dev_client_ll_sample]

Note that **CMSIS_5**, **CMSIS-Driver**, **CMSIS-FreeRTOS**, **mbedtls**, **azure-iot-sdk-c**, **pico-sdk** are needed to run WizFi360 Azure IoT examples.

- **CMSIS_5** is a set of tools, APIs, frameworks, and work flows that help to simplify software re-use, reduce the learning curve for microcontroller developers, speed-up project build and debug, and thus reduce the time to market for new applications.
- **CMSIS-Driver** contains MCU independent device driver implementations and template files.
- **CMSIS-FreeRTOS** is a common API for embedded microcontroller real-time operating system FreeRTOS.
- **IoT_Socket** contains the code of IoT Socket - a simple BSD like IP socket interface that implements the glue logic between IoT cloud connectors (IoT clients) and the underlying communication stack.
- **mbedtls** library supports additional algorithms and support related to TLS and SSL connections.
- **azure-iot-sdk-c** allows applications written in C99 or later or C++ to communicate easily with Azure IoT Hub, Azure IoT Central and to Azure IoT Device Provisioning. This library includes the source code, setup instructions, and samples demonstrating use scenarios.
- **pico-sdk** is made available by Pico to enable developers to build software applications for the Pico platform.
- **pico-extras** has additional libraries that are not yet ready for inclusion the Pico SDK proper, or are just useful but don't necessarily belong in the Pico SDK.

Libraries are located in the '**WizFi360-EVB-Pico-AZURE-C/libraries/**' directory.

- [**CMSIS_5**][link-cmsis_5]
- [**CMSIS-Driver**][link-cmsis-driver]
- [**CMSIS-FreeRTOS**][link-cmsis-freertos]
- [**IoT_Socket**][link-iot_socket]
- [**mbedtls**][link-mbedtls]
- [**azure-iot-sdk-c**][link-azure-iot-sdk-c]
- [**pico-sdk**][link-pico-sdk]
- [**pico-extras**][link-pico-extras]

If you want to modify the code that MCU-dependent and use a MCU other than **RP2040**, you can modify it in the **WizFi360-EVB-Pico-AZURE-C/port/** directory.

- [**FreeRTOS-Kernel**][link-port_freertos-kernel]
- [**RTE**][link-port_rte]
- [**WizFi360**][link-port_wizfi360]
- [**mbedtls**][link-port_mbedtls]
- [**azure-iot-sdk-c**][link-port_azure-iot-sdk-c]
- [**timer**][link-port_timer]



<a name="wizfi360_azure_iot_example_testing"></a>
## WizFi360 Azure IoT example testing

1. Download

If the WizFi360 Azure IoT examples are cloned, the library set as a submodule is an empty directory. Therefore, if you want to download the library set as a submodule together, clone the WizFi360 Azure IoT examples with the following Git command.

```bash
/* Change directory */
// change to the directory to clone
cd [user path]

// e.g.
cd D:/RP2040

/* Clone */
git clone --recurse-submodules https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C.git
```

With Visual Studio Code, the library set as a submodule is automatically downloaded, so it doesn't matter whether the library set as a submodule is an empty directory or not, so refer to it.

2. Patch

With Visual Studio Code, each library set as a submodule is automatically patched, but if you do not use Visual Studio Code, each library set as a submodule must be manually patched with the Git commands below in each library directory.

- CMSIS-FreeRTOS

```bash
/* Change directory */
// change to the 'CMSIS-FreeRTOS' library directory
cd [user path]/RP2040-HAT-C/libraries/CMSIS-FreeRTOS

// e.g.
cd D:/RP2040/WizFi360-EVB-Pico-AZURE-C/libraries/CMSIS-FreeRTOS/CMSIS/RTOS2/FreeRTOS/Source

/* Patch */
git apply ../../../../../../patches/01_cmsis_freertos_cmsis_os2.patch
```

3. Test

Please refer to 'README.md' in each example directory to find detail guide for testing WizFi360 Azure IoT examples.



<!--
Link
-->

[link-getting_started_with_raspberry_pi_pico]: https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf
[link-rp2040]: https://www.raspberrypi.org/products/rp2040/
[link-wizfi360]: https://docs.wiznet.io/Product/Wi-Fi-Module/WizFi360/wizfi360
[link-wizfi360-evb-pico]: https://docs.wiznet.io/Product/Open-Source-Hardware/wizfi360-evb-pico
[link-wizfi360-evb-pico_main]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/blob/main/static/images/getting_started/wizfi360-evb-pico_main.png
[link-iothub_ll_telemetry_sample]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/tree/main/examples/iothub_ll_telemetry_sample
[link-iothub_ll_c2d_sample]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/tree/main/examples/iothub_ll_c2d_sample
[link-iothub_ll_client_x509_sample]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/tree/main/examples/iothub_ll_client_x509_sample
[link-prov_dev_client_ll_sample]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/tree/main/examples/prov_dev_client_ll_sample
[link-cmsis_5]: https://github.com/ARM-software/CMSIS_5
[link-cmsis-driver]: https://github.com/ARM-software/CMSIS-Driver
[link-cmsis-freertos]: https://github.com/ARM-software/CMSIS-FreeRTOS
[link-iot_socket]: https://github.com/MDK-Packs/IoT_Socket
[link-mbedtls]: https://github.com/ARMmbed/mbedtls
[link-azure-iot-sdk-c]: https://github.com/Azure/azure-iot-sdk-c
[link-pico-sdk]: https://github.com/raspberrypi/pico-sdk
[link-pico-extras]: https://github.com/raspberrypi/pico-extras
[link-port_freertos-kernel]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/tree/main/port/FreeRTOS-Kernel
[link-port_rte]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/tree/main/port/RTE
[link-port_wizfi360]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/tree/main/port/WizFi360
[link-port_mbedtls]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/tree/main/port/mbedtls
[link-port_azure-iot-sdk-c]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/tree/main/port/azure-iot-sdk-c
[link-port_timer]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/tree/main/port/timer
