#include "TGraphErrors.h"
#include "TGraph.h"
#include "TFile.h"
#include <string>

string filepath_1 = "stc_save1.root";
string filepath_2 = "e_weight_save1.root";
string filepath_3 = "tc_save1.root";

TGraphErrors* getGraph(TFile* file, string name) {
		TGraphErrors *tge = (TGraphErrors*) file->Get(name.c_str());
		cout << tge->GetN();
		return tge;
}

int overlay() {
		TFile *file1 = new TFile(filepath_1.c_str(), "READ");
		TFile *file2 = new TFile(filepath_2.c_str(), "READ");
		TFile *file3 = new TFile(filepath_3.c_str(), "READ");

		TCanvas *c = new TCanvas("c", "c", 700, 700);
		c->SetGrid();

		TMultiGraph *mg = new TMultiGraph();
		
		TGraphErrors *tge1 = getGraph(file1, "Graph;1");
		tge1->SetTitle("STC");
		tge1->SetMarkerColor(1);
		tge1->SetLineColor(1);

		TGraphErrors *tge2 = getGraph(file2, "Graph;1");
		tge2->SetTitle("EnergyWeighted");
		tge2->SetMarkerColor(3);
		tge2->SetLineColor(3);

		TGraphErrors *tge3 = getGraph(file3, "Graph;1");
		tge3->SetTitle("TCs");
		tge3->SetMarkerColor(15);
		tge3->SetLineColor(15);

		mg->Add(tge1);
		mg->Add(tge2);
		mg->Add(tge3);

		mg->GetXaxis()->SetTitle("Eta");
		mg->GetYaxis()->SetTitle("Minimal error");
		mg->Draw("ac*");
		c->BuildLegend(.9, .21, .9, .21);
		c->Update();
		return 0;
}



