#ifndef BFIELDPRIGENACT_h
#define BFIELDPRIGENACT_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"
#include "globals.hh"
#include "G4ParticleDefinition.hh"

class G4ParticleGun;

class BFieldPriGenAct: public G4VUserPrimaryGeneratorAction
{
  private:
	G4ParticleGun* PG;
	G4ParticleTable* PT;

  public:
	BFieldPriGenAct();
	~BFieldPriGenAct();

	virtual void GeneratePrimaries(G4Event* anEvent);

  private:
	G4ThreeVector gunPos;
	G4ParticleDefinition* par;
	G4ThreeVector momDir;
	G4double mom;
};

#endif
