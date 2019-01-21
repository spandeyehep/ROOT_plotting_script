import os,sys,re,fileinput,string,shutil
import numpy as np
import ROOT as rt
from array import array
from ROOT import TCanvas, TFile, TPaveText, TPaveStats
from ROOT import TLorentzVector
import math


#def generate_plot(h_def, h_2, h_nocut, can_)



canvas_name = "pion_energy"
c = rt.TCanvas("c", "yolo", 600, 600); #FOR WebPage

#rt.gStyle.SetOptStat(1111);
rt.gStyle.SetOptStat(0);

#name='tree_Mmumu_ieta27_MC_NoPU'
#name='tree_Mmumu_ieta27_MC_wPU'
# name_official= '../../ntuple_719_official_v9'
# name_rereco = '../../ntuple_719_correct_tracking'

# name_official= '../../ntuple_719_correct_tracking'
# name_rereco = '../../ntuple_719_noise'


file_1 = '/home/shubham/work/HGCAL/CERNTB/oct2018TB/pion_files/v8/20_jan_2019/test_20GeV_energy_v1.root'
file_2 = '/home/shubham/work/HGCAL/CERNTB/oct2018TB/pion_files/v8/20_jan_2019/test_50GeV_energy_v1.root'
file_3 = '/home/shubham/work/HGCAL/CERNTB/oct2018TB/pion_files/v8/20_jan_2019/test_80GeV_energy_v1.root'
file_4 = '/home/shubham/work/HGCAL/CERNTB/oct2018TB/pion_files/v8/20_jan_2019/test_100GeV_energy_v1.root'
file_5 = '/home/shubham/work/HGCAL/CERNTB/oct2018TB/pion_files/v8/20_jan_2019/test_120GeV_energy_v1.root'
file_6 = '/home/shubham/work/HGCAL/CERNTB/oct2018TB/pion_files/v8/20_jan_2019/test_200GeV_energy_v1.root'
file_7 = '/home/shubham/work/HGCAL/CERNTB/oct2018TB/pion_files/v8/20_jan_2019/test_250GeV_energy_v1.root'
file_8 = '/home/shubham/work/HGCAL/CERNTB/oct2018TB/pion_files/v8/20_jan_2019/test_300GeV_energy_v1.root'

#file_name = [""]*8

in_file_1 = rt.TFile.Open(file_1)
if(not in_file_1):
    print "Could Not open ",file_1
    sys.exit()

in_file_2 = rt.TFile.Open(file_2)
if(not in_file_2):
    print "Could Not open ",file_2
    sys.exit()

in_file_3 = rt.TFile.Open(file_3)
if(not in_file_3):
    print "Could Not open ",file_3
    sys.exit()

in_file_4 = rt.TFile.Open(file_4)
if(not in_file_4):
    print "Could Not open ",file_4
    sys.exit()

in_file_5 = rt.TFile.Open(file_5)
if(not in_file_5):
    print "Could Not open ",file_5
    sys.exit()

in_file_6 = rt.TFile.Open(file_6)
if(not in_file_6):
    print "Could Not open ",file_6
    sys.exit()


in_file_7 = rt.TFile.Open(file_7)
if(not in_file_7):
    print "Could Not open ",file_7
    sys.exit()

in_file_8 = rt.TFile.Open(file_8)
if(not in_file_8):
    print "Could Not open ",file_8
    sys.exit()

#hist_name = "ADC_distributions/EE_1/h_TS3HG_EE_L1_P0_chip2_chan36"

hist_name = "h_energy_EEFH_MIPEE"

h_1 = in_file_1.Get(hist_name)
if(not h_1):
    print "Could Not Load ",hist_name
    sys.exit()

h_2 = in_file_2.Get(hist_name)
if(not h_2):
    print "Could Not Load ",hist_name
    sys.exit()

h_3 = in_file_3.Get(hist_name)
if(not h_3):
    print "Could Not Load ",hist_name
    sys.exit()


h_4 = in_file_4.Get(hist_name)
if(not h_4):
    print "Could Not Load ",hist_name
    sys.exit()


h_5 = in_file_5.Get(hist_name)
if(not h_5):
    print "Could Not Load ",hist_name
    sys.exit()


h_6 = in_file_6.Get(hist_name)
if(not h_6):
    print "Could Not Load ",hist_name
    sys.exit()

h_7 = in_file_7.Get(hist_name)
if(not h_7):
    print "Could Not Load ",hist_name
    sys.exit()

h_8 = in_file_8.Get(hist_name)
if(not h_8):
    print "Could Not Load ",hist_name
    sys.exit()





    
# h_1.Scale(1.0/h_1.Integral())
# h_2.Scale(1.0/h_2.Integral())
# h_3.Scale(1.0/h_3.Integral())
# h_4.Scale(1.0/h_4.Integral())
# h_5.Scale(1.0/h_5.Integral())
# h_6.Scale(1.0/h_6.Integral())
# h_7.Scale(1.0/h_7.Integral())
# h_8.Scale(1.0/h_8.Integral())

hist_mean_1 = h_1.GetMean()
hist_mean_2 = h_2.GetMean()
hist_mean_3 = h_3.GetMean()
hist_mean_4 = h_4.GetMean()
hist_mean_5 = h_5.GetMean()
hist_mean_6 = h_6.GetMean()
hist_mean_7 = h_7.GetMean()
hist_mean_8 = h_8.GetMean()

hist_RMS_1 = h_1.GetRMS()
hist_RMS_2 = h_2.GetRMS()
hist_RMS_3 = h_3.GetRMS()
hist_RMS_4 = h_4.GetRMS()
hist_RMS_5 = h_5.GetRMS()
hist_RMS_6 = h_6.GetRMS()
hist_RMS_7 = h_7.GetRMS()
hist_RMS_8 = h_8.GetRMS()


#print '(hist_mean:'+str(round(hist_mean_1,2))+', hist_RMS:'+str(round(hist_RMS_1,2))+')'
stat_1 = '20GeV (hist_mean:'+str(round(hist_mean_1,2))+', hist_RMS:'+str(round(hist_RMS_1,2))+')'
stat_2 = '50GeV (hist_mean:'+str(round(hist_mean_2,2))+', hist_RMS:'+str(round(hist_RMS_2,2))+')'
stat_3 = '80GeV (hist_mean:'+str(round(hist_mean_3,2))+', hist_RMS:'+str(round(hist_RMS_3,2))+')'
stat_4 = '100GeV (hist_mean:'+str(round(hist_mean_4,2))+', hist_RMS:'+str(round(hist_RMS_4,2))+')'
stat_5 = '120GeV (hist_mean:'+str(round(hist_mean_5,2))+', hist_RMS:'+str(round(hist_RMS_5,2))+')'
stat_6 = '200GeV (hist_mean:'+str(round(hist_mean_6,2))+', hist_RMS:'+str(round(hist_RMS_6,2))+')'
stat_7 = '250GeV (hist_mean:'+str(round(hist_mean_7,2))+', hist_RMS:'+str(round(hist_RMS_7,2))+')'
stat_8 = '300GeV (hist_mean:'+str(round(hist_mean_8,2))+', hist_RMS:'+str(round(hist_RMS_8,2))+')'


# stat_1 = '20GeV'
# stat_2 = '50GeV'
# stat_3 = '80GeV'
# stat_4 = '100GeV'
# stat_5 = '120GeV'
# stat_6 = '200GeV'
# stat_7 = '250GeV'
# stat_8 = '300GeV'



h_title = 'H-Hadrons (pion starting shower in FH)'

h_1.SetLineWidth(2);
h_1.SetLineStyle(1);
h_1.SetName(stat_1)
h_1.GetXaxis().SetTitleSize(0.04);
h_1.GetXaxis().SetLabelSize(0.035);
h_1.GetYaxis().SetLabelSize(0.03);
h_1.GetXaxis().SetTitle("Energy in FH (units of MIPs)");
h_1.GetYaxis().SetTitle("# of entries");
h_1.GetXaxis().SetTitleOffset(0.9);
h_1.GetYaxis().SetTitleOffset(1.45);
h_1.SetTitle(h_title)

h_2.SetLineWidth(2);
h_2.SetLineStyle(1);
h_2.SetLineColor(rt.kCyan+2)
# h_2.SetLineColor(rt.kBlue-7)
h_2.SetName(stat_2)
h_2.GetXaxis().SetTitleSize(0.04);
h_2.GetXaxis().SetLabelSize(0.035);
h_2.GetYaxis().SetLabelSize(0.03);
h_2.GetXaxis().SetTitle("Energy in FH (units of MIPs)");
h_2.GetYaxis().SetTitle("# of entries");
h_2.GetXaxis().SetTitleOffset(0.9);
h_2.GetYaxis().SetTitleOffset(1.45);
h_2.SetTitle(h_title)

h_3.SetLineWidth(2);
h_3.SetLineStyle(1);
h_3.SetLineColor(rt.kBlack)
h_3.SetName(stat_3)
h_3.GetXaxis().SetTitleSize(0.04);
h_3.GetXaxis().SetLabelSize(0.035);
h_3.GetYaxis().SetLabelSize(0.03);
h_3.GetXaxis().SetTitle("Energy in FH (units of MIPs)");
h_3.GetYaxis().SetTitle("# of entries");
h_3.GetXaxis().SetTitleOffset(0.9);
h_3.GetYaxis().SetTitleOffset(1.45);
h_3.SetTitle(h_title)


h_4.SetLineWidth(2);
h_4.SetLineStyle(1);
h_4.SetLineColor(rt.kMagenta)
h_4.SetName(stat_4)
h_4.GetXaxis().SetTitleSize(0.04);
h_4.GetXaxis().SetLabelSize(0.035);
h_4.GetYaxis().SetLabelSize(0.03);
h_4.GetXaxis().SetTitle("Energy in FH (units of MIPs)");
h_4.GetYaxis().SetTitle("# of entries");
h_4.GetXaxis().SetTitleOffset(0.9);
h_4.GetYaxis().SetTitleOffset(1.45);
h_4.SetTitle(h_title)


h_5.SetLineWidth(2);
h_5.SetLineStyle(1);
h_5.SetLineColor(rt.kGreen+2)
h_5.SetName(stat_5)
h_5.GetXaxis().SetTitleSize(0.04);
h_5.GetXaxis().SetLabelSize(0.035);
h_5.GetYaxis().SetLabelSize(0.03);
h_5.GetXaxis().SetTitle("Energy in FH (units of MIPs)");
h_5.GetYaxis().SetTitle("# of entries");
h_5.GetXaxis().SetTitleOffset(0.9);
h_5.GetYaxis().SetTitleOffset(1.45);
h_5.SetTitle(h_title)


h_6.SetLineWidth(2);
h_6.SetLineStyle(1);
h_6.SetLineColor(rt.kMagenta+2)
h_6.SetName(stat_6)
h_6.GetXaxis().SetTitleSize(0.04);
h_6.GetXaxis().SetLabelSize(0.035);
h_6.GetYaxis().SetLabelSize(0.03);
h_6.GetXaxis().SetTitle("Energy in FH (units of MIPs)");
h_6.GetYaxis().SetTitle("# of entries");
h_6.GetXaxis().SetTitleOffset(0.9);
h_6.GetYaxis().SetTitleOffset(1.45);
h_6.SetTitle(h_title)


h_7.SetLineWidth(2);
h_7.SetLineStyle(1);
h_7.SetLineColor(rt.kGreen+2)
h_7.SetName(stat_7)
h_7.GetXaxis().SetTitleSize(0.04);
h_7.GetXaxis().SetLabelSize(0.035);
h_7.GetYaxis().SetLabelSize(0.03);
h_7.GetXaxis().SetTitle("Energy in FH (units of MIPs)");
h_7.GetYaxis().SetTitle("# of entries");
h_7.GetXaxis().SetTitleOffset(0.9);
h_7.GetYaxis().SetTitleOffset(1.45);
h_7.SetTitle(h_title)


h_8.SetLineWidth(2);
h_8.SetLineStyle(1);
h_8.SetLineColor(rt.kGreen+2)
h_8.SetName(stat_8)
h_8.GetXaxis().SetTitleSize(0.04);
h_8.GetXaxis().SetLabelSize(0.035);
h_8.GetYaxis().SetLabelSize(0.03);
h_8.GetXaxis().SetTitle("Energy in FH (units of MIPs)");
h_8.GetYaxis().SetTitle("# of entries");
h_8.GetXaxis().SetTitleOffset(0.9);
h_8.GetYaxis().SetTitleOffset(1.45);
h_8.SetTitle(h_title)

# h_1.GetYaxis().SetRangeUser(0.0,10000.0);
# h_2.GetYaxis().SetRangeUser(0.0,10000.0);
# h_3.GetYaxis().SetRangeUser(0.0,10000.0);
# h_4.GetYaxis().SetRangeUser(0.0,10000.0);


h_1.GetXaxis().SetRangeUser(0.0,3000.0);
h_2.GetXaxis().SetRangeUser(0.0,3000.0);
h_3.GetXaxis().SetRangeUser(0.0,3000.0);
h_4.GetXaxis().SetRangeUser(0.0,3000.0);
h_5.GetXaxis().SetRangeUser(0.0,3000.0);
# h_6.GetXaxis().SetRangeUser(0.0,7000.0);
# h_7.GetXaxis().SetRangeUser(0.0,7000.0);
# h_8.GetXaxis().SetRangeUser(0.0,7000.0);

# h_1.Draw("hist")
# h_2.Draw("hist sames")
# h_3.Draw("hist sames")



h_1.Draw("hist")
h_2.Draw("hist sames")
h_3.Draw("hist sames")
h_4.Draw("hist sames")
h_5.Draw("hist sames")
# h_6.Draw("hist sames")
# h_7.Draw("hist sames")
# h_8.Draw("hist sames")


energy = array('d')
mean = array('d')
sigma = array('d')



fit_range_1 = [150,380]
gaus_1 = rt.TF1("gaus_1","gaus(0)",fit_range_1[0],fit_range_1[1])
gaus_1.SetParameters(4500.0,300,50)
h_1.Fit(gaus_1,"Q","",fit_range_1[0],fit_range_1[1])
gaus_1 = h_1.GetFunction("gaus_1")
energy.append(20.0)
mean.append(gaus_1.GetParameter(1))
sigma.append(gaus_1.GetParameter(2))
gaus_1.Draw("SAME")


fit_range_2 = [400,900]
gaus_2 = rt.TF1("gaus_2","gaus(0)",fit_range_2[0],fit_range_2[1])
gaus_2.SetParameters(1500.0,650,300)
h_2.Fit(gaus_2,"Q","",fit_range_2[0],fit_range_2[1])
gaus_2 = h_2.GetFunction("gaus_2")
energy.append(50.0)
mean.append(gaus_2.GetParameter(1))
sigma.append(gaus_2.GetParameter(2))
gaus_2.Draw("SAME")


fit_range_3 = [600,1400]
gaus_3 = rt.TF1("gaus_3","gaus(0)",fit_range_3[0],fit_range_3[1])
gaus_3.SetParameters(2000.0,1100,350)
h_3.Fit(gaus_3,"Q","",fit_range_3[0],fit_range_3[1])
gaus_3 = h_3.GetFunction("gaus_3")
energy.append(80.0)
mean.append(gaus_3.GetParameter(1))
sigma.append(gaus_3.GetParameter(2))
gaus_3.Draw("SAME")



fit_range_4 = [750,1700]
gaus_4 = rt.TF1("gaus_4","gaus(0)",fit_range_4[0],fit_range_4[1])
gaus_4.SetParameters(1000.0,1300,400)
h_4.Fit(gaus_4,"Q","",fit_range_4[0],fit_range_4[1])
gaus_4 = h_4.GetFunction("gaus_4")
energy.append(100.0)
mean.append(gaus_4.GetParameter(1))
sigma.append(gaus_4.GetParameter(2))
gaus_4.Draw("SAME")


fit_range_5 = [850,2200]
gaus_5 = rt.TF1("gaus_5","gaus(0)",fit_range_5[0],fit_range_5[1])
gaus_5.SetParameters(1000.0,1500,530)
h_5.Fit(gaus_5,"Q","",fit_range_5[0],fit_range_5[1])
gaus_5 = h_5.GetFunction("gaus_5")
energy.append(120.0)
mean.append(gaus_5.GetParameter(1))
sigma.append(gaus_5.GetParameter(2))
gaus_5.Draw("SAME")


rt.gPad.Update()


stat_1 = '20GeV (gaus_mean:'+str(round(mean[0],2))+', gaus_sigma:'+str(round(sigma[0],2))+')'
stat_2 = '50GeV (gaus_mean:'+str(round(mean[1],2))+', gaus_sigma:'+str(round(sigma[1],2))+')'
stat_3 = '80GeV (gaus_mean:'+str(round(mean[2],2))+', gaus_sigma:'+str(round(sigma[2],2))+')'
stat_4 = '100GeV (gaus_mean:'+str(round(mean[3],2))+', gaus_sigma:'+str(round(sigma[3],2))+')'
stat_5 = '120GeV (gaus_mean:'+str(round(mean[4],2))+', gaus_sigma:'+str(round(sigma[4],2))+')'


#legend = rt.TLegend(0.5,0.8,0.5,0.8)
# legend = rt.TLegend(0.60,0.9,0.9,0.778)
# legend = rt.TLegend(0.40,0.9,0.9,0.65)
legend = rt.TLegend(0.30,0.9,0.9,0.70)

legend.AddEntry(h_1,stat_1,"l")
legend.AddEntry(h_2,stat_2,"l")
legend.AddEntry(h_3,stat_3,"l")
legend.AddEntry(h_4,stat_4,"l")
legend.AddEntry(h_5,stat_5,"l")
# legend.AddEntry(h_6,stat_6,"l")
# legend.AddEntry(h_7,stat_7,"l")
# legend.AddEntry(h_8,stat_8,"l")
legend.Draw()

#c.SaveAs("plots/v2_20_jan/energy_hist_WITH_FIT_overlay.png")



'''

energy.append(20.0)
energy.append(50.0)
energy.append(80.0)
energy.append(100.0)
energy.append(120.0)

mean.append(hist_mean_1)
sigma.append(hist_RMS_1)
mean.append(hist_mean_2)
sigma.append(hist_RMS_2)
mean.append(hist_mean_3)
sigma.append(hist_RMS_3)
mean.append(hist_mean_4)
sigma.append(hist_RMS_4)
mean.append(hist_mean_5)
sigma.append(hist_RMS_5)

'''

#c1 = rt.TCanvas("c1","Response and Resolution",800,400)
c1 = rt.TCanvas("c1","Response and Resolution",500,250)

c1.Divide(2)

x_p, y1_p, y2_p = array( 'd' ),array( 'd' ),array( 'd' )
# x = [0,20,50,80,100,120]
# y1 = [0,20,50,80,100,120]
n1= 5

i = 0
while i < n1:
    print energy[i],"\t",mean[i],"\t",sigma[i]/mean[i]
    x_p.append(energy[i])
    y1_p.append(mean[i])
    y2_p.append(sigma[i]/mean[i])
    i+=1



gr1 = rt.TGraph(n1,x_p,y1_p)
gr2 = rt.TGraph(n1,x_p,y2_p)

gr1.SetTitle("Energy linearity (mean)")
gr1.GetXaxis().SetTitleSize(0.04);
gr1.GetXaxis().SetLabelSize(0.06);
gr1.GetYaxis().SetLabelSize(0.05);
# gr1.GetYaxis().SetLabelSize(0.04);
#gr1.GetXaxis().SetTitle("Beam Energy (in GeV)");
#gr1.GetYaxis().SetTitle("Mean (in MIPs)");
# gr1.GetXaxis().SetTitleOffset(0.9);
gr1.GetXaxis().SetTitleOffset(1.0);

gr1.GetXaxis().SetTitleSize(0.5);
gr1.GetYaxis().SetTitleOffset(1.45);
gr1.SetMarkerColor( 4 )
gr1.SetMarkerSize( 2 )
gr1.SetMarkerStyle( 21 )
gr1.GetXaxis().SetRangeUser(0,150)
gr1.GetYaxis().SetRangeUser(0,2000)

gr2.SetTitle("Resolution (Sigma/Mean)")
gr2.GetXaxis().SetTitleSize(0.04);
# gr2.GetXaxis().SetLabelSize(0.035);
# gr2.GetYaxis().SetLabelSize(0.03);

gr2.GetXaxis().SetLabelSize(0.06);
gr2.GetYaxis().SetLabelSize(0.05);

gr2.GetYaxis().SetRangeUser(0.30,0.40)
# gr2.GetYaxis().SetLabelSize(0.04);
#gr2.GetXaxis().SetTitle("Beam Energy (in GeV)");
#gr2.GetYaxis().SetTitle("Sigma/Mean");
gr2.GetXaxis().SetTitleOffset(0.9);
gr2.GetYaxis().SetTitleOffset(1.45);
# gr2.GetYaxis().SetTitleOffset(2.0);
gr2.SetMarkerColor( 4 )
gr2.SetMarkerSize( 2 )
gr2.SetMarkerStyle( 21 )
gr2.GetXaxis().SetRangeUser(0,150)

c1.cd(1)
rt.gPad.SetGridx()
rt.gPad.SetGridy()

# gr1.Draw("AC*")
gr1.Draw("A*")

c1.cd(2)
gr2.Draw("A*")
rt.gPad.SetGridx()
rt.gPad.SetGridy()
c1.Update()
rt.gPad.Update()
c1.SaveAs("plots/v2_20_jan/GAUS_FIT_mean_sigma.png")


