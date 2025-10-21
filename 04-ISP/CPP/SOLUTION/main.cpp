/**
* Cumple con ISP (Solución)
* El código cumple con el ISP porque la interfaz se segrega en roles pequeños:
* (Imprimible, Escaneable, Faxeable). La ImpresoraSimple solo implementa la interfaz
* que realmente necesita (Imprimible), y la ImpresoraMultifuncional implementa las tres,
* sin forzar a ninguna clase a implementar métodos irrelevantes.
*/
#include <iostream>
#include <memory>

class Imprimible
{
    public:
        virtual void imprimir() = 0;
        virtual ~Imprimible() = default;
};

class Escaneable
{
    public:
        virtual void escanear() = 0;
        virtual ~Escaneable() = default;
};

class Faxeable
{
    public:
        virtual void faxear() = 0;
        virtual ~Faxeable() = default;
};

class ImpresoraSimple : public Imprimible
{
    public:
        void imprimir() override { std::cout << "Imprimiendo...\n"; }
};

class ImpresoraMultifuncional : public Imprimible, public Escaneable, public Faxeable
{
    public:
        void imprimir() override { std::cout << "Imprimiendo, "; }
        void escanear() override { std::cout << "Escaneando, "; }
        void faxear() override { std::cout << "Faxeando." << std::endl; }
};

int main()
{
    auto xerox = std::make_unique<ImpresoraSimple>();
    std::cout << "Xerox: ";
    xerox->imprimir();
    
    auto brother = std::make_unique<ImpresoraMultifuncional>();
    std::cout << "Brother: ";
    brother->imprimir();
    brother->escanear();
    brother->faxear();

    return 0;
}