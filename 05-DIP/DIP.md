
# 5. Dependency Inversion Principle (DIP) - Principio de Inversión de Dependencias

## 🎯 Explicación

Este principio invierte el flujo de dependencia tradicional:
1.  Los módulos de **alto nivel** (lógica de negocio) no deben depender de módulos de **bajo nivel** (detalles de implementación, ej: base de datos).
2.  Ambos deben depender de **abstracciones** (interfaces o clases abstractas).

Las abstracciones (los contratos) no deben depender de los detalles; **los detalles deben depender de las abstracciones**.
