# 2. Open/Closed Principle (OCP) - Principio Abierto/Cerrado

## 🎯 Explicación

Las entidades de software deben estar **abiertas para extensión**, pero **cerradas para modificación**.

Se debe poder añadir nuevo comportamiento al sistema (extensión) **sin modificar** el código fuente existente de las clases ya probadas.

### 📐 Ejemplo (Correcto)

La clase **`Forma`** debe ser una **interfaz o clase puramente abstracta**. Para añadir una nueva forma (ej: `Triangulo`), simplemente creas una nueva clase `Triangulo` que implemente el contrato de `Forma` (abierta a extensión) sin modificar el código de la clase base o la función que calcula el área total (cerrada a modificación).