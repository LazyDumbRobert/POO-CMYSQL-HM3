#pragma once

#include<iostream>
#include "ConexionDB2.h"
#include<string>
#include<mysql.h>

using namespace std;

class Proveedores {
private:
	string proveedor, nit, direccion, telefono;

public:
	Proveedores() {

	}
	Proveedores(string prov, string nit2, string adress, string tel) {
		proveedor = prov;
		nit = nit2;
		direccion = adress;
		telefono = tel;
	}


	//Metodos set y get

	void setProv(string prov) { proveedor = prov; }
	void setNit(string nit_1) { nit = nit_1; }
	void setAdress(string Adress) { direccion = Adress; }
	void setTel(string tel) { telefono = tel; }

	string getProv() { return proveedor; }
	string setNit() { return nit; }
	string setAdress() { return direccion; }
	string setTel() { return telefono; }

	void leer() {
		system("cls");
		int q_estado;
		ConexionBD2 cn = ConexionBD2();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "\t\tProductos" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << "ID de proveedor: " << fila[0] << endl;
					cout << "Proveedor: " << fila[1] << endl;
					cout << "NIT: " << fila[2] << endl;
					cout << "Direccion: " << fila[3] << endl;
					cout << "Telefono: " << fila[4] << endl;
					cout << "____________________________________________" << endl;
				}
			}
		}
		cout << "____________________________________________" << endl;
		cn.cerrar_conexion();
		system("pause");
	}

	
	void ingresar() {
		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string insertar = "INSERT INTO `proveedores`(`proveedor`,`nit`,`direccion`,`telefono`) VALUES('" + proveedor + "','" + nit + "','" + direccion + "','" + telefono + "')";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (q_estado) {
				system("cls");
				cout << "Ingreso exitoso" << endl;
				system("pause");
			}
		}
		else {
			system("cls");
			cout << "Hubo un error al ingresar los datos" << endl;
			system("pause");
		}
		cn.cerrar_conexion();
		system("pause");
	}

	
	void eliminar(int id_p) {

		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string id_p1 = to_string(id_p);
			string eliminar = "DELETE from proveedores where id_proveedores = " + id_p1 + "";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				system("cls");
				cout << "Eliminacion exitosa" << endl;
			}
		}
		else {
			system("cls");
			cout << "Hubo un error a la hora de eliminar el registro deseado" << endl;
			system("pause");
		}
	cn.cerrar_conexion();
	system("pause");
}

	void actualizar(int id_p) {

		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string id_p1 = to_string(id_p);
			string eliminar = "UPDATE `proveedores` SET `proveedor` = '"+proveedor+"', `nit` = '"+nit+"', `direccion` = '"+direccion+"', `telefono` = '"+telefono+"' WHERE(`id_proveedores` = "+id_p1+");";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				system("cls");
				cout << "Actualizacion exitosa" << endl;
			}
		}
		else {
			system("cls");
			cout << "Hubo un error a la hora de eliminar el registro deseado" << endl;
			system("pause");
		}
		cn.cerrar_conexion();
		system("pause");
	}

	

};


