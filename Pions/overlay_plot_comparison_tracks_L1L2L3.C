const int n_pl = 2;
int sequence[2] = {1,0};
TString pls[n_pl] = {"FTFP_BERT_EMN","QGSP_FTFP_BERT_EMN"};

int line_width[5] = {1,1,1,1,1};
int line_style[5] = {1,1,1,1,1};
//int line_color[5] = {kBlack, kMagenta, kGreen+2, kBlue, kRed};
int line_color[5] = {kBlack, kBlue, kMagenta, kGreen+2, kRed};

std::map<int,int> rebin_;
std::map<int,float> x_max;


void generate_1Dplot(vector<TH1F*> hist, char const *tag_name="", int energy=-1, char const *leg_head="",
   bool normalize=true, bool log_flag=true, bool save_canvas=false, bool DoRebin=true){  
  

  TCanvas *c = new TCanvas(tag_name, tag_name, 500, 500);
  //TCanvas *c = new TCanvas(htit, htit, 400, 250);
  //TCanvas *c = new TCanvas(tag_name, tag_name, 300, 300); //FOR SLIDES small size
  //TCanvas *c = new TCanvas(tag_name, tag_name, 350, 350); //FOR SLIDES small size
	//TCanvas *c = new TCanvas(tag_name, tag_name, 450, 450); //FOR SLIDES small size
  //TCanvas *c = new TCanvas(tag_name, tag_name, 600, 600); //FOR WebPage

  c->SetRightMargin(0.009);
  c->SetLeftMargin(0.11);
  c->SetTopMargin(0.05);

  //gStyle->SetOptStat(1111111);
  gStyle->SetOptStat(0);
  //gStyle->SetOptStat(0);

  //gStyle->SetOptFit(0);
  vector<TString> legName;
  //TLegend *legend = new TLegend(0.65,0.95,0.99,0.75);
  std::string leg_head_str = leg_head;
  TLegend *legend;
  if(leg_head_str.find("CE-H") != std::string::npos && energy > 50) {
   legend = new TLegend(0.15,0.45,0.59,0.17);
  }
  else {
   //legend = new TLegend(0.55,0.88,0.98,0.65); 
    legend = new TLegend(0.50,0.92,0.98,0.78); 
  }
  TLegendEntry* leg_entry[n_pl+1];
  legend->SetTextSize(0.032);
  float x_label_size = 0.035;
  float y_label_size = 0.030;
  float y_max = -1.0;

  for(int i = 0; i < (int)hist.size(); i++) {
    if(normalize) {
      hist.at(i)->Scale(1.0/hist.at(i)->Integral());
      hist.at(i)->GetYaxis()->SetTitle("Normalized");
      
    }
    hist.at(i)->SetLineWidth(line_width[i]);
    hist.at(i)->SetLineStyle(line_style[i]);
    hist.at(i)->SetLineColor(line_color[i]);
    hist.at(i)->SetTitle("");

    hist.at(i)->GetXaxis()->SetTitleSize(0.04);
    hist.at(i)->GetXaxis()->SetLabelSize(x_label_size);
    hist.at(i)->GetYaxis()->SetLabelSize(y_label_size);
    hist.at(i)->GetYaxis()->SetTitleOffset(1.45);
    if(DoRebin) {
      //hist.at(i)->Rebin(rebin_[energy]);
      hist.at(i)->Rebin(2);
    }
    hist.at(i)->GetXaxis()->SetRangeUser(-6.0,6.0);
    //cout<<"x_max[energy]: " <<x_max[energy]<<endl;
    legName.push_back(hist.at(i)->GetName());
    

    if(hist.at(i)->GetMaximum() > y_max) y_max = hist.at(i)->GetMaximum();

    leg_entry[i] = legend->AddEntry(hist.at(i),legName[i],"l");
    leg_entry[i]->SetTextColor(hist.at(i)->GetLineColor());
    // if(!i) hist.at(i)->Draw("hist");
    // else   hist.at(i)->Draw("hist sames");
  }


  for(int i = 0; i < (int)hist.size(); i++) {
    hist.at(i)->GetYaxis()->SetRangeUser(0.0,y_max*1.35);
    if(!i) hist.at(i)->Draw("hist");
    else hist.at(i)->Draw("hist same");
  }

  legend->Draw();



  if(log_flag) {
      gPad->SetLogy();
    }
  

  // hist_2->Draw("hist");
  // hist_1->Draw("hist sames");
  
  gPad->Update();
  gPad->SetGridx();
  gPad->SetGridy();
  

  

  TLatex* textOnTop = new TLatex();
  textOnTop->SetTextSize(0.04);
  textOnTop->DrawLatexNDC(0.12,0.96,"CMS #it{#bf{Preliminary}}");
  textOnTop->DrawLatexNDC(0.50,0.96,leg_head);

  gPad->Modified();
  char* canvas_name = new char[100];
  //c->Print(canvas_name);
  
  if(save_canvas) {
    sprintf(canvas_name,"./plots/tracks/1D/%s.png",tag_name);
    cout<<"Canvas Name ="<<canvas_name<<endl;
    c->SaveAs(canvas_name);

    // sprintf(canvas_name,"./plots/data_sim_comparison/tracks/pdf_version/%s",tag_name);
    // cout<<"Canvas Name ="<<canvas_name<<endl;
    // c->SaveAs(canvas_name);
  }
  
}




void run_one(int energy, const char* axis = "", bool normalize=false, bool log_flag = false,
       bool save_canvas = false,  bool DoRebin = false){

  
  rebin_.clear();
  x_max.clear();
  char *tag = new char[200];
  char *leg_head = new char[200];

 


  char* dir = new char[2000];
  // sprintf(dir,"/home/shubham/work/HGCAL/CERNTB/oct2018TB/octTB_plotting/withAHCAL/weight_scan/June9_20_newSS_elecScale/
  //   data/newNoiseMap/withCorr/layerwise_info");
  sprintf(dir,"./data");
  
  char* fname0 = new char[2000];
  // char* f_name1 = new char[500];
  vector<TString> fileName;

  sprintf(fname0,"%s/data_pion%d_v16_v8_chi2method_3.root",dir,energy);
  fileName.push_back(fname0);
  sprintf(fname0,"%s/data_pion%d_v16_v8_chi2method_3.root",dir,energy);
  fileName.push_back(fname0);
  sprintf(fname0,"%s/data_pion%d_v16_v8_chi2method_3.root",dir,energy);
  fileName.push_back(fname0);

  char* hist_name_1 = new char[100];
  char* hist_name_2 = new char[100];

  vector<TString> hist_name_i;

  char* hist_name_muon = new char[100];
  char* axis_name = new char[100];
  char *h0 = new char[200];
  char *h1 = new char[200];
  

  char *xtit = new char[200];
 
  sprintf(hist_name_1,"beamProfile/unweighted/h_track%s_EE03_FULL_corrected",axis);
  hist_name_i.push_back(hist_name_1);
  sprintf(hist_name_1,"beamProfile/unweighted/h_track%s_EE02_FULL_corrected",axis);
  hist_name_i.push_back(hist_name_1);
  sprintf(hist_name_1,"beamProfile/unweighted/h_track%s_EE01_FULL_corrected",axis);
  hist_name_i.push_back(hist_name_1);
  sprintf(leg_head,"#bf{HGCAL TB, %d GeV/c#pi^{-} beam}",energy);
  


  sprintf(xtit,"TrackImapctPostion in %s-axis [cm]",axis);
  vector<TH1F*> hists;
  TH1::AddDirectory(kFALSE);
  for(int i = 0; i < fileName.size(); i++) {
    TFile *file0 = TFile::Open(fileName.at(i));

    if(!file0) {
      cout<<"Couldn't find "<<fileName.at(i)<<endl;
      return;
    }
    else {
      cout<<fileName.at(i)<<" is loaded as Target!!"<<endl;
    }

    TH1F* hist_temp = (TH1F*)file0->Get(hist_name_i.at(i));

    if(!hist_temp) {
      cout<<"Couldn't find "<<hist_name_i.at(i)<<" in file : "<<fileName.at(i)<<endl;
      return;
    }
    else {
      cout<<hist_name_i.at(i)<<" Loaded!!"<<endl;
    }
    
    hist_temp->GetXaxis()->SetTitle(xtit);
    switch(i) {
      case 0 : hist_temp->SetName("CE-E Layer 3"); break;
      case 1 : hist_temp->SetName("CE-E Layer 2"); break;
      case 2 : hist_temp->SetName("CE-E Layer 1"); break;
      default : break;
    }
      
    hists.push_back(hist_temp);
    delete file0;
  }
  
  

  sprintf(tag,"Layer_comp_pion_%03dgev_%s_Axis",energy,axis);

 
  generate_1Dplot(hists,tag,energy,leg_head,normalize,log_flag,save_canvas,DoRebin);
}




void run_two(int energy, bool save_ = 0){
  
  run_one(energy,"X",1,0,save_,0);
  run_one(energy,"Y",1,0,save_,0);
  

  // run_one(energy,"raw","X",1,0,save_,0);
  // run_one(energy,"flipped","X",1,0,save_,0);
  // run_one(energy,"raw","Y",1,0,save_,0);
  // run_one(energy,"flipped","Y",1,0,save_,0);
}

void run_all_energy(bool save_ = 0){
  gROOT->SetBatch(1);
  const int n = 8;
  int e_list[n] = {20,50,80,100,120,200,250,300};
  for(int i = 0; i < n; i++) {
    run_two(e_list[i], save_);
  }
}

// void run_all_pl(const char* pl="", bool save_ = 0){
//   gROOT->SetBatch(1);
//   const int n = 8;
//   int e_list[n] = {20,50,80,100,120,200,250,300};
//   for(int i = 0; i < n; i++) {
//     run_two(e_list[i], pl, save_);
//   }
// }


