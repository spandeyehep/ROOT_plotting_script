void generate_1Dplot(TH1F* hist,char const *htit,char const *run, bool log_flag=false,char const *hname=""){
  //TCanvas *c = new TCanvas(htit, htit, 400, 250);
  TCanvas *c = new TCanvas(htit, htit, 300, 300);
  gStyle->SetOptStat(1111);
  //hist->Scale(1.0/hist->Integral());
  hist->SetLineWidth(2);
  hist->SetLineStyle(1);
  hist->GetXaxis()->SetTitleSize(0.05);
  hist->GetXaxis()->SetLabelSize(0.05);
  hist->GetYaxis()->SetLabelSize(0.05);

  if(log_flag) {
    gPad->SetLogy();
  }

  
  hist->Draw();
  gPad->Update();

  hist->SetTitle(0);

  if(strcmp(hname,"dR_min")==0) {
    hist->SetName("min(dR)");
    hist->GetXaxis()->SetTitle("min(dR) in cm");
  }
  if(strcmp(hname,"nrechit")==0){
    hist->SetName("nRecHit");
    hist->GetXaxis()->SetTitle("nRechits");
    //hist->GetXaxis()->SetRangeUser(0,35);
  }

  TPaveStats *s = (TPaveStats*) gPad->GetPrimitive("stats");
  s->SetX1NDC(0.45);                                                                                                                       
  s->SetY1NDC(0.9);                                                                                                                       
  s->SetX2NDC(0.9);                                                                                                                       
  s->SetY2NDC(0.6);       
  gPad->Update();


  
  char* sname = new char[200];
  sprintf(sname,"%s/%s_%s.gif",run,htit,run);
  c->Print(sname);
  
}

void generate_2Dplot(TH2F* hist,char const *htit,char const *run, bool log_flag=false){
  TCanvas *c = new TCanvas(htit, htit, 300, 250);
  //TCanvas *c = new TCanvas(htit, htit, 400, 250);
  gStyle->SetOptStat(0);
  c->SetRightMargin(0.15);
  hist->GetXaxis()->SetTitleSize(0.06);
  hist->GetYaxis()->SetTitleSize(0.06);
  hist->GetXaxis()->SetLabelSize(0.055);
  hist->GetYaxis()->SetLabelSize(0.055);

  hist->GetXaxis()->SetTitleOffset(0.8);
  hist->GetYaxis()->SetTitleOffset(0.7);
  // hist->GetZaxis()->SetTitleOffset(0.5);
  hist->SetTitle(0);

  if(log_flag) {
    gPad->SetLogz();
  }

    
  hist->Draw("colz");
  gPad->Update();


   // TPaletteAxis *palette = (TPaletteAxis*)hist->GetListOfFunctions()->FindObject("palette");
   // palette->SetX1NDC(0.9);
   // palette->SetX2NDC(0.95);
   // palette->SetY1NDC(0.2);
   // palette->SetY2NDC(0.8);
   // c->Modified();
   // c->Update();

  
  char* sname = new char[200];
  sprintf(sname,"%s/%s_%s.gif",run,htit,run);
  c->Print(sname);
  
}

void generate_plots(char const *fname1,char const *run){

  TFile *file0 = TFile::Open(fname1);
  if(!file0) {
    cout<<"Can't find file = "<<fname1<<endl;
    return;
  }

  char* hname = new char[200];
  char* htit = new char[200];
  TH1F* temp1D;
  TH2F* temp2D;
  // int i = 0;
  // sprintf(hname,"Layer_%d/h_deltaR_min_layer%d",i,i+1);
  // cout<<"histname="<<hname<<endl;
  // sprintf(htit,"h_deltaR_min_layer%d",i+1);
  // cout<<"htit="<<htit<<endl;
  // temp1D = (TH1F*)file0->Get(hname);
  // if(!temp1D) {
  //   cout<<"Can't find histogram = "<<hname<<endl;
  //   return;
  // }
  // generate_1Dplot(temp1D,htit);
  //delete temp1D;

  char* hh = new char[100];

  for(int i = 0; i<28; i++) {
    sprintf(hname,"Layer_%d/h_deltaR_min_layer%d",i,i+1);
    sprintf(htit,"h_deltaR_min_layer%d",i+1);
    temp1D = (TH1F*)file0->Get(hname);
    sprintf(hh,"dR_min");
    //generate_1Dplot(temp1D,htit,run,false,"dR_min");
    generate_1Dplot(temp1D,htit,run,false,hh);
    //delete temp1D;
    //    return;

    
    sprintf(hname,"Layer_%d/h_nrechits_layer%d",i,i+1);
    sprintf(htit,"h_nrechits_layer%d",i+1);
    temp1D = (TH1F*)file0->Get(hname);
    sprintf(hh,"nrechit");
    generate_1Dplot(temp1D,htit,run,true,hh);
    //delete temp1D;
    
      
    sprintf(hname,"Layer_%d/h_rechitXY_layer%d",i,i+1);
    sprintf(htit,"h_rechitXY_layer%d",i+1);
    temp2D = (TH2F*)file0->Get(hname);
    generate_2Dplot(temp2D,htit,run,false);
    //delete temp2D;


    sprintf(hname,"Layer_%d/h_trackXY_layer%d",i,i+1);
    sprintf(htit,"h_trackXY_layer%d",i+1);
    temp2D = (TH2F*)file0->Get(hname);
    generate_2Dplot(temp2D,htit,run,false);
    //delete temp2D;
    
    sprintf(hname,"Layer_%d/h_trackX_rechitX_layer%d",i,i+1);
    sprintf(htit,"h_trackX_rechitX_layer%d",i+1);
    temp2D = (TH2F*)file0->Get(hname);
    generate_2Dplot(temp2D,htit,run,false);
    //delete temp2D;


    sprintf(hname,"Layer_%d/h_trackY_rechitY_layer%d",i,i+1);
    sprintf(htit,"h_trackY_rechitY_layer%d",i+1);
    temp2D = (TH2F*)file0->Get(hname);
    generate_2Dplot(temp2D,htit,run,false);
    //delete temp2D;


    sprintf(hname,"Layer_%d/h_dXY_layer%d",i,i+1);
    sprintf(htit,"h_dXY_layer%d",i+1);
    temp2D = (TH2F*)file0->Get(hname);
    generate_2Dplot(temp2D,htit,run,true);
    //delete temp2D;

    //return;
    }

}

void plot2D(char const *fname1, char const *h_name ,int layer) { //, char const *h_tit, char const *h_name,) {
  
  TFile *file0 = TFile::Open(fname1);
  if(!file0) {
    cout<<"Can't find file = "<<fname1<<endl;
    return;
  }
  char* dname = new char[200];
  sprintf(dname,"ADC_distributions/Layer_%d/%s",layer-1,h_name);
  TH2F* hist = (TH2F*)file0->Get(dname);
  //TCanvas *c = new TCanvas(htit, htit, 300, 250);
  TCanvas *c = new TCanvas("c", "c", 300, 250);  
  //TCanvas *c = new TCanvas(htit, htit, 400, 250);
  gStyle->SetOptStat(0);
  c->SetRightMargin(0.15);
  hist->GetXaxis()->SetTitleSize(0.06);
  hist->GetYaxis()->SetTitleSize(0.06);
  hist->GetXaxis()->SetLabelSize(0.055);
  hist->GetYaxis()->SetLabelSize(0.055);

  hist->GetXaxis()->SetTitleOffset(0.8);
  hist->GetYaxis()->SetTitleOffset(0.7);
  // hist->GetZaxis()->SetTitleOffset(0.5);
  //hist->SetTitle(1);
  gPad->SetLogz();
  // if(log_flag) {
  //   gPad->SetLogz();
  // }

    
  hist->Draw("colz");
  gPad->Update();


   // TPaletteAxis *palette = (TPaletteAxis*)hist->GetListOfFunctions()->FindObject("palette");
   // palette->SetX1NDC(0.9);
   // palette->SetX2NDC(0.95);
   // palette->SetY1NDC(0.2);
   // palette->SetY2NDC(0.8);
   // c->Modified();
   // c->Update();

  
  char* sname = new char[200];
  sprintf(sname,"%d_corrected_%s.gif",layer-1,h_name);
  c->Print(sname);


}

void plotAll2D(char const *fname1, int layer) {
  plot2D(fname1,"h_dX_corrected_run_132_161_layer1",layer);
  plot2D(fname1,"h_dY_corrected_run_132_161_layer1",layer);


  plot2D(fname1,"h_dX_corrected_run_206_225_layer1",layer);
  plot2D(fname1,"h_dY_corrected_run_206_225_layer1",layer);


  plot2D(fname1,"h_dX_corrected_run_387_392_layer1",layer);
  plot2D(fname1,"h_dY_corrected_run_387_392_layer1",layer);
}


void plot1D(TH1F* hist,char const *htit,char const *run, bool log_flag=false,char const *hname=""){
  //TCanvas *c = new TCanvas(htit, htit, 400, 250);
  TCanvas *c = new TCanvas(htit, htit, 300, 300);
  gStyle->SetOptStat(1111);
  //hist->Scale(1.0/hist->Integral());
  hist->SetLineWidth(2);
  hist->SetLineStyle(1);
  hist->GetXaxis()->SetTitleSize(0.05);
  hist->GetXaxis()->SetLabelSize(0.05);
  hist->GetYaxis()->SetLabelSize(0.05);

  if(log_flag) {
    gPad->SetLogy();
  }

  
  hist->Draw();
  gPad->Update();

  hist->SetTitle(0);

  if(strcmp(hname,"dR_min")==0) {
    hist->SetName("min(dR)");
    hist->GetXaxis()->SetTitle("min(dR) in cm");
  }
  if(strcmp(hname,"nrechit")==0){
    hist->SetName("nRecHit");
    hist->GetXaxis()->SetTitle("nRechits");
    //hist->GetXaxis()->SetRangeUser(0,35);
  }

  TPaveStats *s = (TPaveStats*) gPad->GetPrimitive("stats");
  s->SetX1NDC(0.45);                                                                                                                       
  s->SetY1NDC(0.9);                                                                                                                       
  s->SetX2NDC(0.9);                                                                                                                       
  s->SetY2NDC(0.6);       
  gPad->Update();


  
  char* sname = new char[200];
  sprintf(sname,"%s/%s_%s.gif",run,htit,run);
  c->Print(sname);
  
}
