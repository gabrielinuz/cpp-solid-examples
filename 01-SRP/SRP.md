# 1. Single Responsibility Principle (SRP) - Principio de Responsabilidad Única

## 🎯 Explicación

Una clase debe tener **una, y solo una, razón para cambiar**.

Esto significa que cada clase o módulo debe tener una **única responsabilidad** bien definida y estar enfocado exclusivamente en esa tarea.

### 💼 Ejemplo de Negocio (Violación)

Si una clase `Empleado` se encarga de manejar los **datos** del empleado y de implementar la lógica para **guardar** en la base de datos (`guardarEnArchivo()`), viola este principio.

**Solución:** Separar la lógica de persistencia en una clase dedicada, como `EmpleadoRepositorio`.