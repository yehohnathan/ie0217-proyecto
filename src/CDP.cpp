#include "CDP.hpp"

// Se le ingresa los datos según lo solicitado por el cliente
void CDP::setDatos(int idPropietario_p, int numeroCDP_p, string tipoMoneda_p, double dineroCDP_p, int fechaCreacion_p[], int plazoMeses_p, double tasaInteres_p, string tipo_p){
    tipo = tipo_p;
    idPropietario = idPropietario_p;
    numeroCDP = numeroCDP_p;
    tipoMoneda = tipoMoneda_p;          // Se inicializa el atributo tipoMoneda
    dineroCDP = dineroCDP_p;            // Se inicializa el atributo dineroCDP
    tasaInteres = tasaInteres_p;        // Se inicializa el atributo tasaInteres
    plazoMeses = plazoMeses_p;          // Se inicializa el atributo plazoMeses
    tasaInteres = tasaInteres_p;        // Se inicializa el atributo tasaInteres

    fechaCreacion[0] = fechaCreacion_p[0];      // Se inicializa el primer valor del array fechaCreacion
    fechaCreacion[1] = fechaCreacion_p[1];      // Se incializa el segundo valor del array fechaCreacion
    fechaCreacion[2] = fechaCreacion_p[2];      // Se inicializa el tercer valor del array fechaCreacion

    /* Se inicializa el primer valor del array fechaExiracion */
    fechaExpira[0] = fechaCreacion[0];
    /* Calcula el plazo de meses dado, partiendo de la fecha actual, e inicializa el segundo valor con el*/
    fechaExpira[1] = fechaCreacion[1] + plazoMeses%12;      // Con el residuo se calcula los meses extra
    /* Calcula el plazo de años dado, partiendo de la fecha actual, e inicializa el tercer valor con el*/
    fechaExpira[2] = fechaCreacion[2] + int(plazoMeses/12); // Con cociente se calcula los años extra

    // Se indica el estado del CDP
    estado = "vigente";     // En la fecha de creación este va a estar siempre vigente
}

// Actualiza la linea temporal del CDP para saber si ya llegó a su vencimiento //< Esto esto esta a prueba
void CDP::actualizarCDP(int fecha[]){
    // Ajusta la hora ingresada en un formato de meses y lo iguala a una variable
    int tiempoMeses = (fecha[2] - fechaCreacion[2])*12 + (fecha[1] - fechaCreacion[1]);
    // Luego se va actualizando las fechas, esto depende de la fecha inicial de llegada del banco
    if(fecha[0] < fechaCreacion[0]){
        tiempoMeses -= 1;
    }
    if(tiempoMeses >= plazoMeses){
        // Si la distancia temporal entre la fecha de creación y la fecha actual del banco supera el plazo de
        // meses del CDP se actualiza el estado
        estado = "vencido";
    }

}
