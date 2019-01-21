void generate_1Dplot(TH1F *hist, TH1F *hist_track, char const *tag_name="", int layer=-1){
  //TCanvas *c = new TCanvas(htit, htit, 400, 250);
  //TCanvas *c = new TCanvas(tag_name, tag_name, 300, 300); //FOR SLIDES small size
  TCanvas *c = new TCanvas(tag_name, tag_name, 600, 600); //FOR WebPage
  gStyle->SetOptStat(1111);
  // hist->Scale(1.0/hist->Integral());
  // hist_track->Scale(1.0/hist_track->Integral());
  hist->SetLineWidth(2);
  hist->SetLineStyle(1);
  hist->GetXaxis()->SetTitleSize(0.04);
  //hist->GetYaxis()->SetTitleSize(0.05);
  hist->GetXaxis()->SetLabelSize(0.035);
  hist->GetYaxis()->SetLabelSize(0.035);

  hist->GetXaxis()->SetTitle("Signal Amplitude(ADC counts)");
  //hist->GetYaxis()->SetTitle("Events/ADC count");
  hist->GetYaxis()->SetTitleOffset(1.45);


  hist_track->SetLineWidth(2);
  hist_track->SetLineStyle(2);
  hist_track->SetLineColor(kRed);
  hist_track->GetXaxis()->SetTitleSize(0.04);
  hist_track->GetXaxis()->SetTitle("Signal Amplitude(ADC counts)");
  hist_track->GetXaxis()->SetLabelSize(0.035);
  hist_track->GetYaxis()->SetLabelSize(0.035);

/*
  if(log_flag) {
    gPad->SetLogy();
  }

*/
  // hist->Rebin(2);
  // hist_track->Rebin(2);
  // gPad->SetLogy();
  hist->Draw();
  hist_track->Draw("sames");
  // hist_track->Draw("hist");
  // hist->Draw("hist sames");

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
  sprintf(canvas_name,"./%s.gif",tag_name);
  c->Print(canvas_name);
  
}

void overlay_adc_EE(char const *fname0="",char const *fname1="",char const *hist0="",char const *hist1="",char const *ht0="",char const *ht1="",char const *tag_name=""){

  TFile *file0 = TFile::Open(fname0);
  if(!file0) {
    cout<<"Can't find file = "<<fname0<<endl;
    return;
  }

  TFile *file1 = TFile::Open(fname1);
  if(!file1) {
    cout<<"Can't find file = "<<fname1<<endl;
    return;
  }

  
  
  // char* hname = new char[200];
  // char* htit = new char[200];
  TH1F* tar;
  TH1F* ref;

  tar = (TH1F*)file0->Get(hist0);
  if(!tar) {
    cout<<"Couldn't find "<<hist0<<endl;
    return;
  }
  else {
    cout<<hist0<<" is loaded as Target!!"<<endl;
  }
  ref = (TH1F*)file1->Get(hist1);
  if(!ref) {
    cout<<"Couldn't find "<<hist1<<endl;
    return;
  }
  else {
    cout<<hist1<<" is loaded as Reference!!"<<endl;
  }

  cout<<"HT0 = "<<ht0<<endl;
  cout<<"HT1 = "<<ht1<<endl;
  tar->SetName(ht0);
  ref->SetName(ht1);
  tar->SetTitle(tag_name);
  ref->SetTitle(tag_name);

  cout<<"tar_title = "<<tar->GetTitle()<<endl;
  cout<<"ref_title = "<<ref->GetTitle()<<endl;
  char *tag = new char[200];
  sprintf(tag,"%s_%s",tag_name,ht0);
  generate_1Dplot(tar,ref,tag,00);
  
  // char* tag_name = new char[100];
  
  // for(int layer = 1; layer <= 28; layer++) {
  //   if(layer > 26) break;
  //     for(int chip = 0; chip < 4; chip++) {
  //       for(int channel = 0; channel < 64; channel+=2) {
  // 	  sprintf(hname,"ADC_distributions/EE_%d/h_adcHG_EE_L%d_P0_chip%d_chan%d",layer,layer,chip,channel);
  //         no_track = (TH1F*)file0->Get(hname);
  // 	  sprintf(hname,"ADC_distributions/EE_%d/h_adcHG_EE_L%d_P0_chip%d_chan%d_track",layer,layer,chip,channel);
  //         track = (TH1F*)file0->Get(hname);
  //         if(track->GetEntries() == 0 || no_track->GetEntries() == 0){
  //           cout<<"track_enries = "<<track->GetEntries()<<" ,no_track_enries = "<< no_track->GetEntries()<<endl;
  //           cout<<hname<<" contains NO events!!! skipping.."<<endl;
  //           continue;
  //         }
  //         if(!no_track || !track){
  //           cout<<hname<<" NOT FOUND!!! skipping.."<<endl;
  //           continue;
  //         }
  //         sprintf(htit,"Board=%d, Chip=%d, Channel=%d",layer,chip,channel);
  //         no_track->SetTitle(htit);
  //         sprintf(htit,"W/O DWC info");
  //         no_track->SetName(htit);
  //         sprintf(htit,"Board=%d, Chip=%d, Channel=%d",layer,chip,channel);
  //         track->SetTitle(htit);
  //         sprintf(htit,"With DWC info");
  //         track->SetName(htit);
  //         sprintf(tag_name,"overlay_%d_%d_%d",layer,chip,channel);
  //         generate_1Dplot(track,no_track,tag_name,layer);

  //       }
  //   }
  //   //return;
  // }

}

/*
void overlay_adc_FH(char const *fname1=""){

  TFile *file0 = TFile::Open(fname1);
  if(!file0) {
    cout<<"Can't find file = "<<fname1<<endl;
    return;
  }
  int FHModules[12] = {96,106,94,102,139,131,119,45,64,62,54,43};
  char* hname = new char[200];
  char* htit = new char[200];
  TH1F* track;
  TH1F* no_track;
  

  char* tag_name = new char[100];
  
  for(int layer = 1; layer <= 12; layer++) {
    //if(layer > 26) break; h_adcHG_FH_L1_P4_chip0_chan0
    if(layer ==1) continue;
      for(int chip = 0; chip < 4; chip++) {
        for(int channel = 0; channel < 64; channel+=2) {
	  sprintf(hname,"ADC_distributions/FH_L%d_P4/h_adcHG_FH_L%d_P4_chip%d_chan%d",layer,layer,chip,channel);
          no_track = (TH1F*)file0->Get(hname);
	  sprintf(hname,"ADC_distributions/FH_L%d_P4/h_adcHG_FH_L%d_P4_chip%d_chan%d_track",layer,layer,chip,channel);
	  if(!no_track){
            cout<<hname<<" NOT FOUND!!! skipping.."<<endl;
            continue;
          }

          track = (TH1F*)file0->Get(hname);
	  if(!track){
            cout<<hname<<" NOT FOUND!!! skipping.."<<endl;
            continue;
          }

          if(track->GetEntries() == 0 || no_track->GetEntries() == 0){
            cout<<"track_enries = "<<track->GetEntries()<<" ,no_track_enries = "<< no_track->GetEntries()<<endl;
            cout<<hname<<" contains NO events!!! skipping.."<<endl;
            continue;
          }
          sprintf(htit,"FH_Layer = %d, Board=%d, Chip=%d, Channel=%d",layer,FHModules[layer-1],chip,channel);
          no_track->SetTitle(htit);
          sprintf(htit,"W/O DWC info");
          no_track->SetName(htit);
          sprintf(htit,"FH_Layer = %d, Board=%d, Chip=%d, Channel=%d",layer,FHModules[layer-1],chip,channel);
          track->SetTitle(htit);
          sprintf(htit,"With DWC info");
          track->SetName(htit);
          sprintf(tag_name,"overlay_%d_%d_%d",layer+28,chip,channel);
          generate_1Dplot(track,no_track,tag_name,layer+28);
	  //return;
        }
    }
    //return;
  }

}
*/
