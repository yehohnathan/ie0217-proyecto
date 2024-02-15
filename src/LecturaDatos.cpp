#include "LecturaDatos.hpp"

// Funcion para leer del usuario un número con decimales
void leerDouble(double& variableDouble, string mensaje){
    // Se crea una variable para realizar la lectura
    double lectura;
    while(1){
        try{
            // Se intenta leer la entrada del usuario
            cout << mensaje;
            cin >> lectura;
            // Si hay un problema con la lectura de la entrada significa que no se ingresó un número. 
            if(cin.fail()){
                // Se ignora la entrada ingresada por el usuario
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                // Se lanza una excepcion con un mensaje que indica que se debe ingresar un número. 
                throw invalid_argument("Debe ingresar un numero. Intente de nuevo.");
            }
            // Si el número es menor o igual a cero. 
            if(lectura <= 0){
                // Se lanza una excepción con un mensaje que indica que la entrada debe ser un número positivo.
                throw "Debe ingresar un numero positivo. Intente de nuevo.";
            }
            // Si todo sale bien se puede salir del ciclo. Si no seguirá preguntando hasta que se ingrese una entrada válida. 
            break;
        }
        // Se recibe la excepcion de entrada invalida.
        catch(const exception& e){
            // Se imprime el mensaje de error. 
            cerr << e.what() << endl;
        }      
        // Se recibe la excepción de numero no positivo. 
        catch(const char* mensajeError){
            // Se imprime el mensaje de error. 
            cerr << mensajeError << endl;
        }    
    }
    // Cuando todo esta bien, se asigna el valor de la lectura a la variable original. 
    variableDouble = lectura;
}

// Funcion para leer un número entero del usuario. 
void leerEntero(int& variableEntero, string mensaje){
    // Se crea una variable para realizar la lectura. 
    double lectura;
    while(1){
        try{
            // Se intenta leer la entrada del usuario. 
            cout << mensaje;
            cin >> lectura;
            // Si la lectura falla es porque no se ingresó un número. 
            if(cin.fail()){
                // Se ignora la entrada ingresada por el usuario. 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                // Se lanza una excepción con un mensaje que indica que se debe ingresar un número. 
                throw invalid_argument("Debe ingresar un numero. Intente de nuevo.");
            }
            // Si el número ingresado no es un número entero o no es un número positivo. 
            if(lectura != floor(lectura) || lectura <= 0){
                // Se lanza una excepción con un mensaje que indica que se debe ingresar un entero positivo. 
                throw "Debe ingresar un entero positivo. Intente de nuevo.";
            }
            // Se produce un string con la lectura realizada. 
            string string_lectura = to_string(int(lectura));
            // Si la cantidad de dígitos es mayor a 9.
            if(string_lectura.size() > 9){
                // Se lanza una excepcion que indica que el número debe tener a lo sumo 9 dígitos. 
                throw "El numero debe ser menor a 1000000000. Intente de nuevo.";
            }
            // Si todo sale bien se puede salir del bucle. Si no continuará leyendo entradas hasta ingresar una entrada válida. 
            break;
        } 
        // Se recibe la excepción si la entrada ingresada no es un número. 
        catch(const exception& e){
            // Se imprime el mensaje de error de la excepción. 
            cerr << e.what() << endl;
        }
        // Se recibe la excepción si el número ingresado no es un entero positivo. 
        catch(const char* mensajeError){
            // Se imprime el mensaje de error de la excepción. 
            cerr << mensajeError << endl;
        }   
    }
    // Cuando todo está bien se asigna el valor de la lectura a la variable. 
    variableEntero = int(lectura);
}

// Función para leer el tipo de Moneda: colones o dólares 
void leerMoneda(string& tipoMoneda){
    // Se crea una variable para la opción. 
    int opcionMoneda = 0;
    while(1){
        // Se muestran las opciones disponibles. 
        cout << "\n---Opciones de tipo de moneda---" << endl;
        cout << "1. Colones." << endl;
        cout << "2. Dolares." << endl;
        // Se lee la opción ingresada por el usuario. 
        leerEntero(opcionMoneda, "Ingrese el tipo de moneda: ");
        // Si la opción es la 1 de colones
        if(opcionMoneda == 1){
            // Se asigna el tipo como colones
            tipoMoneda = "colones";
            // Se sale del bucle. 
            break;
        }
        // Si la opción es la 2 de dólares 
        else if(opcionMoneda == 2){
            // Se asigna el tipo como dólares
            tipoMoneda = "dolares";
            // Se sale del bucle
            break;
        }
        // Si no ingresó ninguna de las opciones
        else{
            // Se imprime un mensaje de error. 
            cout << "La opcion ingresada no es valida. Intente de nuevo." << endl;
        }
    }
}