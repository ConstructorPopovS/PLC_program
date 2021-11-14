#include "../include/Menu_folder/ManualMenuMode.h"

ManualMenuMode::ManualMenuMode() : pCoordinateChange(NULL),
                                   xCoordinateChange("x", robotCoordinates.getPX(), -10, -1, 1, 10),
                                   yCoordinateChange("y", robotCoordinates.getPY(), -10, -1, 1, 10),
                                   fiCoordinateChange("fi", robotCoordinates.getPFi(), -10, -1, 1, 10),
                                   vCoordinateChange("v", robotCoordinates.getPV(), -2, -1, 1, 2),
                                   liftCoordinateChange("lift", furnanceCoordinates.getPLift(), -10, -1, 1, 10),
                                   liftFloorCoordinateChange("liftFloor", furnanceCoordinates.getPLiftFloor(), -1, -1, 1, 1),
                                   doorsCoordinateChange("doors", furnanceCoordinates.getPDoors()),
                                   standCoordinateChange("stand", furnanceCoordinates.getPStand()),
                                   highTemperatureCoordinateChange("highTemperature", temperatureCoordinates.getPHighTemperature(), -50, -5, 5, 50),
                                   lowTemperatureCoordinateChange("lowTemperature", temperatureCoordinates.getPLowTemperature(), -50, -5, 5, 50)

{
}
void ManualMenuMode::printConstPatrOfMode()
{
    menuOnLCD.printConstPartOfManualMode();
}
void ManualMenuMode::doMenu()
{

        processTheFirstKeypad();
        menuOnLCD.renewAllCoordiinates(&robotCoordinates,
                                             &furnanceCoordinates,
                                             &temperatureCoordinates);

        // Serial.print("x=" + String(robotCoordinates.getX()));
        // Serial.print("\ty=" + String(robotCoordinates.getY()));
        // Serial.print("\tfi=" + String(robotCoordinates.getFi()));
        // Serial.print("\tv=" + String(robotCoordinates.getV()));
        // Serial.print("\tlift=" + String(furnanceCoordinates.getLift()));
        // Serial.print("\tdoors=" + String(furnanceCoordinates.getDoors()));
        // Serial.print("\tstand=" + String(furnanceCoordinates.getStand()));
        // Serial.print("\thT=" + String(temperatureCoordinates.getHighTemperature()));
        // Serial.println("\tlT=" + String(temperatureCoordinates.getLowTemperature()));
        // Serial.println();
}
void ManualMenuMode::processTheFirstKeypad()
{
    if (firstKeypad.keyIsPressed())
    {
        _levelOfManualMode = CHANGE_COORDINATE;
        NamesOfFirstKeypadsKeys nameOfKey = firstKeypad.getNameOfKey();
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
            if (toggleFurnaceMode.getMode() == "HIGH")
            {
                pCoordinateChange = &highTemperatureCoordinateChange;
            }
            else if (toggleFurnaceMode.getMode() == "LOW")
            {
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
        menuOnLCD.setCursorAndBlinc(pCoordinateChange->getNameOfCoordinate());
    }
}