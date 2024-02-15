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