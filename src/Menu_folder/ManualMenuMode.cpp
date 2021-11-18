#include "../include/Menu_folder/ManualMenuMode.h"

ManualMenuMode::ManualMenuMode(MenuOnLCD *menuOnLCD)
    : MenuMode(menuOnLCD),
      pCoordinateChange(NULL),
      xCoordinateChange("x", &pRobotCoordinates->x, -10, -1, 1, 10),
      yCoordinateChange("y", &pRobotCoordinates->y, -10, -1, 1, 10),
      fiCoordinateChange("fi", &pRobotCoordinates->fi, -10, -1, 1, 10),
      vCoordinateChange("v", &pRobotCoordinates->v, -2, -1, 1, 2),
      liftCoordinateChange("lift", &pFurnaceCoordinates->lift, -10, -1, 1, 10),
      liftFloorCoordinateChange("liftFloor", &pFurnaceCoordinates->liftFloor, -1, -1, 1, 1),
      doorsCoordinateChange("doors", &pFurnaceCoordinates->doors),
      standCoordinateChange("stand", &pFurnaceCoordinates->stand),
      highTemperatureCoordinateChange("highTemperature", &pTemperatureCoordinates->highTemperature, -50, -5, 5, 50),
      lowTemperatureCoordinateChange("lowTemperature", &pTemperatureCoordinates->lowTemperature, -50, -5, 5, 50)

{
}
void ManualMenuMode::printConstPartOfMode()
{
    Serial.println("pMenuOnLCD.printConstPartOfManualMode()");
    pMenuOnLCD->printConstPartOfManualMode();
    pMenuOnLCD->printAllCoordiinates();
}
void ManualMenuMode::doMenu()
{

    processTheFirstKeypad();
    pMenuOnLCD->renewAllCoordiinates();

    // Serial.print("x=" + String(pRobotCoordinates->x.getValue()));
    // Serial.print("\ty=" + String(pRobotCoordinates->y.getValue()));
    // Serial.print("\tfi=" + String(pRobotCoordinates->fi.getValue()));
    // Serial.print("\tv=" + String(pRobotCoordinates->v.getValue()));
    // Serial.print("\tlift=" + String(pFurnaceCoordinates->lift.getValue()));
    // Serial.print("\tdoors=" + String(pFurnaceCoordinates->doors));
    // Serial.print("\tstand=" + String(pFurnaceCoordinates->stand));
    // Serial.print("\thT=" + String(pTemperatureCoordinates->highTemperature.getValue()));
    // Serial.println("\tlT=" + String(pTemperatureCoordinates->lowTemperature.getValue()));
    // Serial.println();
}
void ManualMenuMode::processTheFirstKeypad()
{
    if (firstKeypad->keyIsPressed())
    {
        _levelOfManualMode = CHANGE_COORDINATE;
        NamesOfFirstKeypadsKeys nameOfKey = firstKeypad->getNameOfKey();
        Serial.println(String(nameOfKey) + " is pressed");
        switch (nameOfKey)
        {
        case X:
            pCoordinateChange = &xCoordinateChange;
            break;
        case Y:
            pCoordinateChange = &yCoordinateChange;
            break;
        case FI:
            pCoordinateChange = &fiCoordinateChange;
            break;
        case V:
            pCoordinateChange = &vCoordinateChange;
            break;
        case LIFT:
            pCoordinateChange = &liftCoordinateChange;
            break;
        case DOORS:
            pCoordinateChange = &doorsCoordinateChange;
            break;
        case STAND:
            pCoordinateChange = &standCoordinateChange;
            break;
        case TEMPERATURE:
            if (pToggleFurnaceModes->getMode() == "HIGH")
            {
                Serial.println("HIGH TEMPERATURE");
                pCoordinateChange = &highTemperatureCoordinateChange;
            }
            else if (pToggleFurnaceModes->getMode() == "LOW")
            {
                Serial.println("LOW TEMPERATURE");
                pCoordinateChange = &lowTemperatureCoordinateChange;
            }
            else
            {
                pCoordinateChange = &highTemperatureCoordinateChange;
            }
            break;
        case MINUS_MINUS:
            if (pCoordinateChange != NULL)
            {
                pCoordinateChange->minusMinus();
                Serial.println("Do minus-minus");
            }
            break;
        case MINUS:
            if (pCoordinateChange != NULL)
            {
                pCoordinateChange->minus();
            }
            break;
        case PLUS:
            if (pCoordinateChange != NULL)
            {
                pCoordinateChange->plus();
            }
            break;
        case PLUS_PLUS:
            if (pCoordinateChange != NULL)
            {
                pCoordinateChange->plusPlus();
            }
            break;
        default:
            break;
        }
        pMenuOnLCD->setCursorAndBlinc(pCoordinateChange->getNameOfCoordinate());
    }
}