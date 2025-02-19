#pragma once

extern "C"
{
	#include "xparameters.h"	// XPAR_XIIC_0_BASEADDR, XPAR_XGPIOPS_0_BASEADDR

	#include "xgpiops.h"		// XGpioPs
    #include "xiicps.h"         // XIicPs
}

#include <cstdio>	// printf()
#include <cstdint>	// uint8_t
#include <vector>	// vector

constexpr uint8_t  SLAVE_ADDRESS       = 0x3B;						// 0x76 >> 1
constexpr uint32_t XGPIOPS_BASEADDR    = XPAR_XGPIOPS_0_BASEADDR;
constexpr uint32_t XIICPS_BASEADDRESS	   = XPAR_XIICPS_0_BASEADDR;
constexpr uint32_t Sil9022A_RESETn_pin = 51;						// This is connected to PS as MIO51

class Sil9022A
{
public:
	Sil9022A (void);

	// ====================================================
	//  Perform a burst I2C write at register address v[0]
	// ====================================================
	void write (const std::vector<uint8_t>& v);

	// ===========================================
	//  Perform a burst I2C read of size "size"
	//  Vector "v" or "reg_addr" is written first
	// ===========================================
	std::vector<uint8_t> read (const std::vector<uint8_t>& v, const uint32_t& size);
	std::vector<uint8_t> read (const uint8_t& reg_addr, const uint32_t& size);
	
private:
	// ======================
	//  Single use functions
	// ======================
	XGpioPs XGpioPs_init (void) const;
	XIicPs XIicPs_init (void);
	void raise_RESETn (void) const;

	// ==================
	//  Common functions
	// ==================
	void wait (void) const;
	
	// =====================
	//  Auxiliary functions
	// =====================
	void print_vec (const std::vector<uint8_t>& v) const;
	void print_vec (const uint8_t& reg, const std::vector<uint8_t>& v) const;

	// ===========
	//  Variables
	// ===========
	XIicPs Iic;
};
