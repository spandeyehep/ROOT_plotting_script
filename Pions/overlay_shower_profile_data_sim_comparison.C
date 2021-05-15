const int n_xy = 79;

double GetYmax(TProfile* tprofle_){
  int i = 0;
  float max_ = -1;
  while (i < tprofle_->GetNbinsX()) {
    if (max_ < tprofle_->GetBinContent(i))
      max_ = tprofle_->GetBinContent(i);
    i++;
  }
  return max_;
}

// std::vector<double*> getXY(TProfile* profile) {
//   double x[n_xy];
//   double y[n_xy];
//   // int x_j = 0;
//   // int y_j = 0;
//   std::vector<double*> temp;
//   int j = 0;
//   for(int i = 0; i < profile->GetNbinsX(); i++) {
//     if(profile->GetBinContent(i) != 0) {
//       x[j] = profile->GetBinCenter(i);
//       y[j] = profile->GetBinContent(i);
//       cout<<j<<"\t"<<x[j]<<"\t"<<y[j]<<endl;
//       j++;
//     }
//   }
//   temp.push_back(x);
//   temp.push_back(y);
//   return temp;
//   //cout<<j<<endl;
// }
double y_max = -1.0;
double y_min = 1.e5;

TGraphErrors* getXY(TProfile* profile) {
  double x[n_xy];
  double y[n_xy];
  double ex[n_xy];
  double ey[n_xy];
  // int x_j = 0;
  // int y_j = 0;
  //std::vector<double*> temp;
  int j = 0;
  for(int i = 0; i < profile->GetNbinsX(); i++) {
    if(profile->GetBinContent(i) != 0) {
      x[j] = profile->GetBinCenter(i);
      y[j] = profile->GetBinContent(i);
      ex[j] = 0.0;
      ey[j] = profile->GetBinError(i);
      if(y[j] > y_max) y_max = y[j];
      if(y[j] < y_min) y_min = y[j];
      //cout<<j<<"\t"<<x[j]<<"\t"<<y[j]<<"\t"<<profile->GetBinError(i)<<endl;
      j++;
    }
  }

  //cout<<"** y_min : y_max :: "<<y_min<<" : "<<y_max<<" **"<<endl;
  TGraphErrors* temp = new TGraphErrors(j, x, y, ex, ey);
  // temp.push_back(x);
  // temp.push_back(y);
  return temp;
  //cout<<j<<endl;
}


//////////////////////////////////////////////////////////////////////////
///                                                                   ///
///                             For Graphs Only                      ///
///                                                                  ///      
////////////////////////////////////////////////////////////////////////



// void overlay_shower_graph(int energy=-1, std::string profile_name="", bool save_canvas=false,
//                             std::string save_path="",std::string save_name=""){
void overlay_shower_graph(int energy=100, int SS_layer=1, int select=0, bool save_canvas=false){
  const int n = 4;
  bool log_flag = true;
  y_max = -1.0;
  y_min = 1.e5;

  //const char* physics_list = "FTFP_BERT_EMN";
  
  std::string legName[4] = {"Data ","FTFP_BERT_EMN","QGSP_FTFP_BERT_EMN","QGSP_FTFP_BERT_EML"};
  //std::string legName[4] = {"Data HGv16_AHv8","Sim [v46 noCorr]","Sim [v46 Corr]","QGSP_FTFP_BERT_EML"};


  char* dir_name = new char[200];
  // switch(select) {
  //     case 0 : sprintf(dir_name,"NoRescaling");  break;
  //     case 1 : sprintf(dir_name,"Rescaling4percent");  break;
  //     case 2 : sprintf(dir_name,"StandardRescaling");  break; 
  //     default: cout<<"Incorrect select switch...."<<endl; return;
  // }

  vector<TString> fileName;
  char* fname0 = new char[200];
  
  // sprintf(fname0,"./data/data_pion%03d_v16_v8.root",energy);
  // fileName.push_back(fname0);
  // sprintf(fname0,"./sim/sim_pion%03d_FTFP_BERT_EMN_v44_VtxBeam_v3_correctFH10.root",energy);  
  // fileName.push_back(fname0);
  // sprintf(fname0,"./sim/sim_pion%03d_QGSP_FTFP_BERT_EMN_v44_VtxBeam_v3_correctFH10.root",energy);  
  // fileName.push_back(fname0);

  sprintf(fname0,"./data/data_pion%03d_v16_v8.root",energy);
  fileName.push_back(fname0);
  //sprintf(fname0,"./sim/unscaled/sim_pion%03d_FTFP_BERT_EMN_v46_patchMIP.root",energy);
  sprintf(fname0,"./sim/scaled/sim_pion%03d_FTFP_BERT_EMN_v46_patchMIP.root",energy);
  fileName.push_back(fname0);
  sprintf(fname0,"./sim/scaled/sim_pion%03d_QGSP_FTFP_BERT_EMN_v46_patchMIP.root",energy);
  fileName.push_back(fname0);


  //float x_range[2] = {-0.5,5.5};
  float x_range[2] = {-0.5,10.0};
  float y_range[2] = {0.0001,1.5};
  //int point_col[5] = {kBlack, kRed,  kGreen+3, kBlue, kMagenta};
  int point_col[5] = {kBlack, kMagenta, kGreen+3, kBlue, kRed,};
  //int point_style[3] = {kFullCircle,kOpenSquare,kFullTriangleUp};
  int point_style[4] = {kFullCircle, kOpenSquare, kFullTriangleUp, kFullTriangleDown};
  float point_size[4] = {1.0, 0.6, 0.6, 0.6};

  switch(select) {
      case 0 : sprintf(dir_name,"mips"); y_range[0] = 0.1; y_range[1] = 1.5; break;
      case 1 : sprintf(dir_name,"gev"); y_range[0] = 0.5; y_range[1] = 1.5; break; 
      default: cout<<"Incorrect select switch...."<<endl; return;
  }

  std::string x_title = "#lambda_{int}";
  //std::string x_title = "Layer";
  std::string y_title = "Mean Energy Deposited [MIPs]";
  //bool save_canvas = false;
  vector<TGraphErrors*> graph_list;

  // gStyle->SetOptFit(0);
  // gStyle->SetOptStat(0);
  gStyle->SetPalette(53);
  // gStyle->SetErrorX(0.0001);
  //TCanvas* c = new TCanvas("c", "yolo", 600, 600);
  TCanvas* c = new TCanvas("c", "c", 800, 500);
  c->SetRightMargin(0.009);
  c->SetLeftMargin(0.11);
  c->SetTopMargin(0.05);
  TLegend* legend;
  if((int)fileName.size() == 1) {
    legend = new TLegend(0.70,0.95,0.99,0.85);
  }
  else {
    legend = new TLegend(0.68,0.95,0.99,0.75);
  }
  gStyle->SetOptFit(0);
  gStyle->SetOptStat(0);



  if(log_flag) {
    y_range[0] = 0.1;
    y_range[1] = 10.0;
    gPad->SetLogy();
  }

  
  std::vector<TProfile*> profile_list;
  float line_y_max = 0.0;

  for(int i = 0; i < (int)fileName.size(); i++) {
    
    TFile* file = TFile::Open(fileName.at(i));
    if(!file) {
      cout<<"Could not open "<<fileName.at(i)<<endl;
      return;
    }
    char *hname = new char[500]; 
    //sprintf(hname,"shower_profile_layer/%s",profile_name.c_str());
    switch(select) {
      case 0 : y_title = "<E> [MIPs]"; sprintf(hname,"shower_profile_lambdaPi/profile_SS/h_longi_profile_raw_SS_%02d",SS_layer); break;
      case 1 : y_title = "<E> [GeV]"; sprintf(hname,"shower_profile_lambdaPi/profile_SS/h_longi_profile_raw_gev_%02d",SS_layer); break;
      default: cout<<"Incorrect select switch...."<<endl; return;
    }
    //sprintf(hname,"shower_profile_layer/h_longi_profile_raw_SS_%02d_layer",SS_layer);
    TProfile* profile = (TProfile*)file->Get(hname);
    
    if(!profile) {
      cout<<"Profile "<<hname<<" not found in file "<<fileName.at(i)<<endl;
      return;
    }
    // std::vector<double*> xy = getXY(profile);
    // TGraph* temp = new TGraph(n_xy, xy.at(0), xy.at(1));

    
    TGraphErrors* temp = getXY(profile);

    temp->GetXaxis()->SetTitle(x_title.c_str());
    temp->SetTitle("");
    if(i == 0) {
      temp->GetXaxis()->SetRangeUser(x_range[0],x_range[1]);
      //temp->GetYaxis()->SetRangeUser(y_range[0],y_range[1]*GetYmax(profile));
      temp->GetYaxis()->SetRangeUser(y_range[0]*y_min,y_range[1]*y_max);
      //cout<<"y_min : y_max :: "<<(y_range[0]*y_min)<<" : "<<(y_range[1]*y_max)<<endl;
      //line_y_max = GetYmax(profile);
      line_y_max = y_max;
    }
    temp->GetXaxis()->SetTitleOffset(0.9);
    temp->GetXaxis()->SetTitleSize(0.05);
    temp->GetYaxis()->SetTitle(y_title.c_str());
    temp->GetYaxis()->SetTitleOffset(point_size[i]);
    temp->SetMarkerStyle(point_style[i]);
    temp->SetMarkerColor(point_col[i]);
    temp->SetLineWidth(2);
    temp->SetLineColor(point_col[i]);
    //temp->SetMarkerColorAlpha(point_col[i],0.05);
    temp->SetMarkerSize(point_size[i]);
    temp->SetLineStyle(1);
    temp->SetLineColor(point_col[i]);
    //temp->SetLineColorAlpha(point_col[i],0.01);
    //temp->SetLineWidth(2);
    TLegendEntry* l_;
    if(i == 0) 
      l_ = legend->AddEntry(temp,legName[i].c_str(),"pe");
    else
      l_ = legend->AddEntry(temp,legName[i].c_str(),"lp");
    l_->SetTextColor(temp->GetMarkerColor());

    graph_list.push_back(temp);
    //cout<< " For "<< file_list.at(i).c_str() << " j = "<< getXY(profile) << endl;

    //file->Delete();
    delete file;
  }

  for(int i = 0; i < (int)graph_list.size(); i++) {
    if(i == 0) {
      //tempe_list.at(i)->Draw("APE");
      graph_list.at(i)->Draw("APE");
    }
    else {
      //tempe_list.at(i)->Draw("e1");
      graph_list.at(i)->Draw("PL sames");
      //break;
    }
    //break;
  }

  
  //sprintf(header,"%d GeV pion",energy);
  //legend->SetHeader(header,"C");
  legend->SetTextSize(0.035);
  legend->Draw();


  char* header = new char[100];
  TLatex* latex = new TLatex();
  latex->SetNDC();
  
  latex->SetTextColor(kBlack);
  latex->SetTextAlign(13);
  latex->SetTextSize(0.045);
  sprintf(header,"#bf{E_{beam} =}  %d GeV",energy);
  latex->DrawLatex(0.15,.94,header);
  
  if(SS_layer <= 28)  sprintf(header,"#bf{FHI : CE-E layer %d}",SS_layer);
  else                sprintf(header,"#bf{FHI : CE-H layer %d}",SS_layer-28);
  latex->DrawLatex(0.4,.94,header);

  latex->SetTextSize(0.035);
  sprintf(header,"#bf{CMS #it{Preliminary}}");
  latex->DrawLatex(0.12,.99,header);
  sprintf(header,"#bf{HGCAL Oct2018 TB,#pi^{-} beam}");
  latex->DrawLatex(0.7,.99,header);


  //latex->DrawLatex(0.35,.94,physics_list);



  TLine *line = new TLine(1.60,0.0,1.60,line_y_max*1.35);
  line->SetLineStyle(2);
  line->SetLineWidth(4);
  line->SetLineColor(kBlack);
  line->Draw("SAME");
  TLine *line1 = new TLine(5.10,0.0,5.10,line_y_max*1.35);
  line1->SetLineStyle(2);
  line1->SetLineWidth(4);
  line1->SetLineColor(kBlack);
  line1->Draw("SAME");
  
  char* compart_ = new char[100];
  sprintf(compart_,"CE-E");

  //latex->SetTextColorAlpha(9, 0.476);
  //TLatex* tex = new TLatex(0.20,0.20,compart_);
  latex->SetTextColorAlpha(kBlue-1, 0.3);
  latex->SetTextSize(0.1);
  latex->SetTextAngle(20.0);
  latex->DrawLatex(0.11,.20,compart_);
  sprintf(compart_,"CE-H");
  latex->DrawLatex(0.35,.20,compart_);
  sprintf(compart_,"AHCAL");
  latex->DrawLatex(0.65,.20,compart_);
  //tex->Draw();

  gPad->SetGridx();
  gPad->SetGridy();
  c->Modified();

  char *canvas_name = new char[500];
  // switch(select) {
  //     case 0 : sprintf(dir_name,"mips");  break;
  //     case 1 : sprintf(dir_name,"gev");  break;
  //     default: cout<<"Incorrect select switch...."<<endl; return;
  // }
  sprintf(canvas_name,"plots/shower_shape_lambda_int_data_simulation_comparison/%03dGeV/%s/pion_%03d_SS%02d_lambdaInt_%s.png",energy,dir_name,energy,SS_layer,dir_name);
  
  cout<<"Canvas name= "<<canvas_name<<" \t SaveCanvas? = "<<save_canvas<<endl;
  if(save_canvas) {
    
    c->SaveAs(canvas_name);
    
  }
  //cout<<" End of the function !!!"<<endl;
}


//////////////////////////////////////////////////////////////////////////
///                                                                   ///
///                            Run all                               ///
///                                                                  ///      
////////////////////////////////////////////////////////////////////////

void run_graph_energy(int energy = 100, int select=0, bool save_canvas=false){
  gROOT->SetBatch(1);
  for (int i = 0; i < 40; i++) {
    overlay_shower_graph(energy,i+1,select,save_canvas);
    
  }
}

//////////////////////////////////////////////////////////////////////////
///                                                                   ///
///                            Run all                               ///
///                                                                  ///      
////////////////////////////////////////////////////////////////////////


void run_graph_all(bool save_canvas=false){
  int energy[8] = {20,50,80,100,120,200,250,300};
  gROOT->SetBatch(1);
  for (int i = 0; i < 8; i++) {
    run_graph_energy(energy[i],0,save_canvas);
    run_graph_energy(energy[i],1,save_canvas);
  }
}


