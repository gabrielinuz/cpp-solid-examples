interface Forma 
{
    area(): number;
}

class Rectangulo implements Forma 
{
    constructor(public ancho: number, public alto: number) {}
    area(): number { return this.ancho * this.alto; }
}

class CalculadoraArea 
{
    calcularTotal(formas: Forma[]): number 
    {
        return formas.reduce((total, f) => total + f.area(), 0);
    }
}