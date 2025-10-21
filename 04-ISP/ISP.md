# 4. Interface Segregation Principle (ISP) - Principio de Segregación de la Interfaz

## 🎯 Explicación

No se debe obligar a los clientes a depender de **interfaces que no usan**.

Es mejor tener **interfaces pequeñas y específicas** que una interfaz grande y monolítica.

### ✂️ Ejemplo

En lugar de una única interfaz `MultiFunción` con métodos para `imprimir()`, `escanear()` y `faxear()`, es mejor tener interfaces segregadas como `Imprimible` y `Escaneable`. Así, una clase solo implementa lo que realmente necesita.
