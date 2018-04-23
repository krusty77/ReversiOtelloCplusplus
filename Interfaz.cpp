#pragma once
#include "Juego.cpp"

class Interfaz{
private:
	Juego j;
public:
	Interfaz(){
		this->jugar();//llama a jugar
	}

	void presentacion(){
		cout<<endl<<endl<<endl;		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);	
		cout<<"		:::    :::    ::::    :::        :::     "<<endl;
		cout<<"		:+:    :+:    :+:+:   :+:      :+: :+:   "<<endl;
		cout<<"		+:+    +:+    :+:+:+  +:+     +:+   +:+  "<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"		+#+    +:+    +#+ +:+ +#+    +#++:++#++: "<<endl;	
		cout<<"		+#+    +#+    +#+  +#+#+#    +#+     +#+ "<<endl;
		cout<<"		#+#    #+#    #+#   #+#+#    #+#     #+# "<<endl;
		cout<<"		 ########     ###    ####    ###     ### "<<endl;

		cout<<"		"<<endl;
		cout<<"		"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);	
		cout<<"		   +-+ +-+ +-+ +-+ +-+ +-+ +-+  "<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);	
		cout<<"		   |O| |T| |H| |E| |L| |L| |O|   "<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);	
		cout<<"		   +-+ +-+ +-+ +-+ +-+ +-+ +-+ 	"<<endl;

		cout<<endl<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);	
		cout<<"	  INTEGRANTES: "<<endl<<endl;	
		cout<<"		->EDUARDO SEQUEIRA	"<<endl;
		cout<<"		->EDGAR RAMIREZ "<<endl;	
		cout<<endl<<endl<<endl;
		system("pause");
		system("cls");
	}

	void instrucciones1(){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);	
		cout<<endl<<"     Reglas del juego:"<<endl<<endl;		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
		cout<<"     Hay 2 tipos de fichas: Negra(X) y Blancas(O)"<<endl;
		cout<<"     Empiezan las negras, seguida de las blancas"<<endl;
		cout<<"     asi sucesivamente hasta encontrar el ganador"<<endl<<endl;
		system("pause");
		system("cls");
	}

	void instrucciones2(){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);	
		cout<<endl<<"     Si un jugador no puede mover el turno pasa al contrario."<<endl;
		cout<<"     Una ficha solo se puede colocar si deja, entre medio de esa ficha"<<endl;
		cout<<"     y otra del mismo color ya colocada, una o varias fichas del color contrario"<<endl<<endl;
		system("pause");
		system("cls");
	}

	void instrucciones3(){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);	
		cout<<endl<<"     Todas estas estaran en una linea continua de fichas, horizontales,"<<endl;
		cout<<"     verticales o diagonales."<<endl;
		cout<<"     Todas las fichas contrarias que han quedado entre medio se voltean"<<endl;
		cout<<"		para que muestren el color de la otra cara."<<endl<<endl;
		system("pause");
		system("cls");
	}

	void instrucciones4(){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);	
		cout<<endl<<"     El juego termina cuando no hay mas posiciones validas."<<endl;
		cout<<"     El ganador es aquel que tenga mas fichas del mismo color"<<endl<<endl;
		system("pause");
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);	
		cout<<endl<<"     BUENAS SUERTE..."<<endl<<endl;
		system("pause");
		system("cls");
	}

	void jugar(){//jugar hace el llamado de todas las intrucciones e inicia la partida
		this->presentacion();
		this->instrucciones1();
		this->instrucciones2();
		this->instrucciones3();
		this->instrucciones4();
		j.turnoPartida();
	}
};