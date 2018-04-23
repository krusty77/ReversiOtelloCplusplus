#pragma once
#include <iostream>

class Nodo{
private:
//-------------------------------Atributos-------------------------------------------
	Nodo* Up;//Arriba
	Nodo* Down;//Abajo
	Nodo* Left;//Izquierda
	Nodo* Right;//Derecha
	Nodo* DiagUpR;//Diagonal Superior Derecha
	Nodo* DiagLowR;//Diagonal Inferior Derecha
	Nodo* DiagUpL;//Diagonal Superior Izquierda
	Nodo* DiagLowL;//Diagonal Inferior Izquierda
	int contenido;//estado de la ficha, 1 negro, 2 blanca, 0 vacia

public:	
//-------------------------------Constructores-----------------------------------------
	Nodo(){
	 this->setUp(NULL);
	 this->setDown(NULL);
	 this->setLeft(NULL);
	 this->setRight(NULL);
	 this->setDiagUpR(NULL);
	 this->setDiagLowR(NULL);
	 this->setDiagUpL(NULL);
	 this->setDiagLowL(NULL);
	 this->setContenido(0);
	}
	~Nodo(){}
	
//-------------------------------Setters & Getters----------------------------------------

	void setUp(Nodo* u){this->Up = u;}
	void setDown(Nodo* d){this->Down = d;}
	void setLeft(Nodo* l){this->Left = l;}
	void setRight(Nodo* r){this->Right = r;}
	void setDiagUpR(Nodo* dur){this->DiagUpR = dur;}
	void setDiagLowR(Nodo* dlr){this->DiagLowR = dlr;}
	void setDiagUpL(Nodo* dul){this->DiagUpL = dul;}
	void setDiagLowL(Nodo* dll){this->DiagLowL = dll;}
	void setContenido(int c){this->contenido = c;}

	Nodo* getUp(){return this->Up;}
	Nodo* getDown(){return this->Down;}
	Nodo* getLeft(){return this->Left;}
	Nodo* getRight(){return this->Right;}
	Nodo* getDiagUpR(){return this->DiagUpR;}
	Nodo* getDiagLowR(){return this->DiagLowR;}
	Nodo* getDiagUpL(){return this->DiagUpL;}
	Nodo* getDiagLowL(){return this->DiagLowL;}	
	int getContenido(){return this->contenido;}
	friend class Tabla;
	friend class Sistema;
	friend class Juego;
};