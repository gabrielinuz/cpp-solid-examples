## 📝 Single Responsibility Principle (SRP)

### 🎯 Explicación

Una clase debe tener **una, y solo una, razón para cambiar**.

Esto significa que cada clase o módulo debe tener una **única responsabilidad** bien definida y estar enfocado exclusivamente en esa tarea. Al asegurar que una clase solo tenga una responsabilidad, cualquier cambio en una funcionalidad específica solo requerirá modificar esa clase, minimizando el riesgo de introducir errores en otras áreas.

---

## 📝 Open/Closed Principle (OCP)

### 🎯 Explicación

Las entidades de software (clases, módulos, funciones) deben estar **abiertas para extensión**, pero **cerradas para modificación**.

Debes poder **extender** el comportamiento de un sistema (añadir nuevas funcionalidades) **sin modificar** el código fuente existente de las clases ya probadas y funcionando. Esto se logra utilizando **abstracciones** (interfaces o clases base abstractas) y polimorfismo, permitiendo que el código existente interactúe con el nuevo código a través de un contrato fijo.

---

## 📝 Liskov Substitution Principle (LSP)

### 🎯 Explicación

Los objetos de una **clase derivada** deben poder **sustituir** a objetos de la **clase base** sin alterar la corrección o el comportamiento deseado del programa.

En términos de código, esto significa que cuando se usa el polimorfismo, el subtipo debe adherirse al contrato de la superclase. Las clases hijas no deben cambiar el significado fundamental de los métodos heredados, lanzar excepciones inesperadas, o restringir las precondiciones de una manera que rompa la lógica que maneja la clase base.

---

## 📝 Interface Segregation Principle (ISP)

### 🎯 Explicación

No se debe obligar a los **clientes** (clases que usan la interfaz) a depender de **interfaces que no usan**.

Es mucho mejor tener **interfaces pequeñas y específicas** (segregadas) que una única interfaz grande y "gorda". Las interfaces deben ser lo suficientemente pequeñas para que las clases solo implementen los métodos que son relevantes para su rol, evitando tener que implementar métodos vacíos o lanzar errores por funcionalidades no soportadas.

---

## 📝 Dependency Inversion Principle (DIP)

### 🎯 Explicación

Este principio invierte el flujo de dependencia tradicional y se define en dos puntos:

1.  Los **módulos de alto nivel** (lógica de negocio) no deben depender de **módulos de bajo nivel** (detalles de implementación, como bases de datos o servicios concretos).
2.  Ambos deben depender de **abstracciones** (interfaces o clases abstractas).

En la práctica, esto significa que el código de alto nivel define el contrato (la abstracción), y los detalles de bajo nivel deben implementarlo. Esto reduce el acoplamiento y facilita la Inyección de Dependencias.