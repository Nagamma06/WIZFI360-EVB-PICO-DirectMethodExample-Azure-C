#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"

#include "iothub.h"
#include "iothub_device_client_ll.h"
#include "iothub_client_options.h"
#include "iothub_message.h"
#include "iothub_client_version.h"
#include "azure_c_shared_utility/threadapi.h"
#include "azure_c_shared_utility/tickcounter.h"
#include "azure_c_shared_utility/crt_abstractions.h"
#include "azure_c_shared_utility/shared_util_options.h"
#include "azure_c_shared_utility/agenttime.h"
#include "azure_c_shared_utility/http_proxy_io.h"

#include "azure_samples.h"

/* This sample uses the _LL APIs of iothub_client for example purposes.
Simply changing the using the convenience layer (functions not having _LL)
and removing calls to _DoWork will yield the same results. */

// The protocol you wish to use should be uncommented
//
#define SAMPLE_MQTT
// #define SAMPLE_MQTT_OVER_WEBSOCKETS
// #define SAMPLE_AMQP
// #define SAMPLE_AMQP_OVER_WEBSOCKETS
// #define SAMPLE_HTTP

#ifdef SAMPLE_MQTT
#include "iothubtransportmqtt.h"
#endif // SAMPLE_MQTT
#ifdef SAMPLE_MQTT_OVER_WEBSOCKETS
#include "iothubtransportmqtt_websockets.h"
#endif // SAMPLE_MQTT_OVER_WEBSOCKETS
#ifdef SAMPLE_AMQP
#include "iothubtransportamqp.h"
#endif // SAMPLE_AMQP
#ifdef SAMPLE_AMQP_OVER_WEBSOCKETS
#include "iothubtransportamqp_websockets.h"
#endif // SAMPLE_AMQP_OVER_WEBSOCKETS
#ifdef SAMPLE_HTTP
#include "iothubtransporthttp.h"
#endif // SAMPLE_HTTP

#ifdef SET_TRUSTED_CERT_IN_SAMPLES
#include "certs.h"
#endif // SET_TRUSTED_CERT_IN_SAMPLES

/* Paste in the your iothub connection string  */
// static const char* connectionString = "[device connection string]";
static const char *connectionString = pico_az_connectionString;
#define PI_LED 25
#define MESSAGE_COUNT 5
static bool g_continueRunning = true;
static size_t g_message_count_send_confirmations = 0;

static int deviceMethodCallback(const char *method_name, const unsigned char *payload, size_t size, unsigned char **response, size_t *response_size, void *userContextCallback)
{
    (void)userContextCallback;
    (void)size;

    int result;

    gpio_init(PI_LED);
    gpio_set_dir(PI_LED, GPIO_OUT);
    char buff[10];
    int j = 0, count = 0;
    int len = strlen(payload);
    strcpy(buff, (char *)payload);

    while (count != 2)
    {
        if (buff[j] == '"')
            count++;
        buff[j] = buff[j];
        j++;
    }
    buff[j] = '\0';
    // strcpy(buff,(char *)payload);
    printf("String of buff %s\r\n", buff);
    char buff2[10] = "\"true\"";

    // User led on
    printf("\n==================================================================\n");
    printf("Device method %s arrived...\n", method_name);
    printf("payload is %s\r\n", payload);
    printf("buff len is %d buff2 len is %d\r\n", strlen(buff), strlen(buff2));

    if (strcmp("Thermostat-1Onoff", method_name) == 0)
    // if  (strcmp(buff2, buff) == 0)
    {
        printf("\nReceived device command request.\n");

        const char deviceMethodResponse[] = "\"OK\"";
        *response_size = sizeof(deviceMethodResponse) - 1;
        *response = malloc(*response_size);
        (void)memcpy(*response, deviceMethodResponse, *response_size);

        if (strcmp(buff2, buff) == 0)
        {
            printf("LED is ON\r\n");
            gpio_put(PI_LED, 1);
            // //gpio_put(PI_RESET_PIN, 1);
            // sleep_ms(1000);
        }
        else
        {
            printf("LED is OFF\r\n");
            gpio_put(PI_LED, 0);
            //     //sleep_ms(1000);
        }
        // gpio_put(PI_RESET_PIN, 0);

        // printf("Signal sent to Device\n");

        result = 200;
    }
    else
    {
        // All other entries are ignored.
        const char deviceMethodResponse[] = "{ \" Connection failed \" }";
        *response_size = sizeof(deviceMethodResponse) - 1;
        *response = malloc(*response_size);
        (void)memcpy(*response, deviceMethodResponse, *response_size);

        result = -1;
    }
    printf("==================================================================\n\n");

    return result;
}
static void connection_status_callback(IOTHUB_CLIENT_CONNECTION_STATUS result, IOTHUB_CLIENT_CONNECTION_STATUS_REASON reason, void *user_context)
{
    (void)reason;
    (void)user_context;
    // This sample DOES NOT take into consideration network outages.
    if (result == IOTHUB_CLIENT_CONNECTION_AUTHENTICATED)
    {
        (void)printf("The device client is connected to iothub\r\n");
    }
    else
    {
        (void)printf("The device client has been disconnected\r\n");
        g_continueRunning = false;
    }
}

void iothub_ll_c2d_method_invoke_sample(void)
{
    IOTHUB_CLIENT_TRANSPORT_PROVIDER protocol;
    size_t messages_count = 0;
    IOTHUB_MESSAGE_HANDLE message_handle;
    IOTHUB_DEVICE_CLIENT_LL_HANDLE device_ll_handle;

    size_t messages_sent = 0;
    float telemetry_temperature;
    float telemetry_humidity;
    char telemetry_msg_buffer[80];
    // Select the Protocol to use with the connection
#ifdef SAMPLE_MQTT
    protocol = MQTT_Protocol;
#endif // SAMPLE_MQTT
#ifdef SAMPLE_MQTT_OVER_WEBSOCKETS
    protocol = MQTT_WebSocket_Protocol;
#endif // SAMPLE_MQTT_OVER_WEBSOCKETS
#ifdef SAMPLE_AMQP
    protocol = AMQP_Protocol;
#endif // SAMPLE_AMQP
#ifdef SAMPLE_AMQP_OVER_WEBSOCKETS
    protocol = AMQP_Protocol_over_WebSocketsTls;
#endif // SAMPLE_AMQP_OVER_WEBSOCKETS
#ifdef SAMPLE_HTTP
    protocol = HTTP_Protocol;
#endif // SAMPLE_HTTP

    if (IoTHub_Init() != 0)
    {
        (void)printf("Failed to initialize the platform.\r\n");
    }
    else
    {
        (void)printf("Creating IoTHub Device handle\r\n");
        device_ll_handle = IoTHubDeviceClient_LL_CreateFromConnectionString(connectionString, protocol);
        if (device_ll_handle == NULL)
        {
            (void)printf("Failure creating IotHub device. Hint: Check your connection string.\r\n");
        }

        else
        {

            // Set any option that are neccessary.
            // For available options please see the iothub_sdk_options.md documentation
#if defined SAMPLE_MQTT || defined SAMPLE_MQTT_OVER_WEBSOCKETS
            // Setting the auto URL Encoder (recommended for MQTT). Please use this option unless
            // you are URL Encoding inputs yourself.
            // ONLY valid for use with MQTT
            bool urlEncodeOn = true;
            (void)IoTHubDeviceClient_LL_SetOption(device_ll_handle, OPTION_AUTO_URL_ENCODE_DECODE, &urlEncodeOn);
#endif
#ifdef SET_TRUSTED_CERT_IN_SAMPLES
            // Setting the Trusted Certificate.
            // This is only necessary on systems without built-in certificate stores.
            if (IoTHubDeviceClient_LL_SetOption(device_ll_handle, "TrustedCerts", certificates) != IOTHUB_CLIENT_OK)
            {
                (void)printf("failure to set option \"TrustedCerts\"\r\n");
            }
#endif // SET_TRUSTED_CERT_IN_SAMPLES
       // Setting connection status callback to get indication of connection to iothub
            if (IoTHubDeviceClient_LL_SetDeviceMethodCallback(device_ll_handle, deviceMethodCallback, &messages_count) != IOTHUB_CLIENT_OK)
            {
                (void)printf("ERROR: IoTHubClient_LL_SetMessageCallback..........FAILED!\r\n");
            }

            do
            {
                if (messages_count != 0)
                {
                    // if (status_flag == 1)
                    // {
                    static char msgText[1024];
                    sprintf(msgText, "{\"message\" : \"[ARHIS] device not operated\"}");
                    (void)printf("\r\nSending message to IoTHub\r\nMessage: %s\r\n", msgText);

                    IOTHUB_MESSAGE_HANDLE msg_handle = IoTHubMessage_CreateFromByteArray((const unsigned char *)msgText, strlen(msgText));
                    (void)IoTHubMessage_SetProperty(msg_handle, "display_message", "Hello, WizFi360-EVB-Pico!");

                    if (msg_handle == NULL)
                    {
                        (void)printf("ERROR: iotHubMessageHandle is NULL!\r\n");
                    }
                    else
                    {
                        if (IoTHubDeviceClient_LL_SendEventAsync(device_ll_handle, msg_handle, NULL, NULL) != IOTHUB_CLIENT_OK)
                        {
                            (void)printf("ERROR: IoTHubClient_LL_SendEventAsync..........FAILED!\r\n");
                        }
                        else
                        {
                            (void)printf("IoTHubClient_LL_SendEventAsync accepted message [%zu] for transmission to IoT Hub.\r\n", messages_count);
                        }
                        IoTHubMessage_Destroy(msg_handle);
                    }
                    //}
                }
                IoTHubDeviceClient_LL_DoWork(device_ll_handle);
                sleep_ms(500); // wait for
            } while (true);

            // Clean up the iothub sdk handle
            IoTHubDeviceClient_LL_Destroy(device_ll_handle);
        }
    }

    // Free all the sdk subsystem
    IoTHub_Deinit();
}
