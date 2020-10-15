import os,sys,re,fileinput,string,shutil
import numpy as np
import ROOT as rt
from array import array
from ROOT import TCanvas, TFile, TPaveText, TPaveStats
from ROOT import TLorentzVector
import math

hadrons = sys.argv[1]
weight = int(sys.argv[2])
save_ = int(sys.argv[3])

save = False
if(save_ == 1):
	save = True
inFileName = "./chi2_calib_factors_%s_hadrons_DATA.txt"%(hadrons)
inFile = open(inFileName,"r")

pions = {
	"EH" : "Showering in CE-E",
	"H" : "MIPs in CE-E"
}
E_total = {
	"EH" : "E_{total} = w_{1}*EE + w_{2}*FH+ w_{3}*AH",
	"H" : "E_{total} = w'_{1}*FH+ w'_{2}*AH"
}

energy, w1, w2, w3 = array( 'd' ),array( 'd' ),array( 'd' ),array( 'd' )
graph_xaxis_title = ["w1","w2","w3"]
energy_ = [20.0, 50.0, 80.0, 100.0, 120.0, 200.0, 250.0, 300.0]
n = 8
for i,line in enumerate(inFile):
	energy.append(energy_[i])
	#print line.split(" ")[1]," :: ",line.split(" ")[1]," :: ",line.split(" ")[3][:-1]
	w1.append(float(line.split(" ")[1]))
	w2.append(float(line.split(" ")[2]))
	w3.append(float(line.split(" ")[3][:-1]))
	print "energy:w1:w2:w3 :: %f:%f:%f:%f"%(energy[i],w1[i],w2[i],w3[i])




graph = list()
graph_temp = rt.TGraph(n,energy,w1)
graph.append(graph_temp)
graph_temp = rt.TGraph(n,energy,w2)
graph.append(graph_temp)
graph_temp = rt.TGraph(n,energy,w3)
graph.append(graph_temp)

for i in range(3):
	if(i+1 != weight):
		continue
	if(hadrons == "H" and i == 0):
		continue
	c_temp = rt.TCanvas(graph_xaxis_title[i],graph_xaxis_title[i], 600, 450); #FOR WebPage
	graph[i].SetTitle("")
	graph[i].GetXaxis().SetTitleSize(1.0);
	graph[i].GetXaxis().SetLabelSize(0.035);
	graph[i].GetYaxis().SetLabelSize(0.035);
	graph[i].GetXaxis().SetTitle("Beam Energy [GeV]");
	if(hadrons == "EH"):
		graph[i].GetYaxis().SetTitle(graph_xaxis_title[i]);
	else:
		graph[i].GetYaxis().SetTitle(graph_xaxis_title[i-1]);
	#graph[i].GetXaxis().SetTitleOffset(1.0);
	graph[i].GetXaxis().SetTitleSize(0.035);
	graph[i].GetYaxis().SetTitleOffset(1.5);
	graph[i].SetMarkerColor( 4 )
	graph[i].SetMarkerSize( 1.3 )
	graph[i].SetMarkerStyle( 22 )
	graph[i].Draw("AP")

	

	# f = rt.TF1("reso","sqrt([0]*[0] + [1]*[1]/x + [2]*[2]/x^2)",20,300)
	# f.SetParameters(1.2,5,0.001)

	f = rt.TF1("reso","sqrt( [0]*[0] + [1]*[1]/x ) ",20,300)
	f.SetParameters(1.2,5)
	#f.FixParameter(0,0.98)
	
	
	graph[i].Fit(f,"Q","R",20,300)
	print "Eval at 100 GeV: %0.2f"%(f.Eval(100))
	print "Eval at 500 GeV: %0.2f"%(f.Eval(500))
	f.Draw("SAME")

	spline3 = rt.TSpline3("Test",energy,w3,8,"b1e1",f.Derivative(20),f.Derivative(300))
	spline3.SetLineColor(rt.kGreen)
	spline3.SetLineWidth(2)
	spline3.SetMarkerColor(rt.kBlue)
	spline3.SetMarkerStyle(20)
	spline3.SetMarkerSize(0.01)
	spline3.Draw("lcpsame")
	
	spline3.SaveAs("./fits/spline_%s_w%d.C"%(hadrons,weight))
	# eps = (300.0-20.0)/1.e-5

	# spline5 = rt.TSpline5("Test",energy,f,8,"b1e1b2e2",f.Derivative(20),f.Derivative(300),(f.Derivative(20+eps)-f.Derivative(300))/eps,(f.Derivative(300)-f.Derivative(300-eps))/eps)
	# spline5.SetLineColor(rt.kMagenta)
	# spline5.SetLineWidth(2)
	# spline5.SetMarkerColor(rt.kBlue)
	# spline5.SetMarkerStyle(20)
	# spline5.SetMarkerSize(0.01)
	# spline5.Draw("lcpsame")

	textOnTop = rt.TLatex()
	textOnTop.SetTextSize(0.035)
	# textOnTop.DrawLatexNDC(0.10,0.91,"CMS #it{#bf{Preliminary}}")
	# textOnTop.DrawLatexNDC(0.55,0.85,pions[hadrons])
	# textOnTop.DrawLatexNDC(0.50,0.80,E_total[hadrons])
	rt.gPad.SetTickx()
	rt.gPad.SetTicky()
	rt.gPad.SetGridx()
	rt.gPad.SetGridy()
	c_temp.Modified()
	c_temp.Update()

	print "f = (sqrt([0]*[0]+[1]*[1]/x+[2]*[2]/(x*x)), 20, 300)"
	print "f.SetParameter(0,%f)"%(f.GetParameter(0))
	print "f.SetParameter(1,%f)"%(f.GetParameter(1))
	# print "f.SetParameter(2,%f)"%(f.GetParameter(2))

	if(save):
		if(hadrons == "EH"):
			c_temp.SaveAs("./fits/%s_%s_FIT.png"%(hadrons,graph_xaxis_title[i]))
		else:
			c_temp.SaveAs("./fits/%s_%s_FIT.png"%(hadrons,graph_xaxis_title[i-1]))


	

