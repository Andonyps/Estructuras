#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#define getch system("pause")
#define getch system("cls")
using namespace std;

void poss(int x, int y) {
	COORD coord;
	coord.X = (SHORT)x;
	coord.Y = (SHORT)y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct pilas
{
	string nombre;
	string edad;
	string peso;
	pilas* direccionA;
}direccion;

struct Date {
	string dato = "";
	string ndato = "";
};

//struct para cola
struct Nodo
{
	Date datos;
	Date numero;
	Nodo* siguente;
};

struct lista {
	string dato;
	string precio;
	string medicamento;
	lista* siguiente;
} *primero, * ultimo;

void insertarNodo();
void desplegarLista();

struct doble {
	string dnombre;
	string mascota;
	string tratamiento;
	doble* siguientes;
	doble* atrass;
} *primeros, * ultimos;

void insertarNodod();
void desplegarListaPU();
void desplegarListaUP();

struct sircul {
	int no;
	string nombre;
	string tmasota;
	sircul* siguient;
} *primer, * ultim;


Nodo* ptrInicio;
Nodo* ptrFin;
Nodo* ptrFlechita;
pilas* pilao, * pilaaux;
void ingreso(pilas*&, string valor);
void mostrar(pilas*&, string&);
void eliminar();
void buscar();
//prototipo de funciones
void nuevaCola(string&, string&, Nodo*&, Nodo*&);
//void eliminarCola(string& , string& ,float &, Nodo*&, Nodo*&);
//solo elimino lo datos mas no los muestro
void eliminarTodaCola(Nodo*&, Nodo*&);
//void muestraDatos(Nodo*&, Nodo*&, string&, string&);
void encabezadoMstIng(string);
void ingresoDatos();
void menuCola();
void opcionesSwitch(int&);
void subMenu();
void submenuSwitch(int&);
void buscarDato(Nodo*&, Nodo*&);
void actualizaDto(Nodo*&, Nodo*&);
void eliminarUnDato(Nodo*&, Nodo*&, Nodo*&);
void muestraDato(Nodo*&, Nodo*&, Nodo*&);
void listasimple(lista*& string);

//PILAS
void ingreso() {
	system("cls");
	system("color 09 ");
	if (pilao == NULL) {
		pilao = new(pilas);
		cout << "DATOS DE LA MASCOTA " << endl;
		cout << "Ingrese el nombre de la mascota" << endl;
		cin >> pilao->nombre;
		cout << "Ingrese la edad de la mascota" << endl;
		cin >> pilao->edad;
		cout << "Ingrese el peso de la mascota" << endl;
		cin >> pilao->peso;
		cout << "Datos de la mascota registrados correctamente" << endl;
		pilao->direccionA = NULL;
		cout << "Direccion Anterior " << pilao->direccionA << endl;
		system("pause");
	}
	else
	{
		//system("cls");
		pilaaux = new(pilas);
		cout << "Ingrese el nombre de la mascota" << endl;
		cin.ignore();
		getline(cin, pilaaux->nombre);
		cout << "Ingrese la edad de la mascota" << endl;
		getline(cin, pilaaux->edad);
		cout << "Ingrese el peso de la mascota" << endl;
		getline(cin, pilaaux->peso);
		cout << "REGISTRADO CORRECTAMENTE" << endl;
		pilaaux->direccionA = pilao;
		cout << "Direccion Anterior " << pilaaux->direccionA << endl;
		pilao = pilaaux;
	}
}
void mostrar() {
	system("color 0a ");
	system("cls");
	if (pilao == NULL) {
		cout << "No hay registros en la pila" << endl;
		system("pause");
	}

	pilaaux = pilao;
	cout << "Las mascotas registradas en la pila son: " << endl;
	while (pilaaux != NULL) {
		cout << "                      *****" << endl;
		cout << " nombre de la mascota | " << pilaaux->nombre << "     |" << endl;
		cout << " edad de la mascota   | " << pilaaux->edad << "        |" << endl;
		cout << " peso de la mascota   | " << pilaaux->peso << "        |" << endl;
		pilaaux = pilaaux->direccionA;
		cout << " direccion de memoria | " << pilaaux << "  |" << endl;
		cout << "                      *****\n";
	}
	cout << "   "; cout << "null" << endl;
	system("pause");
}


void eliminar() {
	system("color 09 ");
	if (pilao == NULL) {
		cout << "No hay registros en la pila" << endl;
		return;
	}
	pilaaux = new(pilas);
	pilaaux = pilao;
	cout << "Registro eliminado " << pilaaux->nombre << pilaaux->edad << pilaaux->peso << endl;
	pilao = pilaaux->direccionA;
	delete(pilaaux);
	system("pause");
}
void buscar() {
	system("color 09 ");
	if (pilao == NULL) {
		cout << "La pila esta vacia" << endl;
		return;
	}
	string buscardatos;
	bool encontrado = false;
	pilaaux = pilao;
	cout << "Ingrese mascota a buscar" << endl;
	cin >> buscardatos;
	while (pilaaux != NULL) {
		if (buscardatos == pilaaux->nombre) {
			cout << "Encontrado, la mascota es; " << pilaaux->nombre << pilaaux->edad << pilaaux->peso << endl;
			encontrado = true;
			break;
		}
		pilaaux = pilaaux->direccionA;
	}
	if (encontrado == false) {
		cout << "No se encontro el registro" << endl;
	}
	system("pause");
}

void menuPila() {
	system("color 09 ");
	system("cls");
	int opcion = 1;
	while (opcion != 5) {
		system("cls");
		poss(40, 9); cout << "ELIJA LA OPCION";
		poss(40, 10); cout << "->->->->->->->->->->->->->->->->->->";
		poss(40, 11); cout << "1. Registrar una mascota";
		poss(40, 12); cout << "2. Ver registros en la pila ";
		poss(40, 13); cout << "3. Eliminar registros de la pila ";
		poss(40, 14); cout << "4. Buscar registros en la pila ";
		poss(40, 15); cout << "5. Regresar al menu";
		poss(57, 17); cout << "__";
		poss(57, 19); cout << "__";
		poss(55, 18); cout << "|"; poss(56, 18); cout << "|";
		poss(60, 18); cout << "|"; poss(61, 18); cout << "|";
		poss(58, 18); cin >> opcion;
		switch (opcion) {
		case 1: {
			system("cls");
			ingreso();
			break;
		}
		case 2: {
			system("cls");
			mostrar();
			break;
		}
		case 3: {
			system("cls");
			eliminar();
			break;
		}
		case 4: {
			system("cls");
			buscar();
			break;
		}
		case 5:
			cout << "Regresando al menú";
			system("pasue");
			system("cls");
			break;
		}
	}
}

//COlA

void menuCola() {
	system("color 09 ");
	int eleccion;
	do {
		system("cls");
		poss(40, 9); cout << "------ELIJA UNA OPCION-------";
		poss(40, 11); cout << "1. Ingresar duenos";
		poss(40, 12); cout << "2. Ver duenos ingresados ";
		poss(40, 13); cout << "3. Modificar los datos ";
		poss(40, 14); cout << "4. Eliminar todos los datos ";
		poss(40, 15); cout << "5. Megresar al menu principal ";
		poss(57, 17); cout << "__";
		poss(57, 19); cout << "__";
		poss(55, 18); cout << "|"; poss(56, 18); cout << "|";
		poss(60, 18); cout << "|"; poss(61, 18); cout << "|";
		poss(58, 18); cin >> eleccion;
		opcionesSwitch(eleccion);
	} while (eleccion != 5);
}

void opcionesSwitch(int& op) {
	system("color 09 ");
	switch (op)
	{
	case 1:
		system("cls");
		ingresoDatos();
		system("cls");
		break;
	case 2:
		system("cls");
		muestraDato(ptrInicio, ptrFin, ptrFlechita);
		system("cls");
		break;
	case 3:
		system("cls");
		subMenu();
		system("cls");
		break;
	case 4:
		system("cls");
		eliminarTodaCola(ptrInicio, ptrFin);
		cout << "Registro eliminados correctamente";
		system("pause");
		system("cls");
		break;
	case 5:
		system("cls");
		printf("Regresando al menu principal \n");
		system("pause");
		system("cls");
		break;
	default:
		system("cls");
		cout << "ERROR AL REGISTRAR AL DUENO";
		system("pause");
		system("cls");
		break;
	}
}
void ingresoDatos() {
	system("color 09 ");
	int opcion;
	string nmDato;
	string nmNdato;
	int posFila = 7;
	encabezadoMstIng("REGISTRO DE DUENO");
	do
	{
		cin.ignore();
		poss(15, posFila - 1); cout << "INGRESE EL NOMBRE DEL USUARIO";
		poss(15, posFila); cout << "> "; getline(cin, nmDato); poss(15, posFila); cout << " ";
		poss(15, posFila + 1); cout << "INGRESE EL TELEFONO DEL USUARIO";
		poss(15, posFila + 2); cout << "> "; getline(cin, nmNdato); poss(15, posFila); cout << " ";
		;
		nuevaCola(nmDato, nmNdato, ptrInicio, ptrFin);
		poss(45, posFila + 5); printf("ingerse \"0\" para finalizar");
		poss(59, posFila + 6); cin >> opcion;
		poss(45, posFila + 5); cout << " ";
		poss(45, posFila + 6); cout << " ";
		posFila++;
	} while (opcion != 0);
}
void subMenu() {
	system("color 09 ");
	int eleccion;
	do {
		system("cls");
		poss(40, 8); cout << "°--------------------------------------°";
		poss(40, 9); cout << "°ELIJA UNA OPCION";
		poss(40, 10); cout << "°--------------------------------------°";
		poss(40, 11); cout << "1. ELIMINAR UN DATO";
		poss(40, 12); cout << "2. BUSCAR UN DATO ";
		poss(40, 13); cout << "3. ACTUALIZAR DATO ";
		poss(40, 14); cout << "4. SALIR";
		poss(40, 15); cout << "==========================================================";
		poss(40, 16); cout << "----------------------------------------";
		poss(40, 18); cout << "----------------------------------------";
		poss(40, 17); cout << "|"; poss(41, 17); cout << "|";
		poss(79, 17); cout << "|"; poss(78, 17); cout << "|";
		poss(59, 17); cin >> eleccion;
		//swich eleccion de opciones 
		system("cls");
		submenuSwitch(eleccion);
	} while (eleccion != 4);
}
void submenuSwitch(int& op) {
	system("color 09 ");
	switch (op)
	{
	case 1:
		eliminarUnDato(ptrInicio, ptrFin, ptrFlechita);
		/*
		system("cls");
		eliminarTodaCola(ptrInicio,ptrFin);
		printf("datos eliminados exitosamente");
		break;*/
		system("cls");
		break;
	case 2:
		system("cls");
		buscarDato(ptrInicio, ptrFlechita);
		system("cls");
		break;
	case 3:
		system("cls");
		actualizaDto(ptrInicio, ptrFlechita);
		system("cls");
		break;
	case 4:
		cout << "regresando al submenu Cola \n";
		system("pause");
		break;
	default:
		break;
	}
}

//funciones para la cola 
void nuevaCola(string& nmDato, string& nmNdato, Nodo*& primero, Nodo*&
	ultimo) {
	Nodo* nuevoNodo = new Nodo();
	//ingresando datos al nodo
	nuevoNodo->datos.dato = nmDato;
	nuevoNodo->numero.ndato = nmNdato;
	//asignado a siguente el valor nulod
	nuevoNodo->siguente = nullptr;
	if (primero == nullptr) {
		primero = nuevoNodo;
	}
	else
	{
		ultimo->siguente = nuevoNodo;
	}
	ultimo = nuevoNodo;
}
void eliminarTodaCola(Nodo*& inicio, Nodo*& fin) {
	//ingreso de datos 
	//nombre = inicio->datos.nombre;
	//hora = inicio->datos.hora;
	//precio = inicio->datos.precio;
	while (inicio != nullptr)
	{
		Nodo* elimAux = inicio;
		if (inicio == fin)
		{
			inicio = nullptr;
			fin = nullptr;
		}
		else
		{
			inicio = elimAux->siguente;
		}
		delete elimAux;
	}
}
void buscarDato(Nodo*& inicio, Nodo*& flechita) {
	system("color 09 ");
	string datoBusca;
	cout << "Ingrese el dato a buscar\n";
	cin.ignore();
	getline(cin, datoBusca);
	flechita = inicio;
	bool existencia = false;
	while (flechita != nullptr)
	{
		if (flechita->datos.dato == datoBusca) {
			cout << "El usuario " << "\"" << datoBusca << "\"" << " se encuenta en la Direccion de memoria " << flechita << endl;
			system("pause");
			existencia = true;
			flechita = nullptr;
		}
		else
		{
			flechita = flechita->siguente;
		}
	}
	if (!(existencia)) {
		cout << "Dato no encontrada porque no existe el dato: \n";
		system("pause");
	}
}
void actualizaDto(Nodo*& inicio, Nodo*& flechita) {
	system("color 09 ");
	int opciones;
	string dato;
	string nuevoDatoNdato;
	string nuevoDatoDato;
	bool existencia = false;
	poss(35, 4); printf("ingese el nombre del dato a Actualizar ");
	poss(35, 5); cin.ignore();
	getline(cin, dato);
	flechita = inicio;
	system("cls");
	while (flechita != nullptr)
	{
		if (flechita->datos.dato == dato) {
			poss(47, 4); cout << "\x1b[46mELIJA UNA OPCION\x1b[0m";
			poss(45, 5); cout << "---------------------------------";
			poss(45, 9); cout << "---------------------------------";
			poss(45, 6); cout << "opcion 1. actualizar nombre";

			poss(45, 10); cout << "> "; cin >> opciones;
			system("cls");
			switch (opciones)
			{
			case 1:
				poss(35, 7); cout << "ingrese el nuevo nombre del dato "
					<< dato;
				cin.ignore();
				poss(35, 8); getline(cin, nuevoDatoDato);
				flechita->datos.dato = nuevoDatoDato;
				poss(35, 10); system("pause");
				existencia = true;
				flechita = nullptr;
				break;
			case 2:
				poss(35, 7); cout << "ingrese el nuevo dato ";
				cin.ignore();
				poss(35, 8); getline(cin, nuevoDatoNdato);
				flechita->datos.ndato = nuevoDatoNdato;
				poss(35, 10); system("pause");
				existencia = true;
				flechita = nullptr;
				break;
			case 3:
				poss(35, 7); cout << "ingrese el nuevo nombre del dato";
				cin.ignore();
				poss(35, 8); getline(cin, nuevoDatoDato);
				flechita->datos.dato = nuevoDatoDato;
				cin.ignore();
				poss(35, 10); cout << "ingrese el nuevo dato";
				poss(35, 11); getline(cin, nuevoDatoNdato);
				flechita->datos.ndato = nuevoDatoNdato;
				poss(35, 10); system("pause");
				existencia = true;
				flechita = nullptr;
				break;
			default:
				system("cls");
				cout << "Error al elegir opcion saliendo de la opcion";
				flechita = nullptr;
				system("pause");
				system("cls");
				break;
			}
		}
		else
		{
			flechita = flechita->siguente;
		}
	}
	if (!(existencia)) {
		poss(35, 7); cout << "Dato no actualizado porque no se encontro: \n";
		poss(35, 10); system("pause");
	}
}

void eliminarUnDato(Nodo*& inicio, Nodo*& fin, Nodo*& flechita) {
	system("color 09 ");
	Nodo* aux;
	string datoEliminar;
	string nuevoDato;
	bool existencia = false;
	poss(35, 4); printf("Ingrese el nombre del dato a eliminar ");
	poss(35, 5); cin.ignore();
	getline(cin, datoEliminar);
	flechita = inicio;
	aux = inicio;
	while (flechita != nullptr)
	{
		if (flechita->datos.dato == datoEliminar) {
			//comprobando si es el inicio de la cola 
			if (flechita == inicio)
			{
				inicio = inicio->siguente;
				delete flechita;
				flechita = nullptr;
				aux = nullptr;
				existencia = true;
				poss(35, 7); cout << "dato eliminado correctamente";
				poss(35, 10); system("pause");
			}
			else
			{
				//dcomprobando si es el fin de la cola
				if (flechita == fin)
				{
					aux->siguente = nullptr;
					fin = aux;
					delete flechita;
					aux = nullptr;
					flechita = nullptr;
					existencia = true;
					poss(35, 7); cout << "dato eliminado correctamente";
					poss(35, 10); system("pause");
				}
				//si no es ni inicio ni fin de la cola 
				else
				{
					//cout << aux->datos.nombre << endl;
					//cout << flechita->datos.nombre;
					aux->siguente = flechita->siguente;
					delete flechita;
					poss(35, 7); cout << "dato eliminado correctamente";
					poss(35, 10); system("pause");
					aux = nullptr;
					existencia = true;
					flechita = nullptr;
				}
			}
		}
		//si el dato no fue encontrado en la cola x pasa a la siguente
		else
		{
			aux = flechita;
			flechita = flechita->siguente;
		}
	}
	//si el dato no existe muestra mensaje
	if (!(existencia)) {
		cout << "Dato no eliminado, porque no existe: \n";
		system("pause");
	}
}



void muestraDato(Nodo*& inicio, Nodo*& fin, Nodo*& flechita) {
	system("color 09 ");
	int posFila = 7;
	int poscolumnas = 10;
	flechita = inicio;
	encabezadoMstIng("Usuarios Registrados\n\n");
	while (flechita != nullptr)
	{
		poss(poscolumnas, posFila); cout << "nombre |" << flechita->datos.dato; cout << "|";
		poss(poscolumnas, posFila + 1); cout << "numero |" << flechita->numero.ndato; cout << "|->\n";
		poss(poscolumnas, posFila + 2); cout << "memoria|" << "" << flechita->datos.ndato << "" << flechita << "|\n";
		poscolumnas++; poscolumnas++; poscolumnas++; poscolumnas++; poscolumnas++; poscolumnas++; poscolumnas++; poscolumnas++; poscolumnas++; poscolumnas++;
		poscolumnas++; poscolumnas++; poscolumnas++; poscolumnas++; poscolumnas++; poscolumnas++; poscolumnas++; poscolumnas++; poscolumnas++; poscolumnas++;
		poscolumnas++; poscolumnas++;
		if (flechita == fin)
		{
			flechita = nullptr;
		}
		else
		{
			flechita = flechita->siguente;
		}

	}
	poss(48, posFila + 5); system("pause");
	system("cls");
}

void encabezadoMstIng(string tituto) {
	system("color 09 ");
	poss(50, 2); cout << " --------DUENOS------ ";
	poss(58, 3); cout << " NOMBRES\n";
	poss(48, 4); cout << "=========================";
	poss(28, 5); cout << "";
}

//lista simplemente enlazada

void insertarNodo() {
	lista* nuevo = new lista();
	cout << " INGRESE EL NOMBRE DEL DUENO A REGISTRAR: ";
	cin >> nuevo->dato;
	cout << " INGRESE EL PRECIO DEL PRODUCTO: ";
	cin >> nuevo->precio;
	cout << " INGRESE EL NOMBRE DEL MEDICAMENTO: ";
	cin >> nuevo->medicamento;

	if (primero == NULL) {
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}
	else {
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	cout << "\n REGISTRO COMPLETADO\n\n";
	system("cls");
}


void marco() {
	cout << "                        ****";
	cout << " NOMBRE DE LA MASCOTA   *                   *";
	cout << " NOMBRE DE LA MASCOTA   *                   *";
	cout << " NOMBRE DE LA MASCOTA   *                   *";
	cout << " NOMBRE DE LA MASCOTA   *                   *";
	cout << "                        ****";
}

void desplegarLista() {
	lista* actual = new lista();
	actual = primero;
	if (primero != NULL) {

		while (actual != NULL) {

			cout << "                        *******" << endl;
			cout << " NOMBRE DEL DUENO       | " << actual->dato << "       |" << endl;
			cout << " PRECIO DEL MEDICAMENTO | " << actual->precio << "          |" << endl;
			cout << " TIPO DE MEDICAMENTO    | " << actual->medicamento << "      |" << endl;
			actual = actual->siguiente;
			cout << " DIRECCION DE MEMORIA   | " << actual << "    |" << endl;
			cout << "                        *******\n";

		}

	}
	else {
		cout << "\n La Lista se Encuentra Vacia\n\n";
	}system("pause");
}

void eliminarNodo() {
	lista* actual = new lista();
	actual = primero;
	lista* anterior = new lista();
	anterior = NULL;
	bool encontrado = false;
	string nodoBuscado;
	desplegarLista();
	cout << "INGRESE EL NOMBRE DEL DUENO A REGISTRAR : ";
	cin >> nodoBuscado;
	if (primero != NULL) {

		while (actual != NULL && encontrado != true) {

			if (actual->dato == nodoBuscado) {
				cout << "\n el usuario " << nodoBuscado << " se encuentra registrado en\n\n";

				if (actual == primero) {
					primero = primero->siguiente;
				}
				else if (actual == ultimo) {
					anterior->siguiente = NULL;
					ultimo = anterior;
				}
				else {
					anterior->siguiente = actual->siguiente;
				}

				cout << "\n registro ELiminado con exito\n\n";

				encontrado = true;
			}

			anterior = actual;
			actual = actual->siguiente;
		}
		if (!encontrado) {
			cout << "\n Registro No Encontrado\n\n";
		}
	}
	else {
		cout << "\n La Lista se Encuentra Vacia\n\n";
	}
	system("pause");
}

void menu_listasimple() {
	system("color 09 ");
	int eleccion;
	do {
		system("cls");
		poss(40, 9); cout << "------LISTA SIMPLEMENTE ENLAZADA-------";
		poss(40, 11); cout << "1. Ingresar duenos";
		poss(40, 12); cout << "2. Ver duenos ingresados ";
		poss(40, 13); cout << "3. Eliminar registros ";
		poss(40, 14); cout << "4. Regresar al menu principal ";
		poss(57, 17); cout << "__";
		poss(57, 19); cout << "__";
		poss(55, 18); cout << "|"; poss(56, 18); cout << "|";
		poss(60, 18); cout << "|"; poss(61, 18); cout << "|";
		poss(58, 18); cin >> eleccion;
		switch (eleccion) {
		case 1:system("cls"); insertarNodo(); break;
		case 2:system("cls"); desplegarLista(); break;
		case 3:system("cls"); eliminarNodo(); break;
		}

	} while (eleccion != 4);
}

//lisata doblemente enlazada
void insertarNodod() {
	doble* nuevo = new doble();
	cout << " INGRESE EL NOMBRE DEL DUENO A REGISTRAR: ";
	cin >> nuevo->dnombre;
	cout << " INGRESE EL NOMBRE DE LA MASCOTA: ";
	cin >> nuevo->mascota;
	cout << " INGRESE EL TRATAMIENTO A APLICAR: ";
	cin >> nuevo->tratamiento;
	if (primeros == NULL) {
		primeros = nuevo;
		primeros->siguientes = NULL;
		primeros->atrass = NULL;
		ultimos = primeros;
	}
	else {
		ultimos->siguientes = nuevo;
		nuevo->siguientes = NULL;
		nuevo->atrass = ultimos;
		ultimos = nuevo;
	}
	cout << "\n Registro Ingresado\n\n";
}

void desplegarListaPU() {
	doble* actual = new doble();
	actual = primeros;
	if (primeros != NULL) {

		while (actual != NULL) {

			cout << "                       *****" << endl;
			cout << " NOMBRE DEL DUENO      | " << actual->dnombre << "      |" << endl;
			cout << " NOMBRE DE LA MASCOTA  | " << actual->mascota << "       |" << endl;
			cout << " TIPO DE TRATAMIENTO   | " << actual->tratamiento << "    |" << endl;
			actual = actual->siguientes;
			cout << " DIRECCION DE MEMORIA  | " << actual << "   |" << endl;
			cout << "                       *****\n";
		}

	}
	else {
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	system("pause\n\n");
}

void eliminarNodod() {
	doble* actual = new doble();
	actual = primeros;
	doble* anterior = new doble();
	anterior = NULL;
	bool encontrado = false;
	string nodoBuscado;
	desplegarListaPU();
	cout << " INGRESE EL NOMBRE DEL DUENO A REGISTRAR: ";
	cin >> nodoBuscado;
	if (primeros != NULL) {

		while (actual != NULL && encontrado != true) {

			if (actual->dnombre == nodoBuscado) {
				cout << "\n Registro con el dato ( " << nodoBuscado << " ) Encontrado";

				if (actual == primeros) {
					primeros = primeros->siguientes;
					primeros->atrass = NULL;
				}
				else if (actual == ultimos) {
					anterior->siguientes = NULL;
					ultimos = anterior;
				}
				else {
					anterior->siguientes = actual->siguientes;
					actual->siguientes->atrass = anterior;
				}

				cout << "\n Registro Eliminado";
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguientes;
		}

		if (!encontrado) {
			cout << "\n Registro no Encontrado\n\n";
		}

	}
	else {
		cout << "\n La listas se encuentra Vacia\n\n";
	}
}

void menu_listadoble() {
	system("color 09 ");
	int eleccion;
	do {
		system("cls");
		poss(40, 9); cout << "------LISTA DOBLELEMENTE ENLAZADA-------";
		poss(40, 11); cout << "1. Ingresar duenos";
		poss(40, 12); cout << "2. Ver duenos ingresados ";
		poss(40, 13); cout << "3. Eliminar registros ";
		poss(40, 14); cout << "4. Regresar al menu principal ";
		poss(57, 17); cout << "__";
		poss(57, 19); cout << "__";
		poss(55, 18); cout << "|"; poss(56, 18); cout << "|";
		poss(60, 18); cout << "|"; poss(61, 18); cout << "|";
		poss(58, 18); cin >> eleccion;
		switch (eleccion) {
		case 1:system("cls"); insertarNodod(); break;
		case 2:system("cls"); desplegarListaPU(); break;
		case 3:system("cls"); eliminarNodod(); break;
		}

	} while (eleccion != 4);
}

// lista circular 

void insertarNodoSIRCULAR() {
	sircul* nuevo = new sircul();

	cout << " INGRESE EL NOMBRE DEL DUENO: ";
	cin >> nuevo->nombre;
	cout << " INGRESE EL TELEFONO: ";
	cin >> nuevo->no;
	cout << " INGRESE EL TIPO DE MASCOTA: ";
	cin >> nuevo->tmasota;

	if (primer == NULL) {
		primer = nuevo;
		primer->siguient = primer;
		ultim = primer;
	}
	else {
		ultim->siguient = nuevo;
		nuevo->siguient = primer;
		ultim = nuevo;
	}
	cout << "\n Nodo Ingresado\n\n";
}
void desplegarListaCIRCULAR() {
	sircul* actual = new sircul();
	actual = primer;
	if (primer != NULL) {
		do {
			cout << "                        *******" << endl;
			cout << " NOMBRE DEL DUENO       |" << actual->nombre << "            |" << endl;
			cout << " NO. TELEFONO           | " << actual->no << "        |" << endl;
			cout << " TIPO DE MASCOTA        | " << actual->tmasota << "          |" << endl;
			actual = actual->siguient;
			cout << " DIRECCION DE MEMORIA   | " << actual << "       |" << endl;
			cout << "                        *******\n";
		} while (actual != primer);
	}
	else {
		cout << "\n La lista se encuentra vacia\n\n";
	}system("pause");
}

void eliminarNodoCIRCULAR() {
	sircul* actual = new sircul();
	actual = primer;
	sircul* anterior = new sircul();
	anterior = NULL;
	bool encontrado = false;
	int nodoBuscado = 0;
	desplegarListaCIRCULAR();
	cout << "\n  INGRESE EL NO.TELEFONO DEL DUENO A ELIMINAR : ";
	cin >> nodoBuscado;
	if (primero != NULL) {
		do {

			if (actual->no == nodoBuscado) {
				cout << "\n El registro con el usuario ( " << nodoBuscado << " ) Encontrado";

				if (actual == primer) {
					primer = primer->siguient;
					ultim->siguient = primer;
				}
				else if (actual == ultim) {
					anterior->siguient = primer;
					ultim = anterior;
				}
				else {
					anterior->siguient = actual->siguient;
				}

				cout << "\n Registro Eliminado\n\n";
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguient;
		} while (actual != primer && encontrado != true);
		if (!encontrado) {
			cout << "\n Registro No Encontrado\n\n";
		}
	}
	else {
		cout << "\n La lista se encuentra vacia\n\n";
	}
}


void menu_listacircular() {
	system("color 09 ");
	int eleccion;
	do {
		system("cls");
		poss(40, 9); cout << "------LISTA CIRCULAR ENLAZADA-------";
		poss(40, 11); cout << "1. Ingresar duenos";
		poss(40, 12); cout << "2. Ver duenos ingresados ";
		poss(40, 13); cout << "3. Eliminar registros ";
		poss(40, 14); cout << "4. Regresar al menu principal ";
		poss(57, 17); cout << "__";
		poss(57, 19); cout << "__";
		poss(55, 18); cout << "|"; poss(56, 18); cout << "|";
		poss(60, 18); cout << "|"; poss(61, 18); cout << "|";
		poss(58, 18); cin >> eleccion;
		switch (eleccion) {
		case 1:system("cls"); insertarNodoSIRCULAR(); break;
		case 2:system("cls"); desplegarListaCIRCULAR(); break;
		case 3:system("cls"); eliminarNodoCIRCULAR(); break;
		}

	} while (eleccion != 4);
}
// ARBOL ABB

struct odo {
	int nro;
	string nombre;
	string receta;
	struct odo* izq, * der;
};
//prototipos ABB
//void mostrarArbol(odo* miArbol );

typedef struct odo* ABB;
/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
   para mayor facilidad de creacion de variables */

ABB crearNodo(int x)
{
	ABB nuevoNodo = new(struct odo);
	nuevoNodo->nro = x;
	nuevoNodo->nombre;
	nuevoNodo->receta;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;

	return nuevoNodo;
}
void insertar(ABB& arbol, int x)
{
	if (arbol == NULL)
	{
		arbol = crearNodo(x);
	}
	else if (x < arbol->nro)
		insertar(arbol->izq, x);
	else if (x > arbol->nro)
		insertar(arbol->der, x);
}

void preOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		cout << arbol->nro << " ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void enOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		enOrden(arbol->izq);
		cout << arbol->nro << " ";
		enOrden(arbol->der);
	}
}

void postOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout << arbol->nro << " ";
	}
}

//void verArbol(ABB arbol, int n)
//{
//	if (arbol == NULL)
//		return;
//	verArbol(arbol->der, n + 1);
//
//	for (int i = 0; i < n; i++)
//		cout << "   ";
//
//	cout << arbol->nro << endl;
//
//	verArbol(arbol->izq, n + 1);
//}
//Metodo Vertical
int auxX = 0;

void mostrarArbol(ABB arbol, int auxY) {
	if (arbol == NULL) {//Arbol vacio nada que mostrar

		return;
	}

	auxX += 5;//variable que permite posicionarse en el eje X

	mostrarArbol(arbol->izq, auxY + 2);//Se para hasta el nodo mas a la izquierda del árbol construye primero el subarbol izq porque sus valores en X son menores
	poss(20 + auxX - auxY, 10 + auxY);//posiciona el nodo segun sus variables en X y en Y

	cout << arbol->nro;// << endl << endl;//Muestra el dato del nodo respectivo

	//auxX = 0;
	mostrarArbol(arbol->der, auxY + 2);
}

int arbol()
{
	ABB arbol = NULL;   // creado Arbol

	int n;  // numero de nodos del arbol
	int x; // elemento a insertar en cada nodo
	string y;
	string z;

	cout << "\n\t\t  ...[ ARBOL BINARIO DE BUSQUEDA ]...  \n\n";

	cout << " Tamano del arbol:  ";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++)
	{

		cout << " Numero de comprobante  " << i + 1 << ": ";
		cin >> x;
		cout << " Nombre del cliente        ";
		cin >> y;
		cout << " Metodo de pago            ";
		cin >> z;
		cout << "\n";
		insertar(arbol, x);


	}system("cls");

	cout << "\n Mostrando Árbol ABB \n\n";
	//verArbol(arbol, 0);
	int contador = 0;
	mostrarArbol(arbol, contador);
	auxX = 0;

	cout << "\n Recorridos del Árbol ABB";

	cout << "\n\n En orden   :  ";   enOrden(arbol);
	cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
	cout << "\n\n Post Orden :  ";   postOrden(arbol);

	cout << endl << endl;

	system("pause");
	return 0;
}

//Arbol ABB EN VERTICAl 

//int auxX = 0;
//auxX = 0;
//mostrarArbol(miArbol, 0);
//
//void mostrarArbol(odo* miArbol, int auxY) {
//	
//	if (miArbol == NULL) {
//		return;
//	}
//	auxX += 5;
//	mostrarArbol(miArbol->izq, auxY + 2);
//	poss(10 + auxX - auxY, 15 + auxY);
//	cout << miArbol->dato << endl << endl;
//
//	mostrarArbol(miArbol->der, auxY + 2);
//}

//ARBOL AVL

struct Nodoavl {
	int data;
	Nodoavl* der;
	Nodoavl* izq;
};


//Identificadores
Nodoavl* crearRNodo(int);
void push(Nodoavl*&, int);
void view(Nodoavl*, int);
void menu();

class arbolAVL {
	int altura(Nodoavl*);
	int diferencia(Nodoavl*);
	Nodoavl* bal(Nodoavl*);
	Nodoavl* rr(Nodoavl*);
	Nodoavl* ll(Nodoavl*);
	Nodoavl* lr(Nodoavl*);
	Nodoavl* rl(Nodoavl*);
};

Nodoavl* arbolA = NULL;

int altura(Nodoavl* arbol) {
	int h = 0;
	if (arbol != NULL) {
		int lh = altura(arbol->izq);
		int rh = altura(arbol->der);
		int maxh = max(lh, rh);
		h = maxh + 1;
	}
	return h;
}

int diferencia(Nodoavl* arbol) {
	int lh = altura(arbol->izq);
	int rh = altura(arbol->der);
	int factor = lh - rh;
	return factor;
}

//void view(Nodoavl* arbol, int cont) {
//	if (arbol == NULL) {
//		return;
//	}
//	else {
//		view(arbol->der, cont + 1);
//		for (int it = 0; it < cont; it++) {
//			cout << "   ";
//		}
//		cout << arbol->data << endl;
//		view(arbol->izq, cont + 1);
//	}
//}
   //funcion para ver AVL en Vertical
int auxXZ = 0;

void view(Nodoavl* arbol, int auxY) { //arbol vacio nada que mostrar 

	if (arbol == NULL) {
		return;
	}
	auxXZ += 5;//Variable que permite poscionarse en el eje X

	view(arbol->izq, auxY + 2);//Más a la izquierda, construye primero el subarbol izq
	poss(18 + auxXZ - auxY, 10 + auxY);//posciona el nodo según sus variables en X y en Y
	cout << arbol->data;//Muestra el el dato del nodo respectivo 

	view(arbol->der, auxY + 2);
}

void menuAVL() {

	//Nodoavl arbol = NULL;
	int v = 0, op = 0, cont = 0;
	/*int contador = 0;
	auxXZ = 0;*/
	//view(arbol, contador);
	do {
		cout << "------------ Menu ------------" << endl;
		cout << "1-. Insertar nuevo nodo" << endl;
		cout << "2-. Imprimir arbol AVL" << endl;
		cout << "3-. Regresar al menu" << endl;
		cout << "------------------------------" << endl;
		cout << "-. "; cin >> op;
		cout << "------------------------------" << endl;

		switch (op) {
		case 1:
			cout << "-. Ingrese un numero: ";
			cin >> v; push(arbolA, v);
			cout << "------------------------------" << endl;
			break;
		case 2:
			cout << "Arbol AVL actual:" << endl;
			cout << "------------------------------" << endl;
			view(arbolA, cont);

			system("pause");
			break;
		}
		system("cls");
	} while (op != 3);
}

Nodoavl* rr(Nodoavl* parent) {
	Nodoavl* arbol;

	arbol = parent->der;
	parent->der = arbol->izq;
	arbol->izq = parent;

	cout << "Rotacion RR";
	return arbol;
}

Nodoavl* ll(Nodoavl* parent) {
	Nodoavl* arbol;

	arbol = parent->izq;
	parent->izq = arbol->der;
	arbol->der = parent;

	cout << "Rotacion LL";
	return arbol;
}

Nodoavl* lr(Nodoavl* parent) {
	Nodoavl* arbol;

	arbol = parent->izq;
	parent->izq = rr(arbol);

	cout << "Rotacion LR";
	return ll(parent);
}

Nodoavl* rl(Nodoavl* parent) {
	Nodoavl* arbol;

	arbol = parent->der;
	parent->der = ll(arbol);

	cout << "Rotacion RL";
	return rr(parent);
}

Nodoavl* bal(Nodoavl* arbol) {
	int factor = diferencia(arbol);

	if (factor > 1) {
		if (diferencia(arbol->izq) > 0) {
			arbol = ll(arbol);
		}
		else {
			arbol = lr(arbol);
		}
	}
	else if (factor < -1) {
		if (diferencia(arbol->der) > 0) {
			arbol = rl(arbol);
		}
		else {
			arbol = rr(arbol);
		}
	}
	return arbol;
}

void push(Nodoavl*& arbol, int n) {
	if (arbol == NULL) {
		cout << "Nodo vacio.. creando..." << endl;
		system("pause");

		Nodoavl* nuevoNodo = crearRNodo(n);
		arbol = nuevoNodo;
	}
	else {
		int root = arbol->data;
		if (n < root) {
			cout << "izquierda.." << endl;
			push(arbol->izq, n);
			arbol = bal(arbol);
		}
		else {
			cout << "derecha..." << endl;
			push(arbol->der, n);
			arbol = bal(arbol);
		}
	}
}

Nodoavl* crearRNodo(int n) {
	Nodoavl* nuevoNodo = new Nodoavl();
	nuevoNodo->data = n;
	nuevoNodo->der = NULL;
	nuevoNodo->izq = NULL;
	return nuevoNodo;
}



void menuPrincipal() {
	int op;
	do
	{
		system("cls");
		system("color 09 ");
		poss(35, 6); cout << "================VETERINARIA================";

		poss(35, 9); cout << "---------------MENU PRINCIPAL---------------";

		poss(35, 11); cout << "1. REGISTRO DE UNA MASCOTA(PILA)";
		poss(35, 12); cout << "2. REGISTRO DE UN DUENO(COLA)";
		poss(35, 13); cout << "3. REGISTRO DE MASCOTA (LISTA SIMPLEMENTE ENLAZADA)";
		poss(35, 14); cout << "4. REGISTRO DE DUENO   (LISTA DOBLEMENTE ENLAZADA)";
		poss(35, 15); cout << "5. REGISTRO DE MASCOTA (LISTA CIRCULAR)";
		poss(35, 16); cout << "6. COMPROBANTE (ARBOL)ABB";
		poss(35, 17); cout << "7. COMPROBANTE (ARBOL)AVL";
		poss(35, 18); cout << "8. SALIR			";
		poss(35, 19); cout << "===========================================";
		poss(54, 20); cout << "| |";
		poss(55, 21); cin >> op;
		system("cls");
		switch (op)
		{
		case 1:
			system("cls");
			menuPila();
			break;
		case 2:
			system("cls");
			menuCola();
			system("cls");
			break;
		case 3:menu_listasimple(); break;
		case 4:menu_listadoble(); break;
		case 5:menu_listacircular(); break;
		case 6:arbol(); break;
		case 7: menuAVL(); break;
		case 8: cout << "fin del programa :)";
			system("cls");
			break; break;

		default:
			system("cls");
			cout << "ERROR AL ELEGIR OPCION";
			system("pause");
			system("cls");
			break;
		}
	} while (op != 8);
}


int main()
{
	int posCol = 19;
	int posFil = 5;
	poss(11, 5); cout << "***     ***  ****** ********  ******   ******  ******  ***   **  ******  ******  ******  ******";
	poss(11, 6); cout << " ***   ***   ***       **     ***      **  **    **    ****  **  **  **  **  **    **    **  **";
	poss(11, 7); cout << "  *** ***    ******    **     ******   *****     **    ** ** **  ******  *****     **    ******";
	poss(11, 8); cout << "   *****     ***       **     ***      ** **     **    **  ****  **  **  ** **     **    **  **";
	poss(11, 9); cout << "    ***      ******    **     ******   **  **  ******  **   ***  **  **  **  **  ******  **  **";
	poss(45, 28); system("pause");
	system("cls");
	system("color 0f");
	menuPrincipal();
	system("cls");
	system("pause");
}