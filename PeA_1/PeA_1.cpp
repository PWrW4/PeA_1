// PeA_1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "Graph.h"
#include "BruteForce.h"
#include "BranchAndBound.h"
#include "HeldKarp.h"
#include "menu.h"

int main()
{
	new menu;
//	Graph * g = new Graph;
//	g->LoadGraph("tsp_5.txt");
//	g->DrawMatrixSize();
//	g->DrawMatrix();
//
//	BruteForce * BF = new BruteForce(g);
//	BF->Resolve(0);
//	BF->ShowRoute();
//
//	BranchAndBound * BB = new BranchAndBound(g);
//	BB->Resolve();
//	BB->ShowRoute();
//
//	HeldKarp * HK = new HeldKarp(g);
//	HK->Resolve();
//	HK->ShowRoute();
//
//	int a;
//	std::cin >> a;
//
//	system("pause");
	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
