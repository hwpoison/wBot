#include <iostream>
#include <string>
#include "wBot.h"
using namespace std;

void print(const char *msg){
	cout << msg << endl;
}

int main()
{
   wBot *bot = new wBot;
   bot->typeText("Hola como va!");
   bot->waitSecs(1);
   
   print("Bajemos un poco el volumen..");
   for(int i=0;i<50;i++)
  	 bot->pressKey(VOLUMEN_DOWN);
   bot->waitSecs(1);
   
   print("Ahora subamoslo un poco..");
   for(int i=0;i<50;i++)
  	 bot->pressKey(VOLUMEN_UP);
   bot->waitSecs(1);
   
   print("Muy alto mejor mutiemos..");
   bot->pressKey(MUTE_SOUND);
   bot->waitSecs(2);
   
   print("Ja era broma");
   bot->pressKey(MUTE_SOUND);
   
   print("A ver escribamos algo..");
   string texto;
   bot->typeText("Hola Mundo como va todo espero que bien yo igual me alegro ;)");
   bot->pressKey(ENTER);
   cin >> texto;
   print("EL MOUSE SE MUEVE SOLO!");
   
   int xpos = 50;
   int ypos = 20;
   for(int i=0;i<5;i++){
  	 bot->xMouse(xpos++);
  	 Sleep(400);
  	 bot->yMouse(ypos--);
   }
   
   print("Bueno ya me voy");
   bot->waitSecs(1);
   print("Chau!");
   system("pause");
}
