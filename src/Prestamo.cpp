#include "Prestamo.hpp"

//< Método para establecer los datos del préstamo
void Prestamo::setDatos(string tipoMoneda_p, double montoTotal_p, int cuotasTotal_p, double tasaInteres_p){
    tipoMoneda = tipoMoneda_p;       //< Se inicializa el atributo tipoMoneda
    montoTotal = montoTotal_p;       //< Se inicializa el atributo montoTotal
    cuotasTotal = cuotasTotal_p;     //< Se inicializa el atributo cuotasTotal
    tasaInteres = tasaInteres_p;     //< Se inicializa el atributo tasaInteres

    //< Calcula el costo de la cuota
    costoCuota = (montoTotal*tasaInteres*pow(1+tasaInteres,cuotasTotal))/(pow(1+tasaInteres,cuotasTotal) - 1);
    cuotasPagadas = 0;      //< La cantidad de cuotas pagadas es inicialmente cero
    interesesPagados = 0;   //< La cantidad de intereses pagados es inicialmente cero
    deudaPagada = 0;        //< La parte de la deuda pagada es inicialmente cero
    
    double montoRestante = montoTotal;      //< El monto restante es inicialmente el monto total de la deuda
    for(int i = 1; i <= cuotasTotal; i++){
        //< Se calcula el aporte de intereses
        double aporteIntereses = montoRestante*tasaInteres;
        //< Se calcula el aporte a la deuda
        double aporteDeuda = costoCuota - aporteIntereses;
        //< Se actualiza el monto restante del préstamo
        montoRestante -= aporteDeuda;
        //< Se verifica si el monto es menor a cero y en caso de serlo lo ajusta a cero
        if(montoRestante < 0){
            montoRestante = 0;      //< Utilizado para evitar valores negativos
        }
        //< Se define un string con la información de la cuota
        string infoCuota = "Cuota " + to_string(i) + ", " + to_string(costoCuota) + ", " + to_string(aporteDeuda) + ", " + to_string(aporteIntereses) + ", " + to_string(montoRestante);
        // Se agrega la información de la cuota al contenedor con la información de las cuotas
        infoCuotas.push_back(infoCuota);
    }
}

//< Método que imprime toda la información relacionada al préstamo
void Prestamo::imprimirInfo(){
    cout << "\n---Prestamo numero " << numeroPrestamo << "---" << endl;
    cout << "Monto total: " << montoTotal << endl;
    cout << "Cantidad total de cuotas: " << cuotasTotal << endl;
    cout << "Tasa de interes: " << tasaInteres << endl;
    cout << "Costo de la cuota: " << costoCuota << endl;
    cout << endl;
}

//< Método para pagar una cuota
void Prestamo::pagarCuota(){
    //< Se suma 1 a la cantidad de cuotas pagadas
    cuotasPagadas += 1;
    //< Se calcula el monto restante antes de pagar la cuota
    double montoRestante = montoTotal - deudaPagada;
    //< Se calcula el aporte de intereses de la cuota a pagar
    double aporteIntereses = montoRestante*tasaInteres;
    //< Se calcula el aporte de la deuda de la cuota a pagar
    double aporteDeuda = costoCuota - aporteIntereses;
    //< Se agrega el aporte de intereses a la cantidad de interes pagados
    interesesPagados += aporteIntereses;
    //< Se agrega el aporte de la deuda a la cantidad de deuda pagada
    deudaPagada += aporteDeuda;
}

//< Método para generar el reporte de cuotas
vector <string> Prestamo::generarReporteCuotas(){
    // Se declara una vector de strings que contendrá la información del reporte
    vector <string> reporte;
    // Se agrega un encabezado para cada columna del reporte
    reporte.push_back("numero de cuota, costo de cuota, aporte deuda, aporte intereses, monto restante");
    // Se agrega un encabezado para las cuotas pagadas
    reporte.push_back("Cuotas pagadas");
    // Se agrega la información de cada una de las cuotas pagadas al reporte
    for(int i = 0; i < cuotasPagadas; i++){
        reporte.push_back(infoCuotas[i]);
    }
    // Se agrega un encabezado para las cuotas restantes
    reporte.push_back("Cuotas restantes");
    // Se agrega la información de cada una de las cuotas restantes al reporte
    for(int i = cuotasPagadas; i < cuotasTotal; i++){
        reporte.push_back(infoCuotas[i]);
    }
    // Se retorna el vector de strings que incluye la información del reporte
    return reporte;
}