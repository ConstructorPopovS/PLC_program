//подключение функций из других файлов
// #include "Robot_folder/RobotClass.h"
#include "main.h"

#include "../include/Console_folder/Toggle_folder/ToggleWithKey.h"

#include "../include/CoordinateClasses_folder/MenuCoordinates.h"
#include "../include/LCD_folder/PrintMenuOnLCD.h"
#include "../include/Console_folder/Toggle_folder/ToggleFurnaceModes.h"
#include "../include/CoordinateClasses_folder/RobotCoordinates.h"
#include "../include/CoordinateClasses_folder/FurnaceCoordinates.h"
#include "../include/CoordinateClasses_folder/TemperatureCoordinates.h"
#include "../include/Console_folder/Keypad_folder/GetDataFromKeypad.h"

ToggleWithKey toggleKey;
PrintMenuOnLCD lcdMenuPrinting;

MenuCoordinates currentMenuState;
MenuCoordinates targetMenuState;

RobotCoordinates robotCoordinates(100, 0, 0, 10);
FurnaceCoordinates furnanceCoordinates(120, 1, false, false);
TemperatureCoordinates temperatureCoordinates(1000, 600);

// Robot robot(1, 2, 3, &Serial1, 4, 1000000L); //TODO 1000000L change to long(1000000) and tested
void setup(void)
{
  Serial.begin(9600);
  Serial.setTimeout(70); //установка времени для считывания из порта
  lcdMenuPrinting.initAndBacklight();
}

/*--------------------------------------------------------------------*/
void loop(void)
{

  targetMenuState.setMode(toggleKey.getMode());
  if (currentMenuState.getMode() != targetMenuState.getMode())
  {
    currentMenuState.setMode(targetMenuState.getMode());
    lcdMenuPrinting.printConstPartOfMode(targetMenuState.getMode());
    if (currentMenuState.getMode() == "MANUAL")
    {
      lcdMenuPrinting.renewAllCoordiinates(robotCoordinates.getTargetX(),
                                           robotCoordinates.getTargetY(),
                                           robotCoordinates.getTargetFi(),
                                           robotCoordinates.getTargetV(),
                                           furnanceCoordinates.getTargetLift(),
                                           furnanceCoordinates.getTargetLiftFloor(),
                                           furnanceCoordinates.getTargetDoors(),
                                           furnanceCoordinates.getTargetSupport(),
                                           temperatureCoordinates.getTargetHighTemperature(),
                                           temperatureCoordinates.getTergetLowTemperature());
    }
  }
}