#include "Banco.hpp"

int main(){
    Banco banco;
    cout << "\n---Bienvenido a nuestro Banco Virtual---" << endl;

    banco.leerInfoClientes();
    banco.leerTransacciones();

    banco.mostrarMenu();
    
    banco.actualizarInfoClientes();
    banco.actualizarTransacciones();
    
    return 0;
}