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
#include "../clock.h"

typedef struct
{
    struct {
	unsigned char port:2;
	unsigned char sda_pin:5;
	unsigned char scl_pin:5;
	unsigned char pin_function:2;
    }gpio;      
    uint32_t volatile *pclksel;
    unsigned char pclk_bit:5;
    unsigned char pconp_bit:5;
    LPC_I2C_TypeDef *conf_addr;
} rflpc_i2c_config_t;

static const rflpc_i2c_config_t _config[3] = {
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

int rflpc_i2c_init(rflpc_i2c_port_t port)
{
    const rflpc_i2c_config_t *i2c = &_config[port];
    if (rflpc_clock_get_system_clock() != 96000000)
	return -1;
    /* Power the port */
    LPC_SC->PCONP |= (1UL << i2c->pconp_bit);
    /* Select the desired clock */
    /* To operate at 100kHz, we set the I2C peripheral clock to 12Mhz,
     * and then the sum I2CSCLL+I2CSCLH to 120 */
    
    /* Set peripheral clock to 12 Mhz (96/8) */
    *(i2c->pclksel) &= ~(RFLPC_CCLK_8 << i2c->pclk_bit);
    *(i2c->pclksel) |= (RFLPC_CCLK_8 << i2c->pclk_bit);

    /* 60 + 60 = 120 */
    i2c->conf_addr->I2SCLL = 60;
    i2c->conf_addr->I2SCLH = 60;
    
    /* Select appropriate pins. Documentation says that the pins should configured with neither pull-up nor pull-down and in opendrain */
    /* SDA */
    rflpc_pin_set(i2c->gpio.port, i2c->gpio.sda_pin, i2c->gpio.pin_function, RFLPC_PIN_MODE_RESISTOR_NONE, 1);
    /* SCL */
    rflpc_pin_set(i2c->gpio.port, i2c->gpio.scl_pin, i2c->gpio.pin_function, RFLPC_PIN_MODE_RESISTOR_NONE, 1);
    
    return 0;
}

#endif
