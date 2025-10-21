// 1. Importación Correcta: Usamos 'import' para módulos Node.js/CommonJS en TS.
//    También necesitamos instalar los tipos de Node.js (@types/node) para que esto funcione.
import * as fs from 'fs';

class Empleado 
{
    constructor(public nombre: string, public salario: number) {}

    getNombre(): string { return this.nombre; }
    getSalario(): number { return this.salario; }

    guardarEnArchivo(): void 
    {
        const fs = require('fs');
        fs.appendFileSync('empleados.txt', `${this.nombre},${this.salario}\n`);
        console.log('Empleado guardado en archivo.');
    }
}

function main()
{
    let juan = new Empleado("Ana", 30.5);
    juan.guardarEnArchivo();
}

main();