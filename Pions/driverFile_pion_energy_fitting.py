import os,sys,re,fileinput,string,shutil


#calib = ["fixed","Ebeam","Ereco"]
calib = ["fixed","Ebeam"]
shower = ["EE","FH","all"]
method = ["gaus","trunc90","trunc95","histmean"]
#method = ["gaus"]


#sample = ["data","FTFP_BERT_EMN","QGSP_FTFP_BERT_EMN"]
#sample = ["data"]
sample = ["FTFP_BERT_EMN","QGSP_FTFP_BERT_EMN"]
#sample = ["data"]
#versions = ["scaled","unscaled"]
#versions = ["unscaled"]

for calib_ in calib:

	for sample_ in sample:

		for shower_ in shower:
			for method_ in method:

				if(sample_ == "data"):
					cmd = "python pion_energy_fitting_with_truncatedMean.py %s %s %s %s"%(calib_,shower_,method_,sample_)
					print cmd
					os.system(cmd)
					#sys.exit(0)
				else:
					cmd = "python pion_energy_fitting_with_truncatedMean.py %s %s %s %s"%(calib_,shower_,method_,sample_)
					print cmd
					os.system(cmd)
		            #sys.exit(0)