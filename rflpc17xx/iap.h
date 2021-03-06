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
/** @file
 * In-Application programming functions 
 * This file defines functions to acces the flash memory interface
 */

/** @defgroup iap Flash memory In-Application Programming (IAP)
 * @ingroup system
 * @{
 */
/*
  Author: Michael Hauspie <michael.hauspie@univ-lille1.fr>
  Created: 2012-03-28
*/
#ifndef __RFLPC_IAP_H__
#define __RFLPC_IAP_H__



#ifdef RFLPC_CONFIG_ENABLE_IAP

/** Gets the flash serial number.
 * This can be used to uniquely identify the LPC17xx running the program.
 * @param [out] result the serial number as four 32 bits word 
 * @return 0 if successful, -1 otherwise
 */
extern int rflpc_iap_get_serial_number(unsigned long result[4]);

/** @} */
#endif /* ENABLE_IAP */

#endif