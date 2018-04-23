#pragma once
#include<iostream>
using namespace std;
#include<stdio.h>
#include<conio.h>
#include "Windows.h"
#include "Nodo.cpp"
#include "Tabla.cpp"

class Sistema{
private:	
//-------------------------------Atributos-------------------------------------------
public:
//-------------------------------Metodos------------------------------------------------
	void gotoxy(int x, int y){
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	Nodo* Cursor(Tabla *t1){
		Nodo *aux;
		int x=25;
		int y=7;
		int control=0;
		char tecla;
		gotoxy(x,y);
		aux=t1->dummy->getRight();
		while(control==0){
			tecla=_getch();
			switch(tecla){
				case 72:
					if(x>24&&x<54&&y==7){
						gotoxy(x,y);
					}
					else{
						y-=2;
						gotoxy(x,y);
						aux=aux->getUp();
					}
					break;
				case 80:
					if(x>24&&x<54&&y==21){
						gotoxy(x,y);
					}
					else{
						y+=2;
						gotoxy(x,y);
						aux=aux->getDown();
					}
					break;
				case 77:
					if(y>6&&y<22&&x==53){
						gotoxy(x,y);
					}
					else{
						x+=4;
						gotoxy(x,y);
						aux=aux->getRight();
					}
					break;
				case 75:
					if(y>6&&y<22&&x==25){
						gotoxy(x,y);
					}
					else{
						x-=4;
						gotoxy(x,y);
						aux=aux->getLeft();
					}
					break;
				case 13:
					control=1;
					break;
				default:
					break;
			}
		}

		return aux;
	}
};