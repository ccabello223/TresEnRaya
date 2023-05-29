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
    void introIa(char (*c)[3], char determinado = 'X', int *yDestino = nullptr, int *xDestino = nullptr);
    void copiarTablero(char (*origen)[3], char (*destino)[3]);
    void coordenadasParaGanar(char caracter, char tableroOriginal[3][3], int *yDestino, int *xDestino);
    


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
            introIa(c, 'O',0,0);
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
            introIa(c, 'O',0,0);
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

int contarHaciaArriba(int x, int y, char caracter, char tablero[3][3])
{
    // Determinar el índice de inicio de y para el bucle.
    int yInicio = (y - 3 >= 0) ? y - 3 + 1 : 0;
    int contador = 0;
    
    // Recorrer hacia arriba desde yInicio hasta y, contando caracteres iguales.
    for (; yInicio <= y; yInicio++)
    {
        if (tablero[yInicio][x] == 'O')
        {
            contador++; // Incrementar el contador si se encuentra un caracter igual.
        }
        else
        {
            contador = 0; // Reiniciar el contador si se encuentra un caracter diferente.
        }
    }
    
    return contador; // Devolver el contador final.
}


int contarHaciaDerecha(int x, int y, char caracter, char tablero[3][3])
{
    // Determinar el índice de fin de x para el bucle.
    int xFin = (x + 3 < 3) ? x + 3 - 1 : 3 - 1;
    int contador = 0;
    
    // Recorrer hacia la derecha desde x hasta xFin, contando caracteres iguales.
    for (; x <= xFin; x++)
    {
        if (tablero[y][x] == caracter)
        {
            contador++; // Incrementar el contador si se encuentra un caracter igual.
        }
        else
        {
            contador = 0; // Reiniciar el contador si se encuentra un caracter diferente.
        }
    }
    
    return contador; // Devolver el contador final.
}

int contarHaciaArribaDerecha(int x, int y, char caracter, char tablero[3][3])
{
    // Determinar el índice de fin de x para el bucle.
    int xFin = (x + 3 < 3) ? x + 3 - 1 : 3 - 1;
    // Determinar el índice de inicio de y para el bucle.
    int yInicio = (y - 3 >= 0) ? y - 3 + 1 : 0;
    int contador = 0;
    
    // Recorrer en la dirección hacia arriba-derecha desde (x, y) hasta (xFin, yInicio), contando caracteres iguales.
    while (x <= xFin && yInicio <= y)
    {
        if (tablero[y][x] == caracter)
        {
            contador++; // Incrementar el contador si se encuentra un caracter igual.
        }
        else
        {
            contador = 0; // Reiniciar el contador si se encuentra un caracter diferente.
        }
        x++; // Avanzar hacia la derecha.
        y--; // Retroceder hacia arriba.
    }
    
    return contador; // Devolver el contador final.
}

int contarHaciaAbajoDerecha(int x, int y, char caracter, char tablero[3][3])
{
    // Determinar el índice de fin de x para el bucle.
    int xFin = (x + 3 < 3) ? x + 3 - 1 : 3 - 1;
    // Determinar el índice de fin de y para el bucle.
    int yFin = (y + 3 < 3) ? y + 3 - 1 : 3 - 1;
    int contador = 0;
    
    // Recorrer en la dirección hacia abajo-derecha desde (x, y) hasta (xFin, yFin), contando caracteres iguales.
    while (x <= xFin && y <= yFin)
    {
        if (tablero[y][x] == caracter)
        {
            contador++; // Incrementar el contador si se encuentra un caracter igual.
        }
        else
        {
            contador = 0; // Reiniciar el contador si se encuentra un caracter diferente.
        }
        x++; // Avanzar hacia la derecha.
        y++; // Avanzar hacia abajo.
    }
    
    return contador; // Devolver el contador final.
}
// Verifica si las coordenadas del tablero están vacías
bool coordenadasVacias(int y, int x, char (*tablero)[3])
{


    return tablero[y][x] != 'X'  &&  tablero[y][x] != 'O';
}

void Negocio::copiarTablero(char (*origen)[3], char (*destino)[3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            destino[i][j] = origen[i][j];
        }
    }
}

int comprobarSiGana(char caracter, char tablero[3][3])
{
    int y;
    for (y = 0; y < 3; y++)
    {
        int x;
        for (x = 0; x < 3; x++)
        {

            if (
                contarHaciaArriba(x, y, caracter, tablero) >= 3 ||
                contarHaciaDerecha(x, y, caracter,tablero) >= 3 ||
                contarHaciaArribaDerecha(x, y, caracter, tablero) >= 3 ||
                contarHaciaAbajoDerecha(x, y, caracter, tablero) >= 3)
            {
                return 1;
            }
        }
    }
    // Terminamos de recorrer y no conectó
    return 0;
}
void mostrarTablero(char c[3][3])
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


// Esta función encuentra las coordenadas para ganar el juego para un jugador específico en un tablero dado.
// Parámetros:
// - caracter: El caracter del jugador.
// - tableroOriginal: El tablero original en forma de matriz.
// - yDestino: Puntero a la variable que almacenará la coordenada y para ganar.
// - xDestino: Puntero a la variable que almacenará la coordenada x para ganar.
void Negocio::coordenadasParaGanar(char caracter, char tableroOriginal[3][3], int *yDestino, int *xDestino)
{
    char copiaTablero[3][3];
    int y, x;
    
    copiarTablero(tableroOriginal, copiaTablero); // Copiar el tablero original una vez antes del bucle
    
    // Recorrer todas las coordenadas del tablero
    for (y = 0; y < 3; y++)
    {
        for (x = 0; x < 3; x++)
        {
            // Verificar si la coordenada está vacía en la copia del tablero
            if (coordenadasVacias(y, x, copiaTablero))
            {
                // Colocar el caracter del jugador en la coordenada vacía
                copiaTablero[y][x] = 'O';
                
                // Comprobar si el jugador gana con esta jugada
                if (comprobarSiGana('O', copiaTablero))
                {
                    // Si el jugador gana, guardar las coordenadas de victoria y salir del bucle
                    *yDestino = y;
                    *xDestino = x;
                    return;
                }
            }
        }
    }
    
    // Si no se encuentra una jugada para ganar, establecer las coordenadas de destino como -1
    *yDestino = *xDestino = -1;
}


bool verificarLinea(char c[3][3], char jugador, char tapar)
{
    // Verificar filas
    for (int i = 0; i < 3; i++) {
        // Comprobar si hay una línea completa en la fila con el jugador y sin el valor de "tapar"
        if ((c[i][0] == jugador && c[i][1] == jugador && c[i][2] != tapar) ||
            (c[i][0] == jugador && c[i][1] != tapar && c[i][2] == jugador) ||
            (c[i][0] != tapar && c[i][1] == jugador && c[i][2] == jugador)) {
            // Si se cumple la condición, buscar una posición vacía en la fila y colocar "tapar"
            for (int j = 0; j < 3; j++) {
                if (c[i][j] != jugador && c[i][j] != tapar) {
                    c[i][j] = tapar;
                    return true; // Se encontró una línea completa y se tapó una posición
                }
            }
        }
    }

    // Verificar columnas
    for (int j = 0; j < 3; j++) {
        // Comprobar si hay una línea completa en la columna con el jugador y sin el valor de "tapar"
        if ((c[0][j] == jugador && c[1][j] == jugador && c[2][j] != tapar) ||
            (c[0][j] == jugador && c[1][j] != tapar && c[2][j] == jugador) ||
            (c[0][j] != tapar && c[1][j] == jugador && c[2][j] == jugador)) {
            // Si se cumple la condición, buscar una posición vacía en la columna y colocar "tapar"
            for (int i = 0; i < 3; i++) {
                if (c[i][j] != jugador && c[i][j] != tapar) {
                    c[i][j] = tapar;
                    return true; // Se encontró una línea completa y se tapó una posición
                }
            }
        }
    }

    // Verificar diagonales
    // Comprobar si hay una línea completa en la diagonal principal con el jugador y sin el valor de "tapar"
    if ((c[0][0] == jugador && c[1][1] == jugador && c[2][2] != tapar) ||
        (c[0][0] == jugador && c[1][1] != tapar && c[2][2] == jugador) ||
        (c[0][0] != tapar && c[1][1] == jugador && c[2][2] == jugador)) {
        // Si se cumple la condición, buscar una posición vacía en la diagonal principal y colocar "tapar"
        for (int i = 0; i < 3; i++) {
            if (c[i][i] != jugador && c[i][i] != tapar) {
                c[i][i] = tapar;
                return true; // Se encontró una línea completa y se tapó una posición
            }
        }
    }

    // Comprobar si hay una línea completa en la diagonal secundaria con el jugador y sin el valor de "tapar"
    if ((c[0][2] == jugador && c[1][1] == jugador && c[2][0] != tapar) ||
        (c[0][2] == jugador && c[1][1] != tapar && c[2][0] == jugador) ||
        (c[0][2] != tapar && c[1][1] == jugador && c[2][0] == jugador)) {
        // Si se cumple la condición, buscar una posición vacía en la diagonal secundaria y colocar "tapar"
        for (int i = 0; i < 3; i++) {
            if (c[i][2 - i] != jugador && c[i][2 - i] != tapar) {
                c[i][2 - i] = tapar;
                return true; // Se encontró una línea completa y se tapó una posición
            }
        }
    }

    return false; // No se encontró ninguna línea completa para tapar
}


// Esta función representa la lógica de la introducción de la IA en el juego.
// Parámetros:
// - c: El tablero en forma de matriz.
// - determinado: El caracter determinado para la IA ('X' o 'O').
// - yDestino: Puntero a la variable que almacenará la coordenada y de la jugada de la IA.
// - xDestino: Puntero a la variable que almacenará la coordenada x de la jugada de la IA.
void Negocio::introIa(char (*c)[3], char determinado, int *yDestino, int *xDestino )
{
    int y, x, conteoJugador, conteoOponente;

    // Verificar si hay una línea completa en el tablero para el jugador humano ('X') y la tapa
    if (verificarLinea(c, 'X', 'O')) {
    } else {
        // Si no hay una línea completa para el jugador humano, se determina la jugada de la IA.

        // Obtener las coordenadas para ganar el juego para la IA ('O')
        coordenadasParaGanar('O', c, &y, &x);

        // Colocar el caracter de la IA en las coordenadas obtenidas
        c[y][x] = 'O';

        // Actualizar los datos del jugador de la IA
        jugador.setFila(y);
        jugador.setColumna(x);
        jugador.setTipoJugador("COMPUTADORA");
        jugador.setSimboloJugador('O');
        jugador.setTiempo(0);
        
        return;
    }
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
