#pragma once
#include "Builder.h"
#include "FactoryMethods.h"
#include <Prototype.h>

int main() {

#pragma region ProfesorFactoryMethod
	// Factory Method
	FMFabrica* fabrica = new FMFabricaConcreta();
	FMProducto* producto = fabrica->crearProducto();

	vector <FMProducto*> productos;
	producto->operacion();


	// Factory Method 2
	FMProducto* chettos = fabrica->crearProducto2();
	chettos->registrar("Torciditos", 10.0f, 10.0f);
	chettos->operacion();

	delete fabrica;
	delete producto;
	delete chettos;
#pragma endregion

#pragma region FernandoFactoryMethod
	FMFabricaVehiculos* fabricaCoches = new FMFabricaCoches();
	FMVehiculo* coche = fabricaCoches->crearVehiculo();
	coche->descripcion();
	delete coche;
	delete fabricaCoches;

	FMFabricaVehiculos* fabricaBicicletas = new FMFabricaBicicletas();
	FMVehiculo* bicicleta = fabricaBicicletas->crearVehiculo();
	bicicleta->descripcion();
	delete bicicleta;
	delete fabricaBicicletas;
#pragma endregion


#pragma region ProfesorBuilderMethod
	Builder* builder = new BuilderConcreto();
	Director director(builder);

	director.construir();

	BPProduct* product = builder->obtenerProducto();
	product->mostrar();

	delete builder;
	delete product;
#pragma endregion

#pragma region Fernando BuilderMethod
	DirectorPizza directorPizza;
	ConstructorPizzaHawaiana constructorHawaiana;
	ConstructorPizzaVegetariana constructorVegetariana;

	directorPizza.setConstructor(&constructorHawaiana);
	Pizza* pizzaHawaiana = directorPizza.construirPizza();
	pizzaHawaiana->mostrar();

	directorPizza.setConstructor(&constructorVegetariana);
	Pizza* pizzaVegetariana = directorPizza.construirPizza();
	pizzaVegetariana->mostrar();

	// Eliminar
	delete pizzaHawaiana;
	delete pizzaVegetariana;
#pragma endregion

#pragma region Profesor PrototypeMethod

	// Prototype
	Prototype* prototipo = new PrototypeConcreto();
	prototipo->configurar("Ejemplo");

	Prototype* copia = prototipo->clonar();
	copia->mostrar();
	prototipo->mostrar();

	delete prototipo;
	delete copia;

#pragma endregion


#pragma region Fernando PrototypeMethod

	DocumentoPrototype* prototipoDocumento = new DocumentoConcreto();
	prototipoDocumento->configurar("Documento de ejemplo");

	DocumentoPrototype* copiaDocumento = prototipoDocumento->clonar();
	copiaDocumento->mostrar();
	prototipoDocumento->mostrar();

	delete prototipoDocumento;
	delete copiaDocumento;

	DocumentoPrototype* prototipoDocumento = new ImagenConcreto();
	prototipoDocumento->configurar("Imagen de ejemplo");

	DocumentoPrototype* copiaDocumento = prototipoDocumento->clonar();
	copiaDocumento->mostrar();
	prototipoDocumento->mostrar();

	delete prototipoDocumento;
	delete copiaDocumento;

#pragma endregion
	return 0;
}