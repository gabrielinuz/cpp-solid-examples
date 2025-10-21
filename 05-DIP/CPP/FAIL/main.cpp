/**
* No Cumple con DIP
* El código viola el DIP porque el módulo de alto nivel (Vehiculo) depende
* directamente del módulo de bajo nivel (MotorGasolina). El Vehiculo está
* fuertemente acoplado a un motor concreto, lo que significa que es rígido y
* no puede cambiar a un MotorElectrico sin modificar su código fuente.
*/
#include <iostream>
#include <memory>

class MotorGasolina 
{
    public:
        void encender() { std::cout << "Motor de gasolina encendido.\n"; }
};

class Vehiculo 
{
    private:
        MotorGasolina motor;
    public:
        Vehiculo() {}
        void arrancar() { motor.encender(); }
};

int main()
{
    auto fiat1500 = std::make_unique<Vehiculo>();
    std::cout << "Fiat 1500: ";
    fiat1500->arrancar();
    
    auto renault12 = std::make_unique<Vehiculo>();
    std::cout << "Renault 12: ";
    renault12->arrancar();

    return 0;
}