/****************************************************************************
*  Copyright (c) 2012 by Michael Blandford. All rights reserved.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
*
****************************************************************************/

#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#ifdef PCBSKY
#include "AT91SAM3S4.h"
#endif

#ifdef PCBX9D
#include "x9d\stm32f2xx.h"
#include "x9d\stm32f2xx_gpio.h"
#include "x9d\hal.h"
#endif


#ifndef SIMU
#include "core_cm3.h"
#endif

#include "ersky9x.h"
#include "drivers.h"
#include "logicio.h"

#ifdef PCBSKY
#include "lcd.h"
#endif

#ifndef SIMU
#ifdef PCBSKY
void configure_pins( uint32_t pins, uint16_t config )
{
	register Pio *pioptr ;
	
	pioptr = PIOA + ( ( config & PIN_PORT_MASK ) >> 6) ;
	if ( config & PIN_PULLUP )
	{
		pioptr->PIO_PPDDR = pins ;
		pioptr->PIO_PUER = pins ;
	}
	else
	{
		pioptr->PIO_PUDR = pins ;
	}

	if ( config & PIN_PULLDOWN )
	{
		pioptr->PIO_PUDR = pins ;
		pioptr->PIO_PPDER = pins ;
	}
	else
	{
		pioptr->PIO_PPDDR = pins ;
	}

	if ( config & PIN_HIGH )
	{
		pioptr->PIO_SODR = pins ;		
	}
	else
	{
		pioptr->PIO_CODR = pins ;		
	}

	if ( config & PIN_INPUT )
	{
		pioptr->PIO_ODR = pins ;
	}
	else
	{
		pioptr->PIO_OER = pins ;
	}

	if ( config & PIN_PERI_MASK_L )
	{
		pioptr->PIO_ABCDSR[0] |= pins ;
	}
	else
	{
		pioptr->PIO_ABCDSR[0] &= ~pins ;
	}
	if ( config & PIN_PERI_MASK_H )
	{
		pioptr->PIO_ABCDSR[1] |= pins ;
	}
	else
	{
		pioptr->PIO_ABCDSR[1] &= ~pins ;
	}

	if ( config & PIN_ENABLE )
	{
		pioptr->PIO_PER = pins ;		
	}
	else
	{
		pioptr->PIO_PDR = pins ;		
	}
}
#endif

#ifdef PCBX9D
void configure_pins( uint32_t pins, uint16_t config )
{
	uint32_t address ;
	GPIO_TypeDef *pgpio ;
	uint32_t thispin ;
  uint32_t pos ;

	address = ( config & PIN_PORT_MASK ) >> 8 ;
	address *= (GPIOB_BASE-GPIOA_BASE) ;
	address += GPIOA_BASE ;
	pgpio = (GPIO_TypeDef* ) address ;
	
  /* -------------------------Configure the port pins---------------- */
  /*-- GPIO Mode Configuration --*/
  for (thispin = 0x0001, pos = 0; thispin < 0x10000; thispin <<= 1, pos +=1 )
  {
    if ( pins & thispin)
    {
      pgpio->MODER  &= ~(GPIO_MODER_MODER0 << (pos * 2)) ;
      pgpio->MODER |= (config & PIN_MODE_MASK) << (pos * 2) ;

      if ( ( (config & PIN_MODE_MASK ) == PIN_OUTPUT) || ( (config & PIN_MODE_MASK) == PIN_PERIPHERAL) )
      {
        /* Speed mode configuration */
        pgpio->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR0 << (pos * 2) ;
        pgpio->OSPEEDR |= ((config & PIN_SPEED_MASK) >> 13 ) << (pos * 2) ;

        /* Output mode configuration*/
        pgpio->OTYPER  &= ~((GPIO_OTYPER_OT_0) << ((uint16_t)pos)) ;
				if ( config & PIN_ODRAIN )
				{
        	pgpio->OTYPER |= (GPIO_OTYPER_OT_0) << pos ;
				}
      }
      /* Pull-up Pull down resistor configuration*/
      pgpio->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << ((uint16_t)pos * 2));
      pgpio->PUPDR |= ((config & PIN_PULL_MASK) >> 2) << (pos * 2) ;

			pgpio->AFR[pos >> 3] &= ~(0x000F << ((pos & 7)*4)) ;
			pgpio->AFR[pos >> 3] |=	((config & PIN_PERI_MASK) >> 4) << ((pos & 7)*4) ;
    }
  }
}
		
#endif


#endif

#ifdef PCBSKY
	
void init_keys()
{
	register Pio *pioptr ;
	
	pioptr = PIOC ;
	// Next section configures the key inputs on the LCD data
#ifdef REVB	
	pioptr->PIO_PER = 0x0000003BL ;		// Enable bits 1,3,4,5, 0
	pioptr->PIO_OER = PIO_PC0 ;		// Set bit 0 output
	pioptr->PIO_ODR = 0x0000003AL ;		// Set bits 1, 3, 4, 5 input
	pioptr->PIO_PUER = 0x0000003AL ;		// Set bits 1, 3, 4, 5 with pullups
#else	
	pioptr->PIO_PER = 0x0000003DL ;		// Enable bits 2,3,4,5, 0
	pioptr->PIO_OER = PIO_PC0 ;		// Set bit 0 output
	pioptr->PIO_ODR = 0x0000003CL ;		// Set bits 2, 3, 4, 5 input
	pioptr->PIO_PUER = 0x0000003CL ;		// Set bits 2, 3, 4, 5 with pullups
#endif

	pioptr = PIOB ;
#ifdef REVB	
	pioptr->PIO_PUER = PIO_PB5 ;					// Enable pullup on bit B5 (MENU)
	pioptr->PIO_PER = PIO_PB5 ;					// Enable bit B5
#else	
	pioptr->PIO_PUER = PIO_PB6 ;					// Enable pullup on bit B6 (MENU)
	pioptr->PIO_PER = PIO_PB6 ;					// Enable bit B6
#endif
}

// Assumes PMC has already enabled clocks to ports
void setup_switches()
{
#ifdef REVB
#else
	register Pio *pioptr ;
	
	pioptr = PIOA ;
#endif
#ifdef REVB
	configure_pins( 0x01808087, PIN_ENABLE | PIN_INPUT | PIN_PORTA | PIN_PULLUP ) ;
#else 
	pioptr->PIO_PER = 0xF8008184 ;		// Enable bits
	pioptr->PIO_ODR = 0xF8008184 ;		// Set bits input
	pioptr->PIO_PUER = 0xF8008184 ;		// Set bits with pullups
#endif 
#ifdef REVB
#else
	pioptr = PIOB ;
#endif 
#ifdef REVB
	configure_pins( 0x00000030, PIN_ENABLE | PIN_INPUT | PIN_PORTB | PIN_PULLUP ) ;
#else 
	pioptr->PIO_PER = 0x00000010 ;		// Enable bits
	pioptr->PIO_ODR = 0x00000010 ;		// Set bits input
	pioptr->PIO_PUER = 0x00000010 ;		// Set bits with pullups
#endif 

#ifdef REVB
#else
	pioptr = PIOC ;
#endif 
#ifdef REVB
	configure_pins( 0x91114900, PIN_ENABLE | PIN_INPUT | PIN_PORTC | PIN_PULLUP ) ;
#else 
	pioptr->PIO_PER = 0x10014900 ;		// Enable bits
	pioptr->PIO_ODR = 0x10014900 ;		// Set bits input
	pioptr->PIO_PUER = 0x10014900 ;		// Set bits with pullups
#endif 

}


#endif


// keys:
// KEY_EXIT    PA31 (PC24)
// KEY_MENU    PB6 (PB5)
// KEY_DOWN  LCD5  PC3 (PC5)
// KEY_UP    LCD6  PC2 (PC1)
// KEY_RIGHT LCD4  PC4 (PC4)
// KEY_LEFT  LCD3  PC5 (PC3)
// Reqd. bit 6 LEFT, 5 RIGHT, 4 UP, 3 DOWN 2 EXIT 1 MENU
// LCD pins 5 DOWN, 4 RIGHT, 3 LEFT, 1 UP
#ifdef PCBSKY
uint32_t read_keys()
{
	register uint32_t x ;
	register uint32_t y ;

	x = LcdLock ? LcdInputs : PIOC->PIO_PDSR << 1 ; // 6 LEFT, 5 RIGHT, 4 DOWN, 3 UP ()
#ifdef REVB
	y = x & 0x00000020 ;		// RIGHT
	if ( x & 0x00000004 )
	{
		y |= 0x00000010 ;			// UP
	}
	if ( x & 0x00000010 )
	{
		y |= 0x00000040 ;			// LEFT
	}
	if ( x & 0x00000040 )
	{
		y |= 0x00000008 ;			// DOWN
	}
#else	
	y = x & 0x00000060 ;
	if ( x & 0x00000008 )
	{
		y |= 0x00000010 ;
	}
	if ( x & 0x00000010 )
	{
		y |= 0x00000008 ;
	}
#endif
#ifdef REVB
	if ( PIOC->PIO_PDSR & 0x01000000 )
#else 
	if ( PIOA->PIO_PDSR & 0x80000000 )
#endif
	{
		y |= 4 ;		// EXIT
	}
#ifdef REVB
	if ( PIOB->PIO_PDSR & 0x000000020 )
#else 
	if ( PIOB->PIO_PDSR & 0x000000040 )
#endif
	{
		y |= 2 ;		// MENU
	}
	return y ;
}
#endif


#ifdef PCBSKY
uint32_t read_trims()
{
	uint32_t trims ;
	uint32_t trima ;

	trims = 0 ;

	trima = PIOA->PIO_PDSR ;
// TRIM_LH_DOWN    PA7 (PA23)
#ifdef REVB
	if ( ( trima & 0x00800000 ) == 0 )
#else
	if ( ( trima & 0x0080 ) == 0 )
#endif
	{
		trims |= 1 ;
	}
    
// TRIM_LV_DOWN  PA27 (PA24)
#ifdef REVB
	if ( ( trima & 0x01000000 ) == 0 )
#else
	if ( ( trima & 0x08000000 ) == 0 )
#endif
	{
		trims |= 4 ;
	}

// TRIM_RV_UP    PA30 (PA1)
#ifdef REVB
	if ( ( trima & 0x00000002 ) == 0 )
#else
	if ( ( trima & 0x40000000 ) == 0 )
#endif
	{
		trims |= 0x20 ;
	}

// TRIM_RH_DOWN    PA29 (PA0)
#ifdef REVB
	if ( ( trima & 0x00000001 ) == 0 )
#else 
	if ( ( trima & 0x20000000 ) == 0 )
#endif 
	{
		trims |= 0x40 ;
	}

// TRIM_LH_UP PB4
	if ( ( PIOB->PIO_PDSR & 0x10 ) == 0 )
	{
		trims |= 2 ;
	}

	trima = PIOC->PIO_PDSR ;
// TRIM_LV_UP   PC28
	if ( ( trima & 0x10000000 ) == 0 )
	{
		trims |= 8 ;
	}

// TRIM_RV_DOWN   PC10
	if ( ( trima & 0x00000400 ) == 0 )
	{
		trims |= 0x10 ;
	}

// TRIM_RH_UP   PC9
	if ( ( trima & 0x00000200 ) == 0 )
	{
		trims |= 0x80 ;
	}

	return trims ;
}
#endif


#ifdef PCBSKY
extern uint32_t keyState(EnumKeys enuk)
{
	register uint32_t a ;
	register uint32_t c ;

  CPU_UINT xxx = 0 ;
  if(enuk < (int)DIM(keys))  return keys[enuk].state() ? 1 : 0;

	a = PIOA->PIO_PDSR ;
	c = PIOC->PIO_PDSR ;
	switch((uint8_t)enuk)
	{
#ifdef REVB
    case SW_ElevDR : xxx = c & 0x80000000 ;	// ELE_DR   PC31
#else 
    case SW_ElevDR : xxx = a & 0x00000100 ;	// ELE_DR   PA8
#endif 
    break ;
    
    case SW_AileDR : xxx = a & 0x00000004 ;	// AIL-DR  PA2
    break ;

    case SW_RuddDR : xxx = a & 0x00008000 ;	// RUN_DR   PA15
    break ;
      //     INP_G_ID1 INP_E_ID2
      // id0    0        1
      // id1    1        1
      // id2    1        0
    case SW_ID0    : xxx = ~c & 0x00004000 ;	// SW_IDL1     PC14
    break ;
    case SW_ID1    : xxx = (c & 0x00004000) ; if ( xxx ) xxx = (PIOC->PIO_PDSR & 0x00000800);
    break ;
    case SW_ID2    : xxx = ~c & 0x00000800 ;	// SW_IDL2     PC11
    break ;

    
		case SW_Gear   : xxx = c & 0x00010000 ;	// SW_GEAR     PC16
    break ;

#ifdef REVB
    case SW_ThrCt  : xxx = c & 0x00100000 ;	// SW_TCUT     PC20
#else 
    case SW_ThrCt  : xxx = a & 0x10000000 ;	// SW_TCUT     PA28
#endif 
    break ;

    case SW_Trainer: xxx = c & 0x00000100 ;	// SW-TRAIN    PC8
    break ;
    default:;
  }

  if ( xxx )
  {
    return 1 ;
  }
  return 0;
}
#endif


#ifdef PCBX9D
void init_keys()
{
// Buttons PE10, 11, 12, PD2, 3, 7
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN ; 		// Enable portE clock
	configure_pins( 0x1C00, PIN_INPUT | PIN_PULLUP | PIN_PORTE ) ;
	configure_pins( 0x008C, PIN_INPUT | PIN_PULLUP | PIN_PORTD ) ;
}

void init_trims()
{
// Trims 
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN ; 		// Enable portC clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN ; 		// Enable portE clock
	configure_pins( 0x0078, PIN_INPUT | PIN_PULLUP | PIN_PORTE ) ;
	configure_pins( 0x200E, PIN_INPUT | PIN_PULLUP | PIN_PORTC ) ;
}

// Reqd. bit 6 LEFT, 5 RIGHT, 4 UP, 3 DOWN 2 EXIT 1 MENU
uint32_t read_keys()
{
	register uint32_t x ;
	register uint32_t y ;

	x = GPIOD->IDR ; // 7 MENU, 3 PAGE(UP), 2 EXIT
	
	y = 0 ;
	if ( x & PIN_BUTTON_MENU )
	{
		y |= 0x02 << KEY_MENU ;			// MENU
	}
	if ( x & PIN_BUTTON_PAGE )
	{
		y |= 0x02 << KEY_UP ;			// up
	}
	if ( x & PIN_BUTTON_EXIT )
	{
		y |= 0x02 << KEY_EXIT ;			// EXIT
	}
	x = GPIOE->IDR ; // 10 RIGHT(+), 11 LEFT(-), 12 ENT(DOWN)

	if ( x & PIN_BUTTON_PLUS )
	{
		y |= 0x02 << KEY_RIGHT ;		// RIGHT
	}
	if ( x & PIN_BUTTON_MINUS )
	{
		y |= 0x02 << KEY_LEFT ;		// LEFT
	}
	if ( x & PIN_BUTTON_ENTER )
	{
		y |= 0x02 << KEY_DOWN ;		// DOWN
	}
	return y ;
}

uint32_t read_trims()
{
	uint32_t trims ;
	uint32_t trima ;

	trims = 0 ;

	trima = GPIOE->IDR ;

// TRIM_LH_DOWN
	if ( ( trima & 0x00000010 ) == 0 )
	{
		trims |= 1 ;
	}
    
// TRIM_LV_DOWN
	if ( ( trima & 0x00000040 ) == 0 )
	{
		trims |= 4 ;
	}

// TRIM_LH_UP
	if ( ( trima & 0x00000008 ) == 0 )
	{
		trims |= 2 ;
	}

// TRIM_LV_UP
	if ( ( trima & 0x00000020 ) == 0 )
	{
		trims |= 8 ;
	}

	trima = GPIOC->IDR ;

// TRIM_RV_UP
	if ( ( trima & 0x00000008 ) == 0 )
	{
		trims |= 0x20 ;
	}

// TRIM_RH_DOWN
	if ( ( trima & 0x00002000 ) == 0 )
	{
		trims |= 0x40 ;
	}


// TRIM_RV_DOWN
	if ( ( trima & 0x00000004 ) == 0 )
	{
		trims |= 0x10 ;
	}

// TRIM_RH_UP
	if ( ( trima & 0x00000002 ) == 0 )
	{
		trims |= 0x80 ;
	}

	return trims ;
}


#endif


#ifdef PCBX9D

// 
void setup_switches()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN ; 		// Enable portA clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN ; 		// Enable portB clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN ; 		// Enable portE clock
	configure_pins( 0x0020, PIN_INPUT | PIN_PULLUP | PIN_PORTA ) ;
	configure_pins( 0x00FB, PIN_INPUT | PIN_PULLUP | PIN_PORTB ) ;
	configure_pins( 0x6384, PIN_INPUT | PIN_PULLUP | PIN_PORTE ) ;
	
}



uint32_t keyState(EnumKeys enuk)
{
  register uint32_t a = GPIOA->IDR;
  register uint32_t b = GPIOB->IDR;
  register uint32_t e = GPIOE->IDR;

  register uint32_t xxx = 0;

  if (enuk < (int) DIM(keys)) return keys[enuk].state() ? 1 : 0;

  switch ((uint8_t) enuk) {
    case SW_SA0:
      xxx = ~e & PIN_SW_A_L;
      break;
    case SW_SA2:
      xxx = e & PIN_SW_A_L;
      break;

    case SW_SB0:
      xxx = ~b & PIN_SW_B_L ;
      break;
    case SW_SB1:
      xxx = (b & (PIN_SW_B_L | PIN_SW_B_H)) == (PIN_SW_B_L | PIN_SW_B_H) ;
      break;
    case SW_SB2:
      xxx = ~b & PIN_SW_B_H ;
      break;

    case SW_SC0:
      xxx = ~b & PIN_SW_C_L ;
      break;
    case SW_SC1:
      xxx = (b & (PIN_SW_C_H | PIN_SW_C_L)) == (PIN_SW_C_H | PIN_SW_C_L) ;
      break;
    case SW_SC2:
      xxx = ~b & PIN_SW_C_H ;
      break;

    case SW_SD0:
      xxx = ~e & PIN_SW_D_L ;
      break;
    case SW_SD1:
      xxx = ((b & PIN_SW_D_H) | (e & PIN_SW_D_L)) == (PIN_SW_D_H | PIN_SW_D_L) ;
      break;
    case SW_SD2:
      xxx = ~b & PIN_SW_D_H ;
      break;

    case SW_SE0:
      xxx = ~a & PIN_SW_E_L ;
      break;
    case SW_SE1:
      xxx = ((b & PIN_SW_E_H) | (a & PIN_SW_E_L)) == (PIN_SW_E_H | PIN_SW_E_L) ;
      break;
    case SW_SE2:
      xxx = ~b & PIN_SW_E_H ;
      break;

    case SW_SF0:
      xxx = ~b & PIN_SW_F_L ;
      break;
    case SW_SF1:
      xxx = ((e & PIN_SW_F_H) | (b & PIN_SW_F_L)) == (PIN_SW_F_H | PIN_SW_F_L) ;
      break;
    case SW_SF2:
      xxx = ~e & PIN_SW_F_H ;
      break;

    case SW_SG0:
      xxx = ~e & PIN_SW_G_L ;
      break;
    case SW_SG1:
      xxx = (e & (PIN_SW_G_H | PIN_SW_G_L)) == (PIN_SW_G_H | PIN_SW_G_L) ;
      break;
    case SW_SG2:
      xxx = ~e & PIN_SW_G_H ;
      break;

    case SW_SH0:
      xxx = ~e & PIN_SW_H_L;
      break;
    case SW_SH2:
      xxx = e & PIN_SW_H_L;
      break;

    default:
      break;
  }

  if (xxx) {
    return 1;
  }

  return 0;
}
#endif


