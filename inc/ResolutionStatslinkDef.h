#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclasses;


#pragma link C++ class std::vector<unsigned>+;
#pragma link C++ class std::vector<vector<unsigned int> >;
#pragma link C++ class ResolutionStats+;
#pragma link C++ class std::vector<ResolutionStats>+;
#pragma link C++ class std::vector<ResolutionStats*>+;
#pragma link C++ class std::map<unsigned int,ResolutionStats>+;


//#pragma link C++ class ResolutionStats+; 
//#pragma link C++ class std::map<unsigned,ResolutionStats>+;
//#pragma link C++ class std::map<int,ResolutionStats>+;


#endif
