// #ifdef G4MULTITHREADED
// #include "G4MTRunManager.hh"
// #else
#include "G4RunManager.hh"
// #endif

#include "G4UIterminal.hh"
#include "G4UItcsh.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "Randomize.hh"
#include "G4GDMLParser.hh"

#include "QGSP_BERT.hh"
#include "FTFP_BERT.hh"

#include "BFieldActIni.hh"
#include "BFieldDetCon.hh"
#include "BFieldPriGenAct.hh"

int main(int argc, char** argv)
{
	// Message
	G4cout << G4endl;
	G4cout << "Usage: BField <intput_gdml_file:mandatory>"
	       << " <macro:optional>" << G4endl;
	G4cout << G4endl;

	// Error when no argument
	if ( argc < 2 )
	{
		G4cout << "Error! Mandatory input file is not specified!" << G4endl;
		G4cout << G4endl;
		return -1; 
	}

	// Error when too many arguments
	if ( argc > 3 )
	{
		G4cout << "Error! Too many arguments!" << G4endl;
		G4cout << G4endl;
		return -1; 
	}

	// Randomizer
	CLHEP::RanluxEngine defaultEngine(1234567, 4);
	G4Random::setTheEngine(&defaultEngine);
	G4int seed = time(NULL);
	G4Random::setTheSeed(seed);

	// Parse GDML file
	G4GDMLParser parser;
	parser.Read(argv[1]);

	// Run manager
//	#ifdef G4MULTITHREADED
//	G4MTRunManager* RM = new G4MTRunManager();
//	RM -> SetNumberOfThreads(5);
//	#else
	G4RunManager* RM = new G4RunManager();
//	#endif

	// Detector construction
	BFieldDetCon* BFDC = new BFieldDetCon(parser.GetWorldVolume());
	RM -> SetUserInitialization(BFDC);

	// Physics list
//	G4VModularPhysicsList* PL = new QGSP_BERT;
	G4VModularPhysicsList* PL = new FTFP_BERT;
	PL -> SetVerboseLevel(0);
	RM -> SetUserInitialization(PL);

	// User actions
	RM -> SetUserInitialization(new BFieldActIni());

	//	Initialize
	RM -> Initialize();

	// Visualization manager
	G4VisManager* VM = new G4VisExecutive();
	VM -> Initialize();

	if ( argc == 2 )
	{
		G4UIsession* session = new G4UIterminal (new G4UItcsh);
		session -> SessionStart();

		delete session;
	}

	else if ( argc == 3 )
	{
		G4String command = "/control/execute ";
		G4String fileName = argv[2];
		G4UImanager* UI = G4UImanager::GetUIpointer();
		UI -> ApplyCommand(command + fileName);
		G4UIExecutive* session = new G4UIExecutive(argc, argv);
		session->SessionStart();

		delete session;
	}

	delete RM;

	return 0;
}
