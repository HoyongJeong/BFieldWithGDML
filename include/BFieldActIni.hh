#ifndef BFIELDACTINI_h
#define BFIELDACTINI_h 1

#include "G4VUserActionInitialization.hh"

class BFieldActIni : public G4VUserActionInitialization
{
public:
    BFieldActIni();
    virtual ~BFieldActIni();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

#endif
