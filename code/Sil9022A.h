#pragma once

extern "C"
{
	#include "xparameters.h"	// XPAR_XIIC_0_BASEADDR, XPAR_XGPIOPS_0_BASEADDR

	#include "xgpiops.h"		// XGpioPs{}
}

#include <cstdio>	// printf()
#include <cstdint>	// uint8_t
#include <vector>	// vector{}
#include "I2C.h"	// I2C{}

constexpr uint32_t XGPIOPS_BASEADDR		= XPAR_XGPIOPS_0_BASEADDR;
constexpr uint32_t Sil9022A_RESETn_pin	= 51;						// This is connected to PS as MIO51

class Sil9022A: virtual public I2C
{
public:
	Sil9022A (void);
	
private:
	// ======================
	//  Single use functions
	// ======================
	XGpioPs XGpioPs_init (void) const;
	void raise_RESETn (void) const;
};
