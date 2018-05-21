#ifndef NOTBLAD_H
#define NOTBLAD_H

#include <vector>

#include "not.h"

class Notblad
{
public:
    Notblad();

    void adderaNot(int typofnot, int hojd);

    std::vector<Not*> getNotes(void);


private:
    std::vector<Not*> notvector;

};

#endif // NOTBLAD_H
