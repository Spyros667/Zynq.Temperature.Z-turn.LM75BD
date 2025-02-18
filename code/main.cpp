#include "platform.h"
#include "Sil9022A.h"	// Sil9022A abstraction class
#include <cstdio>		// printf()

int main()
{
	init_platform();
	printf("Hellow World\r\n");

	// ===========================================
	//  Initialize/ Power up the HDMI transmitter
	// ===========================================
	Sil9022A sil;

	printf("Successfully ran Hellow World application\r\n");
	cleanup_platform();

	return 0;
}
