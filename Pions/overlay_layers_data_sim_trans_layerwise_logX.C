const int n_pl = 4;
bool logx = true;
TString pls[n_pl] = {"FTFP_BERT_EMN","QGSP_FTFP_BERT_EMN","FTFP_BERT_EMM","QGSP_BERT"};
TString dRs[9] = {"dR < 0.56cm","dR < 1.0cm","dR < 2.0cm","dR < 3.0cm","dR < 5.0cm","dR < 8.0cm","dR < 12.0cm","dR < 18.0cm","dR < 20.0cm"};

int line_width[10] = {1,1,1,1,1,1,1,1,1,1};
int line_style[10] = {1,1,1,1,1,1,1,1,1,1};
// /int line_color[n_pl+1] = {kBlack, kRed, kGreen+2, kBlue, kRed};
//int line_color[10] = {kBlack, kBlue, kGray +1, kGreen+2, kMagenta, kRed , kBlue + 2 , kCyan + 1 , kGreen + 3 , kOrange+1};

int line_color[10] = {kBlack, kMagenta, kGreen + 3, kBlue, kRed, kGreen+2, kGray +1 , kBlue + 2 , kCyan + 1  , kOrange+1};

std::map<int,int> rebin_;
std::map<int,float> x_max;
std::map<int,float> x_min;

float x0[] = { 1.00114 , 1.98059 , 2.91411 , 3.89356 , 4.82708 , 5.80653 , 6.74005 , 7.7195 , 8.65302 , 9.63247 ,
               10.566 , 11.5454 , 12.479 , 13.4584 , 14.3919 , 15.3714 , 16.3049 , 17.2844 , 18.2179 , 19.1973 ,
               20.1308 , 21.2774 , 22.211 , 23.3575 , 24.2911 , 25.5403 , 26.4738 , 27.7602 , 30.597 , 33.4725 ,
               36.348 , 39.2235 , 42.099 , 44.8892 , 48.7909 , 51.6664 , 54.5419 , 57.6129 , 60.6003 , 63.3922 , 
               65.415 , 66.4509 , 67.4867 , 68.5226 , 69.5584 , 70.5943 , 71.6301 , 72.666 , 73.7019 , 74.7377 , 
               75.7736 , 76.8094 , 77.8453 , 78.8811 , 79.917 , 80.9528 , 81.9887 , 83.0246 , 84.0604 , 85.0963 , 
               86.1321 , 87.168 , 88.2038 , 89.2397 , 90.2756 , 91.3114 , 92.3473 , 93.3831 , 94.419 , 95.4548 , 
               96.4907 , 97.5266 , 98.5624 , 99.5983 , 100.634 , 101.67 , 102.706 , 103.742 , 106.735};

float nuc_lambda[] = { 0.050461 , 0.11197 , 0.145689 , 0.207199 , 0.240918 , 0.302427 , 0.336146 , 0.397655 , 
                       0.431374 , 0.492884 , 0.526603 , 0.588112 , 0.621831 , 0.68334 , 0.717059 , 0.778569 , 
                       0.812288 , 0.873797 , 0.907516 , 0.969025 , 1.00274 , 1.07992 , 1.11364 , 1.19081 , 1.22453 , 
                       1.29668 , 1.3304 , 1.40402 , 1.70379 , 1.99845 , 2.2931 , 2.58776 , 2.88242 , 3.16908 , 
                       3.57123 , 3.86589 , 4.16055 , 4.45838 , 4.74838 , 5.0352 , 5.24158 , 5.3501 , 5.45863 , 
                       5.56716 , 5.67568 , 5.78421 , 5.89274 , 6.00127 , 6.10979 , 6.21832 , 6.32685 , 6.43537 , 
                       6.5439 , 6.65243 , 6.76096 , 6.86948 , 6.97801 , 7.08654 , 7.19506 , 7.30359 , 7.41212 , 
                       7.52065 , 7.62917 , 7.7377 , 7.84623 , 7.95475 , 8.06328 , 8.17181 , 8.28034 , 8.38886 , 
                       8.49739 , 8.60592 , 8.71444 , 8.82297 , 8.9315 , 9.04003 , 9.14855 , 9.25708 , 9.57073 };

void rebin_init_layer_pi(){
  rebin_.insert(pair<int, int>(20,2));
  rebin_.insert(pair<int, int>(50,2));
  rebin_.insert(pair<int, int>(100,2));
  rebin_.insert(pair<int, int>(120,4));
  rebin_.insert(pair<int, int>(200,2));
  rebin_.insert(pair<int, int>(250,4));
  rebin_.insert(pair<int, int>(300,2));
  x_max.insert(pair<int, int>(20,20.0));
  x_max.insert(pair<int, int>(50,20.0));
  x_max.insert(pair<int, int>(100,20.0));
  x_max.insert(pair<int, int>(120,20.0));
  x_max.insert(pair<int, int>(200,20.0));
  x_max.insert(pair<int, int>(250,20.0));
  x_max.insert(pair<int, int>(300,20.0));
  x_min.insert(pair<int, int>(20,0.0));
  x_min.insert(pair<int, int>(50,0.0));
  x_min.insert(pair<int, int>(100,0.0));
  x_min.insert(pair<int, int>(120,0.0));
  x_min.insert(pair<int, int>(200,0.0));
  x_min.insert(pair<int, int>(250,0.0));
  x_min.insert(pair<int, int>(300,0.0));
  
}

void rebin_init_log_pi(){
  rebin_.insert(pair<int, int>(20,4));
  rebin_.insert(pair<int, int>(50,4));
  rebin_.insert(pair<int, int>(100,4));
  rebin_.insert(pair<int, int>(120,4));
  rebin_.insert(pair<int, int>(200,4));
  rebin_.insert(pair<int, int>(250,4));
  rebin_.insert(pair<int, int>(300,4));
  x_max.insert(pair<int, int>(20,5.0));
  x_max.insert(pair<int, int>(50,5.0));
  x_max.insert(pair<int, int>(100,5.0));
  x_max.insert(pair<int, int>(120,5.0));
  x_max.insert(pair<int, int>(200,5.0));
  x_max.insert(pair<int, int>(250,5.0));
  x_max.insert(pair<int, int>(300,5.0));
  x_min.insert(pair<int, int>(20,-1.0));
  x_min.insert(pair<int, int>(50,-1.0));
  x_min.insert(pair<int, int>(100,-1.0));
  x_min.insert(pair<int, int>(120,-1.0));
  x_min.insert(pair<int, int>(200,-1.0));
  x_min.insert(pair<int, int>(250,-1.0));
  x_min.insert(pair<int, int>(300,-1.0));
  
}



void generate_1Dplot(vector<TH1F*> hist,char const *tag_name="", int energy=-1, int layer=1,char const *leg_head="",
   bool normalize=true, bool log_flag=true, bool DoRebin=true, int SS=1,  bool save_canvas=false){  
  

  // TCanvas *c = new TCanvas(tag_name, tag_name, 600, 600);
  // c->SetRightMargin(0.009);
  // c->SetLeftMargin(0.11);
  // c->SetTopMargin(0.05);

  TCanvas *c = new TCanvas(tag_name,tag_name,700,450);
  
  auto *p2 = new TPad("p2","p2",0.,0.0,1.,0.32); p2->Draw();
  p2->SetTopMargin(0.001);
  p2->SetBottomMargin(0.3);
  //p2->SetBottomMargin(0.15);
  p2->SetRightMargin(0.009);
  p2->SetLeftMargin(0.11);
  p2->SetGrid();

  //auto *p1 = new TPad("p1","p1",0.,0.3,1.,1.);  p1->Draw();
  auto *p1 = new TPad("p1","p1",0.,0.32,1.,1.);  p1->Draw();
  //p1->SetTopMargin(0.05);
  p1->SetBottomMargin(0.001);
  p1->SetRightMargin(0.009);
  p1->SetLeftMargin(0.11);
  p1->cd();
  p1->SetGrid();
  


  gStyle->SetOptStat(0);
  

  double pvt_x_min = 0.75;
  double pvt_x_max = 0.99;
  double pvt_y_min = 0.9;
  double pvt_dely = 0.15;
  
  vector<TString> legName;
  std::string leg_head_str = leg_head;
  double x = 0.15;
  double y = 0.90;
  TLegend *legend;
  //legend = new TLegend(0.60,0.88,0.98,0.72);  
  legend = new TLegend(0.12,0.25,0.45,0.05);  

  // if(layer <= 28 || layer >= 38)  legend = new TLegend(0.65,0.60,0.99,0.40);  
  // else legend = new TLegend(0.15,0.25,0.50,0.05);  

  legend->SetTextSize(0.055);
  

  TLegendEntry* leg_entry[10];
  float x_label_size = 0.035;
  double ymax = 0.0;
  double ymin = 1000.0;

  for(int i = 0; i < (int)hist.size(); i++) {

    if(normalize) {
      	hist.at(i)->Scale(1.0/hist.at(i)->Integral());
        //hist.at(i)->Scale(1.0/hist.at(i)->GetMaximum());
      	hist.at(i)->GetYaxis()->SetTitle("Normalized");
    }

    //hist.at(i)->SetLineWidth(line_width[i]);
    hist.at(i)->SetLineWidth(2);
    hist.at(i)->SetLineStyle(line_style[i]);
    hist.at(i)->SetLineColor(line_color[i]);
    hist.at(i)->SetTitle("");
    
    hist.at(i)->GetYaxis()->SetLabelSize(0.07);
    hist.at(i)->GetYaxis()->SetTitleSize(0.07);
    
    hist.at(i)->GetYaxis()->SetTitleOffset(0.8);
    
    if(DoRebin && !logx) {
      hist.at(i)->Rebin(rebin_[energy]);
      //hist.at(i)->Rebin(1);
    }
    

    if(layer <= 28) hist.at(i)->GetXaxis()->SetRangeUser(0.0,15.0);
    else hist.at(i)->GetXaxis()->SetRangeUser(0.0,40.0);
    //hist.at(i)->GetXaxis()->SetRangeUser(0.0,40.0);
    hist.at(i)->GetXaxis()->SetRangeUser(0.002,-1);
   
    if(!i) {
      legName.push_back(hist.at(i)->GetName());

      hist.at(i)->SetLineStyle(0);
      hist.at(i)->SetMarkerStyle(kFullCircle);
      hist.at(i)->SetLineColor(line_color[i]);
      hist.at(i)->SetMarkerColor(line_color[i]);
      hist.at(i)->SetMarkerSize(0.7);

      leg_entry[i] = legend->AddEntry(hist.at(i),legName[i],"pe");
      

      // leg_entry[i] = legend->AddEntry(hist.at(i),legName[i],"l");
      // leg_entry[i]->SetTextColor(hist.at(i)->GetLineColor());
    }
    else {
      legName.push_back(hist.at(i)->GetName());
      leg_entry[i] = legend->AddEntry(hist.at(i),legName[i],"l");
      leg_entry[i]->SetTextColor(hist.at(i)->GetLineColor());
    }

    // legName.push_back(dRs[i].Data());
    // leg_entry[i] = legend->AddEntry(hist.at(i),legName[i],"l");
    // leg_entry[i]->SetTextColor(hist.at(i)->GetLineColor());
	
	if(hist.at(i)->GetMaximum() > ymax) ymax = hist.at(i)->GetMaximum();
	if(hist.at(i)->GetMinimum() < ymin) ymin = hist.at(i)->GetMinimum();
   
    
    

  }

  vector<TH1F*> ratio_plots;

  if(ymin == 0.0) ymin = 1e-4;
  for(int i = 0; i < (int)hist.size(); i++) {

  	// if(!log_flag) hist.at(i)->GetYaxis()->SetRangeUser(0.0,ymax*1.1);
  	// else hist.at(i)->GetYaxis()->SetRangeUser(ymin,ymax*10);

  	if(!i) hist.at(i)->Draw("");
    else  {
      hist.at(i)->Draw("hist sames");
      TH1F* temp = (TH1F*) hist.at(i)->Clone();
      temp->Divide(hist.at(0));
      
      // temp->GetXaxis()->SetTitleSize(0.04);
      // temp->GetXaxis()->SetLabelSize(x_label_size);
      // temp->GetYaxis()->SetLabelSize(0.035);
      // temp->GetYaxis()->SetTitle("MC/Data");
      // temp->GetYaxis()->SetTitleOffset(1.45);
      // temp->GetYaxis()->SetRangeUser(0.0,2.0);

      temp->GetXaxis()->SetTitleSize(0.15);
      temp->GetXaxis()->SetLabelSize(0.15);
      temp->GetYaxis()->SetTitle("MC/Data");
      temp->GetYaxis()->SetLabelSize(0.15);
      temp->GetYaxis()->SetTitleSize(0.15);
      //temp->GetYaxis()->SetRangeUser(0.0,2.0);
      temp->GetYaxis()->SetRangeUser(0.5,1.5);


      temp->GetYaxis()->SetTitleOffset(0.3);
      temp->GetYaxis()->SetNdivisions(5);
      temp->GetYaxis()->CenterTitle();
      //temp->GetXaxis()->CenterTitle();

      ratio_plots.push_back(temp);
    } 


  }
  
  legend->Draw();
  //cout<<"YOLO"<<endl;


  if(log_flag) {
      gPad->SetLogy();
    }
  if(logx)
    gPad->SetLogx();


  gPad->Update();


  // for(int i = 0; i < (int)hist.size() && false ; i++) {
  //   TPaveStats *pv = (TPaveStats*)hist.at(i)->FindObject("stats");
  //   pv->SetTextColor(hist.at(i)->GetLineColor());
  //   pv->SetLineColor(hist.at(i)->GetLineColor());
  //   pv->SetX1NDC(pvt_x_min);  //x1 left start
  //   pv->SetX2NDC(pvt_x_max);  //x2  right end
  //   pv->SetY1NDC(pvt_y_min - i*pvt_dely);  //y1 top starting
  //   pv->SetY2NDC(pvt_y_min - (i+1)*pvt_dely); //y2 bottom ending
  // }
 
  TLatex* textOnTop = new TLatex();
  textOnTop->SetTextSize(0.07);
  textOnTop->DrawLatexNDC(0.12,0.92,"CMS #it{#bf{Preliminary}}");
  
  char* en_lat = new char[500];
  //textOnTop->SetTextSize(0.035);
  sprintf(en_lat,"%d GeV/c, #pi^{-} beam",energy);
  textOnTop->DrawLatexNDC(0.65,0.92,en_lat);

 
  char* en_lat1 = new char[200];
  sprintf(en_lat1,"#bf{Energy weighted distances at} %s",leg_head);
  //sprintf(en_lat1,"%s, #bf{%s}",leg_head,en_lat);

  textOnTop->SetTextSize(0.035);
  //textOnTop->DrawLatexNDC(x,y,leg_head);
  //textOnTop->DrawLatexNDC(x,y+0.01,en_lat1);
  
  char* SS_text = new char[200];
  if(SS <= 7) {
    sprintf(en_lat1,"#bf{(Shower start at CE-E layer = 01 to 07)}");
    sprintf(SS_text,"SS_01_07");
  }
  else if(SS <= 14) {
    sprintf(en_lat1,"#bf{(Shower start at CE-E layer = 08 to 14)}");
    sprintf(SS_text,"SS_08_14");
  }
  else if(SS <= 21) {
    sprintf(en_lat1,"#bf{(Shower start at CE-E layer = 15 to 21)}");
    sprintf(SS_text,"SS_15_21");
  }
  else if(SS <= 28) {
    sprintf(en_lat1,"#bf{(Shower start at CE-E layer = 22 to 28)}"); 
    sprintf(SS_text,"SS_22_28");
  }
  else {
    sprintf(en_lat1,"#bf{(Shower start at CE-H layer = %d)}",SS-28);
    sprintf(SS_text,"SS_%d",SS);
  }


  textOnTop->SetTextSize(0.07);
  //textOnTop->DrawLatexNDC(x+0.35,y+0.01,en_lat1);
  textOnTop->DrawLatexNDC(0.12,0.45,en_lat1);



  if(layer <= 28)  sprintf(en_lat1,"#bf{Comparison at CE-E layer = %d}",layer);
  else sprintf(en_lat1,"#bf{Comparison at layer CE-H layer = %d}",layer-28);
  textOnTop->SetTextSize(0.07);
  textOnTop->DrawLatexNDC(0.16,0.38,en_lat1);

  float del_x0 = x0[layer-1] - x0[SS-1];
  float del_lam = nuc_lambda[layer -1] - nuc_lambda[SS -1] ;

  sprintf(en_lat1,"#bf{(#DeltaX_{0} = %0.2f, #Delta#lambda = %0.2f)}",del_x0,del_lam);
  //textOnTop->DrawLatexNDC(x+0.45,y-0.07,en_lat1);
  textOnTop->DrawLatexNDC(0.20,0.30,en_lat1);

  // if(layer <= 28)  sprintf(en_lat1,"#bf{(#DeltaX_{0} = %0.2f, #Delta#lambda = %0.2f)}",layer,del_x0,del_lam);
  // else sprintf(en_lat1,"#bf{Comparison at layer CE-H layer = %d, (#DeltaX_{0} = %0.2f, #Delta#lambda = %0.2f)}",layer-28,del_x0,del_lam);

  p2->cd();
  for(int i = 0; i < ratio_plots.size(); i++) {
    if(!i) ratio_plots.at(i)->Draw();
    else ratio_plots.at(i)->Draw("same");
  }

  TLine *line1 = new TLine(0.0,1.0,40,1.0);
  line1->SetLineStyle(2);
  line1->SetLineWidth(3);
  line1->SetLineColor(kBlack);
  line1->Draw("SAME");

  
  if(logx)
    gPad->SetLogx();
  gPad->Modified();
  char* canvas_name = new char[1000];
  //c->Print(canvas_name);
  
  if(save_canvas) {
    
    sprintf(canvas_name,"./log_x/%03dGeV/%s/%s_L%02d_%dgev.png",energy,SS_text,SS_text,layer,energy);
    cout<<canvas_name<<endl;
    //cout<<" canvas name = "<<canvas_name<<endl;
    c->SaveAs(canvas_name);
    
  }
  
}


void run_one(int energy, int SS = 1, int layer = 1, bool normalize=false, bool log_flag = false,
         bool DoRebin = false, bool save_canvas = false){

  
  rebin_.clear();
  x_max.clear();
  char *tag = new char[200];
  char *leg_head = new char[200];

  char* dir = new char[2000];
  sprintf(dir,"/home/shubham/work/HGCAL/CERNTB/oct2018TB/octTB_plotting/withAHCAL/weight_scan/12_april_2021_transverse_shower_shape");
  char* dir_name = new char[1000];
  
  char* fname0 = new char[500];
  // char* f_name1 = new char[500];
  vector<TString> fileName;

  // char* version = new char[200];

  

  sprintf(fname0,"%s/data/data_pion%d_v16_v8.root",dir,energy);
  fileName.push_back(fname0);

  sprintf(fname0,"%s/sim/sim_pion%d_FTFP_BERT_EMN_v46_patchMIP.root",dir,energy);  
  fileName.push_back(fname0);
  sprintf(fname0,"%s/sim/sim_pion%d_QGSP_FTFP_BERT_EMN_v46_patchMIP.root",dir,energy);  
  fileName.push_back(fname0);

  // sprintf(fname0,"./sim/sim_pion%d_v46patchMIP_FTFP_BERT_EMN.root",energy);  
  // fileName.push_back(fname0);
  // sprintf(fname0,"./sim/sim_pion%d_v46patchMIP_QGSP_FTFP_BERT_EMN.root",energy);  
  // fileName.push_back(fname0);
  


  

  char* hist_name_1 = new char[1000];
  char* hist_name_2 = new char[100];
  char *xtit = new char[200];
  char *hist_dir = new char[200];
  char *layer_text = new char[200];
  
  int pos = 0;
  char* SS_text = new char[200];
  int x0_ref = -1;
  if(SS <= 7) {
    sprintf(SS_text,"SS_01_07");
    x0_ref = 1;
  }
  else if(SS <= 14) {
    sprintf(SS_text,"SS_08_14");
    x0_ref = 8;
  }
  else if(SS <= 21) {
    sprintf(SS_text,"SS_15_21"); 
    x0_ref = 15;
  }
  else if(SS <= 28) {
    sprintf(SS_text,"SS_22_28"); 
    x0_ref = 22;
  }
  else {
    sprintf(SS_text,"SS_%d",SS);  
    x0_ref = SS;
  }


  // if(layer <= 28) {
  // 	sprintf(layer_text,"CE-E layer = %d",layer);
  // 	//sprintf(layer_text,"CE-H layer = %d, Position %d,",layer,pos);
  // }
  // else if(layer >= 29 && layer <= 40) {
  //   sprintf(layer_text,"CE-H layer = %d",layer-28);
  // 	//sprintf(layer_text,"CE-H layer = %d, Position %d,",layer-28);	
  // 	//sprintf(layer_text,"CE-H layer = %d, Position %d,",layer,pos);
  // }
  // else {
  // 	sprintf(layer_text,"AHCAL layer = %d",layer-40);		
  // }

  //int layers[10] = {1,7,14,21,28,29,31,33,35,37};
  int layers[10] = {1,8,15,22,28,30,32,34,36,37};
 
  vector<TString> hist_list;
  sprintf(hist_dir,"transverse_inclusive/transverse_distance/distance_%s",SS_text);
  int l_index = 0.0;

  if(layer < SS ) {l_index++; cout<<"Not plotting layer < shower start layer"<<endl; return;}
  sprintf(hist_name_1,"%s/h_transverse_%s_L%02d_distance",hist_dir,SS_text,layer);
  hist_list.push_back(hist_name_1);


  

  // for(int i = 0; i < 10; i++) {
  //   if(layers[i] < SS ) {l_index++; continue;}
  //   sprintf(hist_name_1,"h_transverse_%s_L%02d_distance",SS_text,layers[i]);
  //   hist_list.push_back(hist_name_1);  
  // }
  
  

  sprintf(leg_head,"#bf{%s}",layer_text); 
  
  rebin_init_layer_pi();

 
  vector<TH1F*> hists;
  TH1::AddDirectory(kFALSE);
  //fileName.size()
  for(int i = 0; i < fileName.size(); i++) {
    TFile* file0 = TFile::Open(fileName.at(i),"read");
    //TFile* file0 = TFile::Open(fname0,"read");

    if(!file0) {
      cout<<"Couldn't find "<<fileName.at(i)<<endl;
      //cout<<"Couldn't find "<<fname0<<endl;
      return;
    }
    
    char* temp_histName = new char[2000];
    //sprintf(temp_histName,"%s/%s",hist_dir,hist_list[i].Data());
    sprintf(temp_histName,"%s",hist_list[0].Data());

    TH1F* hist_temp = (TH1F*)file0->Get(temp_histName);
    
    if(!hist_temp) {
      cout<<"Couldn't find "<<temp_histName<<" in file"<<fname0<<endl;
      return;
    }
    
  	hist_temp->GetXaxis()->SetTitle("Energy weighted distance from CoG dR [cm]");
   

    

    // if(!i) hist_temp->SetName("Data HGCv16_AHv8");
    // else hist_temp->SetName(pls[i-1]);
    
   
    

    if(!i) hist_temp->SetName("Data");
    else   hist_temp->SetName(pls[i-1].Data());

    // if(!i) hist_temp->SetName("Data HGCv16_AHv8");
    // else hist_temp->SetName(pls[i-1]);
 
    hists.push_back(hist_temp);
    // cout<<"CHECK i = "<<i<<endl;
    delete file0;
    
  }
   

  cout<<" hists.size() => "<<hists.size()<<endl;
  
  sprintf(tag,"transverse_%03dGeV_%s",energy,SS_text);

  generate_1Dplot(hists,tag,energy,layer,leg_head,normalize,log_flag,DoRebin,SS,save_canvas);

}





void run_two(int energy, int SS, int layer, bool save_ = 0) {
  //energy, SS , normalize, log_flag, DoRebin , save_canvas
  run_one(energy,SS,layer,1,1,1,save_);
}


void run_all_layers(int energy=100, int SS=1, bool save_ = false) {
  gROOT->SetBatch(1);
  for(int i = 1; i <= 40; i++) {
    if(i < SS) continue;
    run_two(energy,SS,i,save_);
  }

}

void run_all_SS(int energy, bool save_ = 0) {

  gROOT->SetBatch(1);
  run_all_layers(energy,1,save_);
  run_all_layers(energy,8,save_);
  run_all_layers(energy,15,save_);
  run_all_layers(energy,22,save_);
  for(int i = 29; i <= 37; i++) {
      run_all_layers(energy,i,save_);
  }
}



void run_all_energy(bool save_ = 0) {
  gROOT->SetBatch(1);

  run_all_SS(20,save_);
  run_all_SS(50,save_);
  run_all_SS(80,save_);
  run_all_SS(100,save_);
  run_all_SS(120,save_);
  run_all_SS(200,save_);
  run_all_SS(250,save_);
  run_all_SS(300,save_);

}

