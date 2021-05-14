#pragma once
#include "Vektoria/root.h"
#include "GameObject.h"
#include "BeispielForGameObject.h"
#include "CGameObjectPlacement.h"

using namespace Vektoria;

class CBuildingManager
{
public:

	CBuildingManager();
	~CBuildingManager();
	
	// Initialisierung des BuildingManagers
	void Init(CScene*);

	// Sucht nach einem bestimmten GameObjectPlacement
	CGameObjectPlacement* lookForGameObject();

	// Update-Methode der Geb�ude pro Tick
	void UpdateBuildings(float deltaTime);

	void IncreaseNrOfBuildings();
	void DecreaseNrOfBuildings();

	

private:

	CScene* m_zs;

	

	// Zum Test hier die Beispiel GameObject-Klasse
	CGameObjectPlacement BeispielGameObjects[20];

	// F�r jeden Geb�udetyp bzw. f�r jede Kategorie feste Anzahl an Geb�uden
	// Muss noch erweitert werden!
	CGameObjectPlacement Wonhungen[50];
	CGameObjectPlacement Versorgung[50];

	// Die Anzahl an Geb�uden, die schon gebaut wurde
	// F�r Statistik 
	int m_NrOfTestObjects;
	int m_NrOfWohungen;
	int m_NrOfVersorgung;

};

