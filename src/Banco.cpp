#include "Banco.hpp"

// Método para establecer la fecha de la ejecución del programa. 
void Banco::setFecha(){
    while(1){
        // Se pide al usuario que ingresa la fecha en formato día mes año. 
        cout << "Ingrese la fecha de hoy (dd mm aaaa): ";
        // Se intenta leer cada parte de la fecha. 
        try{
            for(int i = 0; i < 3; i++){
                cin >> fecha[i];
            }
            // Si la lectura tiene algún problema es porque no se ingresó un número entero. 
            if(cin.fail()){
                // Se descarta la lectura errónea realizada. 
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                // Se lanza una excepcion con un mensaje que indica que todas las entradas deben ser número enteros. 
                throw invalid_argument("Todas las entradas deben ser numeros. Intente de nuevo.");
            }
            // Si el día ingresado es mayor a 31 o el mes ingresado es mayor a 12 la fecha ingresada no existe. 
            if(fecha[0] <= 0 || fecha[0] > 31 || fecha[1] <= 0 || fecha[1] > 12){
                // Se lanza una excepción con un mensaje de que la fecha no es válida. 
                throw "La fecha ingresada no es valida. Intente de nuevo.";
            }
            // Si todo sale bien se sale del bloque while y deja de preguntar. 
            break;
        }
        // Se recibe la excepcion cuando la lectura tuvo un problema. 
        catch(const exception& e){
            // Se imprime el mensaje de argumento inválido. 
            cerr << e.what() << endl;
        }      
        // Se recibe la excepción cuando la fecha ingresada no existe en el calendario. 
        catch(const char* mensajeError){
            // Se imprime el mensaje de error. 
            cerr << mensajeError << endl;
        }    
    }
}

// Método para leer el archivo .txt con las transacciones de los usuarios. 
void Banco::leerTransacciones(){
    // Se abre el archivo en modo de lectura. 
    string nombreArchivo = "registro_transacciones.txt";
    ifstream archivo(nombreArchivo);
    string linea;
    // Se ignoran las primeras 3 líneas que son el encabezado. 
    getline(archivo,linea);
    getline(archivo,linea);
    getline(archivo,linea);
    // Para cada una de las líneas en el archivo. 
    while(getline(archivo,linea)){
        // Se agrega la línea al contenedor con todas las transacciones de los clientes. 
        transacciones.push_back(linea);
    }
    // Se cierra el archivo.
    archivo.close();
}

// Método para actualizar el archivo .txt con las transacciones de los clientes. 
void Banco::actualizarTransacciones(){
    // Se crea si no existe y se abre un archivo .txt de registro de transacciones. 
    string nombreArchivo = "registro_transacciones.txt";
    ofstream archivo(nombreArchivo, ios::out | ios::trunc);
    // Se agrega un encabezado al archivo. 
    archivo << "Registro de transacciones realizadas por los usuarios" << endl;
    archivo << endl;
    // Se agrega un encabezado de la información de las transacciones con los títulos de cada columna. 
    archivo << "fecha,id,nombre,descripcion" << endl;
    // Pata cada línea del vector con todas las transacciones. 
    for (auto& transaccion : transacciones) {
        // Se escribe la línea en el archivo .txt. 
        archivo << transaccion << endl;
    }
    // Se cierra el archivo. 
    archivo.close();
    // Se imprime un mensaje que indica que se pudo generar o actualizar el archivo correctamente. 
    cout << "\nSe actualizo el archivo: " << nombreArchivo << endl;
    cout << endl;
}

