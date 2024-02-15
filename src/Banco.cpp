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


