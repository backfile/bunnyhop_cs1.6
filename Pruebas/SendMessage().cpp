#include <iostream>
#include <windows.h>

#define F2 0x3C0000

using namespace std;

int main() {
	
	HWND cs = FindWindow(0, "Counter-Strike");

	Sleep(8000);
	// PULSAR TECLA F2  
	SendMessage(cs, WM_KEYDOWN, F2, F2);
	Sleep(1);
	SendMessage(cs, WM_KEYUP, F2, F2);
	
	return 0;
}

