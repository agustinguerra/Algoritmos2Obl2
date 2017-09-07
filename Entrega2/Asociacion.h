#pragma once

template <class D,class R>
class Asociacion {
public:
	D clave;
	R valor;
	Asociacion(const D&clave,const R&valor) : clave(clave),valor(valor) {  };
};
