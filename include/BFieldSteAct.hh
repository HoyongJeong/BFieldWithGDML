#ifndef BFIELDSTEACT_h
#define BFIELDSTEACT_h 1

#include "G4UserSteppingAction.hh"

#include "BFieldEveAct.hh"

class BFieldSteAct : public G4UserSteppingAction
{
  public:
	BFieldSteAct(BFieldEveAct* eveAct);
	virtual ~BFieldSteAct();

	virtual void UserSteppingAction(const G4Step*);

  private:
	BFieldEveAct* fEveAct;
};

#endif
