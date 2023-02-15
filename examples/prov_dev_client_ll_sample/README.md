# How to Test prov_dev_client_ll_sample



## Step 1: Prepare software

The following serial terminal program, graphical tool for interacting with devices connected to your Azure IoT and certificate generation tool are required for prov_dev_client_ll_sample test, download and install from below link.

- [**Tera Term**][link-tera_term]
- [**Azure IoT Explorer**][link-azure_iot_explorer]
- [**OpenSSL**][link-openssl]



## Step 2: Prepare hardware

1. Connect WizFi360-EVB-Pico to desktop or laptop using 5 pin micro USB cable.



## Step 3: Create certificate and key

Since self-signed certificates in X.509 format are required, create self-signed certificates in X.509 format using OpenSSL downloaded and installed in advance by referring to the document below.

- [**Using OpenSSL to create self-signed certificates**][link-using_openssl_to_create_self-signed_certificates]

If you created the  self-signed certificate in X.509 format, you need to run the following command in the last step to create a .pem file

```bash
openssl x509 -in [crt name].crt -out [pem name].pem -outform PEM

// e.g.
openssl x509 -in prov_device1.crt -out prov_device1.pem -outform PEM
```



## Step 4: Setup Azure IoT and Device Provisioning Service

Configure Azure IoT and Device Provisioning Service in the Azure Portal.

As Azure IoT, Azure IoT Hub is used.

Refer to the guide documents below to setup Azure IoT Hub and create a device in Azure IoT Hub.

- [**Create an IoT hub**][link-create_an_iot_hub]
- [**Register a new device in the IoT hub**][link-register_a_new_device_in_the_iot_hub]

And as Device Provisioning Service, Azure IoT Hub Device Provisioning Service is used.

Refer to the guide documents below to setup Azure IoT Hub Device Provisioning Service.

- [**Create a new IoT Hub Device Provisioning Service**][link-create_a_new_iot_hub_device_provisioning_service]
- [**Create an enrollment group**][link-create_an_enrollment_group]



## Step 5: Setup prov_dev_client_ll_sample

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

For prov_dev_client_ll_sample, uncomment APP_PROV_X509 and comment the rest of the defined sample application macros.

```cpp
// The application you wish to use should be uncommented
//
//#define APP_TELEMETRY
//#define APP_C2D
//#define APP_CLI_X509
#define APP_PROV_X509
```

3. Setup device ID scope, device ID, certificate and key.

Enter the ID scope, device ID, client certificate and private key.

For ID scope, you can find it in the Azure IoT Hub Device Provisioning Service in the Azure Portal created in Step 4.

![][link-id_scope]

And the device ID, client certificate and private key created in Step 3 and registered when creating the device in Step 4.

ID scope, device ID, client certificate and private key can be set in 'sample_certs.c' in 'WizFi360-EVB-Pico-AZURE-C/examples/' directory.

```cpp
const char pico_az_id_scope[] = "[ID Scope]";

const char pico_az_COMMON_NAME[] = "[custom-hsm-device]";

const char pico_az_CERTIFICATE[] =
"-----BEGIN CERTIFICATE-----""\n"
"-----END CERTIFICATE-----";

const char pico_az_PRIVATE_KEY[] =
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

2. If the prov_dev_client_ll_sample works normally on WizFi360-EVB-Pico, you can see the Wi-Fi connection log and  process of registering the device to Azure IoT Hub through provisioning.

3. After registering the device to Azure IoT Hub through provisioning, you can see the sending the message to Azure IoT Hub.



<!--
Link
-->

[link-tera_term]: https://osdn.net/projects/ttssh2/releases/
[link-azure_iot_explorer]: https://github.com/Azure/azure-iot-explorer/releases
[link-openssl]: https://www.openssl.org/source/
[link-using_openssl_to_create_self-signed_certificates]: https://docs.microsoft.com/en-us/azure/iot-hub/tutorial-x509-self-sign
[link-create_an_iot_hub]: https://docs.microsoft.com/en-us/azure/iot-hub/iot-hub-create-through-portal#create-an-iot-hub
[link-register_a_new_device_in_the_iot_hub]: https://docs.microsoft.com/en-us/azure/iot-hub/iot-hub-create-through-portal#register-a-new-device-in-the-iot-hub
[link-create_a_new_iot_hub_device_provisioning_service]: https://docs.microsoft.com/en-us/azure/iot-dps/quick-setup-auto-provision#create-a-new-iot-hub-device-provisioning-service
[link-create_an_enrollment_group]: https://docs.microsoft.com/en-us/azure/iot-dps/tutorial-custom-hsm-enrollment-group-x509#create-an-enrollment-group
[link-id_scope]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/blob/main/static/images/prov_dev_client_ll_sample/id_scope.png
[link-raspberry_pi_pico_usb_mass_storage]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/blob/main/static/images/prov_dev_client_ll_sample/raspberry_pi_pico_usb_mass_storage.png
[link-connect_to_serial_com_port]: https://github.com/Wiznet/WizFi360-EVB-Pico-AZURE-C/blob/main/static/images/prov_dev_client_ll_sample/connect_to_serial_com_port.png
