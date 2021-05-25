#pragma once
class Player
{
public:

	/// <summary>
	/// Singleton - gibt Instanz zur�ck
	/// </summary>
	/// <returns>Instanz</returns>
	static Player& Instance()
	{
		static Player _instance;
		return _instance;
	};

	void initPlayer(int, int, int);

	void setRessource1(int i) { ressource1 += i; }
	void setRessource2(int i) { ressource2 += i; }
	void setRessource3(int i) { ressource3 += i; }
	int getRessource1() { return ressource1; }
	int getRessource2() { return ressource2; }
	int getRessource3() { return ressource3; }

	void setZufriedenheit1(int);
	void setZufriedenheit2(int);
	void setZufriedenheit3(int);
	int getZufriedenheit1();
	int getZufriedenheit2();
	int getZufriedenheit3();

	int getWohnung() { return WohnungKapa; }
	void setWohnung(int i) { WohnungKapa += i; }

private:

	Player();

	int ressource1;
	int ressource2;
	int ressource3;

	int zufriedenheit1;
	int zufriedenheit2;
	int zufriedenheit3;

	int WohnungKapa = 0;

	
};

