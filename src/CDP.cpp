#include "CDP.hpp"

void CDP::setDatos(int fechaCreacion_p[], string tipoMoneda_P, int plazoMeses_p, double dineroCDP_p, double tasaInteres_p){
    tipoMoneda = tipoMoneda_P;          //< Se inicializa el atributo tipoMoneda
    plazoMeses = plazoMeses_p;          //< Se inicializa el atributo plazoMeses
    dineroCDP = dineroCDP_p;            //< Se inicializa el atributo dineroCDP
    tasaInteres = tasaInteres_p;        //< Se inicializa el atributo tasaInteres

    fechaCreacion[0] = fechaCreacion_p[0];      //< Se inicializa el primer valor del array fechaCreacion
    fechaCreacion[1] = fechaCreacion_p[1];      //< Se incializa el segundo valor del array fechaCreacion
    fechaCreacion[2] = fechaCreacion_p[2];      //< Se inicializa el tercer valor del array fechaCreacion

    /* Se inicializa el primer valor del array fechaExiracion */
    fechaExpira[0] = fechaCreacion[0];
    /* Calcula el plazo de meses dado, partiendo de la fecha actual, e inicializa el segundo valor con el*/
    fechaExpira[1] = fechaCreacion[1] + plazoMeses%12;      //< Con el residuo se calcula los meses extra
    /* Calcula el plazo de años dado, patiendo de la fecha actual, e inicializa el tercer valor con el*/
    fechaExpira[2] = fechaCreacion[2] + int(plazoMeses/12); //< Con cociente se calcula los años extra

    /* Guarda en un array la informacion de certificado */
    informacion = to_string(dineroCDP) + "," + to_string(plazoMeses) + "," + to_string(tasaInteres) + ","
    + to_string(fechaCreacion[0]) + "/" + to_string(fechaCreacion[1]) + "/" + to_string(fechaCreacion[2]) + ","
    + to_string(fechaExpira[0]) + "/" + to_string(fechaExpira[1]) + "/" + to_string(fechaExpira[2]);
}


void CDP::actualizarCDP(int fecha[]){
    int tiempoMeses = tiempoMeses = (fecha[2] - fechaCreacion[2])*12 + (fecha[1] - fechaCreacion[1]);
    if(fecha[0] < fechaCreacion[0]){
        tiempoMeses -= 1;
    }
    if(tiempoMeses < 0){
        tiempoMeses = 0;
    }
    if(tiempoMeses > plazoMeses){
        estado = "vencido";
    }
