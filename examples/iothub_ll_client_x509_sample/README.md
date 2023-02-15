# How to Test iothub_ll_client_x509_sample



## Step 1: Prepare software

The following serial terminal program, graphical tool for interacting with devices connected to your Azure IoT and certificate generation tool are required for iothub_ll_client_x509_sample test, download and install from below link.

- [**Tera Term**][link-tera_term]
- [**Azure IoT Explorer**][link-azure_iot_explorer]
- [**OpenSSL**][link-openssl]



## Step 2: Prepare hardware

1. Connect WizFi360-EVB-Pico to desktop or laptop using 5 pin micro USB cable.



## Step 3: Create certificate and key

Since self-signed certificates in X.509 format are required, create self-signed certificates in X.509 format using OpenSSL downloaded and installed in advance by referring to the document below.

- [**Using OpenSSL to create self-signed certificates**][link-using_openssl_to_create_self-signed_certificates]



## Step 4: Setup Azure IoT

Configure Azure IoT in the Azure Portal.

As Azure IoT, Azure IoT Hub is used.

To setup Azure IoT Hub and create a device in Azure IoT Hub, refer to the documents below.

- [**Create an IoT hub**][link-create_an_iot_hub]
- [**Register a new device in the IoT hub**][link-register_a_new_device_in_the_iot_hub]



## Step 5: Setup iothub_ll_client_x509_sample

To test the iothub_ll_client_x509_sample, minor settings shall be done in code.

1. Setup Wi-Fi configuration in 'socket_startup.c' in 'WizFi360-EVB-Pico-AZURE-C/examples/' directory.

Setup the Wi-Fi network information you use.

```cpp
/* Wi-Fi configuration */
#define SSID "ssid"
#define PASSWORD "password"
#define SECURITY_TYPE ARM_WIFI_SECURITY_WPA2
```

For iothub_ll_client_x509_sample, uncomment APP_CLI_X509 and comment the rest of the defined sample application macros.

```cpp
// The application you wish to use should be uncommented
//
//#define APP_TELEMETRY
//#define APP_C2D
#define APP_CLI_X509
//#define APP_PROV_X509
```

3. Setup device connection string, certificate and key.

Enter the connection string, client certificate and private key.

For the connection string, refer to the following, and the client certificate and private key created in Step 3 and registered when creating the device in Step 4.

```bash
/* Connection string */
HostName=[host name];DeviceId=[device id];x509=true

// e.g.
HostName=my-rp2040-hub.azure-devices.net;DeviceId=my-rp2040-device-cli-x509;x509=true
```

Connection string, client certificate and private key can be set in 'sample_certs.c' in 'WizFi360-EVB-Pico-AZURE-C/examples/' directory.

```cpp
const char pico_az_x509connectionString[] = "[device connection string]";

const char pico_az_x509certificate[] =
"-----BEGIN CERTIFICATE-----""\n"
"-----END CERTIFICATE-----";

const char pico_az_x509privatekey[] =
"-----BEGIN PRIVATE KEY-----""\n"
"-----END PRIVATE KEY-----";
```



## Step 6: Build and Upload

1. After completing the configuration, click 'build' in the status bar at the bottom of Visual Studio Code or press the 'F7' button on the keyboard to build.

2. When the build is completed, 'azure_mqtt_demo.uf2' is generated in 'WizFi360-EVB-Pico-AZURE-C/build/examples/' directory.

3. While pressing the BOOTSEL button of WizFi360-EVB-Pico power on the board, the USB mass storage 'RPI-RP2' is automatically mounted.

![][link-raspberry_pi_pico_usb_mass_storage]

4. Drag and drop 'azure_mqtt_demo.uf2' onto the USB mass storage device 'RPI-RP2'.

5. Connect to the serial COM port of WizFi360-EVB-Pico with Tera Term.

![][link-connect_to_serial_com_port]



## Step 7: Run

1. Reset your board.

2. If the iothub_ll_client_x509_sample works normally on WizFi360-EVB-Pico, you can see the Wi-Fi connection log, connecting to the Azure IoT Hub and sending the message.



<!--
Link
-->

[link-tera_term]: https://osdn.net/projects/ttssh2/releases/
[link-azure_iot_explorer]: https://github.com/Azure/azure-iot-explorer/releases
[link-openssl]: https://www.openssl.org/source/
[link-using_openssl_to_create_self-signed_certificates]: https://docs.microsoft.com/en-us/azure/iot-hub/tutorial-x509-self-sign
[link-create_an_iot_hub]: https://docs.microsoft.com/en-us/azure/iot-hub/iot-hub-create-through-portal#create-an-iot-hub
[link-register_a_new_device_in_the_iot_hub]: https://docs.microsoft.com/en-us/azure/iot-hub/iot-hub-create-through-portal#register-a-new-device-in-the-iot-hub
[link-raspberry_pi_pico_usb_mass_storage]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/blob/main/static/images/iothub_ll_client_x509_sample/raspberry_pi_pico_usb_mass_storage.png
[link-connect_to_serial_com_port]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/blob/main/static/images/iothub_ll_client_x509_sample/connect_to_serial_com_port.png
