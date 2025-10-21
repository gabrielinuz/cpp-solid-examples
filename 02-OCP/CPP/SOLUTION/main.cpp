/**
* Cumple con OCP (Solución)
* El código cumple con el OCP utilizando el polimorfismo. La función calcularTotal
* está cerrada a modificación (siempre llama a f->getArea()), pero el sistema está
* abierto a extensión: para añadir una nueva forma (Triangulo), solo se crea una nueva
* clase que hereda de Forma y no es necesario tocar el código de CalculadoraArea.
*/
#include <iostream>
#include <vector>
#include <memory>

class Forma 
{
    public:
        virtual ~Forma() = default;
        virtual double getArea() const = 0;
};

class Rectangulo : public Forma
{
    public:
        double ancho, alto;
        Rectangulo(double a, double h) : ancho(a), alto(h) {}
        double getArea() const override { return ancho * alto; }
};

class Circulo : public Forma
{
    public:
        double radio;
        Circulo(double r) : radio(r) {}
        double getArea() const override { return 3.14159 * radio * radio; }
};

class CalculadoraArea 
{
    public:
        // virtual ~CalculadoraArea() = default;
        double calcularTotal(const std::vector<std::shared_ptr<Forma>>& formas) const 
        {
            double total = 0;
            for (const auto& f : formas) 
            {
                total += f->getArea();
            }
            return total;
        }
};


int main()
{
    std::shared_ptr<Forma> rectangulo = std::make_shared<Rectangulo>(3, 4);
    std::shared_ptr<Forma> circulo = std::make_shared<Circulo>(4);

    std::cout << "Área del rectangulo: " << rectangulo->getArea() << std::endl;
    std::cout << "Área del círculo: " << circulo->getArea() << std::endl;

    std::vector<std::shared_ptr<Forma>> formas;
    formas.push_back(rectangulo);
    formas.push_back(circulo);

    auto calculadora = std::make_unique<CalculadoraArea>();
    std::cout << "Área total de formas: " << calculadora->calcularTotal(formas) << std::endl;
    
    return 0;
}