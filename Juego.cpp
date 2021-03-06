#pragma once
#include<iostream>
using namespace std;
#include<stdio.h>
#include<conio.h>
#include "Windows.h"
#include "Nodo.cpp"
#include "Tabla.cpp"
#include "Sistema.cpp"
#pragma warning (disable: 4309)//desabilita los warnings es como IOException

class Juego{
private:
//-------------------------------Atributos-------------------------------------------
	Sistema s;
	Tabla *t;
public:
//-------------------------------Metodos------------------------------------------------
	Juego(){
		t = new Tabla();//instancia un obejeto tipo tabla
	}
	void ImprimirFicha(Tabla *t1){//imprime la ficha usando gotoxy
		int x=25;//valores iniciales para el gotoxy
		int y=7;
		int valor=0;//valor del nodo
		char p1=207;//ficha 1 y 2
		char p2=248;
		Nodo *aux1,*aux2;
		aux1=t1->dummy->getRight();
		aux2=aux1;
		while(aux2!=NULL){
			valor=aux1->getContenido();
			switch (valor){
				case 1://si es 1 meta una x q es valor de las negras
					s.gotoxy(x,y);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					cout<<p1;
					break;
				case 2:// si es 2 meta un o que es valor de blancas
					s.gotoxy(x,y);					
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
					cout<<p2;
					break;
				case 0://si no esta vacio
					s.gotoxy(x,y);
					cout<<" ";
					break;
			}
			aux1=aux1->getRight();
			x+=4;
			if(aux1==NULL){//en caso de ser null avance abajo y actualice los gotoxy
				aux1=aux2->getDown();
				aux2=aux1;
				y+=2;
				x=25;
			}
		}
	}

	void ImprimirTablero(){		
		char dib1=201;//╔
		char dib2=187;//╗
		char dib3=200;//╚
		char dib4=188;//╝
		char dib5=205;//═
		char dib6=206;//╬
		char dib7=204;//╠
		char dib8=185;//╣
		char dib9=186;//║
		char dib10=203;//╦
		char dib11=202;//╩
		s.gotoxy(23,6);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout<<dib1<<dib5<<dib5<<dib5<<dib10<<dib5<<dib5<<dib5
			<<dib10<<dib5<<dib5<<dib5<<dib10<<dib5<<dib5<<dib5
			<<dib10<<dib5<<dib5<<dib5<<dib10<<dib5<<dib5<<dib5
			<<dib10<<dib5<<dib5<<dib5<<dib10<<dib5<<dib5<<dib5<<dib2;
		s.gotoxy(23,7);
		cout<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9
			<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9;
		s.gotoxy(23,8);
		cout<<dib7<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5<<dib8;
		s.gotoxy(23,9);
		cout<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9
			<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9;
		s.gotoxy(23,10);
		cout<<dib7<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5<<dib8;
		s.gotoxy(23,11);
		cout<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9
			<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9;
		s.gotoxy(23,12);
		cout<<dib7<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5<<dib8;
		s.gotoxy(23,13);
		cout<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9
			<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9;
		s.gotoxy(23,14);
		cout<<dib7<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5<<dib8;
		s.gotoxy(23,15);
		cout<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9
			<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9;
		s.gotoxy(23,16);
		cout<<dib7<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5<<dib8;
		s.gotoxy(23,17);
		cout<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9
			<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9;
		s.gotoxy(23,18);
		cout<<dib7<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
			<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5<<dib8;
		s.gotoxy(23,19);
		cout<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9
			<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9;
		s.gotoxy(23,20);
		cout<<dib7<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
		<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
		<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5
		<<dib6<<dib5<<dib5<<dib5<<dib6<<dib5<<dib5<<dib5<<dib8;
		s.gotoxy(23,21);

		cout<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9
		<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9<<"   "<<dib9;
		s.gotoxy(23,22);
		cout<<dib3<<dib5<<dib5<<dib5<<dib11<<dib5<<dib5<<dib5
		<<dib11<<dib5<<dib5<<dib5<<dib11<<dib5<<dib5<<dib5
		<<dib11<<dib5<<dib5<<dib5<<dib11<<dib5<<dib5<<dib5
		<<dib11<<dib5<<dib5<<dib5<<dib11<<dib5<<dib5<<dib5<<dib4;
	}

	void turnoPartida(){//determina el turno del jugador, imprime el tablero y hace el calculo de fichas de cada uno
		int x=0;
		int y=0;
		int i=0;
		int turno=1;
		int primera=1;
		Nodo *au;
		Nodo *au2;
		cout<<endl;
		s.gotoxy(23,23);
		do{
			system("cls");
			this->ImprimirTablero();//imprime tablero
			this->ImprimirFicha(t);//imprime la ficha
			s.gotoxy(10,5);//coloca en 10 pixeles eje x y 5 pixeles eje y
			turno=turno%2;//determina el turuno de cada uno
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);//color rojo
			cout<<endl<<"Negras(X): "<<this->t->fichaNegra<<endl;//contadores
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);//color blanco
			cout<<endl<<"Blancas(O): "<<this->t->fichaBlanca<<endl<<endl;//contadores
			if(turno==1){//si es negra
				s.gotoxy(5,2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	            cout<<"Es el turno de las negras..."<<endl;
				au=s.Cursor(t);//cursor en el primer nodo				
				au2=t->dummy->getRight();//vea a la primera posicion de la tabla
				if(ganadorB(t,au)==true){//verifica ganador
					if(t->Valida(au,turno)>0){//si es una posicion valida
						t->Guarda_Pieza(au,turno);//guarde el contenido d ela pieza
						t->invierteNodo(au,turno);//inverte el contedio de las demas
						system("cls");
						this->ImprimirTablero();// dibuje tablreo y ficha
						this->ImprimirFicha(t);
						turno+=1;//pase de turno
						i++;
						CalculoFichasNegras(t,au);//actualice los contadores
						CalculoFichasBlancas(t,au);
					}else{//sino es valido
						s.gotoxy(5,3);
						cout<<"Posicion Invalida";
						cin.get();
						turno+=1;//pase el turno
						i++;
						this->ImprimirTablero();
						this->ImprimirFicha(t);	
						CalculoFichasNegras(t,au);
						CalculoFichasBlancas(t,au);
					}
				}else{
					CalculoFichasNegras(t,au);
					CalculoFichasBlancas(t,au);
					if(this->t->fichaBlanca>this->t->fichaNegra){
						system("cls");
						s.gotoxy(5,2);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
						cout<<"Ganan las blancas"<<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
						cout<<endl<<"Negras(X): "<<this->t->fichaNegra<<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
						cout<<endl<<"Blancas(O): "<<this->t->fichaBlanca<<endl<<endl;
						system("pause");
						system("exit");
					}else{
						system("cls");
						s.gotoxy(5,2);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
						cout<<"Ganan las Negras"<<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
						cout<<endl<<"Negras(X): "<<this->t->fichaNegra<<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
						cout<<endl<<"Blancas(O): "<<this->t->fichaBlanca<<endl<<endl;
						system("pause");
						system("exit");
					}
				}
			}
			if(turno==0){
				s.gotoxy(5,2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
	            cout<<"Es el turno de las blancas..."<<endl;
				au=s.Cursor(t);
				if(ganadorN(t,au)==true){
					if(t->Valida(au,turno)>0){	
						t->Guarda_Pieza(au,turno);
						t->invierteNodo(au,turno);
						system("cls");
						this->ImprimirTablero();
						this->ImprimirFicha(t);
						turno+=1;
						i++;
						CalculoFichasBlancas(t,au);
						CalculoFichasNegras(t,au);
					}else{
						s.gotoxy(5,3);
						cout<<"Posicion Invalida";
						cin.get();
						turno+=1;
						i++;
						this->ImprimirTablero();
						this->ImprimirFicha(t);
						CalculoFichasNegras(t,au);
						CalculoFichasBlancas(t,au);
					}
				}else{
					CalculoFichasNegras(t,au);
					CalculoFichasBlancas(t,au);
						if(this->t->fichaBlanca>this->t->fichaNegra){
							system("cls");
							s.gotoxy(5,2);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
							cout<<"Ganan las blancas"<<endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
							cout<<endl<<"Negras(X): "<<this->t->fichaNegra<<endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
							cout<<endl<<"Blancas(O): "<<this->t->fichaBlanca<<endl<<endl;
							system("pause");
							system("exit");
						}else{
							system("cls");
							s.gotoxy(5,2);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
							cout<<"Ganan las Negras"<<endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
							cout<<endl<<"Negras(X): "<<this->t->fichaNegra<<endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
							cout<<endl<<"Blancas(O): "<<this->t->fichaBlanca<<endl<<endl;
							system("pause");
							system("exit");
						}
				}
			}
		}while(i<64);
		s.gotoxy(5,3);
		cout<<"NO hay mas Posiciones validas";
	}

	void CalculoFichasNegras(Tabla* t, Nodo* inicio){
		Nodo* aux = t->dummy->Right;//dummy vea al primero
		Nodo* aux2 = aux;
		t->fichaNegra = 0;

		for(int i = 0; i<8; i++){//for de filas
			for(int j = 0; j<8; j++){//for columnas
				if(aux2->contenido == 1){//si son negras
					t->fichaNegra = t->fichaNegra+1;// sume y avance
					aux2 = aux2->Right;
				}else{//si no solo avance
					aux2 = aux2->Right;
				}
			}//conto la primer fila
			aux = aux->Down;//avance abajo
			aux2 = aux;//actualize a aux 2 para que quede en la primera posicion
		}
	}

	void CalculoFichasBlancas(Tabla* t, Nodo* inicio){
		Nodo* aux = t->dummy->Right;
		Nodo* aux2 = aux;
		t->fichaBlanca = 0;

		for(int i = 0; i<8; i++){
			for(int j = 0; j<8; j++){
				if(aux2->contenido == 2){
					t->fichaBlanca = t->fichaBlanca+1;
					aux2 = aux2->Right;
				}else{
					aux2 = aux2->Right;
				}
			}
			aux = aux->Down;
			aux2 = aux;
		}
	}

	bool ganador(Tabla* t, Nodo* inicio){		
		Nodo* aux = t->dummy->Right;
		Nodo* aux2 = aux;
		t->fichaBlanca = 0;
		int estado1=0,estado2=0;

		for(int i = 0; i<8; i++){
			for(int j = 0; j<8; j++){
				if(aux2->contenido == 0){
					estado1=t->Valida(aux2,1);
					estado2=t->Valida(aux2,0);
					if(estado1>0||estado2>0){
						return true;
					}
					aux2 = aux2->Right;
				}else{
					aux2 = aux2->Right;
				}
			}
			aux = aux->Down;
			aux2 = aux;
		}
		return false;
	}

	bool ganadorB(Tabla* t, Nodo* inicio){		
		Nodo* aux = t->dummy->Right;
		Nodo* aux2 = aux;
		int estado1=0,estado2=0;

		for(int i = 0; i<8; i++){
			for(int j = 0; j<8; j++){
				if(aux2->contenido == 0){
					estado2=t->Valida(aux2,0);
					if(estado2>0){
						return true;
					}
					aux2 = aux2->Right;
				}else{
					aux2 = aux2->Right;
				}
			}
			aux = aux->Down;
			aux2 = aux;
		}
		return false;
	}
	bool ganadorN(Tabla* t, Nodo* inicio){
		
		Nodo* aux = t->dummy->Right;
		Nodo* aux2 = aux;
		t->fichaBlanca = 0;
		int estado1=0,estado2=0;

		for(int i = 0; i<8; i++){
			for(int j = 0; j<8; j++){
				if(aux2->contenido == 0){
					estado1=t->Valida(aux2,1);
					if(estado1>0){
						return true;
					}
					aux2 = aux2->Right;
				}else{
					aux2 = aux2->Right;
				}
			}
			aux = aux->Down;
			aux2 = aux;
		}
		return false;
	}

};