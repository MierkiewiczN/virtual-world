#pragma once
class Swiat;
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string>
#define PX 0
#define PY 1

using namespace std;
class Organizm
{
public:
	virtual void akcja() = 0;
	virtual Organizm* kolizja() = 0;
	char rysowanie() { return symbol; };
	int getX() { return polozenie[PX]; };
	int getY() { return polozenie[PY]; };
	virtual string getNazwa() = 0;
	virtual bool czyOdparlAtak(Organizm* organizm) = 0;
	virtual void przesunNaWolneMiejsce() = 0;
	void zwiekszWiek() { wiek++; };
	void setId(int id) { this->id = id; };
	int getId() { return id; };
	int getSila() { return sila; };
	int getWiek() { return wiek; };
	int getInicjatywa() { return inicjatywa; };
	virtual ~Organizm();
protected:
	int sila;
	int inicjatywa;
	int polozenie[2];
	int wczesniejsze_polozenie[2];
	char symbol;
	Swiat* swiat;
	int wiek=0;
	int id;
	string nazwa;
};