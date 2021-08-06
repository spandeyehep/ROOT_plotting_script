//int point_col[5] = { kBlack, kRed, kBlue ,  kGreen+3,  kMagenta};
int point_col[5] = { kBlack, kMagenta, kBlue ,  kGreen+3,  kRed};
//int point_style[3] = {kFullCircle,kOpenSquare,kFullTriangleUp};
int point_style[4] = {kFullCircle, kOpenSquare,kFullTriangleUp,kFullTriangleDown};
float point_size[4] = {1.2,1.2,1.2,1.2};

double getMax(TH1F* hist) {
  double max = -1.0;
  for(int i = 1; i < (int)hist->GetNbinsX(); i++) {
      if(hist->GetBinContent(i) > 0 && hist->GetBinCenter(i) > 0.5) {
        if(hist->GetBinContent(i) > max) max = hist->GetBinContent(i);
      }
  }
  return max;   
}


float calculate_error(float x, float y, float dx, float dy) {
  if(x*y == 0.0) return 0;
  return ((x/y)*(sqrt((dx/x)*(dx/x) + (dy/y)*(dy/y))));
}

void re_weight_dEdX(int energy = 200, bool log_ = true, bool fit_expo = false, bool save_ = false){

    
  if(energy < 0) {
    cout<<"Incorrect energy : "<<energy<<endl;
    return;
  }
  //TCanvas *c = new TCanvas("c", "c", 500, 500);
  TCanvas *c = new TCanvas("c", "c", 550, 550);
  c->SetRightMargin(0.008);

  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);

  
  vector<string> legName;
  
  //TLegend *legend = new TLegend(0.45,0.80,0.95,0.70);
  TLegend *legend = new TLegend(0.35,0.88,0.99,0.63);

  //legName.push_back("Data HGCv16_AHv8");
  legName.push_back("Data");
  //legName.push_back("FullBL sim (FTFP_BERT_EMN)");
  legName.push_back("FTFP_BERT_EMN");


  vector<string> filename;
  char* temp_char = new char[2000];

  sprintf(temp_char,"./data/data_pion%03d_v16_v8.root",energy);
  filename.push_back(temp_char);
  sprintf(temp_char,"./sim/sim_pion%03d_FTFP_BERT_EMN_v46_patchMIP.root",energy);
  filename.push_back(temp_char);

  // sprintf(temp_char,"./sim/sim_pion%03d_QGSP_FTFP_BERT_EMN_v46_patchMIP.root",energy);
  // filename.push_back(temp_char);

  // sprintf(temp_char,"./data/test200_lowStat.root");
  // filename.push_back(temp_char);
  // sprintf(temp_char,"./sim/test200_FTF_lowStat.root");
  // filename.push_back(temp_char);

  // sprintf(temp_char,"../26_oct_2020_MIP_scaling/data/data_pion%d_v16_v8_chi2method_3.root",energy);
  // filename.push_back(temp_char);
  // sprintf(temp_char,"../26_oct_2020_MIP_scaling/sim/NoRescaling/sim_pion%d_FTFP_BERT_EMN_v44_VtxBeam_v3_correctFH10_chi2method_3.root",energy);
  // filename.push_back(temp_char);


  // TFile* file = TFile::Open("/home/shubham/work/HGCAL/CERNTB/oct2018TB/octTB_plotting/withAHCAL/weight_scan/Jan_31_data_sim_newChi2Calibrated_energy/data/data_pion200_v16_v8.root");
  // TH1F* hist = (TH1F*)file->Get("h_shower_start_part_collapsed_EE");



  TH1F* new_hist[2];// = new TH1F("new_hist","new_hist",10000,-2.0,5.0);
  
  double y_max = -1.0;  
  double y_range[] = {0.0,0.0};


  for(int j = 0; j < (int)filename.size(); j ++) {
    float last = 0.0;
    int layer = 0;
    // float dL = 0.08075;
    float dL = 0.038;
    
    cout<<endl;
    //TFile* file = TFile::Open(filename.at(j).c_str());
    TFile* file = TFile::Open(filename.at(j).c_str());
    if(!file) {
      cout<<"Could not open "<<filename.at(j).c_str()<<endl;
      return;
    }
    else {
      cout<<filename.at(j).c_str()<<" loaded successfully!!"<<endl;
    }
    TH1F* hist = (TH1F*)file->Get("h_shower_start_part_collapsed_EE");
    if(!hist) {
      cout<<"Could not load histogram from "<<filename.at(j).c_str()<<endl;
      return;
    }
    // hist->Scale(1.0/hist->Integral());
    new_hist[j] = new TH1F("new_hist","new_hist",10000,-2.0,5.0);

    new_hist[j]->Sumw2();
    

    //cout<<"Max = "<<getMax(new_hist[j])<<endl;

    for(int i = 1; i < (int)hist->GetNbinsX(); i++) {
      if(hist->GetBinContent(i) > 0) {
        // cout<<i<<"\t"<<layer<<"\t"<<layer<<"\t"<<hist->GetBinCenter(i)<<"\t"<<(hist->GetBinCenter(i)-last)<<endl;
        layer++;
        if(hist->GetBinCenter(i) > 0) {
        	
          //float weight = dL/(hist->GetBinCenter(i)-last);
          float weight = 1.0/(hist->GetBinCenter(i)-last);
          if(last == 0) weight = 1;
          //weight = 1;
          //cout<<i<<"\t"<<hist->GetBinCenter(i)<<"\t"<<hist->GetBinContent(i)<<"\t"<<(hist->GetBinCenter(i)-last)<<endl;

        	float _toFill = hist->GetBinContent(i)*weight;
        	new_hist[j]->SetBinContent(i, _toFill);
          float bin_error = calculate_error(hist->GetBinContent(i), (hist->GetBinCenter(i)-last), hist->GetBinError(i), 0.0);
          //cout<<"layer : N_layer : weight_layer : N_layer_error : weight_layer_error : total_error :: "<<layer<<" : "<<hist->GetBinContent(i)<<" : "<<(hist->GetBinCenter(i)-last)<<" : "<<hist->GetBinError(i)<<" : 0.0 : "<<bin_error<<endl;
          //new_hist[j]->SetBinError(i, weight*sqrt(hist->GetBinContent(i)));
          new_hist[j]->SetBinError(i, bin_error);
          //new_hist[j]->SetBinError(i, weight*sqrt(hist->GetBinError(i)));
          //new_hist[j]->SetBinError(i, 0.000005);
        	last = hist->GetBinCenter(i);

        }
        else {
        	new_hist[j]->SetBinContent(i,hist->GetBinContent(i));
          //new_hist[j]->SetBinError(i, 0.000005);
          new_hist[j]->SetBinError(i, sqrt(hist->GetBinContent(i)));
        }
        
      }

    }
    // int ll = 0;
    // cout<<" ***** BEFORE Normalizing **** "<<endl;
    // for(int i = 1; i < new_hist[j]->GetNbinsX(); i++) {
    //   if(new_hist[j]->GetBinContent(i) > 0) {
    //     ll++;
    //     if(new_hist[j]->GetBinCenter(i) > 0) {
    //       cout<<"layer : bin_content : binError :: "<<ll<<" : "<<new_hist[j]->GetBinContent(i)<<" : "<<" : "<<new_hist[j]->GetBinError(i)<<endl;
    //     }
    //   }
    // }
    new_hist[j]->Scale(1.0/new_hist[j]->Integral());
    // ll = 0;
    // cout<<" ***** AFTER Normalizing **** "<<endl;
    // for(int i = 1; i < new_hist[j]->GetNbinsX(); i++) {
    //   if(new_hist[j]->GetBinContent(i) > 0) {
    //     ll++;
    //     if(new_hist[j]->GetBinCenter(i) > 0) {
    //       cout<<"layer : bin_content : binError :: "<<ll<<" : "<<new_hist[j]->GetBinContent(i)<<" : "<<" : "<<new_hist[j]->GetBinError(i)<<endl;
    //     }
    //   }
    // }
    new_hist[j]->GetXaxis()->SetRangeUser(-0.1,5.3);
    //new_hist[j]->GetXaxis()->SetRangeUser(-2.0,5.0);

    //new_hist[j]->GetXaxis()->SetTitle("z [in units of #lambda_{#pi}]");
    new_hist[j]->GetXaxis()->SetTitle("z [in units of #lambda_{int}]");
    new_hist[j]->GetXaxis()->SetTitleSize(0.04);

    new_hist[j]->GetXaxis()->SetTitleOffset(0.8);

    new_hist[j]->GetYaxis()->SetTitle("1/N dN/dz");
    new_hist[j]->GetYaxis()->SetTitleSize(0.035);
    new_hist[j]->GetXaxis()->SetTitleOffset(1.3);

    //new_hist[j]->SetName("Shower Start dN/d(#lambda)");
    new_hist[j]->SetName("Shower_Start");
    new_hist[j]->SetLineWidth(2);
    new_hist[j]->SetLineStyle(1);
    new_hist[j]->SetTitle("");
    new_hist[j]->GetXaxis()->SetLabelSize(0.045);

    new_hist[j]->SetMarkerStyle(point_style[j]);
    new_hist[j]->SetMarkerSize(point_size[j]);
    new_hist[j]->SetMarkerColor(point_col[j]);
    new_hist[j]->SetLineColor(point_col[j]);

    //new_hist->GetXaxis()->SetTitleSize(0.05);
    new_hist[j]->GetXaxis()->SetTitleOffset(1.0);
    new_hist[j]->GetYaxis()->SetTitleOffset(1.45);
    //new_hist->GetYaxis()->SetTitleSize(0.05);
    //new_hist->GetXaxis()->SetLabelSize(0.035);
    new_hist[j]->GetXaxis()->SetLabelSize(0.045);
    new_hist[j]->GetYaxis()->SetLabelSize(0.035);

    if(j == 0) {
      
      if(!log_) new_hist[j]->GetYaxis()->SetRangeUser(0.0,1.3*new_hist[j]->GetMaximum());
      else new_hist[j]->GetYaxis()->SetRangeUser(0.001,10*new_hist[j]->GetMaximum());

      if(y_max < new_hist[j]->GetMaximum()) y_max = new_hist[j]->GetMaximum()/12;
    }

    if(j == 0)
      new_hist[j]->Draw();
    else
      new_hist[j]->Draw("same");
    
    if(fit_expo) {
      TF1* expo = new TF1("expo","expo",0.0,5.0);
      expo->SetParameter(7.0,-1.0);
      new_hist[j]->Fit(expo,"Q","",0.04,5.0);
      expo = new_hist[j]->GetFunction("expo");
      expo->SetParameter(expo->GetParameter(0),expo->GetParameter(1));
      new_hist[j]->Fit(expo,"Q","",0.04,5.0);
      TFitResultPtr r = new_hist[j]->Fit(expo,"S","",0.04,5.0);
      cout<<"Chi2/ndf : = "<<r->Chi2()/r->Ndf()<<endl;
      expo->SetLineColor(new_hist[j]->GetMarkerColor());
      expo->SetLineStyle(1);
      expo->Draw("SAME");
      //cout<<"Ndfs : = "<<r->Ndf()<<endl;
      double chi2ndf = (r->Chi2()/r->Ndf());
      double l_int = -1.0/expo->GetParameter(1);
      double l_int_e = (l_int*l_int)*expo->GetParError(1);
      TLegendEntry* l1 = legend->AddEntry(new_hist[j],legName[j].c_str(),"pe");
      l1->SetTextColor(new_hist[j]->GetMarkerColor());
      char* legtemp = new char[100];
      sprintf(legtemp,"#chi^{2}/ndf = %0.2f, #lambda_{#pi} = %0.2f#pm%0.2f #lambda_{int}",chi2ndf,l_int,l_int_e);
      TLegendEntry* l2 = legend->AddEntry(new_hist[j],legtemp,"l");
      l2->SetTextColor(new_hist[j]->GetMarkerColor());
    }
    else {
      TLegendEntry* l1 = legend->AddEntry(new_hist[j],legName[j].c_str(),"pe");
      l1->SetTextColor(new_hist[j]->GetMarkerColor());
      
    }
   


  }
  


  gPad->Update();


  legend->SetTextSize(0.035);
  legend->Draw();

  if(log_) {
    gPad->SetLogy();
  }
  // new_hist->GetYaxis()->SetRangeUser(0.0,2000.0);

  gPad->RedrawAxis();
  gPad->Update();
  

  TLatex* textOnTop = new TLatex();
  textOnTop->SetTextSize(0.035);
  textOnTop->DrawLatexNDC(0.10,0.92,"CMS #it{#bf{Preliminary}}");

  sprintf(temp_char,"#bf{%d GeV/c #pi^{-}, October 2018}",energy);

  textOnTop->DrawLatexNDC(0.60,0.92,temp_char);

  char* compart_ = new char[100];
  sprintf(compart_,"CE-E");

  //textOnTop->SetTextColorAlpha(kBlue-1, 0.3);
  textOnTop->SetTextColorAlpha(kBlack, 1.0);
  //textOnTop->SetTextSize(0.09);
  textOnTop->SetTextSize(0.06);
  textOnTop->DrawLatexNDC(0.14,0.15,compart_);
  //textOnTop->DrawLatexNDC(0.14,0.78,compart_);
  sprintf(compart_,"CE-H");
  textOnTop->DrawLatexNDC(0.5,0.15,compart_);

  



  //TLine* L1 = new TLine(0.0,0.0,0.0,7000.0);
  // TLine* L1 = new TLine(-0.1,0.0,-0.1,0.19);
  // L1->SetLineColor(kMagenta);
  // L1->SetLineStyle(2);
  // L1->SetLineWidth(2);
  // L1->Draw();

  
  //TLine* L2 = new TLine(1.3,0.0,1.3,7000.0);
  TLine* L2 = new TLine(1.4,0.0,1.4,y_max);
  L2->SetLineColor(kBlack);
  L2->SetLineStyle(2);
  L2->SetLineWidth(4);
  L2->Draw("SAME");




  gPad->Update();
  gPad->Modified();
  
  char* can_name = new char[100];
  sprintf(can_name,"./plots/shower_start_datav16v8_FullBL_FTFP_BERT_EMN_pi%03dgev",energy);
  if(save_) {
    char* save_name = new char[100];
    sprintf(save_name,"%s.png",can_name);
    cout<<"Save_name : "<<save_name<<endl;
    c->SaveAs(save_name);
    sprintf(save_name,"%s.pdf",can_name);
    cout<<"Save_name : "<<save_name<<endl;
    c->SaveAs(save_name);

  }


}


void run_all_energy(bool save_) {
  int energy[8] = {20,50,80,100,120,200,250,300};
  gROOT->SetBatch(1);
  for (int i = 0; i < 8; i++) {
    //re_weight_dEdX(energy[i],0,1,save_);
    re_weight_dEdX(energy[i],1,1,save_);
  }

  
}


