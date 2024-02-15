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