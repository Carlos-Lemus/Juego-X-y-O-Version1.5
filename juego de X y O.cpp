//Hecho por Carlos Alfonso Lemus Rodezno LR18001

/*
Este programa consiste en un juego de X y O hecho para entretener a los usuarios
*/

//Libreria iostream permite usar sus funciones
#include <iostream>
//Libreria windows.h permite usar sus funciones
#include <windows.h>
//Libreria stdlib.h permite usar sus funciones
#include <stdlib.h>
//Libreria time.h permite usar sus funciones
#include <time.h>
//Libreria conio.h permite usar sus funciones
#include <conio.h>
//Libreria fstream permite usar sus funciones
#include <fstream>

//Espacio de nombre a usar std permite abreviar el codigo
using namespace std;

/*
declaracion de funcion partida en esta funcion se ejecutaran las lineas de codigo y las funciones
que permitiran jugar al juego X y O
*/
void partida();
//declaracion de funcion para visualizar la tabla de los en la que se jugara
void tablero_mostrar(char tj[3][3]);
/* declaracion de funcion tablero esta complementa la funcion tablero_mostrar ya que asi se visualiza mejor la tabla
en la que se jugara*/
void tablero(char tj[3][3]);
//declaracion de funcion permite al usuario ingresar la posicion en la que el usuario desee coloca la X en el tablero 
void pos_tab(char tj[3][3]);
//declaracion de funcion que permitira rellenar el tablareo de 'O' y simular una partida 
void jugador2(char tj[3][3]); 
//declaracion de funcion que evaluara el ganador de la partida
int ganador(char tj[3][3]);
//declaracion funcion usuario atrevez de esta funcion el usuario ingresara el nombre o apode como quiere tener e el juego
void usuario();
//declaracion funcion mostrar_usuario atrevez de esta funcion se motrara el nombre o apode que el usuario tiene en el juego
void mostrar_usuario();
//declaracio funcion que permitira la reproduccion de musica en el menu del juego
void musica_menu();
//declaracio funcion que permitira la reproduccion de musica en la partida del juego
void musica_partida();
//declaracio funcion que permitira la reproduccion de musica en el resultado del ganador de la partida
void musica_ganador();
//declaracion de funcion que 
void gotoxy(int x, int y);
//declaracion de funcion que permite dar un tiempo de carga
void cargar();
//declaracion Funcion que permite limpiar la pantalla
void clear();
//declaracion de la Funcion para evitar errores de datos
void errordato();


//cuerpo del programa
int main() {
	
	//delcaracion de variable opcion de iipo entero que almacenara la opcion elejida por el usuario
	int opcion;
	
	//funcion que limpia la pantalla de los textos
	clear();
	
	//Añade color a las letras y el fondo de la consola
	system("color 1E");
	
	//funcion que reproducira musica en el menu del juego
	musica_menu();
	
	//ciclo do-while para evitar que el usuario ingrese una opcion que no se encuentra
	do {
		
		/*funcion que mostrara el nombre o apode que tiene el usuario en el juego (en caso de no haberlo)
		  ingresado se le pondra el nombre de jugador*/
		mostrar_usuario();
		
		//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,4);
		cout << "************************************" << endl;
		//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,5);
		cout << "*                                  *" << endl;
		//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,6);
		cout << "*            Bienvenido            *" << endl;
		//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,7);
		cout << "*        ¡Comienza a jugar!        *" << endl;
		//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,8);
		cout << "*                                  *" << endl;
		//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,9);
		cout << "************************************" << endl;
		
		//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,11);
		cout << "Opciones." << endl;
		//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,12);
		cout << "1.Iniciar Partida" << endl;
		//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,13);
		cout << "2.Ingresar usuario" << endl;
		gotoxy(43,14);
		cout << "3.Salir del juego" << endl;
		
		//funcion que limpa el bueffer
		fflush(stdin);
		
		//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,16);
		//Se ingresa la opcion
		cout << "Ingresa una opcion: ";
		cin >> opcion;
		
		//funcion para evitar el ingreso de datos erroneos
		errordato();
		
	} while(opcion < 1 || opcion > 3);
	
	//setencia switch que permitira elejir una opcion
	switch(opcion) {
		
		case 1:
			//Si el usuario ingresa esta opcion se dirijira a la funcion partida()
			partida();
			break;
			
		case 2:
			//Si el usuario ingresa esta opcion se dirijira a la funcion usuario() para	
			usuario();
			break;
		
		case 3:
			//Funcion para limpiar el texto de la pantalla
			clear();
			
			/*funcion que mostrara el nombre o apode que tiene el usuario en el juego (en caso de no haberlo)
		  	  ingresado se le pondra el nombre de jugador*/
			mostrar_usuario();
			
			//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
			gotoxy(50,6);
			cout << "¡Gracias por jugar!\n" << endl << endl;
			break;
	}
	
	//Para evitar que se cierre la pantalla despues de haber realizados las acciones
	system("PAUSE");
	//No retorna ningun valor
	return 0;
}

void partida(){
	
	//Añade color a las letras y el fondo de la consola
	system("color 1F");
	
	//funcion que permitira tener musica dentro de la partida de juego
	musica_partida();
	
	/* Variable partida matriz bidimensional almacenara los datos para la partida de X y O tambien permitira
	visualizar una tabla de la partida en la consola */
	char juego[3][3];
	/*variable turnos contador que se encargara de evitar que se juegue en mas veces de
	la que el juego X y O permite*/ 
	int turno = 0;
	//Variable que almacenara la funcion ganador() que mostrara el resultado de la partida
	int resultado;
	
	//Funcion para limpiar el texto de la pantalla	
	clear();	
	
	/*funcion que mostrara el nombre o apode que tiene el usuario en el juego (en caso de no haberlo)
	  ingresado se le pondra el nombre de jugador*/
	mostrar_usuario();
	
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(55,4);	
	cout << "INSTRUCCIONES.";	
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(30,6);
	cout << "Ingrese un numero de las posiciones indicadas para colocar una X las" << endl;
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(30,7);
	cout << "O seran colocadas de manera automatica, para ganar coloque tres X en"  << endl;
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(30,8);
	cout << "la misma linea no importa si es en el sentido vertical o horizontal" << endl;
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(30,9);
	cout << "pero tambien puede ser en sentido cruz (pero no puede ser dos o mas" << endl;
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(30,10);
	cout << "a la vez, solo se puede ganar en una poscion a la vez)."  << endl;
	
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla	
	gotoxy(54,14);
	cout << " 1 | 2 | 3 " << endl;
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(54,15);
	cout << "-----------" << endl;
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(54,16);
	cout << " 4 | 5 | 6 " << endl;
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(54,17);
	cout << "-----------" << endl;
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(54,18);
	cout << " 7 | 8 | 9 " << endl;
	
	//Funcion que permite un tiempo de espera para que el juego cargue
	cargar();
	
	//funcion mostrar para para visualizar los espacios vacios en la tabla
	tablero_mostrar(juego);
	
	//ciclo do-while que se encargara que de que no se pueda juegue mas veces de lo que el juego X y O permite
	do{
		//funcion que limpia la pantalla de los textos
		clear();	
		
		//funcion tablero para visualizar el tablero
		tablero(juego);
		
		/*funcion que mostrara el nombre o apode que tiene el usuario en el juego (en caso de no haberlo)
		  ingresado se le pondra el nombre de jugador*/
		mostrar_usuario();
		
		//Condicion if para determinar el turno en que el usuario
		if(turno % 2==0)
		{
			//funcion posicion permite al usuario ingresar la posicion en la que desea poner la X 
			pos_tab(juego);
		}
		//Si la condicion if es falsa se ingresara qui
		else {
			//funcion oponente permite colocar una O en el tablero sin ocupar una psocion que contenga X
			jugador2(juego);
		}
		
		//salto de linea
		cout << endl;
	
		//Se almacena la funcion ganador() para saber el resultado de la partid
		resultado = ganador(juego);
		
		//contador turno llevara la cuenta de las veces que se han ingresado X y O
		turno++;
		
	} while(turno <= 9 && resultado == 2);
	
	//Funcion para limpiar el texto de la pantalla
	clear();
	
	/*funcion que mostrara el nombre o apode que tiene el usuario en el juego (en caso de no haberlo)
	  ingresado se le pondra el nombre de jugador*/
	mostrar_usuario();
	
	//funcion tablero para visualizar el tablero
	tablero(juego);	
	
	//Sentencias if si su condicion se cumple se ingresara aqui
	if(resultado == 1){
		
		//Funcion para reproducir un sonido al momento de dar el resultado del ganador de la partida
		musica_ganador();
		//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(44,3);
		cout << "¡Has ganado la partida!" << endl;
	}
	//Sentencias else if si su condicion se cumple se ingresara aqui
	else if(resultado == 0) {
		
		//Funcion para reproducir un sonido al momento de dar el resultado del ganador de la partida
		musica_ganador();
		//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(44,3);
		cout << "Has perdido la partida" << endl;
	}
	//Si niguna condicion se cumple se ingresara aqui
	else {
		
		//Funcion para reproducir un sonido al momento de dar el resultado del ganador de la partida
		musica_ganador();
		//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(44,3);
		cout << "Has empatado" << endl;
	}
	
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(43,16);
	cout << "Presione un boton para continuar." << endl;
	
	//funcion que detiene el programa hasta que el usario presiones un boton
	getch();
	//funcion main esta enviara al usuario devuelta al funcion main() una vez terminada la partida
	main();
}

/*funcion tablero_mostrar que visualiza el tablero vacio en la que se jugara contiene un parametro tipo char y 
es de tipo void por lo que no retorna un valor*/
void tablero_mostrar(char tj[3][3])
{
	/*Cada posicion de la matriz tj[3][3] tiene como valor un espacio vacio, esto con el motivo 
	de que al momento de visulizar la tabla los espacion de la tabla este "vacios"*/
	
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(53,7);
	tj[0][0] = ' ';
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(57,7);
	tj[0][1] = ' ';
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(61,7);
	tj[0][2] = ' ';
	
	gotoxy(53,9);
	tj[1][0] = ' ';
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(57,9);
	tj[1][1] = ' ';
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(61,9);
	tj[1][2] = ' ';
	
	gotoxy(53,11);
	tj[2][0] = ' ';
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(57,11);
	tj[2][1] = ' ';
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(61,11);
	tj[2][2] = ' ';
	
	
}

/*funcion tablero que visualiza el tablero en la que se jugara y los movimientos del usuario esta se complementa
 junto a la funcion tablero_mostrar contiene parametro tipo char y es de tipo void por lo que no retorna un valor*/
void tablero(char tj[3][3])
{
	//cuando el usuario ingrese las posiciones se colocaran el el lugar que le corresponde en el tablero
	
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(53,7);
	cout << tj[0][0] << " | " << tj[0][1]  << " | " << tj[0][2] << endl;
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(53,8);
	cout << "---------" << endl;
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(53,9);
	cout << tj[1][0] << " | " << tj[1][1] << " | " << tj[1][2] << endl;
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(53,10);
	cout << "---------" << endl;
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(53,11);
	cout << tj[2][0] << " | " << tj[2][1] << " | " << tj[2][2] << endl;
	
}

/*funcion cuyo significado es posicion en el tablero permite al usuario ingresar la posicion en la que el usuario 
desee coloca la X en el tablero no contiene un parametro tipo char y es de tipo void por lo que no retorna un valor*/
void pos_tab(char tj[3][3])
{
	//declaracion de la variable p de tipo char
 	char p;
 	//declaracion de la variable lleno de tipo entero
	int lleno;
	
	//ciclo do-while para evitar colocar una X en un lugar ya ocupado 
	do {
		
		//Ciclo do-while para evitar que el usuario elija una condicion que no se encuentra en el programa
		do {
			//variable lleno cuyo valor es 0
			lleno = 0;
			
			//funcion que limpa el bueffer
			fflush(stdin);
			
			//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
			gotoxy(45,3);
			cout << "Ingresa una posicion: ";
			cin >> p;
			//funcion para evitar el ingreso de datos erroneos
			errordato();
		} while(p < '1' || p > '9');
		
		//setencia switch que permitira elejir una opcion
		switch(p){

			/*cada case contiene una condicion para evitar colocar una X en un lugar ya ocupado 
			si la concion se cumple la variable lleno pasara tener un valor 1 por lo que el ciclo 
			se volvera a repetir en caso de ser falsa la condicon se colocara X en el lugar elejido*/
			
			case '1':
	
				if(tj[0][0] == 'X' || tj[0][0] == 'O'){
				lleno = 1;
				}
				else{
					
					tj[0][0] = 'X';	
				}
				
				break;
				
			case '2':
			
				if(tj[0][1] == 'X' || tj[0][1] == 'O'){
				lleno = 1;
				}
				else{
					tj[0][1] = 'X';	
				}
				
				break;
			
			case '3':
				
				if(tj[0][2] == 'X' || tj[0][2] == 'O'){
				lleno = 1;
				}
				else{
					tj[0][2] = 'X';	
				}
				
				break;
			
			case '4':
				
				if(tj[1][0] == 'X' || tj[1][0] == 'O'){
				lleno = 1;
				}
				else{
					tj[1][0] = 'X';	
				}
				
				break;
			
			case '5':
				
				if(tj[1][1] == 'X' || tj[1][1] == 'O'){
				lleno = 1;
				}
				else{
					tj[1][1] = 'X';	
				}
				
				break;
			
			case '6':
	
				if(tj[1][2] == 'X' || tj[1][2] == 'O'){
				lleno = 1;
				}
				else{
					tj[1][2] = 'X';	
				}
				
				break;
			
			case '7':
				
				if(tj[2][0] == 'X' || tj[2][0] == 'O'){
				lleno = 1;
				}
				else{
					tj[2][0] = 'X';	
				}
				
				break;	
			
			case '8':
				
				if(tj[2][1] == 'X' || tj[2][1] == 'O'){
				lleno = 1;
				}
				else{
					tj[2][1] = 'X';	
				}
				
				break;
			
			case '9':
				
				if(tj[2][2] == 'X' || tj[2][2] == 'O'){
				lleno = 1;
				}
				else{
					tj[2][2] = 'X';	
				}
				
				break;
		}
		
		
	} while(lleno == 1);
	
}

/*funcion que permitira rellenar el tablareo de 'O' y simular una partida contiene un parametro tipo char y es 
de tipo void por lo que no retorna un valor*/
void jugador2(char tj[3][3]) 
{
	
	//declaarion de variables de tipo entero
	int i;
	int j;
	int lleno;
	
	/*
	funcion srand esta funcion contiene la semilla para crear numeros aleatorios diferentes cada vez que 
	se ejecute el programa
	*/
	srand(time(NULL));
	
	//Ciclo while permetira evitar que ese coloque una O en un lugar de la tabla de juego que este ocupada
	do {
		//funcion rand colocara una O aleatoriamente en la tabla y se almacenara en la variable i
		i = rand ()% 3;
		//funcion rand almacenara variables aleatorias y se almacenara en la variable j
		j = rand ()% 3;
		//funcion rand colocara una O aleatoriamente en la tabla y se almacenara en la variable j
		lleno = 0;
		
		//condiion que evitara colocar una 0 en un lugar ocupado
		if(tj[i][j]  == 'X' || tj[i][j] == 'O'){
			//si la condicion se cumple lleno pasara a tener el valor de uno por lo que el ciclo se repitira
			lleno = 1;
		}
	} while(lleno == 1);
	
	//la variable tj[i][j] almacenara O
	tj[i][j] = 'O';
	
}

/*funcion que evaluara el ganador de la partida contiene un parametro de tipo char y es de tipo char 
por lo que retorna entero*/
int ganador(char tj[3][3])
{
	//Condiciones para verificar el ganador del juego
	
	if (tj[0][0] == 'X' || tj[0][0] == 'O'){
		if (tj[0][0] == tj[0][1] && tj[0][0] == tj[0][2]){
			if (tj[0][0] == 'X'){
	    	return 1;
	   		}
	   		else {
	    	return 0;
	   		}
		}
		if (tj[0][0] == tj[1][0] && tj[0][0] == tj[2][0]){
			if (tj[0][0] == 'X'){
	    		return 1;
			}
			else{
	    		return 0;
			}
		}
	}
	
	//Ficha central(5)
	if (tj[1][1] == 'X' || tj[1][1] == 'O'){
		//fichas 1 5 9
		if (tj[1][1] == tj[0][0] && tj[1][1] == tj[2][2]){
			if (tj[1][1] == 'X'){
	    		return 1;
	   		}
	   		else{
	    		return 0;
	   		}
	  	}
		//fichas 2 5 8
		if (tj[1][1] == tj[0][1] && tj[1][1] == tj[2][1]){
	   		if (tj[1][1] == 'X'){
	   			return 1;
	   		}
	   		else{
	    		return 0;
	   		}
	  }
		//Fichas 4 5 6
		if (tj[1][1] == tj[1][0] && tj[1][1] == tj[1][2]){
	   		if (tj[1][1] == 'X'){
	    		return 1;
	   		}
	   		else {
	    		return 0;
	   		}
	  	}
	  	//fichas 7 5 3
	  	if (tj[1][1] == tj[2][0] && tj[1][1] == tj[0][2]){
	   		if (tj[1][1] == 'X'){
	    		return 1;
	  	 	}
	   		else{
	    		return 0;
	   		}
	  	}
	 }
	 
	//Ficha final (9)
	else if(tj[2][2] == 'X' || tj[2][2] == 'O'){
		if (tj[2][2] == tj[1][2] && tj[2][2] == tj[0][2]){
	   		if (tj[2][2] == 'X'){
	    		return 1;
	   		}
	   		else{
	    		return 0;
	   		}
	  	if (tj[2][2] == tj[2][1] && tj[2][2] == tj[2][0]){
	   		if (tj[2][2] == 'X'){
	    		return 1;
	   		}
	   		else{
	    		return 0;
	   		}
	   	}
	  }
	}
	 return 2;		
}

/*funcion usuario atrevez de esta funcion el usuario ingresara el nombre o apode como quiere tener e el juego
  y se guardara en un archivo .txt no contiene parametros y es de tipo void por lo que no retorna un valor*/
void usuario()
{
	//funcion que limpia la pantalla de los textos
	clear();	
	
	/*ofstream es un tipo especializado en tipo caracteres que permite el ingreso de datos al fichero
	por eso definimos nuestra fichero como de tipo ofstream*/
	ofstream archivo;
	
	//Abrimos el archivo con la funcion open y especificamos con ios::out que ingresaremos datos en el fichero
	archivo.open("usuario.txt", ios::out);
	
	//Variable de tipo char con de una dimension que permite 21 caracteres
	char usuario[21]; 
	
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(53,4);
	cout << "ADVERTENCIA";
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(40,6);
	cout << "No se permite mas de 20 caracteres";
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(40,7);
	cout << "no se reconoceran los demas";
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(51,9);
	cout << "APODO - NOMBRE ";	
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(35,11);
	cout << "Ingresa el nombre de usuario que quieres: ";	
	
	//ignoramos lo ingresado en el buffer anteriormente
	cin.ignore();
	
	//se ingresa los caracteres que se almacenaran en usuario
	cin.getline(usuario,21);
	
	//se almacena lo ingrsado en usuario en el fichero archvio
	archivo << usuario;
		
	//finalmente se cierra el fichero con la funcion close()
	archivo.close();
	
	//funcion main esta enviara al usuario devuelta al funcion main() una vez terminada la funcion usuario
	main();
}

/*funcion mostrar_usuario atrevez de esta funcion se motrara el nombre o apode que el usuario tiene en el juego el
  que esta almacenado en un archivo .txt no contiene parametros y es de tipo void por lo que no retorna un valor*/
void mostrar_usuario(){
	
	/*ifstream es un tipo especializado en tipo caracteres que permite la lectura al fichero
	por eso definimos nuestra fichero como de tipo ifstream*/
	ifstream archivo;
	
	//Abrimos el archivo con la funcion open y especificamos con ios::in que leermos los datos del fichero
	archivo.open("usuario.txt", ios::in);
	
	//Variable de tipo char con de una dimension que permite 21 caracteres
	char usuario[21];
	
	//se almacena los datos ingresado en la variable usuario en nuestro fichero
	archivo.getline(usuario, 21);
	
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(94,2);
	//Se imprime lo almacenado en la variable usuario
	cout << "| " << usuario << " |";
	
	//finalmente se cierra el fichero con la funcion close()
	archivo.close();
	
}

/*funcion que permitira la reproduccion de musica en el menu del juego no contiene parametros y es
  de tipo void por lo que no retorna un valor*/
void musica_menu()
{
	//funcion que a apartir de un archvio de musica .wav reproducira musica en el juego
	PlaySound(TEXT("Music//03 B-Type Music.wav"), NULL, SND_ASYNC  | SND_LOOP | SND_FILENAME);
	
}

/*funcion que permitira la reproduccion de musica en la partida de juego no contiene parametros 
 y es de tipo void por lo que no retorna un valor*/
void musica_partida()
{
	//funcion que a apartir de un archvio de musica .wav reproducira musica en el juego
	PlaySound(TEXT("Music//18 - Dr. Wily's Castle.wav"), NULL, SND_ASYNC  | SND_LOOP | SND_FILENAME);
	
}

/*funcion que permitira la reproduccion de musica cuando da el resultado del el ganador no contiene 
  parametros y es de tipo void por lo que no retorna un valor*/
void musica_ganador()
{
	//funcion que a apartir de un archvio de musica .wav reproducira musica en el juego
	PlaySound(TEXT("Music//mario-bros vida.wav"), NULL, SND_ASYNC | SND_FILENAME);
	
}

/*Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla contiene dos parametros enteros
y es de tipo void por lo que no retorna ningun valor
*/
void gotoxy(int x, int y)
{
	//Estas instrucciones permiticra ubicar un texto en el lugar que se desee en la pantalla
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

//funcion que permite dar un tiempo de carga no contiene parametros y es de tipo void por lo que no retorna un valor
void cargar()
{
	
	//Variable cargar servira como contador
	int carga = 1;
	
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(30,20);
	cout << "cargando";
	
	//Funcion Sleep para permite generar un tiempo de carga
	Sleep(1500);	
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(30,21);
	cout << "....."; 
	
	//Funcion Sleep para permite generar un tiempo de carga
	Sleep(1500);
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(34,21);
	cout << ".....";
	  
	//Funcion Sleep para permite generar un tiempo de carga
	Sleep(1500);	
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(38,21);
	cout << ".....";   
	
	//Funcion Sleep para permite generar un tiempo de carga
	Sleep(1500);
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(38,21);
	cout << ".....";   
	
	//Funcion Sleep para permite generar un tiempo de carga
	Sleep(1500);
	//Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	gotoxy(38,21);
	cout << ".....";   
}


//Funcion que permite limpiar la pantalla no contiene parametros y es de tipo void por lo que no retorna un valor
void clear()
{
	//funcion system("cls") que limpia la pantalla de los textos que esta contiene
	system("cls");
}

//Funcion para evitar errores de datos no contiene parametros y es de tipo void por lo que no retorna un valor
void errordato()
{
	//Ciclo while para evitar ingresar datos incorrectos
	while(cin.fail()){
		
		//cin.clear limpia el bueffer de los datos ingresados				
			cin.clear();
		
		//cin.igonere ignorara los primeros 1000 caracteres o en este caso los numeros ingresados
			cin.ignore(1000,'\n');
		}
} 
