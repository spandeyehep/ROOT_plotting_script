import os,sys,re,fileinput,string,shutil
import numpy as np
import ROOT as rt
from array import array
from ROOT import TCanvas, TFile, TPaveText, TPaveStats
from ROOT import TLorentzVector
import math


calib = sys.argv[1] # 'fixed', 'Ebeam', 'Ereco'
shower = sys.argv[2] # 'EE', 'FH', 'all'
method = sys.argv[3] # 'gaus', 'trunc90' , 'trunc95', 'trunc100', 'histmean'
sample = sys.argv[4]  # 'data', 'FTFP_BERT_EMN', 'QGSP_FTFP_BERT_EMN'
#version =  sys.argv[5] # 'scaled', 'unscaled'

#version = ["v44_VtxBeam_v3_correctFH10","v46_patchMIP"]

#scaling = int(sys.argv[5])
#flag =  int(sys.argv[3])
dir_name = "./sim"


rt.gROOT.SetBatch(1)
def calculateError(x,dx,y,dy,cov_):
    #print "YOLO = ",(np.square(dx/x))," : ",np.square(dy/y)," : ",2*np.square(cov_)/(x*y)
    #return ((x/y)*(np.sqrt(np.square(dx/x) + np.square(dy/y) - 2*cov_/(x*y))))
    return ((x/y)*(np.sqrt(np.square(dx/x) + np.square(dy/y))))

#def generate_plot(h_def, h_2, h_nocut, can_)

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




save_canvas = False
showResponse = True
canvas_name = "pion_energy"
c = rt.TCanvas("c", "yolo", 600, 600); #FOR WebPage

#rt.gStyle.SetOptStat(1111);
rt.gStyle.SetOptStat(0);
rt.gStyle.SetOptFit(0);
legend = rt.TLegend(0.30,0.9,0.9,0.35)
energy_ = [20,50,80,100,120,200,250,300]

to_draw = [7,6,5,4,3,2,1,0]


if(shower=="EE"):
    if(calib == "fixed"):
        hist_name = "shower_energy_reco/showering_in_EE/h_showerinEE_elecpi_scale"
    elif(calib == "Ebeam"):
        hist_name = "selection_cut_chi2/chi2_EE/h_trackwindow_SS2_reject_chi2_EE"
    elif(calib == "Ereco"):
        hist_name = "selection_cut_chi2/chi2_EE/h_trackwindow_SS2_reject_chi2_EE_recoE"
    h_title = 'Pion starting shower in CE-E'
elif(shower=="FH"):
    if(calib == "fixed"):
        hist_name = "shower_energy_reco/MIPs_in_EE/h_MIPsinEE_elecpi_scale"
    elif(calib == "Ebeam"):
        hist_name = "selection_cut_chi2/chi2_FH/h_trackwindow_chi2_FH"
    elif(calib == "Ereco"):
        hist_name = "selection_cut_chi2/chi2_FH/h_trackwindow_chi2_FH_recoE"
    h_title = 'Pion starting shower in CE-H'
elif(shower=="all"):
    if(calib == "fixed"):
        hist_name = "shower_energy_reco/h_inclusive_elecpi_scale"
    elif(calib == "Ebeam"):
        hist_name = "selection_cut_chi2/h_trackwindow_SS2_reject_chi2_all"
    elif(calib == "Ereco"):
        hist_name = "selection_cut_chi2/h_trackwindow_SS2_reject_chi2_all_recoE"
    h_title = 'Pion starting shower in CE-H'
else:
    print "ERROR: Invalid 2nd argument (use EE, FH)"
    quit()

file_i = list()
in_file_i = list()
h_i = list()
hist_mean_i = list()
hist_RMS_i = list()
stat_i = list()
fit_range_i = list()
gaus_i = list()
legText_i = list()
color = [rt.kBlue,rt.kCyan+2,rt.kBlack,rt.kGreen+2,rt.kMagenta,rt.kMagenta+2,rt.kOrange+2,rt.kGreen]
beamenergy = array('d')
mean = array('d')
sigma = array('d')
mean_e = array('d')
sigma_e = array('d')

maximum = -1.0

for i,energy in enumerate(energy_):
    if(sample == "data"):
        #file_i = dir_name+'/data_pion'+str(energy)+'_newChi2Calib_with100Mips_EE_cut_withGlobalCut.root'
        file_i = "./data/data_pion%d_v16_v8_chi2method_3.root"%(energy)
    else:
        dir_name = "/home/shubham/work/HGCAL/CERNTB/oct2018TB/octTB_plotting/withAHCAL/weight_scan/22_feb_2021_scaling_noscaling_shower_shapes/sim/unscaled"
        file_i = "%s/sim_pion%03d_%s_v46_patchMIP.root"%(dir_name,energy,sample)
    # else:
    #     print "Incorrect sample provided!!!!"
    #     sys.exit()

    in_file_i.append(rt.TFile.Open(file_i))
    if(not in_file_i[i]):
        print "Could Not open ",file_i
        sys.exit()
    
    
    
    h_i.append(in_file_i[i].Get(hist_name))
    if(not h_i[i]):
        print "Could Not Load ",hist_name
        sys.exit()

    if(method == "gaus"):
        h_i[i].Scale(1.0/h_i[i].Integral())
        h_i[i].GetYaxis().SetRangeUser(0.0,0.1)
        
    

    maximum = h_i[i].GetMaximum()

    hist_mean_i.append(h_i[i].GetMean())
    hist_RMS_i.append(h_i[i].GetRMS())

    stat_i.append(str(energy)+'GeV (hist_mean:'+str(round(hist_mean_i[i],2))+', hist_RMS:'+str(round(hist_RMS_i[i],2))+')')
    x_title = "Energy (in GeV)"
    h_i[i].SetLineWidth(1);
    h_i[i].SetLineStyle(1);
    h_i[i].SetLineColor(color[i])
    h_i[i].SetName(stat_i[i])
    h_i[i].GetXaxis().SetTitleSize(0.04);
    h_i[i].GetXaxis().SetLabelSize(0.035);
    h_i[i].GetYaxis().SetLabelSize(0.03);
    h_i[i].GetXaxis().SetTitle(x_title);
    h_i[i].GetYaxis().SetTitle("Normalized # of entries");
    h_i[i].GetXaxis().SetTitleOffset(0.9);
    h_i[i].GetYaxis().SetTitleOffset(1.45);
    h_i[i].SetTitle(h_title)
    # h_i[i].GetYaxis().SetRangeUser(0.0,0.085);
    # h_i[i].GetXaxis().SetRangeUser(0.0,450.0);
   
    if(method == "gaus"):
        fit_range_i = [hist_mean_i[i] - 1.5*hist_RMS_i[i], hist_mean_i[i] + hist_RMS_i[i]]
        gaus_i.append(rt.TF1("gaus_"+str(i+1),"gaus(0)",fit_range_i[0],fit_range_i[1]))
        #gaus_1.SetParameters(4500.0,300,50)
        gaus_i[i].SetParameters(1000.0,hist_mean_i[i],  hist_RMS_i[i])
        h_i[i].Fit(gaus_i[i],"Q","",fit_range_i[0],fit_range_i[1])
        gaus_i[i] = h_i[i].GetFunction("gaus_"+str(i+1))
        fit_range_i = [gaus_i[i].GetParameter(1) - 1.5*gaus_i[i].GetParameter(2), gaus_i[i].GetParameter(1) + 1.5*gaus_i[i].GetParameter(2)]
        h_i[i].Fit(gaus_i[i],"Q","",fit_range_i[0],fit_range_i[1])
        gaus_i[i] = h_i[i].GetFunction("gaus_"+str(i+1))
        fit_range_i = [gaus_i[i].GetParameter(1) - 1.5*gaus_i[i].GetParameter(2), gaus_i[i].GetParameter(1) + 1.5*gaus_i[i].GetParameter(2)]
        h_i[i].Fit(gaus_i[i],"Q","",fit_range_i[0],fit_range_i[1])
        mean.append(gaus_i[i].GetParameter(1))
        sigma.append(gaus_i[i].GetParameter(2))
        mean_e.append(gaus_i[i].GetParError(1))
        sigma_e.append(gaus_i[i].GetParError(2))

    elif(method == "trunc90"):
        truncatedMean = TruncRMS(h_i[i], 0.9)[0]
        truncatedRMS = TruncRMS(h_i[i], 0.9)[1]
        mean.append(truncatedMean)
        sigma.append(truncatedRMS)
        mean_e.append(0.0)
        sigma_e.append(0.0)

    elif(method == "trunc95"):
        truncatedMean = TruncRMS(h_i[i], 0.95)[0]
        truncatedRMS = TruncRMS(h_i[i], 0.95)[1]
        mean.append(truncatedMean)
        sigma.append(truncatedRMS)
        mean_e.append(0.0)
        sigma_e.append(0.0)

    elif(method == "trunc100"):
        truncatedMean = TruncRMS(h_i[i], 1.0)[0]
        truncatedRMS = TruncRMS(h_i[i], 1.0)[1]
        mean.append(truncatedMean)
        sigma.append(truncatedRMS)
        mean_e.append(0.0)
        sigma_e.append(0.0)

    elif(method == "histmean"):
        histMean = h_i[i].GetMean()
        histRMS = h_i[i].GetRMS()
        mean.append(histMean)
        sigma.append(histRMS)
        mean_e.append(0.0)
        sigma_e.append(0.0)
        #print "E:mean:RMS :: %d : %f : %f"%(int(beamenergy),float(truncatedMean),float(truncatedRMS))

    else:
        print "Incorrect method provided!!!!"
        sys.exit()
    beamenergy.append(int(energy))
   
    #gaus_i[i].Draw("SAME")

    print beamenergy[i],'\t',mean[i],'\t',sigma[i],'\t',(sigma[i]/mean[i])*100

    
    legText_i.append(str(energy)+'GeV (gaus_mean:'+str(round(mean[i],2))+', gaus_sigma:'+str(round(sigma[i],2))+')')
    legend.AddEntry(h_i[i],legText_i[i],"l")
rt.gPad.Update()
rt.gPad.Modified()
for i in to_draw:
    #h_i[i].GetYaxis().SetRangeUser(0.0,maximum*1.12)
    
    if(i == 7):
        h_i[i].Draw("hist")
    else:
        h_i[i].Draw("hist sames")
    if(method == "gaus"):
        gaus_i[i].Draw("SAME")


legend.Draw()
rt.gPad.Update()
rt.gPad.Modified()



if(save_canvas):
    #c.SaveAs("plots/"+str(sample)+"_energy_hist_WITH_FIT_overlay.png")
    c.SaveAs("plots/gaus_fits_for_resp_reso/%s_chi2method%s_energy_hist_WITH_FIT_overlay_%s_%s.png"%(sample,calib,shower,method))
    # c.SaveAs("plots/energy_hist_WITH_FIT_overlay.jpg")
    # c.SaveAs("plots/energy_hist_WITH_FIT_overlay.gif")
    # c.SaveAs("plots/energy_hist_WITH_FIT_overlay.C")
    # c.SaveAs("plots/energy_hist_WITH_FIT_overlay.root")
    # c.SaveAs("plots/energy_hist_WITH_FIT_overlay.pdf")


###################################################################################
###################################################################################
###################################################################################

# resp_fname = "./txt_files/response_"+calib+"_"+shower+".txt"
# reso_fname = "./txt_files/resolution_"+calib+"_"+shower+".txt"
if(sample == "data"):
    resp_fname = "./txt_files/response_resolution/data/response_%s_chi2method%s_%s_%s.txt"%(sample,calib,shower,method)
    reso_fname = "./txt_files/response_resolution/data/resolution_%s_chi2method%s_%s_%s.txt"%(sample,calib,shower,method)

    mu_fname = "./txt_files/response_resolution/data/mu_%s_chi2method%s_%s_%s.txt"%(sample,calib,shower,method)
    sigma_fname = "./txt_files/response_resolution/data/sigma_%s_chi2method%s_%s_%s.txt"%(sample,calib,shower,method)
else:
    resp_fname = "./txt_files/response_resolution/sim/response_%s_chi2method%s_%s_%s.txt"%(sample,calib,shower,method)
    reso_fname = "./txt_files/response_resolution/sim/resolution_%s_chi2method%s_%s_%s.txt"%(sample,calib,shower,method)

    mu_fname = "./txt_files/response_resolution/sim/mu_%s_chi2method%s_%s_%s.txt"%(sample,calib,shower,method)
    sigma_fname = "./txt_files/response_resolution/sim/sigma_%s_chi2method%s_%s_%s.txt"%(sample,calib,shower,method)
c1 = rt.TCanvas("c1","Response and Resolution",500,250)

c1.Divide(2)

x_p, x_e, y1_p, y2_p ,y1_e, y2_e = array( 'd' ),array( 'd' ),array( 'd' ),array( 'd' ),array( 'd' ),array( 'd' )
# x = [0,20,50,80,100,120]
# y1 = [0,20,50,80,100,120]
n1= 8

i = 0
if(showResponse):
    print "Printing Response values..."
    print"beam_Energy \t response \t error_on_beam \t error_on_response"
else:
    print "Printing Resolution values..."
    print"beam_Energy \t resolution \t error_on_beam \t error_on_resolution"

# resp_fname = "./txt_files/response_"+sample+"_"+shower+"_5percent.txt"
# reso_fname = "./txt_files/resolution_"+sample+"_"+shower+"_5percent.txt"

# if(flag == 1):
#     resp_fname = "./txt_files/response_"+sample+"_"+shower+".txt"
#     reso_fname = "./txt_files/resolution_"+sample+"_"+shower+".txt"
# elif(flag==2 and sample=="sim"):
#     resp_fname = "./txt_files/response_"+sample+"_"+shower+"_unScaled.txt"
#     reso_fname = "./txt_files/resolution_"+sample+"_"+shower+"_unScaled.txt"
# else:
#     print "Invalid Flag"
#     sys.exit()
resp_txt = open(resp_fname,'w')
reso_txt = open(reso_fname,'w')

mu_txt = open(mu_fname,'w')
sigma_txt = open(sigma_fname,'w')


cov_resp = np.cov(mean,beamenergy)
print "Coviarance between mean and beamenergy :: ",cov_resp[0][1]," and ",cov_resp[1][0]

while i < n1:
    print "mean[i] : mean_e[i] : beamenergy[i] : beamE_e[i] : cov_resp[0][1] :: %f : %f : %f : 0.0 : %f"%(mean[i],mean_e[i],beamenergy[i],cov_resp[0][1])
    i = i+1
i = 0

print mean
print mean_e
print sigma
print sigma_e
print beamenergy


cov_reso = np.cov(mean,sigma)
print "Coviarance between mean and sigma :: ",cov_reso[0][1]," and ",cov_reso[1][0]

while i < n1:
    
    x_p.append(beamenergy[i])
    x_e.append(0.)
    
    y1_p.append(mean[i]/beamenergy[i])
    y1_e.append(calculateError(mean[i],mean_e[i],beamenergy[i],0.,cov_resp[0][1]))

    y2_p.append(sigma[i]/mean[i])
    y2_e.append(calculateError(sigma[i],sigma_e[i],mean[i],mean_e[i],cov_reso[0][1]))
    #print energy[i],"\t",mean[i]/energy[i],"+/-",calculateError(mean[i],mean_e[i],energy[i],0.),"\t",sigma[i]/mean[i],"+/-",calculateError(sigma[i],sigma_e[i],mean[i],mean_e[i])
    #print energy[i],"\t",mean[i]/energy[i],"\t",calculateError(mean[i],mean_e[i],energy[i],0.),"\t",sigma[i]/mean[i],"\t",calculateError(sigma[i],sigma_e[i],mean[i],mean_e[i])

    mu_line = "%d\t %f\t %f\n"%(i,mean[i],mean_e[i])
    sigma_line = "%d\t %f\t %f\n"%(i,sigma[i],sigma_e[i])

    mu_txt.write(mu_line)
    sigma_txt.write(sigma_line)


    line = str(beamenergy[i])+"\t"+str(mean[i]/beamenergy[i])+"\t"+"0.0"+"\t"+str(calculateError(mean[i],mean_e[i],beamenergy[i],0.,cov_resp[0][1]))+'\n'
    resp_txt.write(line)
    line = str(beamenergy[i])+"\t"+str(sigma[i]/mean[i])+"\t"+"0.0"+"\t"+str(calculateError(sigma[i],sigma_e[i],mean[i],mean_e[i],cov_reso[0][1]))+'\n'
    reso_txt.write(line)
    if(showResponse):
        print beamenergy[i],"\t",mean[i]/beamenergy[i],"\t","0.0","\t",calculateError(mean[i],mean_e[i],beamenergy[i],0.,cov_resp[0][1])
    else:
        print beamenergy[i],"\t",sigma[i]/mean[i],"\t","0.0",calculateError(sigma[i],sigma_e[i],mean[i],mean_e[i],cov_reso[0][1])
    i+=1

mu_txt.close()
sigma_txt.close()
resp_txt.close()
reso_txt.close()
print "Following files written!!"
print resp_fname
print reso_fname
line = rt.TLine(0.0,1.0,320,1.0);
line.SetLineStyle(2);
line.SetLineWidth(2);
line.SetLineColor(rt.kRed);

#gr1 = rt.TGraph(n1,x_p,y1_p)
#gr2 = rt.TGraph(n1,x_p,y2_p)

gr1 = rt.TGraphErrors(n1,x_p,y1_p,x_e,y1_e)
gr2 = rt.TGraphErrors(n1,x_p,y2_p,x_e,y2_e)

gr1.SetTitle("Response")
#gr1.GetXaxis().SetTitleSize(0.04);
gr1.GetXaxis().SetTitleSize(1.0);
gr1.GetXaxis().SetLabelSize(0.06);
gr1.GetYaxis().SetLabelSize(0.05);
# gr1.GetYaxis().SetLabelSize(0.04);
gr1.GetXaxis().SetTitle("Beam Energy (in GeV)");
gr1.GetYaxis().SetTitle("Mean (in MIPs)");
# gr1.GetXaxis().SetTitleOffset(0.9);
gr1.GetXaxis().SetTitleOffset(1.0);

gr1.GetXaxis().SetTitleSize(0.5);
gr1.GetYaxis().SetTitleOffset(1.45);
gr1.SetMarkerColor( 4 )
gr1.SetMarkerSize( 1.3 )
gr1.SetMarkerStyle( 22 )
gr1.GetXaxis().SetRangeUser(0,320)
gr1.GetYaxis().SetRangeUser(0.85,1.2)
#gr1.GetYaxis().SetRangeUser(0.5,1.7)

gr2.SetTitle("Resolution")
gr2.GetXaxis().SetTitleSize(0.04);
# gr2.GetXaxis().SetLabelSize(0.035);
# gr2.GetYaxis().SetLabelSize(0.03);

gr2.GetXaxis().SetLabelSize(0.06);
gr2.GetYaxis().SetLabelSize(0.05);

gr2.GetYaxis().SetRangeUser(0.08,0.40)
# gr2.GetYaxis().SetLabelSize(0.04);
#gr2.GetXaxis().SetTitle("Beam Energy (in GeV)");
#gr2.GetYaxis().SetTitle("Sigma/Mean");
gr2.GetXaxis().SetTitleOffset(0.9);
gr2.GetYaxis().SetTitleOffset(1.45);
# gr2.GetYaxis().SetTitleOffset(2.0);
gr2.SetMarkerColor( 4 )
gr2.SetMarkerSize( 1.3 )
gr2.SetMarkerStyle( 22 )
gr2.GetXaxis().SetRangeUser(0,320)

c1.cd(1)
rt.gPad.SetGridx()
rt.gPad.SetGridy()

# gr1.Draw("AC*")
gr1.Draw("AP")
line.Draw("SAME")
c1.cd(2)
gr2.Draw("AP")

rt.gPad.SetGridx()
rt.gPad.SetGridy()
rt.gPad.SetTickx()
rt.gPad.SetTicky()

fit_range_min = 18.0
fit_range_max = 310.0
reso = rt.TF1("reso","sqrt([0]*[0]+[1]*[1]/x+[2]*[2]/(x*x))",20,300)
reso.SetParameters(0.06,1.20,0.)
# gr2.Fit(reso,"","R",15,330)
# gr2.Fit(reso,"","R",15,330)
# gr2.Fit(reso,"","R",15,330)
gr2.Fit(reso,"Q","R",fit_range_min,fit_range_max)
# gr2.Fit(reso,"","R",fit_range_min,fit_range_max)
# gr2.Fit(reso,"","R",fit_range_min,fit_range_max)

#gr2.Fit(reso)
reso.Draw("SAME")

con1 = int(100*reso.GetParameter(0))
con2 = int(10.0*(100*reso.GetParameter(0) - con1))
const = str(con1)+"."+str(con2)

sto = str(round(100*reso.GetParameter(1),2))
sto = str(int(100*reso.GetParameter(1)))
leg = "#sigma/E = "+sto+"%/#sqrt{E} + "+const+"%"
legend1 = rt.TLegend(0.20,0.80,0.85,0.60)
legend1.AddEntry(gr2,leg,"lp")
legend1.Draw()

c1.Update()
rt.gPad.Update()

# rt.gPad.SetGridx()
# rt.gPad.SetGridy()
# c1.Update()
# rt.gPad.Update()
#print reso.GetParameter(0),"\t",reso.GetParameter(1),"\t",reso.GetParameter(2),"\t"

if(save_canvas):
    #c1.SaveAs("plots/"+str(sample)+"_GAUS_FIT_mean_sigma_withResoFit.png")
    c1.SaveAs("plots/%s_chi2method%s_GAUS_FIT_mean_sigma_withResoFit_%s_%s.png"%(sample,calib,shower,method))
    # c1.SaveAs("plots/GAUS_FIT_mean_sigma_withResoFit.gif")
    # c1.SaveAs("plots/GAUS_FIT_mean_sigma_withResoFit.jpg")
    # c1.SaveAs("plots/GAUS_FIT_mean_sigma_withResoFit.C")
    # c1.SaveAs("plots/GAUS_FIT_mean_sigma_withResoFit.root")
    # c1.SaveAs("plots/GAUS_FIT_mean_sigma_withResoFit.C")
    # c1.SaveAs("plots/GAUS_FIT_mean_sigma_withResoFit.pdf")
