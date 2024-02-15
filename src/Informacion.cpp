#include "Informacion.hpp"

// Se incluye el archivo con las constantes. 
#include "Constantes.hpp"

// Método para generar un informe de cuotas de uno de los préstamos predeterminados del banco. 
void Informacion::generarInformePredeterminado(string tipo, int cuotasTotal, double tasaInteres){
        // Se imprime todo la información sobre el préstamo del tipo correspondiente. 
        cout << "\n---Prestamo " << tipo << "---" << endl;
        cout << "Cantidad total de cuotas: " << cuotasTotal << endl;
        cout << "Tasa de interes: " << tasaInteres << endl;
        // Se pregunta si se desea generar la tabla de cuotas. 
        cout << "Desea generar la tabla de cuotas?: " << endl;
        // Se lee la opción ingresada por el usuario. 
        cout << "1. Si." << endl;
        cout << "2. No." << endl;
        int opcion;
        leerEntero(opcion, "Ingrese una opcion: ");
        // Si la opción es 1 de que sí quiere generar la tabla. 
        if(opcion == 1){
            // Se lee el tipo de moneda de parte del usuario. 
            string tipoMoneda;
            leerMoneda(tipoMoneda);
            // Se lee el monto total del préstamo de parte del usuario. 
            double montoTotal;
            leerDouble(montoTotal, "Ingrese el monto total del prestamo: ");
            // Se crea una instancia de la clase Prestamo. 
            Prestamo prestamo;
            // Se setean los datos con el tipo de moneda, monto, cuotas, interés y tipo correspondiente. 
            prestamo.setDatos(0,0, tipoMoneda, montoTotal, cuotasTotal, tasaInteres,0,tipo);
            // Se crea y se abre un archivo .txt en modo de escritura. 
            string nombreArchivo = "consulta_prestamo_predeterminado.txt";
            ofstream archivo(nombreArchivo, ios::out | ios::trunc);
            // Se escribe un encabezado para el archivo. 
            archivo << "Consulta sobre un prestamo " << tipo << endl;
            archivo << endl;
            archivo << "----------------------------Informacion del prestamo----------------------------" << endl;
            // Se agrega un encabezado para la información del préstamo con los títulos de cada columna. 
            archivo << "tipo de prestamo, tipo de moneda, monto total, cantidad cuotas, tasa interes" << endl;
            // Se agregan la información del préstamo en correspondencia con los títulos del encabezado. 
            archivo << prestamo.tipo + ", " + prestamo.tipoMoneda + ", " + to_string(prestamo.montoTotal)
            + ", " + to_string(prestamo.cuotasTotal) + ", " + to_string(prestamo.tasaInteres) << endl;
            // Se agrega un encabezado para la información de las cuotas del préstamo con los títulos de cada columna. 
            archivo << "----------------------------Cuotas a pagar en este prestamo----------------------------" << endl;
            archivo << "numero de cuota, costo de cuota, aporte deuda, aporte intereses, monto restante" << endl;
            // Se agrega la información de las columnas utilizando el método de la clase Prestamo.
            vector <string> cuotas = prestamo.infoCuotas;
            for (string linea : cuotas){
                // Se agrega cada línea de la información de las cuotas al archivo .txt. 
                archivo << linea << endl;
            }
            // Se cierra el archivo. 
            archivo.close();
            // Se imprime un mensaje de confirmación que indica que se generó el archivo correctamente. 
            cout << "\nSe genero el archivo: " << nombreArchivo << endl;
        }
        // Si elige la opción 2 de que no quiere generar el informe. 
        else if(opcion == 2){
            // Se termina la ejecución del método. 
            return;
        }
        // Si no elige ninguna de las anteriores se imprime un mensaje de opción invalida. 
        else{
            cout << "La opcion ingresada no es valida. Intente de nuevo." << endl;
        }
}


// Método para generar un informe de cuotas en archivo .txt de un préstamo con datos personalizados del usuario. 
void Informacion::generarInformePersonalizado(){
        // Se imprime la información del préstamo que en este caso solo es el tipo personalizado. 
        cout << "\n---Prestamo personalizado---" << endl;
        string tipo = "personalizado";
        // Se lee el tipo de moneda del préstamo de parte del usuario. 
        string tipoMoneda;
        leerMoneda(tipoMoneda);
        // Se lee el monto total del préstamo de parte del usuario. 
        double montoTotal;
        leerDouble(montoTotal, "Ingrese el monto total del prestamo: ");
        // Se lee la cantidad total de cuotas del préstamo de parte del usuario. 
        int cuotasTotal;
        leerEntero(cuotasTotal, "Ingrese la cantidad total de cuotas: ");
        // Se lee la tasa de interés del préstamo de parte del usuario. 
        double tasaInteres;
        leerDouble(tasaInteres, "Ingrese la tasa de interes: ");
        // Se crea una instancia de la clase Presgamo. 
        Prestamo prestamo;
        // Se setean los datos con el tipo de moneda, monto total, cantidad de cuotas, tasa de interés y tipo ingresados por el usuarios. 
        prestamo.setDatos(0,0, tipoMoneda, montoTotal, cuotasTotal, tasaInteres, 0,tipo);
        // Se pregunta si desea generar el archivo .txt con la tabla de cuotas. 
        cout << "Desea generar la tabla de cuotas?: " << endl;
        cout << "1. Si." << endl;
        cout << "2. No." << endl;
        // Se lee la elección del usuario. 
        int opcion;
        leerEntero(opcion, "Ingrese una opcion: ");
        // Si desea generar la tabla de cuotas. 
        if(opcion == 1){
            // Se crea y se abre un archivo .txt en modo de escritura. 
            string nombreArchivo = "consulta_prestamo_personalizado.txt";
            ofstream archivo(nombreArchivo, ios::out | ios::trunc);
            // Se agrega un encabezado para el archivo. 
            archivo << "Consulta sobre un prestamo personalizado" << endl;
            archivo << endl;
            // Se agrega un encabezado para la información del préstamo con los títulos de cada columna. 
            archivo << "----------------------------Informacion del prestamo----------------------------" << endl;
            archivo << "tipo de prestamo, tipo de moneda, monto total, cantidad cuotas, tasa interes" << endl;
            // Se agrega la información del préstamo con los datos correspondientes a los títulos del encabezado. 
            archivo << prestamo.tipo + "," + prestamo.tipoMoneda + ", " + to_string(prestamo.montoTotal)
            + ", " + to_string(prestamo.cuotasTotal) + ", " + to_string(prestamo.tasaInteres) << endl;
            // Se agrega un encabezado para la información de las cuotas con el título de cada columna. 
            archivo << "----------------------------Cuotas a pagar en este prestamo----------------------------" << endl;
            archivo << "numero de cuota, costo de cuota, aporte deuda, aporte intereses, monto restante" << endl;
            // Se agrega la información de las cuotas utilizando el método de la clase Prestamo. 
            vector <string> cuotas = prestamo.infoCuotas;
            for (string linea : cuotas){
                // Se agrega cada línea del vector al archivo .txt con la información de las cuotas.
                archivo << linea << endl;
            }
            // Se cierra el archivo. 
            archivo.close();
            // Se imprime in mensaje de confirmación que indica que se logró generar el archivo sin problemas. 
            cout << "\nSe genero el archivo: " << nombreArchivo << endl;
        }
        // Si no desea generar el informe de cuotas. 
        else if(opcion == 2){
            // Se detiene la ejecución del método. 
            return;
        }
        // Si ingresa algo que no está entre las opciones dadas. 
        else{
            // Se imprime un mensaje de opción inválida. 
            cout << "La opcion ingresada no es valida. Intente de nuevo." << endl;
        }
}
