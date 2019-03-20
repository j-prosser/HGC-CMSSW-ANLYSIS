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
#include "TGraphErrors.h"

/*yoyo@dyn3162-24:~/Documents/Project/dev/HGC-CMSSW-ANLYSIS$ ls data/loge/
energy_weight_pu0_200.root         energy_weight_pu200_s200_200.root  energy_weight_pu200_s600_200.root
energy_weight_pu200_s0_200.root    energy_weight_pu200_s400_200.root*/

/*std::string filepath_0 = "data/energy_weight_s019/energy_weight_pu0_200.root";
std::string filepath_1 = "data/energy_weight_s019/energy_weight_pu200_s0_200.root";
std::string filepath_2 = "data/energy_weight_s019/energy_weight_pu200_s200_200.root";
std::string filepath_3 = "data/energy_weight_s019/energy_weight_pu200_s400_200.root";
std::string filepath_4 = "data/energy_weight_s019/energy_weight_pu200_s600_200.root";*/
/*
std::string filepath_0 = "data/inve/energy_weight_pu0_200.root";
std::string filepath_1 = "data/inve/energy_weight_pu200_s0_200.root";
std::string filepath_2 = "data/inve/energy_weight_pu200_s200_200.root";
std::string filepath_3 = "data/inve/energy_weight_pu200_s400_200.root";
std::string filepath_4 = "data/inve/energy_weight_pu200_s600_200.root";
*/
std::string filepath_0 = "data/tc/pu0_200.root";
std::string filepath_1 = "data/tc/pu200_s0_200.root";
std::string filepath_2 = "data/tc/pu200_s200_200.root";
std::string filepath_3 = "data/tc/pu200_s400_200.root";
std::string filepath_4 = "data/tc/pu200_s600_200.root";


std::string filepath_out = "_saves/current_save_tc.root";
typedef std::vector<float> floatvector;
typedef std::vector<std::vector<float>> floatvecvec;
typedef std::vector<std::vector<std::vector<float>>> floatvecvecvec;


void printvector(floatvector v) {
		/* for debugging */
        std::cout << " Print vector size: "<<v.size() << "\t";
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
			TCut zerocorrection = "_pt_reco_gen >0.1";
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

            tree_pu->Draw(comm1.c_str());
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
                tmpout.push_back(offset_vec[0]); //offset_vec returns only the PU offset at index 0
                _output.push_back(tmpout);
                //std::cout << "\t\t" << offset_vec[0]<< std::endl;
            }


        // End of eta /R loops
        }}

    return _output;
}

floatvecvecvec resolution_width(TTree* tree_0, TTree* tree_pu,const floatvector& radii, const floatvector& etas, const std::vector<TCut>& cuts_r,const std::vector<TCut>& cuts_eta, std::string path, float gen_pt) {
    floatvecvec _output;

    // init hists
    std::vector< TH1* > h_pt_reco_gen_0;
    std::vector< TH1* > h_pt_reco_gen_pu;
    //Create a canvas
    TCanvas *c_all = new TCanvas("c","");
    c_all->DivideSquare(4*etas.size()*radii.size());
    unsigned h_count =1;

	// vector[i][j] or vector[i*j]
	floatvecvec cor_widths;
	floatvecvec cor_means;
	floatvecvec cor_res;

    for (unsigned j=0; j<etas.size(); ++j) {
        for (unsigned i=0; i<radii.size(); ++i){

            c_all->cd(h_count);
            TCut all_cuts = cuts_r[i] && cuts_eta[j];

            // file0 : zero pu
            std::string histname0 = "0file" + std::to_string(i) + std::to_string(j);
            std::string pt_reco_gen_path_0 = path + "_pt_reco_gen" + " >> "+ histname0;

            tree_0->Draw(pt_reco_gen_path_0.c_str(),all_cuts);
            TH1 *histotmp0 = (TH1*)gPad->GetListOfPrimitives()->FindObject(histname0.c_str());
            h_pt_reco_gen_pu.push_back(histotmp0);
            h_count +=1;
            // file1
            std::string histname1 = "1file" + std::to_string(i) + std::to_string(j);
            std::string pt_reco_gen_path_200 = path + "_pt_reco_gen" + " >> "+ histname1;

            tree_pu->Draw(pt_reco_gen_path_200.c_str(),all_cuts);
            TH1 *histotmp1 = (TH1*)gPad->GetListOfPrimitives()->FindObject(histname1.c_str());
            h_pt_reco_gen_pu.push_back(histotmp1);
            h_count +=1;

			//cout << "Debug" << histotmp1->GetMean() << endl;

			std::string histname2 = "1file_reco" + std::to_string(i)+std::to_string(j);
			std::string pt_reco_path_200 = path + "_pt_reco" + " >> "+ histname2;

			tree_pu->Draw(pt_reco_path_200.c_str(), all_cuts);
			TH1 *histotmp2 = (TH1*)gPad->GetListOfPrimitives()->FindObject(histname2.c_str());
			h_count +=1;

			//std::cout << "Debug 2" << histotmp2->GetMean() << endl;

			/* Variables for resolution calc */

			float offset_value;
			float Pt_reco_mean;
			float Pt_reco_stdev;
			float gradient_PU0;
			float Pt_reco_PUcorrected_mean;
			float Pt_reco_PUcorrected_stdev;



			//std::cout << " WR: DEBUG: "<<  histotmp1->GetMean() << " "<< histotmp2->GetMean() << endl;

            /*offset calcs + decisions*/

            // if either mean is zero, discard!
			if (histotmp0->GetMean() == 0. || histotmp1->GetMean() == 0.  ) {
                 std::cout << " OFFSETCAlC:\tRadius/Eta"<< radii[i]<<"/"<<etas[j] <<"\tDISCARD\n";
            } else {
                // now we can do something!
                floatvector offset_vec = offset(histotmp0->GetMean(), histotmp0->GetStdDev(), histotmp1->GetMean(), histotmp0->GetStdDev(), gen_pt);
                floatvector tmpout_width;
				floatvector tmpout_means;
				floatvector tmpout_res;

                //std::cout << "\t\t" << offset_vec[0]<< std::endl;

				gradient_PU0 = histotmp0->GetMean();
				Pt_reco_mean = histotmp2->GetMean();
				Pt_reco_stdev = histotmp2->GetStdDev();
				offset_value = offset_vec[0];

				Pt_reco_PUcorrected_mean = (Pt_reco_mean - offset_value) / gradient_PU0;
				Pt_reco_PUcorrected_stdev = Pt_reco_stdev / gradient_PU0;

				tmpout_width.push_back(radii[i]);
				tmpout_width.push_back(etas[j]);
				tmpout_width.push_back(Pt_reco_PUcorrected_stdev);

				tmpout_means.push_back(radii[i]);
				tmpout_means.push_back(etas[j]);
				tmpout_means.push_back(Pt_reco_PUcorrected_mean);

				tmpout_res.push_back(radii[i]);
				tmpout_res.push_back(etas[j]);
				tmpout_res.push_back(Pt_reco_PUcorrected_stdev / Pt_reco_PUcorrected_mean);



				cor_widths.push_back(tmpout_width);
				cor_means.push_back(tmpout_means);
				cor_res.push_back(tmpout_res);
				cout << "for Eta: "<< etas[j] << "   N: " << histotmp2->GetEntries() << endl;
            }


        // End of eta /R loops
        }}
	floatvecvecvec all_results = {cor_widths, cor_means, cor_res};
	return all_results;

}
void plot_pu_offset(const floatvecvec& pu_offset_results, TFile* fileout){
		/* generate 2 dimensional graph of gradients vs radius vs eta. I don't know how to include the error on the grdient in this
         * -> Needs Axis labels, title Etc.
         *  */
		TGraph2D *g2 = new TGraph2D();
		int count = 0;
		for (unsigned i=0; i< pu_offset_results.size(); i++) {
            if (pu_offset_results[i][2] !=0. && pu_offset_results[i][1] >0.){ g2->SetPoint(count, pu_offset_results[i][0], pu_offset_results[i][1], pu_offset_results[i][2]);count++;}
		}
		/* Draw the graph. I should add axis labels and a title here. */
		//g2->SetTitle("");
        g2->GetZaxis()->SetTitle("Sigma_E/E");
		g2->GetXaxis()->SetTitle("Radius (reduced coordinates)");
		g2->GetYaxis()->SetTitle("Eta");

		TCanvas *c = new TCanvas("pu_offset", "PU offset", 600, 600);
		g2->Draw("TRI"); //empty draws a scatter plot, "TRI" draws a surface using triangles.
		fileout->Append(c);
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

floatvecvecvec split2d_1d_by_eta(floatvecvec input, floatvector _etas) {
		/* input of dimensions points <r, eta, interesting_bit> needs to be split into vectors of < r, interesting_bit> for the same eta
		 * already sorted by eta
		 * */

		floatvecvecvec lines; //vector of lines, which are vectors containing 2 vectors of floats x & y. <line<<x><y>>>

		floatvecvec tmpline;
		floatvector x;
		floatvector y;

 		for (auto& eta: _etas) {
			for (auto& it: input) {
					if (it[1]==eta){
							x.push_back(it[0]);
							y.push_back(it[2]);
					}
			}

			tmpline.push_back(x);
			tmpline.push_back(y);
			lines.push_back(tmpline);

			x.clear();
			y.clear();
			tmpline.clear();
		}

		return lines;
}

int min(const float *a, int n) {
		float miny = a[0];
		int loc = 0;
		for (int i =0; i<n; i++) {
				if (miny > a[i]) {
						miny = a[i];
						loc = i;
				}
		}
		return loc;
}

floatvecvec plotLines(floatvecvecvec lines, floatvector etas, TFile* fileout) {
		TCanvas *c_l = new TCanvas("Energy Resolution vs. R for different Etas", "Energy Resolution vs. R for different Etas", 700, 700);
		c_l->SetGrid();
		TMultiGraph *mg = new TMultiGraph();

		floatvecvec minimas_res_r_etas;

		for (unsigned i=0; i<lines.size(); i++) {
				floatvecvec line = lines[i];
				int n = line[0].size();
				float x [n];
				float y [n];

				copy(line[0].begin(), line[0].end(), x);
				copy(line[1].begin(), line[1].end(), y);

				floatvector minimas = {y[min(y, n)], x[min(y,n)], etas[i]};
				minimas_res_r_etas.push_back(minimas);
				TString graphname_eta;
				if (etas[i] > 0.01) {
					graphname_eta.Form("%.3f",etas[i]);
				} else {
						graphname_eta = "Full detector";
				}

				TGraph *tmpgraph = new TGraph(n, x, y);
				tmpgraph->SetLineColor(i+1);
				tmpgraph->SetMarkerColor(i+1);
				tmpgraph->SetTitle(graphname_eta);
				mg->Add(tmpgraph);
		}
		mg->GetXaxis()->SetTitle("Radius (reduced coordinates)");
		mg->GetYaxis()->SetTitle("Energy Resolution"); // Sigma_E/E
		mg->Draw("ac*");
		c_l->BuildLegend(.3, .4, .13, .5);

		fileout->Append(c_l);
		return minimas_res_r_etas;
}

void plotMinimas(floatvecvec minimas, TFile* fileout) {
		int n = minimas.size() -1;
		float etas [n];
		float radii [n];
		float res [n];
		if (minimas[0][2] < 0.01 && minimas[0][2] > -0.01) {
				cout << "All Etas removed from lineplot" << endl;
		} else {
				cout << "Removed from files from lineplots" << endl;
		}

		for (unsigned i=0; i<n; i++) {
				etas[i] = minimas[i+1][2];
				radii[i] = minimas[i+1][1];
				res[i] = minimas[i+1][0];
		}

		TCanvas *c_m_1 = new TCanvas("Best Resolution by Eta", "Best Resolution by Eta", 700, 700);

		TGraph *g1 = new TGraph(n, etas, res);
		g1->GetXaxis()->SetTitle("Eta");
		g1->GetYaxis()->SetTitle("Best SigmaE/E");
		g1->Draw("ac*");

		TCanvas *c_m_2 = new TCanvas("Best Radius by Eta", "Best Radius by Eta", 700, 700);
		TGraph *g2 = new TGraph(n, etas, radii);
		g2->GetXaxis()->SetTitle("Eta");
		g2->GetYaxis()->SetTitle("Best radius (reduced coordinates)");
		g2->Draw("ac*");
		fileout->Append(c_m_1);
		fileout->Append(c_m_2);
}
floatvecvec plotLines2(floatvecvecvec lines1, floatvecvecvec lines2, floatvecvecvec lines3, floatvecvecvec lines4, floatvector etas, TFile* fileout) {

        TCanvas *c_l = new TCanvas("Sigma_E/E vs. R for different Etas", "Sigma_E/E vs. R for different Etas", 700, 700);
		c_l->SetGrid();
		TMultiGraph *mg = new TMultiGraph();

		floatvecvec surface_points;

		int n = etas.size() -1;
		float resol_minimas [n];
		float radius_minimas [n];
		float resol_minimas_err [n];
		float radius_minimas_err [n];
		float Etas [n];
		float etaerr [n];


		for (unsigned i=0; i<lines1.size(); i++) {
				if (true || i !=4) { //in case a single line gives trouble while debugging, set the first statement to false and the number in the second statement to the line that is giving you trouble.
				floatvecvec line1 = lines1[i];
				floatvecvec line2 = lines2[i];
				floatvecvec line3 = lines3[i];
				floatvecvec line4 = lines4[i];


				floatvecvec line = {{},{}, {}};

				for (unsigned i=0; i<line1[0].size();i++) {
						line[0].push_back(line1[0][i]);
						float mean = (line1[1][i] + line2[1][i] + line3[1][i] + line4[1][i])/4.;
						float mean_of_squares = (line1[1][i]*line1[1][i]+line2[1][i]*line2[1][i]+line3[1][i]*line3[1][i]+line4[1][i]*line4[1][i])/4;
						float width = sqrt(mean_of_squares -mean*mean);
						line[1].push_back(mean);
						line[2].push_back(width);
				}
				int n = line1[0].size();
				float x [n];
				float y [n];
				float yerr[n];
				float xerr[n];

				copy(line[0].begin(), line[0].end(), x);
				copy(line[1].begin(), line[1].end(), y);
				copy(line[2].begin(), line[2].end(), yerr);

				for (unsigned j=0; j<n; j++) {
						xerr[j] = 0.00001; //HARDCODED
						if (etas[i] > 0.01) {
								floatvector tmp = {x[j], etas[i], y[j]};
								surface_points.push_back(tmp);
						}
				}

				if (i == 0 && etas[i] < 0.01) {
						cout << "Everything is fine." << endl;
				} else if (i == 0) {
						cout << "Not fine." << endl;
				}

				if (etas[i] > 0.1) {
					resol_minimas[i-1] = y[min(y,n)];
					radius_minimas[i-1] = x[min(y,n)];
					resol_minimas_err[i-1] = yerr[min(y,n)];
					radius_minimas_err[i-1] = xerr[min(y,n)];
					etaerr[i-1] = 0.0;
					Etas[i-1] = etas[i];


				} else  {
						cout << y[min(y, n)] << " " << yerr[min(y,n)] << endl;
				}

				string graphname_eta;
				if (etas[i] > 0.01) {
                    // decimal places for histgoram key
					graphname_eta = Form("%.3f", etas[i]); // to_string(etas[i]);
					//graphname_eta = to_string(etas[i]);

				} else {
						graphname_eta = "Full detector";
				}

				cout << "PlotLines: Position A \n";
				TGraphErrors *tmpgraph = new TGraphErrors(n, x, y, xerr, yerr);
				tmpgraph->SetLineColor(i+1);
				tmpgraph->SetMarkerColor(i+1);
				tmpgraph->SetTitle(graphname_eta.c_str());
				mg->Add(tmpgraph);
				}
		}
		cout << "PlotLines: Position B: plotting sigE v R";
        mg->SetTitle("Standardized Energy Error");
		mg->GetXaxis()->SetTitle("Radius (reduced coordinates)");
		mg->GetYaxis()->SetTitle("Sigma_E/E");
		mg->Draw("ac*");
		c_l->BuildLegend(.13, .71, .45, .87, "Eta Midpoints");

		TCanvas *c_besr_r_eta = new TCanvas("c_r", "c_2", 700, 700);

		cout << "PlotLines: Position C: plotting best R v Eta";
		TGraphErrors *best_r_eta = new TGraphErrors(n, Etas, radius_minimas, etaerr, radius_minimas_err);
		best_r_eta->SetTitle("Best Cluster Radius");
        //best_r_eta->GetYaxis()->SetTitle("Best radius (reduced coordinates)");
		best_r_eta->GetXaxis()->SetTitle("Eta");
		best_r_eta->Draw();

		cout << "PlotLines: Position D: plotting best sigE v Eta";
		TCanvas *c_best_res_eta = new TCanvas("c_res", "c_res", 700,700);
		TGraphErrors *best_res_eta = new TGraphErrors(n, Etas, resol_minimas, etaerr, resol_minimas_err);
		best_res_eta->SetTitle("Standardized Error against Eta");
        best_res_eta->GetXaxis()->SetTitle("Eta");
		best_res_eta->GetYaxis()->SetTitle("standardized error on the measurement");

		best_res_eta->Draw();

		cout << "PlotLines: Position C: appending graphs to file\n";
		fileout->Append(mg);
		fileout->Append(best_res_eta);
		fileout->Append(best_r_eta);

		return surface_points;


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

        std::string path = "gen_clusters._pt_reco_gen";

        std::cout << " MAIN: DEBUG:\t" << tree1->GetEntries() << std::endl;

        // gen_pt! hard coded!
        float gen_pt = 25.0;

		/* Define the list of radii and list of etas */
        // Hard coded variables :(
        float radius_inc = 0.005;
        unsigned radius_n = 12;
        floatvector _radii = generate_radii(radius_n,radius_inc);

        // Define eta
        float eta_inc = 0.2;
		floatvector _etas = genEta(1.65, 2.81, eta_inc, false);
		_etas.insert(_etas.begin(), 0.0);
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
			if (_etas[j] >0.01){
            std::string tmp1= "abs(_eta) > " + std::to_string(_etas[j]-eta_inc/2.);
            std::string tmp2= "abs(_eta) < "+std::to_string( _etas[j] + (eta_inc/2.));
            TCut tmpcut1 = tmp1.c_str();
            TCut tmpcut2 = tmp2.c_str();
            //std::cout << tmp1 << tmp2<<std::endl;
            cuts_eta.push_back( tmpcut1 && tmpcut2 );
			} else {
					string tmp1 = "abs(_eta) > 0";
					TCut tmpcut = tmp1.c_str();
					cuts_eta.push_back(tmpcut);
			}

        }

        // Find PU offset for given cuts in R and Eta
        /*
		floatvecvec offsetoutput =  compare_pu_effects(tree0,tree1,_radii,_etas,cuts_r, cuts_eta, path, gen_pt);
        std::cout <<" MAIN: size of offsetoutput vector:\t" << offsetoutput.size() << std::endl;
        std::cout <<" MAIN: expected size of offsetoutput:\t" << _radii.size() * _etas.size() << std::endl;
        //printvv(offsetoutput); //for debugging uncomment this line

        // plot pu offset results
        plot_pu_offset(offsetoutput);

		*/

        std::string base_path = "tc_clusters.";

        //resolution_width(tree0, tree1, _radii, _etas, cuts_r, cuts_eta, base_path, gen_pt);

        //std::string pt_reco_path = "tc_clusters.";
        //resolution_corrected(offsetoutput,file_1,pt_reco_path, _radii, _etas, eta_inc);
		//

		/* find Resolution for given R & Eta */

		floatvecvecvec all_results = resolution_width(tree0,tree1,_radii,_etas,cuts_r, cuts_eta, base_path, gen_pt); //3D vector, <<r, eta, width>,<r, eta, mean>,<r, eta, width/mean>>


		floatvecvec Sigma_over_mean_by_r_eta = all_results[2];

		floatvecvecvec lines = split2d_1d_by_eta(Sigma_over_mean_by_r_eta, _etas);


		TFile *file_2 = new TFile(filepath_2.c_str(), "READ");
		TFile *file_3 = new TFile(filepath_3.c_str(), "READ");
		TFile *file_4 = new TFile(filepath_4.c_str(), "READ");

		/* get the tree from the input file and specify the path of the relevant leaf*/
		TTree *tree2 = (TTree*) file_2->Get("tstats");
		TTree *tree3 = (TTree*) file_3->Get("tstats");
		TTree *tree4 = (TTree*) file_4->Get("tstats");


		floatvecvecvec lines2 = split2d_1d_by_eta(resolution_width(tree0,tree2,_radii,_etas,cuts_r, cuts_eta, base_path, gen_pt)[2], _etas);
		floatvecvecvec lines3 = split2d_1d_by_eta(resolution_width(tree0,tree3,_radii,_etas,cuts_r, cuts_eta, base_path, gen_pt)[2], _etas);
		floatvecvecvec lines4 = split2d_1d_by_eta(resolution_width(tree0,tree4,_radii,_etas,cuts_r, cuts_eta, base_path, gen_pt)[2], _etas);

		TFile *fileout = new TFile(filepath_out.c_str(), "RECREATE");
		floatvecvec points = plotLines2(lines, lines2, lines3, lines4, _etas, fileout);
		plot_pu_offset(points, fileout);
		//plot_pu_offset(Sigma_over_mean_by_r_eta, fileout);
		//floatvecvec minimas = plotLines(lines, _etas, fileout);
		//plotMinimas(minimas, fileout);

		fileout->Write();
}



