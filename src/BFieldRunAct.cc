#include "G4Run.hh"
#include "G4SystemOfUnits.hh"

#include "BFieldRunAct.hh"
#include "BFieldAna.hh"

BFieldRunAct::BFieldRunAct() : G4UserRunAction()
{
	// Create analysis manager
	// The choice of analysis technology is done via selectin of a namespace
	// in BFieldAna.hh
	G4AnalysisManager* AM = G4AnalysisManager::Instance();
	G4cout << "Using " << AM -> GetType() << G4endl;

	// Default settings
	AM -> SetVerboseLevel(0);

	// Creating ntuple
	AM -> CreateNtuple("tree", "data");
	AM -> CreateNtupleIColumn("eventID"); // Column ID = 0
	AM -> CreateNtupleIColumn("trackID"); // Column ID = 1
	AM -> CreateNtupleSColumn("parName"); // Column ID = 2
	AM -> CreateNtupleIColumn("parID");   // Column ID = 3
	AM -> CreateNtupleDColumn("posX");    // Column ID = 4
	AM -> CreateNtupleDColumn("posY");    // Column ID = 5
	AM -> CreateNtupleDColumn("posZ");    // Column ID = 6
	AM -> FinishNtuple();
}

BFieldRunAct::~BFieldRunAct()
{
	delete G4AnalysisManager::Instance();
}

void BFieldRunAct::BeginOfRunAction(const G4Run* /*run*/)
{
	// Inform the runManager to save random number seed
	// G4RunManager::GetRunManager() -> SetRandomNumberStore(true);

	// Get analysis manager
	G4AnalysisManager* AM = G4AnalysisManager::Instance();

	// Open an output file
	// The default file name is set in BFieldRunAct::BFieldRunAct(),
	// it can be overwritten in a macro
	G4String fileName = "output";
	AM -> OpenFile(fileName);
}

void BFieldRunAct::EndOfRunAction(const G4Run* /*run*/)
{
	// Save ntuple
	G4AnalysisManager* AM = G4AnalysisManager::Instance();
	AM -> Write();
	AM -> CloseFile();
}
