# Nombre del ejecutable
TARGET = gestion_banco.exe

# Objetivo predeterminado
all: $(TARGET)

# Compilador
CXX = g++

# Banderas de compilacion
CXXFLAGS = -Wall -std=c++11

# Lista de archivos fuente
SOURCES = .\src\main.cpp .\src\Banco.cpp .\src\AtencionCliente.cpp .\src\Informacion.cpp .\src\Cliente.cpp .\src\CuentaBancaria.cpp .\src\Prestamo.cpp .\src\CDP.cpp .\src\LecturaDatos.cpp

# Lista de archivos ejecutables
OBJECTS = $(SOURCES:.cpp=.exe)

# Regla para compilar los archivos fuente
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para compilar el programa
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	$(TARGET)

	@del gestion_banco.exe

# Regla para limpiar los archivos
.PHONY: clean
clean:
	del .\src\main.exe .\src\Banco.exe .\src\AtencionCliente.exe .\src\Informacion.exe .\src\Cliente.exe .\src\CuentaBancaria.exe .\src\Prestamo.exe .\src\CDP.exe .\src\LecturaDatos.exe informe_cuentas.txt informe_prestamos.txt informe_certificados_plazo.txt consulta_prestamo_predeterminado.txt consulta_prestamo_personalizado.txt registro_transacciones.txt info_clientes.txt