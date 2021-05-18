#pragma once
#include <unordered_set>
#include <string>

namespace LevelSystem
{
	class Level
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="maximumexperience">Erfahrung f�r n�chsten Aufstieg</param>
		Level(int maximumexperience);

		/// <summary>
		/// F�gt Erfahrung hinzu - Gibt �berfluss der Erfahrung zur�ck zur�ck
		/// </summary>
		/// <param name="experience">Erfahrung</param>
		/// <returns>�berfluss</returns>
		int AddExperience(int experience);

		/// <summary>
		/// F�gt zu entsperrendes Objekt hinzu
		/// </summary>
		/// <param name="typeinfo">Typ (typeid(Object).name)</param>
		void AddLockedObject(std::string typeinfo);

		/// <summary>
		/// Gibt alle zu entsperrende Objekte zur�ck
		/// </summary>
		/// <returns>zu entsperrende Objekte</returns>
		std::unordered_set<std::string> GetLockedObjects();

	private:

		std::unordered_set<std::string> _lockedObjects;

		int _currentExperience;
		int _maxExperience;

	};
}
