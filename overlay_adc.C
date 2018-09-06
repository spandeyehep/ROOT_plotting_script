void generate_1Dplot(TH1F *hist, TH1F *hist_track, char const *tag_name="", int layer=-1){
  //TCanvas *c = new TCanvas(htit, htit, 400, 250);
  //TCanvas *c = new TCanvas(tag_name, tag_name, 300, 300); //FOR SLIDES small size
  TCanvas *c = new TCanvas(tag_name, tag_name, 600, 600); //FOR WebPage
  gStyle->SetOptStat(1111);
  //hist->Scale(1.0/hist->Integral());
  hist->SetLineWidth(2);
  hist->SetLineStyle(1);
  hist->GetXaxis()->SetTitleSize(0.05);
  //hist->GetYaxis()->SetTitleSize(0.05);
  hist->GetXaxis()->SetLabelSize(0.05);
  hist->GetYaxis()->SetLabelSize(0.05);

  hist->GetXaxis()->SetTitle("Signal Amplitude(ADC counts)");
  //hist->GetYaxis()->SetTitle("Events/ADC count");
  hist->GetYaxis()->SetTitleOffset(1.45);

  hist_track->SetLineWidth(2);
  hist_track->SetLineStyle(2);
  hist_track->SetLineColor(kRed);
  hist_track->GetXaxis()->SetTitleSize(0.05);
  hist_track->GetXaxis()->SetLabelSize(0.05);
  hist_track->GetYaxis()->SetLabelSize(0.05);

/*
  if(log_flag) {
    gPad->SetLogy();
  }

*/
  hist->Rebin(4);
  hist_track->Rebin(4);
  gPad->SetLogy();
  hist->Draw();
  hist_track->Draw("sames");
  gPad->Update();

  //hist->SetTitle(0);



  TPaveStats *st1 = (TPaveStats*)hist_track->FindObject("stats");
  st1->SetTextColor(hist_track->GetLineColor());
  st1->SetLineColor(hist_track->GetLineColor());

  //st1->SetX1NDC(0.7);  //x1 left start
  st1->SetX1NDC(0.5);  //x1 left start
  st1->SetX2NDC(0.9);  //x2  right end
  st1->SetY1NDC(0.9);  //y1 top starting
  //st1->SetY2NDC(0.6);
  st1->SetY2NDC(0.7); //y2 bottom ending



  TPaveStats *st2 = (TPaveStats*)hist->FindObject("stats");
  st2->SetTextColor(hist->GetLineColor());
  st2->SetLineColor(hist->GetLineColor());
  //st2->SetX1NDC(0.7);  //x1 left start
  st2->SetX1NDC(0.5);  //x1 left start
  st2->SetX2NDC(0.9);  //x2  right end
  //st2->SetY1NDC(0.6);  //
  st2->SetY1NDC(0.7);  //
  //st2->SetY2NDC(0.3);
  st2->SetY2NDC(0.5);

  
  gPad->Modified();
  char* canvas_name = new char[100];
  if(layer<11) {
    sprintf(canvas_name,"overlay_plots/layer0%d/%s.gif",layer+1,tag_name);
  }
  else {
    sprintf(canvas_name,"overlay_plots/layer%d/%s.gif",layer+1,tag_name);
  
  }
  c->Print(canvas_name);
  
}

void overlay_adc(char const *fname1=""){

  TFile *file0 = TFile::Open(fname1);
  if(!file0) {
    cout<<"Can't find file = "<<fname1<<endl;
    return;
  }

  char* hname = new char[200];
  char* htit = new char[200];
  TH1F* track;
  TH1F* no_track;
  

  char* tag_name = new char[100];
  
  for(int layer = 0; layer < 28; layer++) {
      for(int chip = 0; chip < 4; chip++) {
        for(int channel = 0; channel < 64; channel+=2) {
          sprintf(hname,"ADC_distributions/Layer_%d/%d_%d_%d",layer,layer,chip,channel);
          no_track = (TH1F*)file0->Get(hname);
          sprintf(hname,"ADC_distributions/Layer_%d/%d_%d_%d_track",layer,layer,chip,channel);
          track = (TH1F*)file0->Get(hname);
          if(track->GetEntries() == 0 || no_track->GetEntries() == 0){
            cout<<"track_enries = "<<track->GetEntries()<<" ,no_track_enries = "<< no_track->GetEntries()<<endl;
            cout<<hname<<" contains NO events!!! skipping.."<<endl;
            continue;
          }
          if(!no_track || !track){
            cout<<hname<<" NOT FOUND!!! skipping.."<<endl;
            continue;
          }
          sprintf(htit,"Board=%d, Chip=%d, Channel=%d",layer,chip,channel);
          no_track->SetTitle(htit);
          sprintf(htit,"W/O DWC info");
          no_track->SetName(htit);
          sprintf(htit,"Board=%d, Chip=%d, Channel=%d",layer,chip,channel);
          track->SetTitle(htit);
          sprintf(htit,"With DWC info");
          track->SetName(htit);
          sprintf(tag_name,"overlay_%d_%d_%d",layer,chip,channel);
          generate_1Dplot(track,no_track,tag_name,layer);
          //return;
        }
    }
    //return;
  }

}
