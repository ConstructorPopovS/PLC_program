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
    if (getCurrentMode() == "MANUAL")
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
            case TEMPERATURE:
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
                else
                {
                    pUpdateCoordinate = &highTemperatureUpdateCoordinate;
                    lcdMenuPrinting.setCursorAndBlinc("highTemperature");
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