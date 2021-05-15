import os,sys,re,fileinput,string,shutil
import numpy as np
import ROOT as rt
from array import array
from ROOT import TCanvas, TFile, TPaveText, TPaveStats
from ROOT import TLorentzVector
import math
import sys

energy = int(sys.argv[1])
save = int(sys.argv[2])
save_ = False
if(save == 1):
	save_ = True


#def generate_plot(h_def, h_maxzero, h_nocut, can_)

#rt.gROOT.SetBatch()

c = rt.TCanvas("c", "c", 650, 500) #FOR Slides
#c = rt.TCanvas("c", "yolo", 300, 267); #FOR Slides
rt.gStyle.SetOptStat(0)
#c->SetRightMargin(0.009);
 #c->SetLeftMargin(0.11);
#c.SetTopMargin(0.05)



in_file = rt.TFile.Open("./data/test%d.root"%(energy))
if(not in_file):
    print "Could Not open ./data/test%d.root"%(energy)
    sys.exit()



h_def = in_file.Get("h_rechit_energy_EE_FHAH_inclusive")

if(not h_def):
    print "Could Not Load h_rechit_energy_EE_FHAH_inclusive"
    sys.exit()


h_title = str(energy)+' GeV pion Simulation'

#h_def.SetLineWidth(2);
#h_def.SetLineStyle(1);
#h_def.SetName(stat_default)
h_def.GetXaxis().SetTitleSize(0.04);
h_def.GetYaxis().SetTitleSize(0.04);


h_def.GetXaxis().SetLabelSize(0.032);
h_def.GetYaxis().SetLabelSize(0.032);
h_def.GetXaxis().SetTitleOffset(0.9);
h_def.GetYaxis().SetTitleOffset(1.2);
h_def.SetTitle("")

if(energy == 100):
	h_def.GetXaxis().SetRangeUser(0.0,10000.0);
	h_def.GetYaxis().SetRangeUser(0.0,6000.0);
if(energy == 50):
	h_def.GetXaxis().SetRangeUser(0.0,6000.0);
	h_def.GetYaxis().SetRangeUser(0.0,3000.0);
if(energy == 200):
	h_def.GetXaxis().SetRangeUser(0.0,20000.0);
	h_def.GetYaxis().SetRangeUser(0.0,10000.0);

h_def.Draw("colz")
#h_def.Draw("BOX")

textOnTop = rt.TLatex()
textOnTop.SetTextSize(0.035)
textOnTop.DrawLatexNDC(0.12,0.92,"CMS #it{#bf{Preliminary}}")

textOnTop.SetTextSize(0.04)
#textOnTop.DrawLatexNDC(0.6,0.96,"%d GeV/c, #pi^{-} beam"%(energy))

textOnTop.DrawLatexNDC(0.4,0.85,"#bf{Inclusive in shower start location}")
textOnTop.DrawLatexNDC(0.5,0.80,"%d GeV/c, #pi^{-} beam"%(energy))


#t = rt.TText(0.5,0.94,"Showering in FH");
# t = rt.TText(0.5,0.90,h_title);
# t.SetNDC();
# t.SetTextAlign(22);
# t.SetTextColor(rt.kBlack);
# t.SetTextFont(43);
# t.SetTextSize(20);
# t.Draw();

# t1 = rt.TText(0.5,0.85,text);
# t1.SetNDC();
# t1.SetTextAlign(22);
# t1.SetTextColor(rt.kBlack);
# t1.SetTextFont(43);
# t1.SetTextSize(15);
# t1.Draw();
rt.gPad.SetLogz()
rt.gPad.Update();
rt.gPad.Modified();


save_name = "./plots/energySharing_mips_%dGeV"%(energy)
print save_name
if(save_):
	c.SaveAs(save_name+".png")
	# c.SaveAs(save_name+".jpg")
	# c.SaveAs(save_name+".gif")
	# c.SaveAs(save_name+".C")
	# c.SaveAs(save_name+".root")
	c.SaveAs(save_name+".pdf")
