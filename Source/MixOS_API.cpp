#include "MixOS_API.h" 
/*=================================================================================================
 *==============================MIXOSAPI FOR MIXOS FROM Z_KRAF1ER_Z================================
*/

LPVOID lpvData = NULL;

LPVOID MixInterface(BYTE cType, LPCVOID lpcvData)
{
	switch (cType)
	{
		case TYPE_MIXOS_HWND /*|| TYPE_TERMINAL_HWND || TYPE_PIANO_HWND || TYPE_EMULATE_HWND || TYPE_YOUTUBE_HWND || TYPE_MENUMAKER_HWND*/:
			return lpvData;

		//ОГО
		// зайди в дс
		//Скоро зайду... Я сейчас для всех клавиш пианино прописал код и оно работает
	}
}

BOOL MixSendInfo(BYTE cType, LPCVOID lpcvData)
{
	switch (cType)
	{
	case TYPE_MIXOS_HWND:
		lpvData == lpcvData;
		if (lpvData)
			return TRUE;
		break;
	} 

	return FALSE;
}