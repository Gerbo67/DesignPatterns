#pragma once
#include "Builder.h"
#include "FactoryMethods.h"
#include "Prototype.h"
#include "Composite.h"
#include "Bridge.h"
#include "Template.h"
#include "ChainsOfResponsability.h"
#include "Proxy.h"
#include "Adapter.h"
#include "Decorator.h"

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

#pragma region FernandoBuilderMethod
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

#pragma region ProfesorPrototypeMethod

	// Prototype
	Prototype* prototipo = new PrototypeConcreto();
	prototipo->configurar("Ejemplo");

	Prototype* copia = prototipo->clonar();
	copia->mostrar();
	prototipo->mostrar();

	delete prototipo;
	delete copia;

#pragma endregion


#pragma region FernandoPrototypeMethod

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

#pragma region ProfesorChainsOfResponsabilityMethod

	manejadorConcretoC handleC(nullptr);
	manejadorConcretoB handleB(&handleC);
	manejadorConcretoA handleA(&handleB);

	handleA.manejarSolicitud(50);
	handleA.manejarSolicitud(5);
	handleA.manejarSolicitud(15);
	handleA.manejarSolicitud(19);
	handleA.manejarSolicitud(3);

#pragma endregion

#pragma region FernandoChainsOfResponsabilityMethod

	manejadorDirectorGeneral directorGeneral(nullptr);
	manejadorGerente gerente(&directorGeneral);
	manejadorDirectivo directivo(&gerente);
	directivo.getMonto(800);
	directivo.getMonto(3500);
	directivo.getMonto(10000);

#pragma endregion

#pragma region ProfesorTemplateMethod

	Juego* juego1 = new Ajedrez();
	Juego* juego2 = new Monopoly();

	juego1->jugar();
	juego2->jugar();

	delete juego1;
	delete juego2;

#pragma endregion

#pragma region FernandoTemplateMethod

	Refrigerador* refri1 = new RefrigeradorSamsung;
	Refrigerador* refri2 = new RefrigeradorLG;
	refri1->jugar();
	refri2->jugar();
	delete refri1;
	delete refri2;

#pragma endregion

#pragma region ProfesorCompositeMethod

	Leaf* leaf1 = new Leaf();
	Leaf* leaf2 = new Leaf();

	Compuesto* compuesto = new Compuesto();
	compuesto->agregarLeaf(leaf1);
	compuesto->agregarLeaf(leaf2);

	compuesto->operacion();

	delete leaf1;
	delete leaf2;
	delete compuesto;

#pragma endregion

#pragma region FernandoCompositeMethod

	SistemaArchivo* archivo1 = new SistemaArchivo();
	SistemaArchivo* archivo2 = new SistemaArchivo();
	SistemaCarpeta* carpeta = new SistemaCarpeta();

	carpeta->agregarSistema(archivo1);
	carpeta->agregarSistema(archivo2);

	carpeta->mostrarInfo();

	delete archivo1;
	delete archivo2;
	delete carpeta;

#pragma endregion

#pragma region ProfesorBridgeMethod
	ImplementacionConcretaA impA;
	ImplementacionConcretaB impB;

	AbstraccionRefinada ARA(&impA);
	AbstraccionRefinada ARB(&impB);

	ARA.operacion();
	ARB.operacion();
#pragma endregion

#pragma region ProfesorProxyMethod

	Proxy proxy;
	proxy.operacion();
	proxy.operacion();

#pragma endregion

#pragma region ProfesorAdapterMethod

	// Adapter
	InterfazVieja* objetoViejo = new InterfazVieja();
	InterfazNueva* objetoNuevo = new Adapter(objetoViejo);

	objetoNuevo->metodoNuevo();

	delete objetoViejo;
	delete objetoNuevo;

#pragma endregion

#pragma region ProfesorDecoratorMethod

	// Por cada que pasa se agrega una "decoracion"
	ComponenteConcreto* obj = new ComponenteConcreto();
	DecoratorConcretoA* DecoratorA = new DecoratorConcretoA(obj);
	DecoratorConcretoB* DecoratorB = new DecoratorConcretoB(DecoratorA);

	obj->operacion();
	DecoratorA->operacion();
	DecoratorB->operacion();

	delete obj;
	delete DecoratorA;
	delete DecoratorB;

#pragma endregion

#pragma region FernandoDecoratorMethod

	Cafeteria* cafeteria = new Cafeteria();
	Leche* cafeConLeche = new Leche(cafeteria);
	Azucar* cafeConAzucar = new Azucar(cafeteria);

	cafeteria->prepararCafe();
	cafeConLeche->prepararCafe();
	cafeConAzucar->prepararCafe();

	delete cafeteria;
	delete cafeConLeche;
	delete cafeConAzucar;

#pragma endregion

	return 0;
}