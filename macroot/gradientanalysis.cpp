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
#include "TTree.h"
#include "TString.h"

std::string filepath_0 = "testout.root";
std::string filepath_1 = "testout_pu.root";
typedef std::vector<double> doublevector;
typedef std::vector<std::vector<double>> doublevecvec;

void printvector(doublevector v) {
		/* for debugging */
		for (unsigned i=0; i<v.size(); i++) {
				std::cout << v[i] << " ";
		}
		std::cout << std::endl;
}


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

doublevector cut_by_R_and_Eta(TTree* tree, std::string pathname, double radius, double eta, double halfrange = 0.005, double halfetarange = 0.05) {
		double upperLimit = radius + halfrange;
		double lowerLimit = radius - halfrange;

		double upperLimitEta = eta + halfetarange;
		double lowerLimitEta = eta -halfetarange;

		doublevector r_eta_grad_graderr;
		r_eta_grad_graderr.clear();

		/* Set radius conditions */
        std::string condition = std::to_string(lowerLimit) + " < _radius";
        std::string condition2 = "_radius < " + std::to_string(upperLimit);
		TCut _condition1 = condition.c_str();
		TCut _condition2 = condition2.c_str();

		/* Set eta conditions */

		std::string etacon = std::to_string(lowerLimitEta) + " < _eta";
		std::string etacon2 = "_eta < " + std::to_string(upperLimitEta);
		TCut _etacon1 = etacon.c_str();
		TCut _etacon2 = etacon2.c_str();


		//TCanvas *c = new TCanvas(condition.c_str(), condition.c_str(), 600, 600);
		

		/* get the right leaf, make the cuts and generate the histogram */

		std::string com = pathname + " >> h";
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

/*generates pu offset*/
doublevector cut_by_R_and_Eta_compare(TTree* tree_1, TTree* tree_2, std::string pathname, double radius, double eta, double halfrange = 0.004, double halfetarange = 0.05) {
		
    
        double upperLimit = radius + halfrange;
		double lowerLimit = radius - halfrange;

		double upperLimitEta = eta + halfetarange;
		double lowerLimitEta = eta - halfetarange;

        std::cout << " COMPARE: radius, eta bins:\t" << lowerLimit << "/" << upperLimit 
            << ",\t" << lowerLimitEta << "/" << upperLimitEta << std::endl;
		
        doublevector r_eta_grad_graderr;
		doublevector r_eta_grad_graderr_pu;
		doublevector r_eta_puoffset_offseterr;
		r_eta_puoffset_offseterr.clear();
		r_eta_grad_graderr_pu.clear();
		r_eta_grad_graderr.clear();

		/* Set radius conditions */
		std::string condition = std::to_string(lowerLimit) + " < _radius";
		std::string condition2 = "_radius < " + std::to_string(upperLimit);
		TCut _condition1 = condition.c_str();
		TCut _condition2 = condition2.c_str();

		/* Set eta conditions */

		std::string etacon = std::to_string(lowerLimitEta) + " < _eta";
		std::string etacon2 = "abs(_eta) < " + std::to_string(upperLimitEta);
		TCut _etacon1 = etacon.c_str();
		TCut _etacon2 = etacon2.c_str();

        //std::cout << " COMPARE: cut conditions radius, eta:\t" << condition << "/" << condition2 << "\t" << etacon << "/"<< etacon2 << std::endl;

		//TCanvas *c = new TCanvas(condition.c_str(), condition.c_str(), 600, 600);
		
		/* Case PU0 */

		/* get the right leaf, make the cuts and generate the histogram */

		std::string com = pathname + " >> h";
		tree_1->Draw(com.c_str(), _condition1 && _condition2 && _etacon1 && _etacon2);
		TH1 *histo = (TH1*)gPad->GetListOfPrimitives()->FindObject("h");

		/* Push back the variables */

		r_eta_grad_graderr.push_back(radius);
		r_eta_grad_graderr.push_back(eta);
		r_eta_grad_graderr.push_back(histo->GetMean());
		r_eta_grad_graderr.push_back(histo->GetStdDev());

		
		/* Case PU200 */

		/* get the right leaf, make the cuts and generate the histogram */

		std::string com2 = pathname + " >> j";
		tree_2->Draw(com2.c_str(), _condition1 && _condition2 && _etacon1 && _etacon2);
		TH1 *histo_pu = (TH1*)gPad->GetListOfPrimitives()->FindObject("j");

		/* Push back the variables */

		r_eta_grad_graderr_pu.push_back(radius);
		r_eta_grad_graderr_pu.push_back(eta);
		r_eta_grad_graderr_pu.push_back(histo_pu->GetMean());
		r_eta_grad_graderr_pu.push_back(histo_pu->GetStdDev());

        //Debug
        std::cout << " COMPARE:\t"; 
        printvector(r_eta_grad_graderr_pu); 


		/* calculate offset */

		doublevector offsetvec;
		offsetvec.clear();

		offsetvec = offset( r_eta_grad_graderr.at(2), r_eta_grad_graderr.at(3), r_eta_grad_graderr_pu.at(2), r_eta_grad_graderr_pu.at(3), 25.0);

        // Discard points on R,eta plane if not enough values to generate a gradient 
        if (r_eta_grad_graderr.at(2) == 0. || r_eta_grad_graderr_pu.at(2) ==0.) {
            offsetvec.at(0) = 0.;
        }

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
void printvv(std::vector<std::vector<double>> vv) {
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

doublevecvec compare_pu_effects(TTree* tree_0, TTree* tree_pu,const doublevector& radii, const doublevector& etas, const std::vector<TCut>& cuts_r,const std::vector<TCut>& cuts_eta) {
    doublevecvec _output; 
    
    // init hists
    std::vector< TH1* > hists0;
    std::vector< TH1* > hists1;
    //Create a canvas
    TCanvas *c_all = new TCanvas("c","");
    c_all->DivideSquare(2*etas.size()*radii.size()); 
    unsigned h_count =1;

    for (unsigned i=0; i<radii.size(); ++i) {
        for (unsigned j=0; j<etas.size(); ++j){

            c_all->cd(h_count);
            TCut all_cuts = cuts_r[i] && cuts_eta[j];

            // file0
            std::string histname0 = "0file" + std::to_string(i) + std::to_string(j);
            std::string comm0 = "tc_clusters._pt_reco_gen >> "+ histname0;

            tree_0->Draw(comm0.c_str(),all_cuts);
            TH1 *histotmp0 = (TH1*)gPad->GetListOfPrimitives()->FindObject(histname0.c_str());  
            hists1.push_back(histotmp0);
            h_count +=1;

                
            // file1
            std::string histname1 = "1file" + std::to_string(i) + std::to_string(j);
            std::string comm1 = "tc_clusters._pt_reco_gen >> "+ histname1;

            tree_pu->Draw(comm1.c_str(),all_cuts);
            TH1 *histotmp1 = (TH1*)gPad->GetListOfPrimitives()->FindObject(histname1.c_str());  
            hists1.push_back(histotmp1);
            h_count +=1; 

            /*offset calcs + decisions*/

            // if either mean is zero, discard!
            if (histotmp0->GetMean() == 0. || histotmp1->GetMean() == 0.  ) {
                 std::cout << " OFFSETCAlC:\tRadius/Eta"<< radii[i]<<"/"<<etas[j] <<"\tDISCARD\n";
            } else {
                // now we can do something!
                doublevector offset_vec = offset(histotmp0->GetMean(), histotmp0->GetStdDev(), histotmp1->GetMean(), histotmp0->GetStdDev(), 25.0);
                doublevector tmpout;
                tmpout.push_back(radii[i]);
                tmpout.push_back(etas[j]);
                tmpout.push_back(offset_vec[0]);
                _output.push_back(tmpout);         
                //std::cout << "\t\t" << offset_vec[0]<< std::endl;
            }


        // End of eta /R loops
        }}
    
    return _output;
}


int main() {
        std::cout << " MAIN: gradientanalysis.cpp" << std::endl; 
		/* open input file */
		TFile *file_0 = new TFile(filepath_0.c_str(), "READ");
		TFile *file_1 = new TFile(filepath_1.c_str(), "READ");

		if (file_0->IsOpen()) {	std::cout << " MAIN: file opened:\t" << filepath_0 << std::endl; }
		if (file_1->IsOpen()) { std::cout << " MAIN: file opened:\t" << filepath_1 << std::endl; }

		/* get the tree from the input file and specify the path of the relevant leaf*/ 
		TTree *tree1 = (TTree*) file_1->Get("tstats");
		TTree *tree0 = (TTree*) file_0->Get("tstats");
		
        std::string path = "tc_clusters._pt_reco_gen";
        TString tpath = "tc_clusters._pt_reco_gen";

		/* Define the list of radii and list of etas */
        // Hard coded variables :(
        double radius_inc = 0.02;
        unsigned radius_n = 10; 
        doublevector _radii = generate_radii(radius_n,radius_inc);
        double radii[10];
        std::copy(_radii.begin(), _radii.end(), radii); 

        //double radii [] = { 0.008, 0.016, 0.024, 0.032, 0.040, 0.048, 0.056, 0.064, 0.072, 0.080};
		// 1000? why? 
        double etas [1000];
        double eta_inc = 0.2;
		doublevector _etas = genEta(1.65, 2.81, eta_inc, false); 
        /* the bool at the end specifies if one or both endcaps should be evaluated. (false is one). 
         * usually better to just do one, since the graph becomes more readable */
		std::copy(_etas.begin(), _etas.end(), etas);

        // print  to see what was generated
        std::cout << " MAIN: _radii:\t";
        printvector(_radii);
        std::cout << " MAIN: _etas:\t";
        printvector(_etas);
	
        // Generate vectors of TCuts
        std::vector<TCut> cuts_r;
        for (unsigned i=0; i<radius_n; ++i){
            std::string tmp1= "_radius > " + std::to_string(_radii[i]-radius_inc/2.);
            std::string tmp2= "_radius < " + std::to_string(_radii[i]+ (radius_inc/2.));         
            TCut tmpcut1 = tmp1.c_str();
            TCut tmpcut2 = tmp2.c_str();
            //std::cout << tmp1 << tmp2<<std::endl;
            cuts_r.push_back( tmpcut1 && tmpcut2 );
        }
        std::vector<TCut> cuts_eta; 
        for (unsigned j=0; j<_etas.size(); ++j){
            std::string tmp1= "abs(_eta) > " + std::to_string(_etas[j]-eta_inc/2.);
            std::string tmp2= "abs(_eta) < "+std::to_string( _etas[j] + (eta_inc/2.));         
            TCut tmpcut1 = tmp1.c_str();
            TCut tmpcut2 = tmp2.c_str();
            //std::cout << tmp1 << tmp2<<std::endl;
            cuts_eta.push_back( tmpcut1 && tmpcut2 );
        }
  
        

        // output data
        doublevecvec offsetoutput =  compare_pu_effects(tree0,tree1,_radii,_etas,cuts_r, cuts_eta);
        //hists.push_back(new TH1D(Form("h%d",i),Form("Hist %d",i), 100, 0, 2));
        //tree->Draw(Form("x>>h%d", i), cuts.at(i));
           
        // Initialised: this is a vector of vectors which contain (radius, eta, gradient mean, gradient sigma)

        std::cout <<" MAIN: size of offsetoutput vector:\t" << offsetoutput.size() << std::endl; 
        std::cout <<" MAIN: expected size of offsetoutput:\t" << _radii.size() * _etas.size() << std::endl;
        //printvv(offsetoutput); //for debugging uncomment this line
		
		/* generate 2 dimensional graph of gradients vs radius vs eta. I don't know how to include the error on the grdient in this */

		TGraph2D *g2 = new TGraph2D(offsetoutput.size());
		for (unsigned i=0; i< offsetoutput.size(); i++) {
            if (offsetoutput[i][2] !=0.){ g2->SetPoint(i, offsetoutput[i][0], offsetoutput[i][1], offsetoutput[i][2]);}
		}

		/* Draw the graph. I should add axis labels and a title here. */
		TCanvas *c = new TCanvas("x", "x", 600, 600);
		g2->Draw("TRI"); //empty draws a scatter plot, "TRI" draws a surface using triangles.



}
