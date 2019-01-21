import os,sys,re,fileinput,string,shutil
import numpy as np
import ROOT as rt
from array import array
from ROOT import TCanvas, TFile, TPaveText, TPaveStats
from ROOT import TLorentzVector
import math
from sys import argv

#print argv
#def generate_plot(h_def, h_2, h_nocut, can_)
# en = argv[1]



c = rt.TCanvas("c", "yolo", 600, 600); #FOR WebPage

#rt.gStyle.SetOptStat(1111);
rt.gStyle.SetOptStat(0);

#name='tree_Mmumu_ieta27_MC_NoPU'
#name='tree_Mmumu_ieta27_MC_wPU'
# name_official= '../../ntuple_719_official_v9'
# name_rereco = '../../ntuple_719_correct_tracking'

# name_official= '../../ntuple_719_correct_tracking'
# name_rereco = '../../ntuple_719_noise'

# if(en == "20"):
#     h_range = [0.0,6000.0]
# elif

h_range = [0.0,2500.0]
canvas_name = "20GeV_EE_FH_total"
#h_title = 'Rechit Energies'
h_title_1 = '20GeV (Config 1 Run:679-689)'
# h_title_1 = '50GeV (Config 1 Run:690-696)'
# h_title_1 = '80GeV (Config 1 Run:525-539)'
# h_title_1 = '100GeV (Config 1 Run:552-562)'
# h_title_1 = '120GeV (Config 1 Run:584-593)'


file_1 = '/home/shubham/work/HGCAL/CERNTB/oct2018TB/pion_files/v8/pion_data_679_689_config1_20GeV_v8_new.root'
#file_1 = '/home/shubham/work/HGCAL/CERNTB/oct2018TB/pion_files/v8/pion_data_690_696_config1_50GeV_v8_new.root'
#file_1 = '/home/shubham/work/HGCAL/CERNTB/oct2018TB/pion_files/v8/pion_data_525_539_config1_80GeV_v8_new.root'
#file_1 = '/home/shubham/work/HGCAL/CERNTB/oct2018TB/pion_files/v8/pion_data_552_562_config1_100GeV_v8_new.root'
#file_1 = '/home/shubham/work/HGCAL/CERNTB/oct2018TB/pion_files/v8/pion_data_584_593_config1_120GeV_v8_new.root'

in_file_1 = rt.TFile.Open(file_1)
if(not in_file_1):
    print "Could Not open ",file_1
    sys.exit()

# in_file_2 = rt.TFile.Open(file_2)
# if(not in_file_2):
#     print "Could Not open ",file_2
#     sys.exit()

# in_file_3 = rt.TFile.Open(file_3)
# if(not in_file_3):
#     print "Could Not open ",file_3
#     sys.exit()

# in_file_4 = rt.TFile.Open(file_4)
# if(not in_file_4):
#     print "Could Not open ",file_4
#     sys.exit()

# in_file_5 = rt.TFile.Open(file_5)
# if(not in_file_5):
#     print "Could Not open ",file_5
#     sys.exit()

#hist_name = "ADC_distributions/EE_1/h_TS3HG_EE_L1_P0_chip2_chan36"
hist_name_1 = "h_rechit_energy_EE_only"
hist_name_2 = "h_rechit_energy_FH_only"
hist_name_3 = "h_rechit_energy_all"
h_1 = in_file_1.Get(hist_name_1)

if(not h_1):
    print "Could Not Load ",hist_name
    sys.exit()

h_2 = in_file_1.Get(hist_name_2)
if(not h_2):
    print "Could Not Load ",hist_name
    sys.exit()

h_3 = in_file_1.Get(hist_name_3)
if(not h_3):
    print "Could Not Load ",hist_name
    sys.exit()


# h_4 = in_file_4.Get(hist_name)
# if(not h_4):
#     print "Could Not Load ",hist_name
#     sys.exit()


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
stat_1 = 'EE'
stat_2 = 'FH'
stat_3 = 'EE+FH'
# stat_4 = '100GeV (Config 1 Run:552-562)'
# stat_5 = '120GeV (Config 1 Run:584-593)'


h_1.SetLineWidth(2);
h_1.SetLineStyle(1);
h_1.SetName(stat_1)
h_1.GetXaxis().SetTitleSize(0.04);
h_1.GetXaxis().SetLabelSize(0.035);
h_1.GetYaxis().SetLabelSize(0.03);
h_1.GetXaxis().SetTitle("Rechit Energy (units of MIPs)");
# h_1.GetYaxis().SetTitle("# of entries");
h_1.GetXaxis().SetTitleOffset(0.9);
h_1.GetYaxis().SetTitleOffset(1.45);
h_1.SetTitle(h_title_1)
#h_1.SetTitle(stat_1)

h_2.SetLineWidth(2);
h_2.SetLineStyle(1);
#h_2.SetLineColor(rt.kRed-1)
h_2.SetLineColor(rt.kRed)
h_2.SetName(stat_2)
h_2.GetXaxis().SetTitleSize(0.04);
h_2.GetXaxis().SetLabelSize(0.035);
h_2.GetYaxis().SetLabelSize(0.03);
h_2.GetXaxis().SetTitle("Rechit Energy (units of MIPs)");
# h_2.GetYaxis().SetTitle("# of entries");
h_2.GetXaxis().SetTitleOffset(0.9);
h_2.GetYaxis().SetTitleOffset(1.45);
h_2.SetTitle(h_title_1)
#h_2.SetTitle(stat_1)

h_3.SetLineWidth(2);
h_3.SetLineStyle(2);
h_3.SetLineColor(rt.kBlack)
h_3.SetName(stat_3)
h_3.GetXaxis().SetTitleSize(0.04);
h_3.GetXaxis().SetLabelSize(0.035);
h_3.GetYaxis().SetLabelSize(0.03);
h_3.GetXaxis().SetTitle("Rechit Energy (units of MIPs)");
# h_3.GetYaxis().SetTitle("Normalized to # of entries");
h_3.GetXaxis().SetTitleOffset(0.9);
h_3.GetYaxis().SetTitleOffset(1.45);
h_3.SetTitle(h_title_1)
# h_3.SetTitle(stat_1)


# h_4.SetLineWidth(2);
# h_4.SetLineStyle(1);
# h_4.SetLineColor(rt.kMagenta)
# h_4.SetName(stat_4)
# h_4.GetXaxis().SetTitleSize(0.04);
# h_4.GetXaxis().SetLabelSize(0.035);
# h_4.GetYaxis().SetLabelSize(0.03);
# h_4.GetXaxis().SetTitle("Rechit Energy EE+FH (units of MIPs)");
# h_4.GetYaxis().SetTitle("Normalized to # of entries");
# h_4.GetXaxis().SetTitleOffset(0.9);
# h_4.GetYaxis().SetTitleOffset(1.45);
# h_4.SetTitle(h_title)


# h_5.SetLineWidth(2);
# h_5.SetLineStyle(1);
# h_5.SetLineColor(rt.kGreen+2)
# h_5.SetName(stat_5)
# h_5.GetXaxis().SetTitleSize(0.04);
# h_5.GetXaxis().SetLabelSize(0.035);
# h_5.GetYaxis().SetLabelSize(0.03);
# h_5.GetXaxis().SetTitle("Rechit Energy EE+FH (units of MIPs)");
# h_5.GetYaxis().SetTitle("Normalized to # of entries");
# h_5.GetXaxis().SetTitleOffset(0.9);
# h_5.GetYaxis().SetTitleOffset(1.45);
# h_5.SetTitle(h_title)

# h_1.GetYaxis().SetRangeUser(0.0,10000.0);
# h_2.GetYaxis().SetRangeUser(0.0,10000.0);
# h_3.GetYaxis().SetRangeUser(0.0,10000.0);
# h_4.GetYaxis().SetRangeUser(0.0,10000.0);


h_1.GetXaxis().SetRangeUser(h_range[0],h_range[1]);
h_2.GetXaxis().SetRangeUser(h_range[0],h_range[1]);
h_3.GetXaxis().SetRangeUser(h_range[0],h_range[1]);
# h_4.GetXaxis().SetRangeUser(0.0,8000.0);
# h_5.GetXaxis().SetRangeUser(0.0,8000.0);

# h_1.Draw("hist")
# h_2.Draw("hist sames")
# h_3.Draw("hist sames")

#gaus_1 = rt.TF1("gaus_1","gaus(0)",0,10000)
# gaus_1 = rt.TF1("gaus_1","gaus(0)",250,350)
# gaus_1.SetParameters(1.0,300,50)
# # h_1.Fit("gaus_1","","",200,300)
# # gaus_1.Draw("sames")
# h_1.Fit("gaus_1")

h_1.Draw("hist")
h_2.Draw("hist sames")
h_3.Draw("hist sames")
# h_4.Draw("hist sames")
# h_5.Draw("hist sames")




#legend = rt.TLegend(0.5,0.8,0.5,0.8)
# legend = rt.TLegend(0.60,0.9,0.9,0.778)
legend = rt.TLegend(0.40,0.9,0.9,0.65)

legend.AddEntry(h_1,stat_1,"l")
legend.AddEntry(h_2,stat_2,"l")
legend.AddEntry(h_3,stat_3,"l")
# legend.AddEntry(h_4,stat_4,"l")
# legend.AddEntry(h_5,stat_5,"l")
legend.Draw()

rt.gPad.Update()




# c.SaveAs("plots/"+canvas_name+".png")
c.SaveAs("plots/"+canvas_name+".png")
