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
#include "../inc/ResolutionStats.h"
#include "TTreeReader.h"
#include "TTreeReaderArray.h"

std::string filepath_0 = "testout.root";
std::string filepath_1 = "testout_pu.root";
typedef std::vector<float> floatvector;
typedef std::vector<std::vector<float>> floatvecvec;

void printvector(floatvector v) {
		/* for debugging */
		for (unsigned i=0; i<v.size(); i++) {
				std::cout << v[i] << " ";
		}
		std::cout << std::endl;
}


floatvector offset(float PU0_grad, float PU0_std, float PU200_grad, float PU200_std, float Pt_gen) {
		/* this function takes in the gradients of both the PU0 and the PU200 cases and returns the offset.
		 * This is preferrable to calcuating the offset for individual events, since it uses the average
		 * assuming y_pu0 = m*x , y_pu200 = m_1*x , y_pu200_corr = m*x+c, this yields c = x_0 *(m_1 - m) with x_0 = Pt_gen
		 */

		float offset = Pt_gen * (PU200_grad - PU0_grad);
		floatvector offset_noerr;

		/* This should be changed to offset_err and the error should be included once calculated */

		offset_noerr.clear();
		offset_noerr.push_back(offset);

		return offset_noerr;
}

floatvector cut_by_R_and_Eta(TTree* tree, std::string pathname, float radius, float eta, float halfrange = 0.005, float halfetarange = 0.05) {
		float upperLimit = radius + halfrange;
		float lowerLimit = radius - halfrange;

		float upperLimitEta = eta + halfetarange;
		float lowerLimitEta = eta -halfetarange;

		floatvector r_eta_grad_graderr;
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
floatvector cut_by_R_and_Eta_compare(TTree* tree_1, TTree* tree_2, std::string pathname, float radius, float eta, float halfrange = 0.004, float halfetarange = 0.05) {
		
    
        float upperLimit = radius + halfrange;
		float lowerLimit = radius - halfrange;

		float upperLimitEta = eta + halfetarange;
		float lowerLimitEta = eta - halfetarange;

        std::cout << " COMPARE: radius, eta bins:\t" << lowerLimit << "/" << upperLimit 
            << ",\t" << lowerLimitEta << "/" << upperLimitEta << std::endl;
		
        floatvector r_eta_grad_graderr;
		floatvector r_eta_grad_graderr_pu;
		floatvector r_eta_puoffset_offseterr;
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

		floatvector offsetvec;
		offsetvec.clear();

		offsetvec = offset( r_eta_grad_graderr.at(2), r_eta_grad_graderr.at(3), r_eta_grad_graderr_pu.at(2), r_eta_grad_graderr_pu.at(3), 25.0);

        // Discard points on R,eta plane if not enough values to generate a gradient 
        if (r_eta_grad_graderr.at(2) == 0. || r_eta_grad_graderr_pu.at(2) ==0.) {
            offsetvec.at(0) = 0.;
        }

		floatvector r_eta_offset;
		r_eta_offset.clear();
		r_eta_offset.push_back(radius);
		r_eta_offset.push_back(eta);
		r_eta_offset.push_back(offsetvec.at(0));

		/* return a vector or <radius, eta, gradient, stdDev of gradient> */ 

		return r_eta_offset;
}

floatvector genEta(float start, float stop, float step, bool bothsides) {
		int n = (stop-start)/step;
		if (bothsides) {
				n = 2*n;
		}
		floatvector _etas;
		_etas.clear();

		float _eta = start;
		
		while (_eta <=stop) {
				_etas.push_back(_eta);
				if (bothsides) { _etas.push_back(-1*_eta); }
				_eta += step; // increment step
		}

		return _etas;
}	
void printvv(std::vector<std::vector<float>> vv) {
		/* for debugging */
		for (unsigned i=0; i<vv.size(); i++) {
				printvector(vv[i]);
		}
}
						
floatvector generate_radii(unsigned nR, float incR) {
    floatvector radii;
    for (unsigned i=1; i != nR+1; ++i) {radii.push_back(i*incR);}
    return radii;
}

floatvecvec compare_pu_effects(TTree* tree_0, TTree* tree_pu,const floatvector& radii, const floatvector& etas, const std::vector<TCut>& cuts_r,const std::vector<TCut>& cuts_eta, std::string path, float gen_pt) {
    floatvecvec _output; 
    
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
            std::string comm0 = path + " >> "+ histname0;

            tree_0->Draw(comm0.c_str(),all_cuts);
            TH1 *histotmp0 = (TH1*)gPad->GetListOfPrimitives()->FindObject(histname0.c_str());  
            hists1.push_back(histotmp0);
            h_count +=1;

                
            // file1
            std::string histname1 = "1file" + std::to_string(i) + std::to_string(j);
            std::string comm1 = path + " >> "+ histname1;

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
                floatvector offset_vec = offset(histotmp0->GetMean(), histotmp0->GetStdDev(), histotmp1->GetMean(), histotmp0->GetStdDev(), gen_pt);
                floatvector tmpout;
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

void resolution_width(TTree* tree_0, TTree* tree_pu,const floatvector& radii, const floatvector& etas, const std::vector<TCut>& cuts_r,const std::vector<TCut>& cuts_eta, std::string path, float gen_pt) {
    floatvecvec _output; 
    
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

            // file0 : zero pu
            std::string histname0 = "0file" + std::to_string(i) + std::to_string(j);
            std::string pt_reco_gen_path_0 = path + "_pt_reco_gen" + " >> "+ histname0;

            tree_0->Draw(pt_reco_gen_path_0.c_str(),all_cuts);
            TH1 *histotmp0 = (TH1*)gPad->GetListOfPrimitives()->FindObject(histname0.c_str());  
            hists1.push_back(histotmp0);
            h_count +=1;
                
            // file1
            std::string histname1 = "1file" + std::to_string(i) + std::to_string(j);
            std::string pt_reco_gen_path_200 = path + "_pt_reco_gen" + " >> "+ histname1;

            tree_pu->Draw(pt_reco_gen_path_200.c_str(),all_cuts);
            TH1 *histotmp1 = (TH1*)gPad->GetListOfPrimitives()->FindObject(histname1.c_str());  
            hists1.push_back(histotmp1);
            h_count +=1; 

            /*offset calcs + decisions*/

            // if either mean is zero, discard!
            if (histotmp0->GetMean() == 0. || histotmp1->GetMean() == 0.  ) {
                 std::cout << " OFFSETCAlC:\tRadius/Eta"<< radii[i]<<"/"<<etas[j] <<"\tDISCARD\n";
            } else {
                // now we can do something!
                floatvector offset_vec = offset(histotmp0->GetMean(), histotmp0->GetStdDev(), histotmp1->GetMean(), histotmp0->GetStdDev(), gen_pt);
                floatvector tmpout;
                tmpout.push_back(radii[i]);
                tmpout.push_back(etas[j]);
                tmpout.push_back(offset_vec[0]);
                _output.push_back(tmpout);         
                //std::cout << "\t\t" << offset_vec[0]<< std::endl;
            }


        // End of eta /R loops
        }}
    
}
void plot_pu_offset(const floatvecvec& pu_offset_results){
		/* generate 2 dimensional graph of gradients vs radius vs eta. I don't know how to include the error on the grdient in this 
         * -> Needs Axis labels, title Etc. 
         *  */
		TGraph2D *g2 = new TGraph2D(pu_offset_results.size());
		for (unsigned i=0; i< pu_offset_results.size(); i++) {
            if (pu_offset_results[i][2] !=0.){ g2->SetPoint(i, pu_offset_results[i][0], pu_offset_results[i][1], pu_offset_results[i][2]);}
		}
		/* Draw the graph. I should add axis labels and a title here. */
		TCanvas *c = new TCanvas("x", "x", 600, 600);
		g2->Draw("TRI"); //empty draws a scatter plot, "TRI" draws a surface using triangles.
}

int get_eta_index(float test_eta, const std::vector<float>& etas, float eta_inc){
    int idx =-1;

    unsigned check_idx =0;
    while (idx == -1 && check_idx != etas.size()) {
        
        if (std::abs(test_eta) > etas[check_idx]-eta_inc/2. && std::abs(test_eta) < etas[check_idx] + eta_inc/2.){
            idx = check_idx;
        }

        //increment
        ++check_idx;
    }

    return idx;
}

void resolution_corrected(const floatvecvec& pu_offsets, TFile* f, std::string path, const std::vector<float> radii, const std::vector<float> etas, double eta_inc ){
    // obtain corrected resolution given the PU offsets
    
    TTreeReader reader("tstats", f);
    std::string reco_path = path + "_pt_reco";
    std::string gen_path = path + "_pt_gen";     
    std::string r_path = path + "_radius";    
    std::string eta_path = path + "_eta";    
    TTreeReaderArray<float> raPtReco(reader, reco_path.c_str());   
    TTreeReaderArray<float> raPtGen(reader, gen_path.c_str());
    TTreeReaderArray<float> raR(reader, r_path.c_str());
    TTreeReaderArray<float> raEta(reader, eta_path.c_str());


    
    // need to obtain a eta index from etas for each ...
    
    // need to try to see if we can equate radii (?) 
    // while loop: LOOPS OVER ETA's
    while (reader.Next()) {
        //std::cout << " RC: ra sizes " << raPtReco.GetSize() << " " << raPtGen.GetSize() <<" "<< raR.GetSize()<< " "<< raEta.GetSize() <<  std::endl;
        auto itPtReco = raPtReco.begin();
        auto itPtGen = raPtGen.begin();
        auto itR = raR.begin();
        auto itEta = raEta.begin();

        while (itPtReco != raPtReco.end() && itPtGen != raPtGen.end() && itR != raR.end() && itEta != raEta.end() ) {
        
            //std::cout << " RC: DEBUG: " << get_eta_index( *itEta, etas,eta_inc) << "\t" << *itEta << std::endl;
            
            //increment step
            ++itPtReco; ++itPtGen; ++itR; ++itEta;
        }
        
        
        //Loop over radii
        for (float test: raR) { 
            //std::cout << " RC: DEBUG: test " << test << std::endl;
        }

    }
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

        std::cout << " MAIN: DEBUG:\t" << tree1->GetEntries() << std::endl;

        // gen_pt! hard coded!
        float gen_pt = 25.0; 

		/* Define the list of radii and list of etas */
        // Hard coded variables :(
        float radius_inc = 0.02;
        unsigned radius_n = 10; 
        floatvector _radii = generate_radii(radius_n,radius_inc);
        
        // Define eta
        float eta_inc = 0.2;
		floatvector _etas = genEta(1.65, 2.81, eta_inc, false); 
        /* the bool at the end specifies if one or both endcaps should be evaluated. (false is one). 
         * usually better to just do one, since the graph becomes more readable */

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
  
        // Find PU offset for given cuts in R and Eta
        floatvecvec offsetoutput =  compare_pu_effects(tree0,tree1,_radii,_etas,cuts_r, cuts_eta, path, gen_pt);
        std::cout <<" MAIN: size of offsetoutput vector:\t" << offsetoutput.size() << std::endl; 
        std::cout <<" MAIN: expected size of offsetoutput:\t" << _radii.size() * _etas.size() << std::endl;
        //printvv(offsetoutput); //for debugging uncomment this line
		
        // plot pu offset results
        plot_pu_offset(offsetoutput);
        
        std::string base_path = "tc_clusters.";

        resolution_width(tree0, tree1, _radii, _etas, cuts_r, cuts_eta, base_path, gen_pt);

        //std::string pt_reco_path = "tc_clusters.";
        //resolution_corrected(offsetoutput,file_1,pt_reco_path, _radii, _etas, eta_inc);
        

}
