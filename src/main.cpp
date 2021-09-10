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
#include "../include/Menu_folder/UpdateCoord_folder/IntUpdateCoord.h"
#include "../include/Menu_folder/UpdateCoord_folder/BoolUpdateCoord.h"

ToggleWithKey toggleKey;
PrintMenuOnLCD lcdMenuPrinting;

RobotCoordinates robotCoordinates(100, 0, 0, 10);
FurnaceCoordinates furnanceCoordinates(120, 1, false, false);
TemperatureCoordinates temperatureCoordinates(1000, 600, 985);

MenuCoordinates currentMenuState;
MenuCoordinates targetMenuState;

IntUpdateCoord *rIntUpdateCoordinates;
IntUpdateCoord xIntUpdateCoordinate(robotCoordinates.getRTargetX(), 10, 1, 1, 10);
IntUpdateCoord yIntUpdateCoordinate(robotCoordinates.getRTargetY(), 10, 1, 1, 10);
IntUpdateCoord fiIntUpdateCoordinate(robotCoordinates.getRTargetFi(), 10, 1, 1, 10);
IntUpdateCoord vIntUpdateCoordinate(robotCoordinates.getRTargetV(), 2, 1, 1, 2);
IntUpdateCoord liftIntUpdateCoordinate(furnanceCoordinates.getRTargetLift(), 10, 1, 1, 10);
IntUpdateCoord liftFloorIntUpdateCoordinate(furnanceCoordinates.getRTargetLiftFloor(), 1, 1, 1, 1);
IntUpdateCoord highTemperatureIntUpdateCoordinate(temperatureCoordinates.getRTargetHighTemperature(), 50, 5, 5, 50);
IntUpdateCoord lowTemperatureIntUpdateCoordinate(temperatureCoordinates.getRTergetLowTemperature(), 50, 5, 5, 50);
BoolUpdateCoord *rBoolUpdateCoordinates;
BoolUpdateCoord doorsBoolUpdateCoordinates(furnanceCoordinates.getRTargetDoors());
BoolUpdateCoord supportBoolUpdateCoordinates(furnanceCoordinates.getRTargetSupport());
IntUpdateCoord coordinatesToDoAction[] =
    {xIntUpdateCoordinate, yIntUpdateCoordinate, fiIntUpdateCoordinate, vIntUpdateCoordinate};
// Robot robot(1, 2, 3, &Serial1, 4, 1000000L); //TODO 1000000L change to long(1000000) and tested
void setup(void)
{
  Serial.begin(9600);
  Serial.setTimeout(500); //установка времени для считывания из порта
  lcdMenuPrinting.initAndBacklight();
  Serial.println("Start");
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
      lcdMenuPrinting.printAllCoordiinates(robotCoordinates.getTargetX(),
                                           robotCoordinates.getTargetY(),
                                           robotCoordinates.getTargetFi(),
                                           robotCoordinates.getTargetV(),
                                           furnanceCoordinates.getTargetLift(),
                                           furnanceCoordinates.getTargetLiftFloor(),
                                           furnanceCoordinates.getTargetDoors(),
                                           furnanceCoordinates.getTargetSupport(),
                                           temperatureCoordinates.getTargetHighTemperature(),
                                           temperatureCoordinates.getTergetLowTemperature(),
                                           temperatureCoordinates.getTergetNowTemperature());
    }
  }
  if (currentMenuState.getMode() == "MANUAL")
  {
    int a = 20;
    if (Serial.available())
    {
      a = Serial.parseInt();
      robotCoordinates.setTargetX(a);
      Serial.println("x = " + String(robotCoordinates.getTargetX()));
    }
    lcdMenuPrinting.renewAllCoordiinates(robotCoordinates.getTargetX(),
                                         robotCoordinates.getTargetY(),
                                         robotCoordinates.getTargetFi(),
                                         robotCoordinates.getTargetV(),
                                         furnanceCoordinates.getTargetLift(),
                                         furnanceCoordinates.getTargetLiftFloor(),
                                         furnanceCoordinates.getTargetDoors(),
                                         furnanceCoordinates.getTargetSupport(),
                                         temperatureCoordinates.getTargetHighTemperature(),
                                         temperatureCoordinates.getTergetLowTemperature(),
                                         temperatureCoordinates.getTergetNowTemperature());
  }
}