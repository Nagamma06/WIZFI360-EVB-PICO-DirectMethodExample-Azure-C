# How to Test iothub_ll_telemetry_sample



## Step 1: Prepare software

The following serial terminal program and graphical tool for interacting with devices connected to your Azure IoT are required for iothub_ll_telemetry_sample test, download and install from below link.

- [**Tera Term**][link-tera_term]
- [**Azure IoT Explorer**][link-azure_iot_explorer]



## Step 2: Prepare hardware

1. Connect WizFi360-EVB-Pico to desktop or laptop using 5 pin micro USB cable.



## Step 3: Setup Azure IoT

Configure Azure IoT in the Azure Portal.

As Azure IoT, Azure IoT hub is used.

Refer to the guide documents below to setup Azure IoT Hub and create a device in Azure IoT Hub.

- [**Create an IoT hub**][link-create_an_iot_hub]
- [**Register a new device in the IoT hub**][link-register_a_new_device_in_the_iot_hub]



## Step 4: Setup iothub_ll_telemetry_sample

To test the iothub_ll_telemetry_sample, minor settings shall be done in code.

1. Setup Wi-Fi configuration in 'socket_startup.c' in 'WizFi360-EVB-Pico-AZURE-C/examples/' directory.

Setup the Wi-Fi network information you use.

```cpp
/* Wi-Fi configuration */
#define SSID "ssid"
#define PASSWORD "password"
#define SECURITY_TYPE ARM_WIFI_SECURITY_WPA2
```

2. Select sample application

For iothub_ll_telemetry_sample, uncomment APP_TELEMETRY and comment the rest of the defined sample application macros.

```cpp
// The application you wish to use should be uncommented
//
#define APP_TELEMETRY
//#define APP_C2D
//#define APP_CLI_X509
//#define APP_PROV_X509

```

3. Setup device connection string.

Enter the connection string of the device you created in Step 3.

![][link-device_connection_string_in_azure_iot_hub]

Connection string can be set in 'sample_certs.c' in 'WizFi360-EVB-Pico-AZURE-C/examples/' directory.

```cpp
const char pico_az_connectionString[] = "[device connection string]";
```



## Step 5: Build and Upload

1. After completing the configuration, click 'build' in the status bar at the bottom of Visual Studio Code or press the 'F7' button on the keyboard to build.

2. When the build is completed, 'azure_mqtt_demo.uf2' is generated in 'WizFi360-EVB-Pico-AZURE-C/build/examples/' directory.

3. While pressing the BOOTSEL button of WizFi360-EVB-Pico power on the board, the USB mass storage 'RPI-RP2' is automatically mounted.

![][link-raspberry_pi_pico_usb_mass_storage]

4. Drag and drop 'azure_mqtt_demo.uf2' onto the USB mass storage device 'RPI-RP2'.

5. Connect to the serial COM port of WizFi360-EVB-Pico with Tera Term.

![][link-connect_to_serial_com_port]



## Step 6: Run

1. Reset your board.

2. If the iothub_ll_telemetry_sample works normally on WizFi360-EVB-Pico, you can see the Wi-Fi connection log, connecting to the Azure IoT Hub and sending the message.



<!--
Link
-->

[link-tera_term]: https://osdn.net/projects/ttssh2/releases/
[link-azure_iot_explorer]: https://github.com/Azure/azure-iot-explorer/releases
[link-create_an_iot_hub]: https://docs.microsoft.com/en-us/azure/iot-hub/iot-hub-create-through-portal#create-an-iot-hub
[link-register_a_new_device_in_the_iot_hub]: https://docs.microsoft.com/en-us/azure/iot-hub/iot-hub-create-through-portal#register-a-new-device-in-the-iot-hub
[link-device_connection_string_in_azure_iot_hub]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/blob/main/static/images/iothub_ll_telemetry_sample/device_connection_string_in_azure_iot_hub.png
[link-raspberry_pi_pico_usb_mass_storage]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/blob/main/static/images/iothub_ll_telemetry_sample/raspberry_pi_pico_usb_mass_storage.png
[link-connect_to_serial_com_port]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/blob/main/static/images/iothub_ll_telemetry_sample/connect_to_serial_com_port.png
