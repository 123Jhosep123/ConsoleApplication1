#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <windows.h>
using namespace std;

struct Registro
{
	string nomUsuario;
	string conUsuario;
};

struct RegistroAdmi
{
	string nomAdmi;
	string conAdmi;
};
struct Producto
{
	string nomCliente;
	int codProducto;
	float preProducto;
	string nomProducto;
	int stkProducto;
	float importe;
};
vector<Producto> vecProducto;
vector<Registro> vecRegistro;
vector<RegistroAdmi> vecRegistroAdmi;

void registroInicio();
void registroAdmini();
void registroUsuario();
void inicioSecion();
bool iniciarSecionAdmi();
bool iniciarSesion();
void sistemaVentas();
void sistemaUsuario();
void registroAdministradores();
void registroVendedores();
void mostrarClientes();
void registroProducto();
void generarVenta();
void anularVenta();
void registroCompra();
void eliminarProducto();
int getCorrelativoPro();
string getPassword();
void gotoxy(int x, int y);
void cuadro(int x1, int y1, int x2, int y2);

int main() {
	system("COLOR B0");
	int opcion;

	do {
		cuadro(1, 1, 102, 19);
		cuadro(1, 1, 101, 3);
		gotoxy(46, 2); cout << "INICIO DE SESION";
		gotoxy(2, 12);

		gotoxy(3, 6);
		cout << "REGISTRAR\t\t\t<1>" << endl;
		gotoxy(3, 8);
		cout << "INICIAR SESION\t\t<2>" << endl;
		gotoxy(3, 10);
		cout << "SALIR\t\t\t<3>" << endl;
		gotoxy(3, 12);
		cout << "Elegir una opción[1-3]: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			system("cls");
			registroInicio();
			break;
		case 2:
			system("cls");
			inicioSecion();
			system("pause");
			system("cls");
			break;
		case 3:
			return 0;
		default:
			cout << "Opción no válida. Por favor, selecciona una opción válida." << endl;
			break;
		}
	} while (opcion != 3);

}
void registroInicio()
{
	int opcion;
	do {
		cout << "TIPO DE REGISTRO\n";
		cout << "REGISTRAR COMO ADMINISTRADOR-----[1]\n";
		cout << "REGISTRAR COMO VENDEDOR----------[2]\n";
		cout << "SALIR----------------------------[3]\n";
		cout << "Ingresar una opcion [1-3]: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1: system("cls");
			registroAdmini();
			break;
		case 2: system("cls");
			registroUsuario();
			break;
		case 3: system("cls"); return;
		default: cout << "Ingresar una opcion correcta";
			break;
		}
	} while (opcion != 3);
}
void registroAdmini()
{
	string nomA;
	string conA, rpta;
	do {
		cin.ignore();
		cout << "Usuario de Administrador: ";
		getline(cin, nomA);

		cout << "Contraseña: ";
		conA = getPassword();

		RegistroAdmi registroAdmi;
		registroAdmi.nomAdmi = nomA;
		registroAdmi.conAdmi = conA;

		vecRegistroAdmi.push_back(registroAdmi);
		cout << "Desea agregar otro usuario (S/s): ";
		cin >> rpta;
		system("cls");
	} while (rpta == "S" || rpta == "s");
}
void registroUsuario()
{
	string nomUsu;
	string conUsu, rpta;
	do {
		cin.ignore();
		cout << "Usuario de Vendedor: ";
		getline(cin, nomUsu);

		cout << "Contraseña: ";
		cin >> conUsu;

		Registro registro;
		registro.nomUsuario = nomUsu;
		registro.conUsuario = conUsu;

		vecRegistro.push_back(registro);
		cout << "Desea agregar otro usuario {S/s): ";
		cin >> rpta;
		system("cls");
	} while (rpta == "S" || rpta == "s");
}
bool iniciarSecionAdmi(vector<RegistroAdmi>& vecRegistroAdmi)
{
	string nomAdministrador, contra;
	int intentos = 0;
	char caracter;
	while (intentos < 3)
	{
		cin.ignore();
		cout << "Nombre de Administrador: ";
		getline(cin, nomAdministrador);

		cout << "Contraseña: ";
		contra = getPassword();
		while (true)
		{
			caracter = _getch();
			if (caracter == 13)
				break;
			contra += caracter;
			cout << '*';
		}

		bool sesionIniciada = false;

		for (size_t i = 0; i < vecRegistroAdmi.size(); ++i) {
			if (vecRegistroAdmi[i].nomAdmi == nomAdministrador && vecRegistroAdmi[i].conAdmi == contra)
			{
				cout << "\n¡Sesión iniciada con éxito!" << endl;
				sesionIniciada = true;
				break;
			}
		}

		if (sesionIniciada)
		{
			return true;
		}
		else
		{
			intentos++;
			if (intentos < 3)
			{
				cout << "\nError al iniciar sesión. Intentos restantes: " << 3 - intentos << endl;
			}
			else
			{
				cout << "\nSe excedió el número máximo de intentos." << endl;
				break;
			}
		}
	}

	return false;
}
bool iniciarSesion(vector<Registro>& vecRegistro)
{
	string nombreUsuario, contrasena;
	cin.ignore();
	int intentos = 0;
	while (intentos < 3)
	{
		cout << "Usuario de Vendedor: ";
		getline(cin, nombreUsuario);

		cout << "Contraseña: ";
		char caracter;
		contrasena = "";
		while (true)
		{
			caracter = _getch();
			if (caracter == 13)
				break;
			contrasena += caracter;
			cout << '*';

		}

		bool sesionIniciada = false;

		for (size_t i = 0; i < vecRegistro.size(); ++i)
		{
			if (vecRegistro[i].nomUsuario == nombreUsuario && vecRegistro[i].conUsuario == contrasena) {
				cout << "\n¡Sesión iniciada con éxito!" << endl;
				sesionIniciada = true;
				break;
			}
		}

		if (sesionIniciada)
		{
			return true;
		}
		else
		{
			intentos++;
			if (intentos < 3)
			{
				cout << "\nError al iniciar sesión. Intentos restantes: " << 3 - intentos << endl;
			}
			else
			{
				cout << "\nSe excedió el número máximo de intentos." << endl;
				break;
			}
		}
	}

	return false;
}
void inicioSecion()
{
	int opcion;
	do {
		cout << "TIPO DE INICIO DE SECION\n";
		cout << "INICIAR SECION COMO ADMINISTRADOR-----[1]\n";
		cout << "INICIAR SECION COMO VENDEDOR----------[2]\n";
		cout << "SALIR----------------------------[3]\n";
		cout << "Ingresar una opcion [1-3]: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1: system("cls");
			if (iniciarSecionAdmi(vecRegistroAdmi))
			{
				system("pause"); system("cls"); sistemaVentas();
			}
			break;
		case 2: system("cls");
			if (iniciarSesion(vecRegistro))
			{
				system("pause"); system("cls"); sistemaUsuario(); system("cls");
			}
			break;
		case 3: system("cls");
			return;
			break;
		default: cout << "Ingresar una opcion correcta";
			break;
		}
	} while (opcion != 3);
}
void sistemaVentas()
{
	int opcion;
	do
	{
		cout << "======MENU DE OPCIONES======\n";
		cout << "Mostrar Administradores\t\t\t<1>\n";
		cout << "Mostrar Vendedores\t\t\t<2>\n";
		cout << "Mostrar Clientes\t\t\t<3>\n";
		cout << "Mostrar de productos\t\t\t<4>\n";
		cout << "Generar venta\t\t\t\t<5>\n";
		cout << "Anular venta\t\t\t\t<6>\n";
		cout << "Salir\t\t\t\t\t<7>\n";
		cout << "Ingrese una opción (1-7): "; cin >> opcion;
		switch (opcion)
		{
		case 1:system("cls"); registroAdministradores(); break;
		case 2:system("cls"); registroVendedores(); break;
		case 3:system("cls"); mostrarClientes(); break;
		case 4:system("cls"); registroProducto(); break;
		case 5:system("cls"); generarVenta(); break;
		case 6:system("cls"); anularVenta(); break;
		case 7:system("cls"); break;
		}
	} while (opcion != 7);
}
void registroAdministradores()
{
	for (int i = 0; i < vecRegistroAdmi.size(); i++)
	{
		cout << "-------------------------\n";
		cout << "Nombre de Administrador: " << vecRegistroAdmi[i].nomAdmi << endl;
		cout << "-------------------------\n";
	}
	system("pause");
	system("cls");
}
void registroVendedores()
{
	for (int i = 0; i < vecRegistro.size(); i++)
	{
		cout << "-------------------------\n";
		cout << "Nombre de Vendedor: " << vecRegistro[i].nomUsuario << endl;
		cout << "-------------------------\n";
	}
	system("pause");
	system("cls");
}
void mostrarClientes()
{
	for (int i = 0; i < vecProducto.size(); i++)
	{
		cout << "-------------------------\n";
		cout << "Nombre de Cliente: " << vecProducto[i].nomCliente << endl;
		cout << "-------------------------\n";
	}
	system("pause");
	system("cls");
}
void registroProducto()
{
	for (int i = 0; i < vecProducto.size(); i++)
	{
		cout << "-------------------------\n";
		cout << "Codigo del Producto: " << vecProducto[i].codProducto << endl;
		cout << "Nombre del Comprador: " << vecProducto[i].nomCliente << endl;
		cout << "Nombre del Producto: " << vecProducto[i].nomProducto << endl;
		cout << "Precio del Producto: " << vecProducto[i].preProducto << endl;
		cout << "Stock del Producto: " << vecProducto[i].stkProducto << endl;
		cout << "Importe del Producto: " << vecProducto[i].importe << endl;
		cout << "-------------------------\n";
	}
	system("pause");
	system("cls");
}
void generarVenta()
{
	for (int i = 0; i < vecRegistro.size(); i++)
	{
		for (int j = 0; j < vecProducto.size(); j++)
		{
			cout << "| Nombre del Vendedor: " << vecRegistro[i].nomUsuario << "--" << "Nombre del Cliente: " << vecProducto[j].nomCliente << "--" << "Producto: " << vecProducto[j].nomProducto << "--" << "Importe: " << vecProducto[j].importe << " |" << endl;
		}
	}
	system("pause");
	system("cls");
}
void anularVenta()
{
	int  cod;
	string rpta;
	bool flag = false;
	do {
		cout << "Ingrese el codigo del producto a eliminar:";
		cin >> cod;
		for (int i = 0; i < vecProducto.size(); i++)
		{
			if (cod == vecProducto[i].codProducto)
			{
				vecProducto.erase(vecProducto.begin() + i);
				flag = true;
				break;
			}
		}
		if (flag == true)
		{
			cout << "Venta eliminada satisfactoriamente!!!\n";
		}
		else
		{
			cout << "Codigo ingresado no existe!!!\n";
		}
		cout << "Desea eliminar otro producto [S/s]: ";
		cin >> rpta;
		system("cls");
	} while (rpta == "S" || rpta == "s");
}
void sistemaUsuario()
{
	int opcion;
	do
	{
		cout << "======MENU DE OPCIONES======\n";
		cout << "Agregar Compra\t\t\t<1>\n";
		cout << "Eliminar Compra\t\t\t<2>\n";
		cout << "Salir\t\t\t\t<3>\n";
		cout << "Ingresar una opcion (1-3): ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			system("cls");
			registroCompra();
			system("cls");
			break;
		case 2: system("cls");
			eliminarProducto();
			system("pause");
			system("cls");
			break;
		case 3: return;
			break;
		default: cout << "Ingresar una opcion correcta";
			break;
		}
	} while (opcion != 3);
}
void registroCompra()
{
	string nomCli, nomPro, rpta;
	int codPro, stkPro;
	float prePro, impor;
	do
	{
		codPro = getCorrelativoPro();
		cout << "Codigo: " << codPro << endl;
		cin.ignore();
		cout << "Nombre del Cliente: "; getline(cin, nomCli);
		cout << "Nombre del Producto: "; getline(cin, nomPro);
		cout << "Precio: "; cin >> prePro;
		cout << "Stock: "; cin >> stkPro;
		impor = prePro * stkPro;
		cout << "Importe: " << impor << endl;
		Producto producto;
		producto.nomCliente = nomCli;
		producto.codProducto = codPro;
		producto.nomProducto = nomPro;
		producto.preProducto = prePro;
		producto.stkProducto = stkPro;
		producto.importe = impor;
		vecProducto.push_back(producto);
		cout << "Si desea continuar registrando productos, presione (S o s): "; cin >> rpta;
		system("pause");
		system("cls");
	} while (rpta == "S" || rpta == "s");
}
int getCorrelativoPro()
{
	if (vecProducto.size() == 0)
	{
		return 1;
	}
	else
	{
		return vecProducto[vecProducto.size() - 1].codProducto + 1;
	}
}
void eliminarProducto()
{
	int  cod;
	string rpta;
	do {
		bool flag = false;
		cout << "Ingrese el codigo del producto a eliminar:";
		cin >> cod;
		for (int i = 0; i < vecProducto.size(); i++)
		{
			if (cod == vecProducto[i].codProducto)
			{
				vecProducto.erase(vecProducto.begin() + i);
				flag = true;
				break;
			}
		}
		if (flag == true)
		{
			cout << "Venta eliminada satisfactoriamente!!!\n";
		}
		else
		{
			cout << "Codigo ingresado no existe!!!\n";
		}
		cout << "Desea eliminar otro producto [S/s]: ";
		cin >> rpta;
		system("cls");
	} while (rpta == "S" || rpta == "s");
}
void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void cuadro(int x1, int y1, int x2, int y2)
{
	int i;
	char carac = 219;

	for (i = x1; i < x2; i++)
	{
		gotoxy(i, y1);
		printf("%c", carac);
		gotoxy(i, y2);
		printf("%c", carac);
	}
	for (i = y1; i < y2; i++)
	{
		gotoxy(x1, i);
		printf("%c", carac);
		gotoxy(x2, i);
		printf("%c", carac);
	}
	gotoxy(x1, y1);
	printf("%c", carac);
	gotoxy(x1, y2);
	printf("%c", carac);
	gotoxy(x2, y1);
	printf("%c", carac);
	gotoxy(x2, y2);
	printf("%c", carac);
}
string getPassword()
{
	string password = "";
	char ch;

	while (true) {
		ch = _getch();

		if (ch == 13) { // Si se presiona Enter
			cout << endl;
			break;
		}
		else if (ch == 8) { // Si se presiona Backspace
			if (!password.empty()) {
				password.pop_back();
				cout << "\b \b"; // Retrocede y borra el último carácter visualmente
			}
		}
		else {
			password.push_back(ch);
			cout << '*';
		}
	}

	return password;
}