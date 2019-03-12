#ifndef BFIELDRUNACT_h
#define BFIELDRUNACT_h 1

#include "G4UserRunAction.hh"

class G4Run;

class BFieldRunAct : public G4UserRunAction
{
  public:
    BFieldRunAct();
    virtual ~BFieldRunAct();

    virtual void BeginOfRunAction(const G4Run*);
    virtual void   EndOfRunAction(const G4Run*);
};

#endif
