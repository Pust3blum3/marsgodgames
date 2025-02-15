#pragma once
#include "Building.h"
class Hospital :
    public Building
{
public:
    Hospital() {
        PowerUse = 10;
        WaterUse = 5;
        NutrientUse = 6;

        Category = BuildingCategory::Living;

        setModel("models\\monkey.obj");
        // set material
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 50;
        cost.Concrete = 40;
        cost.Wood = 50;
        return cost;
    }
};