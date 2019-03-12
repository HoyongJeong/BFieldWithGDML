#include "G4ParticleGun.hh"
#include "G4IonTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4Event.hh"	

#include "BFieldPriGenAct.hh"

BFieldPriGenAct::BFieldPriGenAct()
{
	PG = new G4ParticleGun();

	// Gun position
	gunPos = G4ThreeVector(333.0 * mm, 0.0 * mm, 0.0 * mm);
	PG -> SetParticlePosition(gunPos);

	// Set particle definition
	PT = G4ParticleTable::GetParticleTable();
	par = PT -> FindParticle("mu+");
	PG -> SetParticleDefinition(par);

	// Momentum
	momDir = G4ThreeVector(0.0, - 1.0, 0.0);
	PG -> SetParticleMomentumDirection(momDir);
	mom = 300.0 * MeV;
	PG -> SetParticleMomentum(mom);

//	PG -> SetNumberOfParticles(1);
}

BFieldPriGenAct::~BFieldPriGenAct()
{
	delete PG;
}

void BFieldPriGenAct::GeneratePrimaries(G4Event* anEvent)
{
	// If you want several kinds of particle.
/*	G4int i = anEvent -> GetEventID() % 2;
	switch(i)
	{
		case 0:
			par = PT -> FindParticle("mu+");
			break;
		case 1:
//			par = PT -> FindParticle("e-");
			par = PT -> FindParticle("mu+");
			break;
	}
	PG -> SetParticleDefinition(par);
*/
	PG -> GeneratePrimaryVertex(anEvent);
}
