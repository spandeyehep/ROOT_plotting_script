void sigmaEffective() {
	double wmin=110.;
	double wmax=130.;
	int stepsize=1 ;

	int nbins = int((wmax-wmin)/0.001/double(stepsize));
  TH1F *h = new TH1F("h","h",nbins,wmin,wmax);

   TF1 *mygaus = new TF1("mygaus","TMath::Gaus(x,120,1)",wmin,wmax);
  // pdf->fillHistogram(h,RooArgList(*mass));
  h->FillRandom("mygaus",10000);

  double narrowest=1000.;
  double bestInt;
  int lowbin;
  int highbin;

  double oneSigma=1.-TMath::Prob(1,1);

  TStopwatch sw;
  sw.Start();
  // get first guess
  cout << "Getting first guess info. stepsize (MeV) = " << stepsize*100 << endl;
  for (int i=0; i<h->GetNbinsX(); i+=(stepsize*100)){
    for (int j=i; j<h->GetNbinsX(); j+=(stepsize*100)){
      double integral = h->Integral(i,j)/h->Integral();

      if(i%2000 == 0 && j%2000 == 0 && false) {
	      char* toPrint = new char[500];
	      sprintf(toPrint,"i : j : integral :: %d : %d : %f",i,j,integral);
	      cout<<toPrint<<endl;
	  }

      if (integral<oneSigma) continue;
      double width = h->GetBinCenter(j)-h->GetBinCenter(i);
      if (width<narrowest){
        narrowest=width;
        bestInt=integral;
        lowbin=i;
        highbin=j;
        i++;
      }
    }
  }

  cout << "Took: "; sw.Print(); 
  cout<<"lowbin : highbin : bestInt : narrowest :: "<<lowbin<<" : "<<highbin<<" : "<<bestInt<<" : "<<narrowest<<endl;
  cout << narrowest/2. << " " << bestInt << " [" << h->GetBinCenter(lowbin) << "," << h->GetBinCenter(highbin) << "]" << endl;

  // narrow down result
  int thisStepSize=32;
  cout << "Narrowing....." << endl;
  while (thisStepSize>stepsize) {
    cout << "\tstepsize (MeV) = " << thisStepSize << endl;
    for (int i=(lowbin-10*thisStepSize); i<(lowbin+10*thisStepSize); i+=thisStepSize){
      for (int j=(highbin-10*thisStepSize); j<(highbin+10*thisStepSize); j+=thisStepSize){
        double integral = h->Integral(i,j)/h->Integral();
        if (integral<oneSigma) continue;
        double width = h->GetBinCenter(j)-h->GetBinCenter(i);
        if (width<narrowest){
          narrowest=width;
          bestInt=integral;
          lowbin=i;
          highbin=j;
          i++;
        }
      }
    }
    thisStepSize/=2;
  }

  sw.Stop();
  cout<<"lowbin : highbin : bestInt : narrowest :: "<<lowbin<<" : "<<highbin<<" : "<<bestInt<<" : "<<narrowest<<endl;
  cout << narrowest/2. << " " << bestInt << " [" << h->GetBinCenter(lowbin) << "," << h->GetBinCenter(highbin) << "]" << endl;
  cout << "Took:"; sw.Print();
  //pair<double,double> result(h->GetBinCenter(lowbin),h->GetBinCenter(highbin));
  delete h;
  //return result;
}