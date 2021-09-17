//подключение функций из других файлов
// #include "Robot_folder/RobotClass.h"
#include "main.h"

#include "../include/Console_folder/Toggle_folder/ToggleWithKey.h"

#include "../include/CoordinateClasses_folder/MenuModes.h"
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

RobotCoordinates robotCoordinatesInMenu(100, 0, 0, 10);
FurnaceCoordinates furnanceCoordinates(120, 1, false, false);
TemperatureCoordinates temperatureCoordinates(1000, 600, 985);

MenuModes currentMenuMode;
MenuModes targetMenuMode;

UpdateCoord* pUpdateCoordinate = NULL;//указатель
IntUpdateCoord xUpdateCoordinate(robotCoordinatesInMenu.getRX(), 10, 1, 1, 10);
IntUpdateCoord yUpdateCoordinate(robotCoordinatesInMenu.getRY(), 10, 1, 1, 10);
IntUpdateCoord fiUpdateCoordinate(robotCoordinatesInMenu.getRFi(), 10, 1, 1, 10);
IntUpdateCoord vUpdateCoordinate(robotCoordinatesInMenu.getRV(), 2, 1, 1, 2);
IntUpdateCoord liftUpdateCoordinate(furnanceCoordinates.getRLift(), 10, 1, 1, 10);
IntUpdateCoord liftFloorUpdateCoordinate(furnanceCoordinates.getRLiftFloor(), 1, 1, 1, 1);
BoolUpdateCoord doorsUpdateCoordinate(furnanceCoordinates.getRDoors());
BoolUpdateCoord standUpdateCoordinate(furnanceCoordinates.getRStand());
IntUpdateCoord highTemperatureUpdateCoordinate(temperatureCoordinates.getRHighTemperature(), 50, 5, 5, 50);
IntUpdateCoord lowTemperatureUpdateCoordinate(temperatureCoordinates.getRLowTemperature(), 50, 5, 5, 50);
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

  targetMenuMode.setMode(toggleKey.getMode());
  if (currentMenuMode.getMode() != targetMenuMode.getMode())
  {
    currentMenuMode.setMode(targetMenuMode.getMode());
    lcdMenuPrinting.printConstPartOfMode(targetMenuMode.getMode());
    if (currentMenuMode.getMode() == "MANUAL")
    {
      lcdMenuPrinting.printAllCoordiinates(robotCoordinatesInMenu.getX(),
                                           robotCoordinatesInMenu.getY(),
                                           robotCoordinatesInMenu.getFi(),
                                           robotCoordinatesInMenu.getV(),
                                           furnanceCoordinates.getLift(),
                                           furnanceCoordinates.getLiftFloor(),
                                           furnanceCoordinates.getDoors(),
                                           furnanceCoordinates.getStand(),
                                           temperatureCoordinates.getHighTemperature(),
                                           temperatureCoordinates.getLowTemperature(),
                                           temperatureCoordinates.getNowTemperature());
    }
  }
  if (currentMenuMode.getMode() == "MANUAL")
  {
    if (dataFromKeypad.keyIsPressed())
    {
      NamesOfKeys nameOfKey = dataFromKeypad.getNameOfKey();
      switch (nameOfKey)
      {
      case X:
        pUpdateCoordinate = &xUpdateCoordinate;
        lcdMenuPrinting.setCursorAndBlinc("x");
        break;
      case Y:
        pUpdateCoordinate = &yUpdateCoordinate;
        lcdMenuPrinting.setCursorAndBlinc("y");
        break;
      case FI:
        pUpdateCoordinate = &fiUpdateCoordinate;
        lcdMenuPrinting.setCursorAndBlinc("fi");
        break;
      case V:
        pUpdateCoordinate = &vUpdateCoordinate;
        lcdMenuPrinting.setCursorAndBlinc("v");
        break;
      case LIFT:
        pUpdateCoordinate = &liftUpdateCoordinate;
        lcdMenuPrinting.setCursorAndBlinc("lift");
        break;
      case DOORS:
        pUpdateCoordinate = &doorsUpdateCoordinate;
        lcdMenuPrinting.setCursorAndBlinc("doors");
        break;
      case STAND:
        pUpdateCoordinate = &standUpdateCoordinate;
        lcdMenuPrinting.setCursorAndBlinc("stand");
        break;
      case TEMPERATURE: //TODO realise changing H or L temperature
        if (toggleFurnaceMode.getMode() == "HIGH")
        {
          pUpdateCoordinate = &highTemperatureUpdateCoordinate;
          lcdMenuPrinting.setCursorAndBlinc("highTemperature");
        }
        else if (toggleFurnaceMode.getMode() == "LOW")
        {
          pUpdateCoordinate = &lowTemperatureUpdateCoordinate;
          lcdMenuPrinting.setCursorAndBlinc("lowTemperature");
        }
        break;
      case MINUS_MINUS:
        if (pUpdateCoordinate != NULL)
        {
          pUpdateCoordinate->minusMinus();
        }
        break;
      case MINUS:
        if (pUpdateCoordinate != NULL)
        {
          pUpdateCoordinate->minus();
        }
        break;
      case PLUS:
        if (pUpdateCoordinate != NULL)
        {
          pUpdateCoordinate->plus();
        }
        break;
      case PLUS_PLUS:
        if (pUpdateCoordinate != NULL)
        {
          pUpdateCoordinate->plusPlus();
        }
        break;
      default:
        break;
      }
      lcdMenuPrinting.renewAllCoordiinates(robotCoordinatesInMenu.getX(),
                                           robotCoordinatesInMenu.getY(),
                                           robotCoordinatesInMenu.getFi(),
                                           robotCoordinatesInMenu.getV(),
                                           furnanceCoordinates.getLift(),
                                           furnanceCoordinates.getLiftFloor(),
                                           furnanceCoordinates.getDoors(),
                                           furnanceCoordinates.getStand(),
                                           temperatureCoordinates.getHighTemperature(),
                                           temperatureCoordinates.getLowTemperature(),
                                           temperatureCoordinates.getNowTemperature());

      Serial.print("x=" + String(robotCoordinatesInMenu.getX()));
      Serial.print("\ty=" + String(robotCoordinatesInMenu.getY()));
      Serial.print("\tfi=" + String(robotCoordinatesInMenu.getFi()));
      Serial.print("\tv=" + String(robotCoordinatesInMenu.getV()));
      Serial.print("\tlift=" + String(furnanceCoordinates.getLift()));
      Serial.print("\tdoors=" + String(furnanceCoordinates.getDoors()));
      Serial.print("\tstand=" + String(furnanceCoordinates.getStand()));
      Serial.print("\thT=" + String(temperatureCoordinates.getHighTemperature()));
      Serial.println("\tlT=" + String(temperatureCoordinates.getLowTemperature()));
    }
  }
}