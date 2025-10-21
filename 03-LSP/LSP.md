
# 3. Liskov Substitution Principle (LSP) - Principio de Sustitución de Liskov

## 🎯 Explicación

Los objetos de una **clase derivada** deben poder **sustituir** a objetos de la **clase base** sin alterar la corrección o el comportamiento deseado del programa.

En otras palabras, si tu código espera un tipo `Base`, debe funcionar perfectamente cuando recibe un objeto de tipo `Derivada` (Subtipo).

### ⚠️ Implicación

Las clases hijas no deben hacer menos de lo que hacen sus padres, ni deben cambiar los contratos o precondiciones definidas por la clase base.