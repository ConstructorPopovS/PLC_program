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
#include "../include/Menu_folder/UpdateCoord_folder/UpdateCoord.h"
#include "../include/Menu_folder/UpdateCoord_folder/IntUpdateCoord.h"
#include "../include/Menu_folder/UpdateCoord_folder/BoolUpdateCoord.h"
#include "../include/Console_folder/Keypad_folder/GetDataFromKeypad.h"

ToggleWithKey toggleKey;
ToggleFurnaceModes toggleFurnaceMode;
GetDataFromKeypad dataFromKeypad;
PrintMenuOnLCD lcdMenuPrinting;

RobotCoordinates robotCoordinates(100, 0, 0, 10);
FurnaceCoordinates furnanceCoordinates(120, 1, false, false);
TemperatureCoordinates temperatureCoordinates(1000, 600, 985);

MenuCoordinates currentMenuState;
MenuCoordinates targetMenuState;

UpdateCoord *pUpdateCoordinate = NULL;
IntUpdateCoord xUpdateCoordinate(robotCoordinates.getRTargetX(), 10, 1, 1, 10);
IntUpdateCoord yUpdateCoordinate(robotCoordinates.getRTargetY(), 10, 1, 1, 10);
IntUpdateCoord fiUpdateCoordinate(robotCoordinates.getRTargetFi(), 10, 1, 1, 10);
IntUpdateCoord vUpdateCoordinate(robotCoordinates.getRTargetV(), 2, 1, 1, 2);
IntUpdateCoord liftUpdateCoordinate(furnanceCoordinates.getRTargetLift(), 10, 1, 1, 10);
IntUpdateCoord liftFloorUpdateCoordinate(furnanceCoordinates.getRTargetLiftFloor(), 1, 1, 1, 1);
IntUpdateCoord highTemperatureUpdateCoordinate(temperatureCoordinates.getRTargetHighTemperature(), 50, 5, 5, 50);
IntUpdateCoord lowTemperatureUpdateCoordinate(temperatureCoordinates.getRTergetLowTemperature(), 50, 5, 5, 50);
BoolUpdateCoord doorsUpdateCoordinate(furnanceCoordinates.getRTargetDoors());
BoolUpdateCoord standUpdateCoordinate(furnanceCoordinates.getRTargetStand());
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
                                           furnanceCoordinates.getTargetStand(),
                                           temperatureCoordinates.getTargetHighTemperature(),
                                           temperatureCoordinates.getTergetLowTemperature(),
                                           temperatureCoordinates.getTergetNowTemperature());
    }
  }
  if (currentMenuState.getMode() == "MANUAL")
  {
    if (dataFromKeypad.keyIsPressed())
    {
      NamesOfKeys nameOfKey = dataFromKeypad.getNameOfKey();
      switch (nameOfKey)
      {
      case X:
        pUpdateCoordinate = &xUpdateCoordinate;
        break;
      case Y:
        pUpdateCoordinate = &yUpdateCoordinate;
        break;
      case FI:
        pUpdateCoordinate = &fiUpdateCoordinate;
        break;
      case V:
        pUpdateCoordinate = &vUpdateCoordinate;
        break;
      case LIFT:
        pUpdateCoordinate = &liftUpdateCoordinate;
        break;
      case DOORS:
        pUpdateCoordinate = &doorsUpdateCoordinate;
        break;
      case STAND:
        pUpdateCoordinate = &standUpdateCoordinate;
        break;
      case TEMPERATURE:
        if (toggleFurnaceMode.getMode() == "HIGH")
        {
          pUpdateCoordinate = &highTemperatureUpdateCoordinate;
        }
        else if (toggleFurnaceMode.getMode() == "LOW")
        {
          pUpdateCoordinate = &lowTemperatureUpdateCoordinate;
        }
        break;
      case MINUS_MINUS:
        if (pUpdateCoordinate != NULL)
        {
          pUpdateCoordinate->minusMinus();
        }
        break;
      case MINUS:
        pUpdateCoordinate->minus();
        break;
      case PLUS:
        pUpdateCoordinate->plus();
        break;
      case PLUS_PLUS:
        pUpdateCoordinate->plusPlus();
        break;
      default:
        break;
      }
      lcdMenuPrinting.renewAllCoordiinates(robotCoordinates.getTargetX(),
                                           robotCoordinates.getTargetY(),
                                           robotCoordinates.getTargetFi(),
                                           robotCoordinates.getTargetV(),
                                           furnanceCoordinates.getTargetLift(),
                                           furnanceCoordinates.getTargetLiftFloor(),
                                           furnanceCoordinates.getTargetDoors(),
                                           furnanceCoordinates.getTargetStand(),
                                           temperatureCoordinates.getTargetHighTemperature(),
                                           temperatureCoordinates.getTergetLowTemperature(),
                                           temperatureCoordinates.getTergetNowTemperature());
    }
  }
}