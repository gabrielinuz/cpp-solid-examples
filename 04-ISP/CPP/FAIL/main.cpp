/**
* No Cumple con ISP
* El código viola el ISP porque la clase ImpresoraSimple se ve obligada a implementar
* la interfaz grande DispositivoTodoEnUno con métodos (escanear, faxear) que no usa,
* forzándola a lanzar excepciones o a tener implementaciones vacías. El cliente que
* usa la ImpresoraSimple también debe conocer métodos que son irrelevantes.
*/
#include <iostream>
#include <memory>

class DispositivoTodoEnUno
{
    public:
        virtual void imprimir() = 0;
        virtual void escanear() = 0;
        virtual void faxear() = 0;
        virtual ~DispositivoTodoEnUno() = default;
};

class ImpresoraSimple : public DispositivoTodoEnUno
{
    public:
        void imprimir() override { std::cout << "Imprimiendo...\n"; }
        void escanear() override 
        {
            /* No lo soporta */ 
            throw std::runtime_error("La impresora simple no escanea.");
        }
        void faxear() override
        {
            /* No lo soporta */ 
            throw std::runtime_error("La impresora simple no recibe fax.");
        }
};

int main()
{
    auto xerox = std::make_unique<ImpresoraSimple>();
    xerox->imprimir();
    xerox->escanear();
    xerox->faxear();

    return 0;
}