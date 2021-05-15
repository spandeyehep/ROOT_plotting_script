const int n_pl = 4;
bool logx = false;
TString pls[n_pl] = {"FTFP_BERT_EMN","QGSP_FTFP_BERT_EMN","FTFP_BERT_EMM","QGSP_BERT"};
TString dRs[9] = {"dR < 0.56cm","dR < 1.0cm","dR < 2.0cm","dR < 3.0cm","dR < 5.0cm","dR < 8.0cm","dR < 12.0cm","dR < 18.0cm","dR < 20.0cm"};
TString legend_text[9] = {"All events","Showering in CE-E","MIPs in CE-E","Pre-shower reject","Track-window selection","Channel Masking","Noise rejection","dR < 18.0cm","dR < 20.0cm"};

int line_width[10] = {3,2,2,1,1,1,1,1,1,1};
int line_style[10] = {2,1,1,1,1,1,1,1,1,1};
// /int line_color[n_pl+1] = {kBlack, kRed, kGreen+2, kBlue, kRed};
//int line_color[9] = {kBlack, kBlue, kRed, kGreen+2, kMagenta, kRed - 3, kBlue + 2 , kCyan + 1 , kGreen + 3 };
int line_color[10] = {kBlack, kBlue, kRed, kGreen+2, kMagenta, kYellow + 2 , kBlue + 2 , kCyan + 1 , kGreen + 3 , kOrange+1};

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
    
  x_max.insert(pair<int, int>(20,60.0));
  x_max.insert(pair<int, int>(50,150.0));
  x_max.insert(pair<int, int>(50,200.0));
  x_max.insert(pair<int, int>(100,250.0));
  x_max.insert(pair<int, int>(120,300.0));
  x_max.insert(pair<int, int>(200,500.0));
  x_max.insert(pair<int, int>(250,600.0));
  x_max.insert(pair<int, int>(300,700.0));
  
  x_min.insert(pair<int, int>(20,0.0));
  x_min.insert(pair<int, int>(50,0.0));
  x_min.insert(pair<int, int>(80,0.0));
  x_min.insert(pair<int, int>(100,0.0));
  x_min.insert(pair<int, int>(120,0.0));
  x_min.insert(pair<int, int>(200,0.0));
  x_min.insert(pair<int, int>(250,0.0));
  x_min.insert(pair<int, int>(300,0.0));
  
}





void generate_1Dplot(vector<TH1F*> hist, char const *tag_name="", int energy=-1, char const *leg_head="",
   bool normalize=true, bool log_flag=true, bool DoRebin=true, bool save_canvas=false){  
  

  TCanvas *c = new TCanvas(tag_name, tag_name, 600, 600);
  c->SetRightMargin(0.009);
  c->SetLeftMargin(0.11);
  c->SetTopMargin(0.05);

  //gStyle->SetOptStat(1111);
  gStyle->SetOptStat(0);
  //double pvt_x_min = 0.6;
  double pvt_x_min = 0.75;
  double pvt_x_max = 0.99;
  double pvt_y_min = 0.9;
  //double pvt_dely = 0.18;
  double pvt_dely = 0.15;
  //gStyle->SetOptStat(0);

  //gStyle->SetOptFit(0);
  vector<TString> legName;
  //TLegend *legend = new TLegend(0.65,0.95,0.99,0.75);
  std::string leg_head_str = leg_head;
  double x = 0.15;
  double y = 0.90;
  TLegend *legend;
  //legend = new TLegend(0.60,0.88,0.98,0.72);  
  legend = new TLegend(0.60,0.95,0.99,0.7);  
  legend->SetTextSize(0.035);
  

  TLegendEntry* leg_entry[9];
  float x_label_size = 0.025;
  double ymax = 0.0;
  double ymin = 1000.0;
  cout<<" hist.size() = "<<hist.size()<<endl;


  for(int i = 0; i < (int)hist.size(); i++) {
  	
    
    if(normalize) {
      	hist.at(i)->Scale(1.0/hist.at(i)->Integral());
      	hist.at(i)->GetYaxis()->SetTitle("Normalized");
    }
    else {
      hist.at(i)->GetYaxis()->SetTitle("Entries");
    }
    
    hist.at(i)->SetLineWidth(line_width[i]);
    
    hist.at(i)->SetLineStyle(line_style[i]);
    hist.at(i)->SetLineColor(line_color[i]);
    hist.at(i)->SetTitle("");
    
    hist.at(i)->GetXaxis()->SetTitleSize(0.04);
    hist.at(i)->GetXaxis()->SetLabelSize(x_label_size);
    hist.at(i)->GetXaxis()->SetLabelSize(0.030);
    hist.at(i)->GetYaxis()->SetLabelSize(0.030);
    hist.at(i)->GetYaxis()->SetTitleOffset(1.45);
    if(DoRebin && !logx) {
      hist.at(i)->Rebin(rebin_[energy]);
      //hist.at(i)->Rebin(1);
    }
    hist.at(i)->GetXaxis()->SetRangeUser(x_min[energy],x_max[energy]);
   	legName.push_back(hist.at(i)->GetName());
   	leg_entry[i] = legend->AddEntry(hist.at(i),legend_text[i].Data(),"l");
    leg_entry[i]->SetTextColor(hist.at(i)->GetLineColor());
    
   
	
  	if(hist.at(i)->GetMaximum() > ymax) ymax = hist.at(i)->GetMaximum();
  	if(hist.at(i)->GetMinimum() < ymin) ymin = hist.at(i)->GetMinimum();
     
    
    

  }

  if(ymin == 0.0) ymin = 1e-4;
  for(int i = 0; i < (int)hist.size(); i++) {
  	// if(!log_flag) hist.at(i)->GetYaxis()->SetRangeUser(0.0,ymax*1.3);
  	// else hist.at(i)->GetYaxis()->SetRangeUser(ymin,ymax*10);

  	if(!i) hist.at(i)->Draw("hist");
    else   hist.at(i)->Draw("hist sames");

  }
  
  legend->Draw();



  if(log_flag) {
      gPad->SetLogy();
    }
  if(logx)
    gPad->SetLogx();

  
  gPad->Update();

 
  TLatex* textOnTop = new TLatex();
  textOnTop->SetTextSize(0.035);
  textOnTop->DrawLatexNDC(0.12,0.96,"CMS #it{#bf{Preliminary}}");
  
  char* en_lat = new char[500];
  textOnTop->SetTextSize(0.035);
  sprintf(en_lat,"%d GeV/c, #pi^{-} beam",energy);
  textOnTop->DrawLatexNDC(0.6,0.96,en_lat);

 

  gPad->Modified();
  char* canvas_name = new char[1000];
  //c->Print(canvas_name);
  
  if(save_canvas) {
    // sprintf(canvas_name,"./plots/%s.png",tag_name);
    // c->SaveAs(canvas_name);
    
    sprintf(canvas_name,"./plots/%s_GeV_fixedWeight.pdf",tag_name);
    c->SaveAs(canvas_name);
    
  }
  
}


void run_one(int energy, bool normalize=false, bool log_flag = false,
         bool DoRebin = false, bool save_canvas = false){

  
  rebin_.clear();
  x_max.clear();
  char *tag = new char[200];
  char *leg_head = new char[200];

  // char* dir = new char[2000];
  // sprintf(dir,"/home/shubham/work/HGCAL/CERNTB/oct2018TB/octTB_plotting/withAHCAL/weight_scan/02Aug2020_chi2_calibrated/data");
  char* dir_name = new char[200];
  
  char* fname0 = new char[500];
  // char* f_name1 = new char[500];
  vector<TString> fileName;

  // char* version = new char[200];

  sprintf(fname0,"./data/data_pion%d_v16_v8_chi2method_3.root",energy);
  fileName.push_back(fname0);

  // sprintf(fname0,"./data/test%d.root",energy);
  // fileName.push_back(fname0);
    

  char* hist_name_1 = new char[100];
  char* hist_name_2 = new char[100];
  char *xtit = new char[200];
  char *hist_dir = new char[200];
  char *layer_text = new char[200];
  char *lt = new char[200];
  int pos = 0;
  char* SS_text = new char[200];


  sprintf(xtit,"Energy sum in HGCAL + AHCAL [GeV]");

  vector<TString> hist_list;
  sprintf(hist_name_1,"shower_energy_reco/h_inclusive_elecpi_scale");
  hist_list.push_back(hist_name_1);
  sprintf(hist_name_1,"shower_energy_reco/showering_in_EE/h_showerinEE_elecpi_scale");
  hist_list.push_back(hist_name_1);
  sprintf(hist_name_1,"shower_energy_reco/MIPs_in_EE/h_MIPsinEE_elecpi_scale");
  hist_list.push_back(hist_name_1);
  

  sprintf(leg_head,"#bf{leg_head}"); 
  
  rebin_init_layer_pi();

 
  vector<TH1F*> hists;
  TH1::AddDirectory(kFALSE);
  //fileName.size()
  //for(int i = 0; i < fileName.size(); i++) {
  for(int i = 0; i < hist_list.size(); i++) {
    TFile* file0 = TFile::Open(fileName.at(0),"read");
    //TFile* file0 = TFile::Open(fname0,"read");

    if(!file0) {
      cout<<"Couldn't find "<<fileName.at(0)<<endl;
      //cout<<"Couldn't find "<<fname0<<endl;
      return;
    }
    
    char* temp_histName = new char[2000];
    sprintf(temp_histName,"%s",(hist_list.at(i)).Data());

    TH1F* hist_temp = (TH1F*)file0->Get(temp_histName);

    if(!hist_temp) {
      cout<<"Couldn't find "<<temp_histName<<" in file"<<fname0<<endl;
      return;
    }
  	hist_temp->GetXaxis()->SetTitle(xtit);
    
   


  	hist_temp->SetName(dRs[i]);
    // if(!i) hist_temp->SetName("Data HGCv16_AHv8");
    // else hist_temp->SetName(pls[i-1]);
  
    hists.push_back(hist_temp);
    delete file0;
  }
   
  //cout<<"hist size = "<<hists.size()<<endl;
  
  sprintf(tag,"EventCategorization_%03dGeV",energy);
  generate_1Dplot(hists,tag,energy,leg_head,normalize,log_flag,DoRebin,save_canvas);

}



void run_all(bool save_ = false) {
  gROOT->SetBatch(1);
  run_one(20,0,0,1,save_);
  run_one(50,0,0,1,save_);
  run_one(80,0,0,1,save_);
  run_one(100,0,0,1,save_);
  run_one(120,0,0,1,save_);
  run_one(200,0,0,1,save_);
  run_one(250,0,0,1,save_);
  run_one(300,0,0,1,save_);
}


// void run_two(int energy, int SS, int layer, bool save_ = 0) {
//   run_one(energy,SS,layer,1,1,1,save_);
// }

// // void run_all_dR(int energy, int SS, int layer, bool save_ = 0) {
// // 	run_two(energy,SS,layer,2,save_);
// // 	run_two(energy,SS,layer,5,save_);
// // 	run_two(energy,SS,layer,8,save_);
// // 	run_two(energy,SS,layer,10,save_);
// // }


// void run_all_layers(int energy, int SS, bool save_ = 0) {

// 	gROOT->SetBatch(1);
// 	run_two(energy,SS,1,save_);
// 	run_two(energy,SS,8,save_);
// 	run_two(energy,SS,15,save_);
// 	run_two(energy,SS,22,save_);
// 	for(int i = 29; i <= 40; i++) {
//     	run_two(energy,SS,i,save_);
// 	}
// }



// void run_all_SS(int energy, bool save_ = 0) {

// 	gROOT->SetBatch(1);
//   	run_all_layers(energy,1,save_);
//   	run_all_layers(energy,8,save_);
//   	run_all_layers(energy,15,save_);
//   	run_all_layers(energy,22,save_);
// 	for(int i = 29; i <= 40; i++) {
//     	run_all_layers(energy,i,save_);
// 	}
// }


