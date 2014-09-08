#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <stdint.h>

int hw_address(char* interface, unsigned char* hw_address)
{
    struct ifreq s;
    strncpy(s.ifr_name, interface, sizeof(s.ifr_name));
    
    int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    if ( fd == -1 )
        return -1;

    if ( ioctl(fd, SIOCGIFHWADDR, &s) == -1 )
        return -1;

    int i;
    for ( i = 0; i < 6; i++ ) {
        hw_address[i] = s.ifr_addr.sa_data[i];
    }

    close(fd);

    return 0;
}

int main(int argc, char** argv) 
{
    if ( argc < 2 ) {
        printf("%s [ifname]\n", argv[0]);
        return 0;
    }

    unsigned char address[6];

    if ( hw_address(argv[1], address) == -1 ) {
        perror(argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
        (address[0]),
        (address[1]),
        (address[2]),
        (address[3]),
        (address[4]),
        (address[5]));
    return 0;
}
