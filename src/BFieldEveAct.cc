#include "G4Event.hh"
#include "G4SystemOfUnits.hh"

#include "BFieldEveAct.hh"
#include "BFieldAna.hh"

BFieldEveAct::BFieldEveAct()
{
}

BFieldEveAct::~BFieldEveAct()
{
}

void BFieldEveAct::BeginOfEventAction(const G4Event* /*anEvent*/)
{
	trackID.clear();
	parName.clear();
	parID.clear();
	pos.clear();
}

void BFieldEveAct::EndOfEventAction(const G4Event* anEvent)
{
	// Get analysis manager
	G4AnalysisManager* AM = G4AnalysisManager::Instance();
	G4int eID = anEvent -> GetEventID();

	std::multimap<G4int, G4int>::iterator         itTID;
	std::multimap<G4int, G4String>::iterator      itParName = parName.begin();
	std::multimap<G4int, G4int>::iterator         itParID   = parID.begin();
	std::multimap<G4int, G4ThreeVector>::iterator itPos     = pos.begin();
	for ( itTID = trackID.begin(); itTID != trackID.end(); itTID++ )
	{
		AM -> FillNtupleIColumn(0, eID);
		AM -> FillNtupleIColumn(1, itTID     -> second);
		AM -> FillNtupleSColumn(2, itParName -> second);
		AM -> FillNtupleIColumn(3, itParID   -> second);
		AM -> FillNtupleDColumn(4, (itPos    -> second).x());
		AM -> FillNtupleDColumn(5, (itPos    -> second).y());
		AM -> FillNtupleDColumn(6, (itPos    -> second).z());

		AM -> AddNtupleRow();

		itParName++;
		itParID++;
		itPos++;
	}
}

void BFieldEveAct::SetTrackID(G4int tID)
{
	trackID.insert(std::pair<G4int, G4int>(tID, tID));
}

void BFieldEveAct::SetParName(G4int tID, G4String pN)
{
	parName.insert(std::pair<G4int, G4String>(tID, pN));
}

void BFieldEveAct::SetParID(G4int tID, G4int pID)
{
	parID.insert(std::pair<G4int, G4int>(tID, pID));
}

void BFieldEveAct::SetPos(G4int tID, G4ThreeVector pP)
{
	pos.insert(std::pair<G4int, G4ThreeVector>(tID, pP));
}
