#include "GPIOManager.h"
#include "GPIOConst.h"
using namespace GPIO;

int main() 
{
	bool state = false; //false = no recording, true = recording

	GPIOManager* gp = GPIO::GPIOManager::getInstance(); //setting up gpio manager

	int ledpin = GPIO::Const::getInstance()->getGpioByKey("P9_15"); //declaring pins
	int buttonpin =  GPIO::Const::getInstance()->getGpioByKey("P9_41");

	gp->SetDirection(ledpin, OUTPUT); //setting direction
	gp->SetDirection(buttonpin, INPUT);

	while(1)
	{
		if(state == false && getValue(buttonpin) == HIGH)
		{ 
			gp->setValue(ledpin, HIGH);
		}
		else if(state == true && getValue(buttonpin) == LOW)
		{
			gp->setValue(ledpin, LOW);
		}
	}
	gp->~GPIOManager();	

	std::cout << getvalue(buttonpin) "\n";
	
	return 0;
}
