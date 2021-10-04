#include "../include/Menu_folder/ManualMenuMode.h"

ManualMenuMode::ManualMenuMode()
{
}

void ManualMenuMode::doMenu()
{
    setTargetMode(toggleKey.getMode());
    if (getCurrentMode() != getTargetMode())
    {
        setCurrentMode(getTargetMode());
        lcdMenuPrinting.printConstPartOfMode(getTargetMode());
        if (getCurrentMode() == "MANUAL")
        {
            lcdMenuPrinting.printAllCoordiinates(&robotCoordinates,
                                                 &furnanceCoordinates,
                                                 &temperatureCoordinates);
        }
    }
    if (getCurrentMode() == "MANUAL")
    {
        processTheFirstKeypad();
        lcdMenuPrinting.renewAllCoordiinates(&robotCoordinates,
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
        lcdMenuPrinting.setCursorAndBlinc(pCoordinateChange->getNameOfCoordinate());
    }
}