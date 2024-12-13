#include <iostream>
#include <windows.h>

#define F2 0x3C0000
#define W 0x110000;

using namespace std;

int main() {
	
	HWND cs = FindWindow(0, "Counter-Strike");

	Sleep(3000);
	// PULSAR TECLA F2  
	while(1){
		SendMessage(cs, WM_KEYDOWN, W, W);
		Sleep(1);
		cout << "HOLA";
	}
	return 0;
}

