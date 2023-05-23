#include <iostream>
#include <string>
#include <cstdlib>
// Para manejo de archivos
#include <fstream>
// Para toma los segundos
#include <chrono>
using namespace std;

/*CLASE JUGADOR*/
class Jugador
{
public:
    // Constructor por defecto
    Jugador(); 
    // Constructor con parámetros                                                                                                    
    Jugador(int id, string movimiento, int tiempo, string tipoJugador, char simboloJugador, int fila, int columna);

    // Setters
    void setId(int id);
    void setMovimiento(string movimiento);
    void setTiempo(int tiempo);
    void setTipoJugador(string tipoJugador);
    void setSimboloJugador(char simboloJugador);
    void setFila(int fila);
    void setColumna(int columna);

    // Getters
    int getId();
    string getMovimiento();
    int getTiempo();
    string getTipoJugador();
    char getSimboloJugador();
    int getFila();
    int getColumna();

    // Otros métodos
    void imprimirDatos();

private:
    int id;
    string movimiento;
    int tiempo;
    string tipoJugador;
    char simboloJugador;
    int fila;
    int columna;
};

// Constructor sin parametros
Jugador::Jugador()
{
    id = 0;
    movimiento = "";
    tiempo = 0;
    tipoJugador = "";
    simboloJugador = '-';
    fila = 0;
    columna = 0;
}

// Constructor con parametros
Jugador::Jugador(int id, string movimiento, int tiempo, string tipoJugador, char simboloJugador, int fila, int columna)
{
    this->id = id;
    this->movimiento = movimiento;
    this->tiempo = tiempo;
    this->tipoJugador = tipoJugador;
    this->simboloJugador = simboloJugador;
    this->fila = fila;
    this->columna = columna;
}

void Jugador::setId(int id)
{
    this->id = id;
}

void Jugador::setMovimiento(string movimiento)
{
    this->movimiento = movimiento;
}

void Jugador::setTiempo(int tiempo)
{
    this->tiempo = tiempo;
}

void Jugador::setTipoJugador(string tipoJugador)
{
    this->tipoJugador = tipoJugador;
}

void Jugador::setSimboloJugador(char simboloJugador)
{
    this->simboloJugador = simboloJugador;
}

void Jugador::setFila(int fila)
{
    this->fila = fila;
}

void Jugador::setColumna(int columna)
{
    this->columna = columna;
}

int Jugador::getId()
{
    return id;
}

string Jugador::getMovimiento()
{
    return movimiento;
}
int Jugador::getTiempo()
{
    return tiempo;
}

string Jugador::getTipoJugador()
{
    return tipoJugador;
}

char Jugador::getSimboloJugador()
{
    return simboloJugador;
}

int Jugador::getFila()
{
    return fila;
}

int Jugador::getColumna()
{
    return columna;
}

void Jugador::imprimirDatos()
{
    cout << "id: " << id << endl;
    cout << "movimiento: " << movimiento << endl;
    cout << "Tiempo: " << tiempo << endl;
    cout << "Tipo jugador: " << tipoJugador << endl;
    cout << "Simbolo Jugador: " << tipoJugador << endl;
    cout << "Fila: " << fila << endl;
    cout << "columna: " << columna << endl;
}
/* -----------------------------------------------*/
/* -----------------------------------------------*/
/* --------------- FIN CLASE JUGADOR ---------------*/
/* -----------------------------------------------*/
/* -----------------------------------------------*/

/*CLASE VISTA*/
class Vista
{
public:
    Vista();
    void mostrarMenu();
    void mostrarTablero(char c[3][3]);
    void asignaValores(char c[3][3]);

private:
};

Vista::Vista()
{
}

void Vista::mostrarMenu()
{
    cout << "----- MENU -----" << endl;
    cout << "1. Jugador vs Jugador" << endl;
    cout << "2. Jugador vs IA" << endl;
    cout << "3. IA vs IA" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void Vista::mostrarTablero(char c[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j < 2)
            {
                cout << " " << c[i][j] << " |";
            }
            else
            {
                cout << " " << c[i][j] << " ";
            }
        }
        if (i < 2)
        {
            cout << "\n-----------\n";
        }
    }
    cout << endl;
}

// Funcion que solo se utiliza una sola vez para asignar valores del 1-9 a las opciones del juego
void Vista::asignaValores(char c[3][3])
{
    char aux;
    aux = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = aux++;
        }
    }
}
/* -----------------------------------------------*/
/* -----------------------------------------------*/
/* --------------- FIN CLASE VISTA ---------------*/
/* -----------------------------------------------*/
/* -----------------------------------------------*/

/*CLASE DATOS*/
class Datos
{
public:
    Datos();
    Datos(Jugador jugador);
    void crearOrEscribirTXT(Jugador jugador);

private:
};

Datos::Datos() {}

Datos::Datos(Jugador jugador)
{
    crearOrEscribirTXT(jugador);
}

void Datos::crearOrEscribirTXT(Jugador jugador)
{
    // Crear y escribir en el archivo
    ofstream archivo("data.txt", ios::app); // ios::app = Este modo de apertura indica que el archivo se abrirá en modo de adición
    if (archivo.is_open())
    {
        archivo
            << jugador.getId() << ", " << jugador.getMovimiento() << ", " << jugador.getTiempo() << ", "
            << jugador.getId() << ", " << jugador.getTipoJugador() << ", "
            << jugador.getSimboloJugador() << ", "
            << "[" << jugador.getColumna()
            << "], [" << jugador.getFila() << "]" << endl;
        archivo.close();
    }
    else
    {
        cout << "Error abriendo el archivo." << endl;
    }
}

/* -----------------------------------------------*/
/* -----------------------------------------------*/
/* --------------- FIN CLASE DATOS ---------------*/
/* -----------------------------------------------*/
/* -----------------------------------------------*/

/*CLASE NEGOCIO*/
class Negocio
{
private:
    Vista vista;
    Datos datos;
    Jugador jugador;
    char c[3][3];
    int ganador(char c[3][3]);
    void escogerOpcion();
    void jugadorVsJugador(char c[3][3]);
    void jugadorVsComputadora(char c[3][3]);
    void computadoraVsComputadora(char c[3][3]);
    void introUser(char (*c)[3], char determinado = 'X');
    void introIa(char (*c)[3], char determinado = 'X');

public:
    Negocio(Vista vista, Datos datos);
    void ejecutarPrograma();
};

// Constructor
Negocio::Negocio(Vista vista, Datos datos)
{
    this->vista = vista;
    this->datos = datos;
}

// Metodos

// Función que ejecuta el juego
void Negocio::ejecutarPrograma()
{
    escogerOpcion();
}

void Negocio::jugadorVsJugador(char c[3][3])
{
    int i = 0, j, id;
    vista.asignaValores(c);
    do
    {
        system("cls");
        vista.mostrarTablero(c);
        if (i % 2 == 0)
        {
            introUser(c);
            id = 1;
        }
        else
        {
            introUser(c, 'O');
            id = 2;
        }
        j = ganador(c);

        i++;

        this->datos.crearOrEscribirTXT(Jugador(id, "movimiento " + to_string(i), jugador.getTiempo(), jugador.getTipoJugador(),
                                               jugador.getSimboloJugador(), jugador.getFila(), jugador.getColumna()));

    } while (i <= 9 && j == -1);

    system("cls");
    vista.mostrarTablero(c);

    if (j == 0)
    {
        cout << "Ha ganado la X" << endl << endl;
    }
    else if (j == 1)
    {
        cout << "Ha ganado la O" << endl << endl;
    }
    else
    {
        cout << "Empate" << endl << endl;
    }
}

void Negocio::jugadorVsComputadora(char c[3][3])
{
    int i = 0, j, id;
    vista.asignaValores(c);
    do
    {
        system("cls");
        vista.mostrarTablero(c);
        if (i % 2 == 0)
        {
            introUser(c);
            id = 1;
        }
        else
        {
            introIa(c);
            id = 2;
        }
        j = ganador(c);

        i++;

        this->datos.crearOrEscribirTXT(Jugador(id, "movimiento " + to_string(i), jugador.getTiempo(), jugador.getTipoJugador(),
                                               jugador.getSimboloJugador(), jugador.getFila(), jugador.getColumna()));

    } while (i <= 9 && j == -1);

    system("cls");
    vista.mostrarTablero(c);

    if (j == 0)
    {
        cout << "Haz ganado" << endl;
    }
    else if (j == 1)
    {
        cout << "Haz perdido" << endl;
    }
    else
    {
        cout << "Empate" << endl;
    }
}

void Negocio::computadoraVsComputadora(char c[3][3])
{
    int i = 0, j, id;
    vista.asignaValores(c);
    do
    {
        system("cls");
        vista.mostrarTablero(c);
        if (i % 2 == 0)
        {
            introIa(c);
            id = 1;
        }
        else
        {
            introIa(c, 'O');
            id = 2;
        }
        j = ganador(c);

        i++;

        this->datos.crearOrEscribirTXT(Jugador(id, "movimiento " + to_string(i), jugador.getTiempo(), jugador.getTipoJugador(),
                                               jugador.getSimboloJugador(), jugador.getFila(), jugador.getColumna()));

    } while (i <= 9 && j == -1);

    system("cls");
    vista.mostrarTablero(c);

    if (j == 0)
    {
        cout << "Haz ganado" << endl;
    }
    else if (j == 1)
    {
        cout << "Haz perdido" << endl;
    }
    else
    {
        cout << "Empate" << endl;
    }
}

void Negocio::escogerOpcion()
{
    int opcion;
    do
    {
        this->vista.mostrarMenu();

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // código para jugar Jugador vs Jugador
            jugadorVsJugador(c);
            break;
        case 2:
            // código para jugar Jugador vs IA
            jugadorVsComputadora(c);
            break;
        case 3:
            // código para jugar IA vs IA
            computadoraVsComputadora(c);
            break;
        case 4:
            cout << "Restablecer una partida" << endl;
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);
}

// funcion que evalua los movimientos del usuario
void Negocio::introUser(char (*c)[3], char determinado)
{
    int segundos;
    char aux;
    int i, j, k;
    do
    {
        do
        {
            // se crea una variable start para calcula los segundos que le toma al usuario en escoger un movimiento 
            auto start = chrono::high_resolution_clock::now();

            cout << "Escoge un numero del 1-9: ";
            fflush(stdin);
            cin >> aux;

            // se crea una variable end para atrapar los segundos 
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(end - start);
            // Se asigna los segundos a la variable 'segundos'
            segundos = duration.count();

        } while (aux < '1' || aux > '9');

        k = 0;

        switch (aux)
        {
        case '1':
            i = 0;
            j = 0;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                cout << "Casilla Ocupada!! Pruebe con otra casilla";
            }
            break;
        case '2':
            i = 0;
            j = 1;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                cout << "Casilla Ocupada!! Pruebe con otra casilla";
            }
            break;
        case '3':
            i = 0;
            j = 2;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                cout << "Casilla Ocupada!! Pruebe con otra casilla";
            }
            break;
        case '4':
            i = 1;
            j = 0;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                cout << "Casilla Ocupada!! Pruebe con otra casilla";
            }
            break;
        case '5':
            i = 1;
            j = 1;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                cout << "Casilla Ocupada!! Pruebe con otra casilla";
            }
            break;
        case '6':
            i = 1;
            j = 2;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                cout << "Casilla Ocupada!! Pruebe con otra casilla";
            }
            break;
        case '7':
            i = 2;
            j = 0;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                cout << "Casilla Ocupada!! Pruebe con otra casilla";
            }
            break;
        case '8':
            i = 2;
            j = 1;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                cout << "Casilla Ocupada!! Pruebe con otra casilla";
            }
            break;
        case '9':
            i = 2;
            j = 2;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                cout << "Casilla Ocupada!! Pruebe con otra casilla";
            }
            break;

        default:
            break;
        }
    } while (k == 1);

    c[i][j] = determinado;
    jugador.setFila(i);
    jugador.setColumna(j);
    jugador.setTipoJugador("HUMANO");
    jugador.setSimboloJugador('X');
    jugador.setTiempo(segundos);
}

void Negocio::introIa(char (*c)[3], char determinado)
{
    int i, j, k;
    char aux;
    srand(time(nullptr));
    do
    {
        k = 0;
        i = rand() % 3;
        j = rand() % 3;
        if (c[i][j] == 'X' || c[i][j] == 'O')
        {
            k = 1;
        }

    } while (k == 1);
    c[i][j] = determinado;
    jugador.setFila(i);
    jugador.setColumna(j);
    jugador.setTipoJugador("COMPUTADORA");
    jugador.setSimboloJugador('O');
    jugador.setTiempo(0);
}

int Negocio::ganador(char c[3][3])
{
    if (c[0][0] == 'X' || c[0][0] == 'O')
    {
        if (c[0][0] == c[0][1] && c[0][0] == c[0][2])
        {
            if (c[0][0] == 'X')
            {
                return 0; // Ganador
            }
            else
            {
                return 1; // Perdedor
            }
        }
        if (c[0][0] == c[1][0] && c[0][0] == c[2][0])
        {
            if (c[0][0] == 'X')
            {
                return 0; // Ganador
            }
            else
            {
                return 1; // Perdedor
            }
        }
    }

    if (c[1][1] == 'X' || c[1][1] == 'O')
    {
        if (c[1][1] == c[0][0] && c[1][1] == c[2][2])
        {
            if (c[1][1] == 'X')
            {
                return 0; // Ganador
            }
            else
            {
                return 1; // Perdedor
            }
        }

        if (c[1][1] == c[1][0] && c[1][1] == c[1][2])
        {
            if (c[1][1] == 'X')
            {
                return 0; // Ganador
            }
            else
            {
                return 1; // Perdedor
            }
        }

        if (c[1][1] == c[2][0] && c[1][1] == c[0][2])
        {
            if (c[1][1] == 'X')
            {
                return 0; // Ganador
            }
            else
            {
                return 1; // Perdedor
            }
        }

        if (c[1][1] == c[0][1] && c[1][1] == c[2][1])
        {
            if (c[1][1] == 'X')
            {
                return 0; // Ganador
            }
            else
            {
                return 1; // Perdedor
            }
        }
    }
    if (c[2][2] == 'X' || c[2][2] == 'O')
    {
        if (c[2][2] == c[2][0] && c[2][2] == c[2][1])
        {
            if (c[2][2] == 'X')
            {
                return 0; // Ganador
            }
            else
            {
                return 1; // Perdedor
            }
        }
        if (c[2][2] == c[0][2] && c[2][2] == c[1][2])
        {
            if (c[2][2] == 'X')
            {
                return 0; // Ganador
            }
            else
            {
                return 1; // Perdedor
            }
        }
    }
    return -1;
}
/* -----------------------------------------------*/
/* -----------------------------------------------*/
/* --------------- FIN CLASE NEGOCIO ---------------*/
/* -----------------------------------------------*/
/* -----------------------------------------------*/

int main()
{
    Vista vista;
    Datos datos;
    Negocio negocio = Negocio(vista, datos);
    negocio.ejecutarPrograma();
    return 0;
}
