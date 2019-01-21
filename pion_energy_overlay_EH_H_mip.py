import os,sys,re,fileinput,string,shutil
import numpy as np
import ROOT as rt
from array import array
from ROOT import TCanvas, TFile, TPaveText, TPaveStats
from ROOT import TLorentzVector
import math
from sys import argv

#def generate_plot(h_def, h_2, h_nocut, can_)
energy = argv[1]



#c = rt.TCanvas("c", "yolo", 600, 600); #FOR WebPage
c = rt.TCanvas("c", "yolo", 300, 300); #FOR WebPage

#rt.gStyle.SetOptStat(1111)
rt.gStyle.SetOptStat(0);

#name='tree_Mmumu_ieta27_MC_NoPU'
#name='tree_Mmumu_ieta27_MC_wPU'
# name_official= '../../ntuple_719_official_v9'
# name_rereco = '../../ntuple_719_correct_tracking'

# name_official= '../../ntuple_719_correct_tracking'
# name_rereco = '../../ntuple_719_noise'

file_1 = "/home/shubham/work/HGCAL/CERNTB/oct2018TB/pion_files/v8/20_jan_2019/test_"+str(energy)+"GeV_energy_v1.root"

in_file_1 = rt.TFile.Open(file_1)
if(not in_file_1):
    print "Could Not open ",file_1
    sys.exit()


#hist_name = "ADC_distributions/EE_1/h_TS3HG_EE_L1_P0_chip2_chan36"
hist_name_1 = "h_energy_EEFH"
hist_name_2 = "h_energy_EEFH_EH_hadrons"
hist_name_3 = "h_energy_EEFH_MIPEE"
hist_name_4 = "h_energy_EEFH_MIPEEFH"

if(int(energy) == 20):
    x_max = 2000
elif(int(energy) == 50):
    x_max = 4700
elif(int(energy) == 80):
    x_max = 8000
elif(int(energy) == 100):
    x_max = 9000
elif(int(energy) == 120):
    x_max = 11000
elif(int(energy) == 200):
    x_max = 20000
elif(int(energy) == 250):
    x_max = 20000
elif(int(energy) == 300):
    x_max = 20000

h_1 = in_file_1.Get(hist_name_1)

if(not h_1):
    print "Could Not Load ",hist_name_1
    sys.exit()

h_2 = in_file_1.Get(hist_name_2)
if(not h_2):
    print "Could Not Load ",hist_name_2
    sys.exit()

h_3 = in_file_1.Get(hist_name_3)
if(not h_3):
    print "Could Not Load ",hist_name_3
    sys.exit()


h_4 = in_file_1.Get(hist_name_4)
if(not h_4):
    print "Could Not Load ",hist_name_4
    sys.exit()


# h_5 = in_file_5.Get(hist_name)
# if(not h_5):
#     print "Could Not Load ",hist_name
#     sys.exit()





    
# h_1.Scale(1.0/h_1.Integral())
# h_2.Scale(1.0/h_2.Integral())
# h_3.Scale(1.0/h_3.Integral())
# h_4.Scale(1.0/h_4.Integral())
# h_5.Scale(1.0/h_5.Integral())



# stat_1 = '20GeV (Config 1 Run:679-689)'
# stat_2 = '50GeV (Config 1 Run:690-696)'
# stat_3 = '80GeV (Config 1 Run:525-539)'
# stat_4 = '100GeV (Config 1 Run:552-562)'
# stat_5 = '120GeV (Config 1 Run:584-593)'

stat_1 = 'All events'
stat_2 = 'Shower start in EE'
stat_3 = 'Shower start in FH'
# stat_4 = 'muon like events (MIP both in EE & FH)'
stat_4 = 'muon like events '


if(int(energy) == 20):
    h_title = '20GeV (Config 1 Run:679-689)'
elif(int(energy) == 50):
    h_title = '50GeV (Config 1 Run:690-696)'
elif(int(energy) == 80):
    h_title = '80GeV (Config 1 Run:525-539)'
elif(int(energy) == 100):
    h_title = '100GeV (Config 1 Run:552-562)'
elif(int(energy) == 120):
    h_title = '120GeV (Config 1 Run:584-593)'
elif(int(energy) == 200):
    h_title = '200GeV (Config 1 Run:563-567)'
elif(int(energy) == 250):
    h_title = '250GeV (Config 1 Run:541-551)'
elif(int(energy) == 300):
    h_title = '300GeV (Config 1 Run:512-523)'


h_1.SetLineWidth(3);
h_1.SetLineStyle(2);
h_1.SetLineColor(rt.kBlack);
h_1.SetName(stat_1)
h_1.GetXaxis().SetTitleSize(0.04);
# h_1.GetXaxis().SetLabelSize(0.03);
# h_1.GetYaxis().SetLabelSize(0.03);

h_1.GetXaxis().SetLabelSize(0.03);
h_1.GetYaxis().SetLabelSize(0.03);

h_1.GetXaxis().SetTitle("Energy (units of MIPs)");
h_1.GetYaxis().SetTitle("# of entries");
h_1.GetXaxis().SetTitleOffset(0.9);
h_1.GetYaxis().SetTitleOffset(1.45);
h_1.SetTitle(h_title)

h_2.SetLineWidth(2);
h_2.SetLineStyle(1);
h_2.SetLineColor(rt.kBlue-7)
h_2.SetName(stat_2)
h_2.GetXaxis().SetTitleSize(0.04);
h_2.GetXaxis().SetLabelSize(0.03);
h_2.GetYaxis().SetLabelSize(0.03);
h_2.GetXaxis().SetTitle("Energy (units of MIPs)");
h_2.GetYaxis().SetTitle("# of entries");
h_2.GetXaxis().SetTitleOffset(0.9);
h_2.GetYaxis().SetTitleOffset(1.45);
h_2.SetTitle(h_title)

h_3.SetLineWidth(2);
h_3.SetLineStyle(1);
h_3.SetLineColor(rt.kRed)
h_3.SetName(stat_3)
h_3.GetXaxis().SetTitleSize(0.04);
h_3.GetXaxis().SetLabelSize(0.03);
h_3.GetYaxis().SetLabelSize(0.03);
h_3.GetXaxis().SetTitle("Energy (units of MIPs)");
h_3.GetYaxis().SetTitle("# of entries");
h_3.GetXaxis().SetTitleOffset(0.9);
h_3.GetYaxis().SetTitleOffset(1.45);
h_3.SetTitle(h_title)


h_4.SetLineWidth(1);
h_4.SetLineStyle(1);
h_4.SetLineColor(rt.kGreen)
h_4.SetName(stat_4)
h_4.GetXaxis().SetTitleSize(0.04);
h_4.GetXaxis().SetLabelSize(0.03);
h_4.GetYaxis().SetLabelSize(0.03);
h_4.GetXaxis().SetTitle("Energy (units of MIPs)");
h_4.GetYaxis().SetTitle("# of entries");
h_4.GetXaxis().SetTitleOffset(0.9);
h_4.GetYaxis().SetTitleOffset(1.45);
h_4.SetTitle(h_title)



# h_1.GetYaxis().SetRangeUser(0.0,10000.0);
# h_2.GetYaxis().SetRangeUser(0.0,10000.0);
# h_3.GetYaxis().SetRangeUser(0.0,10000.0);
# h_4.GetYaxis().SetRangeUser(0.0,10000.0);


h_1.GetXaxis().SetRangeUser(0.0,x_max);
h_2.GetXaxis().SetRangeUser(0.0,x_max);
h_3.GetXaxis().SetRangeUser(0.0,x_max);
h_4.GetXaxis().SetRangeUser(0.0,x_max);


# h_1.Draw("hist")
# h_2.Draw("hist sames")
# h_3.Draw("hist sames")



h_1.Draw("hist")
h_2.Draw("hist sames")
h_3.Draw("hist sames")
h_4.Draw("hist sames")



#legend = rt.TLegend(0.5,0.8,0.5,0.8)
# legend = rt.TLegend(0.60,0.9,0.9,0.778)
#legend = rt.TLegend(0.25,0.9,0.9,0.65)
#legend = rt.TLegend(0.20,0.9,0.9,0.72)
legend = rt.TLegend(0.40,0.9,0.9,0.72)

rt.gStyle.SetLegendTextSize(.04)
legend.AddEntry(h_1,stat_1,"l")
legend.AddEntry(h_2,stat_2,"l")
legend.AddEntry(h_3,stat_3,"l")
legend.AddEntry(h_4,stat_4,"l")
legend.Draw()

rt.gPad.Update()
canvas_name = str(energy)+"_EH_H_MIP_like"
c.SaveAs("plots/EH_H_MIP_like/21_jan/"+canvas_name+".png")
