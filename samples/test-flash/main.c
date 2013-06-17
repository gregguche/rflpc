/* This file is part of rflpc. Copyright 2010-2011 Michael Hauspie
 *
 * rflpc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rflpc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with rflpc.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
  Author: Michael Hauspie <michael.hauspie@univ-lille1.fr>
  Created:
  Time-stamp: <2012-03-21 09:40:41 (hauspie)>
*/
#include <rflpc17xx/rflpc17xx.h>

#define DATA_SIZE            256
#define SECTOR_START_INDEX   22
#define SECTOR_END_INDEX     22
#define SECTOR_START_ADDRESS 0x00040000


static char data[DATA_SIZE];

int main()
{
    int i, count;

    rflpc_clock_init();
    rflpc_uart_init(RFLPC_UART0);

    printf("RAM to Flash Test started\r\n");

    count = DATA_SIZE;
    for(i = 0; i < count; i++)
      data[i] = i % 256;

    rflpc_iap_prepare_sectors_for_writing(SECTOR_START_INDEX, SECTOR_END_INDEX);
    rflpc_iap_copy_ram_to_flash((void *)SECTOR_START_ADDRESS, data, DATA_SIZE);

    count = SECTOR_START_ADDRESS + DATA_SIZE;
    for(i = SECTOR_START_ADDRESS; i < count; i++) {
	printf("Checking 0x%x\r\n", i);
	if(*((char *)i) != ((i -SECTOR_START_ADDRESS) % 256)) {
            printf("Test Failed at %d\r\n", (i -SECTOR_START_ADDRESS));
            return -1;
        }
    }

    printf("RAM to Flash Test done successfully\r\n");

    while (1);
    return 0;
}