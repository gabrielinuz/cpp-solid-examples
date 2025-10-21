/**
* No Cumple con LSP (Violación)
* El código viola el LSP porque la clase derivada Pinguino no puede sustituir 
* a su clase base Ave sin romper el comportamiento esperado. Si un código espera
* una Ave y llama a volar(), espera que vuele. El Pinguino rompe este contrato
* lanzando una excepción.
*/
#include <iostream>
#include <memory>

class Ave 
{
    public:
        virtual void volar() { std::cout << "Esta ave está volando.\n"; }
        virtual ~Ave() = default;
};

class Pinguino : public Ave 
{
    public:
        void volar() override 
        {
            throw std::runtime_error("Los pingüinos no vuelan.");
        }
};

int main()
{
    auto tux = std::make_shared<Pinguino>();
    tux->volar();

    return 0;
}