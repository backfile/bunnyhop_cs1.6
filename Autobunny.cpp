#include <iostream>
#include <windows.h>
using namespace std;

#define F2 0x3C0000

int main() {
	
	// Direcciones de memoria
	DWORD FL_ONGROUND = 0x1B70A54; 
	DWORD FL_TOGGLE_TEXT = 0x61B8A4;
	DWORD FL_TEXT = 0x627540;
	DWORD FL_VELOCITY = 0x617920;
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
	int text_on = 1;
	int text_off = 0;
	
	
	string text = "Bunny creado por Frankiller UwU\n \\rVelocidad: ";
	string velo;
	string text_def;
	char textchar[256];
	
	float vel;
	
	while(1){
		//Mediante el hp podemos leer y escribir en el proceso
		ReadProcessMemory(hp, (PVOID)(HL + FL_VELOCITY), &vel, sizeof(vel), 0);
		ReadProcessMemory(hp, (PVOID)(HL + FL_ONGROUND), &ground, sizeof(ground), 0);
		velo = to_string(vel);
		//Unir textos
		text_def = text + velo;
		strcpy(textchar, text_def.c_str());
		
		if(GetKeyState(VK_SPACE) & 0x8000){
			if(ground == 1){
				SendMessage(ventana, WM_KEYDOWN, F2, F2);
				Sleep(1);
				SendMessage(ventana, WM_KEYUP, F2, F2);
			}
		}
		if(GetKeyState(VK_F3)){
			WriteProcessMemory(hp, (PVOID*)(HL + FL_TEXT), &textchar, sizeof(textchar), 0);
			WriteProcessMemory(hp, (PVOID*)(HL + FL_TOGGLE_TEXT), &text_on, sizeof(text_on), 0);
		}else{
			WriteProcessMemory(hp, (PVOID*)(HL + FL_TOGGLE_TEXT), &text_off, sizeof(text_off), 0);
		}
		Sleep(1);
	}
	return 0;
}

