#pragma once

#include <vector>
#include "Action.h"
#include "Decision.h"
#include "Transition.h"

namespace AI
{
	//Deklaration, da gegenseitige Refenzierung in C++
	class Transition;

	/// <summary>
	/// Klasse f�r Zust�nde
	/// </summary>
	class State
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		State();

		/// <summary>
		/// Ausf�hrung und Aktualisierung von Aktionen und Entscheidungen
		/// </summary>
		/// <param name="timeDelta">Zeitspanne seit letztem Aufruf der Funktion</param>
		void Update(float timeDelta);

		/// <summary>
		/// F�gt Aktion an (Reihenfolge bestimmt Abfolge)
		/// </summary>
		/// <param name="">Aktion, die angef�gt werden soll</param>
		void AddAction(Action*);
		/// <summary>
		/// F�gt �bergang an (Reihenfolge bestimmt Priorit�t, wenn mehrere Entscheidungen gleichzeitig zutreffen)
		/// </summary>
		/// <param name="">�bergang, der angef�gt werden soll</param>
		void AddTransition(Transition*);

		/// <summary>
		/// Gebe n�chsten Zustand anhand zutreffender Entscheidungen aus (nullptr, wenn keine Entscheidung)
		/// </summary>
		/// <returns>N�chster Zustand</returns>
		State* GetNextState();

	private:

		/// <summary>
		/// Liste aller Aktionen
		/// </summary>
		std::vector<Action*> _Actions;
		/// <summary>
		/// Liste aller �berg�nge
		/// </summary>
		std::vector<Transition*> _Transitions;

		/// <summary>
		/// N�chster Zustand (wird gesetzt, wenn Entscheidung zutrifft, ansonsten nullptr)
		/// </summary>
		State* _NextState;

		/// <summary>
		/// Ausf�hrung und Aktualisierung von Aktionen
		/// </summary>
		void UpdateActions();
		/// <summary>
		/// Ausf�hrung und Aktualisierung von �berg�ngen
		/// </summary>
		void UpdateTransitions();

	};

	/// <summary>
	/// Klasse f�r �berg�nge
	/// </summary>
	class Transition
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="">Entscheidung, die zutreffen soll</param>
		/// <param name="">Zustand, der auf Entscheidung folgen soll</param>
		Transition(Decision*, State*);

		/// <summary>
		/// Werte Entscheidung aus
		/// </summary>
		/// <returns>Entscheidungsergebnis</returns>
		bool Decide();

		/// <summary>
		/// Gibt Zustand aus
		/// </summary>
		/// <returns>Zustand</returns>
		State* GetNextState();

	private:

		/// <summary>
		/// Entscheidung, die ausgewertet wird
		/// </summary>
		Decision* _Decision;
		/// <summary>
		/// Zustand, der eintreffen soll
		/// </summary>
		State* _State;

	};
}
