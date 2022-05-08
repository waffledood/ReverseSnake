// -----------------------------------------------------------------------------
// C-Skeleton to be used with HEL 2 Library from www.console-dev.de
// -----------------------------------------------------------------------------
#include <hel2.h>

// -----------------------------------------------------------------------------
// Prototypes
// -----------------------------------------------------------------------------
void VBLInterruptHandler();


// -----------------------------------------------------------------------------
// Project Entry Point
// -----------------------------------------------------------------------------
int main(void)
{
	// Initialize HAMlib
	ham_Init();

	// Turn of prefetch buffer
	hel_SysSetPrefetch(TRUE);

	// Set background mode
	ham_SetBgMode(0);

	// Enable Vertical Blank Interrupt
	hel_IntrStartHandler(INT_TYPE_VBL, VBLInterruptHandler);


	// Infinite loop
	for(;;)
	{
		// Wait for Vertical-Blank Interrupt
		hel_SwiVBlankIntrWait();
	}
	
	return 0;
}

// -----------------------------------------------------------------------------
// Function gets triggered every vertical blank
// -----------------------------------------------------------------------------
void VBLInterruptHandler()
{
	// Acknowldge Interrupt
	hel_IntrAcknowledge(INT_TYPE_VBL);
}

