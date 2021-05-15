const int n_pl = 4;
bool logx = false;
//TString pls[n_pl] = {"FTFP_BERT_EMN","QGSP_FTFP_BERT_EMN","FTFP_BERT_EMM","QGSP_BERT"};
//TString pls[n_pl] = {"sim no rescaling","sim 4% MIP rescaled","sim standard rescaling","QGSP_BERT"};
TString pls[n_pl] = {"v46 noCorr","v46 Corr","sim standard rescaling","QGSP_BERT"};
int line_color[n_pl+1] = {kBlack, kBlue, kRed, kGreen+2, kMagenta};

int line_width[n_pl+1] = {1,2,2,1,1};
int line_style[n_pl+1] = {1,1,1,1,1};
//int line_color[n_pl+1] = {kBlack, kMagenta, kGreen+2, kBlue, kRed};


std::map<int,int> rebin_;
std::map<int,float> x_max;
void rebin_init_EE(){
  rebin_.insert(pair<int, int>(20,4));
  rebin_.insert(pair<int, int>(50,4));
  rebin_.insert(pair<int, int>(80,4));
  rebin_.insert(pair<int, int>(100,4));
  rebin_.insert(pair<int, int>(120,4));
  rebin_.insert(pair<int, int>(200,8));
  rebin_.insert(pair<int, int>(250,8));
  rebin_.insert(pair<int, int>(300,8));
  x_max.insert(pair<int, int>(20,3000.0));
  x_max.insert(pair<int, int>(50,6500.0));
  x_max.insert(pair<int, int>(80,10000.0));
  x_max.insert(pair<int, int>(100,12000.0));
  x_max.insert(pair<int, int>(120,16000.0));
  x_max.insert(pair<int, int>(200,25000.0));
  x_max.insert(pair<int, int>(250,30000.0));
  x_max.insert(pair<int, int>(300,35000.0));
  cout<<" :: rebin_init_EE ::"<<endl;
}
void rebin_init_FH(){

  rebin_.insert(pair<int, int>(20,2));
  rebin_.insert(pair<int, int>(50,2));
  rebin_.insert(pair<int, int>(80,1));
  rebin_.insert(pair<int, int>(100,1));
  rebin_.insert(pair<int, int>(120,1));
  rebin_.insert(pair<int, int>(200,2));
  rebin_.insert(pair<int, int>(250,2));
  rebin_.insert(pair<int, int>(300,2));
  x_max.insert(pair<int, int>(20,1500.0));
  x_max.insert(pair<int, int>(50,2500.0));
  x_max.insert(pair<int, int>(80,3000.0));
  x_max.insert(pair<int, int>(100,5000.0));
  x_max.insert(pair<int, int>(120,4200.0));
  x_max.insert(pair<int, int>(200,6000.0));
  x_max.insert(pair<int, int>(250,8000.0));
  x_max.insert(pair<int, int>(300,9000.0));
  cout<<" :: rebin_init_FH ::"<<endl;   
}


void rebin_init_FH_1(){

  rebin_.insert(pair<int, int>(20,2));
  rebin_.insert(pair<int, int>(50,2));
  rebin_.insert(pair<int, int>(80,2));
  rebin_.insert(pair<int, int>(100,2));
  rebin_.insert(pair<int, int>(120,2));
  rebin_.insert(pair<int, int>(200,2));
  rebin_.insert(pair<int, int>(250,2));
  rebin_.insert(pair<int, int>(300,2));
  x_max.insert(pair<int, int>(20,-1.0));
  x_max.insert(pair<int, int>(50,-1.0));
  x_max.insert(pair<int, int>(80,-1.0));
  x_max.insert(pair<int, int>(100,-1.0));
  x_max.insert(pair<int, int>(120,-1.0));
  x_max.insert(pair<int, int>(200,-1.0));
  x_max.insert(pair<int, int>(250,-1.0));
  x_max.insert(pair<int, int>(300,-1.0));
  cout<<" :: rebin_init_FH_1 ::"<<endl;   
}



void rebin_init_AH(){

  rebin_.insert(pair<int, int>(20,2));
  rebin_.insert(pair<int, int>(50,2));
  rebin_.insert(pair<int, int>(80,2));
  rebin_.insert(pair<int, int>(100,2));
  rebin_.insert(pair<int, int>(120,2));
  rebin_.insert(pair<int, int>(200,2));
  rebin_.insert(pair<int, int>(250,2));
  rebin_.insert(pair<int, int>(300,2));
  x_max.insert(pair<int, int>(20,1500.0));
  x_max.insert(pair<int, int>(50,3500.0));
  x_max.insert(pair<int, int>(80,5000.0));
  x_max.insert(pair<int, int>(100,6000.0));
  x_max.insert(pair<int, int>(120,8000.0));
  x_max.insert(pair<int, int>(200,12000.0));
  x_max.insert(pair<int, int>(250,15000.0));
  x_max.insert(pair<int, int>(300,17000.0));
  // cout<<" :: rebin_init_AH ::"<<endl;   
}

void generate_1Dplot(vector<TH1F*> hist, char const *tag_name="", char const *physics_list="", int energy=-1, char const *leg_head="",
   bool normalize=true, bool log_flag=true, bool DoRebin=true, bool save_canvas=false){  
  

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
  //gStyle->SetOptStat(0);

  //gStyle->SetOptFit(0);
  vector<TString> legName;
  //TLegend *legend = new TLegend(0.65,0.95,0.99,0.75);
  std::string leg_head_str = leg_head;
  double x = 0.2;
  double y = 0.91;

  double pvt_x_min = 0.68;
  double pvt_x_max = 0.99;
  double pvt_y_min = 0.95;
  double pvt_dely = 0.18;
  
  TLegend *legend;
  
  //TLegend *legend =  new TLegend(0.62,0.88,0.98,0.70);
  bool leg_down = false;

  if(((string)leg_head).find("Showering") != std::string::npos && ((string)hist[0]->GetXaxis()->GetTitle()).find("CE-E") != std::string::npos) leg_down = true;
  if(((string)leg_head).find("MIPs") != std::string::npos && ((string)hist[0]->GetXaxis()->GetTitle()).find("CE-H") != std::string::npos && (energy >= 80)) leg_down = true;

  if(leg_down) legend =  new TLegend(0.15,0.45,0.51,0.27);
  else legend =  new TLegend(0.58,0.95,0.99,0.80);

  // if(((string)leg_head).find("MIPs") != std::string::npos && ((string)hist[0]->GetXaxis()->GetTitle()).find("CE-H") != std::string::npos) {
  //   legend =  new TLegend(0.15,0.45,0.51,0.27);
  // }
  // else {
  //   legend =  new TLegend(0.62,0.88,0.98,0.70);
  // }


  if(((string)leg_head).find("Showering") != std::string::npos && ((string)hist[0]->GetXaxis()->GetTitle()).find("CE-E") != std::string::npos) {
    pvt_x_min = 0.15; pvt_x_max = 0.55; pvt_y_min = 0.65;
  }
  if(((string)leg_head).find("MIPs") != std::string::npos) {
    pvt_x_min = 0.75; pvt_dely = 0.13;
  }

  // if((leg_head_str.find("CE-H") != std::string::npos && energy > 50) || logx) {
  //  //legend = new TLegend(0.15,0.45,0.59,0.17);
  //   if(logx) {
  //     if((leg_head_str.find("CE-E") != std::string::npos && (energy == 20 || energy == 50))) {
  //       if (energy == 20) { legend = new TLegend(0.12,0.90,0.59,0.72); x = 0.4; y = 0.92; legend->SetTextSize(0.032);}
  //       else { legend = new TLegend(0.15,0.90,0.55,0.72); legend->SetTextSize(0.028);  x = 0.4; y = 0.92;}
  //     }
  //     else {
  //       legend = new TLegend(0.16,0.35,0.61,0.17); x = 0.42; y = 0.40; legend->SetTextSize(0.032);
  //     }
  //   }
  //   else {legend = new TLegend(0.16,0.35,0.61,0.17); legend->SetTextSize(0.032);}
  // }
  // else {
  //  //legend = new TLegend(0.55,0.88,0.98,0.65); 
  //  legend = new TLegend(0.50,0.88,0.98,0.7);  legend->SetTextSize(0.032);
  // }
  
  TLegendEntry* leg_entry[n_pl+1];
  float x_label_size = 0.025;
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
    hist.at(i)->GetYaxis()->SetLabelSize(0.035);
    hist.at(i)->GetYaxis()->SetTitleOffset(1.45);
    if(DoRebin && !logx) {
      hist.at(i)->Rebin(rebin_[energy]);
    }
    if(!logx) {
      hist.at(i)->GetXaxis()->SetRangeUser(0.0,x_max[energy]);
    }
    
    if(!i) {
      //legName.push_back("Data v16_v8");
      legName.push_back(hist.at(i)->GetName());
      hist.at(i)->SetLineWidth(1);
      hist.at(i)->SetMarkerColor(line_color[i]);
      hist.at(i)->SetMarkerSize(0.8);
      hist.at(i)->SetMarkerStyle(kFullCircle);
      leg_entry[i] = legend->AddEntry(hist.at(i),legName[i],"pe");
      leg_entry[i]->SetTextColor(hist.at(i)->GetLineColor());
    }
    else {
      //legName.push_back(pls[i-1].Data());
      legName.push_back(hist.at(i)->GetName());
      leg_entry[i] = legend->AddEntry(hist.at(i),legName[i],"l");
      leg_entry[i]->SetTextColor(hist.at(i)->GetLineColor());
    }

    // leg_entry[i] = legend->AddEntry(hist.at(i),legName[i],"l");
    // leg_entry[i]->SetTextColor(hist.at(i)->GetLineColor());

    if(!i) hist.at(i)->Draw("");//hist.at(i)->Draw("hist");
    else   hist.at(i)->Draw("hist sames");
  }

  legend->Draw();



  if(log_flag) gPad->SetLogy();
  if(logx) gPad->SetLogx();


  gPad->Update();
 
   
  char* latex_text = new char[200];
  

  TLatex* textOnTop = new TLatex();
  textOnTop->SetTextSize(0.035);
  textOnTop->DrawLatexNDC(0.12,0.96,"CMS #it{#bf{Preliminary}}");
  textOnTop->SetTextSize(0.035);
  textOnTop->DrawLatexNDC(0.70,0.96,leg_head);
  //textOnTop->DrawLatexNDC(x,y,leg_head);

  textOnTop->SetTextSize(0.03);
  // sprintf(latex_text,"#bf{Sim = %s}",physics_list);
  // textOnTop->DrawLatexNDC(0.15,0.92,latex_text);


  char* compart_ = new char[100];
  if(((string)hist[0]->GetXaxis()->GetTitle()).find("CE-E") != std::string::npos)  sprintf(compart_,"CE-E");
  else if(((string)hist[0]->GetXaxis()->GetTitle()).find("CE-H") != std::string::npos)  sprintf(compart_,"CE-H");
  else if(((string)hist[0]->GetXaxis()->GetTitle()).find("AHCAL") != std::string::npos)  sprintf(compart_,"AHCAL");
  else sprintf(compart_," ");
  //latex->SetTextColorAlpha(9, 0.476);
  //TLatex* tex = new TLatex(0.20,0.20,compart_);
  TLatex* latex = new TLatex();
  latex->SetNDC();
  latex->SetTextColorAlpha(kBlue-1, 0.3);
  latex->SetTextSize(0.2);
  //latex->SetTextAngle(20.0);
  latex->DrawLatex(0.2,.40,compart_);



  gPad->Modified();
  char* canvas_name = new char[2000];
  char* dir_name = new char[200];
  sprintf(dir_name,".");
  
  if(save_canvas) {

    sprintf(canvas_name,"./plots/unweighted/%s/%s_%s.png",physics_list,tag_name,physics_list);
    cout<<"Canvas Name ="<<canvas_name<<endl;
    c->SaveAs(canvas_name);
    sprintf(canvas_name,"./plots/unweighted/pdf/%s/%s_%s.pdf",physics_list,tag_name,physics_list);
    cout<<"Canvas Name ="<<canvas_name<<endl;
    c->SaveAs(canvas_name);

  }
  
}

void run_one(int energy, const char* hist_="", const char* physics_list="", bool normalize=false, bool log_flag = false,  bool DoRebin = false,
       bool save_canvas = false){

  
  rebin_.clear();
  x_max.clear();
  char *tag = new char[200];
  char *leg_head = new char[200];

 
  char* fname0 = new char[5000];
  // char* f_name1 = new char[500];
  vector<TString> fileName;
  

  char* base_dir = new char[1000];
  sprintf(base_dir,"/home/shubham/work/HGCAL/CERNTB/oct2018TB/octTB_plotting/withAHCAL/weight_scan/22_feb_2021_scaling_noscaling_shower_shapes");

  vector<TString> legendName;  
  char* legendName_tmp = new char[100];

  sprintf(fname0,"%s/data/data_pion%03d_v16_v8.root",base_dir,energy);
  fileName.push_back(fname0);

  sprintf(fname0,"%s/sim/unscaled/sim_pion%03d_%s_v46_patchMIP.root",base_dir,energy,physics_list);
  fileName.push_back(fname0);
  sprintf(fname0,"%s/sim/scaled/sim_pion%03d_%s_v46_patchMIP.root",base_dir,energy,physics_list);
  fileName.push_back(fname0);


  sprintf(legendName_tmp,"Data");
  legendName.push_back(legendName_tmp);
  sprintf(legendName_tmp,"%s noCorr",physics_list);
  legendName.push_back(legendName_tmp);
  sprintf(legendName_tmp,"%s Corr",physics_list);
  legendName.push_back(legendName_tmp);
  // sprintf(fname0,"./data/data_test%03d.root",energy);
  // fileName.push_back(fname0);
  // sprintf(fname0,"./sim/sim_test%3d_v44.root",energy);
  // fileName.push_back(fname0);
  // sprintf(fname0,"./sim/sim_test%3d_v46.root",energy);
  // fileName.push_back(fname0);
  
  char* hist_name_1 = new char[100];
  char* hist_name_2 = new char[100];
  

  
  sprintf(leg_head,"#bf{%d GeV/C #pi^{-} beam}",energy);
  char *xtit = new char[200];
 
  if(!strcmp(hist_,"EE")) {
    sprintf(hist_name_1,"h_rechit_energy_raw_EE");
    
    sprintf(xtit,"CE-E Energy sum [MIPs]");
    rebin_init_EE();
  }
  else if(!strcmp(hist_,"FH")) {
    sprintf(hist_name_1,"h_rechit_energy_raw_FH");
    
    sprintf(xtit,"CE-H Energy sum [MIPs]");
    rebin_init_FH();
  }
  else if(!strcmp(hist_,"AH")) {
    sprintf(hist_name_1,"h_rechit_energy_raw_AH");
    
    sprintf(xtit,"AHCAL Energy sum [MIPs]");
    rebin_init_AH();
  }
  else if(!strcmp(hist_,"all")) {
    sprintf(hist_name_1,"h_rechit_energy_raw_all");
    
    sprintf(xtit,"HGCAL + AHCAL Energy sum [MIPs]");
    rebin_init_EE();
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
    hist_temp->GetXaxis()->SetTitle(xtit);
    
    // if(!i) hist_temp->SetName("Data OctTB");
    // else hist_temp->SetName(pls[i-1]);
    hist_temp->SetName(legendName[i]);
    
  
    hists.push_back(hist_temp);
  }
  
  

  sprintf(tag,"data_sim_comp_pion_%03dgev_%s",energy,hist_);

 
  generate_1Dplot(hists,tag,physics_list,energy,leg_head,normalize,log_flag,DoRebin,save_canvas);
}



void run_four(int energy, const char* physics_list="", bool save_ = 0) {
	run_one(energy,"EE",physics_list,1,1,1,save_);
	run_one(energy,"FH",physics_list,1,1,1,save_);
	run_one(energy,"AH",physics_list,1,1,1,save_);
	//run_one(energy,"all",physics_list,1,1,1,save_);

}

// void run_two(int energy, const char* reg="", const char* physics_list="", bool save_ = 0){
//   if(!strcmp(reg,"EE")) {
//     run_one(energy,"EE_1",1,1,save_,1,physics_list);
//     run_one(energy,"EE_2",1,1,save_,1,physics_list);
//     //run_one(energy,"EE_3",1,1,save_,1);  
//   }
//   else if(!strcmp(reg,"FH")) {
//     run_one(energy,"FH_1",1,1,save_,1,physics_list);
//     run_one(energy,"FH_2",1,1,save_,1,physics_list);
//     //run_one(energy,"FH_3",1,1,save_,1);
//   }
//   else {
//     cout<<"Incorrect hist_name provided"<<endl;
//     return;
//   }
// }



void run_all_energy(const char* physics_list="", bool save_ = 0){
  gROOT->SetBatch(1);
  const int n = 8;
  int e_list[n] = {20,50,80,100,120,200,250,300};
  //int e_list[n] = {50,100};
  for(int i = 0; i < n; i++) {
    run_four(e_list[i], physics_list, save_);
    run_four(e_list[i], physics_list, save_);
   
  }
}



