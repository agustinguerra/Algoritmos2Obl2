#include "FuncionHashAnagrama.h"

nat FuncionHashAnagrama::CodigoDeHash(const Cadena& c) const
{
	nat hashCode = 0;
	nat prime1 = 11;
	nat prime2 = 31;
	nat prime3 = 43;
	for (nat i = 0; i < c.Largo; i++)
		hashCode += i * c[i];
	return hashCode;
}
