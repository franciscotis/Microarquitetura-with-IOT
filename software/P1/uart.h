#ifndef UART_H_
#define UART_H_


#define WIFI_MODE "AT+CWMODE=3"
#define WIFI_CONNECT "AT+CWJAP=\"SSID\",\"PASSWORD\""

#define TCP_CONNECT "AT+CIPSTART=\"TCP\",\"IP\",PORT"
#define TCP_DISCONNECT "AT+CIPCLOSE"

#define MQTT_CONNECT_SIZE "AT+CIPSEND=20"
#define MQTT_CONNECT "\x10\x12\x00\x04\aMQTT\x04\x02\x00\x14\x00\x06\aNios 2"

#define MESSAGE_SIZE "AT+CIPSEND=21"
#define MESSAGE_0 "\x30\x13\x00\x06\aPBL 02Mensagem 01"
#define MESSAGE_1 "\x30\x13\x00\x06\aPBL 02Mensagem 02"
#define MESSAGE_2 "\x30\x13\x00\x06\aPBL 02Mensagem 03"
#define MESSAGE_3 "\x30\x13\x00\x06\aPBL 02Mensagem 04"
#define MESSAGE_4 "\x30\x13\x00\x06\aPBL 02Mensagem 05"

#define MQTT_DISCONNECT_SIZE "AT+CIPSEND=2"
#define MQTT_DISCONNECT "\xe0\x00"

void uart_send(char *data);

#endif
