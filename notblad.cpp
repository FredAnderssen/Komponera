#include "notblad.h"

Notblad::Notblad()
{

}

void Notblad::adderaNot(int typofnot, int hojd)
{
    //TODO minnet om size överstiges?
    Not* typ = new Not();
    typ->setHeight(hojd);
    typ->setLength(typofnot);
    notvector.push_back(typ);

}

std::vector<Not*> Notblad::getNotes(void)
{
    return notvector;
}

