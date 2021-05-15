/// \file
/// \ingroup tutorial_graphics
/// \notebook
/// Example of canvas partitioning.
/// Sometimes the Divide() method is not appropriate to divide a Canvas.
/// Because of the left and right margins, all the pads do not have the
/// same width and height. CanvasPartition does that properly. This
/// example also ensure that the axis labels and titles have the same
/// sizes and that the tick marks length is uniform.
///
/// \macro_image
/// \macro_code
///
/// \author Olivier Couet


int point_col[4] = {kBlue, kRed, kBlack,  kMagenta};
//int point_style[3] = {kFullCircle,kOpenSquare,kFullTriangleUp};
int point_style[3] = {kOpenSquare,kFullTriangleUp,kFullCircle};
float point_size[3] = {1.2,1.8,1.2};

int modules[] = {78,90,89,88,77,85,84,32,69,79,76,83,70,73,86,87,82,72,67,65,35,36,44,51,142,143,145,144};

int getBIN(unsigned int skiroc,unsigned int channel) {
  if (channel%2 != 0 || channel > 62 || skiroc > 3) return -1;
  else return (skiroc*32 + (channel/2));
}

TGraphErrors* plot_mip(int layer){
   //For WebPage
   //TCanvas *mycanvas = new TCanvas("mycanvas","mycanvas",600,350);
   // TCanvas *canvas = new TCanvas("mycanvas","mycanvas",1000,500);
   // canvas->SetRightMargin(0.009);
   // canvas->SetLeftMargin(0.11);
   // canvas->SetTopMargin(0.05);
   // //For slides
   // // TCanvas *mycanvas = new TCanvas("mycanvas","mycanvas",400,275);




   // TGraphErrors *graph_;


   char* txt_file = new char[500];

   sprintf(txt_file,"/home/shubham/work/HGCAL/CERNTB/oct2018TB/txt_file/v13pre1/for_matlibplot/EE_withEntries.txt");
   std::ifstream in(txt_file);
   if(!in) {
      cout<<"Could not find file: "<<txt_file<<endl;
      return NULL;
   }
   else {
      cout<<"Successfully opened file: "<<txt_file<<endl;
   }

   const int n = 128;
   int mod_, chip_, channel_, use_ave_, entries_;
   float value_, chi2_ndf_,  error_;
   float channel[128], error_on_x[128];
   float value[128], error_on_value[128];
   int count = 0;
   while(in>>mod_>>chip_>>channel_>>entries_>>value_>>chi2_ndf_>>error_>>use_ave_) {
      if(mod_ != modules[layer-1]) continue;
      channel[count] = getBIN(chip_,channel_);
      if(use_ave_ || chi2_ndf_ > 10 || (value_ == 60.0 && entries_ < 200)) {
         value[count] = -99.0;   
         error_on_value[count] = 0.0;
      }
      else {
         value[count] = value_;  
         error_on_value[count] = error_;  
      }

      error_on_x[count] = 0.0;
      count++;
   }

   //////////////////////////////////////////////////
   ///         Print & Check              ///
   //////////////////////////////////////////////////
   // if(!save_) {
   //    cout<<"Printing for Layer = "<<layer<<" Module = "<<modules[layer-1]<<endl;
   //    cout<<"channel \t Value \t error_on_value"<<endl;
   //    for(int i = 0; i < 128; i++){
   //       cout<<channel[i]<<" \t "<<value[i]<<" \t "<<error_on_value[i]<<endl;
   //    }
   // }
   //////////////////////////////////////////////////


   TGraphErrors* graph_ = new TGraphErrors(n, channel, value, error_on_x, error_on_value);
   graph_->SetTitle("");
   graph_->GetXaxis()->SetTitle("High Gain Channel");
   //graph_->GetXaxis()->SetTitleSize(0.04);
   graph_->GetYaxis()->SetTitle("HG ADC counts/MIP");
   //graph_->GetYaxis()->SetTitleSize(0.04);
   graph_->GetXaxis()->SetRangeUser(0.0,130.0);
   graph_->GetYaxis()->SetRangeUser(10.0,70.0);
   graph_->SetMarkerStyle(kFullCircle);
   graph_->SetMarkerColor(kBlue);
   graph_->SetMarkerSize(0.9);
   graph_->SetLineColor(kBlue);

   return graph_;
 
}

void CanvasPartition(TCanvas *C,const Int_t Nx = 2,const Int_t Ny = 2,
                     Float_t lMargin = 0.15, Float_t rMargin = 0.05,
                     Float_t bMargin = 0.15, Float_t tMargin = 0.05);

void canvas2(bool save_canvas= false) {

   gStyle->SetOptStat(0);

   TCanvas *C = (TCanvas*) gROOT->FindObject("C");
   if (C) delete C;
   //C = new TCanvas("C","canvas",1024,640);
   C = new TCanvas("C","canvas",1024,750);
   C->SetFillStyle(4000);

   // Number of PADS
   const Int_t Nx = 2;
   const Int_t Ny = 3;

   // Margins
   Float_t lMargin = 0.12;
   Float_t rMargin = 0.05;
   Float_t bMargin = 0.15;
   Float_t tMargin = 0.05;

   // Canvas setup
   CanvasPartition(C,Nx,Ny,lMargin,rMargin,bMargin,tMargin);


   // Dummy histogram.
   // TH1F *h = (TH1F*) gROOT->FindObject("histo");
   // if (h) delete h;
   // h = new TH1F("histo","",100,-5.0,5.0);
   // h->FillRandom("gaus",10000);
   // h->GetXaxis()->SetTitle("x axis");
   // h->GetYaxis()->SetTitle("y axis");
   //int layers[] =  {2,8,14,20,27,28};
   //int layers[] =  {27,8,14,28,2,20};
   int layers[] =  {27,14,2,28,20,8};

   TH1F* h[Nx*Ny];

   TGraphErrors* gr[Nx*Ny];

   char* hname = new char[100];
   for(int i = 0; i < Nx*Ny; i++) {
      sprintf(hname,"gr_%d",i+1);
      cout<<"init => "<<hname<<endl;
      gr[i] = plot_mip(layers[i]);
      // h[i] = new TH1F(hname,hname,100,-5,5);
      // h[i]->GetXaxis()->SetTitle("x axis");
      // h[i]->GetYaxis()->SetTitle("y axis");
      // h[i]->SetTitle(hname);
      // h[i]->FillRandom("gaus",10000);
      // h[i]->Scale(1.0/h[i]->GetMaximum());
      // c->cd(i+1);
      // h[i]->Draw();
   }



   TPad *pad[Nx][Ny];
   Int_t k=0;
   for (Int_t i=0;i<Nx;i++) {
      for (Int_t j=0;j<Ny;j++,k++) {
         C->cd(0);

         // Get the pads previously created.
         char pname[16];
         sprintf(pname,"pad_%i_%i",i,j);
         pad[i][j] = (TPad*) gROOT->FindObject(pname);
         pad[i][j]->Draw();
         pad[i][j]->SetFillStyle(4000);
         pad[i][j]->SetFrameFillStyle(4000);
         //pad[i][j]->SetGridx();
         pad[i][j]->SetGridy();
         pad[i][j]->SetTickx();
         pad[i][j]->SetTicky();
         pad[i][j]->cd();

         // Size factors
         Float_t xFactor = pad[0][0]->GetAbsWNDC()/pad[i][j]->GetAbsWNDC();
         Float_t yFactor = pad[0][0]->GetAbsHNDC()/pad[i][j]->GetAbsHNDC();

         //cout<<"*************** xFactor : yFactor :: "<<xFactor<<" : "<<yFactor<<endl;
         char hname[16];
         sprintf(hname,"gr_%d",k+1);
         cout<<"Draw => "<<hname<<endl;
         TGraphErrors* htemp = (TGraphErrors*) gr[k]->Clone(hname);

         //sprintf(hname,"h_%i_%i",i,j);
         //TH1F *hFrame = (TH1F*) h[i*j]->Clone(hname);
         TGraphErrors* hFrame = (TGraphErrors*) htemp->Clone(hname);
         //hFrame->Reset();
         hFrame->Draw("APE");
         
         // y axis range
         //hFrame->GetYaxis()->SetRangeUser(0.0001,1.5*htemp->GetMaximum());

         // Format for y axis
         hFrame->GetYaxis()->SetLabelFont(43);
         hFrame->GetYaxis()->SetLabelSize(16);
         hFrame->GetYaxis()->SetLabelOffset(0.02);
         hFrame->GetYaxis()->SetTitleFont(43);
         hFrame->GetYaxis()->SetTitleSize(16);
         //hFrame->GetYaxis()->SetTitleOffset(5);
         hFrame->GetYaxis()->SetTitleOffset(2); 
         hFrame->GetYaxis()->CenterTitle();
         //hFrame->GetYaxis()->SetNdivisions(505);

         
         // TICKS Y Axis
         hFrame->GetYaxis()->SetTickLength(xFactor*0.04/yFactor);

         // Format for x axis
         hFrame->GetXaxis()->SetLabelFont(43);
         hFrame->GetXaxis()->SetLabelSize(16);
         hFrame->GetXaxis()->SetLabelOffset(0.02);
         hFrame->GetXaxis()->SetTitleFont(43);
         hFrame->GetXaxis()->SetTitleSize(16);
         hFrame->GetXaxis()->SetTitleOffset(5);
         hFrame->GetXaxis()->SetTitleOffset(3);
         hFrame->GetXaxis()->CenterTitle();
         //hFrame->GetXaxis()->SetNdivisions(505);

         
         // TICKS X Axis
         hFrame->GetXaxis()->SetTickLength(yFactor*0.06/xFactor);

         htemp->Draw("PE same");

         char* canvas_title = new char[500];
         char* canvas_caption = new char[500];
         int layer = layers[k];
         if(modules[layer-1] == 144 || modules[layer-1] == 145) sprintf(canvas_caption,"200 #mum sensor");
         else sprintf(canvas_caption,"300 #mum sensor");

         sprintf(canvas_title,"CE-E prototype Layer %d (Module %d)", layer, modules[layer-1]);

         TLatex *caption = new TLatex();
         caption->SetTextSize(0.05);
         caption->SetTextAlign(13);
         caption->DrawLatex(10,68,canvas_title);
         caption->DrawLatex(90,68,canvas_caption);


         caption->SetTextSize(0.04);
         caption->DrawLatex(10,59,"ASIC 0");
         caption->DrawLatex(40,59,"ASIC 1");
         caption->DrawLatex(70,59,"ASIC 2");
         caption->DrawLatex(105,59,"ASIC 3");



         //htemp->Draw();    
         TLine* l_h = new TLine(0,62,130,62);
         l_h->SetLineColor(kRed);
         l_h->Draw("SAME");

         TLine* l1 = new TLine(33,10,33,62);
         l1->SetLineColor(kRed);
         l1->Draw("SAME");

         TLine* l2 = new TLine(65,10,65,62);
         l2->SetLineColor(kRed);
         l2->Draw("SAME");

         TLine* l3 = new TLine(97,10,97,62);
         l3->SetLineColor(kRed);
         l3->Draw("SAME");



        //  TLatex* textOnTop = new TLatex();
        // textOnTop->SetTextSize(0.035);
        // textOnTop->DrawLatexNDC(0.12,0.92,"CMS #it{#bf{Preliminary}}");
         
         //htemp->Delete();
      }
   }
   C->cd();
   if(save_canvas) {
      char* cname =  new char[100];
      sprintf(cname,"./plots/MIPSummary_HG_EE.png");
      C->SaveAs(cname);
      sprintf(cname,"./plots/MIPSummary_HG_EE.pdf");
      C->SaveAs(cname);
   }

  //  TLatex* textOnTop = new TLatex();
  // textOnTop->SetTextSize(0.035);
  // textOnTop->DrawLatexNDC(0.12,0.92,"CMS #it{#bf{Preliminary}}");
}



void CanvasPartition(TCanvas *C,const Int_t Nx,const Int_t Ny,
                     Float_t lMargin, Float_t rMargin,
                     Float_t bMargin, Float_t tMargin)
{
   if (!C) return;

   // Setup Pad layout:
   Float_t vSpacing = 0.0;
   Float_t vStep  = (1.- bMargin - tMargin - (Ny-1) * vSpacing) / Ny;

   Float_t hSpacing = 0.0;
   Float_t hStep  = (1.- lMargin - rMargin - (Nx-1) * hSpacing) / Nx;

   Float_t vposd,vposu,vmard,vmaru,vfactor;
   Float_t hposl,hposr,hmarl,hmarr,hfactor;

   for (Int_t i=0;i<Nx;i++) {

      if (i==0) {
         hposl = 0.0;
         hposr = lMargin + hStep;
         hfactor = hposr-hposl;
         hmarl = lMargin / hfactor;
         hmarr = 0.0;
      } else if (i == Nx-1) {
         hposl = hposr + hSpacing;
         hposr = hposl + hStep + rMargin;
         hfactor = hposr-hposl;
         hmarl = 0.0;
         hmarr = rMargin / (hposr-hposl);
      } else {
         hposl = hposr + hSpacing;
         hposr = hposl + hStep;
         hfactor = hposr-hposl;
         hmarl = 0.0;
         hmarr = 0.0;
      }

      for (Int_t j=0;j<Ny;j++) {

         if (j==0) {
            vposd = 0.0;
            vposu = bMargin + vStep;
            vfactor = vposu-vposd;
            vmard = bMargin / vfactor;
            vmaru = 0.0;
         } else if (j == Ny-1) {
            vposd = vposu + vSpacing;
            vposu = vposd + vStep + tMargin;
            vfactor = vposu-vposd;
            vmard = 0.0;
            vmaru = tMargin / (vposu-vposd);
         } else {
            vposd = vposu + vSpacing;
            vposu = vposd + vStep;
            vfactor = vposu-vposd;
            vmard = 0.0;
            vmaru = 0.0;
         }

         C->cd(0);

         char name[16];
         sprintf(name,"pad_%i_%i",i,j);
         TPad *pad = (TPad*) gROOT->FindObject(name);
         if (pad) delete pad;
         pad = new TPad(name,"",hposl,vposd,hposr,vposu);
         pad->SetLeftMargin(hmarl);
         pad->SetRightMargin(hmarr);
         pad->SetBottomMargin(vmard);
         pad->SetTopMargin(vmaru);

         pad->SetFrameBorderMode(0);
         pad->SetBorderMode(0);
         pad->SetBorderSize(0);

         pad->Draw();
      }
   }
}
