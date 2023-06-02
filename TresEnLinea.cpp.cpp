#include <iostream>
#include <string>
#include <cstdlib>
// Para manejo de archivos
#include <fstream>
// Para toma los segundos
#include <chrono>

#include <sstream>
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
;
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
    void mostrarMenuRestablecer();
    void mostrarTablero(char c[3][3]);
    void asignaValores(char c[3][3]);

private:
};

Vista::Vista()
{
}

void Vista::mostrarMenu()
{
	system("cls");
    cout << "----- MENU -----" << endl;
    cout << "1. Jugador vs Jugador" << endl;
    cout << "2. Jugador vs IA" << endl;
    cout << "3. IA vs IA" << endl;
    cout << "4. Restablecer partida anterior" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void Vista::mostrarMenuRestablecer()
{
	system("cls");
    cout << "----- RESTABLECER PARTIDA -----" << endl;
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
    Datos(Jugador jugador,string TXT,char c[3][3]);
    void crearOrEscribirTXT(Jugador jugador,string nombreTXT);
    void leerArchivo(string nombreTXT, char c[3][3]);
    void limpiarArchivo(string nombreTXT);

private:
};

Datos::Datos() {}

Datos::Datos(Jugador jugador,string nombreTXT,char c[3][3])
{
    crearOrEscribirTXT(jugador,nombreTXT);
    leerArchivo(nombreTXT,c);
    limpiarArchivo(nombreTXT);
}




void Datos::crearOrEscribirTXT(Jugador jugador,string nombreTXT)
{
    // Crear i escribir en el archivo
    ofstream archivo(nombreTXT, ios::app); // ios::app = Este modo de apertura indica que el archivo se abrirá en modo de adición
    if (archivo.is_open())
    {
        archivo
            << jugador.getId() << ", " << jugador.getMovimiento() << ", " << jugador.getTiempo() << ", "
            << jugador.getId() << ", " << jugador.getTipoJugador() << ", "
            << jugador.getSimboloJugador() << ", "
            << "[" << jugador.getFila()
            << "], [" <<  jugador.getColumna() << "]" <<endl;
           
        archivo.close();
    }
    else
    {
        cout << "Error abriendo el archivo." << endl;
    }
}


void Datos::leerArchivo(string nombreTXT, char c[3][3]) {
    std::ifstream file(nombreTXT);
    if (!file) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return;
    }

    int fila, col, valor;
    char jugador;
    std::string line;

    while (std::getline(file, line)) {
        std::sscanf(line.c_str(), "%*d, %*[^,], %*d, %*d, %*[^,], %c, [%d], [%d]", &jugador, &fila, &col);
        c[fila][col] = jugador;
    }

    file.close();
}

void Datos::limpiarArchivo(string nombreTXT)
{
    std::ofstream archivo(nombreTXT); // Abrir el archivo en modo de escritura
    archivo.close(); // Cerrar el archivo, esto eliminará su contenido
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
    void restablecerPartida();
    void jugadorVsJugador(char c[3][3]);
    void jugadorVsComputadora(char c[3][3]);
    void computadoraVsComputadora(char c[3][3]);
    void introUser(char (*c)[3], char determinado = 'X');
    void introIa(char (*c)[3], char determinado = 'X', int *iDestino = nullptr, int *jDestino = nullptr);
    void copiarTablero(char (*origen)[3], char (*destino)[3]);
    void coordenadasParaGanar(char caracter, char tableroOriginal[3][3], int *iDestino, int *jDestino);
    int contarColumnas(int j, int i, char caracter, char tablero[3][3]);
    int contarFilas(int j, int i, char caracter, char tablero[3][3]);
    int contarDiagonal(int j, int i, char caracter, char tablero[3][3]);
    int contarDiagonalInversa(int j, int i, char caracter, char tablero[3][3]);
    bool coordenadasVacias(int i, int j, char (*tablero)[3]);
    int comprobarVictoria(char caracter, char tablero[3][3]);
    bool verificarLinea(char c[3][3], char jugador, char tapar,int *iDestino, int *jDestino);
    


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

    do
    {
        system("cls");
        vista.mostrarTablero(c);
        if (i % 2 == 0)
        {
            introUser(c,'X');
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
                                               jugador.getSimboloJugador(), jugador.getFila(), jugador.getColumna()),"jugadorVsjugador.txt");

    } while (i <= 9 && j == -1);

    system("cls");
    vista.mostrarTablero(c);

    if (j == 0)
    {
        datos.limpiarArchivo("jugadorVsjugador.txt");
        cout << "Ha ganado la X" << endl << endl;
    }
    else if (j == 1)
    {
        datos.limpiarArchivo("jugadorVsjugador.txt");
        cout << "Ha ganado la O" << endl << endl;
    }
    else
    {
        datos.limpiarArchivo("jugadorVsjugador.txt");
        cout << "Empate" << endl << endl;
    }
     system("pause");
}

void Negocio::jugadorVsComputadora(char c[3][3])
{

    int i = 0, j, id;
    jugador.setMovimiento("0");
    do
    {
        system("cls");
        vista.mostrarTablero(c);
        if (i % 2 == 0)
        {
        	jugador.setMovimiento(to_string(i));
            introUser(c);
            id = 1;
        }
        else
        {
        	jugador.setMovimiento(to_string(i));
            introIa(c, 'O',0,0);
            id = 2;
        }
        j = ganador(c);

        i++;

        this->datos.crearOrEscribirTXT(Jugador(id, "movimiento " + to_string(i), jugador.getTiempo(), jugador.getTipoJugador(),
                                               jugador.getSimboloJugador(), jugador.getFila(), jugador.getColumna()),"jugadorVscomputadora.txt");

    } while (i <= 9 && j == -1);

    system("cls");
    vista.mostrarTablero(c);

    if (j == 0)
    {
        datos.limpiarArchivo("jugadorVscomputadora.txt");
        cout << "Haz ganado" << endl;
    }
    else if (j == 1)
    {
        datos.limpiarArchivo("jugadorVscomputadora.txt");
        cout << "Haz perdido" << endl;
    }
    else
    {
        datos.limpiarArchivo("jugadorVscomputadora.txt");
        cout << "Empate" << endl;
    }
    system("pause");
}

void Negocio::computadoraVsComputadora(char c[3][3])
{
    int i = 0, j, id;

    jugador.setMovimiento("0");
    vista.asignaValores(c);
    do
    {
   // Llamar a la función verificarDeterminado() i almacenar el resultado en la variable "encontrado"


        system("cls");
        vista.mostrarTablero(c);
        if (i % 2 == 0)
        {
        	jugador.setMovimiento(to_string(i));
            introIa(c, 'X',0,0);

            id = 1;
        }
        else
        {
        	jugador.setMovimiento(to_string(i));
            introIa(c, 'O',0,0);
            id = 2;
        }
        j = ganador(c);

        i++;

        this->datos.crearOrEscribirTXT(Jugador(id, "movimiento " + to_string(i), jugador.getTiempo(), jugador.getTipoJugador(),
                                               jugador.getSimboloJugador(), jugador.getFila(), jugador.getColumna()),"computadoraVscomputadora.txt");

    } while (i <= 9 && j == -1);

    system("cls");
    vista.mostrarTablero(c);

    if (j == 0)
    {
        datos.limpiarArchivo("computadoraVscomputadora.txt");
        cout << "Ha ganado la X" << endl;
    }
    else if (j == 1)
    {
        datos.limpiarArchivo("computadoraVscomputadora.txt");
        cout << "Ha ganado la O" << endl;
    }
    else
    {
        datos.limpiarArchivo("computadoraVscomputadora.txt");
        cout << "Empate" << endl;
    }
     system("pause");
}
void Negocio::restablecerPartida()
{
    int opcion;
    do
    {
        this->vista.mostrarMenuRestablecer();

        cin >> opcion;

        switch (opcion)
        {
        case 1:
        	vista.asignaValores(c);
        	datos.leerArchivo("jugadorVsjugador.txt", c);
        	jugadorVsJugador(c);
            break;
        case 2:
        	vista.asignaValores(c);
        	datos.leerArchivo("jugadorVscomputadora.txt", c);
        	vista.mostrarTablero(c);
        	jugadorVsComputadora(c);
            break;
        case 3:
        	vista.asignaValores(c);
        	datos.leerArchivo("computadoraVscomputadora.txt", c);
        	computadoraVsComputadora(c);
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);
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
            vista.asignaValores(c);
            datos.limpiarArchivo("jugadorVsjugador.txt");
            jugadorVsJugador(c);
            break;
        case 2:
            // código para jugar Jugador vs IA
            vista.asignaValores(c);
            datos.limpiarArchivo("jugadorVscomputadora.txt");
            jugadorVsComputadora(c);
            break;
        case 3:
            // código para jugar IA vs IA
            vista.asignaValores(c);
            datos.limpiarArchivo("computadoraVscomputadora.txt");
            computadoraVsComputadora(c);
            break;
        case 4:
             restablecerPartida();
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
    jugador.setSimboloJugador(determinado);
    jugador.setTiempo(segundos);
}

int Negocio::contarColumnas(int j, int i, char caracter, char tablero[3][3])
{
    // Determinar el índice de inicio de i para el bucle.
    int iInicio = (i - 3 >= 0) ? i - 3 + 1 : 0;
    int contador = 0;

    // Recorrer hacia arriba desde iInicio hasta i, contando caracteres iguales.
    for (; iInicio <= i; iInicio++)
    {
        if (tablero[iInicio][j] == 'O')
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


int Negocio::contarFilas(int j, int i, char caracter, char tablero[3][3])
{
    // Determinar el índice de fin de j para el bucle.
    int jFin = (j + 3 < 3) ? j + 3 - 1 : 3 - 1;
    int contador = 0;
    
    // Recorrer hacia la derecha desde j hasta jFin, contando caracteres iguales.
    for (; j <= jFin; j++)
    {
        if (tablero[i][j] == caracter)
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
// "/"

int Negocio::contarDiagonal(int j, int i, char caracter, char tablero[3][3])
{
    // Determinar el índice de fin de j para el bucle.
    int jFin = (j + 3 < 3) ? j + 3 - 1 : 3 - 1;
    // Determinar el índice de inicio de i para el bucle.
    int iInicio = (i - 3 >= 0) ? i - 3 + 1 : 0;
    int contador = 0;
    
    // Recorrer en la dirección hacia arriba-derecha desde (j, i) hasta (jFin, iInicio), contando caracteres iguales.
    while (j <= jFin && iInicio <= i)
    {
        if (tablero[i][j] == caracter)
        {
            contador++; // Incrementar el contador si se encuentra un caracter igual.
        }
        else
        {
            contador = 0; // Reiniciar el contador si se encuentra un caracter diferente.
        }
        j++; // Avanzar hacia la derecha.
        i--; // Retroceder hacia arriba.
    }
    
    return contador; // Devolver el contador final.
}

// "\ "
int Negocio::contarDiagonalInversa(int j, int i, char caracter, char tablero[3][3])
{
    // Determinar el índice de fin de j para el bucle.
    int jFin = (j + 3 < 3) ? j + 3 - 1 : 3 - 1;
    // Determinar el índice de fin de i para el bucle.
    int iFin = (i + 3 < 3) ? i + 3 - 1 : 3 - 1;
    int contador = 0;
    
    // Recorrer en la dirección hacia abajo-derecha desde (j, i) hasta (jFin, iFin), contando caracteres iguales.
    while (j <= jFin && i <= iFin)
    {
        if (tablero[i][j] == caracter)
        {
            contador++; // Incrementar el contador si se encuentra un caracter igual.
        }
        else
        {
            contador = 0; // Reiniciar el contador si se encuentra un caracter diferente.
        }
        j++; // Avanzar hacia la derecha.
        i++; // Avanzar hacia abajo.
    }
    
    return contador; // Devolver el contador final.
}
// Verifica si las coordenadas del tablero están vacías
bool Negocio::coordenadasVacias(int i, int j, char (*tablero)[3])
{


    return tablero[i][j] != 'X'  &&  tablero[i][j] != 'O';
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

int Negocio::comprobarVictoria(char caracter, char tablero[3][3])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        int j;
        for (j = 0; j < 3; j++)
        {

            if (
                contarColumnas(j, i, caracter, tablero) >= 3 ||
                contarFilas(j, i, caracter,tablero) >= 3 ||
                contarDiagonal(j, i, caracter, tablero) >= 3 ||
                contarDiagonalInversa(j, i, caracter, tablero) >= 3)
            {
                return 1;
            }
            
        }
    }
    // Terminamos de recorrer i no conectó
    return 0;
}


// - tableroOriginal: El tablero original en forma de matriz.
// - iDestino: Puntero a la variable que almacenará la coordenada i para ganar.
// - jDestino: Puntero a la variable que almacenará la coordenada j para ganar.
void Negocio::coordenadasParaGanar(char caracter, char tableroOriginal[3][3], int *iDestino, int *jDestino)
{
    char copiaTablero[3][3];
    int i, j;
    
    copiarTablero(tableroOriginal, copiaTablero); // Copiar el tablero original una vez antes del bucle
    
    // Recorrer todas las coordenadas del tablero
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            // Verificar si la coordenada está vacía en la copia del tablero
            if (coordenadasVacias(i, j, copiaTablero))
            {
                // Colocar el caracter del jugador en la coordenada vacía
                copiaTablero[i][j] = caracter;
                
                // Comprobar si el jugador gana con esta jugada
                if (comprobarVictoria(caracter, copiaTablero))
                {

                    // Si el jugador gana, guardar las coordenadas de victoria i salir del bucle
                    *iDestino = i;
                    *jDestino = j;
    		
                    return;
                }
            }
        }
    }
    
    // Si no se encuentra una jugada para ganar, establecer las coordenadas de destino como -1
    *iDestino = *jDestino = -1;
}


bool Negocio::verificarLinea(char c[3][3], char jugador, char tapar,int *iDestino, int *jDestino)
{
    // Verificar filas
    for (int i = 0; i < 3; i++) {
        // Comprobar si hay una línea completa en la fila con el jugador i sin el valor de "tapar"
        if ((c[i][0] == jugador && c[i][1] == jugador && c[i][2] != tapar) ||
            (c[i][0] == jugador && c[i][1] != tapar && c[i][2] == jugador) ||
            (c[i][0] != tapar && c[i][1] == jugador && c[i][2] == jugador)) {
            // Si se cumple la condición, buscar una posición vacía en la fila i colocar "tapar"
            for (int j = 0; j < 3; j++) {
                if (c[i][j] != jugador && c[i][j] != tapar) {
                    *iDestino = i;
                    *jDestino = j;
                    return true; // Se encontró una línea completa i se tapó una posición
                }
            }
        }
    }

    // Verificar columnas
    for (int j = 0; j < 3; j++) {
        // Comprobar si hay una línea completa en la columna con el jugador i sin el valor de "tapar"
        if ((c[0][j] == jugador && c[1][j] == jugador && c[2][j] != tapar) ||
            (c[0][j] == jugador && c[1][j] != tapar && c[2][j] == jugador) ||
            (c[0][j] != tapar && c[1][j] == jugador && c[2][j] == jugador)) {
            // Si se cumple la condición, buscar una posición vacía en la columna i colocar "tapar"
            for (int i = 0; i < 3; i++) {
                if (c[i][j] != jugador && c[i][j] != tapar) {
                    *iDestino = i;
                    *jDestino = j;
                    return true; // Se encontró una línea completa i se tapó una posición
                }
            }
        }
    }

    // Verificar diagonales
    // Comprobar si hay una línea completa en la diagonal principal con el jugador i sin el valor de "tapar"
    if ((c[0][0] == jugador && c[1][1] == jugador && c[2][2] != tapar) ||
        (c[0][0] == jugador && c[1][1] != tapar && c[2][2] == jugador) ||
        (c[0][0] != tapar && c[1][1] == jugador && c[2][2] == jugador)) {
        // Si se cumple la condición, buscar una posición vacía en la diagonal principal i colocar "tapar"
        for (int i = 0; i < 3; i++) {
            if (c[i][i] != jugador && c[i][i] != tapar) {
                    *iDestino = i;
                    *jDestino = i;
                return true; // Se encontró una línea completa i se tapó una posición
            }
        }
    }

    // Comprobar si hay una línea completa en la diagonal secundaria con el jugador i sin el valor de "tapar"
    if ((c[0][2] == jugador && c[1][1] == jugador && c[2][0] != tapar) ||
        (c[0][2] == jugador && c[1][1] != tapar && c[2][0] == jugador) ||
        (c[0][2] != tapar && c[1][1] == jugador && c[2][0] == jugador)) {
        // Si se cumple la condición, buscar una posición vacía en la diagonal secundaria i colocar "tapar"
        for (int i = 0; i < 3; i++) {
            if (c[i][2 - i] != jugador && c[i][2 - i] != tapar) {
                *iDestino = i;
                *jDestino = 2 - i;
                return true; // Se encontró una línea completa i se tapó una posición
            }
        }
    }

    return false; // No se encontró ninguna línea completa para tapar
}



// - iDestino: Puntero a la variable que almacenará la coordenada i de la jugada de la IA.
// - jDestino: Puntero a la variable que almacenará la coordenada j de la jugada de la IA.
void Negocio::introIa(char (*c)[3], char determinado, int *iDestino, int *jDestino )
{
    int i, j,k,conteoJugador, conteoOponente;
	char oponente='O';


	
	
	if(determinado=='O'){
		oponente='X';
	}else{
		oponente='O';
	}
	
    // Verificar si hay una línea completa en el tablero para el jugador humano ('X') i la tapa
    
    if (verificarLinea(c, oponente,determinado,&i, &j)){
        c[i][j] = determinado;
            cout<<"verificar linea i,j "<<i<<", "<<j<<endl;
    		jugador.setFila(i);
        	jugador.setColumna(j);
        	jugador.setTipoJugador("COMPUTADORA");
        	jugador.setSimboloJugador(determinado);
        	jugador.setTiempo(0);



    	return;
    }// Si no hay una línea completa para el jugador humano, se determina la jugada de la IA.
//Validacion para que la primera jugada sea aleatoria de la IA
	if(jugador.getMovimiento() == "1"){
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
	}else{ 
	    coordenadasParaGanar(determinado, c, &i, &j);
	            c[i][j] = determinado;
	}
        // Obtener las coordenadas para ganar el juego para la IA ('O')

        // Colocar el caracter de la IA en las coordenadas obtenidas


        // Actualizar los datos del jugador de la IA
        jugador.setFila(i);
        jugador.setColumna(j);
        jugador.setTipoJugador("COMPUTADORA");
        jugador.setSimboloJugador(determinado);
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
