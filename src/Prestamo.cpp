#include "Prestamo.hpp"

void Prestamo::setDatos(string tipoMoneda_p, double montoTotal_p, int cuotasTotal_p, double tasaInteres_p){
    tipoMoneda = tipoMoneda_p;       //< Inicializa el atributo tipoMoneda
    montoTotal = montoTotal_p;       //< Inicializa el atributo montoTotal
    cuotasTotal = cuotasTotal_p;     //< Inicializa el atributo cuotasTatales
    tasaInteres = tasaInteres_p;     //< Inicializa el atributo tasaInteres

    /* Calcula el valor de una cuota*/
    costoCuota = (montoTotal*tasaInteres*pow(1+tasaInteres,cuotasTotal))/(pow(1+tasaInteres,cuotasTotal) - 1);
    cuotasPagadas = 0;      //< Cantidad de cuotas pagadas
    interesesPagados = 0;   //< Cantidad de intereses pagados
    deudaPagada = 0;        //< Parte de la deuda pagada
    
    double montoRestante = montoTotal;      //< 
    for(int i = 1; i <= cuotasTotal; i++){
        /* Calcula el aporte a intereses */
        double aporteIntereses = montoRestante*tasaInteres;
        /* Calcula el aporte a la deuda*/
        double aporteDeuda = costoCuota - aporteIntereses;
        /* Actualiza el monto restante del prestamo*/
        montoRestante -= aporteDeuda;
        /* Verifica si el monto es menor a cero y en caso de serlo lo ajusta a cero*/
        if(montoRestante < 0){
            montoRestante = 0;      //< Utilizado para evitar valores negativos
        }
        /* Define un string con la informacion de la cuota*/
        string infoCuota = "Cuota " + to_string(i) + ", " + to_string(costoCuota) + ", " + to_string(aporteDeuda) + ", " + to_string(aporteIntereses) + ", " + to_string(montoRestante);
        /* La agrega al contenedor */
        infoCuotas.push_back(infoCuota);
    }
}

/* Función que imprime toda la información relacionada al préstamo*/
void Prestamo::imprimirInfo(){
    cout << "\n---Prestamo numero " << numeroPrestamo << "---" << endl;
    cout << "Monto total: " << montoTotal << endl;
    cout << "Cantidad total de cuotas: " << cuotasTotal << endl;
    cout << "Tasa de interes: " << tasaInteres << endl;
    cout << "Costo de la cuota: " << costoCuota << endl;
    cout << endl;
}
