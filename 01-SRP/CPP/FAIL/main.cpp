/**
* El código viola el SRP porque la clase Empleado tiene dos razones para cambiar: 
* si cambian los datos del empleado (nombre/salario) o si cambia la forma en que 
* se persiste (guardar en un archivo, base de datos, etc.).
*/
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

class Empleado 
{
    public:
        std::string nombre;
        double salario;

        Empleado(std::string n, double s) : nombre(n), salario(s) {}

        // Responsabilidad 1: gestionar datos del empleado
        std::string getNombre() const { return nombre; }
        double getSalario() const { return salario; }

        // Responsabilidad 2: guardar en archivo (violación de SRP)
        void guardarEnArchivo() 
        {
            std::ofstream file("empleados.txt", std::ios::app);
            file << nombre << "," << salario << "\n";
            file.close();
            std::cout << "Empleado guardado en archivo.\n";
        }
};

int main()
{
    auto juan = std::make_shared<Empleado>("Ana", 30.5);
    juan->guardarEnArchivo();

    return 0;
}