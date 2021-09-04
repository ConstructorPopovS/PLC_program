//подключение функций из других файлов
// #include "Robot_folder/RobotClass.h"
#include "main.h"

#include "../include/Console_folder/Toggle_folder/ToggleWithKey.h"

#include "../include/CoordinateClasses_folder/MenuCoordinates.h"
#include "../include/CoordinateClasses_folder/CoordinateShownOnLCD_folder/CoordinateShownOnLCD.h"
#include "../include/LCD_folder/LCDClass.h"
#include "../include/Console_folder/Keypad_folder/GetDataFromKeypad.h"
#include "../include/Console_folder/Toggle_folder/ToggleFurnaceModes.h"

ToggleWithKey toggleKey;
const String firstOnLCD[4] = {"       MANUAL       ",
                              "M(    ;    ;    )v  ",
                              "L( ):    ;D:  ;S:  ;",
                              "Ht:    ;Lt:    ;    "};
LCDClass lcd;
MenuCoordinates currentMenu;
MenuCoordinates targetMenu;

CoordinateShownOnLCD rCoordinatesOnLCD;
CoordinateShownOnLCD xOnLCD("x", "    ", 1, 2);
CoordinateShownOnLCD yOnLCD("y", "    ", 1, 7);
CoordinateShownOnLCD fiOnLCD("fi", "    ", 1, 12);
CoordinateShownOnLCD vOnLSD("v", "  ", 1, 18);
CoordinateShownOnLCD coordinatesOnLCD[4] =
    {xOnLCD, yOnLCD, fiOnLCD, vOnLSD};

// Robot robot(1, 2, 3, &Serial1, 4, 1000000L); //TODO 1000000L change to long(1000000) and tested
void setup(void)
{
  Serial.begin(9600);
  Serial.setTimeout(70); //установка времени для считывания из порта
  Serial.println("Start");
  lcd.init();
  lcd.clearSetCursorAndPrint(0, 0, "Start");
  delay(1000);
}

/*--------------------------------------------------------------------*/
void loop(void)
{
  currentMenu.setMode(toggleKey.getMode());
  if (currentMenu.getMode() != targetMenu.getMode())
  {
    targetMenu.setMode(currentMenu.getMode());
    lcd.clear();
    if (currentMenu.getMode() == "MANUAL")
    {
      for (int i = 0; i < 4; i++)
      {
        lcd.setCursorAndPrint(0, i, firstOnLCD[i]);
      }
      for (int i = 0; i < 4; i++)
      {
        rCoordinatesOnLCD = coordinatesOnLCD[i];
        lcd.setCursorAndPrint(rCoordinatesOnLCD.getCoordinateColumn(),
                              rCoordinatesOnLCD.getCoordinateRow(),
                              rCoordinatesOnLCD.getName());
      }
    }
    else if (currentMenu.getMode() == "AUTOPILOT")
    {
      lcd.setCursorAndPrint(0, 0, "AUTOPILOT");
    }
    else if (currentMenu.getMode() == "NULL")
    {
      lcd.setCursorAndPrint(0, 0, "TURN ON THE KEY");
    }
  }
}