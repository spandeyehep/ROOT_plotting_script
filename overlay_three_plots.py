import os,sys,re,fileinput,string,shutil
import numpy as np
import ROOT as rt
from array import array
from ROOT import TCanvas, TFile, TPaveText, TPaveStats
from ROOT import TLorentzVector
import math


#def generate_plot(h_def, h_maxzero, h_nocut, can_)



canvas_name = "maxADCcut_zero_vs_noPreselection"
c = rt.TCanvas("c", "yolo", 600, 600); #FOR WebPage
rt.gStyle.SetOptStat(1111);
#name='tree_Mmumu_ieta27_MC_NoPU'
#name='tree_Mmumu_ieta27_MC_wPU'
# name_official= '../../ntuple_719_official_v9'
# name_rereco = '../../ntuple_719_correct_tracking'

# name_official= '../../ntuple_719_correct_tracking'
# name_rereco = '../../ntuple_719_noise'

file_default = '~/work/HGCAL/CERNTB/oct2018TB/rereco/analyzed_files/muon_rereco_719_default.root'
file_maxzero = '~/work/HGCAL/CERNTB/oct2018TB/rereco/analyzed_files/muon_rereco_719_maxADCCut_zero_v9.root'
file_nocut = '~/work/HGCAL/CERNTB/oct2018TB/rereco/analyzed_files/muon_rereco_719_noPreselection_noise.root'

in_file_default = rt.TFile.Open(file_default)
if(not in_file_default):
    print "Could Not open ",file_default
    sys.exit()

in_file_maxzero = rt.TFile.Open(file_maxzero)
if(not in_file_maxzero):
    print "Could Not open ",file_maxzero
    sys.exit()

in_file_nocut = rt.TFile.Open(file_nocut)
if(not in_file_nocut):
    print "Could Not open ",file_nocut
    sys.exit()

hist_name = "ADC_distributions/EE_1/h_TS3HG_EE_L1_P0_chip2_chan36"
h_def = in_file_default.Get(hist_name)

if(not h_def):
    print "Could Not Load ",hist_name
    sys.exit()

h_max0 = in_file_maxzero.Get(hist_name)
if(not h_max0):
    print "Could Not Load ",hist_name
    sys.exit()

h_nocut = in_file_nocut.Get(hist_name)
if(not h_nocut):
    print "Could Not Load ",hist_name
    sys.exit()



h_def.Scale(1.0/h_def.Integral())
h_max0.Scale(1.0/h_max0.Integral())
h_nocut.Scale(1.0/h_nocut.Integral())



stat_default = 'Default'
stat_max0 = 'MaxADCcut=0'
stat_nocut = 'No PreSelection'

h_title = 'Default vs MaxADCcut=0 vs NoPreSelection'

h_def.SetLineWidth(2);
h_def.SetLineStyle(1);
h_def.SetName(stat_default)
h_def.GetXaxis().SetTitleSize(0.05);
h_def.GetXaxis().SetLabelSize(0.035);
h_def.GetYaxis().SetLabelSize(0.05);
h_def.GetXaxis().SetTitle("TS3 HG ADC amplitude");
h_def.GetXaxis().SetTitleOffset(0.9);
h_def.GetYaxis().SetTitleOffset(1.45);
h_def.SetTitle(h_title)

h_max0.SetLineWidth(2);
h_max0.SetLineStyle(1);
h_max0.SetLineColor(rt.kRed)
h_max0.SetName(stat_max0)
h_max0.GetXaxis().SetTitleSize(0.05);
h_max0.GetXaxis().SetLabelSize(0.035);
h_max0.GetYaxis().SetLabelSize(0.05);
h_max0.GetXaxis().SetTitle("TS3 HG ADC amplitude");
h_max0.GetXaxis().SetTitleOffset(0.9);
h_max0.GetYaxis().SetTitleOffset(1.45);
h_max0.SetTitle(h_title)

h_nocut.SetLineWidth(2);
h_nocut.SetLineStyle(1);
h_nocut.SetLineColor(rt.kBlack)
h_nocut.SetName(stat_nocut)
h_nocut.GetXaxis().SetTitleSize(0.05);
h_nocut.GetXaxis().SetLabelSize(0.035);
h_nocut.GetYaxis().SetLabelSize(0.05);
h_nocut.GetXaxis().SetTitle("TS3 HG ADC amplitude");
h_nocut.GetXaxis().SetTitleOffset(0.9);
h_nocut.GetYaxis().SetTitleOffset(1.45);
h_nocut.SetTitle(h_title)

h_def.GetYaxis().SetRangeUser(0.0,0.15);
h_max0.GetYaxis().SetRangeUser(0.0,0.15);
h_nocut.GetYaxis().SetRangeUser(0.0,0.15);

# h_def.Draw("hist")
# h_max0.Draw("hist sames")
# h_nocut.Draw("hist sames")


h_nocut.Draw("hist")
h_def.Draw("hist sames")
h_max0.Draw("hist sames")



# #out_file =  rt.TFile.Open(name+"_plots.root","recreate")
# #h_official =rt.TH1F("h_official","yolo",130,0.,1300.)
# h_official.SetLineWidth(2);
# h_official.SetLineStyle(1);
# #h_official.SetName("Official")
# h_official.SetName(stat_official)
# h_official.GetXaxis().SetTitleSize(0.05);
# h_official.GetXaxis().SetLabelSize(0.035);
# h_official.GetYaxis().SetLabelSize(0.05);
# h_official.GetXaxis().SetTitle("Rechit energy(MIPs)");
# h_official.GetXaxis().SetTitleOffset(0.9);
# h_official.GetYaxis().SetTitleOffset(1.45);


# h_rereco =rt.TH1F("h_rereco","yolo",130,0.,1300.)
# h_rereco.SetLineWidth(2);
# h_rereco.SetLineColor(rt.kRed);
# h_rereco.SetLineStyle(2);
# #h_rereco.SetName("Rereco")
# h_rereco.SetName(stat_rereco)
# h_rereco.GetXaxis().SetTitleSize(0.05);
# h_rereco.GetXaxis().SetLabelSize(0.035);
# h_rereco.GetYaxis().SetLabelSize(0.05);
# h_rereco.GetXaxis().SetTitle("Rechit energy(MIPs)");
# h_rereco.GetXaxis().SetTitleOffset(0.9);
# h_rereco.GetYaxis().SetTitleOffset(1.45);

# h_official.SetTitle("No change in ReReco Code")
# h_rereco.SetTitle("No change in ReReco Code")


'''
h_official.SetTitle(h_title)
h_rereco.SetTitle(h_title)

in_file_official = rt.TFile.Open(name_official+".root")
in_tree_official = in_file_official.Get("rechitntupler/hits")	
i=-1
print in_tree_official.GetEntriesFast()
for event in in_tree_official:
    i=i+1
    if i%100000==0: 
    	print "100000"
    for energy in event.rechit_energy:
        h_official.Fill(energy)
in_file_official.Close()


in_file_rereco = rt.TFile.Open(name_rereco+".root")
in_tree_rereco = in_file_rereco.Get("rechitntupler/hits")	
i=-1
for event in in_tree_rereco:
    i=i+1
    if i%100000==0: 
    	print "100000"
    for energy in event.rechit_energy:
        h_rereco.Fill(energy)


in_file_rereco.Close()

rt.gPad.SetLogy();
c.Update()

# h_official.Draw("hist")
# h_rereco.Draw("hist same")
h_official.Draw("hist")
h_rereco.Draw("hist sames")
rt.gPad.Update()

# c.Update()
#hist->Scale(1.0/hist->Integral());
# h_official.Scale(1.0/h_official.Integral());
# h_rereco.Scale(1.0/h_rereco.Integral());

 
st1 = h_official.FindObject("stats");
st1.SetTextColor(h_official.GetLineColor());
st1.SetLineColor(h_official.GetLineColor());
st1.SetX1NDC(0.65);  #x1 left start
st1.SetX2NDC(0.9);  #x2  right end
st1.SetY1NDC(0.9);  #y1 top starting
st1.SetY2NDC(0.75); #y2 bottom ending

# c.Update()
# rt.gPad.Modified()
st2 = h_rereco.FindObject("stats");
st2.SetTextColor(h_rereco.GetLineColor());
st2.SetLineColor(h_rereco.GetLineColor());
st2.SetX1NDC(0.65);  #x1 left start
st2.SetX2NDC(0.9);  #x2  right end
st2.SetY1NDC(0.75);  #y1 top starting
st2.SetY2NDC(0.60); #y2 bottom ending



rt.gPad.Modified()
c.Update()
c.Modified()

c.SaveAs("rechit_energy_"+canvas_name+".png")
#raw_input()
#out_file.cd()

'''

'''
  //hist.Scale(1.0/hist.Integral());
  hist.SetLineWidth(2);
  hist.SetLineStyle(1);
  hist.GetXaxis().SetTitleSize(0.05);
  //hist.GetYaxis().SetTitleSize(0.05);
  hist.GetXaxis().SetLabelSize(0.05);
  hist.GetYaxis().SetLabelSize(0.05);

  hist.GetXaxis().SetTitle("Signal Amplitude(ADC counts)");
  //hist.GetYaxis().SetTitle("Events/ADC count");
  hist.GetYaxis().SetTitleOffset(1.45);

  hist_track.SetLineWidth(2);
  hist_track.SetLineStyle(2);
  hist_track.SetLineColor(kRed);
  hist_track.GetXaxis().SetTitleSize(0.05);
  hist_track.GetXaxis().SetLabelSize(0.05);
  hist_track.GetYaxis().SetLabelSize(0.05);

/*
  if(log_flag) {
    gPad.SetLogy();
  }
*/
  hist.Rebin(4);
  hist_track.Rebin(4);
  gPad.SetLogy();
  hist.Draw();
  hist_track.Draw("sames");
  gPad.Update();

  //hist.SetTitle(0);



  TPaveStats *st1 = (TPaveStats*)hist_track.FindObject("stats");
  st1.SetTextColor(hist_track.GetLineColor());
  st1.SetLineColor(hist_track.GetLineColor());

  //st1.SetX1NDC(0.7);  //x1 left start
  st1.SetX1NDC(0.5);  //x1 left start
  st1.SetX2NDC(0.9);  //x2  right end
  st1.SetY1NDC(0.9);  //y1 top starting
  //st1.SetY2NDC(0.6);
  st1.SetY2NDC(0.7); //y2 bottom ending



  TPaveStats *st2 = (TPaveStats*)hist.FindObject("stats");
  st2.SetTextColor(hist.GetLineColor());
  st2.SetLineColor(hist.GetLineColor());
  //st2.SetX1NDC(0.7);  //x1 left start
  st2.SetX1NDC(0.5);  //x1 left start
  st2.SetX2NDC(0.9);  //x2  right end
  //st2.SetY1NDC(0.6);  //
  st2.SetY1NDC(0.7);  //
  //st2.SetY2NDC(0.3);
  st2.SetY2NDC(0.5);

  
  gPad.Modified();
  char* canvas_name = new char[100];
  if(layer<11) {
    sprintf(canvas_name,"overlay_plots/layer0%d/%s.gif",layer+1,tag_name);
  }
  else {
    sprintf(canvas_name,"overlay_plots/layer%d/%s.gif",layer+1,tag_name);
  
  }
  c.Print(canvas_name);
'''
