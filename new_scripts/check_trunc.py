import os,sys,re,fileinput,string,shutil
import numpy as np
import ROOT as rt
from array import array
from ROOT import TCanvas, TFile, TPaveText, TPaveStats
from ROOT import TLorentzVector
import math


energy = int(sys.argv[1])

def TruncRMS(H, lvl):
  mx = H.GetMaximumBin()
  content = H.GetBinContent(mx)
  maxlim = lvl*H.Integral()
  mom = [0.0,0.0]
  nBinsX = H.GetNbinsX()
  mom[0] = H.GetBinContent(mx) * H.GetBinCenter(mx)
  #mom[1] = H.GetBinContent(mx) * pow(H.GetBinCenter(mx),2)
  mom[1] = H.GetBinContent(mx) * (H.GetBinCenter(mx)*H.GetBinCenter(mx))

  tt = 1
  while(content < maxlim and (mx+tt) < nBinsX and (mx+tt) > 0):
  #while(content < maxlim):
    content += H.GetBinContent(mx+tt);
    mom[0] += H.GetBinContent(mx+tt) * H.GetBinCenter(mx+tt)
    #mom[1] += H.GetBinContent(mx+tt) * pow(H.GetBinCenter(mx+tt),2)
    mom[1] += H.GetBinContent(mx+tt) * (H.GetBinCenter(mx+tt)*H.GetBinCenter(mx+tt))

    if(content < maxlim and (mx+tt) < nBinsX and (mx+tt) > 0):
    #if(content < maxlim):
      content += H.GetBinContent(mx-tt)
      mom[0] += H.GetBinContent(mx-tt) * H.GetBinCenter(mx-tt)
      #mom[1] += H.GetBinContent(mx-tt) * pow(H.GetBinCenter(mx-tt),2)
      mom[1] += H.GetBinContent(mx-tt) * (H.GetBinCenter(mx-tt)*H.GetBinCenter(mx-tt))
    

    tt += 1
  
  # print "Integral : ",H.Integral()
  # print "mom[0]:mom[1]:content :: ",mom[0],":",mom[1],":",content

  mom[0] = mom[0]/content
  #mom[1] = sqrt(mom[1]/content-pow(mom[0],2))
  #if(content-(mom[0]*mom[0]) == 0.0):
  # print "mom[0]",mom[0]
  # print "mom[1]/content",(mom[1]/content)
  # print "mom[0]*mom[0]",(mom[0]*mom[0])
  # print "(mom[1]/content)-(mom[0]*mom[0]) : ",((mom[1]/content)-(mom[0]*mom[0]))
  #mom[1] = math.sqrt(mom[1]/content-(mom[0]*mom[0]))
  mom[1] = math.sqrt(mom[1]/content-(mom[0]*mom[0]))
  return(mom)


file_i = "../data/data_pion%d_v16_v8_chi2method_3.root"%(energy)
hist_name = "selection_cut_check_showering_in_EE/h_trackwindow_SS2_reject"

inFile = rt.TFile.Open(file_i)

if(not inFile):
	print "Could not open file:",file_i
	sys.exit(0)

hist = inFile.Get(hist_name)

if(not hist):
	print "Could not load hist:",hist_name
	sys.exit(0)

truncatedMean = TruncRMS(hist, 0.9)[0]
truncatedRMS = TruncRMS(hist, 0.9)[1]

histmean = hist.GetMean()
histrms = hist.GetRMS()

print "histogram mean:RMS = %0.2f : %0.2f"%(histmean,histrms)
print "90%% truncated mean:RMS = %0.2f : %0.2f"%(truncatedMean,truncatedRMS)

truncatedMean = TruncRMS(hist, 0.95)[0]
truncatedRMS = TruncRMS(hist, 0.95)[1]

print "95%% truncated mean:RMS = %0.2f : %0.2f"%(truncatedMean,truncatedRMS)

truncatedMean = TruncRMS(hist, 1.0)[0]
truncatedRMS = TruncRMS(hist, 1.0)[1]

print "100%% truncated mean:RMS = %0.2f : %0.2f"%(truncatedMean,truncatedRMS)

truncatedMean = TruncRMS(hist, 0.001)[0]
truncatedRMS = TruncRMS(hist, 0.001)[1]

print "0.1%% truncated mean:RMS = %0.2f : %0.2f"%(truncatedMean,truncatedRMS)