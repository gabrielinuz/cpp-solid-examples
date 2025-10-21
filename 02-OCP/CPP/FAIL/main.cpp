/**
* No Cumple con OCP
* La función calcularArea está cerrada a extensión y abierta a modificación. 
* Si se quiere añadir una nueva forma (ej: Triangulo), es necesario modificar
* la función calcularArea para añadir otro else if.
*/

#include <iostream>
#include <vector>
#include <memory>

enum class TipoForma { RECTANGULO, CIRCULO };

class Forma 
{
    public:
        TipoForma tipo;
        double ancho, alto, radio;

        Forma(TipoForma t, double ancho, double alto, double radio) : tipo(t), ancho(0), alto(0), radio(0) {}
};

double calcularArea(const std::vector<Forma*>& formas) 
{
    double total = 0;
    for (const auto& f : formas)
    {
        if (f->tipo == TipoForma::RECTANGULO)
        {
            total += f->ancho * f->alto;
        }
        else if (f->tipo == TipoForma::CIRCULO)
        {
            total += 3.14159 * f->radio * f->radio;
        }
    }
    return total;
}

int main()
{
    auto rectangulo = std::make_shared<Forma>(TipoForma::RECTANGULO, 3, 4, 0);
    
    return 0;
}