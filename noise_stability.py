import numpy as np
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
import matplotlib.lines as mlines
import os,sys


def newline(p1, p2):
    ax = plt.gca()
    xmin, xmax = ax.get_xbound()

    if(p2[0] == p1[0]):
        xmin = xmax = p1[0]
        ymin, ymax = ax.get_ybound()
    else:
        ymax = p1[1]+(p2[1]-p1[1])/(p2[0]-p1[0])*(xmax-p1[0])
        ymin = p1[1]+(p2[1]-p1[1])/(p2[0]-p1[0])*(xmin-p1[0])

    l = mlines.Line2D([xmin,xmax], [ymin,ymax])
    ax.add_line(l)
    return l



def getIndex(list_,ele):
    index = 0
    for i in list_:
        if(i == ele):
            return index
        index+=1
    return -1

def getBin(skiroc,channel):
      if (channel%2 != 0 or channel > 62 or skiroc > 3):
          return -1
      else:
          return (skiroc*32 + (channel/2))


#### Take input values from txt file
# fnameOct_EE_cup = "/home/shubham/work/HGCAL/CERNTB/oct2018TB/analysis_code_prompt_reco/MIP_calib/txt_file/v7_with_gaus_SNR_study/test_EE_plot_v1.txt"
# fnameOct_EE_decup = "/home/shubham/work/HGCAL/CERNTB/oct2018TB/analysis_code_prompt_reco/MIP_calib/txt_file/v7_with_gaus/test_EE_de_plot_v1.txt"
fname = "/home/shubham/work/HGCAL/CERNTB/oct2018TB/txt_file/pedestal_noise/Pedestal_noise_EE.txt"
#fnameJune = "/home/shubham/work/HGCAL/CERNTB/oct2018TB/analysis_code_prompt_reco/MIP_calib/txt_file/calibration_map_EE_layers_JuneTB_plotting_compatible.txt"

#### Load relevant columns
# octTB = np.loadtxt(fnameOct,usecols=(1,2,3,4,5,6,,))    ## for rechit (x,y) position
# juneTB = np.loadtxt(fnameJune,usecols=(1,2,3,4,5,6,))     ## for Density & delta
octTB_v7 = np.loadtxt(fname)
# octTB_v2 = np.loadtxt(fnameOct_EE_decup)    ## for rechit (x,y) position

#juneTB = np.loadtxt(fnameJune)     ## for Density & delta


cols = ["red","blue","green","magenta","cyan","yellow","darkorange","darkred","indigo","black","darkcyan","darkgreen","darkblue","orangered","gray","lightcoral","midnightblue"]

JuneTBModules = [78,90,89,88,77,85,84,32,69,79,67,65,76,83,35,36,70,73,44,51,86,87,54,62,64,55,71,59]
OctTBModules = [78,90,89,88,77,85,84,32,69,79,76,83,70,73,86,87,82,72,67,65,35,36,44,51,142,143,145,144]
## plotting Function for one layer
def run_one_layer(layer,octTBv7):
    print "#################################################"
    print "INFO: Working on Module:",layer
    print "INFO: OctTB"
    
    ################## First work on (x,y) co-ordinates of rechits ############
    octTBv7 = (octTBv7[octTBv7[:,0] == layer])   ## Takes columns for given layer
    # if(not len(octTBv7)):
    #     print "Module %d Not Found in octTB_v7 detector configuration."%Module
    #     return
    chip_l_o = octTBv7[:,1]  ## chip
    channel_l_o = octTBv7[:,2] ## channel
    entries_l_o = octTBv7[:,3] ## entries
    mean_l_o = octTBv7[:,4] ## mean
    sig_l_o = octTBv7[:,5] ## sig
    err_l_o = octTBv7[:,6] ## sig_err
    
    #print "Module Found at Layer = ",getIndex(OctTBModules,Module)+1

    #juneTB = (juneTB[juneTB[:,0] == getIndex(JuneTBModules,Module)])   ## Takes columns for given layer
    # juneTB = (juneTB[juneTB[:,0] == JuneTBModules[getIndex(OctTBModules,Module)]])   ## Takes columns for given layer
    # if(not len(juneTB)):
    #     print "Module %d Not Found in juneTB detector configuration."%Module
    #     return
    '''    
    octTBv2 = (octTBv2[octTBv2[:,0] == Module])
    if(not len(octTBv2)):
        print "Module %d Not Found in OctTB_v2 detector configuration."%Module
        return

    chip_l_j = octTBv2[:,1]  ## rechit_x
    channel_l_j = octTBv2[:,2]
    mip_l_j = octTBv2[:,3]
    chi2ndf_l_j = octTBv2[:,4]
    mip_un_l_j = octTBv2[:,5]
    snr_j = octTBv2[:,10]
    snr_err_j = octTBv2[:,11]

 
    # if(len(mip_l_o) != len(mip_l_j)):
    #     print "INFO: number of channels are not equal for module:",Module
    #     print "\t June = ",len(mip_l_j),", October = ",len(mip_l_o)
    #     return

    # print "INFO: Now plotting...."
    '''
    # size_x = 12
    # size_y = 6
    size_x = 8
    size_y = 4

    #fig, (ax1,ax2) = plt.subplots(1,2,sharey=False,figsize=(size_x,size_y))
    fig, ax = plt.subplots(figsize=(size_x,size_y))

    #offset = 1.0;
    #ax.set_xlim(min(x)-(offset*10), max(x)+(offset*10))
    ax.set_xlim(0.0,130.0)
    # ax.set_ylim(10.0,80.0)
    ax.set_ylim(0.0,10.0)
    
    #ax.set_xlabel("Channel #",fontsize=18)
    #ax.set_xlabel("Channel #")
    ax.set_ylabel("Noise (sigma)")
    title = "EE Layer "+str(layer)
    ax.set_title(title,fontsize=18)


    cnt = 0    ## it is short for Count, it is not what you think
    #size = [20.0,20.0]  ## marker size, although not used!!
    marker_size = 8
    mean = 0.0
    count_ = 0.0
    while cnt < len(mean_l_o):
        xo = getBin(chip_l_o[cnt],channel_l_o[cnt])
        yo = sig_l_o[cnt]
        yerro = err_l_o[cnt]
        col_ = cols[int(chip_l_o[cnt])]
        mean+= sig_l_o[cnt]
        if(entries_l_o[cnt] > 5000):
            count_+=1
        #ax.scatter(x,y,c=col_,marker='o',s=100.0)
        #ax.errorbar(x,y,yerr,ecolor=col_,marker='o',s=100.0)
        if(entries_l_o[cnt] > 5000):
            ax.errorbar(xo,yo,yerro,color="blue",ecolor="black",marker='o',ms=marker_size)
        # if(cnt == 0):
        #     ax.errorbar(xo,yo,yerro,color="blue",ecolor="black",marker='o',ms=marker_size,label="OctTB")
        # else:
        #     ax.errorbar(xo,yo,yerro,color="blue",ecolor="black",marker='o',ms=marker_size)
        cnt+=1
    print "Mean = ",(mean/count_)
    print "count = ",count_
    '''   
    cnt = 0    ## it is short for Count, it is not what you think
    while cnt < len(mip_l_j):
        xj = getBin(chip_l_j[cnt],channel_l_j[cnt])
        yj = snr_j[cnt]
        yerrj = snr_err_j[cnt]

        col_ = cols[int(chip_l_j[cnt])+4]
        #ax.errorbar(xj,yj,yerrj,color="red",ecolor="black",marker='v',ms=marker_size)
        cnt+=1
    '''
    poinx = [0.0,0.0]
    poiny = [0.0,0.0]
    ax.grid(color='black', linestyle='--', linewidth=1) # draws grid
    # legend_elements  = [ Line2D(poinx,poiny,color='w',markerfacecolor='blue',marker="o",label="Coupled Gauss",markersize=10),
    #     Line2D(poinx,poiny,color='w',markerfacecolor='red',marker="v",label="Decoupled Gauss",markersize=10)]

    legend_elements  = [ Line2D(poinx,poiny,color='w',markerfacecolor='blue',marker="o",label="Noise",markersize=10)]
    
    ax.legend(handles=legend_elements,loc=2,numpoints=1)

    plt.plot([0, 0], [0, 9], 'k-', lw=2)
    plt.plot([32, 32], [0, 9], 'k-', lw=2)
    plt.plot([64, 64], [0, 9], 'k-', lw=2)
    plt.plot([96, 96], [0, 9], 'k-', lw=2)
    plt.plot([128, 128], [0, 9], 'k-', lw=2)
    plt.plot([0, 128], [9, 9], 'k-', lw=2)
    plt.text(10,8.1,"Chip:0",fontsize=15)
    plt.text(41,8.1,"Chip:1",fontsize=15)
    plt.text(65,8.1,"Chip:2",fontsize=15)
    plt.text(101,8.1,"Chip:3",fontsize=15)
    p1 = [64,20]
    p2 = [64,50]

    # oct_module = getIndex(OctTBModules,Module)
    # layer_ = "EE Layer = "+str(oct_module+1)
    # plt.text(55,75,layer_,fontsize=20,color="red")
    # newline(p1,p2)
    


    print "INFO: Plot saved for layer: ",layer
    if(layer < 10):
        canvas_name = '0'+str(layer)+'.png'
    else:
        canvas_name = str(layer)+'.png'
    plt.savefig(canvas_name)

    plt.show()
    sys.exit()



start = 6
end = 6


# start = 34
# end = 34

i = start
n = end
#newModules = [82,72,142,143,144,145]
newModules = [144,145]
while (i <= end):
    # if(getIndex(newModules,OctTBModules[i]) > 0):
    #     print "INFO: %d is New module, skipping..."%OctTBModules[i]
    #     i+=1
    #     continue
    run_one_layer(i,octTB_v7)
    #sys.exit()
    i+=1

print "INFO: All done!!!"
