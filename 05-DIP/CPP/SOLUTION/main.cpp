/**
* Cumple con DIP (Solución)
* El código cumple con el DIP. Ambos módulos (Vehiculo y MotorGasolina) dependen
* de la abstracción (Motor). El módulo de alto nivel (Vehiculo) acepta cualquier
* Motor (polimorfismo) a través de la Inyección de Dependencias, y el módulo de bajo
* nivel (MotorGasolina) implementa la abstracción, invirtiendo la dependencia.
*/
#include <iostream>
#include <memory>

class Motor
{
    public:
        virtual void encender() = 0;
        virtual ~Motor() = default;
};

class MotorGasolina : public Motor
{
    public:
        void encender() override { std::cout << "Motor de gasolina encendido.\n"; }
};

class Vehiculo 
{
    private:
        std::unique_ptr<Motor> motor;
    public:
        //Toma la propiedad por movimiento.
        //std::unique_ptr no permite la copia, 
        //solo la transferencia de propiedad (movimiento).
        Vehiculo(std::unique_ptr<Motor> m) : motor(std::move(m)) {}
        void arrancar() { motor->encender(); }
};

int main()
{
    // 1. Primer Vehículo:
    auto motorFiat = std::make_unique<MotorGasolina>();

    // Usar std::move para transferir la propiedad del motorFiat 
    // al constructor de Vehiculo.
    auto fiat1500 = std::make_unique<Vehiculo>(std::move(motorFiat));
    std::cout << "Fiat 1500: ";
    fiat1500->arrancar();
    
    // 2. Segundo Vehículo:
    auto motorRenault = std::make_unique<MotorGasolina>();
    // Se repite el uso de std::move
    auto renault12 = std::make_unique<Vehiculo>(std::move(motorRenault));
    std::cout << "Renault 12: ";
    renault12->arrancar();

    return 0;
}