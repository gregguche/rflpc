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
*/
#ifdef RFLPC_CONFIG_ENABLE_I2C

#include "i2c.h"
#include "../nxp/LPC17xx.h"
#include "../pinconf.h"
#include "../config.h"

typedef struct
{
    struct {
	unsigned char port:2;
	unsigned char sda_pin:5;
	unsigned char scl_pin:5;
	unsigned char pin_function:2;
    }gpio;      
    uint32_t *pclksel;
    unsigned char pclk_bit:5;
    unsigned char pconp_bit:5;
    LPC_I2C_TypeDef *conf_addr;
} rflpc_i2c_config_t;

static rflpc_i2c_config_t _config[3] = {
    { /* I2C0 */
	{RFLPC_I2C0_PORT, RFLPC_I2C0_SDA_PIN, RFLPC_I2C0_SCL_PIN, RFLPC_I2C0_PIN_FUNC}, /* gpio */
	&LPC_SC->PCLKSEL0,   	/* PCLKSEL register */
	14, 			/* pclk_bit */
	7,			/* pconp_bit */
	LPC_I2C0,   		/* conf_addr */
    },    
    { /* I2C1 */
	{RFLPC_I2C1_PORT, RFLPC_I2C1_SDA_PIN, RFLPC_I2C1_SCL_PIN, RFLPC_I2C1_PIN_FUNC}, /* gpio */
	&LPC_SC->PCLKSEL1,   	/* PCLKSEL register */
	6, 			/* pclk_bit */
	19,			/* pconp_bit */
	LPC_I2C1,   		/* conf_addr */
    },
    { /* I2C2 */
	{RFLPC_I2C2_PORT, RFLPC_I2C2_SDA_PIN, RFLPC_I2C2_SCL_PIN, RFLPC_I2C2_PIN_FUNC}, /* gpio */
	&LPC_SC->PCLKSEL1,   	/* PCLKSEL register */
	20, 			/* pclk_bit */
	26,			/* pconp_bit */
	LPC_I2C2,   		/* conf_addr */
    },    
};

void rflpc_i2c_init(rflpc_i2c_port_t port, rflpc_i2c_mode_t mode)
{
    
}

#endif
