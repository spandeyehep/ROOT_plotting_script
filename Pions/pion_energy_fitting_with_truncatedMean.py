import os,sys,re,fileinput,string,shutil
import numpy as np
import ROOT as rt
from array import array
from ROOT import TCanvas, TFile, TPaveText, TPaveStats
import math


calib = sys.argv[1] # 'fixed', 'Ebeam', 'Ereco'
shower = sys.argv[2] # 'EE', 'FH', 'all'
method = sys.argv[3] # 'gaus', 'trunc90' , 'trunc95', 'trunc100', 'histmean'
sample = sys.argv[4]  # 'data', 'FTFP_BERT_EMN', 'QGSP_FTFP_BERT_EMN'

dir_name = "./sim"


rt.gROOT.SetBatch(1)
def calculateError(x,dx,y,dy,cov_):
    #print "YOLO = ",(np.square(dx/x))," : ",np.square(dy/y)," : ",2*np.square(cov_)/(x*y)
    #return ((x/y)*(np.sqrt(np.square(dx/x) + np.square(dy/y) - 2*cov_/(x*y))))
    return ((x/y)*(np.sqrt(np.square(dx/x) + np.square(dy/y))))


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
    # c.SaveAs("plots/energy_hist_WITH_FIT_overlay.pdf")


###################################################################################
###################################################################################
###################################################################################


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



x_p, x_e, y1_p, y2_p ,y1_e, y2_e = array( 'd' ),array( 'd' ),array( 'd' ),array( 'd' ),array( 'd' ),array( 'd' )

n1= 8

i = 0
if(showResponse):
    print "Printing Response values..."
    print"beam_Energy \t response \t error_on_beam \t error_on_response"
else:
    print "Printing Resolution values..."
    print"beam_Energy \t resolution \t error_on_beam \t error_on_resolution"


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