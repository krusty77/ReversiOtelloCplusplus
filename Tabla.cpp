#pragma once
#include "Nodo.cpp"
#include <iostream>
using namespace std;

class Tabla{//es la clase que me va a funcionar como lista
private:
//-------------------------------Atributos--------------------------------------------
	Nodo* dummy;
	Nodo* primero;
	Nodo* actual;
	int fichaNegra;
	int fichaBlanca;
public:	
//-------------------------------Constructores-----------------------------------------
	Tabla(){
		this->setFichaBlanca(2);
		this->setFichaNegra(2);
		dummy=new Nodo();
		Nodo *aux;
		aux=dummy->Right=Establece_Fila(); //estalbece la primera fila de nodos
		for(int i=0;i<8;i++){//enlaza crea las filas
			Enlaza_Fila(aux,Establece_Fila());
			if(i==2){
				Coloca_en_Medio(i+1,primero)->setContenido(2); //coloca las primeras 4 piezas
				Coloca_en_Medio(i+2,primero)->setContenido(1); //al primero del juego
			}
			if(i==3){
				Coloca_en_Medio(i,primero)->setContenido(1);  //coloca las primeras 4 piezas
				Coloca_en_Medio(i+1,primero)->setContenido(2); //al primero del juego
			}
			aux=primero;
		}
	}
	~Tabla(){}
	
//-------------------------------Setters & Getters--------------------------------------
	void setFichaNegra(int fn){this->fichaNegra = fn;}
	void setFichaBlanca(int fb){this->fichaBlanca = fb;}
	int getFichaNegra(){return this->fichaNegra;}
	int getFichaBlanca(){return this->fichaBlanca;}
	Nodo* getDummy(){return this->dummy;}
	void setDummy(Nodo* pDummy){this->dummy = pDummy;}
//-------------------------------Metodos------------------------------------------------
	int Valida(Nodo *inicio, int J){ //busca si la posicion en la que se quiere insertar la pieza es una posicion valida
		int i=0;
	    int jugador=0; 
		if(J==1){
			jugador=2;
		}
		if(J==0){
			jugador=1;
		}
		if((Revisa_posicion_vacia(inicio)==false)&&inicio->getContenido()==0){
			
			i+=revisaFichaUp(inicio,jugador);
			i+=revisaFichaDown(inicio,jugador);
			i+=revisaFichaRight(inicio,jugador);
			i+=revisaFichaLeft(inicio,jugador);
			i+=revisaFichaDiagUpR(inicio,jugador);
			i+=revisaFichaDiagLowR(inicio,jugador);
            i+=revisaFichaDiagUpL(inicio,jugador);
			i+=revisaFichaDiagLowL(inicio,jugador);
		}
		return i;
	}
	Nodo* Establece_Fila(){
		Nodo *aux=new Nodo(); //crea una lista de 8 nodos
			primero=aux;           //y retorna el primero
			for(int i=0;i<7;i++){
				aux->setRight(new Nodo());
				aux->getRight()->setLeft(aux);
				aux=aux->getRight();
			}
			return primero;
	}

	Nodo* Coloca_en_Medio(int L, Nodo* primero){//se encarga de buscar las filas de en 
			Nodo *aux;//medio para colocar las primeras 4 piezas
			aux=primero;
			for(int k=0;aux->getRight()!=NULL&&k<L;k++){
				aux=aux->getRight();
			}
			return aux;
		}
	void invierteNodo(Nodo *primero, int J){ //cambia el color de la ficha
		int jugador=0;                      
		int pieza=0;                        
		if(J==1){//si es el primer jugador
			jugador=2;//si es negra pongale blanca
			pieza=1;
		}
		if(J==0){
			jugador=1;//si es blanca pongale negra
			pieza=2;
		}
		this->cambioFichaUp(primero,pieza,jugador);//llama a todos lo posibles casos
		this->cambioFichaDown(primero,pieza,jugador);
		this->cambioFichaRight(primero,pieza,jugador);
		this->cambioFichaLeft(primero,pieza,jugador);
		this->cambioFichaDiagLowR(primero,pieza,jugador);
		this->cambioFichaDiagLowL(primero,pieza,jugador);
		this->cambioFichaDiagUpL(primero,pieza,jugador);
		this->cambioFichaDiagUpR(primero,pieza,jugador);
	}
	void Guarda_Pieza(Nodo *Posicion, int Jugador){
		if(Jugador%2==1){
			Posicion->setContenido(1); //guarda en la pocicion del nodo escogida si es el jugador 1 o 2
		}
		else{
		Posicion->setContenido(2);//guarda en la pocicion del nodo escogida si es el jugador 1 o 2
		}
	}

	void Enlaza_Fila(Nodo *aux1, Nodo *aux2){ //enlaza doblemente dos filas del tablero
		Nodo * primero;
		primero=aux1;
		aux1->setDown(aux2);
		aux2->setUp(aux1);

		while(aux1->getRight()!=NULL&&aux2->getRight()!=NULL)
		{
			aux1->setDiagLowR(aux2->getRight());
			aux2->setDiagUpR(aux1->getRight());
			aux1->getRight()->setDiagLowL(aux2);
			aux2->getRight()->setDiagUpL(aux1);
			aux1->getRight()->setDown(aux2->getRight());
			aux2->getRight()->setUp(aux1->getRight());
			aux1=aux1->getRight();
			aux2=aux2->getRight();
		}//Fin while
	}
	bool Revisa_posicion_vacia(Nodo *aux){//valida la posicion vacia
		if((aux->getRight()!=NULL&&aux->getRight()->getContenido()>0)||(aux->getLeft()!=NULL&&aux->getLeft()->getContenido()>0)
		||(aux->getDown()!=NULL&&aux->getDown()->getContenido()>0)||(aux->getUp()!=NULL&&aux->getUp()->getContenido()>0)
		||(aux->getDiagLowR()!=NULL&&aux->getDiagLowR()->getContenido()>0)||(aux->getDiagLowL()!=NULL&&aux->getDiagLowL()->getContenido()>0)
		||(aux->getDiagUpR()!=NULL&&aux->getDiagUpR()->getContenido()>0)||(aux->getDiagUpL()!=NULL&&aux->getDiagUpL()->getContenido()>0)){
		
		return false;
		}
		else {
		return true;
		}
	}

	int Valida_Nodo(Nodo *inicio, int J){ //busca si la posicion en la que se quiere insertar la pieza es una posicion valida
		int i=0;
	    int jugador=0; 
		if(J==1){
			jugador=2;
		}
		if(J==0){
			jugador=1;
		}
		if((Revisa_posicion_vacia(inicio)==false)&&inicio->getContenido()==0){
			
			i+=revisaFichaUp(inicio,jugador);
			i+=revisaFichaDown(inicio,jugador);
			i+=revisaFichaRight(inicio,jugador);
			i+=revisaFichaLeft(inicio,jugador);
			i+=revisaFichaDiagUpR(inicio,jugador);
			i+=revisaFichaDiagLowR(inicio,jugador);
            i+=revisaFichaDiagUpL(inicio,jugador);
			i+=revisaFichaDiagLowL(inicio,jugador);
		}
		return i;
	}



//-------------------------------Metodos_Cambio_Ficha------------------------------------
	void cambioFichaUp(Nodo* n, int ficha, int jugador){//intercambia el valor de la ficha de Arriba
		Nodo* aux = n;
		while(aux->getUp()!=NULL && aux->getUp()->getContenido() == jugador){
			aux=aux->getUp();
		}
		if(aux->getUp()!=NULL && aux->getUp()->getContenido()>0){//valida q sea una posicion correcta
			while(aux!=n){//mientras el auxiliar sea diferente del nodo de parametro ingrese al while
				n->getUp()->setContenido(ficha);//n en el nodo de arriba meta la ficha nueva
				n = n->getUp();//avance para arriba
			}
		}
	}
	void cambioFichaDown(Nodo* n, int ficha, int jugador){//intercambia el valor de la ficha de Abajo
		Nodo* aux = n;
		while(aux->getDown()!=NULL && aux->getDown()->getContenido() == jugador){
			aux=aux->getDown();
		}
		if(aux->getDown()!=NULL && aux->getDown()->getContenido()>0){//valida q sea una posicion correcta
			while(aux!=n){//mientras el auxiliar sea diferente del nodo de parametro ingrese al while
				n->getDown()->setContenido(ficha);//n en el nodo de abajo meta la ficha nueva
				n = n->getDown();//avance para abajo
			}
		}
	}
	void cambioFichaLeft(Nodo* n, int ficha, int jugador){//intercambia el valor de la ficha de la izquierda
		Nodo* aux = n;
		while(aux->getLeft()!=NULL && aux->getLeft()->getContenido() == jugador){
			aux=aux->getLeft();
		}
		if(aux->getLeft()!=NULL && aux->getLeft()->getContenido()>0){//valida q sea una posicion correcta
			while(aux!=n){//mientras el auxiliar sea diferente del nodo de parametro ingrese al while
				n->getLeft()->setContenido(ficha);//n en el nodo de abajo meta la ficha nueva
				n = n->getLeft();//avance para la izquierda
			}
		}
	}
	void cambioFichaRight(Nodo* n, int ficha, int jugador){//intercambia el valor de la ficha de la Derecha
		Nodo* aux = n;
		while(aux->getRight()!=NULL && aux->getRight()->getContenido() == jugador){
			aux=aux->getRight();
		}
		if(aux->getRight()!=NULL && aux->getRight()->getContenido()>0){//valida q sea una posicion correcta
			while(aux!=n){//mientras el auxiliar sea diferente del nodo de parametro ingrese al while
				n->getRight()->setContenido(ficha);//n en el nodo de abajo meta la ficha nueva
				n = n->getRight();//avance para la Derecha
			}
		}
	}

	void cambioFichaDiagUpR(Nodo* n, int ficha, int jugador){//intercambia el valor de la ficha de diagonal Superior Derecha
		Nodo* aux = n;
		while(aux->getDiagUpR()!=NULL && aux->getDiagUpR()->getContenido() == jugador){
			aux=aux->getDiagUpR();
		}
		if(aux->getDiagUpR()!=NULL && aux->getDiagUpR()->getContenido()>0){//valida q sea una posicion correcta
			while(aux!=n){//mientras el auxiliar sea diferente del nodo de parametro ingrese al while
				n->getDiagUpR()->setContenido(ficha);//n en el nodo de abajo meta la ficha nueva
				n = n->getDiagUpR();//avance para la diagonal Superior Derecha
			}
		}
	}
	void cambioFichaDiagLowR(Nodo* n, int ficha, int jugador){//intercambia el valor de la ficha de diagonal Inferior Derecha
		Nodo* aux = n;
		while(aux->getDiagLowR()!=NULL && aux->getDiagLowR()->getContenido() == jugador){
			aux=aux->getDiagLowR();
		}
		if(aux->getDiagLowR()!=NULL && aux->getDiagLowR()->getContenido()>0){//valida q sea una posicion correcta
			while(aux!=n){//mientras el auxiliar sea diferente del nodo de parametro ingrese al while
				n->getDiagLowR()->setContenido(ficha);//n en el nodo de abajo meta la ficha nueva
				n = n->getDiagLowR();//avance para la diagonal Inferior Derecha
			}
		}
	}
	void cambioFichaDiagUpL(Nodo* n, int ficha, int jugador){//intercambia el valor de la ficha de diagonal Superior Izquierda
		Nodo* aux = n;
		while(aux->getDiagUpL()!=NULL && aux->getDiagUpL()->getContenido() == jugador){
			aux=aux->getDiagUpL();
		}
		if(aux->getDiagUpL()!=NULL && aux->getDiagUpL()->getContenido()>0){//valida q sea una posicion correcta
			while(aux!=n){//mientras el auxiliar sea diferente del nodo de parametro ingrese al while
				n->getDiagUpL()->setContenido(ficha);//n en el nodo de abajo meta la ficha nueva
				n = n->getDiagUpL();//avance para la diagonal Superior Izquierda
			}
		}
	}
	void cambioFichaDiagLowL(Nodo* n, int ficha, int jugador){//intercambia el valor de la ficha de diagonal inferior Izquierda
		Nodo* aux = n;
		while(aux->getDiagLowL()!=NULL && aux->getDiagLowL()->getContenido() == jugador){
			aux=aux->getDiagLowL();
		}
		if(aux->getDiagLowL()!=NULL && aux->getDiagLowL()->getContenido()>0){//valida q sea una posicion correcta
			while(aux!=n){//mientras el auxiliar sea diferente del nodo de parametro ingrese al while
				n->getDiagLowL()->setContenido(ficha);//n en el nodo de abajo meta la ficha nueva
				n = n->getDiagLowL();//avance para la diagonal Inferior Izquierda
			}
		}
	}
//-------------------------------Metodos_Revisa_Ficha------------------------------------

	int revisaFichaUp(Nodo* n, int jugador){
		int valor = 0;
		Nodo* aux = n;

		if(aux->getUp()!=NULL){
			while(aux->getUp()!=NULL && aux->getUp()->getContenido() == jugador){
				aux=aux->getUp();
				valor++;
			}
			if(aux->getUp()!=NULL){
				if(aux->getUp()->getContenido()>0){
					return valor;
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}
	int revisaFichaDown(Nodo* n, int jugador){
		int valor = 0;
		Nodo* aux = n;
		if(aux->getDown()!=NULL){
			while(aux->getDown()!=NULL && aux->getDown()->getContenido() == jugador){
				aux=aux->getDown();
				valor++;
			}
			if(aux->getDown()!=NULL){
				if(aux->getDown()->getContenido()>0){
					return valor;
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}
	int revisaFichaLeft(Nodo* n, int jugador){
		int valor = 0;
		Nodo* aux = n;
		if(aux->getLeft()!=NULL){
			while(aux->getLeft()!=NULL && aux->getLeft()->getContenido() == jugador){
			aux=aux->getLeft();
			valor++;
			}
			if(aux->getLeft()!=NULL){
				if(aux->getLeft()->getContenido()>0){
					return valor;
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}
	int revisaFichaRight(Nodo* n, int jugador){
		int valor = 0;
		Nodo* aux = n;
		if(aux->getRight()!=NULL){
			while(aux->getRight()!=NULL && aux->getRight()->getContenido() == jugador){
				aux=aux->getRight();
				valor++;
			}
			if(aux->getRight()!=NULL){
				if(aux->getRight()->getContenido()>0){
					return valor;
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}
		else{
			return 0;
		}
	}
	int revisaFichaDiagUpR(Nodo* n, int jugador){
		int valor = 0;
		Nodo* aux = n;
		if(aux->getDiagUpR()!=NULL){
			while(aux->getDiagUpR()!=NULL && aux->getDiagUpR()->getContenido() == jugador){
				aux=aux->getDiagUpR();
				valor++;
			}
			if(aux->getRight()!=NULL){
				if(aux->getDiagUpR()!=NULL){
					if(aux->getDiagUpR()->getContenido()>0){
						return valor;
					}else{
						return 0;
					}
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}
	int revisaFichaDiagLowR(Nodo* n, int jugador){
		int valor = 0;
		Nodo* aux = n;
		if(aux->getDiagLowR()!=NULL){
			while(aux->getDiagLowR()!=NULL && aux->getDiagLowR()->getContenido() == jugador){
				aux=aux->getDiagLowR();
				valor++;
			}
			if(aux->getDiagLowR()!=NULL){
				if(aux->getDiagLowR()->getContenido()>0){
			      return valor;
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}
	int revisaFichaDiagUpL(Nodo* n, int jugador){
		int valor = 0;
		Nodo* aux = n;
		if(aux->getDiagUpL()!=NULL){
			while(aux->getDiagUpL()!=NULL && aux->getDiagUpL()->getContenido() == jugador){
				aux=aux->getDiagUpL();
				valor++;
			}
			if(aux->getDiagUpL()!=NULL){
				if(aux->getDiagUpL()->getContenido()>0){
					return valor;
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}
	}
	int revisaFichaDiagLowL(Nodo* n, int jugador){
		int valor = 0;
		Nodo* aux = n;
		if(aux->getDiagLowL()!=NULL){
			while(aux->getDiagLowL()!=NULL && aux->getDiagLowL()->getContenido() == jugador){
				aux=aux->getDiagLowL();
				valor++;
			}
			if(aux->getDiagLowL()!=NULL){
				if(aux->getDiagLowL()->getContenido()>0){
					return valor;
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}
	
	friend class Sistema;
	friend class Juego;
};