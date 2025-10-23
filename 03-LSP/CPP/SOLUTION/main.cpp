/**
* Cumple con LSP (Solución)
* El código cumple con el LSP porque se evita la herencia incorrecta 
* (Pinguino de Ave con el método volar). Se utiliza la composición de interfaces 
* (Nadadora, Voladora) para modelar el comportamiento correcto. Todos los objetos
* que heredan de Ave (como Paloma y Pinguino) pueden sustituirse en el método 
* iniciarAovacion sin romper el comportamiento.
*/
#include <iostream>
#include <vector>
#include <memory>

class Nadadora
{
    public:
        virtual void nadar() = 0;
        virtual ~Nadadora() = default;
};

class Voladora
{
    public:
        virtual void volar() = 0;
        virtual ~Voladora() = default;
};

class Aovadora
{
    public:
        virtual void aovar() = 0;
        virtual ~Aovadora() = default;
};

class Ave : public Aovadora
{
    protected:
        // string plumasTipo;
        // Ave();
    public:
        virtual ~Ave() = default;
        void piar() { std::cout << "Esta ave está piando.\n"; }
        //implementa Aovadora
        virtual void aovar() override { std::cout << "Esta ave está poniendo huevos.\n"; }
};

class AveNadadora: public Ave, public Nadadora 
{
    public:
        virtual void nadar() { std::cout << "Esta ave está nadando.\n"; }
        virtual ~AveNadadora() = default;
};

class AveVoladora: public Ave, public Voladora
{
    public:
        virtual void volar() { std::cout << "Esta ave está volando.\n"; }
        virtual ~AveVoladora() = default;
};


class Paloma : public AveVoladora 
{
    public:
        void volar() override { std::cout << "La paloma vuela alto.\n"; }
};

class Pinguino : public AveNadadora
{
    public:
        void nadar() override { std::cout << "El pingüino nada rápido.\n"; }
};

class MaquinaAovadora
{
    public:
        void iniciarAovacion(const std::vector<std::shared_ptr<Ave>>& aves) const
        {
            for (const auto& ave : aves) 
            {
                ave->aovar();
            }        
        }
};

int main()
{
    auto tux = std::make_shared<Pinguino>();
    tux->nadar();
    tux->piar();

    auto peace = std::make_shared<Paloma>();
    peace->volar();
    peace->piar();

    std::vector< std::shared_ptr<Ave> > aves;
    aves.push_back(tux);
    aves.push_back(peace);

    auto caterpillar = std::make_unique<MaquinaAovadora>();
    caterpillar->iniciarAovacion(aves);
    
    return 0;
}