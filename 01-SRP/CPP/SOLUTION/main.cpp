/**
* El código cumple con el SRP al separar la gestión de la entidad (Empleado) 
* de la gestión de la persistencia (EmpleadoRepositorio). Ahora, si el formato
* de guardado cambia (a base de datos, por ejemplo), solo debe modificarse 
* la clase EmpleadoRepositorio.
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

        std::string getNombre() const { return nombre; }
        double getSalario() const { return salario; }
};

class EmpleadoRepositorio 
{
    public:
        void guardar(const std::shared_ptr<Empleado>& emp) 
        {
            std::ofstream file("empleados.txt", std::ios::app);
            file << emp->getNombre() << "," << emp->getSalario() << "\n";
            file.close();
            std::cout << "Empleado guardado en archivo.\n";
        }
};

int main()
{
    auto juan = std::make_shared<Empleado>("Ana", 30.5);
    auto repo = std::make_shared<EmpleadoRepositorio>();
    repo->guardar(juan);

    return 0;
}