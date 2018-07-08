#include "P3DMaterial.h"




P3DMaterial * NewP3DMat()
{
	Class_ID P3DMat = { 0x7e8caded , 0xb6928000 };
	Interface *gi = GetCOREInterface();
	P3DMaterial *mtlb = (P3DMaterial*)gi->CreateInstance(MATERIAL_CLASS_ID, P3DMat);
	if (mtlb)
	{
		return mtlb;
	}
	return NULL;

}

int P3DMaterial::ConvertPrepar3DMaterials(RIFFMATE * mate)
{

	return 0;
}
