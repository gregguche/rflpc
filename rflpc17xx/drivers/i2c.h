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
 * I2C Device driver
 */
#ifndef __RFLPC_I2C_H__
#define __RFLPC_I2C_H__
/*
  Author: Michael Hauspie <michael.hauspie@univ-lille1.fr>  
*/

#ifdef RFLPC_CONFIG_ENABLE_I2C

/** @addtogroup i2c I2C
 * @ingroup drivers
 * @{
 */

/** These constants selects which port the driver functions manipulate. */
typedef enum
{
    RFLPC_I2C_PORT0,
    RFLPC_I2C_PORT1,
    RFLPC_I2C_PORT2,
} rflpc_i2c_port_t;

/** Defines the operating mode of the I2C bus. */
typedef enum
{
    RFLPC_I2C_MODE_MASTER,
    RFLPC_I2C_MODE_SLAVE,
} rflpc_i2c_mode_t;

/** Inits a given I2C port on a given mode.
 * @param port the port to initialize (cf ::rflpc_i2c_port_t)
 * @param mode the mode to use (cd ::rflpc_i2c_mode_t)
 */
void rflpc_i2c_init(rflpc_i2c_port_t port, rflpc_i2c_mode_t mode);

/** @} */

#endif /* ENABLE_SPI */
#endif
