#ifndef KEYBOT_H
#define KEYBOT_H
#include <windows.h>

class wBot
{
private:
    INPUT _buffer;
    void clearBuffer(){
    	ZeroMemory(&_buffer,sizeof(INPUT));
	};
	void setInputType(char type){
		_buffer.type = type;
	}
public:
    wBot();
    //Keyboard Functions
    void KeyUp( char key ); 
    void KeyDown( char key );
    void pressKey( char key );
    char charToHex( char key);
    void typeASCIIText( const char *text);
    void typeUnicode(char key);
    void typeText( const char *text, int lag=10);
    void waitSecs(int secs);
    
    //Mouse Functions
	void xMouse( long x);
	void yMouse( long y);
	void xyMouse(long x, long y);
	void mousePressButton(char mouseButton);
	void mouseLClick();
	void mouseRClick();
};

enum {
	LALT = 0xA4,
	RALT = 0xA5,
	ENTER = 0x0D,
	VOLUMEN_UP = 0xAF,
	VOLUMEN_DOWN = 0xAE,
	MUTE_SOUND = 0xAD,
};
//https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes
#endif


