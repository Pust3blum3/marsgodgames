#pragma once

#include "Vektoria\root.h"

using namespace Vektoria;

class CAudioManager
{

public:

	CAudioManager();
	~CAudioManager();

	//Initialisiert alle Audio-Objekte
	void Init(CScene*);

	//Alle Audio-Elemente sind public f�r einfacheren Zugriff; unsch�n, aber (eh) unausweichlich
	CAudio Ambient_Background_Music;
	CAudio Ambient_Building_Sound;
	CAudio Ambient_Click_Sound;



};

