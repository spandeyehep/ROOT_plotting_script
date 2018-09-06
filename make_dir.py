import os,sys
layer = 0
while layer < 28:
        if(layer<11):
	        cmd = "mkdir overlay_plots/layer0"+str(layer+1)
        else:
	        cmd = "mkdir overlay_plots/layer"+str(layer+1)
        
	print cmd
	os.system(cmd)
	layer+=1
