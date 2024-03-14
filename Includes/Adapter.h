#pragma once
#include "Prerequisites.h";

// Interfaz vieja
class InterfazVieja {
public:
	virtual void metodoViejo() {
		cout << "Metodo viejo llamado" << endl;
	}
};

// Interfaz vieja
class InterfazNueva {
public:
	virtual void metodoNuevo() {
		cout << "Metodo nuevo llamado" << endl;
	}
};

// Adpatador que las conecta
class Adapter : public InterfazNueva {
public:
	Adapter(InterfazVieja* vieja) : m_interfazVieja(vieja) {}

	virtual void metodoNuevo() override {
		cout << "Adaptador llmado al metodo nuevo" << endl;
		m_interfazVieja->metodoViejo();
	}

private:
	InterfazVieja* m_interfazVieja;
};


