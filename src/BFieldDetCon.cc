#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4UniformMagField.hh"
#include "G4FieldManager.hh"
#include "G4ChordFinder.hh"
#include "G4UserLimits.hh"

#include "BFieldDetCon.hh"

BFieldDetCon::BFieldDetCon(G4VPhysicalVolume* setWorld = 0)
{
	world = setWorld;
}

BFieldDetCon::~BFieldDetCon()
{
}

G4VPhysicalVolume* BFieldDetCon::Construct()
{
	// Apply uniform mgnetic field in our world
	magField = new G4UniformMagField(G4ThreeVector(0.0, 0.0, 3.0 * tesla));
	G4FieldManager* fieldMgr = new G4FieldManager(magField);
	world -> GetLogicalVolume() -> SetFieldManager(fieldMgr, true);

	return world;
}
