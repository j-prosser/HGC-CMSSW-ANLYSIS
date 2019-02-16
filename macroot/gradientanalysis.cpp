#include "stdio.h"
#include "TROOT.h"
#include "TAxis.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TMath.h"
#include "TMultiGraph.h"
#include "TFile.h"
#include "TCanvas.h"
#include <iostream>
#include "TH1F.h"

std::string filepath_0 = "pu0_thres.root";

typedef vector<double> doublevector;
typedef vector<vector<double>> doublevecvec;



doublevector cut_by_R_and_Eta(TTree* tree, string pathname, double radius, double eta, double halfrange = 0.005, double halfetarange = 0.1) {
		double upperLimit = radius + halfrange;
		double lowerLimit = radius - halfrange;

		double upperLimitEta = eta + halfetarange;
		double lowerLimitEta = eta -halfetarange;

		doublevector r_eta_grad_graderr;
		r_eta_grad_graderr.clear();

		/* Set radius conditions */
		string condition = to_string(lowerLimit) + " < _radius";
		string condition2 = "_radius < " + to_string(upperLimit);
		TCut _condition1 = condition.c_str();
		TCut _condition2 = condition2.c_str();

		/* Set eta conditions */

		string etacon = to_string(lowerLimitEta) + " < _eta";
		string etacon2 = "_eta < " + to_string(upperLimitEta);
		TCut _etacon1 = etacon.c_str();
		TCut _etacon2 = etacon2.c_str();


		//TCanvas *c = new TCanvas(condition.c_str(), condition.c_str(), 600, 600);
		

		/* get the right leaf, make the cuts and generate the histogram */

		string com = pathname + " >> h";
		tree->Draw(com.c_str(), _condition1 && _condition2 && _etacon1 && _etacon2);
		TH1 *histo = (TH1*)gPad->GetListOfPrimitives()->FindObject("h");

		/* Push back the variables */

		r_eta_grad_graderr.push_back(radius);
		r_eta_grad_graderr.push_back(eta);
		r_eta_grad_graderr.push_back(histo->GetMean());
		r_eta_grad_graderr.push_back(histo->GetStdDev());

		/* return a vector or <radius, eta, gradient, stdDev of gradient> */ 

		return r_eta_grad_graderr;
}

doublevector genEta(double start, double stop, double step, bool bothsides) {
		int n = (stop-start)/step;
		if (bothsides) {
				n = 2*n;
		}
		doublevector _etas;
		_etas.clear();

		double _eta = start;
		
		while (_eta <=stop) {
				_etas.push_back(_eta);
				if (bothsides) {
						_etas.push_back(-1*_eta);
				}
				_eta += step;
		}

		return _etas;
}	

void printvector(vector<double> v) {
		/* for debugging */
		for (unsigned i=0; i<v.size(); i++) {
				cout << v[i] << " ";
		}
		cout << endl;
}

void printvv(vector<vector<double>> vv) {
		/* for debugging */
		for (unsigned i=0; i<vv.size(); i++) {
				printvector(vv[i]);
		}
}
						

int main() {

		/* open input file */
		TFile *file_0 = new TFile(filepath_0.c_str(), "READ");

		if (file_0->IsOpen()) {
				cout << "file opened" << endl;
		}

		/* get the tree from the input file and specify the path of the relevant leaf*/ 
		TTree *tree = (TTree*) file_0->Get("tstats");

		string path = "tc_clusters._pt_reco_gen";

		/* Define the list of radii and list of etas */

		double radii [] = {.02, .04, .06, .08, .10, .12, .14, .16, .18, .20};
		double etas [1000];
		doublevector _etas = genEta(1.6, 2.81, 0.2, false); //the bool at the end specifies if one or both endcaps should be evaluated. (false is one). usually better to just do one, since the graph becomes more readable
		std::copy(_etas.begin(), _etas.end(), etas);

	
		doublevecvec data; //this is a vector of vectors which contain (radius, eta, gradient mean, gradient sigma)

		/* Loop over the different radii and eta ranges, and extract the data into data */

		for (unsigned i=0; i<sizeof(radii)/sizeof(radii[0]); i++) {
				for (unsigned j=0; j<_etas.size(); j++) {
						double radius = radii[i];
						double eta = etas[j];
						data.push_back(cut_by_R_and_Eta(tree, path, radius, eta));
				}
		}


		// printvv(data); //for debugging uncomment this line
		
		/* generate 2 dimensional graph of gradients vs radius vs eta. I don't know how to include the error on the grdient in this */

		TGraph2D *g2 = new TGraph2D(data.size());
		for (unsigned i=0; i< data.size(); i++) {
				g2->SetPoint(i, data[i][0], data[i][1], data[i][2]);
		}

		/* Draw the graph. I should add axis labels and a title here. */
		TCanvas *c = new TCanvas("x", "x", 600, 600);
		g2->Draw("TRI"); //empty draws a scatter plot, "TRI" draws a surface using triangles.



}
