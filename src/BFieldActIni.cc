#include "BFieldActIni.hh"
#include "BFieldPriGenAct.hh"
#include "BFieldRunAct.hh"
#include "BFieldEveAct.hh"
#include "BFieldSteAct.hh"

BFieldActIni::BFieldActIni() : G4VUserActionInitialization()
{
}

BFieldActIni::~BFieldActIni()
{
}

void BFieldActIni::BuildForMaster() const
{
	SetUserAction(new BFieldRunAct);
}

void BFieldActIni::Build() const
{
	SetUserAction(new BFieldPriGenAct);
	SetUserAction(new BFieldRunAct);

	BFieldEveAct* BFieldEA = new BFieldEveAct;
	SetUserAction(BFieldEA);

	SetUserAction(new BFieldSteAct(BFieldEA));
}  
