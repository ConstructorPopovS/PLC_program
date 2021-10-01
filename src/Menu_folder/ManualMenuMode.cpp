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
        if (dataFromKeypad.keyIsPressed())
        {
            NamesOfKeys nameOfKey = dataFromKeypad.getNameOfKey();
            Serial.println(String(nameOfKey) + " is pressed");
            switch (nameOfKey)
            {
            case X:
                pCoordinateChange = &xCoordinateChange;
                lcdMenuPrinting.setCursorAndBlinc("x");
                break;
            case Y:
                pCoordinateChange = &yCoordinateChange;
                lcdMenuPrinting.setCursorAndBlinc("y");
                break;
            case FI:
                pCoordinateChange = &fiCoordinateChange;
                lcdMenuPrinting.setCursorAndBlinc("fi");
                break;
            case V:
                pCoordinateChange = &vCoordinateChange;
                lcdMenuPrinting.setCursorAndBlinc("v");
                break;
            case LIFT:
                pCoordinateChange = &liftCoordinateChange;
                lcdMenuPrinting.setCursorAndBlinc("lift");
                break;
            case DOORS:
                pCoordinateChange = &doorsCoordinateChange;
                lcdMenuPrinting.setCursorAndBlinc("doors");
                break;
            case STAND:
                pCoordinateChange = &standCoordinateChange;
                lcdMenuPrinting.setCursorAndBlinc("stand");
                break;
            case TEMPERATURE:
                if (toggleFurnaceMode.getMode() == "HIGH")
                {
                    pCoordinateChange = &highTemperatureCoordinateChange;
                    lcdMenuPrinting.setCursorAndBlinc("highTemperature");
                }
                else if (toggleFurnaceMode.getMode() == "LOW")
                {
                    pCoordinateChange = &lowTemperatureCoordinateChange;
                    lcdMenuPrinting.setCursorAndBlinc("lowTemperature");
                }
                else
                {
                    pCoordinateChange = &highTemperatureCoordinateChange;
                    lcdMenuPrinting.setCursorAndBlinc("highTemperature");
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
            lcdMenuPrinting.renewAllCoordiinates(&robotCoordinates,
                                                 &furnanceCoordinates,
                                                 &temperatureCoordinates);

            Serial.print("x=" + String(robotCoordinates.getX()));
            Serial.print("\ty=" + String(robotCoordinates.getY()));
            Serial.print("\tfi=" + String(robotCoordinates.getFi()));
            Serial.print("\tv=" + String(robotCoordinates.getV()));
            Serial.print("\tlift=" + String(furnanceCoordinates.getLift()));
            Serial.print("\tdoors=" + String(furnanceCoordinates.getDoors()));
            Serial.print("\tstand=" + String(furnanceCoordinates.getStand()));
            Serial.print("\thT=" + String(temperatureCoordinates.getHighTemperature()));
            Serial.println("\tlT=" + String(temperatureCoordinates.getLowTemperature()));
            Serial.println();
        }
    }
}