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
#include "TCut.h"

std::string filepath_0 = "testout.root";
std::string filepath_1 = "testout_pu.root";
typedef std::vector<double> doublevector;
typedef std::vector<std::vector<double>> doublevecvec;

doublevector offset(double PU0_grad, double PU0_std, double PU200_grad, double PU200_std, double Pt_gen) {
		/* this function takes in the gradients of both the PU0 and the PU200 cases and returns the offset.
		 * This is preferrable to calcuating the offset for individual events, since it uses the average
		 * assuming y_pu0 = m*x , y_pu200 = m_1*x , y_pu200_corr = m*x+c, this yields c = x_0 *(m_1 - m) with x_0 = Pt_gen
		 */

		double offset = Pt_gen * (PU200_grad - PU0_grad);
		doublevector offset_noerr;

		/* This should be changed to offset_err and the error should be included once calculated */

		offset_noerr.clear();
		offset_noerr.push_back(offset);

		return offset_noerr;
}

doublevector cut_by_R_and_Eta(TTree* tree, string pathname, double radius, double eta, double halfrange = 0.005, double halfetarange = 0.05) {
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

doublevector cut_by_R_and_Eta_compare(TTree* tree_1, TTree* tree_2, string pathname, double radius, double eta, double halfrange = 0.004, double halfetarange = 0.05) {
		double upperLimit = radius + halfrange;
		double lowerLimit = radius - halfrange;

		double upperLimitEta = eta + halfetarange;
		double lowerLimitEta = eta -halfetarange;

		doublevector r_eta_grad_graderr;
		doublevector r_eta_grad_graderr_pu;
		doublevector r_eta_puoffset_offseterr;
		r_eta_puoffset_offseterr.clear();
		r_eta_grad_graderr_pu.clear();
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
		
		/* Case PU0 */

		/* get the right leaf, make the cuts and generate the histogram */

		string com = pathname + " >> h";
		tree_1->Draw(com.c_str(), _condition1 && _condition2 && _etacon1 && _etacon2);
		TH1 *histo = (TH1*)gPad->GetListOfPrimitives()->FindObject("h");

		/* Push back the variables */

		r_eta_grad_graderr.push_back(radius);
		r_eta_grad_graderr.push_back(eta);
		r_eta_grad_graderr.push_back(histo->GetMean());
		r_eta_grad_graderr.push_back(histo->GetStdDev());

		
		/* Case PU200 */

		/* get the right leaf, make the cuts and generate the histogram */

		string com2 = pathname + " >> j";
		tree_2->Draw(com2.c_str(), _condition1 && _condition2 && _etacon1 && _etacon2);
		TH1 *histo_pu = (TH1*)gPad->GetListOfPrimitives()->FindObject("j");

		/* Push back the variables */

		r_eta_grad_graderr_pu.push_back(radius);
		r_eta_grad_graderr_pu.push_back(eta);
		r_eta_grad_graderr_pu.push_back(histo_pu->GetMean());
		r_eta_grad_graderr_pu.push_back(histo_pu->GetStdDev());



		/* calculate offset */

		doublevector offsetvec;
		offsetvec.clear();

		offsetvec = offset( r_eta_grad_graderr.at(2), r_eta_grad_graderr.at(3), r_eta_grad_graderr_pu.at(2), r_eta_grad_graderr_pu.at(3), 25.0);


		doublevector r_eta_offset;
		r_eta_offset.clear();
		r_eta_offset.push_back(radius);
		r_eta_offset.push_back(eta);
		r_eta_offset.push_back(offsetvec.at(0));

		/* return a vector or <radius, eta, gradient, stdDev of gradient> */ 

		return r_eta_offset;
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
				if (bothsides) { _etas.push_back(-1*_eta); }
				_eta += step; // increment step
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
						
doublevector generate_radii(unsigned nR, double incR) {
    doublevector radii;
    for (unsigned i=1; i != nR+1; ++i) {radii.push_back(i*incR);}
    return radii;
}


int main() {
        cout << " MAIN: gradientanalysis.cpp" << endl; 
		/* open input file */
		TFile *file_0 = new TFile(filepath_0.c_str(), "READ");
		TFile *file_1 = new TFile(filepath_1.c_str(), "READ");

		if (file_0->IsOpen()) {	cout << " MAIN: file opened:\t" << filepath_0 << endl; }
		if (file_1->IsOpen()) { cout << " MAIN: file opened:\t" << filepath_1 << endl; }

		/* get the tree from the input file and specify the path of the relevant leaf*/ 
		TTree *tree1 = (TTree*) file_1->Get("tstats");
		TTree *tree = (TTree*) file_0->Get("tstats");
		
        string path = "tc_clusters._pt_reco_gen";

        doublevector _radii = generate_radii(10,0.02);

		/* Define the list of radii and list of etas */
		// radii bins! this is hard-coded and therefore needs to be changed for different input files!
        double radii[10];
        std::copy(_radii.begin(), _radii.end(), radii); 

        //double radii [] = { 0.008, 0.016, 0.024, 0.032, 0.040, 0.048, 0.056, 0.064, 0.072, 0.080};
		// 1000? why? 
        double etas [1000];
		doublevector _etas = genEta(1.65, 2.81, 0.1, false); 
        /* the bool at the end specifies if one or both endcaps should be evaluated. (false is one). 
         * usually better to just do one, since the graph becomes more readable */
		std::copy(_etas.begin(), _etas.end(), etas);

        // print  to see what was generated
        std::cout << " MAIN: _radii:\t";
        printvector(_radii);
        std::cout << " MAIN: _etas:\t";
        printvector(_etas);
	
        // Initialised: this is a vector of vectors which contain (radius, eta, gradient mean, gradient sigma)
		doublevecvec data; 		
        
        /* Loop over the different radii and eta ranges, and extract the data into data */
		for (unsigned i=0; i<sizeof(radii)/sizeof(radii[0]); i++) {
				for (unsigned j=0; j<_etas.size(); j++) {
						double radius = radii[i];
						double eta = etas[j];
						data.push_back(cut_by_R_and_Eta_compare(tree, tree1, path, radius, eta));
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
