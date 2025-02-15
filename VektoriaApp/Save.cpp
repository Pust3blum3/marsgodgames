#include "Save.h"
//Karo start
Save::Save()
{
	*pos_arr = new float[100];
	
	pos_id = 0;
}

Save::~Save()
{
}

void Save::getObjects()
{
}

void Save::deleteTxt()
{
	remove("Ressources.txt");
	
}

std::string Save::getObjName(GameObject *GO)
{
	std::string objName;
	

	if (dynamic_cast<BeispielForGameObject*>(GO))
	{
		objName = "BeispielForGameObject";
		//ULDebug(objName.c_str());
	}
	else if (dynamic_cast<Apartment*>(GO))
	{
		objName = "Apartment";
		//ULDebug(objName.c_str());
	}
	/*else if (dynamic_cast<Building*>(GO))
	{
		objName = "Building";
		//ULDebug(objName.c_str());
	}*/
	else if (dynamic_cast<ControlCenter*>(GO))
	{
		objName = "ControlCenter";
		//ULDebug(objName.c_str());
	}
	else if (dynamic_cast<FoodFarm*>(GO))
	{
		objName = "FoodFarm";
		//ULDebug(objName.c_str());
	}
	else if (dynamic_cast<Foundry*>(GO))
	{
		objName = "Foundry";
		//ULDebug(objName.c_str());
	}
	else if (dynamic_cast<GravelPlant*>(GO))
	{
		objName = "GavelPlant";
		//ULDebug(objName.c_str());
	}
	else if (dynamic_cast<Hospital*>(GO))
	{
		objName = "Hospital";
		//ULDebug(objName.c_str());
	}
	else if (dynamic_cast<Laboratory*>(GO))
	{
		objName = "Laboratory";
		//ULDebug(objName.c_str());
	}
	else if (dynamic_cast<Launchpad*>(GO))
	{
		objName = "Launchpad";
		//ULDebug(objName.c_str());
	}
	else if (dynamic_cast<Mine*>(GO))
	{
		objName = "Mine";
		//ULDebug(objName.c_str());
	}
	else if (dynamic_cast<NuclearPowerPlant*>(GO))
	{
		objName = "NuclearPowerPlant";
		//ULDebug(objName.c_str());
	}
	else if (dynamic_cast<RobotFactory*>(GO))
	{
		objName = "RobotFactory";
		//ULDebug(objName.c_str());
	}
	else if (dynamic_cast<SolarPowerPlant*>(GO))
	{
		objName = "SolarPowerPlant";
		//ULDebug(objName.c_str());
	}
	else if (dynamic_cast<TreeFarm*>(GO))
	{
		objName = "TreeFarm";
		//ULDebug(objName.c_str());
	}
	else if (dynamic_cast<Well*>(GO))
	{
		objName = "Well";
		//ULDebug(objName.c_str());
	}
	else {
		ULDebug("Failure: Object Name not found.");
		objName = "Fail";
	}
	return objName;
}

void Save::writePosToTxt(std::string file_name, std::string object_name, float x_pos, float z_pos)
{
	std::ofstream file;
	file.open(file_name, std::ios_base::app);
	file << object_name << ", " << x_pos << ", " << z_pos << std::endl;

	file.close();
}

void Save::writeCurrToTxt(std::string file_name, int val1, int val2, int val3)
{
	std::ofstream file;
	file.open(file_name, std::ios_base::app);
	file << val1 << ", " << val2 << ", " << val3 << std::endl;

	file.close();
}

void Save::fillPosAr(GameObject* GO, float x, float z)
{
	std::string obj_class = this->getObjName(GO);
	
	geo_arr[pos_id] = obj_class;
	
	pos_arr[pos_id] = new float[2];
	pos_arr[pos_id][0] = x;
	pos_arr[pos_id][1] = z;
	
	pos_id += 1; 

}

bool Save::saveItAll()
{
	/*if (pos_arr[pos_id][0] == undefined) {
		pos_arr[pos_id][0] = 1.0f;
		pos_arr[pos_id][1] = 1.0f;
	}*/
	ULDebug(geo_arr[0].c_str());
	for (int i = 0; i < pos_id; i++) {
		this->writePosToTxt("Positions.txt", geo_arr[i], pos_arr[i][0], pos_arr[i][1]);
	}

	return true;
}
//Karo start