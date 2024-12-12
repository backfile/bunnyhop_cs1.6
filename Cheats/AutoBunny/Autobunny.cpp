#include <iostream>
#include <windows.h>
using namespace std;

#define F2 0x3C0000

int main() {
	
	// Direcciones de memoria
	DWORD FL_ONGROUND = 0x1B70A54; 
	DWORD HL = 0x01400000;
	
	//Ventana del cs
	HWND ventana = FindWindow(0, "Counter-Strike");

	//Handle al cs
	HANDLE hp;
	
	//process id de cs
	DWORD pid;
	
	// Obtener el procces id del cs mediante su ventana
	GetWindowThreadProcessId(ventana, &pid);
	
	//Obtener el handle mediante el pid
	hp = OpenProcess(PROCESS_ALL_ACCESS, true, pid);
	
	
	int ground;
	
	while(1){
		//Mediante el hp podemos leer y escribir en el proceso
		ReadProcessMemory(hp, (PVOID)(HL + FL_ONGROUND), &ground, sizeof(ground), 0);
		cout << ground;
		if(GetKeyState(VK_SPACE) & 0x8000){
			if(ground == 1){
				SendMessage(ventana, WM_KEYDOWN, F2, F2);
				Sleep(1);
				SendMessage(ventana, WM_KEYUP, F2, F2);
			}
		}
		Sleep(1);
	}
	return 0;
}

