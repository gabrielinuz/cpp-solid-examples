type TipoForma = 'RECTANGULO' | 'CIRCULO';

interface Forma 
{
    tipo: TipoForma;
    ancho?: number;
    alto?: number;
    radio?: number;
}

function calcularArea(formas: Forma[]): number 
{
    return formas.reduce((total, f) => {
        if (f.tipo === 'RECTANGULO') {
            return total + (f.ancho! * f.alto!);
        } else if (f.tipo === 'CIRCULO') {
            return total + (3.14159 * f.radio! * f.radio!);
        }
        return total;
    }, 0);
}