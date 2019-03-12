#ifndef BFIELDDETCON_h
#define BFIELDDETCON_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;
class G4UniformMagField;
class G4UserLimits;

class BFieldDetCon: public G4VUserDetectorConstruction
{
public:
	BFieldDetCon(G4VPhysicalVolume*);
	virtual ~BFieldDetCon();
	virtual G4VPhysicalVolume* Construct();

private:
	G4VPhysicalVolume* world;
	G4UniformMagField* magField;
	G4UserLimits* myLimits;
};

#endif
