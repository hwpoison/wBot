#include "wBot.h"
wBot::wBot()
{
	clearBuffer();
    setInputType(INPUT_KEYBOARD);
    _buffer.ki.dwFlags = KEYEVENTF_UNICODE;
    _buffer.ki.wScan = 0;
    _buffer.ki.time = 0;
    _buffer.ki.dwExtraInfo = 0;
}

void wBot::KeyUp( char key )
{
    _buffer.ki.wVk = key;
    _buffer.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput( 1, &_buffer, sizeof( INPUT ) );
}
 
void wBot::KeyDown( char key )
{
    _buffer.ki.wVk = key;
    _buffer.ki.dwFlags = 0;
    SendInput( 1, &_buffer, sizeof( INPUT ) );
}

void wBot::pressKey( char key)
{
	KeyDown( key );
	KeyUp( key );
}

char wBot::charToHex( char key )
{
	return (int)key-32;
}

void wBot::typeASCIIText(const char *string ){
	for(int i = 0; string[i] != '\0'; i++){
		pressKey(charToHex(string[i]));
	}
	
}

void wBot::typeUnicode( char key ){
	clearBuffer();
	setInputType(INPUT_KEYBOARD);
    _buffer.ki.dwFlags = KEYEVENTF_UNICODE;
    _buffer.ki.time = 0;
    _buffer.ki.dwExtraInfo = 0;
	_buffer.ki.wScan = key;
	SendInput( 1, &_buffer, sizeof( INPUT ) );
}

void wBot::typeText(const char *string ,int lag){
	for(int i = 0; string[i] != '\0'; i++){
		typeUnicode(string[i]);
		Sleep(lag);
	
	}
	
}

void wBot::waitSecs(int secs){
	Sleep(secs*1000);
}

void wBot::xMouse(long x){
	setInputType(INPUT_MOUSE);
	_buffer.mi.dwFlags = MOUSEEVENTF_MOVE;
	_buffer.mi.dx = x;
	SendInput( 1, &_buffer, sizeof(INPUT));
}


void wBot::yMouse(long y){
	setInputType(INPUT_MOUSE);
	_buffer.mi.dwFlags = MOUSEEVENTF_MOVE;
	_buffer.mi.dy = y;
	SendInput( 1, &_buffer, sizeof(INPUT));
}

void wBot::xyMouse(long x, long y){
	setInputType(INPUT_MOUSE);
	_buffer.mi.dwFlags = MOUSEEVENTF_MOVE;
	_buffer.mi.dy = y;
	_buffer.mi.dx = x;
	SendInput( 1, &_buffer, sizeof(INPUT));
}

void wBot::mousePressButton(char mouseButton){
	setInputType(INPUT_MOUSE);
	_buffer.mi.dwFlags  = mouseButton;
	SendInput( 1, &_buffer, sizeof(INPUT));
}

void wBot::mouseLClick(){
	//Left Click
	mousePressButton(MOUSEEVENTF_LEFTDOWN);
	mousePressButton(MOUSEEVENTF_LEFTUP);
}

void wBot::mouseRClick(){
	//Right Click
	mousePressButton(MOUSEEVENTF_RIGHTDOWN);
	mousePressButton(MOUSEEVENTF_RIGHTUP);
}

