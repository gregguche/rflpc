#ifndef __DHCP_PACKET_H__
#define __DHCP_PACKET_H__

#include <stdint.h>

#define DHCPDISCOVER 1     
#define DHCPOFFER    2     
#define DHCPREQUEST  3    
#define DHCPDECLINE  4     
#define DHCPACK      5     
#define DHCPNAK      6     
#define DHCPRELEASE  7     
#define DHCPINFORM   8     
#define DHCP_SERVER_PORT 67
#define DHCP_CLIENT_PORT 68

#define BOOTREQUEST 1

#define DHCP_MESSAGE_TYPE 53
#define DHCP_END_OPTIONS 0xff

typedef struct dhcp_message {
  /* Each line corresponds to the RFC 2131 spec page 8 */
  uint8_t op, htype, hlen, hops;
  uint8_t xid[4];
  uint8_t secs[2], flags[2];
  uint8_t ciaddr[4];
  uint8_t yiaddr[4];
  uint8_t siaddr[4];
  uint8_t giaddr[4];
  uint8_t chaddr[16];
  uint8_t sname[64];
  uint8_t file[128];
  uint8_t options[64];
} DhcpHead;

#define DHCP_HLEN 300


extern void proto_dhcp_demangle(DhcpHead *dh, const uint8_t *data);
extern void proto_dhcp_mangle(DhcpHead *dh, uint8_t *data);


#endif /* __DHCP_PACKET_H__ */
