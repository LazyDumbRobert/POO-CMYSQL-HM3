// mysql_c++(2).cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "proveedores.h"

using namespace std;

Proveedores p;

void getData();
void deleteid();
void actualizar();

//Funcion principal
int main()
{
	int op;

	Proveedores p;
	do {
		system("cls");
		cout << "1.Agregar un proveedor" << endl;
		cout << "2.Leer Proveedores" << endl;
		cout << "3.Actualizar proveedor" << endl;
		cout << "4.Eliminar proveedor" << endl;
		cout << "0.Salir" << endl;
		cout << "Ingrese la opcion que desea realizar: ";
		cin >> op;

		switch (op) {
		case 1: getData(); break;
		case 2: p.leer(); break;
		case 3: actualizar(); break;
		case 4: deleteid(); break;
		case 0: break;
		default: cout << "La opcion que ingreso no existe, intentelo de nuevo" << endl; break;

		}
	} while (op != 0);
	
   system("pause");
   return 0;
}

void getData() {
	system("cls");
	string nit, proveedor, telefono, direccion;

	cout << "Ingrese el nit del proveedor: ";
	cin.ignore();
	getline(cin, nit);
	cout << "Ingrese el nombre del proveedor: ";
	getline(cin, proveedor);
	cout << "Ingrese el telefono del proveedor: ";
	getline(cin, telefono);
	cout << "Ingrese la direccion del proveedor: ";
	getline(cin, direccion);

	Proveedores p = Proveedores(proveedor, nit, direccion, telefono);
	p.ingresar();
}

void deleteid() {
	system("cls");
	int id;
	Proveedores p;
	cout << "Ingrese le id que desea eleminar: ";
	cin >> id;

	p.eliminar(id);
}

void actualizar() {
	system("cls");
	int id;
	string nit, proveedor, telefono, direccion;
	cout << "Ingrese le id que desea actualizar: ";
	cin >> id;

	cout << "Ingrese el nuevo nit del proveedor: ";
	cin.ignore();
	getline(cin, nit);
	cout << "Ingrese el nuevo nombre del proveedor: ";
	getline(cin, proveedor);
	cout << "Ingrese el nuevo telefono del proveedor: ";
	getline(cin, telefono);
	cout << "Ingrese la nueva direccion del proveedor: ";
	getline(cin, direccion);

	Proveedores p = Proveedores(proveedor, nit, direccion, telefono);
	p.actualizar(id);
}