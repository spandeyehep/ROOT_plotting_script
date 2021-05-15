
// void generate_1Dplot(TH1F *hist_1, TH1F *hist_2, char const *tag_name="", int energy=-1, char const *leg_head="",
//    bool normalize=true, bool log_flag=true, bool save_canvas=false, bool DoRebin=true){
const int n_pl = 4;
TString pls[n_pl] = {"FTFP_BERT_EMN","QGSP_FTFP_BERT_EMN","FTFP_BERT_EMM","QGSP_BERT"};

int line_width[n_pl+1] = {1,2,2,1,1};
int line_style[n_pl+1] = {1,1,1,1,1};
int line_color[n_pl+1] = {kBlack, kMagenta, kGreen+2, kBlue, kRed};
// int line_color[n_pl+1] = {kBlack, kRed, kBlue,   kMagenta, kGreen+2};
//int rebin[n_pl+1] = {2,2,2,2,2};

std::map<int,int> rebin_;
std::map<int,float> x_max;
std::map<int,float> x_min;

void rebin_init_layer_pi(){
  rebin_.insert(pair<int, int>(20,1));
  rebin_.insert(pair<int, int>(50,1));
  rebin_.insert(pair<int, int>(80,1));
  rebin_.insert(pair<int, int>(100,2));
  rebin_.insert(pair<int, int>(120,2));
  rebin_.insert(pair<int, int>(200,4));
  rebin_.insert(pair<int, int>(250,4));
  rebin_.insert(pair<int, int>(300,4));
    
  x_max.insert(pair<int, int>(20,80.0));
  x_max.insert(pair<int, int>(50,150.0));
  x_max.insert(pair<int, int>(80,200.0));
  x_max.insert(pair<int, int>(100,300.0));
  x_max.insert(pair<int, int>(120,300.0));
  x_max.insert(pair<int, int>(200,600.0));
  x_max.insert(pair<int, int>(250,700.0));
  x_max.insert(pair<int, int>(300,800.0));
  
  x_min.insert(pair<int, int>(20,0.0));
  x_min.insert(pair<int, int>(50,0.0));
  x_min.insert(pair<int, int>(80,0.0));
  x_min.insert(pair<int, int>(100,0.0));
  x_min.insert(pair<int, int>(120,0.0));
  x_min.insert(pair<int, int>(200,0.0));
  x_min.insert(pair<int, int>(250,0.0));
  x_min.insert(pair<int, int>(300,0.0));
  
}

float getmax(TH1F* hist) {
  float y_max = -1.0;
  for(int i = 1; i <= hist->GetNbinsX(); i++) {
    if(hist->GetBinContent(i) > y_max) y_max = hist->GetBinContent(i);
    //cout<<i<<" => "<<hist->GetBinContent(i)<<endl;
  }

  return y_max;
}


void generate_1Dplot(vector<TH1F*> hist, char const *tag_name="", int energy=-1, char const *leg_head="",
   bool normalize=true, bool log_flag=true, bool save_canvas=false, bool DoRebin=true, int scaling = 0){  
  
  //rebin[20] = 1; rebin[50] = 1; rebin[80] = 2; rebin[100] = 2; rebin[120] = 2; rebin[200] = 4; rebin[250] = 8; rebin[300] = 8; 
  TCanvas *c = new TCanvas(tag_name, tag_name, 500, 500);
  //TCanvas *c = new TCanvas(htit, htit, 400, 250);
  //TCanvas *c = new TCanvas(tag_name, tag_name, 300, 300); //FOR SLIDES small size
  //TCanvas *c = new TCanvas(tag_name, tag_name, 350, 350); //FOR SLIDES small size
	//TCanvas *c = new TCanvas(tag_name, tag_name, 450, 450); //FOR SLIDES small size
  //TCanvas *c = new TCanvas(tag_name, tag_name, 600, 600); //FOR WebPage

  c->SetRightMargin(0.009);
  c->SetLeftMargin(0.11);
  c->SetTopMargin(0.05);

  //gStyle->SetOptStat(1111);
  gStyle->SetOptStat(0);
  double pvt_x_min = 0.6;
  double pvt_x_max = 0.99;
  double pvt_y_min = 0.95;
  double pvt_dely = 0.18;
  //gStyle->SetOptStat(0);

  //gStyle->SetOptFit(0);
  vector<TString> legName;
  // legName.push_back("Data HGCv16_AHv8");
  // legName.push_back("FullSim (FTFP_BERT_EMN)");
  TLegend *legend = new TLegend(0.52,0.95,0.99,0.8);
  TLegendEntry* leg_entry[n_pl+1];
  legend->SetTextSize(0.035);
  float y_max = -1.0;

 
  for(int i = 0; i < (int)hist.size(); i++) {
    if(DoRebin) {
      hist.at(i)->Rebin(rebin_[energy]);
    }
    if(normalize) {
      // hist.at(i)->Scale(1.0/hist.at(i)->Integral());
      // hist.at(i)->GetYaxis()->SetTitle("Normalized");

      hist.at(i)->Scale(1.0/hist.at(i)->GetMaximum());
      hist.at(i)->GetYaxis()->SetTitle("Normalized to peak");
      
    }

    

    hist.at(i)->SetLineWidth(line_width[i]);
    hist.at(i)->SetLineStyle(line_style[i]);
    hist.at(i)->SetLineColor(line_color[i]);
    hist.at(i)->SetTitle("");
      
    hist.at(i)->GetXaxis()->SetTitleSize(0.04);
    hist.at(i)->GetXaxis()->SetLabelSize(0.04);
    hist.at(i)->GetXaxis()->SetTitle("Energy [GeV]");
    hist.at(i)->GetYaxis()->SetLabelSize(0.035);
    hist.at(i)->GetYaxis()->SetTitleSize(0.04);
    hist.at(i)->GetYaxis()->SetTitleOffset(1.45);
    hist.at(i)->GetXaxis()->SetRangeUser(x_min[energy],x_max[energy]);
    if(getmax(hist.at(i)) > y_max) y_max = getmax(hist.at(i));
    //cout<<i<<" = getmax(hist.at(i)) : y_max :: "<<getmax(hist.at(i))<<" : "<<y_max<<endl;
    //hist.at(i)->GetYaxis()->SetRangeUser(0.0,y_max*1.10);hist.at(i)->Draw("hist");return;

    if(!i) {
      legName.push_back("Data");
      hist.at(i)->SetLineWidth(1);
      hist.at(i)->SetMarkerColor(line_color[i]);
      hist.at(i)->SetMarkerSize(0.8);
      hist.at(i)->SetMarkerStyle(kFullCircle);
      leg_entry[i] = legend->AddEntry(hist.at(i),legName[i],"pe");
      leg_entry[i]->SetTextColor(hist.at(i)->GetMarkerColor());
    }
    else {
      legName.push_back(pls[i-1].Data());
      leg_entry[i] = legend->AddEntry(hist.at(i),legName[i],"l");
      leg_entry[i]->SetTextColor(hist.at(i)->GetLineColor());
    }

    
    // if(!i) hist.at(i)->Draw("hist");
    // else   hist.at(i)->Draw("hist sames");
  }
  for(int i = 0; i < (int)hist.size(); i++) {
    if(!log_flag) hist.at(i)->GetYaxis()->SetRangeUser(0.0,y_max*1.20);
    if(!i) hist.at(i)->Draw("");
    else   hist.at(i)->Draw("hist sames");
  }
  legend->Draw();



  if(log_flag) {
      gPad->SetLogy();
    }
  

  // hist_2->Draw("hist");
  // hist_1->Draw("hist sames");
  
  gPad->Update();
 
  // for(int i = 0; i < (int)hist.size(); i++) {
  //   TPaveStats *pv = (TPaveStats*)hist.at(i)->FindObject("stats");
  //   pv->SetTextColor(hist.at(i)->GetLineColor());
  //   pv->SetLineColor(hist.at(i)->GetLineColor());
  //   pv->SetX1NDC(pvt_x_min);  //x1 left start
  //   pv->SetX2NDC(pvt_x_max);  //x2  right end
  //   pv->SetY1NDC(pvt_y_min - i*pvt_dely);  //y1 top starting
  //   pv->SetY2NDC(pvt_y_min - (i+1)*pvt_dely); //y2 bottom ending
  // }
   

  char* dir_name = new char[200];
  char* en_text = new char[200];
  sprintf(en_text,"%d GeV/c #pi^{-} beam",energy);
  TLatex* textOnTop = new TLatex();
  textOnTop->SetTextSize(0.035);
  textOnTop->DrawLatexNDC(0.12,0.96,"CMS #it{#bf{Preliminary}}");
  //textOnTop->SetTextSize(0.035);
  textOnTop->DrawLatexNDC(0.70,0.96,en_text);
  textOnTop->SetTextSize(0.05);
  textOnTop->DrawLatexNDC(0.60,0.75,leg_head);
  sprintf(en_text,"MC rescaled");
  textOnTop->SetTextSize(0.04);
  textOnTop->SetTextColor(kRed);
  textOnTop->DrawLatexNDC(0.65,0.70,en_text);
  
  // if(scaling == 0) {
  //   textOnTop->DrawLatexNDC(0.75,0.25,"#bf{No rescaling}");
  //   sprintf(dir_name,"un_rescaled");
  // }
  // else if(scaling == 8) {
  //   textOnTop->DrawLatexNDC(0.75,0.25,"#bf{Sim: EE/1.08}");
  //   sprintf(dir_name,"rescaled_EE8");
  // }
  // else if(scaling == 15) {
  //   textOnTop->DrawLatexNDC(0.70,0.25,"#bf{Sim: EE/1.08 & FH/1.15}");
  //   sprintf(dir_name,"rescaled_EE8_FH15");
  // }
  // else {
  //   cout<<"Incorrect scaling input. Exiiting...."<<endl;
  //   return;
  // }

  
  //textOnTop->DrawLatexNDC(0.63,0.66,"#bf{ShowerStart based EventCateg.}");

  std::string name_ = tag_name;

  cout<<"GetName : "<<name_<<endl;

  gPad->Modified();
  char* canvas_name = new char[500];
  //c->Print(canvas_name);
  


  if(save_canvas) {
    
    sprintf(canvas_name,"./plots/weighted/%s_MCrescaled.png",tag_name);
    cout<<"Canvas Name ="<<canvas_name<<endl;
    c->SaveAs(canvas_name);
    sprintf(canvas_name,"./plots/weighted/pdf/%s_MCrescaled.pdf",tag_name);
    cout<<"Canvas Name ="<<canvas_name<<endl;
    c->SaveAs(canvas_name);

    // sprintf(canvas_name,"./plots/data_sim_comparison/calibrated/pdf_version/%s_%s.pdf",tag_name,trailer);
    // cout<<"Canvas Name ="<<canvas_name<<endl;
    // c->SaveAs(canvas_name);
  }
  
}



void run_one(int energy, const char* hist_="", int scaling = 0, bool normalize=false, bool log_flag = false,
       bool save_canvas = false,  bool DoRebin = false){

  char *tag = new char[200];
  char *leg_head = new char[200];

 
  char* fname0 = new char[5000];
  // char* f_name1 = new char[500];
  vector<TString> fileName;

  // vector<string> legName;
  // legName.push_back("1");
  // legName.push_back("2");
  // legName.push_back("3");

  char* dir_name = new char[2000];
  if(scaling == 0) {
    sprintf(dir_name,"./sim/un_rescaled");
  }
  else if(scaling == 8) {
    sprintf(dir_name,"./sim/EE8_rescaled");
  }
  else if(scaling == 15) {
    sprintf(dir_name,"./sim/EE8_FH15_rescaled");
  }
  else {
    cout<<"Incorrect scaling input. Exiiting...."<<endl;
    return;
  }

  sprintf(dir_name,"/home/shubham/work/HGCAL/CERNTB/oct2018TB/octTB_plotting/withAHCAL/weight_scan/27_Apr_2021_plotsForThesis");

  sprintf(fname0,"%s/data/data_pion%d_v16_v8_chi2method_3.root",dir_name,energy);
  fileName.push_back(fname0);

  //sprintf(dir_name,"/home/shubham/work/HGCAL/CERNTB/oct2018TB/octTB_plotting/withAHCAL/weight_scan/22_feb_2021_scaling_noscaling_shower_shapes/sim/unscaled");
  sprintf(dir_name,"/home/shubham/work/HGCAL/CERNTB/oct2018TB/octTB_plotting/withAHCAL/weight_scan/22_feb_2021_scaling_noscaling_shower_shapes/sim/scaled");

  for(int i = 0; i < 2; i++) {
    //sprintf(fname0,"./sim/rescaled/sim_pion%d_%s_v44_VtxBeam_v3_SS0_noise4.root",energy,pls[i].Data());  
    sprintf(fname0,"%s/sim_pion%03d_%s_v46_patchMIP.root",dir_name,energy,pls[i].Data());  
    fileName.push_back(fname0);
  }

  
   rebin_init_layer_pi();


  char* hist_name_1 = new char[100];
  char* hist_name_2 = new char[100];
  vector<string> hist_name;
  char* hist_name_muon = new char[100];
  char* axis_name = new char[100];
  char *h0 = new char[200];
  char *h1 = new char[200];
  

  char *xtit = new char[200];
 
  if(!strcmp(hist_,"EE")) {
    sprintf(hist_name_1,"shower_energy_reco/showering_in_EE/h_showerinEE_elecpi_scale");
    hist_name.push_back(hist_name_1);
    sprintf(hist_name_2,"%s",hist_name_1);
    hist_name.push_back(hist_name_2);
    //sprintf(leg_head,"#bf{%d GeV/C #pi^{-}, Showering in CE-E}",energy);
    sprintf(leg_head,"#bf{Showering in CE-E}");
  }
  else if(!strcmp(hist_,"FH")) {
    sprintf(hist_name_1,"shower_energy_reco/MIPs_in_EE/h_MIPsinEE_elecpi_scale");
    sprintf(hist_name_2,"%s",hist_name_1);
    hist_name.push_back(hist_name_1);
    // /sprintf(leg_head,"%d GeV/C pion, MIPs in CE-E",energy);
    sprintf(leg_head,"#bf{MIPs in CE-E}");
    hist_name.push_back(hist_name_2);
  }
  else {
    cout<<"Incorrect hist_name provided"<<endl;
    return;
  }
  

  
  vector<TH1F*> hists;

  for(int i = 0; i < fileName.size(); i++) {
    TFile *file0 = TFile::Open(fileName.at(i));

    if(!file0) {
      cout<<"Couldn't find "<<fileName.at(i)<<endl;
      return;
    }
    else {
      cout<<fileName.at(i)<<" is loaded as Target!!"<<endl;
    }

    TH1F* hist_temp = (TH1F*)file0->Get(hist_name_1);

    if(!hist_temp) {
      cout<<"Couldn't find "<<hist_name_1<<" in file"<<fileName.at(i)<<endl;
      return;
    }
    
    if(!i) hist_temp->SetName("Data OctTB");
    else hist_temp->SetName(pls[i-1]);
    hists.push_back(hist_temp);
    
  }
  sprintf(xtit,"Energy [GeV]");
  

  sprintf(tag,"data_comp_pion_%03dgev_%s",energy,hist_);
  //sprintf(tag,"data_comp_pion_%03dgev_%s_SSBasedEvntCat",energy,hist_);

 
  generate_1Dplot(hists,tag,energy,leg_head,normalize,log_flag,save_canvas,DoRebin, scaling);
}


void run_selected(bool save_ = 0) {


  gROOT->SetBatch(1);
  const int n = 8;
  int e_list[n] = {20,50,80,100,120,200,250,300};
  for(int i = 0; i < n; i++) {
    run_one(e_list[i],"EE",0,1,0,save_,1);
    run_one(e_list[i],"FH",0,1,0,save_,1);
  }

}

void run_two(int energy, bool save_ = 0){
  //energy, hist, normalize, log_flag, save, Dorebin

  // run_one(energy,"EE",1,1,save_,1);
  // run_one(energy,"FH",1,1,save_,1);
  bool log_flag = false;
  int scaling = 0;
  if(energy > 20) {
    run_one(energy,"EE",scaling,1,log_flag,save_,1);
    run_one(energy,"FH",scaling,1,log_flag,save_,1);
  }
  else {
    run_one(energy,"EE",scaling,1,log_flag,save_,0);
    run_one(energy,"FH",scaling,1,log_flag,save_,0); 
  }
}

// void run_all_scaling_energy(bool save_ = 0){
//   gROOT->SetBatch(1);
//   const int n = 8;
//   int e_list[n] = {20,50,80,100,120,200,250,300};
//   for(int i = 0; i < n; i++) {
//     run_scaling(e_list[i], 0, save_);
    
//   }
// }

// void run_all_pl(const char* pl="", bool save_ = 0){
//   gROOT->SetBatch(1);
//   const int n = 8;
//   int e_list[n] = {20,50,80,100,120,200,250,300};
//   for(int i = 0; i < n; i++) {
//     run_two(e_list[i], pl, save_);
//   }
// }


